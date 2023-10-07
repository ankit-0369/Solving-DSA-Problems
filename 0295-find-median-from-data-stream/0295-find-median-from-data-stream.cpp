class MedianFinder {
public:
    // vector<int> ar;
    priority_queue<int> mxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double med;
    
    MedianFinder() {
        med=-1;
    }
    
    int signum(int a, int b){
        return a-b;
    }
    
    void addNum(int num) {
        
        // ar.push_back(num);
        switch(signum(mxheap.size(), minheap.size())) {
                
            case 0 :
                if(num > med){
                    minheap.push(num);
                    med= minheap.top();
                }else{
                    mxheap.push(num);
                    med= mxheap.top();
                }
                break;
            case 1:
                if(num > med){
                    minheap.push(num);
                    med= (double)(mxheap.top() + minheap.top())/2;
                }else{
                    int x= mxheap.top();
                    mxheap.pop();
                    minheap.push(x);
                    mxheap.push(num);
                    med= (double)(mxheap.top() + minheap.top())/2;
                    
                }
                
                break;
            case -1:
                if(num>med){
                    //min me add the num--
                    int x= minheap.top();
                    minheap.pop();
                    mxheap.push(x);
                    minheap.push(num);
                    med= (double)(mxheap.top() + minheap.top())/2;
                }else{
                    mxheap.push(num);
                    med= (double)(mxheap.top() + minheap.top())/2;
                }
                break;
        }
        
        
    }
    
    double findMedian() {
//         sort(ar.begin(), ar.end());
//         double ans=-1;
//         if(ar.size()&1){
//             int ind= ar.size()/2;
//             ans= ar[ind];
//         }else{
//             int ind= ar.size()/2;
//             ans= double (ar[ind]+ar[ind-1])/2;
//         }
        
//         return ans;
        
        return med;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */