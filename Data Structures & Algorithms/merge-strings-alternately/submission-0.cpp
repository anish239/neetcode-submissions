class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string newString = "";

        int i = 0;
        int j = 0;

        while(i<n && j<m){
            newString.push_back(word1[i]);
            i++;
            newString.push_back(word2[j]);
            j++;
        }

        while(i<n){
            newString.push_back(word1[i]);
            i++;
        }

        while(j<m){
            newString.push_back(word2[j]);
            j++;
        }

        return newString;
    }
};