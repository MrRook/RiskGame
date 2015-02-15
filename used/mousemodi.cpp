#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
ifstream in("final.bin",ios::binary|ios::in);
ofstream o("temp.bin",ios::binary|ios::out);
int p;
for(int i=0;i<800;i++)
for(int j=0;j<600;j++)
{
in>>p;
if(((3*i+2*j-598)>0)&&j>=265&&j<=292&&i<=88&&i>=6)
o<<43<<" ";
else if(i>=25&&i<=88&&j<=260&&j>=190)
o<<44<<" ";
else if(((3*i+2*j-588)<0)&&j>=190&&j<=292&&i<=22&&i>=6)
o<<45<<" ";
else
o<<p<<" ";
}
in.close();
o.close();

}
