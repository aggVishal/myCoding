#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

class edge
{
public:
    int u;
    int w = 10;
    edge(int u, int w)
    {
        this->u = u;
        this->w = w;
    }
};
int N = 7;                                     //no of vertex
vector<vector<edge>> graph(N, vector<edge>()); //adjacency list type graph

void constructgraphB(int v, int u, int w)
{ //in bidirection(v->u & u->v)
    edge e1(u, w);
    edge e2(v, w);
    graph[v].push_back(e1);
    graph[u].push_back(e2);
}
void constructgraphU(int v, int u, int w)
{ //in unidirection(v->u)
    edge e1(u, w);
    graph[v].push_back(e1);
}

void addedge(vector<vector<edge>> &Ngraph, int u, int v, int w)
{
    edge e1(u, w);
    edge e2(v, w);
    Ngraph[v].push_back(e1);
    Ngraph[u].push_back(e2);
}

void display_(vector<vector<edge>> &ngraph)
{
    for (int i = 0; i < ngraph.size(); i++)
    {
        cout << i << "-> ";
        for (edge x : ngraph[i])
        {
            cout << "(" << x.u << "," << x.w << ")"
                 << " ";
        }
        cout << endl;
    }
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-> ";
        for (edge x : graph[i])
        {
            cout << "(" << x.u << "," << x.w << ")"
                 << " ";
        }
        cout << endl;
    }
}
//BASICS************************************************************************************************************
int findindex(vector<edge> gp, int v)
{ //find index of vertex v in graph[u]
    int i = 0;
    for (i = 0; i < gp.size(); i++)
    {
        edge e = gp[i];
        if (e.u == v)
        {
            break;
        }
    }
    return i;
}

void removeedge(int v, int u)
{
    int idx1 = findindex(graph[u], v);
    int idx2 = findindex(graph[v], u);
    graph[u].erase(graph[u].begin() + idx1);
    graph[v].erase(graph[v].begin() + idx2);
}
bool findedge(int v1, int v2)
{
    for (edge e : graph[v1])
    {
        if (e.u == v2)
        {
            return true;
        }
    }
    return false;
}

// void removevertex(int vtx)
// {

//     while (graph[vtx].size() != 0)
//     {
//         //int vtx2=graph[vtx][graph[vtx].size()-1];

//         edge e = graph[vtx].back();
//         removeedge(vtx, e.u);
//     }
// }
void removevertex(int v)
{
    while (graph[v].size() != 0)
    {
        edge e = graph[v][0];
        removeedge(v, e.u);
    }
}

//QUETIONS********************************************************************************************************
bool haspath(int s, int d, vector<bool> &vis)
{
    if (s == d)
    {
        //cout<<ans<<endl;
        return true;
    }
    vis[s] = true;
    bool res = false;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            res = res || haspath(e.u, d, vis);
        }
    }
    return res;
}

int allpath(int s, int d, vector<bool> &vis, int w, string ans)
{
    if (s == d)
    {
        cout << ans << d << "->" << w << endl;
        return 1;
    }
    vis[s] = true;
    int count = 0;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            count += allpath(e.u, d, vis, w + e.w, ans + to_string(s) + " ");
        }
    }
    vis[s] = false;
    return count;
}
void preorder(int s, vector<bool> &vis, int w, string ans)
{
    vis[s] = true;
    cout << ans << s << " @ " << w << endl;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            preorder(e.u, vis, w + e.w, ans + to_string(s) + " ");
        }
    }
    vis[s] = false;
}
void postorder(int s, vector<bool> &vis, int w, string ans)
{
    vis[s] = true;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            postorder(e.u, vis, w + e.w, ans + to_string(s) + " ");
        }
    }
    cout << ans << s << " @ " << w << endl;
    vis[s] = false;
}

