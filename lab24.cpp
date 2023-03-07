#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double a,const ComplexNumber &c){
	return ComplexNumber(a+c.real,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator-(double a,const ComplexNumber &c){
	return ComplexNumber(a-c.real,-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)+(-1)*(imag*c.imag),(imag*c.real)+(real*c.imag));
}

ComplexNumber operator*(double real,const ComplexNumber &c){
	return ComplexNumber(real*c.real,real*c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double o = pow(c.real,2)+pow(c.imag,2);
	return ComplexNumber(((real*c.real)+(imag*c.imag))/o,-((real*c.imag)-(imag*c.real))/o);
}
ComplexNumber operator/(double real,const ComplexNumber &c){
	double o = pow(c.real,2)+pow(c.imag,2);
	return ComplexNumber((real*c.real)/o,-(real*c.imag)/o);
}
bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real and imag == c.imag)return true;
	else return false;
}

bool operator==(double a,const ComplexNumber &c){
	if(a == c.real and a == c.imag)return true;
	else return false;
}

double ComplexNumber::abs(){
    return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
    double m = atan2(imag,real);
    double ang = m*180/M_PI;
    return ang;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
    if((c.imag > 0 and c.real > 0) or (c.imag > 0 and c.real < 0))return os << c.real << "+" << c.imag << "i";
    else if ((c.imag < 0 and c.real < 0) or (c.imag < 0 and c.real > 0))return os << c.real << c.imag << "i";
    else if (c.imag == 0)return os << c.real;
    else if (c.real == 0)return os << c.imag << "i";
    else return os << "0";
}


//Write your code here.

