#include "TopologicalSort.h"

int CriticalPath(ALGraph G){
    int vl[G.vexnum];   //顶点事件的最迟发生时间
    int i,j,k;
    int ve_max=0;
    int dut;    //持续时间（权值）
    ArcNode *p;

    for(i=0;i<G.vexnum;++i){
        if(ve[i]>ve_max)    ve_max=ve[i];
    }

    if(!TopologicalSort(G)) return ERROR;

    //初始化
    for(i=0;i<G.vexnum;++i){
        vl[i]=ve_max;
    }

    while(!s.empty()){  //按逆拓扑排序求各顶点的vl值
        j=t.top();
        t.pop();
        for(p=G.vertices[j].firstarc;p;p=p->nextarc){
            k=(p->adjvex)-1;
            dut=p->weight;
            if(vl[k]-dut<vl[j]) vl[j]=vl[k]-dut;
        }
    }

    cout<<"关键路径是:";
    for(j=0;i<G.vexnum;++j){
        for(p=G.vertices[j].firstarc;p;p=p->nextarc){
            k=(p->adjvex)-1;
            dut=p->weight;
            if(ve[j]==(vl[k]-dut)){
                cout<<j;
            }
        }
    }
    cout<<'\n'<<"关键路径执行完毕"<<endl;
    return OK;
}
