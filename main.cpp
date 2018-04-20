#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("date.in");
class nod
{
    public:
    nod *adr;
    char inf;
};

class stiva
{
nod *p;
public:

stiva(stiva&);
stiva();
void push(char x);
char pop();
char top();
void afis();
friend class nod;
friend ostream &operator << (ostream &output, stiva &s);
friend istream &operator >> (istream &input, stiva &s);
stiva operator - (stiva s);
~stiva();
bool operator == (stiva &s);
bool operator != (stiva &s);
};
stiva::stiva()
{
    p=NULL;

}
stiva::~stiva()
{

}
bool stiva::operator == (stiva &s)
{

    nod *q,*q1;
    q=p;
    q1=s.p;
    while(q&&q1)
    {
        if(q->inf!=q1->inf)
            return 0;
        q=q->adr;
        q1=q1->adr;
    }
    return 1;
}

bool stiva::operator != (stiva &s)
{

    bool ok=0;
    nod *q,*q1;
    q=p;
    q1=s.p;
    while(q&&q1)
    {
        if(q->inf!=q1->inf)
            ok=1;
        q=q->adr;
        q1=q1->adr;
    }
    return ok;
}
/*stiva operator - (stiva s)
{
    stiva newS;
    while(s.pop()==this.pop())
        {
        s.pop();
        pop();



        }

    newS.p=new nod;
    newS.p->inf=p->inf;
    nod *q=p;
    nod *r=newS.p;
    while(p->adr)
    {
        nod *q=new nod;
        q->inf=p->adr->inf;
        p=p->adr;
        newS.r->adr=q;
        r=r->adr;

    }
    return newS;
}
*/




ostream &operator << (ostream &output, stiva &s)
{
    while(s.p)
    {
    output<<s.top()<<" ";
    s.pop();
     }
     return output;
}
istream &operator >> (istream &input, stiva &s)
{
    int n;
    char x;
    input>>n;
    for(int i=1;i<=n;i++)
        {
            input>>x;
            s.push(x);

        }
         return input;

}

void stiva::push(char x)
{
    nod *q;
    if(p==NULL)
    {
        p=new nod;
        p->inf=x;
        p->adr=NULL;
    }
    else
    {
        q=new nod;
        q->inf=x;
        q->adr=p;
        p=q;

    }
}
char stiva::pop()
{
    char x;
    nod *r;
    r=p;
    x=r->inf;
    p=p->adr;
    delete r;
    return x;
}
char stiva::top()
{
   return p->inf;
}
void stiva::afis()
{
    nod *q;
    q=p;
    while(q)
    {
        cout<<q->inf<<" ";
        q=q->adr;
    }
}

stiva::stiva(stiva& copie)
{
     nod*r=copie.p;
     p=NULL;
    while(r)
      {
      push(r->inf);
      r=r->adr;
      }



}
int main()
{
    stiva s1,s3;
    stiva s2(s1);
    fin>>s1;
    cin>>s3;
    if(s3==s1)
        cout<<"da";
    if(s3!=s1)
        cout<<"nu";
    return 0;
}
