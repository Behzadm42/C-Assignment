#include<iostream>
using namespace std;
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


class danesh{
      
	protected:
		char name[31];
		 int er;
		char darsa[10][21];
		float avg;
		int vahed;
	char id[10];
	public:  

		void setname(char *);
		void setid(char *);
		void setavg(float );
		void setdarsa(char *ob,int m){ strcpy(darsa[m],ob);}
		char *getname(){return name;}
		char *getid(){return id;}
		float getavg(){return avg;}

		virtual void print()=0;
		
		};
void danesh::setname( char *ob)
{
	
		strcpy(name,ob);

		}
void danesh::setid(char *ib)
{
	strcpy(id,ib);
	}
void danesh::setavg(float a)
{
	avg=a;
	}

class d_roz:public danesh
{     
      static int m;
      
	public:
           d_roz *next;		//chera
		d_roz();
		void print();
		friend class linkroz;
};
int d_roz::m=0;
d_roz::d_roz()
{
	name[0]='\0';
    er=0;
	id[0]='\0';	
	avg=0.0;
	vahed=0;
	for(int i=0;i<10;i++)
	{       

            darsa[i][0]='\0';
		
    }
	next=0;
	}
void d_roz::print()
{
	cout<<"\n name = "<<getname();
    cout<<"\n id = "<<getid();
    cout<<"\n avg = "<<getavg();	
	for(int j=0;j<10; j++)
		cout<<"\n darsa = "<<darsa[j];
	cout<<"\n vahed = "<<vahed;
	}
class linkroz{
      
       
      d_roz *first,*last;
	public:
           
		linkroz();
		void save();
		void load();
		void moratab();
		int bar();
		int tash(char *);
		void vahedd(char *);
		int asd(char *,int );
		void adddars1(char *,char *,int );
		void adddars2(int ,char *);
		void deletedars(char *);
		void virayesh1(char *);
		void adddaneshjo();
		void deletedaneshjo(char *);
		void search(char *);
		void virayesh2(char *);
		void showt(char *);
		void namayesh();
		};
linkroz::linkroz()
{first=last=0;}
int linkroz::bar()
{
    d_roz *nextptr=first;
    while(nextptr)
    {
             for(int i=1;i<10;i++)
             {
                     if(strcmp(nextptr->darsa[i],"\0")==0)
                                   { return i;
                                    break;
                                    }
               }                     
        nextptr=nextptr->next;     
     }
}                                  
void linkroz::moratab()
{
     d_roz *nextptr=first;
     while(nextptr)
              {
                   for(int i=1;i<9;i++)
                           if(strcmp(nextptr->darsa[i],"\0")==0)
                                { strcpy(nextptr->darsa[i],nextptr->darsa[i+1]);
                                   strcpy(nextptr->darsa[i+1],"\0");
                                   } 
                 nextptr=nextptr->next;
                 }
}                                                             
int linkroz::asd(char *ob,int b)
{	d_roz *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
            nextptr->er=b-1;                         
            nextptr->er++;
            return nextptr->er;
            break;
            }
         else
         nextptr=nextptr->next;
     }
}                                            
int linkroz::tash(char *ob)
{	d_roz *nextptr=first;
     char ch[31];
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
            strcpy(ch,nextptr->name);                         
			cout<<"  "<<ch<<"                                tarahi shode tavasot ";//
    //        cout<<char(8)<<char(8)<<char(8)<<char(8)<<char(8)<<char(8);
			return 1;
			break;
		}
		else
			nextptr=nextptr->next;
	}
	return 0;// momken eshkal bede
}	

void linkroz::adddars1(char *od,char *ob,int c)
{	
	d_roz *nextptr=first;

		while(nextptr)
			{
				if(strcmp(nextptr->id,ob)==0)
				{         
                 
					strcpy(nextptr->darsa[c],od);
					
					break;
					}
				else
					nextptr=nextptr->next;
			}
	
}
void linkroz::adddars2(int s,char *ob)
{
	d_roz *nextptr=first;
		while(nextptr)
			{
				if(strcmp(nextptr->id,ob)==0)
				{
					nextptr->vahed+=s;
					break;
					}
				else
					nextptr=nextptr->next;
			}		
}					

