#include<iostream>//in barnamero hatman ba dev ejra kon ba tashakor 
using namespace std;
#include<conio.h>
#include<stdlib.h>
#define m 100
int node[m+1];
class nodeptr{
      public:
         long   int wazn;
            int row;
            int col;
            };
class enode
{
      public:
     enode(){info=0;wazn=0;}        
     long	int info;
	long int wazn;
	enode *next;
	friend class vnode;
	friend class graph;
	};
class vnode
{
      public:
             vnode(){info=0;}
	long int info;
	vnode *nextnode;
	enode *listptr;
	friend class graph;
	};

class graph
{
		public:
			graph();
			~graph();
			void AddVertex(int ele);
			void addedge(int a,int b,int w);
			void print();
			void sort();
			void matrix(int t[][m]);
			void print2(int t[][m]);
			void shortpath(int t[m][m],int s[m][m]);
			int min(int,int);
			void max_w(int t[m][m],nodeptr arr[m]);
			void shart(int t[m][m]);
			void min_w(nodeptr arr[m]);
		private:
            static int n1;    
			vnode *start;
			vnode *last;
};
/*******************************************************************************************************/
int graph::n1=0;
/*******************************************************************************************************/
graph::graph()
{
		start=0;
}
/*******************************************************************************************************/
graph::~graph()
{
		vnode *ap;
			while(start)
			{
				ap=start;
				start=start->nextnode;
				delete ap;
				}
	}
/*******************************************************************************************************/	
void graph::AddVertex(int ele)
{
	vnode *p=new vnode;
	vnode *q=0;	
	vnode *ap=0;
	p->info=ele;
	p->nextnode=0;
	p->listptr=0;
	
	++n1;
	if(start==0)
	start=last=p;
	else
    {
        last->nextnode=p;
        last=p;
        }
}
/*******************************************************************************************************/
void graph::addedge(int a,int b,int w)
{
	vnode *p=start;
	vnode *q=start;
	enode *ap,*eofap;
	if(!p)
		exit(0);
	else
	{
		while(p)
		{
			if(p->info==a)
				break;
			else
				p=p->nextnode;
				
		}
	}	
				ap=new enode;
				ap->info=b;
				ap->wazn=w;
				ap->next=0;
				if(p->listptr==0)
				{
					p->listptr=ap;
					eofap=ap;
					}
				else
				{
					eofap=p->listptr;
					while(eofap->next)
						eofap=eofap->next;
					eofap->next=ap;
				}
}		
/*******************************************************************************************************/				
void graph::print()
{
	vnode	*np=start;
	enode   *ap;
		cout<<"\n  Graph Vertex---------------------------------------------------- \n";
		while(np!=0)
		{
			cout<<np->info<<"->";
			ap=np->listptr;
			while(ap!=0)
			{
				cout<<ap->info<<"("<<ap->wazn<<") ";
				ap=ap->next;
				}
			np=np->nextnode;	
			cout<<"\n";
		}	
}
/*******************************************************************************************************/
void graph::sort()
{
	vnode	*np=start;
	enode   *ap,*q;
	int temp1,temp2;
		while(np!=0)
		{
			ap=np->listptr;
           for(ap=np->listptr;ap->next!=0;ap=ap->next)
               for(q=ap->next;q!=0;q=q->next)
                   if(ap->info>q->info)
                     {temp1=ap->info;
                     temp2=ap->wazn;
                     ap->wazn=q->wazn;
                     ap->info=q->info;
                     q->wazn=temp2;
                     q->info=temp1;                                                                       
                     }
			np=np->nextnode;	
			cout<<"\n";
		}	
}
/*******************************************************************************************************/
void graph::matrix(int t[m][m])
{
     
	vnode *np=start;
	enode *ap;
	for(int i=1;i<=n1;i++)
		{    

			ap=np->listptr;
	
            	if(!ap)		
                  {
                         ap=new enode;
                  ap->next=0;
                
                    }
			for(int j=1;j<=n1;j++)
			{			 
                 
				if((ap->info)==j)
				{
                                 
					t[i][j]= (ap->wazn);
					if(ap->next!=0)
					        ap=ap->next;
					}
				else
					t[i][j]=1000;		
			}
			np=np->nextnode;
        }
}
/*******************************************************************************************************/	
void graph::print2(int t[m][m])
{
	cout<<"\n  Matrix Parts  \n";
	for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=n1;j++)
			{
				cout<<t[i][j]<<" ";
				}
			cout<<"\n";
		}
}	
/*******************************************************************************************************/
void graph::shart(int t[m][m])
{
     int flag=0;
     for(int j=1;j<n1;j++)
           {
             for(int i=j;i<n1;i++)
             {
                flag+=t[i][i+1];
                     }
                        flag+=t[n1][j];
                            if(flag<0)
                            {    
                                cout<<"\n You Have Inserted the Edges Wrongly ";
                                _getch();
                                exit(0);
                                }
                     
              }         
}                   
                  
