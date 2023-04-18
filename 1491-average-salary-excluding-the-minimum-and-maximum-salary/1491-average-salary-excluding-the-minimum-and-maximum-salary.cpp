class Solution {
public:
    double average(vector<int>& salary) {//t.c:- O(n) & auxilary-space:- O(1)
        double avg= 0;
        double maxSalary= *max_element(salary.begin(), salary.end());
        double minSalary= *min_element(salary.begin(), salary.end());
       double sum=0;
        for(int i=0; i<salary.size(); i++){
                if(salary[i]!= maxSalary && salary[i]!=minSalary)
                sum+= salary[i];
        }
       // avg= sum/(salary.size()-2);
        return sum/(salary.size()-2);
    }
};