void linkroz::virayesh1(char *ob)
{	d_roz *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{		char aname[31];
				char did[10];
				float davg;
				
				cout<<"\n name = ";
				cin.get();
				cin.get(aname,25);
				
				nextptr->setname(aname);
				cout<<"\n id= ";
				cin>>did;
				nextptr->setid(did);
				cout<<"\n avg ";
				cin>>davg;
				nextptr->setavg(davg);

					break;
		}
		else
			nextptr=nextptr->next;
	}
}	
void linkroz::deletedars(char *ob)
{	d_roz *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
			int a;
			int p;
			cout<<"\n chandomin dars hazf shavad = ";
			cin>>a;
			//cin.get();
			cout<<"\n vahe ra vared kon = ";
			cin>>p;
             strcpy(nextptr->darsa[a],"\0");
			 nextptr->vahed-=p;
	          break;		
			      
		}
		else
		nextptr=nextptr->next;
	}		
}
void linkroz::vahedd(char *ob)
{
	d_roz *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{	if(nextptr->avg>17.00)
				{cout<<"mojaz be bardashtan 24 vahed hasti";
				break;}
			else
				{cout<<"mojaz be bardashtan 20 vahed hasti";
				break;}
				}
		else
			{
			nextptr=nextptr->next;
			}
			}
}				
void linkroz::adddaneshjo()
{
	d_roz *newptr;
	newptr=new d_roz;
	if(!newptr)//momken eshkal dashte bashe
		{
			cout<<"daneshjo ezafe nashode";
			getch();
			exit(0);
			}
	newptr->next=0;
	cout<<"name = ";
	cin.get();
	cin.get(newptr->name,31);

	cout<<"\n id = ";
	cin>>newptr->id;
	cout<<"\n avg = ";
	cin>>newptr->avg;
	if(first==0)
		first=last=newptr;
	else
	{
		last->next=newptr;
		last=newptr;
		}
}
void linkroz::deletedaneshjo(char *ob)
{
	d_roz *curptr=first,*nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
			if(nextptr==first)
				{first=first->next;
				delete nextptr;
				break;
				}
			else
				{if(nextptr==last)
					last=curptr;
				curptr->next=nextptr->next;
				delete nextptr;
				break;
				}
		else
			{
			curptr=nextptr;
			nextptr=nextptr->next;}
	}
			
}
void linkroz::search(char *ob)
{
	d_roz *nextptr=first;
	while(nextptr)
	{	
		if(strcmp(ob,nextptr->id)==0)
			{
			cout<<"in daneshjo ba shomareye "<<nextptr->id<<" vojod darad ";
			break;
			}
		else
			nextptr=nextptr->next;
	}
} 
void linkroz::virayesh2(char *ob)
{
	d_roz *nextptr=first;
			
	char aname[31];
	char did[10];
	float davg;
	while(nextptr)
	{
		if(strcmp(ob,nextptr->id)==0)
		    {
			cout<<"\n name = ";
			cin.get();
			cin.get(aname,30);
			
			nextptr->setname(aname);
			cout<<"\n id = ";
			cin>>did;
			nextptr->setid(did);
			cout<<"\n avg = ";
			cin>>davg;
			nextptr->setavg(davg);
			break;
			}
		else
			nextptr=nextptr->next;
	}

}
void linkroz::showt(char *ob)
{
	d_roz *ptr=first;
		while(ptr)
		{
			if(strcmp(ob,ptr->id)==0)
			{		cout<<"\n name = "<<ptr->getname();
					cout<<"\n id = "<<ptr->getid();
					cout<<"\n avg = "<<ptr->getavg();
					for(int j=1;j<10; j++)
					cout<<"\n dars = "<<ptr->darsa[j];
					cout<<"\n vahed = "<<ptr->vahed;
					break;	
					}
			else
				ptr=ptr->next;
		}
}
void linkroz::namayesh()
{
	d_roz *nextptr=first;
		while(nextptr)
			{		cout<<"\n name = "<<nextptr->getname();
					cout<<"\n id = "<<nextptr->getid();
					cout<<"\n avg = "<<nextptr->getavg();
					for(int j=1;j<10; j++)
					cout<<"\n dars = "<<nextptr->darsa[j];
					cout<<"\n vahed = "<<nextptr->vahed;
					nextptr=nextptr->next;
				}
}
void linkroz::save()
{
	int index=0;
	d_roz *temp=first;
	ofstream fp1("daneshjoyerozane.txt",ios::out);
	while(temp!=0)//shayad irad bede
		{
			fp1.seekp(index*sizeof(d_roz),ios::beg);
			fp1.write((char *)(temp),sizeof(class d_roz));
				temp=temp->next;
				++index;				
		}
	}
void linkroz::load()
{
	int index=0;
	d_roz *temp;
	
	
	ifstream fp1("daneshjoyerozane.txt",ios::in);
	while(1)
	{
		if(fp1.eof())
			break;
		temp=new d_roz;	
		fp1.seekg(index*sizeof(d_roz),ios::beg);
		fp1.read((char * )(temp),sizeof(d_roz));
			if(first==0)
				{first=last=temp;
				temp->next=0;}
			else
				{
				last->next=temp;
				last=temp;
				temp->next=0;
				}
			index++;
	}
}
class d_shab:public danesh
{
	long int sh;
	
