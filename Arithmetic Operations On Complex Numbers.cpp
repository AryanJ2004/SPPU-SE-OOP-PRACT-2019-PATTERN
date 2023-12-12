#include <iostream>
using namespace std;

class complex
{

	float r;
	float i;
public:
	complex()
	{
                 r=0;
                 i=0;
        }

        complex operator+(complex);
        complex operator*(complex);
        friend istream &operator >>(istream &input,complex &t);
        friend ostream &operator <<(ostream &output,complex &t);

};

complex complex::operator+(complex c)
{
        complex temp;
        temp.r=r+c.r;
        temp.i=i+c.i;
        return(temp);
}

complex complex::operator*(complex c)
{
        complex temp2;
        temp2.r=(r*c.r)-(i*c.i);
        temp2.i=(i*c.r)+(r*c.i);
        return(temp2);
}
istream &operator>>(istream &input,complex &t)
{
	cout<<"Enter the real part:";
	input>>t.r;
	cout<<"Enter the imaginary part:";

	input>>t.i;
}

ostream &operator<<(ostream &output,complex &t)
{
	output<<t.r<<"+"<<t.i<<"i\n";
}

int main()
{
	complex c1,c2,c3,c4;

	cout<<"Enter the 1st number:\n";
	cin>>c1;
	cout<<"\nEnter the 2nd number:";
	cin>>c2;
        c3=c1+c2;
        c4=c1*c2;

	cout<<"The first number is:\n"<<c1;
	cout<<"The second number is:\n"<<c2;

	cout<<"\nAddition Of Two Complex Number Is:"<<c3;
	cout<<"\nMultiplication Of Two Complex Number Is:"<<c4;

	return 0;

}
