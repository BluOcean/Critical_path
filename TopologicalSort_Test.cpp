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

/*
int LocateVex(ALGraph &G,char &v1)   //查找节点V1在图G的存储节点数组中的索引位置
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v1) //如果数组中有这个节点，返回该节点在数组中的索引
            return i;
    }
    if(i>=G.vexnum)
        return ERROR;
    else
        return 0;
}
*/

//创建图
/*
void CreateDG(ALGraph &G)
{
    ArcNode *p,*q;
    char v1,v2;
    char v;
    int i,j,k,n;
    cout<<"请输入图的顶点数和弧数："<<endl;
    cin>>G.vexnum; //输入图的顶点数量
    cin>>G.arcnum; //输入图的弧（边）的数量
    cout<<"请输入顶点："<<endl;

    for(i=0;i<G.vexnum;i++) //创建头结点
    {
        cin>>v;   //输入顶点名字
        G.vertices[i].data=v;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"请输入弧尾和弧头：";
    for(k=0;k<G.arcnum;k++) //创建边，并连接头结点
    {
        cin>>v1;  //v1为弧尾
        cin>>v2;   //v2为弧头
        i=LocateVex(G,v1);j=LocateVex(G,v2);

        if(G.vertices[i].firstarc==NULL)  //如果链表为空新建一个表节点，让头节点的指针指向该表节点
        {
            p=(ArcNode *)new ArcNode;
            G.vertices[i].firstarc=p;
            q=G.vertices[i].firstarc;
        }
        else        //链表的插入
        {
            q=G.vertices[i].firstarc;//获取头结点的表头指针
            for(n=0;n<G.arcnum;n++,q=q->nextarc)//将q指针移动至链表的尾巴处
            {
                if(!q->nextarc)
                    break;
            }
            p=(ArcNode *)new ArcNode;
            q->nextarc=p; //将该边（弧）加入到链表中
            q=q->nextarc;
        }
        q->adjvex=j;  //记录弧头的索引
        q->nextarc=NULL;
    }
    cout<<"图构建成功！";
}
*/

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
                //tempArc=tempArc->nextarc;
                //cout<<"执行了while  ";
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
/*
void CreateALGraph(VNode vnode,ArcNode arcnode){
    int vexnum;
    int data;
    int arcnum;
    int adjvex;
    int weight;

    int i;
    int j;

    cout<<"接下来创建邻接表"<<endl;
    cout<<"请输入顶点总数:"<<endl;
    cin>>vexnum;
    if (vexnum<=0) return 0;
    for(i=1;i<=vexnum;i++){
        cout<<"请输入第"<<i<<"个顶点的信息："<<endl;
        cin>>data;
        vnode.data=data;
        cout<<"输入该顶点弧的数量:"<<endl;
        cin>>arcnum;
        if(arcnum>0){
            for(j=1;j<=arcnum;j++){
                cout<<"输入第"<<j<<"条弧所指向的顶点的位置:"<<endl;
                cin>>adjvex;
                arcnode.adjvex=adjvex;
                cout<<"输入第"<<j<<"条弧的权值:"<<endl;
                cin>>weight;
                arcnode.weight=weight;
                vnode.

            }
        }
    }

}*/

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
    //int ve[G.vexnum];
    int i;
    int count;
    ArcNode *p;
    int k;
    //初始化数组
    for(i=0;i<G.vexnum;i++){
        indegree[i]=0;
    }
    FindInDegree(G,indegree);
    //cout<<"度数是"<<indegree[0]<<' '<<indegree[1]<<endl;
    //stack<int> s;
    cout<<"G.vexnum是"<<G.vexnum<<endl;
    for(i=0; i<G.vexnum; ++i){
        if(!indegree[i])    s.push(i);//找到入度为0的位置，入栈
    }
    count=0;

    //初始化各顶点事件的最早发生时间ve
    for(i=0;i<G.vexnum;++i){
        ve[i]=0;
    }

    while(!s.empty())
    {
        i = s.top();//保存栈顶元素
        s.pop();    //删除栈顶元素
        t.push(i);  //入t栈
        //cout << G.vertices[i].data<<" ";//输出拓扑序列
        ++count;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc)  //p是一条边
        {
            k=(p->adjvex)-1;
            if(!(--indegree[k]))    s.push(k);
            if(ve[i]+p->weight>ve[k])   ve[k]=ve[i]+p->weight;
            cout<<"ve["<<k<<"]是"<<ve[k]<<endl;
        }
    }
    //cout<<"执行了一次拓扑排序"<<endl;
    if(count<G.vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }

}



