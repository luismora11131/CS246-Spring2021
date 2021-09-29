#include <iostream>
#include <string>
using namespace std;
class Rectangle{
    private:
    double length,width;
    public:
    Rectangle(){
        length=width=1;
    }
    Rectangle(const Rectangle &obj){
    }

    Rectangle &operator(const Rectangle &obj){
    }

    ~Rectangle();

    const double GetLength(){
        return length;
    }

    const double GetWidth(){
        return width;
    }

    void SetLength(double a){
        if(a>0&&a>=length){
            length=a;
        }
    }

    void SetWidth(double a){
        if(a>0&&a<=length){
            width=a;
        }
    }

    const double Perimeter(){
        return 2*(length+width);
    }
    
    const double Area(){
        return length*width;
    }

    const string ToString(){
        string value = "["+width+","+length+"]";
    }
};