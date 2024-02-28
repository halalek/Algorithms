#include <iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int u, v, k;
bool st = 0, en = 0;
typedef struct node1{
    int i,j,color;
}node1;
typedef struct node2{
    vector<node1> v;
}node2;
node1 start;
node1 End;
node2*nod2;

void EnterToArray(int a,int i ,int j)
{
    if(a<=k && a>0)
    {
    if(nod2==NULL)
         nod2=new node2[k];
    node1 n;
    n.i=i;
    n.j=j;
    n.color=a;
    nod2[a-1].v.push_back(n);
    }
}
int** EnterGraph()
{
    int** graph = new int* [u];
    for (int i = 0; i < u; i++)
    {
        graph[i] = new int[v];
    }
    cout << "\n\nENTER THE MAP WITH THE BUILDING COLORS\n" << "PAYING ATTENTION TO THE COLORING OF THE BUILDING YOU ARE IN : IN THE COLOR (1)\n"
        << "AND THE BUILDING YOU WANT TO GO TO : IN THE COLOR (" << k << ") \n\n";

    for (int i = 0; i < u; i++)
    {
        cout << "ENTER ROW (" << i + 1 << ")\n";
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
            EnterToArray(graph[i][j],i,j);
            if (graph[i][j] > k || graph[i][j] < 0)
                return NULL;
            if (graph[i][j] == 1 && st == 0)
                {
                    st = 1;
                    start.i=i;
                    start.j=j;
                    start.color=1;
                }
            else if (graph[i][j] == 1 && st == 1)
                return NULL;
            else if (graph[i][j] == k && en == 0)
                {
                    en = 1;
                    End.i=i;
                    End.j=j;
                    End.color=k;
                }
            else if (graph[i][j] == k && en == 1)
                return NULL;
        }
    }
    return graph;
}
void PrintMap(int** graph)
{
    cout << "YOUR MAP IS :\n\n";
    for (int i=0; i < u; i++)
    {
        for (int j=0; j < v; j++)
            cout << graph[i][j]<<"\t";
        cout << endl << endl;
    }
}

 queue <node1> q1;
void neighbors(int ** graph,node1 nod)
{
    int ii=nod.i;
    int jj=nod.j;
        /* for(int i=0;i<nod2[nod.color-1].v.size();i++)
            {
               // cout<<"hey";
                       q1.push(nod2[nod.color-1].v[i]);
            } */
      nod.i=ii-1;
    if(graph[nod.i][nod.j]!=0 && nod.i>=0)
    {
    nod.color=graph[nod.i][nod.j];
    q1.push(nod);
    }
     nod.i=ii+1;
     if(graph[nod.i][nod.j]!=0 && nod.i<u)
     {
     nod.color=graph[nod.i][nod.j];
     q1.push(nod);
     }
     nod.i=ii;
     nod.j=jj-1;
     if(graph[nod.i][nod.j]!=0 && nod.j>=0){
     nod.color=graph[nod.i][nod.j];
     q1.push(nod);
     }
     nod.i=ii;
     nod.j=jj+1;
     if(graph[nod.i][nod.j]!=0 && nod.j<v){
     nod.color=graph[nod.i][nod.j];
     q1.push(nod);
     }
      nod.i=ii;
      nod.j=jj;
}

/*int ** distance(int **graph)
{
    int** dist = new int* [u];
    for (int i = 0; i < u; i++)
    {
        dist[i] = new int[v];
    }
     for (int i=0; i < u; i++)
    {
        for (int j=0; j < v; j++)
            dist[i][j]=1000000000000;
    }
    queue <node1> q;
    q.push(start);
    dist[start.i][start.j]=0;
    while(!q.empty())
    {
        node1 nod3=q.front();
        q.pop();
        neighbors(graph,nod3);
        while(!q1.empty())
              {
                node1 nod4=q1.front();
                q.pop();
                if((dist[nod4.i][nod4.j]+1)<(dist[nod3.i][nod3.j]))
                {
                  dist[nod4.i][nod4.j]=dist[nod3.i][nod3.j]+1;
                  q.push(nod4);
                }
                q1.pop();
              }
              while(!q1.empty())
              {
                  q1.pop();
              }
    }
    return dist;
}
*/
int main()
{
    cout << "ENTER NUMBER OF ROWS\n";
    cin >> u;
    cout << "ENTER NUMBER OF COLUMNS\n";
    cin >> v;
    cout << "ENTER NUMBER OF COLOR\n";
    cin >> k;
    int** graph = EnterGraph();
    if (graph == NULL)
        {
            cout<<"\n***** ERROR IN YOUR MAP *****\n";
            return 0;
        }
     system("pause");
     system("cls");
     PrintMap(graph);
     cout<<"\n\n****************************************\n\n";
     cout<<"queue neighbors start\n";
     neighbors(graph,start);
      while(!q1.empty())
      {
          cout<< q1.front().color <<"\t";
          q1.pop();
      }
      cout<<endl<<"queue neighbors end\n";
     neighbors(graph,End);
      while(!q1.empty())
      {
          cout<< q1.front().color <<"\t";
          q1.pop();
      }
    /* cout<<"array color\n"; //ARRAY COLOR
     for(int j=0;j<k;j++)
    {
        for(int i=0;i<nod2[j].v.size();i++)
     {
         cout<<nod2[j].v[i].color<<"\t";
     }
     cout<<endl;
    }*/
     //int**dist=distance(graph);
     //cout<<"THE SHORTEST PATH FROM WHERE YOU ARE TO YOUR DESTINATION IS :\t"<<dist[End.i][End.j]<<endl;
    return 0;
}
