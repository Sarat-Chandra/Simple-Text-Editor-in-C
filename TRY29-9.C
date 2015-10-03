#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"SCRNTL.h"
#include"FILE.h"
#include"DIALOG.h"
#include"BUFFER.h"
char buffer[200][80];
char tempBuffer[200];
int top;
int FIRST,LAST;
int value;
int x,y;
int offset = 0;
int startX;
int startY;
int tempX;
int tempY;
int prevX;
int prevY;
int main()
{



  FILE *source,*destination;
  int i = 0;
  int z =1;
  int key;
  int j=1;
  int k;
  int shift,control,up,left,ins=0,del;
  int prevShift=0;
  textbackground(0); // source = fopen("source.txt","r");
  clrscr();
  //while(fgets(buffer[i++],80,source));
    //	LAST  =   i;
    formatbuffer();
      loadbuffer();
	startX = startY = -1;
	gotoxy(1,1);
	i=0;
  j=UpdateScreen(top);

    while(1)
  {

    key = getkey(&shift,&control,&up,&left,&ins,&del);
    if(up == -1&&shift ==0)
      {
	if(wherey()==25&&j<LAST)
	  {
	    top++;

	    UpdateScreen(top);
	    j++;

	    gotoxy(wherex(),25);
	  }
	else if(wherey()<25&&j<LAST)
	       {
		gotoxy(wherex(),wherey()+1);
		j++;
		}
       //	  else
	 //    printf("%d",top);

      }
     else if(up == 1&&shift ==0)
	  {

	   if(wherey()==1&&j>1)
	   {
	   top--;
	   UpdateScreen(top);
	   j--;

	   gotoxy(wherex(),1);

	    }

	    else if(wherey()>1&&j>1)
	       {

	     gotoxy(wherex(),wherey()-1);
	     j--;
	       }
	 //   else
	   //   printf("%d",top);
		   }
      else if(left ==1&&wherex()>1&&shift==0)
	     {
	     gotoxy(wherex()-1,wherey()),x=wherex();
	     prevShift = 0;
	     }
      else if(left ==-1&&wherex()<80&&shift==0)
	   {
	    gotoxy(wherex()+1,wherey()),x=wherex();
	    prevShift = 0;
	    }
      else if(ins == 1)
	    {
	       if(isascii(key)&&key!=0)
		 {

		   putchar(key);
		   if(key!='\r')
		    {
		    i=0;
		    while(buffer[top+wherey()-1][i++]!='\0');
		    if((i-1)<=wherex()-1)
		     {
		      for(k=i-1;k<=wherex()-1;k++)
			  buffer[top+wherey()-1][k]=' ';
		      buffer[top+wherey()-1][wherex()-2] = key;
		      buffer[top+wherey()-1][wherex()] = '\0';
		     // refreshline(top+wherey()-1);
		     }

		     else
			       buffer[top+wherey()-1][wherex()-2] = key;

		    }
		    else if(key==8)  //backspace
			   {
			  // backspace();
			   }


		    else  {
			   //
			  // clrscr();
			  // printf(" j= %d%s\n",j,buffer[j-1]);
			   for(k=LAST;k>=j+1;k--)
			     {
			      /*i=0;
			      for(i=0;i<79;i++)
				  buffer[k][i]='!';
				  buffer[k][i]='\0';
				  i=0;
				  while(buffer[k-1][i]!='\0')
					buffer[k][i]=buffer[k-1][i++];
					buffer[k][i]='\0'; */
				     strcpy(buffer[k],buffer[k-1]);
					}
			 /*  for(k=0;k<79;k++)
			      buffer[top+wherey()][k]='!';
			      buffer[top+wherey()][k]='\0'; */
			   k=x-1;
			   i=0;
			   while(buffer[j-1][k]!='\0')
				buffer[j][i++] = buffer[j-1][k++];
				buffer[j][i]='\0';
				LAST++;
				buffer[j-1][x-1] = '\0';

				UpdateScreen(top);
					       //	   printf("%d   %d",x,y);

			   j++;
			   gotoxy(1,wherey()+1);
			  }

	      //	 else if(del==1)
		//       delchar();
		   }

		}
     else if(shift==1)
	 {

	    if(left==-1)
	      {

		    if(prevShift==0&&offset == 0)
		      {
		       startX = wherex();
		       prevX  = wherex();
		       offset = 0;
		       startY = wherey();
		       prevY = wherey();
		       prevShift = 1;
		      }
		    tempX = wherex();

		 if(prevShift==1)
		   {
		  //gotoxy(wherex(),wherey());
		  textbackground(10);
		  cprintf("%c",buffer[j-1][wherex()-1]);

		  offset+=1;
		  prevX = wherex();
		   }
		  else if(prevShift ==0)
		      {   //deselect



			   tempX = wherex();
			   textbackground(0);
			   gotoxy(startX,wherey());
			   for(i=startX;i<=startX+offset;i++)
			    {

			      cprintf("%c",buffer[j-1][i-1]);
			     }
			  textbackground(10);
			  startX = tempX;
			  startY = wherey();
			  gotoxy(startX,startY);
			  textbackground(10);
			 cprintf("%c",buffer[j-1][wherex()-1]);
			 prevShift = 1;
			offset=0;
			}



	     }
	     }
     else               //assumed for close dialog
       {

	 WriteFile("rat.txt");
	// value = dialog(SAVE);
      /*	 if(value == a0)   //CANCEL
	    UpdateScreen();
	 else if(value ==1)       //SAVE
	    {
	      WriteFile(OldName);

	     Update(Screen);

	    }
	  else
	       {
	       WriteFile(NewName);
	       UpdateScreen();
	       }     */
	 fcloseall();
	 break;
	}
  }
  //clrscr();
 // displayfile();
  getch();
  return 0;
  }








