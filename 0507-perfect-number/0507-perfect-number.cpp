class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1; i<=num/2; i++){
            sum+= (num%i==0) ? (i) : 0;
        }
        
        return (sum==num);
    }
};