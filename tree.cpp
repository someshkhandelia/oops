#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
 using namespace std;

struct bst{
	int val;
	//struct bst* parent;
	struct bst* left;
	struct bst* right;

};
struct bst* insert(){
	struct bst *p;
	p=(struct bst*)malloc(sizeof(struct bst));
	p->left = NULL;
	p->right= NULL;
	return p;

}
int postorder(struct bst* m){

	struct bst *z,*k;
	z=m;
	if(z!=NULL){
	postorder(z->left);
	postorder(z->right);
	printf("%d  ",z->val);
	return 0;
	}
	else{
		return 0;
	}
	

}

int preorder(struct bst* m){

	struct bst *z,*k;
	z=m;
	if(z!=NULL){
	printf("%d  ",z->val);
	preorder(z->left);
	preorder(z->right);
	return 0;
	}
	else{
		return 0;
	}
	
	
	

}
int inorder(struct bst* m){

	struct bst *z,*k;
	z=m;
	if(z!=NULL){
	inorder(z->left);
	printf("%d  ",z->val);
	inorder(z->right);
	return 0;
	}
	else{
		return 0;
	}
	
	
	

}
int main(void){
	int i,j,n,k;
	int* arr;
	printf("Enter no. of elements in BST:");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements:  ");

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}


	//sort(arr,arr+n);
	/*for(i=0;i<n;i++){

		printf("%d  ",arr[i]);
	}*/
		struct bst *head,*z,*q;
		head=(struct bst*)malloc(sizeof(struct bst));
		head->val=arr[0];
		head->left=NULL;
		head->right=NULL;
		
		for(i=1;i<n;i++){

			z=head;
			
			while(z!=NULL){
				if(arr[i]<z->val){
				q=z;
				z=z->left;
				//continue;
				}
				else if(arr[i]>z->val){
					
					q=z;
					z=z->right;
					
					//continue;
				}

			}
			
			if(arr[i]<q->val){
				q->left=(struct bst*)malloc(sizeof(struct bst));
				q=q->left;
				q->val=arr[i];
				q->left=NULL;
				q->right=NULL;

				//continue;
			}
			else if(arr[i]>q->val){
				q->right=(struct bst*)malloc(sizeof(struct bst));
				q=q->right;
				q->val=arr[i];
				q->left=NULL;
				q->right=NULL;
				//continue;
			}

			

		}


		int v;

		printf("\nPostorder traversal gives:\n ");
		v=postorder(head);


		printf("\nPreorder traversal gives: ");
		v=preorder(head);

		printf("\nInorder traversal gives: ");
		v=inorder(head);












free(arr);
return 0;
}