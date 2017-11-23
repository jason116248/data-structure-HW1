#include <iostream>
#include <queue>
using namespace std;
//string record[50]={0};
int flag=1,k=0,priority_num=100,flag2[10]= {0},arr[10]= {0};
string strArray=" ";//去紀錄第一個被排列的字母

int stairs(int num)
{
    int product = 1;
    for(int i=1; i<= num; i++)
        product*=i;
    return product;
}
void perm(char *List,int i,int n)
{
    string rec1;
    int j;
    int X;

    if(i==n)
    {
        for(int num=k-1; num>0; num--)
        {
            if( *(List+0)==strArray.at(num) )
            {
                flag = 0;
                break;
            }
        }

        /*for(X=9;X>0;X--)
        {
            if(arr[X]!=0)
            {
                flag2[X]--;
                flag = 0;
                break;
            }
        }
        if(X==0)
            flag = 1;*/

            for(j=0; j<=n; j++)
            {

                if(flag==1)
                {
                    cout << *(List+j) ;
                }
            }

        if(flag)
            cout << endl;

    }
    else
    {

        for(j=i; j<=n; j++)
        {
            swap(*(List+i),*(List+j));  //這個swap可以決定好字母排列的順序
            if(*(List+i)==*(List+j) && j!=i)
                flag = 0;

            if(i!=0)
            {
                if(i==j)
                    rec1+=*(List+i);
                else if(j > i)
                {
                    /*if(i==1)
                    {
                        cout << "flag: " << flag << endl;
                        //cout << "string's charater: ";
                    }*/

                    for(int z=0; z<rec1.length(); z++)
                    {
                        //cout <<" string letter: "<<rec1.at(z) << endl;

                        if(*(List+i)==rec1.at(z))
                        {
                            flag = 0;
                            flag2[i] = stairs(n-i);
                            arr[i] = i;
                            break;
                        }

                    }
                    rec1+=*(List+i);
                }

            }

            if(i==0)
            {
                flag = 1;
                k++;
                strArray+=*(List+0);
                //cout << "str: " << strArray << endl;
            }
            perm(List,i+1,n); //持續的做排列或印出字串

            /*if(*(List+i)==*(List+j) && j!=i)
                flag = 0;*/
            swap(*(List+i),*(List+j)); //當排在第一個字母的排列完成時，讓字串回到最一開始的狀態

            if(j==n)
            {
                flag = 1;
            }
            //cout << flag << endl;

        }

    }

}
int main()
{
    string str;
    int length;

    cout << "enter the string" << endl;
    getline(cin,str);
    cout << endl;
    length = str.length();
    perm(&(str.at(0)),0,length-1);
    return 0;
}
