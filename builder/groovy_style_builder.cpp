#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

/*
 *Using uniform initalization syntax 
 *to create the builder.
 *
 * */

struct Tag{
	string name, text;
	vector<Tag> childrem;
	vector<pair<string,string>> attributes;
	
	friend std::ostream & operator<<(std::ostream& os, const Tag& tag)
	{
		os << "<" << tag.name;

		for (const auto & att: tag.attributes)
			os << " " << att.first << "=\"" << att.second << "\"";
		
		if (tag.childrem.size() == 0 && tag.text.length() == 0)
		{
			os << "/>" << std::endl;
		}
		else
		{
			os << ">" << std::endl;
			if (tag.text.length())
				os << tag.text << std::endl;
			for (const auto & child : tag.childrem)
				os << child;

			os << "</" << tag.name << ">" << std::endl;
		}
		return os;
	}

protected:
public:
	Tag(const string & name, const string & text): name(name), text(text){}
	
	Tag(const string & name, const vector<Tag> & childrem)
		:name(name), childrem(childrem){}
};

// HTML paragrapth
struct P : Tag
{
	P(const string & text): Tag("p", text){}
	P(initializer_list<Tag> childrem)
		: Tag{"p", childrem}{}
};

//HTML image
struct IMG : Tag
{
	explicit IMG(const string & url)
		: Tag{"img", ""}
	{
		attributes.emplace_back(make_pair("src",url));
	}
};

using namespace std;

int main(){
	cout <<
		P{
			IMG {"http://pokemon.com/pikachu.png"}
		}
	<< endl;

}

