class Solution {
private:
    int m;
    int n;
    map<pair<int,int>, int > umap;
    int res;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 得到短珠串的长度。【连三颗即成串，不必把所有珠子连起来】
     * @param pearls int整型vector<vector<>> n*2的二维数组，珠子的坐标，坐标值都为非负整数
     * @return int整型
     */
    void dfs(int& num,int length,int x, int y) {
        if(num == 3) {
            res = min(length,res);
        }
        if( x < 0 || y < 0 ||x >m || y >n) {
            return ;
        }
        if(umap[{x,y}]) {
            umap[{x,y}]--;
            num++;
        }
        dfs(num,length+1,x+1,y);
        dfs(num,length+1,x-1,y);
        dfs(num,length+1,x,y+1);
        dfs(num,length+1,x,y-1);
        umap[{x,y}]++;
    }
    int getMinLength(vector<vector<int> >& pearls) {
        // write code here
        m = 0;
        n = 0;
        for(auto & pearl:pearls) {
            umap[pair(pearl[0],pearl[1])]++;
            m = max(m,pearl[0]);
            n = max(n,pearl[1]);
        }
        res = INT_MAX;
        int val = 0;
        int num = 0;
        for(auto & pearl:pearls) {
            num = 0;
            dfs(num,val,pearl[0],pearl[1]);
        }
        return res;
    }
};