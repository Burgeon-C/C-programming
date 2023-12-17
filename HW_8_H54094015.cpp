#include<iostream>
#include <iomanip>
#include <string>

using namespace std;

class DegreeAngle {
    public:
        DegreeAngle(): angle(1000)  // 透過 initializer 設定超出的default值
        { 
            if (angle <0||angle>=360) {  // 確認角度數範圍
                angle=90;    
            }
        }
        // ~DegreeAngle();
        
        void operator - (int sub) {   //減法
            angle=angle-sub;
        }
        void operator + (int add) {   //加法
            angle=angle+add;
        }
        void show() const {       
            cout<<"Your DegreeAngle is: "<<angle<<endl; //const 無法改變成員內容
        }
        private:
        int angle; // 一個整數角度
};

int main() {
    DegreeAngle BUR;
    BUR+(100);     // 加addition=100,減subtraction=50; 寫data
    BUR.show();    // 讀 data show出來
    BUR-(50);
    BUR.show();
}