	public:
           d_shab *next;// chera
		d_shab();
		void setsh(long int );//shahreye be ezaye har vahed
		double getsh(){return sh;}
		void print();
		friend class linkshab;
		};
d_shab::d_shab()
{
 //               danesh::danesh();
name[0]='\0';
er=0;
id[0]='\0';	
avg=0.0;
vahed=0;
	for(int i=0;i<10;i++)
	        strcpy(darsa[i],"\0");//ye moshkel dard
	sh=0;
	next=0;

}
void d_shab::setsh(long int shah)
{
	sh=shah;//shahriye be ezaye har vahed ra migirim beazfeye shahreye sabet mikonim	
}
void d_shab::print()
{
	cout<<"\n name = "<<getname();
    cout<<"\n id = "<<getid();
    cout<<"\n avg = "<<getavg();
	
	for(int j=0;j<10; j++)
		cout<<"\n dars = "<<darsa[j];
	cout<<"\n vahed = "<<vahed;
	cout<<"\n shahriaye kol = "<<getsh();
	}
class linkshab
{
	d_shab *first,*last;
	public:
		linkshab();
		int asd(char *,int );
		void shah(char *,long int);
		void save();
		void load();
		void moratab();
		int bar();
		int tash(char *);
		void vahedd(char *);
		void adddars1(char *,char*,int);
		void adddars2(int ,char *);
		void deletedars(char *);
		void virayesh1(char *);
		void adddaneshjo();
		void deletedaneshjo(char *);
		void search(char *);
		void virayesh2(char *);
		void showt(char *);
		void namayesh();
		};
linkshab::linkshab()
{first=last=0;}
int linkshab::bar()
{
    d_shab *nextptr=first;
    while(nextptr)
    {
             for(int i=1;i<10;i++)
             {
                     if(strcmp(nextptr->darsa[i],"\0")==0)
                                   { return i;
                                    break;
                                    }
               }                     
        nextptr=nextptr->next;     
     }
}
void linkshab::shah(char *ob,long int a)
{	d_shab *nextptr=first;
    long int b;
    
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
           nextptr->sh=0;                          
           b=a*(nextptr->vahed+1);                          
          nextptr->sh+=b;
          break;
          }
         else
         nextptr=nextptr->next;
     }
}           
     
int linkshab::asd(char *ob,int b )
{	d_shab *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
             nextptr->er=b-1;                        
            nextptr->er++;
            return nextptr->er;
            break;
            }
         else
         nextptr=nextptr->next;
     }
}
void linkshab::adddars1(char *od,char *ob,int c)
{	
	d_shab *nextptr=first;

		while(nextptr)
			{
				if(strcmp(nextptr->id,ob)==0)
				{         
                 
					strcpy(nextptr->darsa[c],od);
					
					break;
					}
				else
					nextptr=nextptr->next;
			}
	
}  
void linkshab::adddars2(int s,char *ob)
{
	d_shab *nextptr=first;
		while(nextptr)
			{
				if(strcmp(nextptr->id,ob)==0)
				{
					nextptr->vahed+=s;
					break;
					}
				else
					nextptr=nextptr->next;
			}		
}
int linkshab::tash(char *ob)
{	d_shab *nextptr=first;
    char *ch;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
            ch=nextptr->name;                         
            cout<<"  "<<ch<<"                                 tarahi shode tavasot behzad ";
			return 1;
			break;
		}
		else
			nextptr=nextptr->next;
	}
	return 0;// momken eshkal bede
}	

void linkshab::deletedars(char *ob)
{	d_shab *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{
			int a;
			int p;
			cout<<"\n chandomin dars hazf shavad = ";
			cin>>a;
			//cin.get();
			cout<<"\n vahe ra vared kon = ";
			cin>>p;
             strcpy(nextptr->darsa[a],"\0");
			 nextptr->vahed-=p;
	          break;		
			      
		}
		else
		nextptr=nextptr->next;
	}		
}
void linkshab::virayesh1(char *ob)
{	d_shab *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{		char aname[31];
				char did[10];
				float davg;
				
				cout<<"\n name = ";
				cin.get();
				cin.get(aname,30);
				
				nextptr->setname(aname);
				cout<<"\n id= ";
				cin>>did;
				nextptr->setid(did);
				cout<<"\navg ";
				cin>>davg;
				nextptr->setavg(davg);
			
					break;
		}
		else
			nextptr=nextptr->next;
	}
}	

