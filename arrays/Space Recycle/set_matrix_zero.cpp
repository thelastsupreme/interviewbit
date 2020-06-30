// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

// Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



// Input Format:

// The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
// Output Format:

// Return a 2-d matrix that satisfies the given conditions.
// Constraints:

// 1 <= N, M <= 1000
// 0 <= A[i][j] <= 1
// Examples:

// Input 1:
//     [   [1, 0, 1],
//         [1, 1, 1], 
//         [1, 1, 1]   ]

// Output 1:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [1, 0, 1]   ]

// Input 2:
//     [   [1, 0, 1],
//         [1, 1, 1],
//         [1, 0, 1]   ]

// Output 2:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [0, 0, 0]   ]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vect(vector<vector<int> >&input)
{
	for (int i = 0; i < input.size(); i++) {
		for(int j=0;j<input[i].size();j++)
        {
            cout << input[i][j] << ' ';
        }
        cout<<endl;
	}
}

//logic: the only problem is you just cant make things zeroes
//so store flags for the rows anc cols you want to make zeroes and in next cycle make them zeroes
void setZeroes(vector<vector<int> > &A) {
    vector<bool>col_check(A.size(),true);
    vector<bool>row_check(A.size(),true);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(A[i][j]==0)
            {
                col_check[j]=false;
                row_check[i]=false;
            }

        }
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(row_check[i]==false||col_check[j]==false)
            {
                A[i][j]=0;
            }

        }
    }
    print_vect(A);

}
//most efficient method it can be done in space of O(1) by using th first row as row_check vector and first column as column_check vector
void setZeros_1(vector<vector<int>>&A){
    bool rowHasZero=false;
    bool colhasZero=false;
    //check if first col has a zero
    for(int i=0;i<A.size();i++){
        if(A[i][0]==0){
            colhasZero=true;
            break;
        }
    }
    //check if first row has a zero
    for(int i=0;i<A[0].size();i++){
        if(A[0][i]==0){
            rowHasZero=true;
            break;
        }
    }
    for(int i=1;i<A.size();i++) //i from second row
    {
        for(int j=1;j<A[i].size();j++) //j from second col
        {

            if(A[i][j]==0)
            {
                A[i][0]=false;  //first col is being used as row_check vector
                A[0][j]=false;  //first row is being used as col_check vector
            }

        }
    }
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {

            if(A[i][0]==false||A[0][j]==false)
            {
                A[i][j]=0;
            }

        }
    }
    if (rowHasZero)
    {
        for (int i = 0; i <A.size(); i++)
        {
            A[0][i]=0;
        }
        
    }
    if (colhasZero)
    {
        for (int i = 0; i <A.size(); i++)
        {
            A[i][0]=0;
        }
        
    }
    print_vect(A);

}


//krutikas code
// void Solution::setZeroes(vector<vector<int> > &A) {

//     vector<int> m(A.size());
//     vector<int> col;
//     int flag=0;
//     for(int i=0;i<A.size();i++)
//     {
//         for(int j=0;j<A.size();j++)
//         {
//             if(A[i][j]==0)
//             {
//                 flag=1;
//                 col.push_back(j);
//             }
//         }
//         if(flag)
//            { A[i]=m; flag=0;}
//     }
//     for(int i=0;i<A.size();i++)
//        for(int j=0;j<i;j++)  //limits?
//            A[i][j]=A[j][i];
//     for(int i=0;i<col.size();i++)
//         A[col[i]]=m;

// }

int main()
{
    vector<vector<int>> A={{1,1},{0,0}};
    vector<vector<int>> C={{1,0,1},{1,1,1},{1,0,1}};
    setZeroes(C);
}
