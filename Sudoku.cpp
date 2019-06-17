using namespace std;

bool checkRow(int k,int a[][9],int i)
{
    for(int j=0;j<9;j++){
        if(a[i][j]==k)
            return true;}
    return false;
}
bool checkColumn(int k,int a[][9],int j)
{
    for(int i=0;i<j;i++){
        if(a[i][j]==k)
            return true;}
    return false;
}
bool checkGrid(int data,int a[][9],int i,int j)
{
    for(int k=0;k<3;k++){
        for(int l=0;l<3;l++)
        {
            if(a[k+i][l+j]==data)
                return true;
        }
    }
    return false;
}
bool allAsnd(int a[][9],int &i,int &j) {
    for(i=0;i<9;i++) {
	    for(j=0;j<9;j++) {
            if(a[i][j]==0)    
                return false;
	    }
	}
	return true;
}
bool isSafe(int grd[][9],int rw,int cl,int nm) {
    return (
        !checkRow(nm,grd,rw) &&
        !checkColumn(nm,grd,cl) &&
        !checkGrid( nm,grd, (rw-rw%3), (cl-cl%3))
        );
}

bool solve(int a[][9])
{
    int i,j;
    if(allAsnd(a,i,j)) return true;
    else{
	   for(int k=1;k<=9;k++)
	       if(isSafe(a,i,j,k))
	       {  
	           a[i][j]=k;
	           if(solve(a))
	           {
	               return true;
	           }
	           else 
	               a[i][j]=0;
	       }
	   }
	   return false;
}


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int a[9][9];
	    for(int i=0;i<9;i++)
	        for(int j=0;j<9;j++)
	            cin>>a[i][j];
	    if(solve(a)){
    	    for(int i=0;i<9;i++) {
        	    for(int j=0;j<9;j++)
                    cout<<a[i][j]<<" ";
	}
    cout<<endl;
	    }
	    else 
	        cout<<"-1\n";
	    
	}
	return 0;
}