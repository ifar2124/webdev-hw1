class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> myMinHeap;

public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            add(n);   // reuse add() so the heap ends up holding the top k
        }
    }
    
    int add(int val) {
        if ((int)myMinHeap.size() < k) {
            myMinHeap.push(val);
        } else if (val > myMinHeap.top()) {
            myMinHeap.pop();
            myMinHeap.push(val);
        }
        return myMinHeap.top();
    }
};