class allsolutionpair
{
public:
    int lightW = 1e7;
    int heavyW = 0;
    int ceil = 1e7;
    int floor = 0;
    string lightpath;
    string heavypath;
    string ceilpath;
    string floorpath;
};
void allsolution(int s, int d, int w, vector<bool> &vis, string ans, allsolutionpair &pair, int data)
{
    if (s == d)
    {
        if (pair.lightW > w)
        {
            pair.lightW = w;
            pair.lightpath = ans + to_string(d);
        }
        if (pair.heavyW < w)
        {
            pair.heavyW = w;
            pair.heavypath = ans + to_string(d);
        }
        if (w > data && w < pair.ceil)
        {
            pair.ceil = w;
            pair.ceilpath = ans + to_string(d);
        }
        if (w < data && w > pair.floor)
        {
            pair.floor = w;
            pair.floorpath = ans + to_string(d);
        }
        return;
    }
    vis[s] = true;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            allsolution(e.u, d, w + e.w, vis, ans + to_string(s) + " ", pair, data);
        }
    }
    vis[s] = false;
    return;
}

void ishamiltoniancycle(int s, int osrc, int count, vector<bool> &vis, string ans)
{
    if (count == (N - 1))
    {
        if (findedge(s, osrc))
        {
            cout << "hamiltonian cycle: " << ans + to_string(s) << endl;
        }
        else
        {
            cout << "hamiltonian path: " << ans + to_string(s) << endl;
        }
        return;
    }
    vis[s] = true;
    //bool res=false;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            ishamiltoniancycle(e.u, osrc, count + 1, vis, ans + to_string(s) + " ");
        }
    }
    vis[s] = false;
    return;
}

int GCC_(int s, vector<bool> &vis)
{
    vis[s] = true;
    int count = 0;
    for (edge e : graph[s])
    {
        if (!vis[e.u])
        {
            count += GCC_(e.u, vis);
        }
    }
    return count + 1;
}

//Get Connected Components
int GCC(vector<bool> &vis)
{
    int count = 0;
    int maxsize = 0;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == false)
        {
            count++;
            maxsize = max(maxsize, GCC_(i, vis));
        }
    }
    cout << maxsize << endl;
    return count;
}

string differIslands_(vector<vector<int>> &board, int r, int c)
{
    board[r][c] = 2;
    string L = "", R = "", D = "", U = "";
    if (r - 1 >= 0 && board[r - 1][c] == 1)
    {
        U = "U";
        U += differIslands_(board, r - 1, c);
        U += "B";
    }
    if (r + 1 < board.size() && board[r + 1][c] == 1)
    {
        D = "D";
        D += differIslands_(board, r + 1, c);
        D += "B";
    }
    if (c - 1 >= 0 && board[r][c - 1] == 1)
    {
        L = "L";
        L += differIslands_(board, r, c - 1);
        L += "B";
    }
    if (c + 1 < board[0].size() && board[r][c + 1] == 1)
    {
        R = "R";
        R += differIslands_(board, r, c + 1);
        R += "B";
    }
    return L + R + U + D;
}

int differIslands(vector<vector<int>> &board)
{
    string s;
    int l = 1;
    vector<string> strings;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
            {
                s = differIslands_(board, i, j);
                for (string str : strings)
                {
                    if (str == s)
                    {
                        l = 0;
                    }
                }
                if (l == 1)
                {
                    strings.push_back(s);
                }
            }
            l = 1;
        }
    }
    return strings.size();
}

//BFS*********************************************************************************************************************************

class BFSpair
{
public:
    int first;
    string second;
    int level = 0;
    BFSpair(int first, string second)
    {
        this->first = first;
        this->second = second;
    }
    BFSpair(int first, string second, int lvl)
    {
        this->first = first;
        this->second = second;
        level = lvl;
    }
};

void BFS_01(int s, vector<bool> &vis)
{ // Normal BFS
    queue<BFSpair> que;
    que.push({s, to_string(s)});
    int dest = 6;
    while (que.size() != 0)
    {
        BFSpair v = que.front();
        que.pop();
        if (vis[v.first] == true)
        {
            cout << "Cycle: " << v.second << endl;
            continue;
        }
        if (v.first == dest)
        {
            cout << "Destination: " << v.second << endl;
        }
        vis[v.first] = true;
        for (edge e : graph[v.first])
        {
            if (!vis[e.u])
            {
                que.push({e.u, v.second + to_string(e.u)});
            }
        }
    }
}

