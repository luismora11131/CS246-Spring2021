
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
//1.b
double SumOfProduct(double a, double b){
    return (a*a) + (b*b);
}

/*1.c
-True
-False
-False 
-True
*/

//2
string Translate(string word){
    string letter = "abcdefghijklmnopqrstuvwqyz";
    string morse[] = {"*-","-***","-*-*","-**", "*", "**-*", "--*","****", "**", "*---", "-*-", "*-**", "--","-*", "---", "*--*", "--*-", "*-*", "***", "-","**-", "***-", "*--", "-**-", "-*--", "--**"};
    for(int i=0;i<word.length();i++){
        int index = letter.find(word[i]);
        cout<<word[index]<<" ";
    }
}

//3
double Variance(double dataset[]){
    int size = sizeof(dataset)/sizeof(dataset[0]);
     double sum=0.0;
     double value = 0.0;
    for (int i=0;i<size;i++){
        sum += dataset[i];
    }
    double average = sum / size;
    for(int i=0;i<size;i++){
        value += (dataset[i]-average)*(dataset[i]-average);
    }
    double solution = value / size;
    return solution;
}

/* 4 Debugging
a.
line 05 = return 'g';
line 07 = return 'e';
line 13 = return 'z';

b.
line 01 = double I(const double& a, double& b)
line 04 = b +=a;

c.
line 05 = cout<< "Enter first name: ";
*/

int main(){
    double arr[5] = {1.0,2.0,3.0,4.0,5.0};
    double a = Variance(arr);
    cout<<"The varience of the dataset is "<<a<<endl;
    //1.d
    int c = 3;
    if(c%2!=0){
        c++;
    }
    //1.e
    for(int i=1;i<1000;i++){
        if(i%7==0){
            cout<<i<<endl;
        }
    }

}   