void linkshab::vahedd(char *ob)
{
	d_shab *nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
		{	if(nextptr->avg>17.00)
				{cout<<"mojaz be bardashtan 24 vahed hasti";
				break;}
			else
				{cout<<"mojaz be bardashtan 20 vahed hasti";
				break;}
				}
		else
			{
			nextptr=nextptr->next;
			}
			}
}			
void linkshab::adddaneshjo()
{
	d_shab *newptr;
	newptr=new d_shab;
	long int s;
	if(!newptr)//momken eshkal dashte bashe
		{
			cout<<"daneshjo ezafe nashode";
			getch();
			exit(0);
			}
	newptr->next=0;
	cout<<"name = ";
	cin.get();
	cin.get(newptr->name,31);
	cout<<"\n id = ";
	cin>>newptr->id;
	cout<<"\n avg = ";
	cin>>newptr->avg;

	if(first==0)
		first=last=newptr;
	else
	{
		last->next=newptr;
		last=newptr;
		}
}
void linkshab::deletedaneshjo(char *ob)
{
	d_shab *curptr=first,*nextptr=first;
	while(nextptr)
	{	if(strcmp(ob,nextptr->id)==0)
			if(nextptr==first)
				{first=first->next;
				delete nextptr;
				break;
				}
			else
				{if(nextptr==last)
					last=curptr;
				curptr->next=nextptr->next;
				delete nextptr;
				break;
				}
		else
			{
			curptr=nextptr;
			nextptr=nextptr->next;}
	}
			
}		
void linkshab::search(char *ob)
{
	d_shab *nextptr=first;
	while(nextptr)
	{	
		if(strcmp(ob,nextptr->id)==0)
			{
			cout<<"in daneshjo ba shomare "<<nextptr->id<<" vojod darad ";
			
			break;
			}
		else
			nextptr=nextptr->next;
	}
} 
void linkshab::virayesh2(char *ob)
{
	d_shab *nextptr=first;
			
	char aname[31];
	char did[10];
	float davg;
	while(nextptr)
	{
		if(strcmp(ob,nextptr->id)==0)
		    {
			cout<<"\n name = ";
			cin.get();
			cin.get(aname,30);
			
			nextptr->setname(aname);
			cout<<"\n id= ";
			cin>>did;
			nextptr->setid(did);
			cout<<"\n avg ";
			cin>>davg;
			nextptr->setavg(davg);
			break;
			}
		else
			nextptr=nextptr->next;
	}

}	
void linkshab::showt(char *ob)
{
	d_shab *ptr=first;
		while(ptr)
		{
			if(strcmp(ptr->id,ob)==0)
			{		cout<<"name = "<<ptr->getname();
					cout<<"\n id = "<<ptr->getid();
					cout<<"\n avg = "<<ptr->getavg();
					for(int j=1;j<10; j++)
					cout<<"\n dars = "<<ptr->darsa[j];
					cout<<"\n vahed = "<<ptr->vahed;
						cout<<"\n shahriaye kol = "<<ptr->getsh();
						break;
					}
			else
				ptr=ptr->next;
		}
}		
void linkshab::namayesh()
{
	d_shab *nextptr=first;
		while(nextptr)
			{		cout<<"name = "<<nextptr->getname();
					cout<<"\n id = "<<nextptr->getid();
					cout<<"\n avg = "<<nextptr->getavg();
					for(int j=1;j<10; j++)
					cout<<"\n dars = "<<nextptr->darsa[j];
					cout<<"\n vahed = "<<nextptr->vahed;
					cout<<"\n shahriaye kol = "<<nextptr->getsh();
					nextptr=nextptr->next;
				}
}
void linkshab::save()
{
	int index=0;
	d_shab *temp=first;
	ofstream fp2("daneshjoyeshabane.txt",ios::binary|ios::out);
	while(temp!=0)
		{
			fp2.seekp(index*sizeof(d_shab),ios::beg);
			fp2.write((char *)(temp),sizeof(class d_shab));
				temp=temp->next;
				++index;				
		}
	}
void linkshab::load()
{
	int index=0;
	d_shab *temp;
	
	
	ifstream fp2("daneshjoyeshabane.txt",ios::binary|ios::in);
	while(1)
	{
		if(fp2.eof())
			break;
		temp=new d_shab;
		fp2.seekg(index*sizeof(d_shab),ios::beg);
		fp2.read((char *)(temp),sizeof(d_shab));
			if(first==0)
				{
				first=last=temp;
				temp->next=0;
				}
			else
				{
				last->next=temp;
				last=temp;
				temp->next=0;
				}
		//	temp=temp->next; //momken moshkel dash te bashe
			index++;
	}
}	
class dars{
		char name[21];
		int  code;
		int  z;
		int v;
		dars *next;
	public:
		dars();
		void setvahed(int );
		void setname(char *);
		void setcode(int );
		void setz(int );
		int getvahed(){return v;}
		char *getname(){return name;}
		int getcode(){return code;}
		int getz(){return z;}
		friend class linkdars;
		friend class linkroz;
		};
dars::dars()
{
	name[0]='\0';
	code=0;
	z=0;
	v=0;
	next=0;
	}
