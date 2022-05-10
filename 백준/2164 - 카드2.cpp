#include <iostream>
#include <deque>
using namespace std;
deque<int> card;
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		card.push_back(i+1);
	}
	int answer = 0;
	while(1){
		if(card.size()<=1){
			break;
		}
		card.pop_front();
		int n = card.front();
		card.pop_front();
		card.push_back(n);
	}
	cout<<card.front()<<"\n";
	return 0;
}
