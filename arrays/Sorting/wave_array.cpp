// Given an array of integers, sort the array into a wave like array and return it,
// In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

// Example

// Given [1, 2, 3, 4]

// One possible answer : [2, 1, 4, 3]
// Another possible answer : [4, 1, 3, 2]
//  NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
// So, in example case, you will return [2, 1, 4, 3]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//prabhaths code
vector<int> wave(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    if(n%2==0)        //if total size ois even no issues just swap alternative elements
    {
        for(int i=0;i<n;i+=2)
        swap(A[i],A[i+1]);
    }
    else{                            //if odd leave out the last element
        for(int i=0;i<n-2;i+=2)
        swap(A[i],A[i+1]);
    }
    return A;
}
//krutikas code
vector<int> wave_1(vector<int> &A) {
    sort(A.begin(),A.end());int temp;
    for(int i=0;i<A.size();i+=2)
    {
        if(i+1==A.size())             //the last element case is handled here in a different way
         continue; 

        temp=A[i];
        A[i]=A[i+1];
        A[i+1]=temp;
    }

   return A;
}
//prakritis code
vector<int> wave_2(vector<int> &A) {
        sort(A.begin(),A.end());
    for(int i=0;i<A.size();i+=2)
    {
        if(A.size()==i+1)
        {
            continue;
        }
        swap(A[i],A[i+1]);
    }
    return A;
}


int main()
{
    vector<int> A={6,17,15,13,1};
    vector<int>B=wave(A);
    print(B);
}
