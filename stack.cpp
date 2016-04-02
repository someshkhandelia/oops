//*****************************AUTHOR - SOMESH KHANDELIA******************************************************
//*****************************GENERIC STACK CLASS************************************************************


#include<iostream>
#include<stdio.h>

using namespace std;

template<class T>
class stack{

private:
	int top,size;
	T*arr;
public:
	stack(int x){
		this->size=x;
		this->top=-1;
		this->arr=new T[size];
	}
	void push(T x){
		if(top==size-1){
			cout<<"Overflow"<<endl;
		}
		else{
			top++;
			arr[top]=x;
		}
	}
	void pop(){
		if(top==-1){
			cout<<"Underflow";
		}
		else{
			top=top-1;
			cout<<arr[top+1]<<" was popped"<<endl;
		}
	}

	void display(){
		int i;
		if(top==-1){
			cout<<"Stack is empty"<<endl;
		}
		else{
			for(i=top;i>=0;i--){
				cout<<arr[i]<<endl;
			}
		}
	}

	~stack(){
		cout<<"Destructor reached"<<endl;
		delete []arr;
	}


};





int main(void){

stack<int> s1(7);
s1.push(5);
s1.push(2);
s1.push(3);
s1.push(7);
s1.push(1);
s1.push(10);
s1.push(11);

s1.pop();
s1.pop();


stack<float> s2(7);

s2.push(5.6);
s2.push(2.1);
s2.push(3.4);
s2.push(7.2);
s2.push(1.1);
s2.push(10.9);
s2.push(11.6);

s2.display();

return 0;





}