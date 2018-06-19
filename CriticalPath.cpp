#include "TopologicalSort.h"

int CriticalPath(ALGraph G)
{
    int vl[G.vexnum];   //�����¼�����ٷ���ʱ��
    int i,j,k;
    //int ve_max=0;
    int dut;    //����ʱ�䣨Ȩֵ��
    //stack<int> q=t;
    ArcNode *p;


    //�����Ƿ��л�
    if(!TopologicalSort(G))
        return ERROR;

    //��ʼ����ٷ���ʱ��vl
    for(i=0; i<G.vexnum; ++i)
    {
        vl[i]=ve[G.vexnum-1];
    }

    if(t.empty())
    {
        cout<<"t�ǿյ�"<<endl;

    }



    while(!t.empty())   //��������������������vlֵ
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
                cout<<'\n'<<"��ٷ���ʱ����:";
                cout<<vl[k]<<endl;
                */
            }
        }
    }

    //�����ٷ���ʱ��
    cout<<"���vlֵ:"<<endl;
    for(j=0; j<G.vexnum; j++)
    {
        cout<<vl[j]<<endl;
    }

    cout<<"�ؼ�·����:";
    for(j=0; j<G.vexnum; ++j)
    {
        for(p=G.vertices[j].firstarc; p; p=p->nextarc)
        {
            k=(p->adjvex)-1;
            dut=p->weight;
            if(ve[j]==(vl[k]-dut))  //����ؼ�·��
            {

                cout<<"<"<<j+1<<","<<k+1<<">"<<' ';
            }
        }
    }

    cout<<'\n'<<"�ؼ�·��ִ�����"<<endl;
    return OK;
}
