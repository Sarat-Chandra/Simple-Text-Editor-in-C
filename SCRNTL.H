#include<stdio.h>
#include<dos.h>
#define RIGHT  0x01
#define LEFT   0x02
#define CTRL   0x04
#define ALT    0x08
extern int LAST;
extern char buffer[200][80];
getkey(int *shift,int *control,int *up,int *left,int *ins,int *del)
{


   int key, modifiers;
   int key1;
   *shift = 0;
   *control =0;
   *up = 0;
   *left = 0;
   //*ins = 0;
   *del = 0;






   while (bioskey(1) == 0);


   key = bioskey(0);


   modifiers = bioskey(2);
   if (modifiers)
   {
     // printf("[");
     if (modifiers & RIGHT || (modifiers & LEFT))
	   *shift = 1;
      if (modifiers & CTRL)
	  *control = 1;

   }
   /* print out the character read  */


      if ( (key & 0xFF) ==0)
   {
       key1  = key >> 8;
       switch(key1)
       {
	 case 72 :
	      *up = 1;
	      return 0;
	 case 80  :
	      *up = -1;
	      return 0;
	 case 75 :
	      *left = 1;
	      return 0;
	 case 77 :
	      *left = -1;
	      return 0;
	 case 82 :
	    if((*ins)==1)
		*ins =0;
	     else
	      *ins =1;
	      return 0;  
	 case 83:
	      *del = 1;
	      return 0;
       default : break;
	 }

    }

      return (key&255);


}
/*refreshline(int line)
{
 int x,y;
 gotoxy(1,wherey());
 x = wherex();
 y = wherey();
 printf("%s",buffer[line]);
 gotoxy(x,y);
 }      */

UpdateScreen(int top)
{
  char s[80];

  int i=top;
  int j =0 ;
  int tempX = wherex();
  int tempY = wherey();
  clrscr();
  gotoxy(1,1);
  for(;i<top+24&&i<LAST-1;i++)
     printf("%s\n",buffer[i]);


    while(buffer[i][j]!='\n'&&/*buffer[i][j]!=EOF&&*/j!=0)
       {
       //	 s[j] = buffer[i][j];
       //	 j++;
       putchar(buffer[i][j++]);
	 }
    //	 s[j]='\0';
     //	 printf("%s",s);
	 gotoxy(tempX,tempY);

	 return wherey();
	 }

displayfile()
{
  int  i = 0;
  for(i=0;i<10;i++)
     printf("%s\n",buffer[i]);
     return 0;
}

