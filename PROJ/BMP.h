#define GL_BGR  0x80E0
GLuint load(const char *s)
{
unsigned char *data;
FILE *f=fopen(s,"rb");
if(!f)
printf("sorry");
unsigned char header[54];
if(fread(header,1,54,f)!=54)
printf("corrupted");
printf("%c %d\n",header[0],header[0x16]);
//unsigned int dataPos    = *(int*)&(header[0x0A]);
unsigned int imageSize  = *(int*)&(header[0x22]);
unsigned int width      = *(int*)&(header[0x12]);
unsigned int height     = *(int*)&(header[0x16]);
printf("%u",imageSize);
data=new unsigned char[imageSize];
fread(data,1,imageSize,f);
fclose(f);
GLuint textureID;
glGenTextures(1,&textureID);
glBindTexture(GL_TEXTURE_2D,textureID);
glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

delete data;
return textureID;
}
