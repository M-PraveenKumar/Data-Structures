#include <iostream>
using namespace std;

class stack
{
public:
	int top;
	char a[15];
	stack(){ top=-1;}
	char push(char x){a[++top]=x; return a[top];}
	char pop(){ return a[top--]; }
	void display(){ for (int i=0; i<=top; i++) cout<<a[i]<<" ";}
};
//1234/*5-+
class postfix
{
	char exp[15];
	stack st, out;
	int n;
public:
	int pre(char c){
		switch(c){
			case '+': 
			case '-': return 1;
			case '*': 
			case '/': return 2;
		}
	}

	postfix(){
		cout<<"enter no. of operands & infix exp : "; cin>>n;
		for (int i = 0; i < 2*n-1; i++)  cin>>exp[i];
	}
	
	void convert(){
		for (int i = 0; i < n; i++)
		{
			if(exp[i]>'0' && exp[i]<'9')	
				cout<<"out.push  "<<out.push(exp[i])<<endl;
			else
			{	
				if (pre(exp[i])<=pre(st.top))
					cout<<"st.push  "<<st.push(exp[i])<<endl;
				else
					{cout<<"out.push2  "<<out.push(st.pop())<<endl;}
			}
		}
	}

	void display(){
		st.display(); cout<<"\n";
		out.display();
	}
};

int main(){
	postfix p;
	p.convert();
	p.display();	
}
