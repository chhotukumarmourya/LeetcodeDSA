class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(auto x: mp){
            p.push({x.second,-x.first});
        }
        vector<int>ans;
        while(p.size()>0){
            int x=-p.top().second;
            int y=p.top().first;
            for(int i=0;i<y;i++){
                ans.push_back(x);
            }
            p.pop();
        }
        return ans;
    }
};