void BFS_02(int s, vector<bool> &vis)
{ /// when level is also taken in class BFSpair
    queue<BFSpair> que;
    que.push({s, to_string(s), 0});
    int dest = 6;

    while (que.size() != 0)
    {
        BFSpair v = que.front();
        que.pop();
        if (vis[v.first] == true)
        {
            cout << "Cycle: " << v.second << " @ " << v.level << endl;
            continue;
        }
        if (v.first == dest)
        {
            cout << "Destination: " << v.second << " @ " << v.level << endl;
        }

        vis[v.first] = true;
        for (edge e : graph[v.first])
        {
            if (!vis[e.u])
            {
                que.push({e.u, v.second + to_string(e.u), v.level++});
            }
        }
    }
}

void BFS_03(int s, vector<bool> &vis)
{ /// Queue bases on size
    queue<BFSpair> que;
    que.push({s, to_string(s)});
    int dest = 6;
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            BFSpair v = que.front();
            que.pop();

            if (vis[v.first] == true)
            {
                cout << "Cycle: " << v.second << " @ " << level << endl;
                continue;
            }
            if (v.first == dest)
            {
                cout << "Destination: " << v.second << " @ " << level << endl;
            }

            vis[v.first] = true;
            for (edge e : graph[v.first])
            {
                if (!vis[e.u])
                {
                    que.push({e.u, v.second + to_string(e.u)});
                }
            }
        }
        level++;
    }
}

void BFS_04(int s, vector<bool> &vis)
{ /// Queue based on size and can't detect cycles
    queue<BFSpair> que;
    que.push({s, to_string(s)});
    int dest = 6;
    int level = 0;
    vis[0] = true;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            BFSpair v = que.front();
            que.pop();

            if (v.first == dest)
            {
                cout << "Destination: " << v.second << " @ " << level << endl;
            }

            for (edge e : graph[v.first])
            {
                if (!vis[e.u])
                {
                    que.push({e.u, v.second + to_string(e.u)});
                    vis[e.u] = true;
                }
            }
        }
        level++;
    }
}

// leetcode 1091
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        return -1;
    vector<vector<int>> dir = {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};
    queue<int> que;
    que.push(0);
    int level = 1;
    grid[0][0] = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;
            if (r == n - 1 && c == m - 1)
                return level;
            for (int d = 0; d < 8; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0)
                {
                    que.push(x * m + y);
                    grid[x][y] = 1;
                }
            }
        }
        level++;
    }
    return -1;
}

//leetcode 286 (walls and gates)  or lintcode 663
void wallsAndGates(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    int m = rooms[0].size();
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rooms[i][j] == 0)
            {
                que.push(i * m + j);
            }
        }
    }
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;
            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                if (x >= 0 && y >= 0 && x < n && y < m && rooms[x][y] == 2147483647)
                {
                    que.push(x * m + y);
                    rooms[x][y] = level;
                }
            }
        }
        level++;
    }
    return;
}

//leetcode 994 (amazon's favorite)
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<int> que;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
            if (grid[i][j] == 2)
            {
                que.push(i * m + j);
            }
        }
    }
    if (count == 0)
        return 0;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            int r = idx / m;
            int c = idx % m;
            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                {
                    que.push(x * m + y);
                    grid[x][y] = 2;
                }
            }
        }
        level++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return level - 1;
}

//Is Barpatite or leetcode 785

bool isbarpatite_(int s, vector<int> &vis)
{
    pair<int, int> p(s, 0);
    queue<pair<int, int>> que;
    que.push(p);
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> idx = que.front();
            que.pop();
            if (vis[idx.first] != -1)
            {
                if (vis[idx.first] != idx.second)
                {
                    return false;
                }
                else
                    continue;
            }
            vis[idx.first] = idx.second;
            for (edge e : graph[idx.first])
            {
                if (vis[e.u] == -1)
                {
                    que.push({e.u, (idx.second + 1) % 2});
                }
            }
        }
    }
    return true;
}
bool isBipartite()
{
    vector<int> vis(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1)
        {
            if (!isbarpatite_(i, vis))
            {
                return false;
            }
        }
    }
    return true;
    ;
}

