#include <iostream>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;

// Class-1 -- Numbers
class Number{
    public:
	virtual void display() = 0;
};

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
tuple<int, int> read_input(){
    double x, y;
    cout << "Enter first number  - " ;
    cin >> x ;
    cout << "Enter second number - " ;
    cin >> y ;
    cout << "--------------------------------------" << endl;
    try {
        if (floor(x)!=x || floor(y)!=y) {
            throw std::invalid_argument("ERROR::Unsupported Input argument-Input must be integer");
        }
    }
    catch(int x){
        exit(0);
    }
    return  std::make_tuple(x , y);
}    

tuple<int,int,int,int> read_fraction_input(){
    double x,y ,a,b;
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
        if (floor(a)!=a || floor(b)!=b || floor(x)!=x || floor(y)!=y) {
            throw std::invalid_argument("ERROR::Unsupported Input argument-Input must be integer");
        }
        if(b==0 || y==0){
			throw std::logic_error("ERROR::Denominator of Fraction cannot be zero");
		}
    }
    catch(int x){
        exit(0);
    }
    return  std::make_tuple(x , y, a, b);
}  

tuple<int,int,int> read_mix_input(){
    double x,y;
    double a;
    cout << "Enter Fraction numbers numerator    - " ;
    cin >> x ;
    cout << "Enter Fraction numbers denominator  - " ;
    cin >> y ;
    cout << "Enter Non-Fraction Number           - " ;
    cin >> a ;
    cout << "--------------------------------------" << endl;
    try {
        if (floor(a)!=a || floor(x)!=x || floor(y)!=y) {
            throw std::invalid_argument("ERROR::Unsupported Input argument-Input must be integer");
        }
        if(y==0){
			throw std::logic_error("ERROR::Denominator of Fraction cannot be zero");
		}
    }
    catch(int x){
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
    int x, y;
    int num_1, den_1, num_2, den_2;
    int ip_type;
    ip_type = select_input_type();
    
    if (ip_type == 1) {
        tie(x, y) = read_input();
            Integer a(x);
            Integer b(y);
            Integer c;
            c = a+b;
            //a==b;

           	Integer *num1 = new Integer(a);
            Integer *num2 = new Integer(b);

            cout << "First number  : " ;
            num1->display();    
            cout << "Second number : "; 
            num2->display();
            cout << "Sumed Number  : " << c.val << endl; 
            cout << std::boolalpha << "Are value same: " << (a==b) << endl; 
            cout << "--------------------------------------" << endl;
    }
    else if (ip_type == 2){
        tie(num_1, den_1, num_2, den_2) = read_fraction_input();
        Fraction d(num_1,den_1);
        Fraction e(num_2,den_2);
        Fraction f;
        f=d+e; 

        Fraction *num1 = new Fraction(d);
        Fraction *num2 = new Fraction(e);
        
        cout << "First number  : " ; 
        num1->display();   
        cout << "Second number : " ;
        num2->display();  
        cout << "Sumed Number  : " << f.num << "/" << f.den << endl; 
        cout << std::boolalpha << "Are value same: " << (d==e) << endl; 
        cout << "--------------------------------------" << endl;
    } 
    else if (ip_type == 3){
        tie(num_1, den_1, x) = read_mix_input();
        Fraction d(num_1,den_1);
        Integer e(x);
        Fraction f;
        f=d+e;

        Number *num1 = new Fraction(d);
        Number *num2 = new Integer(e);

        cout << "First number  : " ;
        num1->display();   
        cout << "Second number : " ;
        num2->display();
        cout << "Sumed Number  : " << f.num << "/" << f.den << endl; 
        cout << std::boolalpha << "Are value same: " << (d==e) << endl; 
        cout << "--------------------------------------" << endl;
    } 
    
   return 0;
}



