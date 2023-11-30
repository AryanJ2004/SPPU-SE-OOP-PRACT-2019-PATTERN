#include <iostream>
#include <string.h>
using namespace std;
class person_additional_info
{
	char address[20],license[20],insurence[20];
	long int contact;
public:
	person_additional_info()
	{
		cout<<"Constructor";
		strcpy(address,"XYZ");
		strcpy(license,"AB00000000");
		strcpy(insurence,"XXXXXXXXX");
		contact=0000000000;
	}
	~person_additional_info()
	{
		cout<<"Destructor";
	}

friend class person;
};

class person
{
	char name[20],dob[20],blood[20],div[10];
	int roll_no;
	float ht,wt;
	static int count;
	person_additional_info *pai;
public:
	person()	
	{
		strcpy(name,"ABCD");
		strcpy(dob,"XX");
		strcpy(blood,"X");
		strcpy(div,"A");
		roll_no=1;
		ht=0;
		wt=0;
		pai=new person_additional_info;
	}
	person(person *p1)
	{
		strcpy(name,p1->name);
		strcpy(dob,p1->dob);
		strcpy(blood,p1->blood);
		strcpy(div,p1->div);
		roll_no=p1->roll_no;
		ht=p1->ht;
		wt=p1->wt;
		pai=new person_additional_info;
		strcpy(pai->address,p1->pai->address);
		strcpy(pai->license,p1->pai->license);
		strcpy(pai->insurence,p1->pai->insurence);
		pai->contact=p1->pai->contact;
	}
	static void showcount()
	{
		cout<<"\nNo Of records count="<<count<<"\n";
	}

	~person()
	{
		cout<<"Destructor";
	}
	void getdata(char name [20]);
	inline void display();

};


void person::getdata(char name[20])
{

	strcpy(this->name,name);
	cout<<"\nEnter data of birth="<<endl;
	cin>>dob;
	cout<<"\nEnter Blood Group="<<endl;
	cin>>blood;
	cout<<"Enter Division";
	cin>>div;
	cout<<"Enter Roll No="<<endl;
	cin>>roll_no;
	cout<<"\nEnter height="<<endl;
	cin>>ht;
	cout<<"\nEnter Weight="<<endl;
	cin>>wt;
	cout<<"\nEnter Address"<<endl;
	cin>>pai->address;
	cout<<"Enter License Number="<<endl;
	cin>>pai->license;
	cout<<"\nEnter Insurence Policy Number="<<endl;
	cin>>pai->insurence;
	cout<<"\nEnter Contact Number="<<endl;
	cin>>pai->contact;
	count++;

}


void person::display()
{
	cout<<"\t"<<name;
	cout<<"\t"<<dob;
	cout<<"\t"<<blood;
	cout<<"\t"<<div;
	cout<<"\t"<<roll_no;
	cout<<"\t"<<ht;
	cout<<"\t"<<wt;
	cout<<"\t"<<pai->address;
	cout<<"\t"<<pai->license;
	cout<<"\t"<<pai->insurence;
	cout<<"\t"<<pai->contact;
}	
int  person::count;

int main()
{
	person *p1,*p2;
	int ch;
	p1=new person;
	p2=new person(p1);
	cout<<"\tName";
	cout<<"\tDOB";
	cout<<"\tBlood";
	cout<<"\tDivision";
	cout<<"\tRoll No";
	cout<<"\tHeight";	
	cout<<"\tWeight";
	cout<<"\tAddress";
	cout<<"\tLicense";
	cout<<"\tInsurence";
	cout<<"\tContact";
	cout<<endl;

	cout<<"Default Constructor Value \n";
	p1->display();
	cout<<"\n";
	cout<<"Copy Constructor Value \n";
	p2->display();
	int n;
	cout<<"\nEnter How many Records You Want?";
	cin>>n;
	person p3[n];
	char name[20];
	int x=0;
	do
	{
		cout<<"\nWelcome To Personal Database System";
		cout<<"\n1.Enter The Record";
		cout<<"\n2.Display The Record";
		cout<<"\n3.Exit"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter The Name=";
				cin>>name;
				p3[x].getdata(name);
				person::showcount();
				x++;
				break;
			}
			case 2:
			{
				cout<<"\tName";
				cout<<"\tDOB";
				cout<<"\tBlood";
				cout<<"\tDivision";
				cout<<"\tRoll No";
				cout<<"\tHeight";
				cout<<"\tWeight";
				cout<<"\tAddress";
				cout<<"\tlicense";
				cout<<"\tInsurence";
				cout<<"\tContact";
				for(int i=0;i<x;i++)
				{
					cout<<"\n";
					p3[i].display();
				}

				break;
			}
		}
	}while(ch!=3);

delete p1;
delete p2;
return 0;

}