// Topological Sort***************************************************************************************************
void topoDFS_(vector<vector<edge>> &ngraph, int s, vector<bool> &vis, vector<int> &ans)
{
    vis[s] = true;
    for (edge e : ngraph[s])
    {
        if (!vis[e.u])
        {
            topoDFS_(ngraph, e.u, vis, ans);
        }
    }
    ans.push_back(s);
}

void topoDFS()
{ //can't detect cycle
    vector<bool> vis(N, false);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoDFS_(graph, i, vis, ans);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}

//topology sort by BFS (kahn's algorithm)**************************************************************************

void kahnsAlgo()
{
    vector<int> ans;
    vector<int> ind(N, 0);
    for (int i = 0; i < graph.size(); i++)
    {
        for (edge e : graph[i])
        {
            ind[e.u]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < graph.size(); i++)
    {
        if (ind[i] == 0)
        {
            que.push(i);
        }
    }
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int idx = que.front();
            que.pop();
            ans.push_back(idx);
            for (edge e : graph[idx])
            {
                if (--ind[e.u] == 0)
                {
                    que.push(e.u);
                }
            }
        }
    }
    if (ans.size() == N)
    {
        cout << "Non cycle: ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << "Cycle...";
}

//leetcode 207
//leetcode 210

//Cycle detection using DFS****************************************************************************************
bool cycledetectDFS_(int s, vector<int> &vis)
{
    if (vis[s] == 1)
        return true;
    if (vis[s] == 2)
        return false;

    vis[s] = 1;
    bool res = false;
    for (edge e : graph[s])
    {
        res = res || cycledetectDFS_(e.u, vis);
    }
    vis[s] = 2;
    return res;
}

void cycledetectDFS()
{
    vector<int> vis(N, 0);
    bool res = false;
    for (int i = 0; i < graph.size() && !res; i++)
    {
        if (vis[i] == 0)
        {
            res = res || cycledetectDFS_(i, vis);
        }
    }
    cout << res << endl;
}

//SCC (Stongly connected components)*****************************************************************************************************************

//Kosaraju Algorithm

int kosarajualgo()
{ //counts number of SCC in a  graph(element not in cycle counts as a SCC)
    vector<bool> vis(N, false);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoDFS_(graph, i, vis, ans);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    vector<vector<edge>> ngraph(N, vector<edge>());
    for (int i = 0; i < N; i++)
    {
        for (edge e : graph[i])
        {
            edge x(i, 10);
            //x.u=i;
            ngraph[e.u].push_back(x);
        }
    }
    //display_(ngraph);
    vector<bool> vis2(N, false);
    int count = 0;
    vector<int> x;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (!vis2[ans[i]])
        {
            count++;
            topoDFS_(ngraph, ans[i], vis2, x);
        }
    }
    return count;
}

//Union Find*************************************************************************************************************
//***********************************************************************************************************************

vector<int> par;
vector<int> setsize;
int findpar(int idx)
{
    if (par[idx] == idx)
        return idx;
    return par[idx] = findpar(par[idx]);
}
void mergeset(int p1, int p2)
{
    if (setsize[p1] > setsize[p2])
    {
        par[p2] = p1;
        setsize[p1] += setsize[p2];
    }
    else
    {
        par[p1] = p2;
        setsize[p2] += setsize[p1];
    }
}

//union find function to detect cycle in a graph
bool Union_find_detect_cycle()
{
    par.resize(N);
    setsize.resize(N);
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
        setsize[i] = 1;
    }
    for (int i = 0; i < graph.size(); i++)
    {
        for (edge e : graph[i])
        {
            int p1 = findpar(i);
            int p2 = findpar(e.u);
            if (p1 == p2)
            {
                return true;
            }
            else
                mergeset(p1, p2);
        }
    }
    return false;
}

//leetcode 584

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    par.resize(n + 1);
    setsize.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        setsize[i] = 1;
    }
    int a, b;
    for (int i = 0; i < n; i++)
    {
        int l1 = findpar(edges[i][0]);
        int l2 = findpar(edges[i][1]);
        if (l1 == l2)
        {
            a = edges[i][0];
            b = edges[i][1];
            break;
        }
        mergeset(l1, l2);
    }
    return {min(a, b), max(a, b)};
}

