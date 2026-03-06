class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int i=s.find('0');
        if(i==-1)return 1;
        int j=s.find_last_of('1');
        return i>j;
    }
};