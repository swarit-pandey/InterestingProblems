/*
Smallest Intersecting Element
Question 746 of 818

You are given a two-dimensional list of integers matrix where each row is sorted in ascending order. Return the smallest number that exists in every row. If there's no solution, return -1.

Constraints

    n, m ≤ 250 where n and m are the number of rows and columns in matrix

Example 1

Input

matrix = [
    [1, 2, 4],
    [4, 9, 9],
    [0, 2, 4]
]

Output

4
*/

/*
INTUITION:
The idea is to map all the elements and maintain a set, as set will only take distinct elements 
we can be sure that it will only contain the elements which are actually common in all the rows.
*/

#define matrix mat

int solve(vector<vector<int>>& matrix) {
    int n = mat.size();
    map<int, set<int>> m;
    
    int goToSet = 0;
    for(auto i : mat) {
        for(auto j : i) {
            m[j].insert(goToSet);
        }
        goToSet++;
    }
    
    for(auto i : m) {
        auto l = i.second;
        if(l.size() == n) {
            return i.first;
        }
    }
    
    return -1;
}
