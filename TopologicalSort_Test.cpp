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
        /*(*temp).adjvex = a;
        (*temp).weight = w;*/

        //temp=end;
        G.vertices[i].firstarc=end;
        return;
    }
    ArcNode *temp = G.vertices[i].firstarc;
    //int *p;
    //ArcNode **p=&(G.vertices[i].firstarc);
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

/*
int LocateVex(ALGraph &G,char &v1)   //���ҽڵ�V1��ͼG�Ĵ洢�ڵ������е�����λ��
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v1) //���������������ڵ㣬���ظýڵ��������е�����
            return i;
    }
    if(i>=G.vexnum)
        return ERROR;
    else
        return 0;
}
*/

//����ͼ
/*
void CreateDG(ALGraph &G)
{
    ArcNode *p,*q;
    char v1,v2;
    char v;
    int i,j,k,n;
    cout<<"������ͼ�Ķ������ͻ�����"<<endl;
    cin>>G.vexnum; //����ͼ�Ķ�������
    cin>>G.arcnum; //����ͼ�Ļ����ߣ�������
    cout<<"�����붥�㣺"<<endl;

    for(i=0;i<G.vexnum;i++) //����ͷ���
    {
        cin>>v;   //���붥������
        G.vertices[i].data=v;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"�����뻡β�ͻ�ͷ��";
    for(k=0;k<G.arcnum;k++) //�����ߣ�������ͷ���
    {
        cin>>v1;  //v1Ϊ��β
        cin>>v2;   //v2Ϊ��ͷ
        i=LocateVex(G,v1);j=LocateVex(G,v2);

        if(G.vertices[i].firstarc==NULL)  //�������Ϊ���½�һ����ڵ㣬��ͷ�ڵ��ָ��ָ��ñ�ڵ�
        {
            p=(ArcNode *)new ArcNode;
            G.vertices[i].firstarc=p;
            q=G.vertices[i].firstarc;
        }
        else        //����Ĳ���
        {
            q=G.vertices[i].firstarc;//��ȡͷ���ı�ͷָ��
            for(n=0;n<G.arcnum;n++,q=q->nextarc)//��qָ���ƶ��������β�ʹ�
            {
                if(!q->nextarc)
                    break;
            }
            p=(ArcNode *)new ArcNode;
            q->nextarc=p; //���ñߣ��������뵽������
            q=q->nextarc;
        }
        q->adjvex=j;  //��¼��ͷ������
        q->nextarc=NULL;
    }
    cout<<"ͼ�����ɹ���";
}
*/

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
                //tempArc=tempArc->nextarc;
                //cout<<"ִ����while  ";
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
/*
void CreateALGraph(VNode vnode,ArcNode arcnode){
    int vexnum;
    int data;
    int arcnum;
    int adjvex;
    int weight;

    int i;
    int j;

    cout<<"�����������ڽӱ�"<<endl;
    cout<<"�����붥������:"<<endl;
    cin>>vexnum;
    if (vexnum<=0) return 0;
    for(i=1;i<=vexnum;i++){
        cout<<"�������"<<i<<"���������Ϣ��"<<endl;
        cin>>data;
        vnode.data=data;
        cout<<"����ö��㻡������:"<<endl;
        cin>>arcnum;
        if(arcnum>0){
            for(j=1;j<=arcnum;j++){
                cout<<"�����"<<j<<"������ָ��Ķ����λ��:"<<endl;
                cin>>adjvex;
                arcnode.adjvex=adjvex;
                cout<<"�����"<<j<<"������Ȩֵ:"<<endl;
                cin>>weight;
                arcnode.weight=weight;
                vnode.

            }
        }
    }

}*/

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
    //int ve[G.vexnum];
    int i;
    int count;
    ArcNode *p;
    int k;
    //��ʼ������
    for(i=0;i<G.vexnum;i++){
        indegree[i]=0;
    }
    FindInDegree(G,indegree);
    //cout<<"������"<<indegree[0]<<' '<<indegree[1]<<endl;
    //stack<int> s;
    cout<<"G.vexnum��"<<G.vexnum<<endl;
    for(i=0; i<G.vexnum; ++i){
        if(!indegree[i])    s.push(i);//�ҵ����Ϊ0��λ�ã���ջ
    }
    count=0;

    //��ʼ���������¼������緢��ʱ��ve
    for(i=0;i<G.vexnum;++i){
        ve[i]=0;
    }

    while(!s.empty())
    {
        i = s.top();//����ջ��Ԫ��
        s.pop();    //ɾ��ջ��Ԫ��
        t.push(i);  //��tջ
        //cout << G.vertices[i].data<<" ";//�����������
        ++count;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc)  //p��һ����
        {
            k=(p->adjvex)-1;
            if(!(--indegree[k]))    s.push(k);
            if(ve[i]+p->weight>ve[k])   ve[k]=ve[i]+p->weight;
            cout<<"ve["<<k<<"]��"<<ve[k]<<endl;
        }
    }
    //cout<<"ִ����һ����������"<<endl;
    if(count<G.vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }

}



