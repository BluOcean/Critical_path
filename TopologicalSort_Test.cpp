#include "TopologicalSort.h"

void InsertEdge(ALGraph &G,int i, int a, int w)
{
    //新建一个表节点
    ArcNode *end = new ArcNode(a, w);
    end->nextarc=NULL;

    //将第i个单链表移动到表尾
    //ArcNode *temp = G.vertices[i].firstarc;
    if (!G.vertices[i].firstarc)
    {

        G.vertices[i].firstarc=end;
        return;
    }
    ArcNode *temp = G.vertices[i].firstarc;

    while (temp->nextarc)
    {
        cout<<"build执行了next"<<endl;
        temp = temp->nextarc;
    }
    //在尾部插入该表节点
    if(temp)
    {
        //p=temp;
        temp->nextarc=end;

        cout<<"insert执行了一次end"<<endl;
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

    cout << "输入顶点的个数" << endl;
    cin >> G.vexnum;
    cout << "输入弧的个数" << endl;
    cin >> G.arcnum;
    for ( i = 0; i < G.vexnum; i++)
    {
        cout << "输入第" << i + 1 << "个顶点的位置及边数" << endl;
        cin >> G.vertices[i].data;
        int single_arc_num = 0;
        cin >> single_arc_num;
        for (j = 0; j < single_arc_num; j++)
        {
            cout <<"输入第" << i + 1 << "个顶点相邻的表节点的顶点位置以及权值" << endl;
            int a = 0, w = 0;
            cin >> a >> w;

            InsertEdge(G,i, a, w);
        }
    }
}

void printALGraph(ALGraph &G)
{
    cout << "图的邻接表为：" << endl;
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

            //tempArc=tempArc->nextarc;   //从第一条相邻边到第二条相邻边
            //第二条相邻边存在时
            while (tempArc->nextarc)
            {
                cout<<"<"<<tempArc->adjvex<<",";
                tempArc=tempArc->nextarc;
                cout<<tempArc->adjvex<<">="<<tempArc->weight<<" ";
            }
            if(!tempArc)
            {
                cout<<"tempArc为空"<<endl;
            }

        }
        cout << "^" << endl;
        ++count;

    }
}

//计算每个节点的入度，并保存在indegree中
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


    //初始化数组
    for(i=0; i<G.vexnum; i++)
    {
        indegree[i]=0;
    }
    FindInDegree(G,indegree);


    cout<<"G.vexnum是"<<G.vexnum<<endl;

    for(i=0; i<G.vexnum; ++i)
    {
        if(!indegree[i])
            s.push(i);//找到入度为0的位置，入栈
    }
    count=0;

    //初始化各顶点事件的最早发生时间ve
    for(i=0; i<G.vexnum; ++i)
    {
        ve[i]=0;
    }

    while(!s.empty())
    {
        i = s.top();//保存栈顶元素
        s.pop();    //删除栈顶元素
        t.push(i);  //入t栈

        ++count;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc)  //p是一条边
        {
            k=(p->adjvex)-1;
            if(!(--indegree[k]))
                s.push(k);
            if(ve[i]+p->weight>ve[k])
                ve[k]=ve[i]+p->weight;
            //cout<<"ve["<<k<<"]是"<<ve[k]<<endl;
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



