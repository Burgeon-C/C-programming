#include <iostream>
#include <iomanip>
using namespace std;
class  savingsAccount

{
 private:
    static double annualInterestRate; // static = shared, only one instance
    double savingsBalance;

 public:
    savingsAccount();
    savingsAccount(float b):savingsBalance(b){}
    static void modifyInterestRate(double);
    static double getInterestRate();
    void calculateMonthlyInterest(){
        savingsBalance+=(savingsBalance*annualInterestRate/12);
    }
    double getSavingsBalance(){
        return savingsBalance; //回傳金額
    }
};

    double savingsAccount::annualInterestRate=0.0;
    void savingsAccount::modifyInterestRate(double r){
        annualInterestRate=r;
    }
    double savingsAccount::getInterestRate(){
        return  annualInterestRate;  //回傳年利率
    }

int main()
{
    savingsAccount saver1(2000.0);
    savingsAccount saver2(3000.0);
    savingsAccount::modifyInterestRate(0.03);
    saver1.calculateMonthlyInterest();
    cout<<"Saver 1 account balance is "<<saver1.getSavingsBalance()<<" (Current Interest rate=0.03)"<<endl;
    saver2.calculateMonthlyInterest();
    cout<<"Saver 2 account balance is "<<saver2.getSavingsBalance()<<" (Current Interest rate=0.03)"<<endl;
    savingsAccount::modifyInterestRate(0.04);
    saver1.calculateMonthlyInterest();
    cout<<"Saver 1 account balance is "<<saver1.getSavingsBalance()<<" Current Interest rate=0.04)"<<endl;
    saver2.calculateMonthlyInterest();
    cout<<"Saver 2 account balance is "<<saver2.getSavingsBalance()<<" (Current Interest rate=0.04)"<<endl;
    system("Pause");
    return 0;
}


