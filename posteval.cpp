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
class postfix: public stack
{
	char exp[15];
	stack st;
	int n;
public:
	postfix(){ cout<<"enter n: "; cin>>n; cout<<"\nenter postfix exp : "; cin>>exp; }
	void eval(){
		for (int i = 0; i < n; i++)
		{
			if(exp[i]>='0' && exp[i]<='9')
				st.push(exp[i]);
			else{
				char v1=st.pop();
				char v2=st.pop();
				cout<<"c+d:"<<v1-'0'+v2-'0'<<endl;
				switch(exp[i]){
					case '+': cout<<st.push(v1-'0'+v2-'0'); break;
					case '*': st.push(v1*v2); break;
					case '-': st.push(v1-v2); break;
					case '/': st.push(v1/v2); break;
				}
			}
		}
		cout<<st.a[top];
	}
};

int main(){
	postfix p;
	p.eval();	
}
