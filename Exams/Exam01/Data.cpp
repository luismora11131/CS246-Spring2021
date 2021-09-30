#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Date{
  private: 
  string month;
  short day;
  int year;
  public:
  void set(string month,int year,short day){
    month = "January";
    day = 1;
    year = 1900;
  }
  //const getter method
  const string getMonth() const {
    return month;
  }
  const int getYear() const {
    return year;
  }
  const short getDay() const {
    return day;
  }

  void setMonth(string Month){
    Month = month;
  }
  void setYear(int Year){
    Year = year;
  }
  void setDay(short Day){
    Day = day;
  }
  
  const string ToString() const{
    stringstream ss;
    ss<<day<<" "<<month<<", "<<year;
    return ss.str();
  }

  friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt){
    os<<dt.month<<' '<<dt.day<<' '<<dt.year;
    return os;
  }

class TimeStamp: public Date{
  private:
  int time;

  public:
  void set(int time, const Date& month, const Date& day, const Date& year){
    time = 0;
  }
  const int getTime() const {
    return time;
  }
  void setMonth(int Time){
    Time = time;
  }
  const string ToString() const{
    stringstream ss;
    ss<<getDay()<<" "<<getMonth()<<", "<<getYear()<<"; "<<time<<'s';
    return ss.str();
  }
  friend ostream& operator<<(ostream& os, const TimeStamp& dt);
};
ostream& operator<<(ostream& os, const TimeStamp& dt){
    os<<TimeStamp.getDay<<" "<<TimeStamp.getMonth()<<", "<<TimeStamp.getYear()<<"; "<<time<<'s';
    return os;
  }