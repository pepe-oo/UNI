#include <iostream>
#include <vector>

void solve (size_t idx, std::vector<int>& actual, std::vector<int>& nums)
{
    if (idx == nums.size()) {
        std::cout << "{";
        for (size_t i = 0; i < actual.size(); i ++) {
            std::cout << actual[i];
            if (i < actual.size() - 1) {std::cout << " ";}
        }
        std::cout << "}" << std::endl;
        return;
    }
    solve(idx + 1, actual, nums);
    actual.push_back(nums[idx]);
    solve(idx + 1, actual,nums);
    actual.pop_back();
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    std::vector<int> actua;
    size_t idx = 0;
    solve(idx,actua,nums);
    return 0;
}