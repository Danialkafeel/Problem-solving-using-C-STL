#include<iostream>
#include<stack>
using namespace std;

template <typename T>
class queue
{
	stack<T> s1,s2;
public:
	void enque(T data){
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(data);
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
	}
	T deque(){
		T d = s2.top();
		s2.pop();
		return d;
	}
	bool empty(){
		return s2.size() == 0;
	}
};

int main() {
	int n;
	cin>>n;
	queue<int> q;
	for(int i=0;i<n;i++)
		q.enque(i);
	while(!q.empty()){
		cout<<q.deque()<<" ";
	}
	cout<<endl;
	return 0;
}