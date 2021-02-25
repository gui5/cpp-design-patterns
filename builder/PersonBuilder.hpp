#ifndef PERSON_BUILDER_
#define PERSON_BUILDER_

#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase{
protected:
	Person & person;

public:
	PersonBuilderBase(Person& person);
	PersonAddressBuilder lives()const;
	PersonJobBuilder works()const;
};

class PersonBuilder : public PersonBuilderBase
{
public:
	PersonBuilder();
private:

	Person p;
};

#endif
