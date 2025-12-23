#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <iostream.h>


//Codigo salva-vidas
/*      b=0;
      d=((-jog[0][(mapa[x][y]-1)].alca)-1);
      for(a=((y-jog[0][(mapa[x][y]-1)].alca));a<=(y+jog[0][(mapa[x][y])].alca);a++)
      {
       d++;
       if (d<=0)
       b++;
       else
       b--;
	for(c=x-b+1;c<x+b;c++)
	{
	 if ((c>-1)&&(a>-1)&&(c<7)&&(a<7))
	 {
	  mapa2[c][a]=1;
	  setfillstyle(1,2);
	  bar ((c*64)+2,(a*64)+2,((c+1)*64)-2,((a+1)*64)-2);
	 }
	}
       }*/


class tropa
{
 private:
 public:
 short posx, posy, alca, atac, defe, desl, maxhp, hp;
 char clas;

 void setclas(char cla)
 {
  if (cla=='g')
  {
   clas=cla;
   atac=2;
   defe=4;
   alca=1;
   desl=2;
   maxhp=40;
   hp=maxhp;
  }

  if (cla=='a')
  {
   clas=cla;
   atac=3;
   defe=2;
   alca=4;
   desl=3;
   maxhp=20;
   hp=maxhp;
  }

  if (cla=='m')
  {
   clas=cla;
   atac=5;
   defe=1;
   alca=3;
   desl=2;
   maxhp=20;
   hp=maxhp;
  }
 }
};


void desmap(void)
{
 short x,y;
 for (x=0;x<448;x+=64)
 for (y=0;y<448;y+=64)
 {
 setfillstyle(1,8);
 bar (x+1,y+1,x+64,y+64);
 setcolor(15);
 line (x+1,y+1,x+64,y+1);
 line (x+1,y+1,x+1,y+64);
 line (x+1,y+64,x+64,y+64);
 line (x+64,y+1,x+64,y+64);
 }
}


void desgue(int x, int y, int z,tropa jog[2][5], short k)
{
//provisorio at‚ ter um desenho
char hit[3];
setfillstyle(1,3);
bar((x*64)+6,(y*64)+6,(x*64)+58,(y*64)+58);
setcolor(9);
outtextxy((x*64)+10,(y*64)+10,"G");
if (z==1)
itoa(jog[z-1][k].hp,hit,10);
else
itoa(jog[z-1][k].hp,hit,10);
outtextxy((x*64)+38,(y*64)+10,hit);
if (z==1)
outtextxy((x*64)+28,(y*64)+28,"1");
else
outtextxy((x*64)+28,(y*64)+28,"2");
}


void desarc(int x, int y, int z, tropa jog[2][5], short k)
{
//provisorio at‚ ter um desenho
char hit[3];
setfillstyle(1,3);
bar((x*64)+6,(y*64)+6,(x*64)+58,(y*64)+58);
setcolor(9);
outtextxy((x*64)+10,(y*64)+10,"A");
if (z==1)
itoa(jog[z-1][k].hp,hit,10);
else
itoa(jog[z-1][k].hp,hit,10);
outtextxy((x*64)+38,(y*64)+10,hit);
if (z==1)
outtextxy((x*64)+28,(y*64)+28,"1");
else
outtextxy((x*64)+28,(y*64)+28,"2");
}


void desmag(int x, int y, int z, tropa jog[2][5], short k)
{
//provisorio at‚ ter um desenho
char hit[3];
setfillstyle(1,3);
bar((x*64)+6,(y*64)+6,(x*64)+58,(y*64)+58);
setcolor(9);
outtextxy((x*64)+10,(y*64)+10,"M");
if (z==1)
itoa(jog[z-1][k].hp,hit,10);
else
itoa(jog[z-1][k].hp,hit,10);
outtextxy((x*64)+38,(y*64)+10,hit);
if (z==1)
outtextxy((x*64)+28,(y*64)+28,"1");
else
outtextxy((x*64)+28,(y*64)+28,"2");
}


