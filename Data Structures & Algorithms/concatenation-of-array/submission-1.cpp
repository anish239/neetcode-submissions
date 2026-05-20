class Solution {
public:
    vector<int> getConcatenation(vector<int>& arr){
    vector<int> res = arr;
    for(int x : arr)
        res.push_back(x);
    return res;
    }

};