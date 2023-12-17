#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Fig. 13.13: Employee.h
// Employee abstract base class.
class Employee
{
public:
Employee( const string &, const string &, const string & );
void setFirstName( const string & ); // set first name
string getFirstName() const; // return first name
void setLastName( const string & ); // set last name
string getLastName() const; // return last name
void setSocialSecurityNumber( const string & ); // set SSN
string getSocialSecurityNumber() const; // return SSN

// pure virtual function makes Employee abstract base class
virtual double earnings() const = 0; // pure virtual 
virtual void print() const; // virtual 
private:
string firstName;
string lastName;
string socialSecurityNumber;

}; // end class Employee

Employee::Employee( const string &first, const string &last,
const string &ssn )
: firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
// empty body
} // end Employee constructor

// set first name
void Employee::setFirstName( const string &first )
{
firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const string &last ){
    lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn )
{
 socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
return socialSecurityNumber;
} // end function getSocialSecurityNumber

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const{
cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber();
} // end function print


class SalariedEmployee : public Employee
{
public:
SalariedEmployee( const string &, const string &,
const string &, double = 0.0 );

void setWeeklySalary( double ); // set weekly salary
double getWeeklySalary() const; // return weekly salary

// keyword virtual signals intent to override 
virtual double earnings() const; // calculate earnings 
virtual void print() const; // print SalariedEmployee object
private:
double weeklySalary; // salary per week
}; // end class SalariedEmployee

// constructor
SalariedEmployee::SalariedEmployee( const string &first,const string &last, const string &ssn, double salary ): Employee( first, last, ssn )
{
setWeeklySalary( salary );
} // end SalariedEmployee constructor

// set salary
void SalariedEmployee::setWeeklySalary( double salary )
{
weeklySalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
return weeklySalary;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
return getWeeklySalary();
} // end function earnings

// print SalariedEmployee's information
void SalariedEmployee::print() const
{
cout << "\nsalaried employee: ";
Employee::print(); // reuse abstract base-class print function
cout << "\nweekly salary: " << getWeeklySalary();
}


class HourlyEmployee : public Employee
{
public:
HourlyEmployee( const string &, const string &,
const string &, double = 0.0, double = 0.0 );

void setWage( double ); // set hourly wage
double getWage() const; // return hourly wage

void setHours( double ); // set hours worked
double getHours() const; // return hours worked

// keyword virtual signals intent to override 
virtual double earnings() const; // calculate earnings 
virtual void print() const; // print HourlyEmployee object
private:
double wage; // wage per hour
double hours; // hours worked for week
}; // end class HourlyEmployee

// constructor
HourlyEmployee::HourlyEmployee( const string &first, const string &last,const string &ssn, double hourlyWage, double hoursWorked ): Employee( first, last, ssn )
{
setWage( hourlyWage ); // validate hourly wage
setHours( hoursWorked ); // validate hours worked
} // end HourlyEmployee constructor

// set wage
void HourlyEmployee::setWage( double hourlyWage )
{
wage = ( hourlyWage < 0.0 ? 0.0 : hourlyWage );
} // end function setWage

// return wage
double HourlyEmployee::getWage() const
{
return wage;
} // end function getWage

// set hours worked
void HourlyEmployee::setHours( double hoursWorked )
{
hours = ( ( ( hoursWorked >= 0.0 ) && ( hoursWorked <= 168.0 ) ) ?
hoursWorked : 0.0 );
} // end function setHours

// return hours worked
double HourlyEmployee::getHours() const
{
return hours;
} // end function getHours

// calculate earnings;
// override pure virtual function earnings in Employee
double HourlyEmployee::earnings() const
{
if ( getHours() <= 40 ) // no overtime
    return getWage() * getHours();
else
    return 40 * getWage() + ( ( getHours() - 40 ) * getWage() * 1.5 );
} // end function earnings

// print HourlyEmployee's information
void HourlyEmployee::print() const
{
cout << "\nhourly employee: ";
Employee::print(); // code reuse
cout << "\nhourly wage: " << getWage() <<"; hours worked: " << getHours();
}

