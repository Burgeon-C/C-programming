#include<iostream>
#include <iomanip>
#include <ctime>
using namespace std;

template <class T>
void Sort(T X[],T Y[],T size){  //設定一個template Sort函式裡面有三個參數
    for (int i = 1; i <=size; i++) { //目前要處理的資料
        int key=X[i]; //用來存要輸入的
        int j = i - 1; //設變數j是域判斷排序資料的前一筆資料
		for (j = i - 1; j > -1 && key> X[j]; j--){ //確認前一筆資料都是排序好的資料開始比較做排序
            if(X[j+1] > X[j])
            { //判斷並排序
                int tem = X[j+1];  //設一int變數tem暫時儲存
                X[j+1] = X[j];     
                X[j] = tem;        //排序交換
                key = X[j];         
                
                tem=Y[j+1];
                Y[j+1]=Y[j];
                Y[j]=tem;   //再將資料內容排序交換的同時也將其對應到的row值做交換

            }
            else{
                break;
            }
		}   
    }
    cout<<"已排序資料=[ "; //為了讓輸出的結果可讀性比較好
    for(int k=0; k<size; k++){
        cout<<X[k]<<" ";   //一一印出排序過後c的數量資料(由大到小)  
    }
    cout<<"]"<<endl;
    cout<<"對應到的rows=[ ";
    for(int k=0; k<size; k++){
        cout<<Y[k]<<" ";   //一一印出排序後c的數量資料對應到的row(同樣由大到小)
    }
    cout<<"]"; //為了讓輸出的結果可讀性比較好   
}

int main()    //主程式
{
    srand(time(NULL));  //亂數種子
    int n; //變數n儲存陣列大小
    int counter = 0; //設定counter 變數準備用來計算c
    int tempCounter = 0;  //設定teamcounter 變數準備用來計算剛剛累積的c數量
    cout<<"Please input the array size(10~20)"<<endl; //輸入陣列大小
    cin>>n;
    
    if(n>20 || n<10){
        cout<<"Wrong input,terminated"; //驗證輸入的n範圍 若超出範圍則終止程式
        return 0;
        
    }
    char A[20][20] = {};  //設定一個char型態的陣列
            
	for(int i = 0; i <n; i++)
	{
		for(int j = 0; j <n; j++)
		{
            switch(rand()%5){  //switch的條件每次都將產生的數除以5(產生五種情況)
                case 0:        //不同隨機情況產生英文字母放進陣列
                    A[i][j]='a';
                    break; 
                case 1: 
                    A[i][j]='b'; 
                    break; 
                case 2: 
                    A[i][j]='c';
                    break; 
                case 3: 
                    A[i][j]='d'; 
                    break; 
                case 4:
                    A[i][j]='e'; 
                    break;
            } 
    
			cout<<A[i][j]<<"  ";
		}
		cout << endl;
	}

    int B[21]={}; //產生B陣列存放各列c的數量
    int index[21]={};//產生index陣列紀錄row index
    for(int i=0; i<=n; i++){
        index[i]=i+1;  //將row 1,2,3依序指派到index陣列
    }
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            if(A[i][j]=='c'){
                counter++;  //在n*n的陣列中每找到一個c就在counter+1
            }
           
        }    
    cout<<"Row["<<i+1<<"]"<<"有"<<counter-tempCounter<<"個c"<<endl; //輸出有幾個c
    B[i]=(counter-tempCounter); //將n row中總共有幾個c減去(n-1)的row累積的c 可得個別row 的c
    tempCounter=counter;  //每次更新累積的c
    }

    cout<<"未排序資料=[ "; //增加輸出結果可讀性
    for(int k=0; k<n; k++){
        cout<<B[k]<<" ";   //印出未排序資料    
    }

    cout<<"]"<<endl;  //增加輸出結果可讀性
    
    Sort<int>(B,index,n); //呼叫template 執行sort函數的內容 B為為排序的c數量陣列 
                            //index為row1~n的陣列 n為使用者輸入的array size//
    
	system("pause");
	return 0;
}