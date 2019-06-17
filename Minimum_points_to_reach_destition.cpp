using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	   int n,m;
	   cin>>n>>m;
	   int a[n][m];
	   int dp[n][m];
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           cin>>a[i][j];
	           dp[i][j]=INT_MAX;
	       }
	   }
	   if(a[n-1][m-1]>=0)
	   {
	       dp[n-1][m-1]=1;
	   }
	   else
	   
	   {
	       dp[n-1][m-1]=1-a[n-1][m-1];
	   }
	   for(int i=n-1;i>=0;i--)
	   {
	       for(int j=m-1;j>=0;j--)
	       {
	           
	           if(i!=0 || j!=0){
	               //cout<<i<<" "<<j<<endl;
    	           if(i>0 && j>0)
    	           {
    	               if(dp[i][j]>a[i-1][j] && dp[i-1][j]>(dp[i][j]-a[i-1][j]))
    	               {
    	                   dp[i-1][j]=dp[i][j]-a[i-1][j];
    	                   //cout<<i<<j<<dp[i-1][j]<<endl;
    	               }
    	               else if(dp[i][j]<=a[i-1][j])
    	               {
    	                   dp[i-1][j]=1;
    	               }
    	               if(dp[i][j]>a[i][j-1] && dp[i][j-1]>dp[i][j]-a[i][j-1])
    	               {
    	                   dp[i][j-1]=dp[i][j]-a[i][j-1];
    	               }
    	               else if(dp[i][j]<=a[i][j-1])
    	               {
    	                   dp[i][j-1]=1;
    	               }
    	           }
    	           else if(i==0)
    	           {
    	               if(dp[i][j]>a[i][j-1] && dp[i][j-1]>dp[i][j]-a[i][j-1])
        	               {
        	                   dp[i][j-1]=dp[i][j]-a[i][j-1];
        	               }
        	               else if(dp[i][j]<=a[i][j-1])
        	               {
        	                   dp[i][j-1]=1;
        	               }
    	           }
    	           else if(j==0)
    	           {
    	               if(dp[i][j]>a[i-1][j] && dp[i-1][j]>dp[i][j]-a[i-1][j])
        	               {
        	                   dp[i-1][j]=dp[i][j]-a[i-1][j];
        	               }
        	               else if(dp[i][j]<=a[i-1][j])
        	               {
        	                   dp[i-1][j]=1;
        	               }
    	           }
	           }
	       }
	   }
	   cout<<dp[0][0]<<endl;
	}
	return 0;
}