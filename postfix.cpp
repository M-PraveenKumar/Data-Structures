#include <iostream>
using namespace std;

class stack
{
public:
	int top, a[15];
	stack(){ top=-1;}
	void push(int x){a[top]=x;  top++;}
	int pop(){top--; return a[top+1];}
	void display(){for (int i=top; i>0; i--) cout<<a[i]<<" ";}
};

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
				out.push(exp[i]);
			else
			{
				if (pre(exp[i])>pre(st.top) )
					st.push(exp[i]);
				else{
					while(pre(exp[i])>pre(st.top))
						out.push(st.pop());
				}
			}
		}
	}

	void display(){
		out.display();
	}
};

int main(){
	postfix p;
	p.convert();
	p.display();	
}
