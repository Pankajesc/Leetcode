class Solution {
public:
	int m, n, MAX_HEIGHT, currWater = 0, ans = 0;
	vector<vector<int>> map;
	vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	bool isInMap(int row, int col) {
		return row >= 0 && col >= 0 && row < m && col < n;
	}

	void dfs(int row, int col) {
		if(!isInMap(row, col))
			return;

		if(map[row][col] != 0)
			return;

		for(auto& [dirRow, dirCol] : dirs) {
			int nextRow = row + dirRow;
			int nextCol = col + dirCol;
			if(!isInMap(nextRow, nextCol) || map[nextRow][nextCol] == -1) {
				currWater--;
				map[row][col] = -1;
				break;
			}
		}

		if(map[row][col] == 0)
			return;

		for(auto& [dirRow, dirCol] : dirs) {
			int nextRow = row + dirRow;
			int nextCol = col + dirCol;
			dfs(nextRow, nextCol);
		}
	}

	int trapRainWater(vector<vector<int>>& heightMap) {
		m = heightMap.size();
		n = heightMap[0].size();
		MAX_HEIGHT = 2 * 1e4;
		map = vector<vector<int>>(m, vector<int>(n, 1));
		unordered_map<int, vector<pair<int, int>>> coordinates;

		for(int row = 0; row < m; row++) {
			for(int col = 0; col < n; col++) {
				coordinates[heightMap[row][col]].push_back({row, col});
			}
		}

		for(int height = 0; height <= MAX_HEIGHT; height++) {
			if(coordinates.count(height)) for(auto& [row, col] : coordinates[height]) {
				map[row][col] = 0;
				currWater++;
				dfs(row, col);
			}
			ans += currWater;
		}
		return ans;
	}
};