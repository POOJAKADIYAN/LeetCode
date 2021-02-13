// On a **N * M** chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return a **N * M** array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

// **Notes:**

// 1. Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
// 2. You are given an array of N strings, each of size M. Each character is either a `1` or `0` denoting if there is a queen at that position or not, respectively.
// 3. Expected time complexity is worst case O(N*M).

// **For example**,

// `Let chessboard be,
// [0 1 0]
// [1 0 0]
// [0 0 1]
// where a 1 denotes a queen at that position.
// Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
// Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
// Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
// and so on...
// Finally, we return matrix
// [3, 1, 2]
// [1, 3, 3]
// [2, 3, 0]`

// ## SOLUTION -


int row[]={0,-1,-1,-1,0,1,1,1};
int col[]={1,1,0,-1,-1,-1,0,1};
int n,m;
void rec(vector<string> &A,vector<vector<int> > &mem,int i,int j,int k)
{   
	  if(i>=n || i<0 || j>=m || j<0)
       return;
    if(A[i][j]=='1') 
    {
			 mem[i][j]++; 
       return;
		}
    mem[i][j]++;
    rec(A,mem,i+row[k],j+col[k],k);
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) 
{    
     n=A.size();
     m=A[0].size();
     vector<vector<int> > mem(n,vector<int> (m,0));
		 for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					for(int k=0;k<8;k++)
				    if(A[i][j]=='1')
			        rec(A,mem,i+row[k],j+col[k],k);
		 return mem;
}