class Solution {
private:
    // DSU Template by jiangly
    struct DSU {
        std::vector<int> f, siz;
        
        DSU() {}
        DSU(int n) {
            init(n);
        }
        
        void init(int n) {
            f.resize(n);
            std::iota(f.begin(), f.end(), 0);
            siz.assign(n, 1);
        }
        
        int find(int x) {
            while (x != f[x]) {
                x = f[x] = f[f[x]];
            }
            return x;
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);
        }
        
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            siz[x] += siz[y];
            f[y] = x;
            return true;
        }
        
        int size(int x) {
            return siz[find(x)];
        }

        void reset(int x) {
            f[x] = x;
            siz[x] = 1;
        }

        bool isConnected() {
            return siz[find(0)] == siz.size();
        }
    };
    vector<int> getPrimes(int num) {
        vector<int> primes;
        for(int i=2;i*i <= num;++i) {
            if(num % i) continue;
            primes.push_back(i);
            while((num % i) == 0) {
                num /= i;
            }
        }
        if(num != 1) primes.push_back(num);
        return primes;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if(n == 1) return true;
    
        DSU dsu(n);
        unordered_map<int,int> vis;
        for(int i = 0;i < n;++i) {
            // edge case
            if(nums[i] == 1) return false;

            vector<int> primes = getPrimes(nums[i]);
            for(int &e :primes) {
                if(vis.count(e))  dsu.merge(vis[e],i);
                else vis[e]=i;
            }
        }
        return dsu.isConnected();
    }
};