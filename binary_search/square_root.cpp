int binarySearch(int A) {

	//set stating and ending index
	long start = 0, end = A/2;
    long mid=0;
	while(start <= end) {
		// take mid of the list
		mid = (start + end) / 2;

		// we found a match
		if(mid*mid <=A && (mid+1)*(mid+1)>A) {
			return mid;
		}
		// go on right side
		else if(mid*mid< A) {
			start = mid + 1;
		}
		// go on left side
		else {
			end = mid - 1;
		}
	}
}

int Solution::sqrt(int A) {
    if(A==1)
        return 1;
    int ans=binarySearch(A);
    return ans;
}


//recursive approach
double ans(double A, double n) {
    return abs(A - n) < 0.001;
}

double better(double A, double n) {
    return (n + A / n) / 2;
}

double sol(double A, double n) {
    if (ans(A/n, n)) return n;
    return sol(A, better(A, n));
}

int Solution::sqrt(int A) {
    return (int)sol(A, 1);
}
