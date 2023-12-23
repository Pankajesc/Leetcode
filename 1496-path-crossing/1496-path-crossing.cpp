class Solution {
public:
    bool isPathCrossing(string& path) {
        unordered_set<int> P;
        int x0 =10000, y0=10000, xy=x0*20001+y0;
        P.insert(xy);

        for (char c : path) {
            switch (c) {
                case 'N': y0++; break;
                case 'S': y0--; break;
                case 'E': x0++; break;
                case 'W': x0--; break;
            }
            xy=x0*20001+y0;
            if (P.count(xy)==1) return 1;
            P.insert(xy);
        }
        return 0;    
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();