void desperso(short mapa[7][7], tropa jog[2][5])
{
 short x, y, z;
 for (x=0;x<7;x++)
 for (y=0;y<7;y++)
 {
  if(mapa[x][y]!=0)
  {
   if(mapa[x][y]<6)
   {
    z=mapa[x][y]-1;
    if(jog[0][z].clas=='a')
    desarc(x,y,1,jog,z);
    else if(jog[0][z].clas=='g')
    desgue(x,y,1,jog,z);
    else
    desmag(x,y,1,jog,z);
   }

   else
   {
    z=mapa[x][y]-6;
    if(jog[1][z].clas=='a')
    desarc(x,y,2,jog,z);
    else if(jog[1][z].clas=='g')
    desgue(x,y,2,jog,z);
    else
    desmag(x,y,2,jog,z);
   }
  }
 }
}


void deftro(tropa jog[2][5],char nome1[10],char nome2[10])
{
 int x;
 setcolor(11);
 outtextxy(450,5,nome1);
 outtextxy(450,70,nome2);
 setcolor(7);
 for (x=0;x<5;x++)
 {
  if (jog[0][x].clas=='a')
  outtextxy(450,(x*10)+15,"Arqueiro");
  if (jog[0][x].clas=='g')
  outtextxy(450,(x*10)+15,"Guerreiro");
  if (jog[0][x].clas=='m')
  outtextxy(450,(x*10)+15,"Mago");

  if (jog[1][x].clas=='a')
  outtextxy(450,(x*10)+85,"Arqueiro");
  if (jog[1][x].clas=='g')
  outtextxy(450,(x*10)+85,"Guerreiro");
  if (jog[1][x].clas=='m')
  outtextxy(450,(x*10)+85,"Mago");
 }
}


void setstatus (tropa jog[2][5])
{
 int x;
 char text[4];
 setfillstyle(1,0);
 bar (555,1,590,135);
 setcolor(4);
 for (x=0;x<5;x++)
 {
 itoa(jog[0][x].hp,text,10);
 outtextxy(555,(x*10)+15,text);
 itoa(jog[1][x].hp,text,10);
 outtextxy(555,(x*10)+85,text);
 }
}


void dialogo(void)
{
 setfillstyle(1,8);
 bar(460,320,640,448);
 setcolor(7);
 line(460,320,460,448);
 line(460,320,640,320);
 line(460,448,640,448);
 line(639,320,639,448);
}


void instrojogada()
{
 dialogo();
 setcolor(4);
 outtextxy(470,330,"A");
 outtextxy(470,340,"M");
 outtextxy(470,350,"S");
 setcolor(15);
 outtextxy(480,330,"tacar");
 outtextxy(480,340,"over");
 outtextxy(480,350,"air do jogo");
}


void instromov()
{
 dialogo();
 setcolor(4);
 outtextxy(470,330,"I");
 outtextxy(470,340,"K");
 outtextxy(470,350,"J");
 outtextxy(470,360,"L");
 outtextxy(470,370,"C");
 setcolor(15);
 outtextxy(480,330," - cima");
 outtextxy(480,340," - baixo");
 outtextxy(480,350," - esquerda");
 outtextxy(480,360," - direita");
 outtextxy(480,370,"onfirma");
}

void calareaatac(short x, short y, short alcan, short mapa2[7][7])
{
short a, b, c, d;
b=0;
d=-alcan-1;
for(a=-alcan+y;a<=alcan+y;a++)
{
 d++;
 if (d<=0)
 b++;
 else
 b--;
 for(c=x-b+1;c<x+b;c++)
 {
  if ((c>-1)&&(a>-1)&&(c<7)&&(a<7))
  {
   mapa2[c][a]=1;
  }
 }
}
}


void calareadesl(short x, short y, short alcan, short mapa2[7][7], short mapa[7][7])
{
short a, b, c, d;
b=0;
d=-alcan-1;
for(a=-alcan+y;a<=alcan+y;a++)
{
 d++;
 if (d<=0)
 b++;
 else
 b--;
 for(c=x-b+1;c<x+b;c++)
 {
  if ((c>-1)&&(a>-1)&&(c<7)&&(a<7)&&(mapa[c][a]==0))
  {
   mapa2[c][a]=1;
   }
  }
 }
}


