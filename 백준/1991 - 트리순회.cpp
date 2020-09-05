#include <iostream>
#include <vector>

using namespace std;

char in[26][2];
int n;

void preorder(char head){
	if(head=='.') return;
	else{
		cout<<head;
		preorder(in[head-'A'][0]);
		preorder(in[head-'A'][1]);
	}
}

void inorder(char head){
	if(head=='.') return;
	else{
		inorder(in[head-'A'][0]);
		cout<<head;
		inorder(in[head-'A'][1]);
	}
}

void postorder(char head){
	if(head=='.') return;
	else{
		postorder(in[head-'A'][0]);
		postorder(in[head-'A'][1]);
		cout<<head;
	}
}

int main(void){
	cin>>n;
	in[0][0] = -1;
	for(int i=0;i<n;i++){
		char a,b,c;
		cin>>a>>b>>c;
		in[a-'A'][0] = b;
		in[a-'A'][1] = c;
	}
	preorder('A');
	cout<<"\n";
	inorder('A');
	cout<<"\n";
	postorder('A');
	cout<<"\n";	
	return 0;
}
