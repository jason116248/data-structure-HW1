#include <iostream>
#include <queue>
using namespace std;
//string record[50]={0};
int flag=1,k=0,priority_num=100,flag2[10]= {0},arr[10]= {0};
string strArray=" ";//�h�����Ĥ@�ӳQ�ƦC���r��

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
            swap(*(List+i),*(List+j));  //�o��swap�i�H�M�w�n�r���ƦC������
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
            perm(List,i+1,n); //���򪺰��ƦC�ΦL�X�r��

            /*if(*(List+i)==*(List+j) && j!=i)
                flag = 0;*/
            swap(*(List+i),*(List+j)); //��Ʀb�Ĥ@�Ӧr�����ƦC�����ɡA���r��^��̤@�}�l�����A

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
