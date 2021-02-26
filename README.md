# cpp-design-patterns

This repository is a collecttion of study notes and exercises related to the implementation of design patterns in C++ based on the Udemy course [Design Patterns in Modern C++](https://www.udemy.com/course/patterns-cplusplus/)

# Builder

* A builder is a separated component for building an object
* Can either give builder a constructor or return it via a static function
* To make builder fluent return this.
* Different facets of an object can be built with different builder working in tandem via a base class.

## Simple builder

@startuml
skinparam packageStyle rectangle
package ""{
class HtmlElement{
+name : String
+text : String
+elements : vector<HtmlElement>
+indent_size: int
+HtmlElement()
+HtmlElement(String name, String text)
+str(int indent): String
}
class HtmlBuilder{
	+root: HtmlElement
	+HtmlBuilder(String root_name)
	+add_child(String child_name, String child_text):void
	+str():String
}

HtmlBuilder --> HtmlElement : creates

@enduml

## Fluent builder

@startuml
skinparam packageStyle rectangle
package ""{
class HtmlElement{
+name : String
+text : String
+elements : vector<HtmlElement>
+indent_size: int
+HtmlElement()
+HtmlElement(String name, String text)
+str(int indent): String
}
class HtmlBuilder{
	+root: HtmlElement
	+HtmlBuilder(String root_name)
	+add_child(String child_name, String child_text):<ref> HtmlBuilder
	+str():String
}

HtmlBuilder --> HtmlElement : creates

@enduml


