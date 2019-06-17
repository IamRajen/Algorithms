using namespace std;
const int ALPHABET_SIZE = 26; 
  
  
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    bool flag; 
}; 
  
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->flag = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
  
    pCrawl->flag = true; 
} 
  
void print(struct TrieNode *root,vector<char> v)
{
    if(root->flag)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<" ";
    }
    TrieNode  *temp=root;
    int flag=0;
    for(int i=0;i<26;i++)
    {
        if(temp->children[i]){
            flag=1;
            char c=i+'a';
            v.push_back(c);
            print(temp->children[i],v);
            v.pop_back();
        }
    }
    
}

bool search(string s,struct TrieNode *root)
{
    //cout<<s<<endl;
    vector<char> v;
    for(int i=0;i<s.length();i++)
    {
        v.push_back(s[i]);
        int index = s[i] - 'a';
        if(root->children[index])
        {
            root=root->children[index];
            
        }
        else 
        {
            cout<<"0";
            return false;
        }
    }
    print(root,v);
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<string> v;
	    for(int i=0;i<n;i++)
	    {
	        string s;
	        cin>>s;
	        v.push_back(s);
	    }
	    string s;
	    cin>>s;
	    struct TrieNode *root = getNode();
	    for(int i=0;i<n;i++)
	    {
	        string s=v[i];
	        insert(root,s);
	    }
	    string s1="";
	    for(int i=0;i<s.length();i++)
	    {
	        s1+=s[i];
	        search(s1,root);
	        cout<<endl;
	    }
	    
	}
	return 0;
}