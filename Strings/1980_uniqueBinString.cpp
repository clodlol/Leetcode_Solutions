#include <iostream>
#include <vector>

std::string findBinary(const int &n, const int &precision)
{
    std::string s;
    if (n > 0)
    {
        for (int i = n; i >= 2; i /= 2)
        {
            s += '0' + (i % 2);
        }
        s += '0' + 1;
    }
    else
    {
        s = '0';
    }

    while (s.size() < precision)
        s += '0';

    std::reverse(s.begin(), s.end());
    return s;
}

bool isMissing(const std::string &targetBin, const std::vector<std::string> &nums)
{
    int missing = true;
    for (const auto &s : nums)
    {
        if (strcmp(s.c_str(), targetBin.c_str()) == 0)
        {
            missing = false;
            break;
        }
    }

    return missing;
}

std::string findMissingBinString(const std::vector<std::string> &nums)
{
    const int n = nums.size();
    for (int i = 0; i < std::pow(2, n); i++)
    {
        std::string target = findBinary(i, n);
        // std::cout << target << "\n";
        if (isMissing(target, nums))
            return target;
    }
    return "";
}

int main()
{
    std::vector<std::string> nums = {"1001", "0111", "0000", "0001"};
    std::cout << findMissingBinString(nums) << "\n";
    return 0;
}