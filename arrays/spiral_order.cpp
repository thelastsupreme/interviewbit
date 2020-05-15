#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

/*vector<int> spiralOrder(const vector<vector<int> > &A) {
    int T=0,B=A.size()-1,L=0,R=A[0].size()-1;
    int dir=0;
    vector<int>result;
    while(T<=B&&L<=R)
    {
        if(dir==0)
        {
            for(int i=L;i<=R;i++)
                result.push_back(A[T][i]);
               // print(result);
            T++;
        }
        else if(dir==1)
        {
            for(int i=T;i<=B;i++)
                result.push_back(A[i][R]);
            R--;
        }
        else if(dir==2)
        {
            for(int i=R;i>=L;i--)
                result.push_back(A[B][i]);
            B--;
        }
        else if(dir==3)
        {
            for(int i=B;i>=T;i--)
                result.push_back(A[i][L]);
            L++;
        }
        dir=(dir+1)%4;

    }
    return result;
}
*/
//recursive code prakritis
void spiralMatrix(vector<vector<int>> &arr, int i,int j, int m, int n){

    if(i>=m || j>=n){
        return;
    }
    // spiralMatrix(arr,i+1,j+1,m-1,n-1);  //for reverse spiral
    //first row
    for(int p=i;p<n;p++){
        cout<<arr[i][p]<<" ";
    }
    // last column
    for(int p=i+1;p<m;p++){
        cout<<arr[p][n-1]<<" ";
    }
    //last row

    if(i!=(m-1)){
        for(int p=n-2;p>=j;p--){
            cout<<arr[m-1][p]<<" ";
        }
    }
    if(j!=(n-1)){
        for(int p=m-2;p>i;p--){
            cout<<arr[p][j]<<" ";
        }
    }
   spiralMatrix(arr,i+1,j+1,m-1,n-1);
}
int main()
{
    vector<vector<int>>A={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiralMatrix(A,0,0,4,4);
    return 0;
}
