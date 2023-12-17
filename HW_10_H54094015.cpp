#include<iostream>
#include <iomanip>
#include <string>
using namespace std;
class Account 
{
private:
    double balance;
public:
    Account(double initialBalance){
        if (initialBalance>=0.0){
            balance=initialBalance;
        }
        else {
            cout<<"\nInitial Balance can't be negative! Set default value to zero!";
            balance=0.0;
        }
    }
    bool debit(double amount){
        if (amount>balance){
            cout<<"Debit amount exceed current account balance!";
            return false;
        }
        else{
            balance-=amount;
            return true;
        }    
    }
    void credit(double amount){
        balance+=amount;
    }       
    double getBalance(){
        return balance;
    }
    void setBalance(double newBalance){
        balance=newBalance;
    }

};

class SavingAccount: public Account
{
private:
    double interestrate;
public:
    SavingAccount(double initialBalance,double rate):Account(initialBalance)
    {
        if (rate>=0.0){
            interestrate=rate;
        }
        else{
            cout<<"Interest rate should>=0.0!";
        }
    }
    double calculateInterest(){
        return getBalance() *interestrate;
    }

};
class CheckingAccount:public Account
{
public:
    CheckingAccount(double initialBalance,double fee):Account(initialBalance)
    {
        if (fee>=0.0){
            transactionfee=fee;
        }
        else cout<<"Charging transaction fee should >=0.0!";
    }
    bool debit(double amount){
        bool success=true;Account::debit(amount);
        if (success){
            chargefee();
            return true;
        }
        else return false;
    }
    void credit(double amount){
        Account::credit(amount);
        chargefee();
    }
private:
    double transactionfee;
    void chargefee(){
        setBalance(getBalance()-transactionfee);
        cout<<"$"<<transactionfee<<" "<<"Transaction Fee is charged"<<endl;

    }
};

int main(){
    Account e1(-50);
    Account a1(50.0);
    SavingAccount a2(25.0,0.3);
    CheckingAccount a3(80.0,5.0);

    cout<<fixed<<setprecision(2);

    cout<<"\na1 initial balance:"<<a1.getBalance()<<endl;
    cout<<"a2 initial balance:"<<a2.getBalance()<<endl;
    cout<<"a3 initial balance:"<<a3.getBalance()<<endl;

    a1.debit(20.0);
    a1.credit(40.0);
    a1.credit(-30.0);

    cout<<"\na1 balance after testing="<<a1.getBalance()<<endl;
    
    double interestearned =a2.calculateInterest();
    a2.credit(interestearned);
    cout<<"\nAdding interest(After caculation) $"<<interestearned<<" to a2"<<"\na2 balance after testing="<<a2.getBalance()<<endl<<endl;

    a3.debit(20.0);
    a3.debit(12.0);
    a3.credit(5.0);

    cout<<"a3 balance after testng="<<a3.getBalance()<<endl;
    return 0;
}
