// Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

// Return all such possible sentences.

// Note : Make sure the strings are sorted in your result.

// Input Format:

// The first argument is a string, A.
// The second argument is an array of strings, B.
// Output Format:

// Return a vector of strings representing the answer as described in the problem statement.
// Constraints:

// 1 <= len(A) <= 50
// 1 <= len(B) <= 25
// 1 <= len(B[i]) <= 20
// Examples:

// Input 1:
//     A = "b"
//     B = ["aabbb"]

// Output 1:
//     []

// Input 1:
//     A = "catsanddog",
//     B = ["cat", "cats", "and", "sand", "dog"]

// Output 1:
//     ["cat sand dog", "cats and dog"]

#include <bits/stdc++.h>
using namespace std;


unordered_map<string,vector<string>> memo;
vector<string> BreakHelper(string A, vector<string> &B){
    // cout<<"A : "<<A<<endl;
    set<string> result_set;
    vector<string> result;
    if (memo.find(A) != memo.end())
    {
        return memo[A];
    }

    if (A.size() == 0)
    {
        return result;
    }
    else if (find(B.begin(), B.end(), A) != B.end())
    {
        result_set.insert(A);
    }

    for (int i = 1; i < A.size(); i++)
    {
        vector<string> leftResult = BreakHelper(A.substr(0, i), B);
        vector<string> rightResult;
        if (leftResult.size() != 0)
        {
            rightResult = BreakHelper(A.substr(i, A.size()), B);
        }

        for (int i = 0; i < leftResult.size(); i++)
        {
            for (int j = 0; j < rightResult.size(); j++)
            {
                result_set.insert(leftResult[i] + " " + rightResult[j]);
            }
        }
    }
    result.assign(result_set.begin(), result_set.end());

    return memo[A] = result;
}

vector<string>wordBreak(string A, vector<string> &B) {
    memo.clear();
    return BreakHelper(A,B);
}

int main()
{
    vector<string>B ={"cat", "cats", "and", "sand", "dog"};
    vector<string>result=wordBreak("catsanddog",B);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    // auto it=memo.begin();
    // while (it != memo.end())
    // {
    //     cout<<"key :"<<it->first<<endl;
    //     for (int i = 0; i <it->second.size(); i++)
    //     {
    //         cout << it->second[i]<<"  ";
    //     }
    //     cout<<endl;
    //     it++;
    // }
}