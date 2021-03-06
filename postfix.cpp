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
//1+2*3/4 == 1234/*+
class postfix: public stack
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
			default : if (st.top==-1) return 0;
		}
	}

	postfix(){
		cout<<"enter no. of operands & infix exp : "; cin>>n;
		  cin>>exp;
	}
	
	void convert(){
		for (int i = 0; i < n; i++)
		{
			if(exp[i]>'0' && exp[i]<'9')	
				cout<<"out.push  "<<out.push(exp[i])<<endl;
			else
			{	
				if (pre(exp[i])>pre(st.a[top]))
					cout<<"st.push  "<<st.push(exp[i])<<endl;
				else while(pre(exp[i])<=pre(st.a[top]))
					cout<<"out.push2  "<<out.push(st.pop())<<endl;
			}
		}
		while(st.top>=0)
			cout<<"out.pushF  "<<out.push(st.pop());
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
