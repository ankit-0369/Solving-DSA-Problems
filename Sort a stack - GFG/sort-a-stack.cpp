//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void solve(stack<int>& s1){
    if(s1.size()<=1)
    return;
    
    int ele= s1.top();
    s1.pop();
    solve(s1);
    stack<int> s2;
    while(!s1.empty()&& ele<s1.top()){
        s2.push(s1.top());
        s1.pop();
    }
    
    s1.push(ele);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}
void SortedStack :: sort()
{
   //Your code here---
   solve(s);
}