//leetcode 547
int findCircleNum(vector<vector<int>> &M)
{
    int n = M.size();
    par.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    int count = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                int l1 = findpar(i);
                int l2 = findpar(j);
                if (l1 != l2)
                {
                    par[l1] = l2;
                    count--;
                }
            }
        }
    }
    return count;
}

//leetcode 1061
/*
https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters. For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
For example, given the equivalency information from A and B above, S = "eed", "acd", and "aab" are equivalent strings, and "aab" is the lexicographically smallest equivalent string of S.

Return the lexicographically smallest equivalent string of S by using the equivalency information from A and B.

Example 1:

Input: A = "parker", B = "morris", S = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in A and B, we can group their characters as [m,p], [a,o], [k,r,s], [e,i]. The characters in each group are equivalent and sorted in lexicographical order. So the answer is "makkek".
Example 2:

Input: A = "hello", B = "world", S = "hold"
Output: "hdld"
Explanation:  Based on the equivalency information in A and B, we can group their characters as [h,w], [d,e,o], [l,r]. So only the second letter 'o' in S is changed to 'd', the answer is "hdld".
Example 3:

Input: A = "leetcode", B = "programs", S = "sourcecode"
Output: "aauaaaaada"
Explanation:  We group the equivalent characters in A and B as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in S except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
Note:

String A, B and S consist of only lowercase English letters from 'a'- 'z'.
The lengths of string A, B and S are between 1 and 1000.
String A and B are of the same length.


A and B are equal, for each index, the corresponding character in A and B should be in the same union.

When do the union, union by rank. a<c, a is c's parent.

Later, for each character of S, find its ancestor and append it to result.

Time Complexity: O((m+n)logm). m = A.length(), n = S.length(). find takes O(logm). 

With path compression and union by rank, amatorize O(1).

Space: O(m).
*/

//solution leetcode 1061

string leetcode_1061(string A, string B, string S)
{
    vector<int> par(26);
    for (int i = 0; i < 26; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < A.length(); i++)
    {
        int p1 = findpar(A[i] - 'a');
        int p2 = findpar(B[i] - 'a');
        if (p1 != p2)
        {
            par[p2] = min(p1, p2);
            par[p1] = min(p1, p2);
        }
    }
    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        ans += (char)(findpar(S[i] - 'a') + 'a');
    }
    return ans;
}

//leetcode 200 (Number of Islands)

int numIslands2(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0)
        return 0;
    int noOfOnces = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            par.push_back(i * m + j);
            if (grid[i][j] == '1')
                noOfOnces++;
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                if (j + 1 < m && grid[i][j + 1] == '1')
                {
                    int p1 = findpar(i * m + j);
                    int p2 = findpar(i * m + j + 1);
                    if (p1 != p2)
                    {
                        par[p1] = p2;
                        noOfOnces--;
                    }
                }

                if (i + 1 < n && grid[i + 1][j] == '1')
                {
                    int p1 = findpar(i * m + j);
                    int p2 = findpar((i + 1) * m + j);
                    if (p1 != p2)
                    {
                        par[p1] = p2;
                        noOfOnces--;
                    }
                }
            }
        }
    }

    return noOfOnces;
}

//leetcode 839
bool isSimilar(string &p, string &q)
{
    int count = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] != q[i] && ++count > 2)
            return false;
    }
    return true;
}

int numSimilarGroups(vector<string> &A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
        par.push_back(i);

    int groups = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSimilar(A[i], A[j]))
            {
                int p1 = findpar(i);
                int p2 = findpar(j);
                if (p1 != p2)
                {
                    par[p1] = p2;
                    groups--;
                }
            }
        }
    }
    return groups;
}

//Kruskal's Algorithm (finding MST)

int kruskal_algo(vector<vector<int>> &arr)
{
    for (int i = 0; i < N; i++)
    {
        par.push_back(i);
    }
    vector<vector<edge>> kruskal_graph;
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    int MST = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int p1 = findpar(arr[i][0]);
        int p2 = findpar(arr[i][1]);
        if (p1 != p2)
        {
            par[p1] = p2;
            MST += arr[i][2];
            addedge(kruskal_graph, arr[i][0], arr[i][1], arr[i][2]);
        }
    }
    display_(kruskal_graph);
    return MST;
}

