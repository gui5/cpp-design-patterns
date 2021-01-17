// Open Close Principle

/*
   The system must be open for extention, and close for modification

    * avoid to jump in to code we already written
*/

#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string name;
  Color color;
  Size size;
};

/*
    This kind of approach does no scale
    You have to keep modifying the Productfilter to add new filters
*/
struct Productfilter {
  vector<Product *> by_color(vector<Product *> &items, Color color) {
    vector<Product *> result;
    for (auto &i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  vector<Product *> by_size(vector<Product *> &items, Size size) {
    vector<Product *> result;
    for (auto &i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

  vector<Product *> by_size_and_color(vector<Product *> &items, Size size,
                                      Color color) {
    vector<Product *> result;
    for (auto &i : items)
      if (i->color == color && i->size == size)
        result.push_back(i);
    return result;
  }
};

/*
   The goal is to make the code easy to extend

   implementation of a better filter using the specification pattern
*/

// base specification interface, can be used with any type of item
template <typename T> struct Specification {
  virtual bool is_satisfied(T *item) = 0;
};

// base filter interface, can be used with any type of item and specification
template <typename T> struct Filter {
  virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

/*
    the Filter implementation is a filter of Product named of BetterFilter

*/
struct BetterFilter : Filter<Product> {
  vector<Product *> filter(vector<Product *> items,
                           Specification<Product> &spec) override {
    vector<Product *> result;
    for (auto &item : items)
      if (spec.is_satisfied(item))
        result.push_back(item);

    return result;
  }
};

struct ColorSpecification : Specification<Product> {
  Color color;
  explicit ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) override { return item->color == color; }
};

struct SizeSpecification : Specification<Product> {
  Size size;
  explicit SizeSpecification(Size size) : size(size) {}

  bool is_satisfied(Product *item) override { return item->size == size; }
};

/*
    combinators to combine different Specifications
*/
template <typename T> struct AndSpecification : Specification<T> {
  Specification<T> &first;
  Specification<T> &second;

  AndSpecification(Specification<T> &first, Specification<T> &second)
      : first(first), second(second) {}

  bool is_satisfied(T *item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main() {
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  vector<Product *> items{&apple, &tree, &house};

  //   Productfilter pf;
  //   auto green_things = pf.by_color(items, Color::green);
  //   for (auto item : green_things)
  //     cout << item->name << " is green\n";

  BetterFilter bf;
  ColorSpecification green(Color::green);

  for (auto &item : bf.filter(items, green))
    cout << item->name << " is green\n";

  SizeSpecification large(Size::large);
  AndSpecification<Product> green_and_large(green, large);

  for (auto &item : bf.filter(items, green_and_large))
    cout << item->name << " is green and large\n";


  return 0;
}
