//left rotate by B for right rotate uncomment the commented part
vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret;
   // reverse(A.begin(),A.end());
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B)%A.size()]);
    }
  //  reverse(ret.begin(),ret.end());
    return ret;
}
