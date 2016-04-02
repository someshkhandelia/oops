#include<iostream>
#include<stdio.h>
using namespace std;

class stack{
public:
	int arr[100];
	int top;


void stackinit(){
	top=-1;


}
void push(int a){
	if(top==99){
		printf("Cant push any more\n");
	}
	else{
		arr[++top]=a;
	}

	
}
int pop(){
	if(top==-1){
		printf("Cant pop\n");
		return 0;
	}
	else{
		//printf("%c was popped",arr[top--]);
		return arr[top--];
	}
}


};


int main(void){

	stack s;
	s.stackinit();
	char str[100];
	int brr[100];
	printf("Enter a valid postfix expression\n");
	fflush(stdin);
	char c;
	int l=0,i=0,j=0;
	int x,y;
	scanf("%s",str);
	do{
		c=str[i];
		l=l+1;
		i++;
	}while(c!='\0');

	l--;                 //length of my expression






	//My str array will contain postfix expression

	for(i=0;i<=l;i++){
		if(str[i]>=65&&str[i]<=90||str[i]>=97&&str[i]<=122){
			
			printf("value of %c=",str[i]);
			scanf("%d",&brr[j++]);
			s.push(brr[j-1]);

		}
		else{
			if(str[i]=='+'){
				x=s.pop();
				y=s.pop();
				s.push(y+x);
			}
			if(str[i]=='-'){
				x=s.pop();
				y=s.pop();
				s.push(y-x);
			}
			if(str[i]=='*'){
				x=s.pop();
				y=s.pop();
				s.push(y*x);
			}
			if(str[i]=='/'){
				x=s.pop();
				y=s.pop();
				s.push(y/x);
			}
			
		}


	}
	printf("Answer is %d",s.arr[0]);
	return 0;




}