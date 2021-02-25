#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
	Lets do the job with a builder
*/


struct HtmlElement
{
	std::string name, text;
	std::vector<HtmlElement> elements;
	const size_t indent_size =2;

	HtmlElement(){}
	HtmlElement(const std::string &name, 
			const std::string &text):name(name),text(text){}

	std::string str(int indent =0)const{
		std::ostringstream oss;
		std::string i(indent_size*indent, ' ');
		oss << i << "<" << name << ">" << std::endl;
		if (text.size() > 0)
			oss << std::string(indent_size *(indent +1),' ') << text <<std::endl;

		for (const auto & e : elements)
			oss << e.str(indent+1);
		
		oss << i << "</" << name << ">" << std::endl;
		return oss.str();
	}

	// hint to the client to use the bulder interface
	// does not work anymore
	//static HtmlBuilder build(std::string root_name)
//	{
//		return HtmlBuilder(root_name);
//	}


};

struct HtmlBuilder
{
	HtmlElement root;
	
	HtmlBuilder(std::string root_name){
		root.name=root_name;
	}
 
	// to create a the fluent interface, change the return type to pointer or referece
	// to itself.
	HtmlBuilder & add_child(std::string child_name, std::string child_text){
		HtmlElement e{child_name, child_text};
		root.elements.emplace_back(e);
		return *this;
	}

	std::string str()const {return root.str();}

	operator HtmlElement()const {return root;}
};


int main(){
	//lets create an html example
	
	auto text = "hello";
	std::string output;
	output += "<p>";
	output += text;
	output += "</p>";
	std::cout<<output<<std::endl;
	
	std::string words[] = {"hello", "world"};
	std::ostringstream oss;
	oss << "<ul>";
	for(auto w : words)
		oss << "   <li>" << w << "</li>";
	oss << "</ul>";
	std::cout << oss.str() << std::endl;

	HtmlBuilder builder {"ul"};

	// we need two lines to call multiple add_child methods.
	//builder.add_child("li","hello");
	//builder.add_child("li","world");
	
	// this is the way a fluent builder interface is.
	builder.add_child("li","hello").add_child("li","world");
	std::cout<<builder.str()<<std::endl;

	// using the hint in HtmlElement
//	auto builder2 = HtmlElement::build("ul").add_child(" "," ");
	return 0;

}