/**leetcode 1168
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i], or pipe in water from another well 
to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[i] = [house1, house2, cost] 
represents the cost to connect house1 and house2 together using a pipe. Connections are bidirectional.

Find the minimum total cost to supply water to all houses.

Example 1:

Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so 
the total cost is 3.

Constraints:

1 <= n <= 10000
wells.length == n
0 <= wells[i] <= 10^5
1 <= pipes.length <= 10000
1 <= pipes[i][0], pipes[i][1] <= n
0 <= pipes[i][2] <= 10^5
pipes[i][0] != pipes[i][1]
*/

// leetcode 1168 solution

int leetcode_1168(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < n; i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
        par.push_back(i);
    }
    par.push_back(wells.size());
    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    int cost = 0;
    for (vector<int> &p : pipes)
    {
        int p1 = findpar(p[0]);
        int p2 = findpar(p[1]);
        if (p1 != p2)
        {
            cost += p[2];
            par[p1] = p2;
        }
    }

    return cost;
}

//Hacker earth: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
int mr_president()
{
    ll N, M, k;
    cin >> N >> M >> k;
    vector<vector<int>> graph;
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    for (int i = 0; i <= N; i++)
    {
        par.push_back(i);
    }
    sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    vector<vector<int>> newgraph;
    ll MST = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int p1 = findpar(graph[i][0]);
        int p2 = findpar(graph[i][1]);
        if (p1 != p2)
        {
            par[p1] = p2;
            MST += graph[i][2];
            newgraph.push_back(graph[i]);
        }
    }
    int no = 0;
    for (int i = 1; i <= N; i++)
    {
        if (par[i] == i && ++no > 1)
            return -1;
    }
    int n = 0;
    for (int i = newgraph.size() - 1; i >= 0; i--)
    {
        if (MST <= k)
        {
            break;
        }
        MST = MST - newgraph[i][2] + 1;
        n++;
    }
    return MST <= k ? n : -1;

    return n;
}
auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

//Hackerrank: https://www.hackerrank.com/challenges/journey-to-the-moon/problem

// leetcode 924 -> question link: https://leetcode.com/problems/minimize-malware-spread/discuss/614031/C++-:-Union-Find-(pepcoding.com)-reframe-the-question-on-"CORONA"-with-relatable-explanation

//dijistra's Algorithm

class pair_
{
public:
    int src;
    int par;
    int w;
    int wsf;
    pair_(int src, int par, int w, int wsf)
    {
        this->src = src;
        this->par = par;
        this->w = w;
        this->wsf = wsf;
    }
};

struct dijistrcomp
{
public:
    bool operator()(pair_ const &a, pair_ const &b)
    {
        return a.wsf > b.wsf;
    }
};

void dijistra_algo(int src)
{
    vector<vector<edge>> dijistra_graph(graph.size());
    priority_queue<pair_, vector<pair_>, dijistrcomp> pq;
    vector<bool> vis(N, false);
    pq.push({src, -1, 0, 0});
    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair_ idx = pq.top();
            pq.pop();
            if (vis[idx.src])
            {
                continue;
            }
            if (idx.par != -1)
            {
                addedge(dijistra_graph, idx.par, idx.src, idx.w);
            }

            vis[idx.src] = true;
            for (edge e : graph[idx.src])
            {
                if (!vis[e.u])
                {
                    pair_ p1(e.u, idx.src, e.w, idx.wsf + e.w);
                    pq.push(p1);
                }
            }
        }
    }
    display_(dijistra_graph);
}

//prims Algo

struct primscomp
{
public:
    bool operator()(pair_ &a, pair_ &b)
    {
        return a.w > b.w;
    }
};

