#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct stu{
    char num[4];
    char name[20];
    float a[8]={0};
    float s;
}st[10];
int main()
{
    int n,k;
    ifstream putin1("/Users/s20181102936/Desktop/student.txt");
    ifstream putin2("/Users/s20181102936/Desktop/caipan.txt");
    ofstream putout ("/Users/s20181102936/Desktop/score1.txt ");
    if(putin1.is_open())
    {
        if(putin2.is_open())
        {
            for(k=0;k<4;k++)
            {
                putin1>>st[k].num>>st[k].name;
                for (int i=0;i<7;i++)
                {
                    putin2>>st[k].a[i];
                }
            }
            putin2.close();
        }
        putin1.close();
    }
    if(putout.is_open())
    {
        for(k=0;k<4;k++)
        {
            for (int i=0;i<7;i++)
            {
                for(int j=1;j<7;j++)
                {
                    if(st[k].a[j-1]>st[k].a[j])
                    {
                        n=st[k].a[j-1];
                        st[k].a[j-1]=st[k].a[j];
                        st[k].a[j]=n;
                    }
                }
            }
        }
        for(k=0;k<4;k++){
            st[k].s=0;
            for (int i=1;i<6;i++)
            {
                st[k].s+=st[k].a[i];
            }
        }
        for(k=0;k<4;k++)
        {
            putout<<st[k].num<<" "<<st[k].name<<" ";
            for (int i=1;i<6;i++)
            {
                putout<<st[k].a[i]<<" ";
                
            }
            putout<<st[k].s/5<<endl;
        }
        putout.close();
    }
    return 0;
}

