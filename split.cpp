#include<stdio.h>
int main(void){

	FILE *fp,*f1,*f2;
	char ch;
	int count=0;
	fp=fopen("student.txt","r+");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(ch=='\n'){
			count++;
		}

	}
	fclose(fp);
	int cou=0;

	fp=fopen("student.txt","r+");
	f1=fopen("one.txt","w+");
	f2=fopen("two.txt","w+");
	while(!feof(fp)&&cou<count/2){
		fscanf(fp,"%c",&ch);
		fprintf(f1,"%c",ch);
		if(ch=='\n'){
			cou++;
		}

		
	}
	fclose(f1);
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		fprintf(f2,"%c",ch);

		
	}
	fclose(f2);
	return 0;




}