void prims_algo(int src)
{
    vector<vector<edge>> prims_graph(graph.size());
    priority_queue<pair_, vector<pair_>, primscomp> pq;
    vector<bool> vis(N, false);
    pq.push({src, -1, 0, 0});
    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair_ idx = pq.top();
            pq.pop();
            if (vis[idx.src])
            {
                continue;
            }
            if (idx.par != -1)
            {
                addedge(prims_graph, idx.par, idx.src, idx.w);
            }

            vis[idx.src] = true;
            for (edge e : graph[idx.src])
            {
                if (!vis[e.u])
                {
                    pair_ p1(e.u, idx.src, e.w, idx.wsf + e.w);
                    pq.push(p1);
                }
            }
        }
    }
    display_(prims_graph);
}

//leetcode 743
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> graph(n + 1);
    for (vector<int> e : times)
    {
        graph[e[0]].push_back({e[1], e[2]});
    }
    vector<int> dis(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair<int, int> idx = pq.top();
            pq.pop();

            if (dis[idx.second] != -1)
            {
                continue; //cycle
            }
            dis[idx.second] = idx.first;
            for (pair<int, int> p : graph[idx.second])
            {
                if (dis[p.first] == -1)
                {
                    pq.push({p.second + idx.first, p.first});
                }
            }
        }
    }
    int maxtime = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == -1)
        {
            return -1;
        }
        maxtime = max(maxtime, dis[i]);
    }
    return maxtime;
}

//leetcode 787
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> graph(n);
    for (vector<int> e : flights)
    {
        graph[e[0]].push_back({e[1], e[2]});
    }

    vector<int> dis(n, -1);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, k + 1});
    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size--)
        {
            vector<int> idx = pq.top();
            pq.pop();

            if (idx[1] == dst)
                return idx[0]; // it will find the cost
            if (idx[2] == 0)
                continue; // it will check for no of stops

            dis[idx[1]] = idx[0];
            for (pair<int, int> e : graph[idx[1]])
            {
                if (dis[e.first] == -1)
                {
                    pq.push({e.second + idx[0], e.first, idx[2] - 1});
                }
            }
        }
    }
    return -1;
}

//Bellman Ford Algorithm

//Finding Articulation Points
vector<int> dis(N, 0);
vector<int> low(N, 0);
vector<bool> vis_(N, false);
vector<int> AP(N, 0);
int time = 0;
int rootcalls = 0;
void DFS_AP(int src, int par)
{
    dis[src] = low[src] = time++;
    vis_[src] = true;
    for (edge e : graph[src])
    {
        int child = e.u;
        if (!vis_[child])
        {
            if (par == -1)
            {
                rootcalls++;
            }
            DFS_AP(child, src);
            if (dis[src] <= low[child])
            {
                AP[src]++;
            }
            low[src] = min(low[src], low[child]);
        }
        else if (child != par)
        {
            low[src] = min(low[src], dis[child]);
        }
    }
}

void print_AP()
{
    int src = 0;
    DFS_AP(src, -1);
    if (rootcalls == 1)
    {
        AP[src]--;
    }
    for (int i = 0; i < N; i++)
    {
        if (AP[i] != 0)
        {
            cout << i << " @ " << AP[i] << endl;
        }
    }
}

//*********************************************************************************************************************
void solve()
{
    vector<bool> vis(N, false);
    // vector<vector<char>> board={};
    // constructgraphU(0,1,10);
    // constructgraphU(1,2,10);
    // constructgraphU(2,3,10);
    constructgraphB(0, 1, 20);
    constructgraphB(0, 3, 20);
    constructgraphB(2, 1, 10);
    constructgraphB(2, 3, 40);
    constructgraphB(3, 4, 2);
    constructgraphB(4, 5, 3);
    constructgraphB(4, 6, 8);
    constructgraphB(5, 6, 2);

    //removeedge(3,4);
    // removevertex(3);
    //postorder(0,vis,0,"");
    //cout<<findedge(1,5);
    display();
    // allsolutionpair pair;
    // allsolution(0,6,0,vis,"",pair,20);
    // cout<<pair.lightpath<<"@"<<pair.lightW<<endl;
    // cout<<pair.heavypath<<"@"<<pair.heavyW<<endl;
    // cout<<pair.ceilpath<<"@"<<pair.ceil<<endl;
    // cout<<pair.floorpath<<"@"<<pair.floor<<endl;
    //ishamiltoniancycle(2,2,0,vis,"");
    // cout<<GCC(vis);
    //cout<<differIslands(board);
    //BFS_04(0,vis);
    // isbarpatite();
    //topoDFS();
    //cycledetectDFS();
    // cout<<kosarajualgo();
    // cout<<Union_find_detect_cycle;
    // cout<<numIslands2(board);

    // vector<vector<int>> arr;
    // for(int i=0;i<N;i++){
    //     for(edge e:graph[i]){
    //         arr.push_back({i,e.u,e.w});
    //     }
    // }
    // cout<<kruskal_algo(arr);

    // int n=3;
    // vector<int> wells={2,2,2};
    // vector<vector<int>> pipes={{1,2,1},{2,3,1},{1,3,-1}};
    // cout<<leetcode_1168(n,wells,pipes)<<endl;
    // dijistra_algo(0);
    // prims_algo(0);
    print_AP();
}
int main()
{
    solve();
    return 0;
}






