#include <iostream>
using namespace std;
int n;
#define size 10
template <class T>
void sel(T A[size])
{
	int i,j,min;
	T temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])	
			min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
cout<<"\nSorted Array:"<<endl;
for(i=0;i<n;i++)
{

	cout<<" "<<A[i];
}
}

int main()
{

int A[size];
float B[size];

int i;
int ch;

do
{

	cout<<"\n******SELECTION SORT SYSTEM*********";
	cout<<"\n******MENU***************";
	cout<<"\n1.Integer Values";
	cout<<"\n2.Float Values";
	cout<<"\n3.Exit";
	cout<<"\nEnter Your Choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\nEnter Total Number Of Integer Elements:";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
	sel(A);
	break;
		case 2:
		cout<<"\nEnter Total Number Of Float Elements:";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>B[i];
		}
	sel(B);
	break;
		case 3:
			cout<<"\nExiting Program... Thanks For Using!";
			break;
	}
	}while(ch!=3);

return 0;
}


