#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct stud
{
int rno;
char nm[10];
}s;

void create()
{
ofstream fout;
int n,i;
fout.open("stud.txt",ios::out);
cout<<"\nEnter The Number of records="<<endl;
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\nEnter The Roll No And Name="<<endl;
cin>>s.rno>>s.nm;
fout<<endl<<s.rno<<"\t"<<s.nm;
}
}

void display()
{
ifstream fin;
fin.open("stud.txt",ios::in);
while(!fin.eof())
{
fin>>s.rno>>s.nm;
cout<<"\n"<<s.rno<<"\t"<<s.nm;
}
fin.close();
}

void search()
{
ifstream fin;
int fl,key;
cout<<"\nEnter roll Number of element which you want to search =";
cin>>key;
fin.open("stud.txt",ios::in);
while(!fin.eof())
{
	fin>>s.rno>>s.nm;
if(s.rno==key)
{
fl=1;
break;
}
if(fl==1)
cout<<"Element Found\n"<<s.rno<<"\t"<<s.nm;
else
cout<<"\nElement Not Found"<<endl;
fin.close();
}
}

int main()
{
int ch;
do{
cout<<"\n1.Create\n2.Display\n3.Search\n4.Exit";
cout<<"\nEnter The Choice="<<endl;
cin>>ch;
switch(ch)
{
case 1:create();
	break;
case 2:display();
break;
case 3:search();
break;
}
}while(ch<4);
return 0;
}


