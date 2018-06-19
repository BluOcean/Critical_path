#include "TopologicalSort.h"

void InsertEdge(ALGraph &G,int i, int a, int w)
{
    //�½�һ����ڵ�
    ArcNode *end = new ArcNode(a, w);
    end->nextarc=NULL;

    //����i���������ƶ�����β
    //ArcNode *temp = G.vertices[i].firstarc;
    if (!G.vertices[i].firstarc)
    {

        G.vertices[i].firstarc=end;
        return;
    }
    ArcNode *temp = G.vertices[i].firstarc;

    while (temp->nextarc)
    {
        cout<<"buildִ����next"<<endl;
        temp = temp->nextarc;
    }
    //��β������ñ�ڵ�
    if(temp)
    {
        //p=temp;
        temp->nextarc=end;

        cout<<"insertִ����һ��end"<<endl;
    }

}

void BuildALGraph(ALGraph &G)
{

    int i;
    int j;
    for ( i = 0; i < MAX_VERTEX_NUM; i++)
    {
        G.vertices[i].data = -1;
        G.vertices[i].firstarc = NULL;
    }

    cout << "���붥��ĸ���" << endl;
    cin >> G.vexnum;
    cout << "���뻡�ĸ���" << endl;
    cin >> G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cout << "�����" << i + 1 << "�������λ�ü�����" << endl;
        cin >> G.vertices[i].data;
        int single_arc_num = 0;
        cin >> single_arc_num;
        for (j = 0; j < single_arc_num; j++)
        {
            cout <<"�����" << i + 1 << "���������ڵı�ڵ�Ķ���λ���Լ�Ȩֵ" << endl;
            int a = 0, w = 0;
            cin >> a >> w;

            InsertEdge(G,i, a, w);
        }
    }
}

void printALGraph(ALGraph &G)
{
    cout << "ͼ���ڽӱ�Ϊ��" << endl;
    int  count = 0;
    while (count != G.vexnum)
    {
        cout << G.vertices[count].data << " ";
        VNode temp = G.vertices[count];

        if(temp.firstarc)
        {
            cout<<"<"<<temp.data<<",";
            ArcNode *tempArc=temp.firstarc;
            cout<<tempArc->adjvex<<">="<<tempArc->weight<<" ";

            //tempArc=tempArc->nextarc;   //�ӵ�һ�����ڱߵ��ڶ������ڱ�
            //�ڶ������ڱߴ���ʱ
            while (tempArc->nextarc)
            {
                cout<<"<"<<tempArc->adjvex<<",";
                tempArc=tempArc->nextarc;
                cout<<tempArc->adjvex<<">="<<tempArc->weight<<" ";
            }
            if(!tempArc)
            {
                cout<<"tempArcΪ��"<<endl;
            }

        }
        cout << "^" << endl;
        ++count;

    }
}

//����ÿ���ڵ����ȣ���������indegree��
void FindInDegree(ALGraph G,int indegree[])
{
    ArcNode* temp;
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        temp=G.vertices[i].firstarc;
        while(temp)
        {
            ++indegree[(temp->adjvex)-1];
            temp=temp->nextarc;
        }
    }
}

int TopologicalSort(ALGraph G)
{
    int indegree[G.vexnum];

    int i;
    int count;
    ArcNode *p;
    int k;


    //��ʼ������
    for(i=0; i<G.vexnum; i++)
    {
        indegree[i]=0;
    }
    FindInDegree(G,indegree);


    cout<<"G.vexnum��"<<G.vexnum<<endl;

    for(i=0; i<G.vexnum; ++i)
    {
        if(!indegree[i])
            s.push(i);//�ҵ����Ϊ0��λ�ã���ջ
    }
    count=0;

    //��ʼ���������¼������緢��ʱ��ve
    for(i=0; i<G.vexnum; ++i)
    {
        ve[i]=0;
    }

    while(!s.empty())
    {
        i = s.top();//����ջ��Ԫ��
        s.pop();    //ɾ��ջ��Ԫ��
        t.push(i);  //��tջ

        ++count;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc)  //p��һ����
        {
            k=(p->adjvex)-1;
            if(!(--indegree[k]))
                s.push(k);
            if(ve[i]+p->weight>ve[k])
                ve[k]=ve[i]+p->weight;
            //cout<<"ve["<<k<<"]��"<<ve[k]<<endl;
        }
    }

    if(count<G.vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }

}



