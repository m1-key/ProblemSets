    #include <bits/stdc++.h>

    using namespace std;



    int findMaxSquareWithAllZeros(int** arr, int row, int col){

        /* Don't write main().
         *  Don't read input, it is passed as function argument.
         *  Return output and don't print it.
         *  Taking input and printing output is handled automatically.
         */


        int dp[row][col];

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dp[row][col]=0;


        for(int i=0;i<row;i++)
        {
            if(arr[0][i]==1)
                dp[0][i]=0;
            else
                dp[0][i]=1;
        }

        for(int j=0;j<col;j++)
        {
            if(arr[j][0]==1)
                dp[j][0]=0;
            else
                dp[j][0]=1;
        }

        cout<<endl<<"madarrrrr "<<endl;
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++)
            {
                if(arr[i][j]==1)
                {dp[i][j]=0;continue;}
                if(dp[i-1][j-1]==0 && arr[i][j]==0)
                {
                    dp[i][j]=1;
                    continue;}

                if(arr[i][j]==0 && dp[i-1][j-1]>0)
                {
                    int flag =1;
                    int k=dp[i-1][j-1];
                    for(int m = 0;m<k;m++)
                    {
                        if(dp[i-1][j-1-m]==0)
                            flag=0;
                        if(dp[i-1-m][j-1]==0)
                            flag=0;
                    }
                    if(flag==1)
                        dp[i][j]=dp[i-1][j-1]+1;
                }

            }

            }
            int max=0;
            for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            if(dp[i][j]>max)
                max=dp[i][j];
            }

            for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            cout<<dp[i][j]<<" ";

            cout<<endl;
            }
        return max;


    }



    int main()
    {
        int row,col;cin>>row>>col;

        int **arr = new int*[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin>>arr[i][j];
            }
        }


        cout<<findMaxSquareWithAllZeros(arr,row,col);
        delete arr;

    return 0;
    }