void dars::setvahed(int w)
{
	v=(w>0&&w<=4)?w:1;
	}
void dars::setname(char *ob)
{
	strcpy(name,ob);
	}
void dars::setcode(int a)
{
		code=a;
		}
void dars::setz(int b)
{
	z=b;
	}
class linkdars{
	dars *first,*last;
	public:
		linkdars();
		void adddars();
		int tashkhis(int);
		dars bargardan(int);
		void k_z(int);
		void deletedars(int );
		void search(int );
		void virayesh(int );
		void showd(int );
		void nameyesh();
		void save();
		void load();
		
	};
linkdars::linkdars()
{
	first=last=0;
	}
void linkshab::moratab()
{
     d_shab *nextptr=first;
     while(nextptr)
              {
                   for(int i=1;i<9;i++)
                           if(strcmp(nextptr->darsa[i],"\0")==0)
                                { strcpy(nextptr->darsa[i],nextptr->darsa[i+1]);
                                   strcpy(nextptr->darsa[i+1],"\0");
                                   } 
                 nextptr=nextptr->next;
                 }
}	
int linkdars::tashkhis(int a)
{
	dars *nextptr=first;
//	cout<<"javad ";
		while(nextptr)
		{
			if(nextptr->code==a)
			{	
				return 1;
				break;
			}
			else
				nextptr=nextptr->next;
	    }
}
dars linkdars::bargardan(int a)
{	dars *nextptr=first;
 // cout<<"omid ";
		while(nextptr)	
		{
			if(nextptr->code==a)
				{
					return *nextptr;
					break;
				}
			else
				nextptr=nextptr->next;
		}
}
void linkdars::k_z(int a)
{	dars *nextptr=first;
		while(nextptr)	
		{
			if(nextptr->code==a)
				{   
                    if(nextptr->z==0)
                        {cout<<"\n zarfiat takmil ast";
                        exit(0);
                        }             
					nextptr->z-=1;
					break;
					}
			else
				nextptr=nextptr->next;
		}
}		
			
void linkdars::adddars()
{
	dars *newptr;
	newptr=new dars;
	if(!newptr)
		{
			cout<<" dars ra ezafe nakard ";
			getch();
			exit(0);
		}
	newptr->next=0;
	cout<<"name = ";
	cin.get();
	cin.get(newptr->name,30);
	
	cout<<"code = ";
	cin>>newptr->code;
	cout<<" zarfiat = ";
	cin>>newptr->z;
	cout<<"vahed = ";
	cin>>newptr->v;
	if(first==0&&last==0)
	{
		first=newptr;
		last=newptr;
		}
	else
		{
		last->next=newptr;
		last=newptr;
		}
}
void linkdars::deletedars(int ob)
{
	dars *nextptr=first;
	dars *curptr=first;
	 while(nextptr)
		{
			if(nextptr->code==ob)
				{
					if(first==nextptr)
						{first=first->next;
						delete nextptr;
						break;
						}
					else
						{
						if(nextptr==last)
							last=curptr;
						curptr->next=nextptr->next;
						delete nextptr;
						break;
						}
				}
			else
				{
					curptr=nextptr;
					nextptr=nextptr->next;
						}
		}
}
void linkdars::search(int ob)
{
	dars *temp;
		while(temp)
			{
				if(temp->code==ob)
					{
						cout<<"in dars  vojod dard"<<endl;
						break;
                        }
				else
					temp=temp->next;
			}
	}
void linkdars::virayesh(int ob)	
{
	dars *temp;
		while(temp)
			{
				if(temp->code==ob)
					{
						char dname[21];
						int c;
						int zarfiat;
						int vahed;
						cout<<"name = ";
						cin.get();
						cin.get(dname,30);
						
						temp->setname(dname);
						cout<<"\n code = ";
						cin>>c;
						temp->setcode(c);
						cout<<"\n zarfiat = ";
						cin>>zarfiat;
						temp->setz(zarfiat);
						cout<<"\n vahed = ";
						cin>>vahed;
						temp->setvahed(vahed);
						break;
					}
				else
					
					temp=temp->next;
					
			}
}
void linkdars::showd(int ob)
{
	dars *temp=first;
	 while(temp)
		{
			if(temp->code==ob)
				{
					cout<<"\n name = "<<temp->getname();
					cout<<"\t code = "<<temp->getcode();
					cout<<"\n zarfiat = "<<temp->getz();
					cout<<"\t vahed = "<<temp->getvahed();
					break;
				}
			else
				temp=temp->next;
		}
}
void linkdars::nameyesh()
{
	dars *temp=first;
	 while(temp)
		{
					cout<<"\n name = "<<temp->getname();
					cout<<"\t code = "<<temp->getcode();
					cout<<"\n zarfiat = "<<temp->getz();
					cout<<"\t vahed = "<<temp->getvahed();
					temp=temp->next;
					}
}
void linkdars::save()
{
	int index=0;
	dars *temp=first;
	ofstream fpdars("dars.txt",ios::binary|ios::out);
	while(temp!=0)
		{
			fpdars.seekp(index*sizeof(dars),ios::beg);
			fpdars.write((char *)(temp),sizeof(class dars));
				temp=temp->next;
				++index;				
		}
}
void linkdars::load()
{
	int index=0;
	dars *temp;
	
	
	ifstream fpdars("dars.txt",ios::binary|ios::in);
	while(1)
	{
		if(fpdars.eof())
			break;
		temp=new dars;
		fpdars.seekg(index*sizeof(dars),ios::beg);
		fpdars.read((char *)(temp),sizeof(dars));
			if(first==0&&last==0)
				{
				first=temp;
				last=temp;
				temp->next=0;
				}
			else
				{
				last->next=temp;
				last=temp;
				temp->next=0;
				}
		//	temp=temp->next; //momken moshkel dash te bashe
			index++;
	}
}

