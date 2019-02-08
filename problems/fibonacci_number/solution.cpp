class Solution {
public:
    std::unordered_map<int, int> m;
    int fib(int N) {
        if (m.count(N)) {
            return m[N];
        }
        
        if (N < 2) {
            m[N] = N;
            return m[N];
        }
        
        m[N] = fib(N-1) + fib(N-2);
        return m[N];
    }
};