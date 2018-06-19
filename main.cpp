#include "TopologicalSort.h"

stack<int> s;
stack<int> t;
int ve[MAX_VERTEX_NUM];

int main()
{


    ALGraph G;
    BuildALGraph(G);
    printALGraph(G);    //打印邻接表

    if(CriticalPath(G)){
        cout<<'\n'<<"关键路径输出成功"<<endl;
    }
    else{
        cout<<'\n'<<"关键路径输出失败"<<endl;
    }

    return 0;
}
