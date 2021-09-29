#include <iostream>
#include <string>
using namespace std;
class Point3D{
    public:
    int x,y,z;
    Point3D(){
        x=y=z=1;
    }
    void Output(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<z<<endl;
    }
};