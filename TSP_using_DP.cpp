using namespace std;
int a[12][12];
long long int miniSum;
bool check(bool visi[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(visi[i]==0){
            return 0;
        }
    }
    return 1;
}
void travel(bool visi[],long long sum,int n,int i)
{
    visi[i]=1;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(visi[i]==0){
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(miniSum>sum)
            miniSum=sum;
        visi[0]=0;
        return;
    }
    for(int j=0;j<n;j++)
    {
        
        if(visi[j]==0)
        {
            if(check(visi,n) && j==0){
                sum+=a[i][j];
                travel(visi,sum,n,j);
                sum-=a[i][j];
            }
            else if(j!=0)
            {
                sum+=a[i][j];
                travel(visi,sum,n,j);
                sum-=a[i][j];
            }
        }
    }
    visi[i]=0;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>a[i][j]; cout<<endl;
    	   //}
	    bool visi[n];
	    memset(visi,0,sizeof(visi));
        miniSum=INT_MAX;
	    for(int j=1;j<n;j++)
	    {
            long long int sum=a[0][j];
	        travel(visi,sum,n,j);
	        memset(visi,0,sizeof(visi));
	    }
	    cout<<miniSum<<endl;
	}
	return 0;
}