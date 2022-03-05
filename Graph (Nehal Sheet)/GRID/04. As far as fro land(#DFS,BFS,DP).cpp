//ques      :- https://leetcode.com/problems/as-far-from-land-as-possible/
//intution  :- https://leetcode.com/problems/as-far-from-land-as-possible/discuss/360963/C%2B%2B-with-picture-DFS-and-BFS

//code
int maxDistance(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q, q1;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 1)
        q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
  while (!q.empty()) {
    ++steps;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      q.pop();
      if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
        g[i][j] = steps;
        q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
      }
    }
    swap(q1, q);
  }
  return steps == 1 ? -1 : steps - 1;
}
