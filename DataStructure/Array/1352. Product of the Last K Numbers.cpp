// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers
{
private:
    vector<int> nums;
    vector<int> prefix{1};

public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        nums.push_back(num);
        if (num == 0)
        {
            prefix = vector<int>{1}; // 元素为0，则重置prefix
        }
        else
        {
            prefix.push_back(prefix[prefix.size() - 1] * num);
        }
    }

    int getProduct(int k)
    {
        if (prefix.size() < k + 1)
        {             // +1是因为有初始元素1
            return 0; // 后k个元素中有0
        }
        else
        {
            return prefix[prefix.size() - 1] / prefix[prefix.size() - 1 - k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */