#include<iostream>
#include<iomanip>
using namespace std;
class matrix{
	private:
		int maxrow,maxcol;
		int *ptr;
	public:
		matrix(int r,int c){
			maxrow=r;maxcol=c;
			try{
			
			ptr=new int[r*c];
		}
		catch(bad_alloc){
			cout<<"error";
		}
		}
	void startmat(){
		int i,j,mat_off;
		cout<<"Enter elements matrix:"<<endl;
		for(i=0;i<maxrow;i++){
			for(j=0;j<maxcol;j++){
				//cout<<"error";
				mat_off=i*maxcol+j;
				cin>>ptr[mat_off];
			}
		}
	}
	
	void printmat(){
		int i,j,mat_off;
		for(i=0;i<maxrow;i++){
			cout<<endl;
			for(j=0;j<maxcol;j++){
				mat_off=i*maxcol+j;
				cout<<setw(3)<<ptr[mat_off];
			}
		}
	}
	int detmat(){
		matrix q(maxrow-1,maxcol-1);
		int sign=1,sum=0,i,j,k,count;
		int newpos,pos,order;
		order=maxrow;
		if(order==1){
			return(ptr[0]);
		}
		for(i=0;i<order;i++,sign*=-1){
			for(j=1;j<order;j++){
				for(k=0,count=0;k<order;k++){
					if(k==i)
						continue;
					pos=j*order+k;
					newpos=(j-1)*(order-1)+count;
					q.ptr[newpos]=ptr[pos];
					count++;
					}
				}
				sum=sum+ptr[i]*sign*q.detmat();
			}
			return(sum);
		}
			
	matrix operator+(matrix b){
		matrix c(maxrow,maxcol);
		int i,j,mat_off;
		for(i=0;i<maxrow;i++){
			for(j=0;j<maxcol;j++){
				mat_off=i*maxcol+j;
				c.ptr[mat_off]=ptr[mat_off]+b.ptr[mat_off];
				
			}
		}
		return c;
	}
	matrix operator*(matrix b){
		matrix c(b.maxcol,maxrow);
		int i,j,k,mat_off1,mat_off2,mat_off3;
		for(i=0;i<c.maxrow;i++){
			for(j=0;j<c.maxcol;j++){
				mat_off3=i*c.maxcol+j;
				c.ptr[mat_off3]=0;
				for(k=0;k<b.maxrow;k++){
					mat_off2=k*b.maxcol+j;
					mat_off1=i*maxcol+k;
					c.ptr[mat_off3]+=ptr[mat_off1]*b.ptr[mat_off2];
				}
			}
		}
		return c;
	}
	int operator==(matrix b){
		int i,j,mat_off;
		if(maxrow !=b.maxrow|| maxcol!=b.maxcol)
			return 0;
		for(i=0;i<maxrow;i++){
			for(j=0;j<maxcol;j++){
				mat_off=i*maxcol+j;
				if(ptr[mat_off]!= b.ptr[mat_off])
					return 0;
			}
		}
		return 1;
	}	
};
int main(){
	int rowa,cola,rowb,colb;
	cout<<"enter the dimensions of matrix a"<<endl;
	cin>>rowa>>cola;
	matrix a(rowa,cola);
	a.startmat();
	
	cout<<"enter the dimensions of matrix b"<<endl;
	cin>>rowb>>colb;
	matrix b(rowb,colb);
	b.startmat();
	
	matrix c(rowa,cola);
	c=a+b;
	cout<<"the sum of the two matrices are="<<endl;
	c.printmat();
	
	matrix d(rowa,colb);
	d=a*b;
	cout<<endl<<"the product of the two matrices are="<<endl;
	d.printmat();
	
	cout<<endl<<"Determinant of matrix a="<<a.detmat();
	if(a==b)
		cout<<endl<<"a and b are equal"<<endl;
	else
		cout<<endl<<"a and b are not equal"<<endl;
	return 0;
}
