// You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

// Notes:

// Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
// For example,

// S = 010

// Pair of [L, R] | Final string
// _______________|_____________
// [1 1]          | 110
// [1 2]          | 100
// [1 3]          | 101
// [2 2]          | 000
// [2 3]          | 001

// We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1,1]
// Another example,

// If S = 111

// No operation can give us more than three 1s in final string. So, we return empty array [].

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

//this method excceds in time limit cause O(N^2)
//logic here was to just make substrings and flip bits an left and right substring ancd check if
//i can generate more ones this way

vector<int> flip(string A) {
    int n=A.size();
    int t1=count(A.begin(),A.end(),'1');
    vector<int>res;
    int q=0,w=0;
    int z=0,o1=0,o2=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
           // cout<<"i:"<<i<<"j:"<<j<<endl;
            string s0=A.substr(0,i); //remember substring takes parameter of index and length
           // cout<<"s0 : "<<s0<<endl;
            string s1=A.substr(i,j-i+1);
           // cout<<"s1 : "<<s1<<endl;
            string s2=A.substr(j+1,n-j);
           // cout<<"s2 : "<<s2<<endl;
            o1=count(s0.begin(),s0.end(),'1');
           // cout<<o1<<endl;
            z=count(s1.begin(),s1.end(),'0');
           // cout<<z<<endl;
            o2=count(s2.begin(),s2.end(),'1');
           //cout<<o2<<endl;
            if(o1+z+o2>t1)
            {
                t1=o1+z+o2;
                q=i+1;
                w=j+1;
                flag=1;
               // cout<<"q :"<<q<<endl;
               // cout<<"w:"<<w<<endl;
            }
        }
    }
    if(flag==0)
      return res;
    else
    {
        res.push_back(q);
        res.push_back(w);
        return res;
    }

}

///////////////most efficient ////////////////////
//kadanes algorithm
//only logic here is to find those two indices where the flip benefits us
vector<int>flip(string A) {
    vector<int> ZeroOrOne(A.size()); 
    vector<int> ans;

    for(int i = 0; i<A.size(); i++){
        if(A[i]=='0')
            ZeroOrOne[i] = 1; //if bit is 0 then store 1 in the array

        else
            ZeroOrOne[i] = -1;//if bit is 1 store -1 in the array
    }

    int cumulative=0, left=0, right=0, maxSum=INT32_MIN;
    int leftAns=0, rightAns=0;

    for(int i=0; i<A.size(); i++){ //iterate through string
        cumulative+=ZeroOrOne[i];  //add element value to cumulative 1 or -1

        if(cumulative<0){   //if less than 0 implies more 1s encountered till then than 0s
            left=i+1;       //so just dont shift this part
            cumulative=0;   //reset cumulative to zero again
        }

        else if(cumulative>maxSum){ //if cumulative is >=0 then that is the region we need to keep updating
            leftAns = left;         //on each iteration
            rightAns = i;
            maxSum=cumulative;
        }
    }

    if(maxSum<=0){     //if all 1s already then just return empty array
        return ans;
    }

    else{
        ans.push_back(leftAns+1); //push left index
        ans.push_back(rightAns+1);//push right index
    }

    return ans;
}


int main()
{
    string s="100101";
    vector<int>v=flip(s);
    print(v);
}

