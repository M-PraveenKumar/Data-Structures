#include <iostream>
using namespace std;
class XO
{
char a[10][10];
int n,x,y;
public:
	void work(){
		cin>>n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j]='_';

		for(int i = 0; i < n*n; )
		{
			cout<<"\nenter pos: ";
			cin>>x>>y;
			if(a[x][y]!='O' || a[x][y]!='X')
			{
				a[x][y]='X';
				++i;
			}
			else cout<<"An element already exists in that location. Try with another position\n";
			
			if(a[x+1][y+1]!='X')
			{
				a[x+1][y+1]='O';
				++i;
			}
			else if(a[x-1][y-1]!='X')
			{
				a[x-1][y-1]='O';
				++i;
			}
			else if(a[x-1][y+1]!='X' )
			{
				a[x-1][y+1]='O';
				++i;
			}
			else if(a[x+1][y-1]!='X'){
				a[x+1][y-1]='O';
				++i;
			}
			display();
		}	
	}
	void display()
	{	
		for (int i = 0; i < n; ++i)
		{	
			for (int j = 0; j < n; ++j)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}	
};

int main(){
	XO xo;
	xo.work();
}