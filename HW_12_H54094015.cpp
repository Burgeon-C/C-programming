#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
class Account 
{
private:
    double balance;
public:
    Account(double initialBalance)
    :balance(initialBalance){
        if (initialBalance>=0.0)
            balance=initialBalance;
        cout<<"\nInitial Balance can't be negative! Set default value to zero!";
        balance=0.0;       
    }
    virtual bool debit(double amount){
        if (amount>balance){
            cout<<"Debit amount exceed current account balance!";
            return false;
        }
        else{
            balance-=amount;
            return true;
        }    
    }
    virtual void credit(double amount){
        balance+=amount;
    }       
    virtual double getBalance(){
        return balance;
    }
    virtual void setBalance(double newBalance){
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
    virtual bool debit(double amount){
        bool success=true;Account::debit(amount);
        if (success){
            chargefee();
            return true;
        }
        else return false;
    }
    virtual void credit(double amount){
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
    vector<Account*> accounts(4);
   	accounts[ 0 ] = new SavingAccount( 90.0, .03 );
	accounts[ 1 ] = new CheckingAccount( 140.0, 1.0 );
	accounts[ 2 ] = new SavingAccount( 300.0, .05 );
	accounts[ 3 ] = new CheckingAccount( 500.0, .5 );

	cout << fixed << setprecision( 2 );

	// loop through vector, prompting user for debit and credit amounts 根據課本及網路上的資料用Vector
	for ( size_t i = 0; i < accounts.size(); i++ )
	{
		cout << "Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << endl;/* Call the getBalance function through Account pointer i */;
		double withdrawalAmount = 0.0;
		cout << "\nEnter an amount to withdraw from Account " << i + 1 << ": ";
		cin >> withdrawalAmount;
		accounts[i]->debit(withdrawalAmount);/* Call the debit function through Account pointer i */
		double depositAmount = 0.0;
		cout << "Enter an amount to deposit into Account " << i + 1 << ": ";
		cin >> depositAmount;
		accounts[i]->credit(depositAmount);/* Call the credit function through Account pointer i */

		// downcast pointer
		SavingAccount *savingAccountPtr =dynamic_cast<SavingAccount* > (accounts[i]);
		/* Write a dynamic_cast operation to to attempt to downcast Account pointer i to a SavingsAccount pointer */
		
		// if Account is a SavingsAccount, calculate and add interest
		if ( savingAccountPtr!=0)
		{
			double interestEarned = savingAccountPtr->calculateInterest()/* Call member function calculateInterest through savingsAccountPtr */;
			cout << "Adding $" << interestEarned << " interest to Account " << i + 1 << " (a SavingsAccount)" << endl;
			savingAccountPtr->credit(interestEarned);/* Use the credit function to credit interestEarned to the SavingsAccount pointed to by savingsAccountPtr*/
		} // end if
		
		cout << "Updated Account " << i + 1 << " balance: $" << accounts[i]->getBalance() /* Call the getBalance function through Account pointer i */ << "\n\n";
	} // end for
return 0;
} // end main
