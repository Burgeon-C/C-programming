#include <iostream>
#include <iomanip>
using namespace std;
class Rational{
public:
   Rational( int = 0, int = 1 ); // default constructor
   Rational addition(const Rational &) const; // +的函式
   Rational subtraction(const Rational &) const; // -的函式
   Rational multiplication(const Rational &) const; // *的函式
   Rational division(const Rational &) const; // /的函式
   void printRational ()const; // 只印出有理型式
   void printRationalAsDouble()const; // 以浮點數印出
private:
   int numerator; // 分子       
   int denominator; // 分母
   void reduce(); // utility function 的 prototype
}; 

Rational::Rational( int n, int d ) : numerator(n), denominator(d){
     reduce(); // 儲存在裡面
} //  Rational constructor建構者(參考網路建構方式)

Rational Rational::addition( const Rational &a )const
{
    Rational t( a.numerator * denominator + a.denominator * numerator,a.denominator * denominator );
    t.reduce(); //把算出來的分數丟去約分
    return t;
}

Rational Rational::subtraction( const Rational &s )const
{
    Rational t( s.denominator * numerator - denominator * s.numerator,s.denominator * denominator );
    t.reduce(); //把算出來的分數丟去約分
    return t;
}

Rational Rational::multiplication( const Rational &m )const
{
     Rational t(m.numerator*numerator,m.denominator*denominator); 
     t.reduce(); //把算出來的東西丟去約分
     return t;
}

Rational Rational::division( const Rational &v )const
{
    Rational t(v.denominator*numerator,denominator*v.numerator);
    t.reduce(); //把算出來的東西丟去約分
    return t;
} 

void Rational::printRational()const
{
    if (denominator==0) // 分母如果=0 出事
       cout<<"\nCannot divide by zero->ERROR!";
    else if ( numerator==0 ) //分子=0
       cout<< 0;
    else
       cout<<numerator <<"/"<<denominator;
} 

void Rational::printRationalAsDouble()const
{ 
   cout << static_cast< double >(numerator)/denominator;//參考網路static_cast< double >
} 

void Rational::reduce()
{

   int largest;
   if(numerator > denominator){
       largest =numerator;
   }
   else {
       largest=denominator;
   }

   int gcd = 0; // 找greatest common divisor最大公因數 
   for (int i=2;i<=largest;++i )
   {
       if ( numerator%i==0 and denominator%i==0)
          gcd=i;
   }
   if(gcd!=0)
   {
    numerator/=gcd;
    denominator/=gcd;
   } // 做約分

} //reduce 函式

 

int main(){
Rational x(2,4),y(6,9),z; //creates three rational objects
   x.printRational(); // 印有理物件x
   cout <<"+";
   y.printRational(); // 印有理物件y
   cout <<"=";                                        
   z = x.addition( y ); // 相加物件x y; sets the value to z
   z.printRational(); // 印出有理物件 z
   cout <<"\n"<<"After adding:"<<endl;
   z.printRational(); // 印出有理物件 z   
   cout <<"=";
   z.printRationalAsDouble(); // 將z的double型式印出

   cout <<"\n\n"; //換兩行

   x.printRational(); 
   cout <<"-";
   y.printRational();
   z = x.subtraction( y ); 
   cout <<"=";
   z.printRational();
   cout <<"\n"<<"After subtracting"<<endl;
   z.printRational(); 
   cout <<"=";
   z.printRationalAsDouble();

    cout <<"\n\n";

   x.printRational(); 
   cout <<"x";
   y.printRational(); 
   z = x.multiplication( y );                     
   cout <<"=";
   z.printRational(); 
   cout <<"\n"<<"After multiplying"<<endl;
   z.printRational(); 
   cout <<"=";
   z.printRationalAsDouble(); 

   cout <<"\n\n";

   x.printRational(); 
   cout <<"/";
   y.printRational();    
   z = x.division( y ); 
   cout <<"=";
   z.printRational();                   
   cout <<"\n"<<"After dividing"<<endl;
   z.printRational(); 
   cout <<"=";
   z.printRationalAsDouble(); 
   cout << endl;

} //主程式結束

 