/*******************************************************************************************************/                                 	
void  graph::shortpath(int t[m][m],int spath[m][m])
{
	int q[m][m];
		for(int i=1;i<=n1;i++)
			for(int j=1;j<=n1;j++)
				spath[i][j]=t[i][j];

		for(int k=1;k<=n1;k++)
			{
				for(int i=1;i<=n1;i++)	
					for(int j=1;j<=n1;j++)			
						q[i][j]=min(spath[i][j],spath[i][k]+spath[k][j]);
				for(int i=1;i<=n1;i++)	
					for(int j=1;j<=n1;j++)
						spath[i][j]=q[i][j];
			}			
}	
/*******************************************************************************************************/
int graph::min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
/*******************************************************************************************************/
void graph::max_w(int t[m][m],nodeptr arr[m])
{
    
                for(int i=1;i<=n1;i++)
                 {     arr[i].wazn=t[1][i];  	
					for(int j=2;j<=n1;j++)
						 if(t[j][i]>arr[i].wazn)
                             { arr[i].wazn=t[j][i];
                               arr[i].row=j;
                               arr[i].col=i;
                               }
                              }
}       
/*******************************************************************************************************/
void  graph::min_w(nodeptr arr[m])
{
      int qw=0;
     int v;
     int min=arr[1].wazn;
     for(int i=2;i<=n1;i++)
           if(arr[i].wazn<min)
                min=arr[i].wazn;
     for(int i=2;i<=n1;i++)
           {if(arr[i].wazn=min)
               v=arr[i].row;
               }
               
 _getch();    
      vnode *np=start;
      while(np)
      {
               if((np->info)==v)
                {cout<<"\n\n\t\t\t\t  Graph Center  "<<np->info;
                     _getch();
                     qw=1;
                     break;
                     }                
                np=np->nextnode;             
      }                   
      if(qw==0)
      {
               cout<<"\n\n\t\t\t\t  Graph Not center ";
               _getch();
               }
}                   
/*******************************************************************************************************/
int menu();                                                 		
int main()
{
    system("color 80");
	cout<<"ba salam in barneme baraye peyda kardan kotahtarin masir ast \n\t  menu ba 7 gozine darad ghabl az anjame alghrithm floyed va peyda kardan kotahtarin masir bayad gozineye 4 khande shavad\n\n\n gozineye 1 faghat baraye khandan rouse hast \n\n gozineye 2 baraye khandane yal beyne 2 ras ast \n\n gozineye 3 baraye namayeshe graph mibashad \n\n gozineye 4 baraye ijade matrix va namayeshe an ast ke agar yal vared nashode bashad bejaye binahayat  adad 1000 gozashte shode ast va sikle manfi ra tashkhis midhad \n\n gozineye 5 baraye anjame algoritme floyd ast \n\n gozineye 6 baraye peyda kardane kotahtarin masir ast (ke ebteda max sotonha ra yafte va bad bein maxha, min ra peyda mikonad )\n\n\n\n\t\t\t"; 
    system("pause");
    system("cls");
    system("color 0c");  
    cout<<"\n  pass = ";
	char password[4];
	for(int i=0 ; i<4 ; i++)
	{
		password[i]=getche();
		
		cout<<char(8);
		cout<<"*";
    }
    cout<<endl;
    
    for(int i=0 ; i<5 ; i++)
          if(i=password[i]);
          cout<<"\n\n\n\n\n\n\n\t\t\t\t\a Correct pasword";
	getch();
	system("color 0e");
	int a[m][m];
	int o,p,w;
	int ele;
	int spath[m][m];
	nodeptr arr[m];
	graph ob;
	while(1)
	{
            system("cls");
            switch(menu())
               {
                    case 1:
						cout<<"Insert a Vertex ";
						cin>>ele;	
                         ob.AddVertex( ele);
                         break;
                    case 3:
                         ob.print();
                         getch();
                         break;
                    case 4:
                          ob.matrix(a);
                          ob.shart(a);
                         ob.print2(a);   
                         getch();       
                         break;
                    case 5:
                         ob.shortpath(a,spath);
                         break;
                    case 6:
                         ob.max_w(spath,arr);
                	     ob.min_w(arr);  
                         break;
                    case 7:
                         cout<<"Exit";
                         getch();
                         
                          cout<<"\n\n\t\t\t Designed by Behzad Movasegh";
                         getch();
                         exit(0);
                         break;                                 
                    case 2:
                         cout<<" Insert an Edge For  Vertixes From ";
						cin>>o;
						cout<<" to ";
						cin>>p;
						cout<<"\n Wight ";	
                         cin>>w;
                         ob.addedge(o,p,w);     	
                	     break;
                	
                 }
          }         	
	        
      
	_getch();
	return 0;
	}
/*******************************************************************************************************/	
int menu()
{
    cout<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15);
    cout<<"\n 1) Make Vertex Graph ";
	cout<<"\n 2) Make Edge Graph ";
    cout<<"\n 3) Show Graph ";
    cout<<"\n 4) Make & Show Matrix ";
    cout<<"\n 5) Floyd Algorithm ";
    cout<<"\n 6) Find the Shortest Way ";
    cout<<"\n 7) Exit ";
    cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------------------------------------------  ";
    cout<<"\n Insert a Number Between 1-7 : ";
    int n;
    cin>>n;
    return n;
}
	
			
				
				
