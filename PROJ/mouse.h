#include<fstream>
using namespace std;
void mousebuf(unsigned char mou[][600],char a[])
{
ifstream moe(a,ios::binary|ios::in);
int r;
for(int i=0;i<800;i++)
  for(int j=0;j<600;++j)
  {
moe>>r;
mou[i][j]=r;
}
moe.close();
}
