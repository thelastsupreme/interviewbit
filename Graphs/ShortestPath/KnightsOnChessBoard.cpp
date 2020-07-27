// Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

// Knight's movements on a chess board

// The above figure details the movements for a knight ( 8 possibilities ).

// If yes, then what would be the minimum number of steps for the knight to move to the said point.
// If knight can not move from the source point to the destination point, then return -1.

// Note: A knight cannot go out of the board.



// Input Format:

// The first argument of input contains an integer A.
// The second argument of input contains an integer B.
//     => The chessboard is of size A x B.
// The third argument of input contains an integer C.
// The fourth argument of input contains an integer D.
//     => The Knight is initially at position (C, D).
// The fifth argument of input contains an integer E.
// The sixth argument of input contains an integer F.
//     => The Knight wants to reach position (E, F).
// Output Format:

// If it is possible to reach the destination point, return the minimum number of moves.
// Else return -1.
// Constraints:

// 1 <= A, B <= 500
// Example

// Input 1:
//     A = 8
//     B = 8
//     C = 1
//     D = 1
//     E = 8
//     F = 8
    
// Output 1:
//     6

// Explanation 1:
//     The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
//     The minimum number of moves required for this is 6.

#include <bits/stdc++.h>
using namespace std;

//just traversing but change the x and y traverse key value from 1s and 0s to 1s and 2s

bool issafe(int x,int y,int a, int b)
{
    return !(x<=0 || y<=0 || x>a || y>b);
}
int knight(int a, int b, int c, int d, int e, int f) {
    if(!issafe(c,d,a,b) || !issafe(e,f,a,b)) return -1;
    if(c == e && d == f) return 0;
    int count = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(c,d));
    vector<vector<bool>>vis(a+1,vector<bool>(b+1,0));
    vis[c][d] = 1;
    vector<int> r = {2,1,-1,-2,-2,-1,1,2};
    vector<int> col = {1,2,2,1,-1,-2,-2,-1};
    while(!q.empty())
    {
        int x = q.size();
        while(x--)
        {
            int u= q.front().first;
            int v= q.front().second;
            q.pop();
            for(int i=0; i<8; i++)
            {
                if(issafe(u+r[i],v+col[i],a,b) && !vis[u+r[i]][v+col[i]])
                {
                    if(u+r[i] == e && v + col[i] == f)
                    {
                        return count+1;
                    }
                    vis[u+r[i]][v+col[i]] = true;
                    q.push(make_pair(u+r[i],v+col[i]));
                }
            }
        }
        ++count;
    }
    return -1;
}