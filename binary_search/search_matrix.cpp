
//best solution
int Solution::searchMatrix(vector<vector > &A, int B) {
    size_t rows = A.size();
    size_t cols = A[0].size();
    int start = 0, end = (rows*cols)-1;
    while (start <= end) {
    int mid = start + (end-start)/2;
    int row = mid/cols, col = mid%cols;
    if (A[row][col] == B)
    return 1;
    else if (A[row][col] < B)
    start = mid + 1;
    else
    end = mid - 1;
}
return 0;
}

//p and p code
int binarySearch(vector<int>&A, int n, int target) {
	int start = 0, end = n-1;
	while(start <= end) {
		// take mid of the list
		int mid = (start + end) / 2;

		// we found a match
		if(A[mid] == target) {
			return mid;
		}
		// go on right side
		else if(A[mid] < target) {
			start = mid + 1;
		}
		// go on left side
		else {
			end = mid - 1;
		}
	}
	// element is not present in list
    return -1;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    vector<int>C;
    for(int i=0;i<A.size();i++)
        C.insert(C.end(), A[i].begin(), A[i].end());
   int n= binarySearch(C,C.size(),B);
   if(n==-1)
        return 0;
    else
        return 1;
}

//krutikas code
int binarySearch(vector<int> Arr, int n, int target) {

	int start = 0, end= n-1;

	while(start <= end) {

		int mid=(start + end) / 2;
		if(Arr[mid] == target) {
			return 1;
		}
		else if(Arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    int M=A.size(); //rows
    int N=A[0].size();   //columns
    int idx;
    if(M==0)
       return 0;
    if(M==1)
    {
        idx=0;
    }
    else{
        for(int i=0;i<M;i++)
        {
            if(A[i][0]<=B&&A[i][N-1]>=B)
            {
                idx=i;
                break;
            }
        }
    }
    return (binarySearch(A[idx],A[idx].size(),B));
}