int menu1();
int menu2();
int menu3();
int menu4();
int main()
{
    system("cls");
    system("color 9b");
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    "<<char(17)<<" system jame golestan "<<char(16);
    getch();
	linkroz list1;
	linkshab list2;
	linkdars list3;
	list1.load();
	list2.load();
	list3.load();

	d_roz *temp;
	temp=new d_roz;
	temp->next=0;
	d_shab *temp2;
	dars *temp5;
	temp5=new dars;
	dars *temp6;
	temp6=new dars;
	char user[21];
	char pass[21];
	system("cls");
	while(1)
	{       
//            
        system("color f0");    
        system("cls");    
        cout<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15);
		cout<<"\n username : ";
			cin>>user;
		cout<<"\n password : ";
        for(int i=0;i<4;i++)
        {    
		 pass[i]=getche();
        cout<<char(8);
        cout<<"*";
        }		


		system("cls");
		if(strcmp(user,"admin")==0)
			{if(strcmp(pass,"1234")==0)
			 {
                system("color 4b");                       
				int q;
				cout<<"\n  daneshjoyane rozane adad 1 va baraye shabane 2 ra vared konid  ";
				cin>>q;
				system("cls");
				if(q==2)
					{
                        int qwe=1;
						while(qwe)
							{	
								system("cls");
								switch(menu2())
									{
									case 1:
										{  
                                            //cout<<"behzad";
											list2.adddaneshjo();
										//	getch();
											break ;
											}
									case 2:
										{	char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list2.deletedaneshjo(ob);
										//	getch();
											break;
											}
									case 3:
										{
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list2.search(ob);
											//getch();
											break;
											}
									case 4:
										{
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list2.virayesh2(ob);
											//getch();
											break;
											}
									case 5:
										{  
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list2.showt(ob);
											getch();
											break;
											}
									case 6:
										{
											list2.namayesh();
											getch();
											break;
											}
									case 7:
										{
										  list2.save();
										  //getch();
										  break;
										  }
									case 8:
										{
											list2.load();
											//getch();
											break;
											}
									case 9:	
										{
											list3.adddars();
											//getch();
											break;}
									case 10:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.deletedars(ob);
											//getch();
											break ;
											}
									case 11:
										{
										    int ob;
											cout<<" code dars ra vared kon";
											
											cin>>ob;
											list3.search(ob);
											getch();
											break;
											}
									case 12:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.virayesh(ob);
											//getch();
											break;
											}
									case 13:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.showd(ob);
											getch();
											break;
											}
									case 14:
										{
											list3.nameyesh();
											getch();
											break;
											}
									case 15:
										{
											list3.save();
											//getch();
											break;
											}
									case 16:
										{
											list3.load();
											//getch();
											break;
										}
									case 17:
										{
											cout<<"\n exit ";
											getch();
												exit(0);
												}
									case 18:
                                         {
                                         	char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
                                             long int a;
                                             cout<<"\n shahriye be ezaye har vahed";
                                             cin>>a;
                                             list2.shah(ob,a);
                                             //getch();
                                             break;
                                         }			
									case 20:
                                         {
                                             qwe=0;
                                             //getch();
                                             break;
                                             }			
								if(menu2()==20)
									{getch();
                                    break;}
								}
							}
					}		
				else
					
					{
                         int qw=1;
					while(qw)
							{
								system("cls");
								switch(menu1())
									{
									case 1:
										{
											list1.adddaneshjo();
											//getch();
											break ;
											}
									case 2:
										{	char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list1.deletedaneshjo(ob);
											//getch();
											break;
											}
									case 3:
										{
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list1.search(ob);
											getch();
											break;
											}
									case 4:
										{
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list1.virayesh2(ob);
											//getch();
											break;
											}
									case 5:
										{
											char ob[10];
											cout<<"shomareye daneshjo ra vared kon";
											cin>>ob;
											list1.showt(ob);
											getch();
											break;
											}
									case 6:
										{
											list1.namayesh();
											getch();
											break;
											}
									case 7:
										{
										  list1.save();
										  //getch();
										  break;
										  }
									case 8:
										{
											list1.load();
											//getch();
											break;
											}
									case 9:	
										{
											list3.adddars();
											//getch();
											break;}
									case 10:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.deletedars(ob);
											//getch();
											break ;
											}
									case 11:
										{
										    int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.search(ob);
											getch();
											break;
											}
									case 12:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.virayesh(ob);
										//	getch();
											break;
											}
									case 13:
										{
											int ob;
											cout<<" code dars ra vared kon";
											cin>>ob;
											list3.showd(ob);
											getch();
											break;
											}
									case 14:
										{
											list3.nameyesh();
											getch();
											break;
											}
									case 15:
										{
											list3.save();
											//getch();
											break;
											}
									case 16:
										{
											list3.load();
											//getch();
											break;
										}
									case 17:
										{
											cout<<"\n exit ";
											getch();
												exit(0);
												}
									case 20:
                                         {
                                             qw=0;
                                            // getch();
                                             break;
                                             }			
								if(menu1()==20)
								    {getch();
									break;}
								}
						}
					}	
								
			 } 
			else
			{
				cout<<"\n pass eshtebah ast";
				getch();
				exit(0);}
			}	
			
		else if(user[2]=='1')
			{	if (strcmp(pass,"1234")==0)
					{	
                        int we=1;
						system("cls");
					     char ob[21];
					     strcpy(ob,user);
						while(we)// shayad moshkel bede
							{
								system("cls");
								if(list1.tash(ob)==1)
                                   { 
                                      cout<<"behzad";        
									switch(menu3())//shayad eror begirad
									{
										case 1:
											{
												list1.vahedd(ob);
												getch();
												break; 
												}
										case 2:
											{
												list3.nameyesh();
												int a;
												cout<<"\n code dars ravared kon ";
												cin>>a;
												if(list3.tashkhis(a)==1)
													{
                                                         int b,f;
                                                         f=list1.bar();
                                                         b=list1.asd(ob,f);               
                                                         list3.k_z(a);               
														*temp5=list3.bargardan(a);
														list1.adddars1(temp5->getname(),ob,b);
														list1.adddars2(temp5->getvahed(),ob);
														//if(list1.tash(ob)==1)
														
													}
												else{
														cout<<"code dorost vared nashode ";
														getch();
														exit(0);
														}
												
											  //  getch();
												break;
												}
										case 3:
											{
                                                list1.showt(ob);
                                                getch();
												list1.deletedars(ob);
												list1.moratab();
												getch();
												break;
												}
										case 4:
											{
												list1.virayesh1(ob);
												//getch();
												break;
												}
										case 5:
											{
												list1.showt(ob);
												getch();
												break;
												}
										case 6:
                                            {
                                                cout<<"save ";
                                                list1.save();
                                                list3.save();
                                                //getch();
                                                break;
                                                
                                                }		
										case 7:
											{
												cout<<"exit ";
												getch();
												exit(0);
											}	
										case 10:
                                             {
                                                  
                                                  system("cls");
                        
                                                //  getch();
                                                  we=0;
                                                  break;
                                                  }      
                                         }
                                         }	

                                      else
                                         { cout<<"id dorost nist";
                                         getch();
                                          exit(0);
                                          }            
                                 }

							
                        }
				else
					{
						system("cls");
					cout<<"pass eshtebah ast";
					getch();
						exit(0);
						}
                  
			}
			
		else if(user[2]=='2')
			{	if (strcmp(pass,"1234")==0)
					{	
                        int er=1;
						system("cls");
						char ob[10];
						//cout<<"\n shomare daneshjoyi ra vared konid ";
						//cin>>ob;
						strcpy(ob,user);
						while(er)//shyead mosh kel bede
							{
								system("cls");
								if(list2.tash(ob))
									switch(menu4())//shayad eror begirad
									{
										case 1:
											{
												list2.vahedd(ob);
												getch();
												break; 
												}
										case 2:
											{
												list3.nameyesh();
												int a;
												cout<<"\n code dars ravared kon ";
												cin>>a;
												if(list3.tashkhis(a)==1)
													{
                                                         int b,f;
                                                         f=list2.bar();
                                                         b=list2.asd(ob,f);               
                                                         list3.k_z(a);               
														*temp6=list3.bargardan(a);
														list2.adddars1(temp6->getname(),ob,b);
														list2.adddars2(temp6->getvahed(),ob);
														//if(list1.tash(ob)==1)
														
													}
												else{
														cout<<"code dorost vared nashode ";
														getch();
														exit(0);
														}
												
											    //getch();
												break;
												}
										case 3:
											{
                                                list2.showt(ob);
                                                getch();
												list2.deletedars(ob);
												list2.moratab();
												getch();
												break;
												}
										case 4:
											{
												list2.virayesh1(ob);
												//getch();
												break;
												}
										case 5:
											{
												list2.showt(ob);
												getch();
												break;
												}

										case 6:
                                            {
                                                 cout<<"save ";
                                                 list2.save();
												 list3.save();
                                                 //getch();
                                                 break;
                                                 }	
										case 7:
											{
												cout<<"exit ";
												getch();
												exit(0);
											}
                                         case 10:
                                            {
                                                 er=0;
                                                 break;
                                                 }                                                           	
									           }
                                else
                                         { cout<<"id dorost nist";
                                         getch();
                                          exit(0);}
									
							}
						}
				else
					{
						system("cls");
					cout<<"pass eshtebah ast";
					getch();
						exit(0);
						}
					
			}		
		else
			{
				system("cls");
				cout<<"username dorost vared nashode";
				getch();
				exit(0);
				}
	}	
	getch();
	return 0;
}	
int menu1()
{
    
    system("color 0e");
	int n;
	cout<<"\n \n 1)vared kardan daneshjo";
	cout<<"\n 2)hazf daneshjo";
	cout<<"\n 3)search daneshjo";
	cout<<"\n 4)virayesh daneshjo";
	cout<<"\n 5)namayesh yek daneshjo";
	cout<<"\n 6)namayesh kol";
	cout<<"\n 7)save daneshjo";
	cout<<"\n 8)load daneshjo";
	cout<<"\n 9)vared kardan dars";
	cout<<"\n 10)hazf dars";
	cout<<"\n 11)search dars";
	cout<<"\n 12)virayesh dars";
	cout<<"\n 13)namayesh dars";
	cout<<"\n 14)namayesh kol dars ha";
	cout<<"\n 15)save dars";
	cout<<"\n 16)load dars";
	cout<<"\n 17)exit";
	cout<<"\n 20)bargasht";
	cout<<"\n \n"<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717);
	cout<<"\n yek meghdar vared kon = ";
	cin>>n;
	return n;
	}