class CommissionEmployee : public Employee
{
public:
CommissionEmployee( const string &, const string &,
const string &, double = 0.0, double = 0.0 );

void setCommissionRate( double ); // set commission rate
double getCommissionRate() const; // return commission rate

void setGrossSales( double ); // set gross sales amount
double getGrossSales() const; // return gross sales amount

// keyword virtual signals intent to override 
virtual double earnings() const; // calculate earnings 
virtual void print() const; // print CommissionEmployee object
private:
double grossSales; // gross weekly sales
double commissionRate; // commission percentage
}; // end class CommissionEmployee

// constructor
CommissionEmployee::CommissionEmployee( const string &first,const string &last, const string &ssn, double sales, double rate ): Employee( first, last, ssn )
{
setGrossSales( sales );
setCommissionRate( rate );
} // end CommissionEmployee constructor

// set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{
commissionRate = ( ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0 );
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
return commissionRate;
} // end function getCommissionRate

// set gross sales amount
void CommissionEmployee::setGrossSales( double sales )
{
grossSales = ( ( sales < 0.0 ) ? 0.0 : sales );
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
return grossSales;
} // end function getGrossSales

// calculate earnings;
// override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
return getCommissionRate() * getGrossSales();
} // end function earnings

// print CommissionEmployee's information
void CommissionEmployee::print() const{
cout << "\ncommission employee: ";
Employee::print(); // code reuse
cout << "\ngross sales: " << getGrossSales()<< "; commission rate: " << getCommissionRate();
}

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
BasePlusCommissionEmployee( const string &, const string &,
const string &, double = 0.0, double = 0.0, double = 0.0 );

void setBaseSalary( double ); // set base salary
double getBaseSalary() const; // return base salary

// keyword virtual signals intent to override 
virtual double earnings() const; // calculate earnings 
virtual void print() const; // print BasePlusCommissionEmployee object
private:
double baseSalary; // base salary per week
};

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn,double sales, double rate, double salary ): CommissionEmployee( first, last, ssn, sales, rate )
{
setBaseSalary( salary ); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
baseSalary = ( ( salary < 0.0 ) ? 0.0 : salary );
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
return baseSalary;
} // end function getBaseSalary

// calculate earnings;
// override pure virtual function earnings in Employee
double BasePlusCommissionEmployee::earnings() const
{
return getBaseSalary() + CommissionEmployee::earnings();
} // end function earnings

// print BasePlusCommissionEmployee's information
void BasePlusCommissionEmployee::print() const
{
cout << "\nbase-salaried ";
CommissionEmployee::print(); // code reuse
cout << "; base salary: " << getBaseSalary();
}

int main() //依據課本程式改動Driver funtion
{
void virtualViaReference( const Employee &); 
void virtualViaPointer( const Employee * const);
// set floating-point output formatting
cout << fixed << setprecision( 2 );
Employee *EmployeePtr = 0;

// create derived-class objects 
EmployeePtr = new SalariedEmployee(    //找網路上的方法做新的指標
"John", "Smith", "111-11-1111", 800 );
EmployeePtr->print();
cout << "\nearned $" << EmployeePtr->earnings() << "\n\n";
EmployeePtr = new HourlyEmployee (
"Karen", "Price", "222-22-2222", 16.75, 40 );
EmployeePtr->print();
cout << "\nearned $" << EmployeePtr->earnings() << "\n\n";
EmployeePtr = new CommissionEmployee (
"Sue", "Jones", "333-33-3333", 10000, .06 );
EmployeePtr->print();
cout << "\nearned $" << EmployeePtr->earnings() << "\n\n";
EmployeePtr = new BasePlusCommissionEmployee (
"Bob", "Lewis", "444-44-4444", 5000, .04, 300 );
EmployeePtr->print();
cout << "\nearned $" << EmployeePtr->earnings() << "\n\n";
return 0;
}

