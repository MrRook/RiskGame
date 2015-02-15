#include<iostream>
#include<fstream>
using namespace std;
struct s{int a,b,c;
             int assign;
           };
int main()
{
ofstream inn("screenout.txt");
ifstream in("input.txt");
ifstream final("final.bin");//,ios::binary|ios::out);
int r,p,q;
s k[42],y;
int i=0;
while(in>>r)
{
 k[i].a=r ;
 in>>k[i].b;
 in>>k[i].c;
 //cout<<k[i].a<<" "<<k[i].b<<" "<<k[i].c<<" \n";
 i++;
}

while(final>>r)
{
if(r!=0)
inn<<k[r-1].a<<" "<<k[r-1].b<<" "<<k[r-1].c<<endl;
else
inn<<255<<" "<<255<< " "<<255<<endl;
}
inn.close();
in.close();
final.close();
}
