// O(logN)
// O(N)

class SeatManager {
public:

    // vector<bool> Seat;
    priority_queue<int,vector<int>, greater<>> pq;

    SeatManager(int n) {

    //    Seat.resize(n+1, false);
        for(int i=1; i<n+1; i++) pq.push(i);
    }
    
    int reserve() {
        
        // for(int i=1; i<Seat.size(); i++){

        //     if(!Seat[i]){

        //         Seat[i] = true;

        //         return i;
        //     }
        // }
        // return -1;

        auto Seat = pq.top();
        pq.pop();

        return Seat;
    }
    
    void unreserve(int seatNumber) {
        
        // Seat[seatNumber] = false;
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
