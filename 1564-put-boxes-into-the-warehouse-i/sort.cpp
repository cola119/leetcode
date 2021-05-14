class Solution {
public:
    /*
    b [4,3,4,1]
    w [5,3,3,4,1]
    
    b [4,4,1,1] [1,1,4,4]
    w [5,4,3,3,1] [1,3,3,4,5]
    */
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int min_warehouse = warehouse[0];
        for(int i = 1; i < warehouse.size(); i++) {
            min_warehouse = min(min_warehouse, warehouse[i]);
            warehouse[i] = min_warehouse;
        }
        // w [5,3,3,3,1]
        reverse(warehouse.begin(), warehouse.end());
        // w [1,3,3,3,5]
        // b [1,3,4,4]
        sort(boxes.begin(), boxes.end());
        int cnt = 0;
        int w = 0;
        int b = 0;
        while(b < boxes.size() && w < warehouse.size()) {
            int size = warehouse[w]; // 3
            int box = boxes[b]; // 4
            if(box <= size) {
                cnt++;
                w++;
                b++;
            } else {
                while(w < warehouse.size() && warehouse[w] < box) {
                    w++;
                }
            }
        }
        return cnt;
    }
};