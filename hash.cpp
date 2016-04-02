#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char name[100];

	struct node* link;
};

struct node* getnode(){
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	return p;
}

int main(void){
	struct node *arr[5];

	int i,j,n,z,k;
	int count;
	for(i=0;i<5;i++){
		arr[i]=NULL;
	}
	char naam[100];
	printf("Enter no. of names: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter %dth name :",i+1);
		fflush(stdin);
		scanf("%s",naam);
		j=0;
		while(naam[j]!='\0'){
			count=count+(int)naam[j];
			j++;

		}
		k=count%5;
		arr[k]=getnode();
		strcpy(arr[k]->name,naam);



	}
	char nom[100];
	printf("Search for a NAME: ");
	fflush(stdin);
	scanf("%s",nom);
	j=0;
	count=0;
		while(nom[j]!='\0'){
			count=count+(int)nom[j];
			j++;

		}
		k=count%5;
		printf("located at %d (when mod value is calculated)",k);

		for(i=0;i<5;i++){
			free(arr[i]);
		}
return 0;

}