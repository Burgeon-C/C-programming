#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int My_TICKS = 20;

class TimeandDate
{
public:
    TimeandDate(int=0,int=0,int=0,int=1,int=1,int=2000); // default constructor
    
        void setTime( int,int,int,int,int,int); // set hour, minute, second    
        void printUniversal(); // output time in universal-time format
        void printStandard(); // output time in standard-time format
        void Tick();
        
private:
        int hour; // 0 - 23 (24-hour clock format)
        int minute; // 0 - 59
        int second; // 0 - 59
        int year;
        int month;
        int day;
};// end class Time

// Time constructor initializes each data member to zero
TimeandDate::TimeandDate(int hour,int minute,int second,int month,int day,int year)
    {
        setTime( hour,minute,second,month,day,year); // validate and set time
    } // end Time constructor 課本建構者函式


    // print Time in universal-time format (HH:MM:SS)
void TimeandDate::printUniversal()
{
    cout<<"Time:"<< setfill('0') << setw(2) <<hour<<":"<< setw(2)<<minute<<":" <<setw(2)<<second<<"   "<<month<<"/"<<day<<"/"<<year;
} // end function printUniversal 課本函式

// print Time in standard-time format (HH:MM:SS AM or PM)
void TimeandDate::printStandard()
{
    cout<<"Time:"<<((hour==0 || hour==12 ) ? 12 : hour%12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour<12 ?"AM":"PM")<<"   "<<"Date:"<<month<<"/"<<day<<"/"<<year;
} // end function printStandard 課本函式

// set new Time value using universal time
void TimeandDate::setTime( int h, int mi, int s ,int mo ,int d, int y)
    {
        hour =(h>= 0 && h<24) ? h : 0;
        minute =(mi>=0 && mi<60) ? mi : 0;
        second =(s>=0 && s<60) ? s : 0;
        month = mo;
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
    } // end function setTime

void TimeandDate::Tick() //Tick先從秒開始做增加 
{
    second+= 1;
    if (second==60){
        second=0;
        minute++;
    }
    if (minute==60 ){
        minute=0;
        hour++;
    }
    if (hour==24){
        hour=0;
        day+=1;//從日期開始加
    }
    
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
    TimeandDate t;
        cout<<"Current Time & Date:"<<endl;
        t.setTime(23,59,50,06,02,2002);
        t.printStandard();
        cout<<"\n\nTime & Date after start ticking:"<<endl;
        
    for (int i=0;i<My_TICKS;i++){ 
        t.Tick();
        cout<<"\n";
        t.printStandard();
        
    }
    
}