#include<bits/stdc++.h>
using namespace std;
#define max1 200005
#define sz1 10001
#define mod 1000000007
#define moda 421412341324321ll
#define inf 1e18
#define ll long long int
#define debug(x) cout<<#x<<" "<<x<<endl
typedef pair<ll,ll> pr;
#define rte cout<<"Correct";exit(0);
vector<string> in1;
vector<int> freq;
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
  if(x.first<y.first)
  {
    return true;
  }
  else if(x.first==y.first)
  {
    if(freq[x.second]>freq[y.second])
    {
      return true;
    }
    return false;
  }
  return false;
}
int main(int argv,char** argc)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fstream cin;
  cin.open(argc[0],ios::in);//created a object read file data
  string query;
  while(!cin.eof())// loop is running until we reach end of file
  {
    string ch,ch1,num;
    getline(cin,ch);// used to read one line at a time
    stringstream s(ch);
    string temp;
    ll k=0;
    while(getline(s,ch1,','))// used to seprate strings in single line
    {
      if(k==0)
      {
        in1.push_back(query);
      }
      else
      {
        num=ch1;
      }
      k++;
    }
    ll x=0;
    for(ll i=0;i<num.length();i++)// convert frequency of string from string to integer
    {
      x=x*10+(num[i]-'0');
    }
    if(num.length()>0)
    freq.push_back(x);
  }
  query=arc[1];
  vector<pair<ll,ll> > ans;
  for(ll i=0;i<in1.size();i++)
  {
    ll n=in1[i].length();
    ll m=query.length();
    vector<vector<ll> > dp(2,vector<ll>(n+1,0));
    for(ll i=0;i<=n;i++)
    {
      dp[0][i]=i;
    }
    for(ll it=1;it<=m;it++)// used to check how many edit operations we have perform to convert current string to resultant string
    {
      for(ll j=0;j<=n;j++)
      {
        if(j==0)
        {
          dp[it%2][j]=i;
        }
        else if(in1[i][j-1]==query[it-1])
        {
          dp[it%2][j]=dp[(it-1)%2][j-1];
        }
        else
        {
          dp[it%2][j]=min(dp[(it-1)%2][j],min(dp[it%2][j-1],dp[(it-1)%2][j-1]))+1;
        }
      }
    }
    ll x=dp[m%2][n];
    if(ans.size()<5) // push if we have less than 5 strings in ans need not check any condition
    {
      ans.push_back({x,i});
    }
    else
    {
      for(ll j=0;j<5;j++) // if we have more than 5 strings then we have to check whether this better then any string present in the answer
      {
        if(ans[j].first>x)
        {
          ans[j].first=x;
          ans[j].second=i;
          break;
        }
        else if(ans[j].first==x)
        {
          if(freq[ans[j].second]<freq[i])
          {
            ans[j].first=x;
            ans[j].second=i;
            break;
          }
        }
      }
    }
  }
  sort(ans.begin(),ans.end(),cmp); // sorting answer according to their minimum edit operation and maximum frequency
  for(ll i=0;i<ans.size();i++)
  {
    cout<<in1[ans[i].second];
    if(i<4)
    {
      cout<<", ";
    }
    //cout<<ans[i].first<<" "<<freq[ans[i].second]<<endl;
  }
} 