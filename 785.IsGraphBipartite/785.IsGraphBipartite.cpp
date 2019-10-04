class Solution {
public:
    map<int,int>m;
    int parent(int a)
    {
        if(m.count(a)==0)return -1;
        if(m[a]==a)return a;
        return parent(m[a]);
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
 
        int n=graph.size();
        int parenta,parentb;
        int x,y;// x,y denote the head vertices which represent the 2 sets
        for(int i=0;i<n;i++)
        {
            parenta=parent(i);
            for(int j:graph[i])
            {
                parentb=parent(j);
                if(parenta==-1 && parentb==-1)//for the first edge
                {
                    m[i]=i;
                    m[j]=j;
                    parenta=i;
                    parentb=j;
                    x=i;y=j;
                }
                else if(parenta==parentb)
                {
                    return false;
                }
                else if(parenta==-1)
                {
                    if(parentb==x)m[i]=y;
                    else m[i]=x;
                }
                else if(parentb==-1)
                {
                    if(parenta==x)m[j]=y;
                    else m[j]=x;
                }
                else
                {
                    m[i]=parenta;
                    m[j]=parentb;
                }
            }
        }
        return true;
        
    }
};