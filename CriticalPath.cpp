#include "TopologicalSort.h"

int CriticalPath(ALGraph G){
    int vl[G.vexnum];   //�����¼�����ٷ���ʱ��
    int i,j,k;
    int ve_max=0;
    int dut;    //����ʱ�䣨Ȩֵ��
    ArcNode *p;

    for(i=0;i<G.vexnum;++i){
        if(ve[i]>ve_max)    ve_max=ve[i];
    }

    if(!TopologicalSort(G)) return ERROR;

    //��ʼ��
    for(i=0;i<G.vexnum;++i){
        vl[i]=ve_max;
    }

    while(!s.empty()){  //��������������������vlֵ
        j=t.top();
        t.pop();
        for(p=G.vertices[j].firstarc;p;p=p->nextarc){
            k=(p->adjvex)-1;
            dut=p->weight;
            if(vl[k]-dut<vl[j]) vl[j]=vl[k]-dut;
        }
    }

    cout<<"�ؼ�·����:";
    for(j=0;i<G.vexnum;++j){
        for(p=G.vertices[j].firstarc;p;p=p->nextarc){
            k=(p->adjvex)-1;
            dut=p->weight;
            if(ve[j]==(vl[k]-dut)){
                cout<<j;
            }
        }
    }
    cout<<'\n'<<"�ؼ�·��ִ�����"<<endl;
    return OK;
}
