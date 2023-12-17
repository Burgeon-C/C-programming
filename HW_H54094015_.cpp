#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
// Function to find all possible combinations by
// replacing key's digits with characters of the corresponding list
// 開檔案

ofstream PhoneNumberfile("PhoneNumberWordsGenerator.txt",ios::out);
void TofindCombinations(int keypad[],char index[10][3], string word, int input)
{
    // 檔案部分
    if (input == 7) {
        PhoneNumberfile<<word<<endl;
        return;
    }
 
    // Stores current digit 參考網路上的陣列使用
    int digit = keypad[input];
    
 
    // One by one replace the digit with each character 
    // 參考網路替換方法
    for (int i = 0; i < 3; i++) {
        
        TofindCombinations(keypad, index, word+index[digit][i], input + 1);
    }
}
 
// 主程式
int main()
{
int enter, keypad
// 檔案操作
ofstream PhoneNumberfile("PhoneNumberWordsGenerator.txt",ios::out);
if(!PhoneNumberfile){
    cerr<<"File couldn't be open"<<endl;
        exit(1);
 }
PhoneNumberfile<<"The number is:"<<enter<<"Combinations";

    
    char index[10][3] =
    {
        {}, {},        // 0 and 1 沒有對應字元
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y',},
    };
 
    // 輸入七位數電話
    cout<<"Please enter 7-digit phone number:(digits 2 through 9)"<<endl;
    cin>>enter;
 
    // 呼叫函式 找組合
    TofindCombinations(keypad , index , "",0);
    // 關閉檔案
    PhoneNumberfile.close();
 
    return 0;
}
//程式無法完整執行，希望助教教授逐步給分