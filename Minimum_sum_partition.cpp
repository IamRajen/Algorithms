using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];
	    }
	    //sort(a,a+n);
	    int dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	        dp[i][0]=1;
	    for(int i=1;i<=sum;i++)
	        dp[0][i]=0;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(j<a[i-1])
	                dp[i][j]=dp[i-1][j];
	            else if(dp[i-1][j-a[i-1]]==1 || dp[i-1][j]==1)
	            {
	                dp[i][j]=1;
	            }
	            else
	                dp[i][j]=0;
	        }
	    }
	   
	   int mini;
	   for(int i=sum/2;i>=0;i--)
	   {
	       if(dp[n][i])
	       {
	           mini=sum-(i*2);
	           break;
	           
	       }
	   }
	   cout<<mini<<endl;
	    
	    
	    
	}
	return 0;
}