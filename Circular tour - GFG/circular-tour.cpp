//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here---
       //using two pointer--
    //   int front=0, rear= 0;
    //   int curPet= 0;
       
    //   while(front<n){
           
    //       if(curPet+ p[front].petrol- p[front].distance>=0 ){
    //           curPet+= p[front].petrol-p[front].distance;
    //           rear= (rear+1)%n;
               
    //           if(front==rear){
    //               return front;
    //           }
    //       }else{
    //           curPet= p[front].petrol;
    //           front= rear+1;
    //           rear= front;
    //       }
    //   }
    
    //another approach--
    int bal= 0, defecit= 0;
    int start= 0;
    for(int i=0; i<n; i++){
        bal+= p[i].petrol -p[i].distance;
        
        if(bal<0){
            defecit+= bal;  //kitni kami hogi next pump me jaane me add kr lo
            bal= 0;
            start= i+1; //mtlb agle pump se start krke dekho kitna bachta hai petrol
        }
    }
    
    //finally ek loop complete hone me kitna petrol chahiye vo mil gaya
    if(bal+ defecit>=0){
        return start;
    }
       
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends