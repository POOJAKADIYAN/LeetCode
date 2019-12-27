// Given a binary matrix, Your task is to complete the function

// **maxArea**

// which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M and the next two are two integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

// **Input:**

// The first line of input is an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in the next line are n*m space separated values of the matrix M.

// **Output:**

// For each test case output will be the area of the maximum rectangle .

// **Constraints:**

// 1<=T<=501<=n,m<=500<=M[][]<=1

// **Example:**

// **Input**

// 14 4 0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

// **Output**

// 8

// **Explanation**

// For the above test case the matrix will look like0 1 1 01 1 1 11 1 1 11 1 0 0the max size rectangle is 1 1 1 11 1 1 1and area is 4 *2 = 8

// ## SOLUTION -


int hg(vector <int> row,int m)
{
    stack <int> st;
    int i=0,x,maxx=0,area;
    while(i<m)
    {
        if(st.empty() || row[st.top()]<=row[i])
            st.push(i++);
        else
        {
            x=st.top();
            st.pop();
            area=row[x]*(st.empty()?i:i-st.top()-1);
            if(maxx<area)
                maxx=area;
        }
    }
    while(!st.empty())
    {
        x=st.top();
        st.pop();
        area=row[x]*(st.empty()?i:i-st.top()-1);
        if(area>maxx)
        maxx=area;
    }
    return maxx;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    vector <int> row(m);
    memset(&row[0], 0 , sizeof(row) );
    //memset(row,0,sizeof(row));
    int ans,maxhist,maxx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==0)
                row[j]=0;
            else
                row[j]+=1;
        }
        maxhist=hg(row,m);
        if(maxhist>maxx)
            maxx=maxhist;
    }
    return maxx;
}