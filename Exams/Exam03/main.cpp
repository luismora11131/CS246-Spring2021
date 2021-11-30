#include <iostream>
#include <string>
#include "Node.h"
#include "Deque.h"
#include "Stack.h"
#include "Array.h"
using namespace std;
using namespace ds;

//Luis Mora
//11/30/2021

/****************************************************************************************
 * Fundamentals
 ****************************************************************************************
 *First In First Out FIFO
 *Its when more than one hashing algorith/function generate a hash value at the same slot
 *A key to store values
 *It is equal m/n size/count
 *It allows items to exist at the same location in the hash table. This is done by shifting a key to the next free slot of the hash table
 ***************************************************************************************/

/****************************************************************************************
 * Implementation
 ***************************************************************************************/
template<class T>
class Deque{
  private:
  dn::Node<T>* front;
  dn::Node<T>* back;
};
template<class T>
void RemoveFromBack(){
  if(head!=NULL){
    if(head->next==NULL){
      head=NULL;
    }
    else{
      Node<T>* temp=head;
      while(temp->next->next!=NULL){
        temp=temp->next;
        Node<T>* lastNode=temp->next;
        temp->next=NULL;
        free(lastNode);
      }
    }
  }
}


/****************************************************************************************
 * Problem Solving
 ***************************************************************************************/
//3)
int OddMedian(Array<int>& data){
  int median;
  int size = data.Length();
  if(size%2!=0){
    //sort in ascending order
    for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
        int temp = data[i];
        data[i]=data[j];
        data[j]=temp;
      }
    }
    median = data[(size-1)/2];
    return median;
  }
  else{
    return 0;
  }
}


//4)
string Alter(string str){
  int size = str.length();
  bool run=true;
//while loop to make run it again until there are no more substrings
    for(int i=0;i<size;i++){
        for(int j=1;j<size;j++){
          if(str[i]==str[j]){
            char temp = str[i];
            str[i]=str[size-1];
            str[size-1]=temp;
            temp = str[j];
            str[j]=str[size-2];
            str[size-2]=temp;
            str.Pop();
            str.Pop();
            size=str.length();
          }

        }
        
      }


  }
int main()
{
	return 0;
}
