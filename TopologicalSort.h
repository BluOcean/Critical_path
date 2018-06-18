#ifndef TOPOLOGICALSORT_H_INCLUDED
#define TOPOLOGICALSORT_H_INCLUDED

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
#define MAX_VERTEX_NUM 20
#define ERROR 0
#define OK 1

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

static stack<int> s;    //������������
static stack<int> t;    //���ڹؼ�·��

static int *ve=new int[MAX_VERTEX_NUM]; //����������緢��ʱ��

void BuildALGraph(ALGraph &G);
void printALGraph(ALGraph &G);
void FindInDegree(ALGraph G,int indegree[]);
int TopologicalSort(ALGraph G);
int CriticalPath(ALGraph G);


#endif // TOPOLOGICALSORT_H_INCLUDED
