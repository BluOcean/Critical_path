#include "TopologicalSort.h"

int CriticalPath(ALGraph G)
{
    int vl[G.vexnum];   //顶点事件的最迟发生时间
    int i,j,k;
    //int ve_max=0;
    int dut;    //持续时间（权值）
    //stack<int> q=t;
    ArcNode *p;


    //检验是否有环
    if(!TopologicalSort(G))
        return ERROR;

    //初始化最迟发生时间vl
    for(i=0; i<G.vexnum; ++i)
    {
        vl[i]=ve[G.vexnum-1];
    }

    if(t.empty())
    {
        cout<<"t是空的"<<endl;

    }



    while(!t.empty())   //按逆拓扑排序求各顶点的vl值
    {
        j=t.top();
        t.pop();
        for(p=G.vertices[j].firstarc; p; p=p->nextarc)
        {
            k=(p->adjvex)-1;
            dut=p->weight;
            if(vl[k]-dut<vl[j])
            {
                vl[j]=vl[k]-dut;

                /*
                cout<<'\n'<<"最迟发生时间是:";
                cout<<vl[k]<<endl;
                */
            }
        }
    }

    //输出最迟发生时间
    cout<<"输出vl值:"<<endl;
    for(j=0; j<G.vexnum; j++)
    {
        cout<<vl[j]<<endl;
    }

    cout<<"关键路径是:";
    for(j=0; j<G.vexnum; ++j)
    {
        for(p=G.vertices[j].firstarc; p; p=p->nextarc)
        {
            k=(p->adjvex)-1;
            dut=p->weight;
            if(ve[j]==(vl[k]-dut))  //输出关键路径
            {

                cout<<"<"<<j+1<<","<<k+1<<">"<<' ';
            }
        }
    }

    cout<<'\n'<<"关键路径执行完毕"<<endl;
    return OK;
}
