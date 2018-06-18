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
    int adjvex;                         //�û�ָ��Ķ����λ��
    int weight;                         //�ߵ�Ȩֵ
    ArcNode *nextarc;
} ArcNode;
typedef struct VNode
{
    int data;
    ArcNode *firstarc;                  //ָ���һ�������ڸõ�Ļ���ָ��
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
    printALGraph(G);    //��ӡ�ڽӱ�
    if(TopologicalSort(G)){
        cout<<'\n'<<"������������ɹ�"<<endl;
    }
    else{
        cout<<'\n'<<"��������ʧ��"<<endl;
    }


    if(CriticalPath(G)){
        cout<<'\n'<<"�ؼ�·������ɹ�"<<endl;
    }
    else{
        cout<<'\n'<<"�ؼ�·�����ʧ��"<<endl;
    }


    //cout<<'\n'<<TopologicalSort(G)<<endl;
    return 0;
}
