//**************************LINEAR QUEUE********************************************************


#include<iostream>
#include<stdio.h>

using namespace std;

template<class T>
class queue{

private:
	int top,rear,size;
	T*arr;
public:
	queue(int x){
		this->size=x;
		this->top=-1;
		this->rear=-1;
		this->arr=new T[size];
	}
	void enqueue(T x){
		if(rear==size-1){
			cout<<"Overflow"<<endl;
		}
		else{
			rear++;
			arr[rear]=x;
		}
	}
	void dequeue(){
		if(top>rear){
			cout<<"Underflow";
		}
		else{
			top=top+1;
			cout<<arr[top]<<" was dequeued"<<endl;
		}
	}

	void display(){
		int i;
		if(top>rear){
			cout<<"queue is empty"<<endl;
		}
		else{
			for(i=top+1;i<=rear;i++){
				cout<<arr[i]<<endl;
			}
		}
	}

	~queue(){
		cout<<"Destructor reached"<<endl;
		delete []arr;
	}


};





int main(void){

queue<int> s1(7);
s1.enqueue(5);
s1.enqueue(2);
s1.enqueue(3);
s1.enqueue(7);
s1.enqueue(1);
s1.enqueue(10);
s1.enqueue(11);

s1.dequeue();
s1.dequeue();




queue<float> s2(7);

s2.enqueue(5.6);
s2.enqueue(2.1);
s2.enqueue(3.4);
s2.enqueue(7.2);
s2.enqueue(1.1);
s2.enqueue(10.9);
s2.enqueue(11.6);

s2.display();

return 0;





}