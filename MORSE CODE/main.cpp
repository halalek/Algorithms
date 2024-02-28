#include <iostream>
#include <string>

using namespace std;
const int Size = 2;
struct trie
{char ch;
    bool x;
    trie *num[Size];
};


trie *TRIE()
    {
      trie *p=new trie;
      p->ch=0;
        p->x=false;
       for(int i=0;i<Size;i++)
        p->num[i]= NULL;
    return p;
    }


void scan(trie *head,char c,string s)
 {
 trie *cur=head ;cout<<c;
for(int i=0;i<s.length();i++)
{
int number=s[i]-48;cout<<number<<"\n";
 if(cur->num[number]==NULL)
   {
      cur->num[number]=TRIE();
      cur->ch=c;
   }
 cur=cur->num[number];
}
cur->x=true;}


char Search(trie*head,string s)
{
     trie*cur= head;

    for(int i=0; i<(s.length()-1);i++)
    {
        int number = s[i]-48;
        if (cur->num[number]==NULL)
            {return 'z';}//NOT FOUND
        cur= cur->num[number];
    }

    if(cur!= NULL && cur->x);//tru
    return cur->ch;

}


void print(char s[],int w)
{
   for(int i=0;i<w;i++)
        cout<<s[i];
}

int main()
{
trie *head=TRIE();
int N;
  string num,num1;char c,c1;int sum=0;
cout<<"ENTER N\n";
cin>>N;
for(int i=0;i<N;i++)
{cout<<"ENTER LETTER AND STRING NUMBER:\n";
cin>>c>>num;
if(sum==0||(c1!=c&&num1!=num))
{
scan(head,c,num);
c1=c;
num1=num;
sum++;
}
else
{
  if(c1==c)  {cout<<"ERORR :LETTER HAS 2 VALUE\n";
              cout<<"PLEASE ENTER THE LETTER\n";}
else if(num1==num)
              {cout<<"ERORR :NUMBER STRING HAS 2 VALUE \n";
              cout<<"PLEASE ENTER THE NUMBER STRING \n";}

    i--;
}}
cout<<"ENTER LENGTH OF SENTENSE:\n";
int w;string d;
cin>>w;
char s[w];
for(int i=0;i<w;i++)
{cout<<"ENTER STRING NUMBER:\n";
cin>>d;
s[i]=Search(head,d);
if(s[i]=='z')
{cout<<"Not FOUND PLEASE ENTER AGAIN"<<"\n";
i--;}
}
print(s,w);
    return 0;
}






















/*
// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
     TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}*/
