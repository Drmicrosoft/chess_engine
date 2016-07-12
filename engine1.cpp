
#include <stdio.h>
#include <stdlib.h>



int game ();
int piece (int c);
void changer (int f) ;
int checker ();
int  loops (int a , int b);
void printer ();

int b[8][8] = { 	{2,1,0,0,0,0,-1,-2},
					{3,1,0,0,0,0,-1,-3},
					{4,1,0,0,0,0,-1,-4},
					{5,1,0,0,0,0,-1,-5},
					{6,1,0,0,0,0,-1,-6},
					{4,1,0,0,0,0,-1,-4},
					{3,1,0,0,0,0,-1,-3},
					{2,1,0,0,0,0,-1,-2}
				 };
int x=0,y=0,x1=0,y1=0;
int ch ;

int p = 0 ;




int main()
{
	
	
	//	3askary 1
	//	tabya 	2
	//	hosan	3
	//	feel 	4
	//	wazyer	5
	//	malek 	6
	//	3askary after moving 	7
	//	empty	0
	//	Player 1 >>	+
	//	Player 2 >>	-
	
				 printf("omar\n");
				 printf("game started");
				 int i ;
	scanf("%d",&i);
	
		printer();
		int o = 0 ;
		while ( 1 )
		{
		 o = 0;
		 ch = 0;
	if ((p == 0 || p == 2)&&o==0 )
	{
		p=1 ; o = 1;
	}
	else if ( p ==1 && o == 0)
	{
		p = 2 ; o = 1;
	}
	game();
	printer();
	
	
	
}
}

int game ()
{
	v:;
	printf (" your turn player %d \n",p);
	
	printf (" input the the x dimension for the Piece \n");
	scanf("%d",&x);
	printf (" input the the y dimension for the Piece \n");
	scanf("%d",&y);
	
	// hena bashof law masala Player 1 howa ely 3aleh yel3ab 2at2kd ezay eno howa ely la3b
	if(x >= 0 && x <8 && y >= 0 && y < 8 )
	{
	if( p == 1  )
	{
		if( b[x][y] > 0 )
		
		{		ch = 1 ;printf("done\n");}
	}
	else if( p == 2 )
	{
		if( b[x][y] < 0 )
				{ch = 1 ;printf("done\n");}
	}
	else 
	{
		ch = 0 ;
		printf("error 1 ");
		goto v;
	}
	}
	else { printf("error 2 "); goto v ;}
	
	
	
printf(" your choose is (%d , %d ) = %d \n",x ,y ,b[x][y]);

	printf (" input the the x dimension for your destination \n");
	scanf("%d",&x1);
	printf (" input the the y dimension for your destination \n");
	scanf("%d",&y1);
	
	// hena bashof law masala Player 1 howa ely 3aleh yel3ab 2at2kd ezay eno howa la3b fe makan fady aw makan fe piece le el player 2
	if(x1 >= 0 && x1 <8 && y1 >= 0 && y1 < 8 )
	{
	if( p == 1 )
	{
		if( b[x1][y1] > 0 )
				{ch = 0 ;
				printf("error 3");
				goto v;}
		else {ch = 1 ;printf("done\n");}
	}
	else if( p == 2 )
	{
		if( b[x1][y1] < 0 )
				{ch = 0 ;
					printf("error 4 ");
				goto v;}
		else {ch = 1 ;printf("done\n");}
	}
	else 
	{
		ch = 1 ;
	}
	}
	else { printf("error 5 "); goto v ;}
	
	
	
	if (ch == 1 )
	{
		int u ;
		printf("start piece \n");
		printf(" your piece is %d \n ", b[x][y]);
		u=piece(b[x][y]);
		if ( u == 0 )
		{
			printf("error 6 ");
			goto v ;
		}
		
	}
	else if ( ch == 0 )
	{
		printf("error 7 ");
		goto v;
	}
	return 1;
}