// Must read article for Graph:  https://leetcode.com/discuss/study-guide/1326900/graph-algorithms-problems-to-practice



// BFS problems
// Flood Fill: https://leetcode.com/problems/flood-fill/
// Number of Islands: https://leetcode.com/problems/number-of-islands/
// Word Ladder I: https://leetcode.com/problems/word-ladder/
// Word Ladder II: https://leetcode.com/problems/word-ladder-ii/
// Evaluate Division: https://leetcode.com/problems/evaluate-division/
// Get Watched Videos by Your Friends: https://leetcode.com/problems/get-watched-videos-by-your-friends/
// Cut Off Trees for Golf Event: https://leetcode.com/problems/cut-off-trees-for-golf-event/


// DFS problems
// Number of Islands: https://leetcode.com/problems/number-of-islands/
// Flood Fill: https://leetcode.com/problems/flood-fill/
// Longest Increasing Path in a Matrix: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Evaluate Division: https://leetcode.com/problems/evaluate-division/
// Robot Room Cleaner: https://leetcode.com/problems/robot-room-cleaner/
// Most Stones Removed with Same Row or Column: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Reconstruct Itinerary: https://leetcode.com/problems/reconstruct-itinerary/
// Tree Diameter: https://leetcode.com/problems/tree-diameter/
// Accounts Merge: https://leetcode.com/problems/accounts-merge/


// Connected components problems
// Number of Provinces: https://leetcode.com/problems/number-of-provinces/
// Number of Connected Components in an Undirected Graph: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Number of Operations to Make Network Connected: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Accounts Merge: https://leetcode.com/problems/accounts-merge/
// Critical Connections in a Network: https://leetcode.com/problems/critical-connections-in-a-network/


// Dijkstra's problems
// Path With Maximum Minimum Valued: https://leetcode.com/problems/path-with-maximum-minimum-value/
// Network delay time: https://leetcode.com/problems/network-delay-time/
// Path With Minimum Effort: https://leetcode.com/problems/path-with-minimum-effort/
// Cheapest Flights Within K Stops: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// https://leetcode.com/problems/the-maze-ii/
// https://leetcode.com/problems/the-maze-iii/
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/


// Union Find problems
// Number of Islands: https://leetcode.com/problems/number-of-islands/
// Largest Component Size by Common Factor: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Most Stones Removed with Same Row or Column: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Number of Connected Components in an Undirected Graph: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/


// Minimum Spanning Tree problems
// Connecting Cities With Minimum Cost: https://leetcode.com/problems/connecting-cities-with-minimum-cost/
// Min Cost to Connect All Points: https://leetcode.com/problems/min-cost-to-connect-all-points/


// Topological sort problems
// Course Schedule : https://leetcode.com/problems/course-schedule/
// Course Schedule II: https://leetcode.com/problems/course-schedule-ii/
// Sequence Reconstruction: https://leetcode.com/problems/sequence-reconstruction/      // Lintcode 605   // Bad Question
// Alien Dictionary: https://leetcode.com/problems/alien-dictionary/


// Floyd Warshall problems
// Find the City With the Smallest Number of Neighbors at a Threshold Distance: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Network delay time: https://leetcode.com/problems/network-delay-time/


// Bellman Ford problems
// Network delay time: https://leetcode.com/problems/network-delay-time/