void desarea(short mapa2[7][7])
{
 int x, y;
 for (x=0;x<7;x++)
 for (y=0;y<7;y++)
 {
  if(mapa2[x][y]==1)
  {
   setfillstyle(1,5);
   bar ((x*64)+2,(y*64)+2,((x+1)*64)-2,((y+1)*64)-2);
  }
 }
}


void main(void)
{
 tropa jog[2][5];
 short x, y, a, b, k, posx, posy, mov, mapa[7][7], mapa2[7][7];
 char dgt='z', nome1[10], nome2[10];


 for (x=0;x<7;x++)
 for (y=0;y<7;y++)
 {
 mapa[x][y]=0;
 mapa2[x][y]=0;
 }


 cout<<"Bem vindo ao Barbarian Tatics Proto v.Alpha\n\n";
 cout<<"Qual o nome do Jogador 1: ";
 cin>>nome1;
 cout<<"Qual o nome do Jogador 2: ";
 cin>>nome2;
 cout<<"\nUse (A) para arqueiro, (G) para guerreiro ou (M) para mago\n";
 for (y=0;y<2;y++)
 for (x=0;x<5;x++)
  {
   dgt='z';
   while ((dgt != 'a')&&(dgt !='g')&&(dgt !='m'))
   {
    cout<<"Qual a tropa "<<x+1<<" do jogadordor "<<y+1<<"?";
    cin>>dgt;
    if((dgt!='a')&&(dgt!='g')&&(dgt!='m'))
    cout<<"\nEscolha somente entre (G) Guerreiro, (A) Arqueiro ou (M) Mago\n";
   }
   jog[y][x].setclas(dgt);
  }

 //preenche o mapa com a posi‡Æo dos personagens
 for(x=1;x<6;x++)
 {
 mapa[x][0]=x;
 mapa[x][6]=x+5;
 }


 int modo,drive=DETECT;
 initgraph(&drive,&modo,"c:\\tclite\\bgi");


 deftro(jog,nome1,nome2);
 setstatus(jog);


 while (dgt!='s')
 {


  //selecionar o personagem q ser  usado

  for(k=1;k<11;k++)
  for(y=0;y<7;y++)
   for(x=0;x<7;x++)
   {
    if(mapa[x][y]==k)
    {
    desmap();
    setfillstyle(1,9);
    bar ((x*64)+2,(y*64)+2,((x+1)*64)-2,((y+1)*64)-2);
    desperso(mapa, jog);
    instrojogada();


    //escolhe o q o personagem far 
    dgt=getch();

    while((dgt!='a')&&(dgt!='m')&&(dgt!='s'))
    dgt=getch();

    if (mapa[x][y]<6)
    {
     if(dgt=='a')
     {
      calareaatac(x,y,jog[0][(mapa[x][y]-1)].alca,mapa2);
	instromov();
	posx=x;
	posy=y;
	mov=0;
	while(mov==0)
	{
	 desmap();
	  desarea(mapa2);
	 setfillstyle(1,4);
	 bar ((posx*64)+2,(posy*64)+2,((posx+1)*64)-2,((posy+1)*64)-2);
	 desperso(mapa,jog);


	 dgt='q';
	 while((dgt!='i')&&(dgt!='k')&&(dgt!='j')&&(dgt!='l')&&(dgt!='c'))
	 dgt=getch();
	 if(dgt=='i')
	 {
	 dgt='q';
	 if(mapa2[posx][posy-1]==1)
	 posy-=1;
	 }

	 else if(dgt=='k')
	 {
	 dgt='q';
	 if(mapa2[posx][posy+1]==1)
	 posy+=1;
	 }

	 else if(dgt=='j')
	 {
	 dgt='q';
	 if(mapa2[posx-1][posy]==1)
	 posx-=1;
	 }

	 else if(dgt=='l')
	 {
	 dgt='q';
	 if(mapa2[posx+1][posy]==1)
	 posx+=1;
	 }
	 else
	 {
	  dgt='q';
	  if(mapa[posx][posy]>5)
	  {
	   jog[1][(mapa[posx][posy])-6].hp-=(jog[0][(mapa[x][y]-1)].atac*3)-jog[1][(mapa[posx][posy])-6].defe;
	   setstatus(jog);
	   if(jog[1][(mapa[posx][posy]-6)].hp<0)
	   mapa[posx][posy]=0;
	   mov=1;
	  }
	  else
	  {
	   dialogo();
	   setcolor(15);
	   outtextxy(470,330,"Nao pode atacar");
	   outtextxy(470,340,"Deseja mandar?");
	   outtextxy(480,350,"im");
	   outtextxy(480,360,"ao");
	   setcolor(4);
	   outtextxy(470,350,"S");
	   outtextxy(470,360,"N");

	   dgt=getch();
	   while((dgt!='s')&&(dgt!='n'))
	   dgt=getch();

	   if (dgt=='s')
	   {
	    dgt='q';
	    for (a=0;a<7;a++)
	    for (b=0;b<7;b++)
	    mapa2[a][b]=0;
	    goto ANDAR;
	   }
	   dgt='q';
	  }
	 }
	}
       for (x=0;x<7;x++)
       for (y=0;y<7;y++)
       mapa2[x][y]=0;
     }

     else if(dgt=='m')
     {
      ANDAR:
      calareadesl(x,y,jog[0][(mapa[x][y]-1)].desl,mapa2,mapa);
	instromov();
	posx=x;
	posy=y;
	mov=0;
	while(mov==0)
	{
	 desmap();
	 desarea(mapa2);
	 setfillstyle(1,4);
	 bar ((posx*64)+2,(posy*64)+2,((posx+1)*64)-2,((posy+1)*64)-2);
	 desperso(mapa,jog);


	 dgt='q';
	 while((dgt!='i')&&(dgt!='k')&&(dgt!='j')&&(dgt!='l')&&(dgt!='c'))
	 dgt=getch();

	 if(dgt=='i')
	 {
         dgt='q';
	 if(mapa2[posx][posy-1]==1)
	 posy-=1;
	 }

	 else if(dgt=='k')
	 {
         dgt='q';
	 if(mapa2[posx][posy+1]==1)
	 posy+=1;
	 }

	 else if(dgt=='j')
	 {
	 dgt='q';
	 if(mapa2[posx-1][posy]==1)
	 posx-=1;
	 }

	 else if(dgt=='l')
	 {
	 dgt='q';
	 if(mapa2[posx+1][posy]==1)
	 posx+=1;
	 }
	 else
	 {
	 dgt='q';
	 if(mapa[posx][posy]!=mapa[x][y])
         {
         mapa[posx][posy]=mapa[x][y];
	 mapa[x][y]=0;
	 }
	 mov=1;
	 }

	}
       for (x=0;x<7;x++)
       for (y=0;y<7;y++)
       mapa2[x][y]=0;
     }

     else goto FIMPROG;


    }

     else
     {
      if(dgt=='a')
      {
      calareaatac(x,y,jog[1][(mapa[x][y]-6)].alca,mapa2);
	instromov();
	posx=x;
	posy=y;
	mov=0;
	while(mov==0)
	{
	 desmap();
	  desarea(mapa2);
	 setfillstyle(1,4);
	 bar ((posx*64)+2,(posy*64)+2,((posx+1)*64)-2,((posy+1)*64)-2);
	 desperso(mapa,jog);


	 dgt='q';
	 while((dgt!='i')&&(dgt!='k')&&(dgt!='j')&&(dgt!='l')&&(dgt!='c'))
	 dgt=getch();
	 if(dgt=='i')
	 {
	 dgt='q';
	 if(mapa2[posx][posy-1]==1)
	 posy-=1;
	 }

	 else if(dgt=='k')
	 {
	 dgt='q';
	 if(mapa2[posx][posy+1]==1)
	 posy+=1;
	 }

	 else if(dgt=='j')
	 {
	 dgt='q';
	 if(mapa2[posx-1][posy]==1)
	 posx-=1;
	 }

	 else if(dgt=='l')
	 {
	 dgt='q';
	 if(mapa2[posx+1][posy]==1)
	 posx+=1;
	 }
	 else
	 {
	  dgt='q';
	  if((mapa[posx][posy]<6)&&(mapa[posx][posy])>0)
	  {
	   jog[0][(mapa[posx][posy])-1].hp-=(jog[1][(mapa[x][y]-6)].atac*3)-jog[0][(mapa[posx][posy])-1].defe;
	   if(jog[0][(mapa[posx][posy]-1)].hp<0)
	   mapa[posx][posy]=0;
	   setstatus(jog);
	   mov=1;
	  }
	  else
	  {
	   dialogo();
	   setcolor(15);
	   outtextxy(470,330,"Nao pode atacar");
	   outtextxy(470,340,"Deseja mandar?");
	   outtextxy(480,350,"im");
	   outtextxy(480,360,"ao");
	   setcolor(4);
	   outtextxy(470,350,"S");
	   outtextxy(470,360,"N");

	   dgt=getch();
	   while((dgt!='s')&&(dgt!='n'))
	   dgt=getch();

	   if (dgt=='s')
	   {
	    dgt='q';
	    for (a=0;a<7;a++)
	    for (b=0;b<7;b++)
	    mapa2[a][b]=0;
	    goto ANDAR2;
	   }
	   dgt='q';
	  }
	 }
	}

       for (x=0;x<7;x++)
       for (y=0;y<7;y++)
       mapa2[x][y]=0;
      }

      else if(dgt=='m')
      {
      ANDAR2:
      calareadesl(x,y,jog[1][(mapa[x][y]-6)].desl,mapa2,mapa);
	instromov();
	posx=x;
	posy=y;
	mov=0;
	while(mov==0)
	{
	 desmap();
	 desarea(mapa2);
	 setfillstyle(1,4);
	 bar ((posx*64)+2,(posy*64)+2,((posx+1)*64)-2,((posy+1)*64)-2);
	 desperso(mapa,jog);


	 dgt='q';
	 while((dgt!='i')&&(dgt!='k')&&(dgt!='j')&&(dgt!='l')&&(dgt!='c'))
	 dgt=getch();

	 if(dgt=='i')
	 {
         dgt='q';
	 if(mapa2[posx][posy-1]==1)
	 posy-=1;
	 }

	 else if(dgt=='k')
	 {
         dgt='q';
	 if(mapa2[posx][posy+1]==1)
	 posy+=1;
	 }

	 else if(dgt=='j')
	 {
	 dgt='q';
	 if(mapa2[posx-1][posy]==1)
	 posx-=1;
	 }

	 else if(dgt=='l')
	 {
	 dgt='q';
	 if(mapa2[posx+1][posy]==1)
	 posx+=1;
	 }
	 else
	 {
	 dgt='q';
	 if(mapa[posx][posy]!=mapa[x][y])
         {
         mapa[posx][posy]=mapa[x][y];
	 mapa[x][y]=0;
	 }
	 mov=1;
	 }

	}
       for (x=0;x<7;x++)
       for (y=0;y<7;y++)
       mapa2[x][y]=0;
      }

      else goto FIMPROG;
     }


    }
    //checar se algum jogador ganhou;
    b=0;
    for(a=0;a<5;a++)
    {
     b+=jog[0][a].hp;
    }
    if(b<0)
    {
     setcolor(14);
     settextstyle(3,0,6);
     outtextxy(10,180,"GANHOU");
     outtextxy(220,180,nome2);
     getch();
     goto FIMPROG;
    }
    b=0;
    for(a=0;a<5;a++)
    {
     b+=jog[1][a].hp;
    }
    if(b<0)
    {
     setcolor(12);
     settextstyle(3,0,6);
     outtextxy(10,180,"GANHOU");
     outtextxy(220,180,nome1);
     getch();
     goto FIMPROG;
    }
   }
  }
 FIMPROG:
 closegraph();
}