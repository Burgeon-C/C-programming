#include<iostream>
#include <iomanip>
#include <string>
using namespace std;
 
class Package //base class
{
	protected:
        string recipient_name;   //課本要求收寄者的資訊 (protected
		string recipient_address;
		string recipient_city;
		string recipient_state;
		string recipient_ZIP;
		string sender_name;
		string sender_address;
		string sender_city;
		string sender_state;
		string sender_ZIP;	
		double costperounce;
        double weight;
	public:
        Package(string sender_n, string sender_addr, string sender_c,string sender_s, string sender_Z, string recipient_n,string recipient_addr,string recipient_c,string recipient_s, string recipient_Z, double wei,double cost);
	
    void setrecipient_name(string recipient_n);//設定寄收者的個人資訊
    string getrecipient_name();
 
    void setrecipient_address(string recipient_addr);
    string getrecipient_address();
 
    void setrecipient_city(string recipient_c);
    string getrecipient_city();
 
    void setrecipient_state(string recipient_s);
    string getrecipient_state();
 
    void setrecipient_ZIP(string recipient_Z);
    string getrecipient_ZIP();
 	
	void setsender_name(string sender_n); 
    string getsender_name();
 
    void setsender_address(string sender_addr);
    string getsender_address();
 
    void setsender_city(string sender_c);
    string getSendCity();
 
    void setsender_state(string sender_s);
    string getsender_state();
 
    void setsender_ZIP(string sender_Z);
    string getsender_ZIP();
    
    void setweight(double w);
    double getweight();
 
    void setcostperounce(double cost);
    double getcostperounce();
    double calculateCost();
};
 
Package::Package(string sender_n,string sender_addr,string sender_c,string sender_s,string sender_Z,string recipient_n,string recipient_addr,string recipient_c,string recipient_s,string recipient_Z,double wei,double cost)
{	
        recipient_name=recipient_n;   //指定進去(參考網路查詢到的程式碼使用的名稱)
		recipient_address=recipient_addr;
		recipient_city=recipient_c;
		recipient_state=recipient_s;
		recipient_ZIP=recipient_Z;
    	sender_name=sender_n;
		sender_address=sender_addr;
		sender_city=sender_c;
		sender_state=sender_s;
		sender_ZIP=sender_Z;	
	if(wei>0.00 && cost>0.00){
		
        weight=wei;
		costperounce=cost;
	}
	else{
		weight=0.0;
		costperounce=0.0;
	}		
}
 
void Package::setsender_name(string sender_n)
{
	sender_name=sender_n;
}
string Package::getsender_name()
{
	return sender_name;
}   
void Package::setsender_address(string sender_addr)
{
	sender_address=sender_addr;
}
string Package::getsender_address()
{
	return sender_address;
}
 
void Package::setsender_city(string sender_c)
{
	sender_city=sender_c;
}
 
string Package::getSendCity()
{
	return sender_city;
}
 
void Package::setsender_state(string sender_s)
{
	sender_state=sender_s;
}
string Package::getsender_state()
{
	return sender_state;
}
 
void Package::setsender_ZIP(string sender_Z)
{
	sender_ZIP=sender_Z;
}
string Package::getsender_ZIP()
{
	return sender_ZIP;
}
    
void Package::setrecipient_name(string recipient_n)
{
	recipient_name=recipient_n;
}
string Package::getrecipient_name()
{
	return recipient_name;
}
 
void Package::setrecipient_address(string recipient_addr)
{
	recipient_address=recipient_addr;
}
string Package::getrecipient_address()
{
	return recipient_address;
}
 
void Package::setrecipient_city(string recipient_c)
{
	recipient_city=recipient_c;
}
string Package::getrecipient_city()
{
	return recipient_city;
}
 
void Package::setrecipient_state(string recipient_s)
{
	recipient_state=recipient_s;
}
string Package::getrecipient_state()
{
	return recipient_state;
}
 
void Package::setrecipient_ZIP(string recipient_Z)
{
	recipient_ZIP=recipient_Z;
}
string Package::getrecipient_ZIP()
{
	return recipient_ZIP;
}
 
void Package::setweight(double w)
{
	 weight=(w<0.0) ? 0.0 : w;
}
double Package::getweight()
{
	return weight;
}
 
void Package::setcostperounce(double cost)
{
	costperounce=(cost<0.0) ? 0.0 : cost;
}
 
double Package::getcostperounce()
{
	return costperounce;
}
 
