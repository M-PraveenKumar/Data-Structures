#include <iostream>
using namespace std;
int main(){
  int rank[50], l[50], n, count=0; cin>>n;
  for (int i = 1; i < n; i++)
  	cin>>l[i];
  for (int i=1 ;i<n; i++){
    count=0;
    for (int j=1; j<n; j++)
      if (l[i]==l[j])
        count+=1;
    rank[i]=count;
	}
    for (int i = 1; i < n; i++)
    	cout<<rank[i]<<" ";  
}

/*
def onehop(l):
  out=[]
  (i,j)=(0,0)
  for i in range(len(l)):
    for j in range(len(l)):
      if l[i][1]==l[j][0] and i!=j:
        if l[i][0]!=l[j][1]:
          out.append((l[i][0],l[j][1]))
  print out

def train(n):
  (srt,dest,no,i,persons)=([],[],[],0,[[]])
  for i in range(n):
	srt.append(input())
	dest.append(input())
	no.append(input())

def recc(n):
  for i in range(n):
    for j in range(n):
      if n==min(no):
        return 1
      if (n-i-j)==no[0]:
        persons[i].append(recc(n-i-j))
        persons[i].append(recc(j))
  print persons

def frequency(l):
  rank=[]
  count=0
  i=0
  j=0
  for i in range(0,len(l)):
    count=0
    for j in range(0,len(l)):
      if l[i]==l[j]:
        count+=1
    rank.append(count)
  print rank
  (minim, maxim, MAX, MIN) = (min(rank),max(rank), [], [])
  k=0
  for k in range(1,len(rank)):
    if rank[k] == maxim:
      if l[k] not in MAX:
        MAX.append(l[k])
    if rank[k] == minim:
      if l[k] not in MIN:
        MIN.append(l[k])
  return sorted(MIN),sorted(MAX)*/