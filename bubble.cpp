#include<iostream>
#include<stdio.h>

using namespace std;

template<class T>
void bubble(int size,T* arr){



int i,j;


T temp;
for(i=0;i<size;i++){
	for(j=0;j<size-i-1;j++){
		if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}

cout<<"The sorted array is:"<<endl;

for(i=0;i<size;i++){
	cout<<arr[i]<<endl;
}





}

int main(void){
	int x[5]={2,5,6,7,1};
	float y[5]={3.5,9.8,1.2,4.7,2.0};


int n;


bubble(5,x);
bubble(5,y);

}