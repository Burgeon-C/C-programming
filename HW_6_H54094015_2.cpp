#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int=0,int=0,int=0);

        Time &setTime(int,int,int);
        Time &setHour(int);
        Time &setMinute(int);
        Time &setSecond(int);

        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        void printUniversal() const;
        void printStandard() const;   // 按照課本程式碼    
};
Time::Time(int hr,int min,int sec){
    setTime(hr,min,sec);
}
Time &Time::setTime(int h,int m,int s){
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this;
}
Time &Time::setHour(int h){
    hour=(h>=0 && h<24) ? h : 0;
    return *this;
}
Time &Time::setMinute(int m){
    minute=(m>=0 && m<60) ? m : 0;
    return *this;
}
Time &Time::setSecond(int s){
    second=(s>=0 && s<60) ? s : 0;
    return *this;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
int Time::getSecond() const{
    return second;
}
void Time::printStandard() const{
    cout<<((hour==0 || hour==12) ? 12 : hour%12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour<12 ? " AM" : " PM");
}
void Time::printUniversal() const{   // 利用更動printUniversal把時分轉換為秒再和在一起
    cout<<hour*3600+minute*60+second<<"seconds"<<endl;
}

int main(){
    Time t;
    t.setHour(18).setMinute(30).setSecond(22);
    cout<<"Standard time:";
    t.printStandard();
    cout<<endl;
    cout<<"Universal time(in seconds): "; // 重新以秒顯示時間
    t.printUniversal();
    cout<<endl;
    cout<<"Your new universal time in seconds: ";   
    t.setTime(10,9,14).printUniversal();
    cout<<endl;
    cout<<"Your new universal time in seconds: ";
    t.setTime(19,05,03).printUniversal();
    cout<<endl;
    cout<<"Your new universal time in seconds: ";
    t.setTime(23,55,55).printUniversal();
    cout<<endl;
    cout<<"Feel free to input your own time, and we'll convert it to seconds";
}