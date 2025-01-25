class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> mySet;
        for(int i: nums){
            mySet.insert(i);
        }

        if(mySet.find(target) != mySet.end()){
            return true;
        }else{
            return false;
        }
        
    }
};