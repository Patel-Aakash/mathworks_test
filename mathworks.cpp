#include <iostream>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;

// Class-1 -- Numbers
class Numbers{
    public:

    template <class T >
    T display(T x,T y){
        cout << "First number  : " << x << endl;
        cout << "Second number : " << y << endl;
    }    

    template <class T >
    T add(T x,T y){
        cout << "Sumed Number  : " << x+y << endl; 
    }

    template <class T >
    T are_same (T x,T y){
        printf("Are value same: %s\n",(x == y)?"true":"false");
        cout << "--------------------------------------" << endl;
    }

};

// Class-2 -- Integers
class Integers : public Numbers{
};


// Class-3 -- Fractions
class Fractions {
    public:
    void display(int n_1, int d_1, int n_2, int d_2){
        cout << "First number  : " << n_1 << "/" << d_1 << endl;
        cout << "Second number : " << n_2 << "/" << d_2 << endl;
    }    
    
    void add (int n_1, int d_1, int n_2, int d_2){
        
        //find LCM 
        int lcm = d_1*d_2 / findHCF(d_1,d_2);

        int sum = ((lcm*n_1)/d_1) + ((lcm*n_2)/d_2);

        cout << "Sumed number  : " << sum << "/" << lcm << endl; 
    }

    void are_same (int n_1, int d_1, int n_2, int d_2){
        int y = n_1*d_2 - n_2*d_1; 
        printf("Are value same: %s\n",(y==0)?"true":"false");
        cout << "--------------------------------------" << endl;
    } 

    private:
    //HCF function - highest common factor
    int findHCF(int n1, int n2){
        int hcf;
        for (int i=1; i<= n1 && i<=n2; i++)
        {
            if (n1%i ==0 && n2%i ==0)
            hcf = i;                
        }
        return hcf;
    }
};


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

int select_input_type(){
    int input_type;
    cout << "--------------------------------------" << endl;
    cout << "Select Input type:    " << endl;
    cout << " 1 : Number           " << endl;
    cout << " 2 : Fraction         " << endl;
    cout << "--------------------------------------" << endl;

    try {
        cout << "Please Enter Value:   " ;
        cin >> input_type ;   
        cout << "--------------------------------------" << endl;
        if (input_type != 1 && input_type != 2 ){
            throw 99;
        }     
    }
    catch(...){
        cout << "ERROR::Unsupported Input argument" << endl;
        exit(0);
    }
    //cout << "Please Enter Value:   " ;
    //cin >> input_type ;
    return input_type;
}

int main(){
    Numbers N_Object;  // Object for class-1
    Integers N_int;    // Object for class-2 
    Fractions N_fra;   // Object for class-3
    double x, y;
    int num_1, den_1, num_2, den_2;
    int ip_type;
    ip_type = select_input_type();
    
    if (ip_type == 1) {
        tie(x, y) = read_input();
     
        if (floor(x) == x && floor(y) == y){
            N_int.display(x, y);               // Integer Object and  Integer class will be used here 
            N_int.add(x, y);                   // Integer Object and  Integer class will be used here  
            N_int.are_same(x, y);              // Integer Object and  Integer class will be used here 
        }
        else {
            N_Object.display(x, y);           // Number Object and Number class will be used here 
            N_Object.add(x, y);               // Number Object and Number class will be used here
            N_Object.are_same(x, y);          // Number Object and Number class will be used here
        }
    }
    else if (ip_type == 2){
        tie(num_1, den_1, num_2, den_2) = read_input_1();
        
        N_fra.display(num_1,den_1,num_2,den_2);    // Fraction Object and Fraction class will be used here
        N_fra.add (num_1,den_1,num_2,den_2);       // Fraction Object and Fraction class will be used here
        N_fra.are_same (num_1,den_1,num_2,den_2);  // Fraction Object and Fraction class will be used here 
    } 
    
   return 0;
}



