// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 278. First Bad Version
class Solution {
public:
    int firstBadVersion(int n) {
       int L = 1, R = n;
       while(L < R) {
           int M = L + (R - L) / 2;
           if(isBadVersion(M)) {
               R = M;
           }
           else {
               L = M + 1;
           }
       }
      return L;
    }
};
