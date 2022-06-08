#include <iostream>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;


// Class-1 -- Numbers
class Number{
    public:
	double val;
	
	Number():val(0){}
	Number(const double &_val):val(_val){
		//pass
	}
	
	virtual void display(){
        std::cout<<val<<std::endl;
    }
	Number operator =(const Number &rhs){
		this->val = rhs.val;
		return *this;
	}
	virtual bool operator ==(const Number &rhs) const{
		if(this->val==rhs.val){
			cout  << "value same: " << endl;
			return true;
		}else{
			cout  << "value not same: " << endl;
			return false;
		}
	}

	protected:
	friend Number operator+(const Number& a, const Number& b);
};
Number operator+(const Number& a, const Number& b){
	return Number(a.val+b.val);
}

//Class-2 -- Integer
class Integer : public Number{
    public:
	int val;
	
	Integer():val(0){}
	Integer(const int &_val):val(_val){
		//pass
	}
    void display(){
        std::cout<<val<<std::endl;
    }
	Integer operator =(const Integer &rhs){
		this->val = rhs.val;
		return *this;
	}
	bool operator ==(const Integer &rhs) const{
		if(this->val==rhs.val){
			return true;
		}else{
			return false;
		}
	}
	protected:
	friend Integer operator+(const Integer& a, const Integer& b);
};
Integer operator+(const Integer& a, const Integer& b){
	return Integer(a.val+b.val);
}

//Class-3 -- Fractions
class Fraction : public Number{
    public:
	int num,den;
	
	Fraction():num(1),den(1){}
	Fraction(int _num,int _den):num(_num),den(_den){
		if(den==0){
			throw std::logic_error("Denominator of Fraction cannot be zero");
		}
	}
    void display(){
        std::cout<<num<<"/"<<den<<std::endl;
    }
	Fraction &operator =(const Fraction &rhs){
		this->num = rhs.num;
		this->den = rhs.den;
		return *this;
	}
	bool operator ==(const Fraction &rhs) const{
		if(this->num/this->den==rhs.num/rhs.den){
			return true;
		}else{
			return false;
		}
	}
	bool operator ==(const Integer &rhs) const{
		if(this->num/this->den==rhs.val){
			return true;
		}else{
			return false;
		}
	}
	protected:
	friend class Integer;
	friend Fraction operator+(const Fraction& a, const Fraction& b);
	friend Fraction operator+(const Fraction& a, const Integer& b);
	friend Fraction operator+(const Integer& a, const Fraction& b);
};
Fraction operator+(const Fraction& a, const Fraction& b){
	return Fraction(a.num*b.den+b.num*a.den,a.den*b.den);
}
Fraction operator+(const Fraction& a, const Integer& b){
	return Fraction(a.num+b.val*a.den,a.den);
}
Fraction operator+(const Integer& a, const Fraction& b){
	return Fraction(b.num+a.val*b.den,b.den);
}

int main(){
	int x_int = 2;
	int y_int = 3;
	double x_double = 3.2;
	double y_double = 2.5;
	int num_1=1, den_1=2, num_2=2, den_2=4;
	
	//Inputs
	Number *num1 = new Integer(x_int);
	Number *num2 = new Integer(y_int);
	Number *num3 = new Fraction(num_1,den_1);
	Number *num4 = new Fraction(num_2,den_2);
	Number *num5 = new Number(x_double);
	Number *num6 = new Number(y_double);

	Integer a(x_int);
	Integer b(y_int);
	Integer c;

	Number d(x_double);
	Number e(y_double);
	Number f;

	Fraction g(num_1,den_1);
	Fraction h(num_2,den_2);
	Fraction i;

	c= a+b;
	f=d+e; 
    i=g+h;
	//Outputs
	Number *num7 = new Integer(c);
	//Number *num8 = new Fraction(i);
	Number *num9 = new Number(f);
	

	a==b;
	
	std::cout<<"Intpust Numbers : "<<std::endl;

	num1->display();
	num2->display();
	num3->display();
	num4->display();
	num5->display();
	num6->display();
	
	std::cout<<"OutPuts Numbers : "<<std::endl;

	num7->display();
	num8->display();
	num9->display();

	//std::cout<<"sumed number: int "<< c.val <<std::endl;
	//std::cout<<"sumed number: double "<< f.val <<std::endl;
	//std::cout<<"sumed number: fraction "<< i.num <<"/" << i.den<<std::endl;



	std::cout<<"\n"<<std::endl;
	//num5 = num1+num2;
}