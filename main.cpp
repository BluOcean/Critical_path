#include "TopologicalSort.h"

/*
#include<string>
#include<queue>
using namespace std;
#define MAX_VERTEX_NUM 20
#define ERROR 1

typedef struct ArcNode
{
    ArcNode(int a, int w) :adjvex(a), weight(w), nextarc(NULL) {}
    ArcNode() :nextarc(NULL) {}
    int adjvex;                         //该弧指向的顶点的位置
    int weight;                         //边的权值
    ArcNode *nextarc;
} ArcNode;
typedef struct VNode
{
    int data;
    ArcNode *firstarc;                  //指向第一条依附于该点的弧的指针
} VNode,AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
    int kind;
} ALGraph;
*/


int main()
{

    //stack<int> s;
    ALGraph G;
    BuildALGraph(G);
    printALGraph(G);    //打印邻接表
    if(TopologicalSort(G)){
        cout<<'\n'<<"拓扑排序输出成功"<<endl;
    }
    else{
        cout<<'\n'<<"拓扑排序失败"<<endl;
    }


    if(CriticalPath(G)){
        cout<<'\n'<<"关键路径输出成功"<<endl;
    }
    else{
        cout<<'\n'<<"关键路径输出失败"<<endl;
    }


    //cout<<'\n'<<TopologicalSort(G)<<endl;
    return 0;
}
