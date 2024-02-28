#include <iostream>
#include <list>
#include<queue>
using namespace std;
queue<int>q;


 struct tree
{
 int num ;
 int h,p;
 list<int>li;
} ;


int LCA(tree*t,int T1, int T2)
{
 while(T1!=T2)
 {

 if(t[T1-1].h > t[T2-1].h )
 {T1 = t[T1-1].p;}
 else if(t[T1-1].h < t[T2-1].h)
 {T2=t[T2-1].p;}
 else
 {
 T1=t[T1-1].p;
 T2=t[T2-1].p;
 }
 }
 return T1; //return T2
}



int distance(tree*t,int a,int b)
{
if(a==b)return 0;
int x=LCA(t,a,b);
if(x == a)
   return (t[b-1].h - t[a-1].h);

else if(x==b)
   return (t[a-1].h -t[b-1].h);

else
{
   return (t[a-1].h-t[x-1].h) + (t[b-1].h-t[x-1].h);
}
}

int main()
{
    int n,a,b,s;
    cout << "NUMBER OF NODE : " ;
    cin>>n ;
    tree*t=new tree[n];
    t[0].h=0;t[0].p=0;

for(int i=0;i<n ;i++)//INSERT
{
    t[i].num=i+1;

    cout<<"NODE "<< i+1<<" :";
    cin>>a>>b;
    t[i].li.push_back(a);
    t[i].li.push_back(b);
    t[a-1].p=i+1;
    t[b-1].p=i+1;
    s=t[i].p;
    if(i!=0&&s!=0)
    t[i].h=(t[s-1].h)+1;
}


for(int i=0;i<n ;i++)//PRINT
{
    cout<<"NUMBER\t"<<t[i].num<<"\t";
    cout<<"LEFT\t"<<t[i].li.front()<<"\t";
    cout<<"RIGHT\t"<<t[i].li.back()<<"\t";
    cout<<"PERENTS\t"<<t[i].p<<"\t";
    cout<<"HEIGHT\t"<<t[i].h<<"\t";
    cout<<"\n";

}
cout<<"NUMBER OF QUERIES:\t";
cin>>s;

for(int i=0;i<s;i++)
{
        cout<<" FIRST  NODE :";cin>>a;
        cout<<" SECOND NODE :";cin>>b;
        cout<<"\n";
        q.push(a);q.push(b);
}


for(int i=0;i<s;i++)
{
a=q.front();q.pop();
b=q.front();q.pop();
if(a==b)
   {cout<<"THE NODE IN THE MIDDLE : "<<b<<endl;continue;}

if(t[a-1].p==t[b-1].p)//PARENTS
   {cout<<"THE NODE IN THE MIDDLE :"<<t[a-1].p<<endl;}

else
{
int x= distance(t,a,b);
cout<<"Distance :"<<x<<endl;
int d=x/2; int z;

if(t[a-1].h>=t[b-1].h)
       z=a;

else if(t[b-1].h>t[a-1].h)
      z=b;

for(int i=0;i<d;i++)
   {z=t[z-1].p;}
   cout<<"THE NODE IN THE MIDDLE :"<<z<<endl;
}
}

}
