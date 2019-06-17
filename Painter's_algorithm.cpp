using namespace std;

int fun(long long int limit,int a[],int n)
{
    int stu=1,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>limit)
        {
            sum=a[i];
            stu++;
        }
    }
    return stu;
}


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long int low=0;
	    long long int sum=0;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	        if(low<a[i])
	            low=a[i];
	    }
	    int m;
	    cin>>m;
	    long long int high=sum;
	    long long int minimum=(low+high)/2;
	    if(n<m){
	        cout<<"-1\n";
	    }
	    else{
    	    while(low<=high)
    	    {
    	        long long int mid=(low+high)/2;
    	        int stu=fun(mid,a,n);
    	        if(stu>m)
    	        {
    	            low=mid+1;
    	        }
    	        else if(stu<=m)
    	        {
    	            high=mid-1;
    	        }
    	    }
    	    cout<<low<<endl;
	    }   
	}
	return 0;
}