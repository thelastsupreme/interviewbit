int binSearch(vector<int> &arr, int l, int h, int key){
    if(l>h) return -1;
    int mid=(l+h)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[l]<=arr[mid]){
        if(key<=arr[mid] && key>=arr[l]){
            return binSearch(arr,l,mid-1,key);
        }
        return binSearch(arr,mid+1,h,key);
    }
    if(key>=arr[mid] && key<=arr[h]){
        return binSearch(arr,mid+1,h,key);
    }
    return binSearch(arr,l,mid-1,key);
}

