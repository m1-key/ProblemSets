    #include <bits/stdc++.h>

    using namespace std;


    long long highestPowerof2(long long n) 
    { 
        // Invalid input 
        if (n < 1) 
            return 0; 
    
        long long res = 1; 
    
        // Try all powers starting from 2^1 
        for (long long i=0; i<8*sizeof(long long); i++) 
        { 
            long long curr = 1 << i; 
    
            // If current power is more than n, break 
            if (curr > n) 
            break; 
    
            res = curr; 
        } 
    
        return res; 
    } 
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {

            long long n;cin>>n;

            long long kmax=highestPowerof2(n);
            long long x;
            for( long long k=2;k<kmax;k++)
            {
                if(n%((1<<k)-1)==0)
                {
                 
                } 
            }
            
            cout<<kfin<<endl;




        }


    return 0;   
    }