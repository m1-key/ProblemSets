#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;cin>>t;
    while(t--)
    {
        int arr[3];
        for(int i=0;i<3;i++)
            cin>>arr[i];
        int count =0;
        sort(arr,arr+3);
        swap(arr[0],arr[2]);

        int f1=1,f2=1,f3=1,f4=1,f5=1,f6=1,f7=1;

        if(arr[0]==0 && arr[1]==0 && arr[2] ==0)
        {
            cout<<0<<endl;
            continue;
        }
        int i=0;
        while(i<=7)
        {
            if(arr[0]>0 && f5)
            {
                count++;
                f5=0;
                arr[0]--;
            }

           else if(arr[1]>0 && f6)
            {
                count++;
                f6=0;
                arr[1]--;
            }


          else  if(arr[2]>0 && f7)
            {
                count++;
                f7=0;
                arr[2]--;
            }


           else if(arr[0]>0  && arr[1]>0 && f2)
            {
                count++;
                f2=0;
                arr[0]--;
                arr[1]--;
            }
           else if(arr[1]>0  && arr[2]>0 && f3)
            {
                count++;
                f3=0;
                arr[2]--;
                arr[1]--;
            }
           else if(arr[0]>0  && arr[2]>0 && f4)
            {
                count++;
                f4=0;
                arr[0]--;
                arr[2]--;
            }
           else if(arr[0]>0 && arr[1]>0 && arr[2]>0 && f1)
            {
                count++;
                f1=0;
                arr[0]--;
                arr[1]--;
                arr[2]--;
            }
            i++;
    }
    cout<<count<<endl;
    }
}
