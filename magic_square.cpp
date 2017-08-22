#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a[10][10], n;
	cout<<"enter n: "; cin>>n;
	cout<<"sum of horizontal, vertical and diagonals is"<<n*(pow(n,2)+1)/2<<endl;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j]=0;
	int x=0, y=n/2;
	a[x][y]=1;
	for (int i = 1; i < n*n; )
	{
		if(x<0){
			x=n-1;
			a[x][++y]=i;
			++i;
		}
		else if(y>=n){
			y=0;
			a[--x][y]=i;
			++i;
		}
		else if(a[x-1][y+1]!=0)
			{a[++x+1][--y]=i;  ++x; ++i;}
		while(a[x-1][y+1]==0 )
		{	
			a[--x][++y]=i;
			++i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}