#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Scrollbar{
    public:
    int bar;
    Scrollbar(){
        bar = 5;
    }
    Scrollbar (const Scrollbar &obj){

    }

    Scrollbar &operator=(const Scrollbar &obj){
    }

    ~Scrollbar(){

    }

    int GetLength() const{
        return bar;
    }

    void SetLength(int a){
        if(a>0&&a<=50){
            bar = a;
        }
    }

    void GetPosition(int a){
        if(a>0&&a<50){
            bar = a;
        }
    }
    bool Moveup(){
        if(bar+1<50){
            bar+=1;
            return true;
        }
        else return false;
    }

    bool MoveDown(){
        if(bar-1>0){
            bar-=1;
            return true;
        }
        else return false;

    }

    bool Drag(int a){
        if(a>-50&&a<50){
            bar = a;
            return true;
        }
    }
    string ToString() const{
        stringstream out;

        string scrollbar[3][52];
        for(int i=0;i<3;i++){
            for(int j=0;j<52;j++){
                if(i==0||i==2){
                    if(j>0&&j<52){
                    scrollbar[i][j] = "*";
                    }
                }
                if(i==1&&j==0){
                    scrollbar[i][j] = "-";
                }
                if(i==1&&j==51){
                    scrollbar[i][j] = "+";
                }
                if(i==1&&j==bar){
                    scrollbar[i][j-1] = "[";
                    scrollbar[i][j+1] = "]";
                }

            }
        }
        out << scrollbar;
        return out.str();
    }

    friend ostream &operator << (ostream& out, const Scrollbar &obj){
        out << obj.ToString();
        return out;
    }
};