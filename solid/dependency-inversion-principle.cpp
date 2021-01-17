/*
    Dependency inversion principle

    High-level modules should not depend on low level modules.
    Both should depend on abstractions.
    
    Abstractions should not depend on details.
    Details should depend on abstractions.
*/


// ** Abstractions = interfaces or base types.

#include <vector>
#include <tuple>
#include <string>
#include <iostream>

using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

//abstrction to not break the principle
struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string & name)=0;
};

struct Relationships : RelationshipBrowser// low-level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_add_child(const Person & parent, const Person & child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child,parent});
    }

     vector<Person> find_all_children_of(const string & name)override{
         vector<Person> result;
          for(auto&& [first, rel, second]: relations)
        {
            if(first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;

     }

};

// a reasearch is considered a high-level

/*
    To reasearch we need data. If we depend on the low-level model,
    it will break the depency inversion principle
*/

struct Reasearch // just to ilustrate if the Relationships changes this breaks
{
    // Reasearch(Relationships & relationships){
    //     auto & relations = relationships.relations;
    //     for(auto&& [first, rel, second]: relations)
    //     {
    //         if(first.name == "John" && rel == Relationship::parent)
    //         {
    //             cout<< "John has a child called "<< second.name<<endl;
    //         }
    //     }
    // }

    Reasearch(RelationshipBrowser & browser)
    {
        for(auto & child: browser.find_all_children_of("John")){
            cout << "John has a child called "<<child.name <<endl;
        }
    }
};


int main()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_add_child(parent,child1);
    relationships.add_parent_add_child(parent,child2);

    Reasearch _(relationships);

    return 0;
}
