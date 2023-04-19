class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod=1;
        long long sum=0;
        while(n!=0){
            sum+= (n%10);
            prod*= (n%10);
            n/=10;
        }
        return (int)prod-(int)sum;
    }
};