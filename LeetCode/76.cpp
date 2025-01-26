class Solution {
public:
    string minWindow(string s, string t) {
        int sArr[70], tArr[70];
        int ansS = 0, ansE = 100000000;
        for(char c: t)
            tArr[c-'A']++;
        int start=0, end=0;
        while(true) {
            bool judge = true;
            for(int k=0;k<70;k++) {
                if(sArr[k]<tArr[k]) {
                    judge=false;
                    break;
                }
            }
            if(judge) {
                if(end-start < ansE-ansS) {
                    ansS = start;
                    ansE = end;
                }
                sArr[s[start]-'A']--;
                start++;
            }
            else {
                if (end >= s.length())
                    break;
                sArr[s[end]-'A']++;
                end++;
            }
        }
        
        string ans;
        if(ansE < 5000000) ans = s.substr(ansS, ansE-ansS);
        else ans = "";
        return ans;
    }
};