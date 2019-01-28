class RecentCounter {
    std::deque<int> pingTimes;
	const int interval = 3000;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pingTimes.push_back(t);
        while (pingTimes.front() < t - interval)
        {
            pingTimes.pop_front();
        }
        return pingTimes.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */