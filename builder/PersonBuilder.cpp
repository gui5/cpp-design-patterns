#include "PersonBuilder.hpp"
#include "PersonAddressBuilder"
#include "PersonJobBuilder"

PersonBuilderBase::PersonBuilderBase(Person& person):
	person(person){}

PersonBuilder::PersonBuilder():
	PersonBuilderBase(p){}
