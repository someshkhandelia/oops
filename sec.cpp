#include<stdio.h>
#include<string.h>
typedef struct emplo{
	char name[100];
	int id;
};


int main(void){
	struct emplo arr[100];
	FILE *fp;
	int i,j,k,z,n;
	int ch,bh;
	char na[100];
	fp=fopen("employee.txt","w+");
	printf("Enter no. of employees:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter %d employee's data\n",i+1);
		printf("Enter name:");
		fflush(stdin);
		scanf("%s",&arr[i].name);
		fprintf(fp,"name-%s",arr[i].name);
		printf("Enter id:");
		scanf("%d",&arr[i].id);
		fprintf(fp,"        id-%d\n",arr[i].id);
	}
	fclose(fp);
	
	
	do{
		printf("Do you want to search for an employee? 1 for yes ,2 for no: ");
		//fflush(stdin);
		scanf("%d",&ch);
		if(ch==2){
			break;
			}
		else{
			printf("Search by name or id? 1 for name 2 for id: ");
			scanf("%d",&bh);
			if(bh==2){
				int newid;
				printf("Enter employee id: ");
				scanf("%d",&newid);
				for(i=0;i<n;i++){
					if(arr[i].id==newid){
						printf("Enter new name for employee %d\n",arr[i].id);
						fflush(stdin);
						scanf("%s",&arr[i].name);
					}
				}
			}
			else{
				printf("Enter employee name:  ");
				fflush(stdin);
				scanf("%s",na);
				for(i=0;i<n;i++){
					if(strcmp(na,arr[i].name)==0){
						printf("ID of the employee is %d\n",arr[i].id);
					}
				}


			}

			
		}
	}while(ch==1);
	fp=fopen("employee.txt","w+");

for(i=0;i<n;i++){
		
		
		fprintf(fp,"name-%s",arr[i].name);
		
		fprintf(fp,"        id-%d\n",arr[i].id);
	}


	
	fclose(fp);


}