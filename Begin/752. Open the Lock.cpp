// https://leetcode.com/problems/open-the-lock/description/

class Solution {
private:
    string get_new_lock(string lock, int index, int val) {
        lock[index] = val + '0';
        return lock;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> wheels;
        queue<int> steps;
        unordered_set<string> visited;
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        wheels.push("0000");
        visited.insert("0000");
        steps.push(0);

        // 如果初始条件就是死亡数字
        if (deadend.find("0000") != deadend.end()) return -1;

        while (!wheels.empty()) {
            string lock = wheels.front();
            wheels.pop();
            int step = steps.front();
            steps.pop();

            // 结束条件
            if (lock == target) return step;

            // 计算邻居结点（一步旋转之后的所有可能结果）
            for (int i = 0; i < 4; ++i) {   // 四个数字
                for (int j = 0; j < 2; ++j) {   // 上调+下调

                    // 计算新的字符串
                    int old_value = lock[i] - '0';
                    int new_value = 0;
                    if (j == 0) new_value = (old_value + 1) % 10;
                    else new_value = (old_value - 1 + 10) % 10; // 避免减为负数
                    string new_lock = get_new_lock(lock, i, new_value);
                    
                    // 避免循环遍历
                    if (visited.find(new_lock) != visited.end()) continue;

                    // 死亡数字
                    if (deadend.find(new_lock) != deadend.end()) continue;

                    wheels.push(new_lock);
                    steps.push(step + 1);
                    visited.insert(new_lock);   // 当前结点加入至visited
                }
            }
        }
        return -1;
    }
};