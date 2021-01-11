/*
    Interface segregation principle

   Not create interfaces that are too large
*/

#include <iostream>

using namespace std;

struct Document;

// struct IMachine
// {
//     virtual void print(Document & doc)=0;
//     virtual void scan(Document & doc)=0;
//     virtual void fax(Document & doc)=0;
// };

// //multi function printer

// struct MFP : IMachine
// {
//     void print(Document & doc)override{/*ok*/}
//     void scan(Document & doc) override{/*ok*/}
//     void fax(Document & doc) override{/*ok*/}
// };

// // the scanner does not have to implemente all 
// struct Scanner: IMachine
// {
//     void print(Document & doc)override{}
//     void scan(Document & doc) override{/*ok*/}
//     void fax(Document & doc) override{}
// };

//segregate the interface becouse not always any client will need
//to implment all methods

struct IPrinter
{
    virtual void print(Document & doc)=0;
};

struct IScanner
{
    virtual void scan(Document & doc)=0;
};

struct IFax
{
    virtual void fax(Document & doc)=0;
};

struct Printer : IPrinter
{
    void print(Document & doc)override{/*OK*/}
};

struct Scanner : IScanner
{
    void scan(Document & doc)override{/*OK*/}
};

// agregate interfaces to define a complex machine
// does not require a body, keep abstract
struct IMachine: IPrinter, IScanner {};

// struct Machine: IMachine
// {
//     void print(Document & doc)override{/*OK*/}
//     void scan(Document & doc)override{/**/}
// };

struct Machine: IMachine
{
    IPrinter & printer;
    IScanner & scanner;

    Machine(IPrinter & printer, IScanner &scanner): printer(printer),
    scanner(scanner){}

    void print(Document & doc)override{
        printer.print(doc);
    }
    void scan(Document & doc)override{
        scanner.scan(doc);
    }
};

int main()
{
    return 0;
}
