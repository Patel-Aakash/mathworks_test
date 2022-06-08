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
			return true;
		}else{
			return false;
		}
	}

	protected:
	friend Number operator+(const Number& a, const Number& b);
};
Number operator+(const Number& a, const Number& b){
	return Number(a.val+b.val);
}

// Class-2 -- Numbers
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

// Class-3 -- Numbers
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


//Input reading
tuple<double, double> read_input(){
    double x;
    double y;
    cout << "Enter first number  - " ;
    cin >> x ;
    cout << "Enter second number - " ;
    cin >> y ;
    cout << "--------------------------------------" << endl;
    return  std::make_tuple(x , y);
}    

tuple<int,int,int,int> read_input_1(){
    int x,y ,a,b;
    cout << "Enter first numbers numerator    - " ;
    cin >> x ;
    cout << "Enter first numbers denominator  - " ;
    cin >> y ;
    cout << "Enter second numbers numerator   - " ;
    cin >> a ;
    cout << "Enter second numbers denominator - " ;
    cin >> b ;
    cout << "--------------------------------------" << endl;
    try {
        if (b==0 || y==0) {
            throw 0;
        }
    }
    catch(int x){
        cout << "ERROR::Unsupported Input argument-Input must be non-zero integer" << endl;
        exit(0);
    }
    return  std::make_tuple(x , y, a, b);
}  

tuple<int,int,int> read_input_2(){
    int x,y;
    double a;
    cout << "Enter Fraction numbers numerator    - " ;
    cin >> x ;
    cout << "Enter Fraction numbers denominator  - " ;
    cin >> y ;
    cout << "Enter Non-Fraction Number           - " ;
    cin >> a ;
    cout << "--------------------------------------" << endl;
    try {
        if ( floor(a)!=a || y==0) {
            throw 0;
        }
    }
    catch(int x){
        cout << "ERROR::Unsupported Input argument-Input must be non-zero integer" << endl;
        exit(0);
    }
    return  std::make_tuple(x , y, a);
}  

int select_input_type(){
    int input_type;
    cout << "--------------------------------------" << endl;
    cout << "Select Input type:     " << endl;
    cout << " 1 : Number-Number     " << endl;
    cout << " 2 : Fraction-Fraction " << endl;
    cout << " 3 : Mix               " << endl;
    cout << "--------------------------------------" << endl;

    try {
        cout << "Please Enter Value:   " ;
        cin >> input_type ;   
        cout << "--------------------------------------" << endl;
        if (input_type != 1 && input_type != 2 && input_type != 3){
            throw 99;
        }     
    }
    catch(...){
        cout << "ERROR::Unsupported Input argument" << endl;
        exit(0);
    }
    return input_type;
}

int main(){
    double x, y;
    int num_1, den_1, num_2, den_2;
    int ip_type;
    ip_type = select_input_type();
    
    if (ip_type == 1) {
        tie(x, y) = read_input();
     
        if (floor(x) == x && floor(y) == y){
            Integer a(x);
            Integer b(y);
            Integer c;
            c = a+b;
            a==b;
            cout << "First number  : " << a.val << endl;
            cout << "Second number : " << b.val << endl;
            cout << "Sumed Number  : " << c.val << endl; 
            cout << std::boolalpha << "Are value same: " << (a==b) << endl; 
            cout << "--------------------------------------" << endl;
        }
        else {
            Number a(x);
            Number b(y);
            Number c;
            c = a+b;
            a==b;
            cout << "First number  : " << a.val << endl;
            cout << "Second number : " << b.val << endl;
            cout << "Sumed Number  : " << c.val << endl; 
            cout << std::boolalpha << "Are value same: " << (a==b) << endl; 
            cout << "--------------------------------------" << endl;
        }
    }
    else if (ip_type == 2){
        tie(num_1, den_1, num_2, den_2) = read_input_1();
        Fraction d(num_1,den_1);
        Fraction e(num_2,den_2);
        Fraction f;

        f=d+e;


    
        cout << "First number  : " << d.num << "/" << d.den << endl ;
        cout << "Second number : " << e.num << "/" << e.den << endl;
        cout << "Sumed Number  : " << f.num << "/" << f.den << endl; 
        cout << std::boolalpha << "Are value same: " << (d==e) << endl; 
        cout << "--------------------------------------" << endl;
    } 
    else if (ip_type == 3){
        tie(num_1, den_1, x) = read_input_2();
        Fraction d(num_1,den_1);
        Integer  e(x);
        Fraction f;
        
        f=d+e;

        cout << "First number  : " << d.num << "/" << d.den << endl;
        cout << "Second number : " << e.val << endl;
        cout << "Sumed Number  : " << f.num << "/" << f.den << endl; 
        cout << std::boolalpha << "Are value same: " << (d==e) << endl; 
        cout << "--------------------------------------" << endl;
    } 
    
   return 0;
}



