//single Responsiblity Principle

/*
    A Class should have a primary resposiblity and not change other things

    -> Separation of concerns

*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>


using namespace std;
using namespace boost;

// the journal must be responsible for the title and entries
struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string & title): title(title){}

    void add_entry(const string & entry){
        static int count =1;
        entries.push_back(lexical_cast<string>(count++)+": "+entry);
    }
};

// the PersistenceManager is responsible for saving Journals
struct PersistenceManager{
    static void save(const Journal & j, const string & filename )
    {
        ofstream ofs(filename);
        for(auto & e: j.entries)
            ofs << e << endl;
    }
};

int main()
{
    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    // this is bad
    //journal.save("filename"); 

    PersistenceManager::save(journal,"10_12-2023.txt");

    return 0;
}
