class Solution {
public:
    int maximumProduct(vector<int>& A) {
        sort(A.begin(),A.end());
        return max(
            A.back() * A[A.size() - 2] * A[A.size() - 3],
            A.back() * A.front() * A[1]
        );
    }
};