double Package::calculateCost()
{
	double result;
	
	result=weight*costperounce;
	
	return result;
}
 
 
class TwoDayPackage:public Package //繼承Package 使用網路上查詢到的解題方法資訊跟課本上的
{
	private:
		double two_day_delivery_fee;
	public:
		TwoDayPackage(string sender_n,string sender_addr,string sender_c,string sender_s,string sender_Z,string recipient_n,string recipient_addr,string recipient_c,string recipient_s,string recipient_Z,double wei, double cost, double delivery_fee);
        double gettwo_day_delivery_fee();
		void settwo_day_delivery_fee(double delivery_fee);
		double calculateCost();
};
 
TwoDayPackage::TwoDayPackage(string sender_n, string sender_addr, string sender_c, string sender_s, string sender_Z, string recipient_n,string recipient_addr,string recipient_c,string recipient_s,string recipient_Z, double wei, double cost, double delivery_fee):Package(sender_n, sender_addr, sender_c, sender_s, sender_Z, recipient_n,recipient_addr, recipient_c, recipient_s, recipient_Z,wei,cost)
{
	    settwo_day_delivery_fee(delivery_fee);	
}
double TwoDayPackage::gettwo_day_delivery_fee()
{
	return two_day_delivery_fee;
}
double TwoDayPackage::calculateCost()
{
	double result;
	result=Package::calculateCost()+two_day_delivery_fee;
	return result;
}
void TwoDayPackage::settwo_day_delivery_fee(double delivery_fee)
{
	two_day_delivery_fee=delivery_fee;
}

 
class OvernightPackage:public Package //繼承Package 使用網路上查詢到的解題方法資訊跟課本上的
{
	private:
		double overnight_delivery_fee;
	public:  
    OvernightPackage(string sender_n, string sender_addr, string sender_c,string sender_s,string sender_Z,string recipient_n,string recipient_addr,string recipient_c,string recipient_s, string recipient_Z, double wei,double cost, double delivery_fee);
	double calculateCost();
    double getovernight_delivery_fee();
    void setovernight_delivery_fee(double delivery_fee);
	
};
 
OvernightPackage::OvernightPackage(string sender_n, string sender_addr,string sender_c, string sender_s, string sender_Z, string recipient_n,string recipient_addr,string recipient_c,string recipient_s,string recipient_Z, double wei, double cost, double delivery_fee):Package(sender_n, sender_addr, sender_c, sender_s, sender_Z, recipient_n,recipient_addr, recipient_c, recipient_s, recipient_Z,wei,cost)
{
	setovernight_delivery_fee(delivery_fee);
}
void OvernightPackage::setovernight_delivery_fee(double delivery_fee)
{
	overnight_delivery_fee = delivery_fee;
}
double OvernightPackage::getovernight_delivery_fee()
{
	return overnight_delivery_fee;
}
double OvernightPackage::calculateCost()
{
	double result;
	result=(getcostperounce()+overnight_delivery_fee)*getweight();
	return result;
}
 
int main() //主程式
{
	OvernightPackage Pac1("Michael Jordan","My Street","Tokyo","Japan","089487","Scottie Pippen","Burgeon street","Tainan","Taiwan","080000",20.08,1.60,1.45);
	TwoDayPackage Pac2("Kobe Bryant","Club Street","Osaka","Japan","000751","Lebron James","Long avenue","Taipei","Taiwan","999999",18.88,1.00,2.45);
 
    cout<<"\nOvernight Delivery\n";
    cout<<"Sender:"<<Pac1.getsender_name()<<"\n";
    cout<<Pac1.getsender_address()<<","<<Pac1.getSendCity()<<","<<Pac1.getsender_state()<<","<<Pac1.getsender_ZIP()<<"\n";
    cout<<"\n";
    cout<<"Recipient:"<<Pac1.getrecipient_name()<<"\n";
    cout<<Pac1.getsender_address()<<","<<Pac1.getrecipient_city() <<"," <<Pac1.getrecipient_state() <<","<< Pac1.getrecipient_ZIP()<<"\n";
    cout<<"Cost= $"<<Pac1.calculateCost()<<"\n";
    cout<<"\n\n";
    cout<<"Two Day Delivery\n";
    cout<<"Sender:"<<Pac2.getsender_name()<<"\n";
    cout<<Pac2.getsender_address()<<","<<Pac2.getSendCity() <<","<<Pac2.getsender_state() <<","<< Pac2.getsender_ZIP()<<"\n";
    cout<<"\n";
    cout<<"Recipient:"<<Pac2.getrecipient_name()<<"\n";
    cout<<Pac2.getsender_address()<<","<<Pac2.getrecipient_city() <<","<< Pac2.getrecipient_state()<< ","<<Pac2.getrecipient_ZIP()<<"\n";
    cout<<"Cost= $" <<Pac2.calculateCost()<<"\n";

	return 0;
}