#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
T Max(T *arr, int n){
    int max = arr[0];
    for(int j=0j<n;j++){
        if(arr[j]>max){
            max=arr[j];
        }
    }
    return max;
}


class Pair<K,V>{
    public:
    K key;
    V value;
    Pair(){
    }
    ~Pair(){
    }
    Pair(const Pair& obj){
    }
    Pair& operator(const Pair& rhs){
    }
    K GetKey() const{
        return key;
    }
    V GetValue() const{
        return value;
    }
    void SetKey(K a){
        key=a;
    }
    void SetValue(V b){
        value=b;
    }
    string ToString() const{
        stringstream out;
        out<<setprecision(1)<<fixed;
        out<<"("<<key<<","<<value<<")";
        return out.str();
    }
    friend ostream& operator<<(ostream& out, const Pair obj){
        out<<obj.ToString();
        return out;
    }
};

#endif