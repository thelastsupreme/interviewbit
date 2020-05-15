
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
