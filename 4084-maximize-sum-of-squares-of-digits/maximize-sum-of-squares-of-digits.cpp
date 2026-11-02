class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";
        int k = sum / 9;
        int r = sum % 9;
        string res(k, '9');
        if (r > 0)
            res += char('0' + r);
        res.append(num - res.size(), '0');
        return res;
    }
};