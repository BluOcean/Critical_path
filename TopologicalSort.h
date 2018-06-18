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


void BuildALGraph(ALGraph &G);
void printALGraph(ALGraph &G);
void FindInDegree(ALGraph G,int indegree[]);
int TopologicalSort(ALGraph G);


#endif // TOPOLOGICALSORT_H_INCLUDED
