#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
       
       for(auto p : prerequisites){
            graph[p[0]].push_back(p[1]);
       }

       vector<int> visited(numCourses, 0);
       for(int i = 0; i < numCourses; i++){
            if(!dfs(graph, i, visited))  return false;

       }
       return true;
    }

    bool dfs(vector<vector<int>>& graph, int course, vector<int>& visited){
        if(visited[course] == 1)    return false;
        if(visited[course] == 2)    return true;

        visited[course] = 1;
        for(auto c : graph[course]){
            if(!dfs(graph, c, visited))     return false;

        }
        visited[course] = 2;
        return true;
    }
};