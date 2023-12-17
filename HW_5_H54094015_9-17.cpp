#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int M = 10;

class Date
{
public:
    Date(int=1,int=1,int=2000);
    void print();
    void nextDay();
private:
    int year;
    int month;
    int day;

};

Date::Date(int m,int d,int y){
    month = m;
    day = d;
    year = y;

    if ((day <= 0) || (day >= 32)){
        cout << "Day is limited between 1 and 31, you entered: "<<day<<"\nWrond input!"<<endl;
    }//確認輸入的日期沒有問題
    
    if ((month<=0) || (month>=13)){
        cout << "Month is limited between 1 and 12, you entered: "<<month<<"\nWrond input!"<<endl;  
    }//確認輸入的月份沒有問題
    
    if ((year<=1899) || (year>=2022)){
        cout << "Year is limited between 1900 and 2022, you entered: "<<year<<"\nWrond input!"<<endl;
    }//確認輸入的年份沒有問題
    
}

void Date::print(){
    cout<<month<<"/"<<day<<"/"<<year;
}

void Date::nextDay(){
    day+=1;	 //先從日期開始加
   	switch(month){		
        case 1: 
        case 3: 
        case 5: 
        case 7:
        case 8:
        case 10:  
            if(day==31){
                month=month+1;
                day=1;
            }               
            break;
        case 2: 
        case 4: 
        case 6: 
        case 9:
        case 11:
            if(day==30){
                month=month+1;
                day=1;
            }
            break;
        case 12: 
            if(day==31){
                year=year+1;
                month=1;
                day=1;
            break;
            }
    }//利用switch將各個月份不同天數情況調整+的方式
}
int main(){
    Date date1(12,27,2002);
    Date date2;

    cout<<"Date1: ";
    date1.print();
    cout<<endl;
    cout<<"Date2: ";
    date2.print();

    date2=date1;

    cout<<"\n\nAfter assignment, date2=" ;
    date2.print();
    cout<<endl;

    cout<<"\nStart nextDay:"<<endl;    
    for (int i=0;i<M;i++){ 
    date1.nextDay();
    cout<<endl;
    date1.print();
    }
}