int piece (int c)
{
	int yy=b[x][y];
	int xx=b[x1][y1];
	
	int u = 1;
	if ( c == 1 || c == -1 )
	{printf("el askary start ");
		if((p==1&&y1>y)||(p==2&&y>y1)) 
		{
			if(x==x1 && (abs(y1-y) ==1 || abs(y1-y) ==2))
			{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{changer(7);
					printf("your 3askary has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
				
			}
			
			if(abs(x-x1) == 1 && (abs(y1-y) ==1 ) && ((p==1 && xx < 0 ) ||  (p==2 && xx > 0 )) )
			{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{changer(7);
				printf("your 3askary has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
				
			}
			
			
		}
			
		
	}
	else if ( c == 2 || c == -2 )
	{
		if( (x == x1 && y1 != y) || (x != x1 && y1 == y))
		{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{
				changer(yy);
				printf("your tabya has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
			
		}
		

		
		
	}
	else if ( c == 3 || c == -3 )
	{
		printf("Hosan \n");
		if( (abs(x1-x)==1  && abs(y1-y)==2) || (abs(x1-x)==2  && abs(y1-y)==1))
		{
				
				changer(yy);
				printf("your Hosan has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			
		}
		
		
	}
	else if ( c == 4 || c == -4 )
	{
		if( (abs(x1-x) == abs(y1-y) && (x1 != x && y1 != y) ))
		{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{
				changer(yy);
				printf("your Feel has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
		}
		

		
	}
	else if ( c == 5 || c == -5 )
	{
		
		if ((abs(x1-x) == abs(y1-y) && (x1 != x && y1 != y) ) || ( (x == x1 && y1 != y) || (x != x1 && y1 == y))  )
		{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{
				changer(yy);
				printf("your Wazer has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
		}
		
		
	}
	else if ( c == 6 || c == -6 )
	{
		
		
		if( ((abs(x1-x) == 1) && (abs(y1-y) == 0)) || ((abs(x1-x) == 0) && (abs(y1-y) == 1)) || ((abs(x1-x) == 1) && (abs(y1-y) == 1)))
		{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{
				changer(yy);
				printf("your Malek has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
		}
		

		
	}
	else if ( c == 7 || c == -7 )
	{
		printf("el askart 7 start ");
		if(x==x1 && (abs(y1-y) ==1 ))
			{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{
				changer(yy);
				printf("your 3askary has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
			}
			
			else if(abs(x-x1) == 1 && (abs(y1-y) ==1 ) && ((p==1 && xx < 0 ) ||  (p==2 && xx > 0 )) )
			{
				u=checker();
				if( u == 0 )
				{
					return 0;
				}
				else 
				{changer(7);
				printf("your 3askary has moved from (%d,%d) to (%d,%d)\n",y,x,y1,x1);
				return 1 ;
			}
				
			}

			else printf ("error");
		
	}
	else {
		printf("piece error");
		return 0 ;
	}
	
	return 0 ;
	
}



void changer (int f) 
{f = abs(f);
	if (p == 1)
	{
		b[x1][y1] 	= f ;
		b[x][y] 	= 0 ;
	}
	if (p == 2)
	{
		b[x1][y1] 	=-1 * f ;
		b[x][y] 	= 0 ;
	}
}




int checker ()
{
	int ch2;
	int jj = b[x][y];
	if(jj == 2  ||jj == 4 ||jj == 5 ||jj == 1  )
	{
		if ( jj ==2 )
		{
			if(y1 == y ) 
			{
				ch2=loops(1,1);
			}
			else if ( x1 == x )
			{
				ch2=loops(1,2);
			}
		}
		
		
		else if ( jj ==4 )
		{
				ch2=loops(1,2);
			
		}
		
		else if ( jj == 5 )
		{
			if(x1 == x )
					ch2=loops(1,2);
			else if ( y1 == y )
					ch2=loops(1,1);
			else 
					ch2=loops(2,2);
			
			
		}
		
		else if ( jj == 1)
		{
			if (abs(y1-y) == 2)
			{
					ch2=loops(1,2);
			}
			else ch2 = 1 ;
		}
		
		
	}
	
	
	
	return ch2;
	
}



// a for 1 loop or 2 loop 
// b for x or y 

int loops (int a , int n)
{
	printf("start loops\n");
	int ch3=0;
	int i =0 ;
	if ( a == 1 )
	{
		if ( n == 1 )
		{
			 
			for (i = x+1 ;i<=x1-1; i++)
			{
				if(b[i][y]==0)
				{
					ch3 =1;					
				}
				else 
				{
					ch3 = 0;
				}
			}
			
		}
		else if ( n == 2 )
		{
			
			for (i = y+1 ;i<=y1-1; i++)
			{
				if(b[x][i]==0)
				{
					ch3 =1;					
				}
				else 
				{
					ch3 = 0;
				}
			}
		}		
	}
	
	
	
	
	else if ( a == 2 )
	{
		
		if ( x1 > x && y1 > y ) 
		{
		for (i=1 ;i<=abs(x1-x); i++)
		{
			int l,m ;
			l=x+i;
			m=y+i;
			if(b[l][m] == 0)
			ch3 = 1 ;
			else 
			ch3 = 0;
		}
		
		}
	
	else if ( x1 > x && y1 < y ) 
		{
		for (i=1 ;i<=abs(x1-x); i++)
		{
			int l,m ;
			l=x+i;
			m=y-i;
			if(b[l][m] == 0)
			ch3 = 1 ;
			else 
			ch3 = 0;
		}
		
		}
	
	
	else if ( x1 < x && y1 > y ) 
		{
		for (i=1 ;i<=abs(x1-x); i++)
		{
			int l,m ;
			l=x-i;
			m=y+i;
			if(b[l][m] == 0)
			ch3 = 1 ;
			else 
			ch3 = 0;
		}
		
		}
	
	
	else if ( x1 < x && y1 < y ) 
		{
		for (i=1 ;i<=abs(x1-x); i++)
		{
			int l,m ;
			l=x-i;
			m=y-i;
			if(b[l][m] == 0)
			ch3 = 1 ;
			else 
			ch3 = 0;
		}
		
		}
	
	
	
	
	
	
	
}
	
	
	return ch3 ;
	
	
	
}
void printer ()
{int i ,j;
	printf("-----------------------------------------------------------\n");
	for(i = 0 ; i<8 ; i++)
	{
		for (j=0;j<8;j++)
		{
			printf("%d\t",b[j][i]);
		}
		printf("\n");
		printf("\n");
	}
		printf("-----------------------------------------------------------\n");
}
