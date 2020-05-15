#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
void PrintStack(stack<string> s)
{
    if (s.empty())
        return;
    string x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}
//krutikas code
/*string simplifyPath(string A) {

    if(A.size()==1)
       return "/";
    int pos=0;
    string temp="";
    string res="";
    int prevpos=0;
    int flag=0;
    stack<string> sol;
    for(int i=0;i<A.size();i++)
    {
       // PrintStack(sol);
      //  cout<<endl;
        if(A[i]=='/')
        {
            prevpos=pos+1;
            pos=i;
            flag=1;
        }
       // cout<<"pos::"<<pos<<"prevpos ::"<<prevpos<<endl;
        if(pos>=prevpos && flag==1)
        {
            temp=A.substr(prevpos,pos-prevpos);
            //cout<<"temp =  "<<temp<<endl;
            if(temp==".."&&!sol.empty())
                sol.pop();
            else if(temp!="."&&temp!=".."&&temp!="")
                sol.push(temp);
            temp="";
            flag=0;
        }

    }
    temp=A.substr(pos+1);
    if(temp==".."&&!sol.empty())
        sol.pop();
    if(temp!="."&&temp!=".."&&temp!="")
    sol.push(temp);
    //cout<<"stack :"<<endl;
    //PrintStack(sol);
    //cout<<endl;
    if(sol.empty())
        return "/";
    while(!sol.empty())
    {
        string s=sol.top();
        reverse(s.begin(),s.end());
        res+=s;
        res+='/';
        sol.pop();
    }
    //cout<<res<<endl;
    reverse(res.begin(),res.end());
    if(res[res.length()-1]=='/')
        res.erase(res.end()-1,res.end());
    return res;
}
//prakritis code
string simplifyPath(string A)
{
    stack<string> B;
    int n=A.size();

    for(int i=1;i<n;i++)
    {
        if(A[i]=='.')
        {
            if(i+1<n && A[i+1]=='.')
            {
                if(!B.empty())
                    B.pop();
                i++;
            }
        }
        else
        {
            string t="";
            while(i<n && A[i]!='/')
            {
                t+=A[i];
                i++;
            }
            B.push(t);
        }
    }
    string res="";
    while(!B.empty())
    {
        res="/"+B.top()+res;
        B.pop();
    }

    if(res=="")
        return "/";
    return res;
}
*/
//prabhaths code
string simplifyPath(string A) {
    int n=A.length();
    string res="";
    string ans="";
    stack<string>s;
    for(int i=1;i<n;i++)
    {
        if(A[i]>='a'&&A[i]<='z')
            res+=A[i];
        else if(A[i]=='/'&&A[i-1]!='.')
            {
                if(res.length()!=0)
                    s.push(res);
                res="";
            }
        else if(A[i]=='.'&&A[i+1]=='.'&&i!=n-1)
            if(!s.empty())
                s.pop();

    }
    //cout<<res;
    s.push(res);
    while(!s.empty())
    {
        string st=s.top();
        reverse(st.begin(),st.end());
        ans+=st;
        ans+='/';
        s.pop();
    }

    reverse(ans.begin(),ans.end());
    if(ans[ans.length()-1]=='/')
        ans.erase(ans.end()-1,ans.end());
    return ans==""?"/":ans;

}
int main()
{
    string s="/./.././ykt/xhp/nka/eyo/blr/emm/xxm/fuv/bjg/./qbd/./../pir/dhu/./../../wrm/grm/ach/jsy/dic/ggz/smq/mhl/./../yte/hou/ucd/vnn/fpf/cnb/ouf/hqq/upz/akr/./pzo/../llb/./tud/olc/zns/fiv/./eeu/fex/rhi/pnm/../../kke/./eng/bow/uvz/jmz/hwb/./././ids/dwj/aqu/erf/./koz/..";
    string ans=simplifyPath(s);
    cout<<ans;
}
