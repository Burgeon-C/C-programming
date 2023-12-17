#include<iostream>
#include <iomanip>
#include <ctime>
using namespace std;

template <class T>
void Sort(T X[],T Y[],T size){  //�]�w�@��template Sort�禡�̭����T�ӰѼ�
    for (int i = 1; i <=size; i++) { //�ثe�n�B�z�����
        int key=X[i]; //�ΨӦs�n��J��
        int j = i - 1; //�]�ܼ�j�O��P�_�ƧǸ�ƪ��e�@�����
		for (j = i - 1; j > -1 && key> X[j]; j--){ //�T�{�e�@����Ƴ��O�ƧǦn����ƶ}�l������Ƨ�
            if(X[j+1] > X[j])
            { //�P�_�ñƧ�
                int tem = X[j+1];  //�]�@int�ܼ�tem�Ȯ��x�s
                X[j+1] = X[j];     
                X[j] = tem;        //�Ƨǥ洫
                key = X[j];         
                
                tem=Y[j+1];
                Y[j+1]=Y[j];
                Y[j]=tem;   //�A�N��Ƥ��e�Ƨǥ洫���P�ɤ]�N������쪺row�Ȱ��洫

            }
            else{
                break;
            }
		}   
    }
    cout<<"�w�ƧǸ��=[ "; //���F����X�����G�iŪ�ʤ���n
    for(int k=0; k<size; k++){
        cout<<X[k]<<" ";   //�@�@�L�X�ƧǹL��c���ƶq���(�Ѥj��p)  
    }
    cout<<"]"<<endl;
    cout<<"�����쪺rows=[ ";
    for(int k=0; k<size; k++){
        cout<<Y[k]<<" ";   //�@�@�L�X�Ƨǫ�c���ƶq��ƹ����쪺row(�P�˥Ѥj��p)
    }
    cout<<"]"; //���F����X�����G�iŪ�ʤ���n   
}

int main()    //�D�{��
{
    srand(time(NULL));  //�üƺؤl
    int n; //�ܼ�n�x�s�}�C�j�p
    int counter = 0; //�]�wcounter �ܼƷǳƥΨӭp��c
    int tempCounter = 0;  //�]�wteamcounter �ܼƷǳƥΨӭp����ֿn��c�ƶq
    cout<<"Please input the array size(10~20)"<<endl; //��J�}�C�j�p
    cin>>n;
    
    if(n>20 || n<10){
        cout<<"Wrong input,terminated"; //���ҿ�J��n�d�� �Y�W�X�d��h�פ�{��
        return 0;
        
    }
    char A[20][20] = {};  //�]�w�@��char���A���}�C
            
	for(int i = 0; i <n; i++)
	{
		for(int j = 0; j <n; j++)
		{
            switch(rand()%5){  //switch������C�����N���ͪ��ư��H5(���ͤ��ر��p)
                case 0:        //���P�H�����p���ͭ^��r����i�}�C
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

    int B[21]={}; //����B�}�C�s��U�Cc���ƶq
    int index[21]={};//����index�}�C����row index
    for(int i=0; i<=n; i++){
        index[i]=i+1;  //�Nrow 1,2,3�̧ǫ�����index�}�C
    }
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            if(A[i][j]=='c'){
                counter++;  //�bn*n���}�C���C���@��c�N�bcounter+1
            }
           
        }    
    cout<<"Row["<<i+1<<"]"<<"��"<<counter-tempCounter<<"��c"<<endl; //��X���X��c
    B[i]=(counter-tempCounter); //�Nn row���`�@���X��c��h(n-1)��row�ֿn��c �i�o�ӧOrow ��c
    tempCounter=counter;  //�C����s�ֿn��c
    }

    cout<<"���ƧǸ��=[ "; //�W�[��X���G�iŪ��
    for(int k=0; k<n; k++){
        cout<<B[k]<<" ";   //�L�X���ƧǸ��    
    }

    cout<<"]"<<endl;  //�W�[��X���G�iŪ��
    
    Sort<int>(B,index,n); //�I�stemplate ����sort��ƪ����e B�����ƧǪ�c�ƶq�}�C 
                            //index��row1~n���}�C n���ϥΪ̿�J��array size//
    
	system("pause");
	return 0;
}