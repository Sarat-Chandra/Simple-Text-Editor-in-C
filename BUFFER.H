extern char buffer[200][80];
extern int LAST;
loadbuffer()
{
  FILE * source;
  int i,j;
  char c;
  i = j = 0;
  source = fopen("source.txt","r");
  while((c=getc(source))!=EOF)
    {
       if(c=='\n')
	{
	 buffer[i][j]='\0';
	 i++,j=0;
	 }
       else
	 buffer[i][j++]=c;
     }
     LAST = i;


  }

 formatbuffer()
 {
   int i,j;
   for(i=0;i<200;i++)
     {
      for(j=0;j<79;j++)
	 buffer[i][j] ='!';
	 buffer[i][j]='\0';
     }
     return 0;
     }