int menu2()
{
    system("color 0e");
    int n;
	cout<<"\n \n 1)vared kardan daneshjoye shabane";
	cout<<"\n 2)hazf daneshjoye shabane";
	cout<<"\n 3)search daneshjoye shabane";
	cout<<"\n 4)virayesh daneshjoye shabane";
	cout<<"\n 5)namayesh yek daneshjoye shabane";
	cout<<"\n 6)namayesh kol";
	cout<<"\n 7)save daneshjoye shabane";
	cout<<"\n 8)load daneshjoye shabane";
	cout<<"\n 9)vared kardan dars";
	cout<<"\n 10)hazf dars";
	cout<<"\n 11)search dars";
	cout<<"\n 12)virayesh dars";
	cout<<"\n 13)namayesh dars";
	cout<<"\n 14)namayesh kol dars ha";
	cout<<"\n 15)save dars";
	cout<<"\n 16)load dars";
	cout<<"\n 17)exit";
	cout<<"\n 18)enter shahriye";
	cout<<"\n 20)bargasht";
	cout<<"\n \n"<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717)<<char(717);
	
	cout<<"\n yek meghdar vared kon = ";
	cin>>n;
	return n;
	}	
int menu3()
{
    system("color 0e");
   	int n;
	cout<<"\n \n 1)vahed mojaz baraye bardashtan";
	cout<<"\n 2)vared kardan dars";
	cout<<"\n 3)hazf dars";
	cout<<"\n 4)virayesh etelate khod";
	cout<<"\n 5)namayesh etelaat";
	cout<<"\n 6)svae";
	cout<<"\n 7)exit";
	cout<<"\n 10)bargasht";
	cout<<"\n \n"<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732);
    cout<<"\n yek meghdar vared konid = ";
	cin>>n;
	return n;
	}
int menu4()
{
    system("color 0e");
	int n;
	cout<<"\n \n 1)vahed mojaz baraye bardashtan";
	cout<<"\n 2)vared kardan dars";
	cout<<"\n 3)hazf dars";
	cout<<"\n 4)virayesh etelate khod";
	cout<<"\n 5)namayesh etelaat";
	cout<<"\n 6)svae";
	cout<<"\n 7)exit";
	cout<<"\n 10)bargasht";
    cout<<"\n \n"<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732)<<char(732);
    cout<<"\n yek meghdar vared konid = ";
	cin>>n;
	return n;
	}	 	

