#include <iostream>
#include <iostream>
#include <exception>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    double weight,height,BMI;
    cout<<"~Calculating BMI for you~" <<endl;
    cout<<"Input your weight(kg) and height(cm): ";     // 使用者端輸入體重與身高資料
    cin>>weight>>height;   
    BMI=weight/(height/100*height/100);      // BMI計算與分類

    try {   //try區塊內含可能傳回例外的程式碼
        if(BMI<18.5) {
            throw "You're in the underweight range";
        } 
        if(BMI>=18.50 && BMI<=24.99){
            throw "You're in the healthy weight range";
        } 
        if(BMI>=25.00 && BMI<29.99){
            throw "You're in the overweight range";
        } 
        if(BMI>=30.00 && BMI<=39.99)
            throw "You're in the obese range";

    }
    catch (const char* exception) { //例外處理程式
        cout<<"\nYour BMI:"<<BMI<<"\n";

        cout<<"Exception message:"<<exception;
    }       

    return 0;
}