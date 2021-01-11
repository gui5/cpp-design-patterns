/*
    Liskov substitution principle

    Subtypes should be imediatelly substituble by base types
*/

#include <iostream>

using namespace std;

class Rectange
{
protected:
    int width, height;

public:
    Rectange(int width, int height):width(width), height(height){}

    int getWidth()const{
        return width;
    }
    virtual void setWidth(int width){
        Rectange::width = width;
    }
    
    int getHeight()const{
        return height;
    }
    virtual void setHeight(int height){
        Rectange::height= height;
    }

    int area()const{return width*height;}
};

class Square: public Rectange
{
public: 
    Square(int size):Rectange(size,size){}

    void setWidth(int value)override
    {
        this->width = this->height = value;
    }

    void setHeight(int value)override
    {
        this->width = this->height = value;
    }
};


void process(Rectange & r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout<<"expected area = "<<(w*10)
        <<", got "<<r.area()<<endl;
}


int main()
{
    Rectange r{3,4};
    process(r);

 //with this design this principle is broken 
    Square sq{5};
    process(sq);
    
    return 0;
}
