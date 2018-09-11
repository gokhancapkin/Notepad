#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<string.h>

#define ARROW_UP    72
#define ARROW_LEFT  75
#define ARROW_RIGHT 77
#define ARROW_DOWN  80
#define ENTER 		13
#define BACKSPACE   8
#define WINDOWS 1

void dosya_ac();
void box(int ,int ,int ,int );
unsigned char getArrow();
void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
main()
{
	unsigned char arrow,karakter; 
	system("COLOR F0");
	int satir=0,sayfa=0,sutun=0,j,k,t;
	int satirx=0,sayfax=0,sutunx=0;
	int sayac=8;	
	char metin [80][52][100];
	char yazilacak;
	int okunan[80][5][100];
	char metin2[80][52][100];
	int x=0,c=0,v=0;
	for(sayfa=0;sayfa<100;sayfa++){	
	satirx=0;
	box(1,0+sayac*sayfa,82,7+sayac*sayfa);gotoxy(2,1+sayac*sayfa);
	printf("SAYFA %d\n",sayfa+1);	
	for(satir=0;satir<5;satir++){
	sutunx=0;
	for(sutun=0;sutun<80;sutun++)
	{
	gotoxy(sutun+2,satir+2+sayac*sayfa);
	karakter=getche();
	if(karakter==43)
	{
		clrscr();
		
		for(t=0;t<100;t++){
		for(k=0;k<5;k++){
		for(j=0;j<80;j++){
		metin[j][k][t]=NULL;

				}
				}
			}
		
		box(1,0,82,7);gotoxy(2,1);
		printf("SAYFA %d\n",1);	gotoxy(2,2);
		}	
	if( karakter==39)
	{
		FILE *fp=fopen("notepad.txt","a+");
	

	for(sayfa=0;sayfa<100;sayfa++){	
	box(1,0+sayac*sayfa,82,7+sayac*sayfa);gotoxy(2,1+sayac*sayfa);
	printf("SAYFA %d\n",sayfa+1);
	for(satir=0;satir<5;satir++){
	for(sutun=0;sutun<80;sutun++){	
	gotoxy(sutun+2,satir+2+sayac*sayfa);
	okunan[sutun][satir][sayfa]=fgetc(fp);
	metin[sutun][satir][sayfa]=okunan[sutun][satir][sayfa];	
		
	printf("%c",metin[sutun][satir][sayfa]);
	
	}
	}
	if(feof(fp)) break;sayac++;
	}
	fclose(fp);
}

	if(karakter==ENTER){
		box(1,0+sayac*sayfa,82,7+sayac*sayfa);gotoxy(2,1+sayac*sayfa);
		printf("SAYFA %d\n",sayfa+1);
		printf("\n");satir++;sutun--;
		if(satir==5){sayfa++; satir=0;sutun=0;
		}

}
	if(karakter==BACKSPACE)
	{

				sutun=sutun-1;
	     		for(t=sayfa;t<100;t++){
		 		for(k=satir;k<5;k++){
				for(j=sutun+1;j<79;j++){
				gotoxy(satir-1,sutun+2);
				metin2[x][c][v]=metin[j][k][t];
				gotoxy(satir,sutun+2);
				printf("%c",metin2[x][c][v]);
				x++;
				}
				if(metin2[x][c][v]==NULL)
				break;
				c++;
				}
				v++;
				if(metin2[x][c][v]==NULL)
				break;
	}
	}
	if(karakter==224) 
	{
		karakter=getche();
		j=satir;k=sutun;t=sayfa;
	
		        switch(karakter) {
                case ARROW_UP:{putchar(255);
                
                if(satir>0)
				{
						
                    satir=satir-1;sutun=sutun-1;
                     }else 	if (sayfa>0 && satir ==0) 
					 {satir=4; sayfa--; sutun--;}
					 else sutun=sutun-1;}break;
                case ARROW_LEFT:
                	putchar(255);
					
                if(sutun==0 && satir>0){	
					sutun=79;
                    	satir--;break;	} 	
					
						if(sutun>0)
                    sutun=sutun-2;break;
					
                    
                    
				
                    break;
                case ARROW_RIGHT:putchar(255);
                	if(sutun==79 && satir<4){	
					sutun=0;satir++;break;	}	
				else if (satir==4 && sutun ==79) 
					 {sutun=0;satir=0; sayfa++;break;}
                else if (sutun!=79 && metin[sutun+1][satir][sayfa]==NULL){sutun=sutun-1;break;}
				 break;
                case ARROW_DOWN:{putchar(255);
          			if (metin[sutun][satir+1][sayfa]!=NULL) {
					  
          		
                    satir++;sutun=sutun-1;break;}
                   	if (sayfa<100 && satir ==4) 
					 {satir=0; sayfa++; }
					 sutun--;
                }break;
                case ENTER:
                	printf("\n");
                    break;
					default:printf("Tuþ Algýlanamadý!!");
           	}
           		
                
           		 gotoxy(2,2);
				for(t=0;t<100;t++){
				for(k=0;k<5;k++){
				for(j=0;j<80;j++){
				gotoxy(j+2,k+2+sayac*t);
				yazilacak=metin[j][k][t];

				if(yazilacak==NULL)
				break;
				printf("%c",metin[j][k][t]);
				}
				if(yazilacak==NULL)
				break;
    
				printf("\n");
				}
				if(yazilacak==NULL)
				break;
				printf("\n");
	}

			gotoxy(sutun,satir);
		}
            	
            else if(karakter!=39 && karakter !=33 && karakter!=43){
	metin[sutun][satir][sayfa]=karakter;
		sutunx++;
	}
	if(karakter==33){printf("\b");putchar(255);
	break;}

}
if(karakter==33)
	break;
      printf("\n");
      satirx++;
}
	if(karakter==33)
	break;
	sayfax++;
}
	if(karakter==33){
    FILE *fpt=fopen("notepad.txt","w");
	for(sayfa=0;sayfa<100;sayfa++){
	for(satir=0;satir<5;satir++){
	for(sutun=0;sutun<80;sutun++){
	if(metin[sutun][satir][sayfa]==NULL)
	continue;
	fprintf(fpt,"%c",metin[sutun][satir][sayfa]);
	}
	if(yazilacak==NULL)
	continue;
    
	fputs("\n",fpt);
	}
	if(yazilacak==NULL)
	continue;
	fputs("\n",fpt);
	}
	fclose(fpt);
}
}
void box(int x1,int y1,int x2,int y2)
{
   int i;
   for(i=x1;i<=x2;i++)
     {
      gotoxy(i,y1);
      printf("%c",196);
      gotoxy(i,y2);
      printf("%c",196);
     }
   for(i=y1;i<=y2;i++)
     {
      gotoxy(x1,i);
      printf("%c",179);
      gotoxy(x2,i);
      printf("%c",179);
     }
      gotoxy(x1,y1);
      printf("%c",218);
      gotoxy(x1,y2);
      printf("%c",192);
      gotoxy(x2,y1);
      printf("%c",191);
      gotoxy(x2,y2);
      printf("%c",217);
}


