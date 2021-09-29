#ifndef Card_cpp
#define Card_cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class card{
    private:
    string suit,symbol;
    public:
    card (){
        suit = "";
        symbol = "";
    }
    card(const card &obj){
    }
    card& operator=(const card& rhs){
    }
    ~card(){
    }
    const string GetSuit(){
        return suit;
    }
    const string GetSymbol(){
        return symbol;
    }
    void SetSuit(string a){
        suit = a;
    }
    void SetSymbol(string a){
        symbol = a;
    }
    const string ToString(){
        stringstream out;
        out << "[" << symbol << ":" << suit << "]";
        return out.str();
    }
    friend ostream operator<<(ostream out, card& obj){
        out << obj.ToString();
        return out;
    }

};

#endif