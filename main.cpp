#include "TopologicalSort.h"

stack<int> s;
stack<int> t;
int ve[MAX_VERTEX_NUM];

int main()
{


    ALGraph G;
    BuildALGraph(G);
    printALGraph(G);    //��ӡ�ڽӱ�

    if(CriticalPath(G)){
        cout<<'\n'<<"�ؼ�·������ɹ�"<<endl;
    }
    else{
        cout<<'\n'<<"�ؼ�·�����ʧ��"<<endl;
    }

    return 0;
}
