class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    SeatManager(int n) {
      while(n!=0){
          q.push(n--);
      }
    }
    
    int reserve() {
        int seat= q.top();
        q.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */