class Solution
{
public:
    bool hasPrefix(const vector<string> &strs, const string &s)
    {
        for (auto str : strs)
        {
            if (str.find(s) != 0)
                return false;
        }

        return true;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = strs[0];
        int ansSize = ans.size();

        while (ansSize > 0)
        {
            ans.resize(ansSize);
            if (hasPrefix(strs, ans))
            {
                return ans;
            }

            ansSize--;
        }

        return "";
    }
};