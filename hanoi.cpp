#include<iostream>  //pass barname 1234 
using namespace std;
#include<conio.h>
#include<stdlib.h>
void hanoi(int ,char,char,char);
int main()
{
    system("color 1c");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t(borjhaye hanoi)";
    cout<<"\n\n\n\n\n\n\n\t\t\tpress any key to continue . . .";
    getch();
    system("cls"); 
    system("color 8e" );
    cout<<"\n    pass = ";
	char password[4];
	for(int i=0 ; i<4 ; i++)
	{
		password[i]=getche();
		
		cout<<char(8);
		cout<<"*";
    }
    cout<<endl;
    
    for(int i=0 ; i<4 ; i++)
          if(i=password[i]);
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\tpassword correct   ";
	getch();
	system("cls");
    int n;
    char a,b,c;
    cout<<"\t\t\t"<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<char(15)<<endl;
    cout<<"\n insert the page 1 = ";
    cin>>a;
    cout<<" insert the page 2 = ";
    cin>>b;
    cout<<" insert the page 3 = ";
    cin>>c; 
    cout<<" how many disk are on the <a> peg ? ";
    cin>>n;
    hanoi(n,a,b,c);
    
    _getch();
    return 0;
}
void hanoi(int n,char a,char b,char c)
{
     if(n==1)
             cout<<"\n\t mov disk "<<n<<" from page "<<a<<" to page "<<b;
     else
     {
         hanoi(n-1,a,c,b);
          cout<<"\n\t mov disk "<<n<<" from page "<<a<<" to page "<<b;
         hanoi(n-1,c,b,a);
         }
}                
    
    
