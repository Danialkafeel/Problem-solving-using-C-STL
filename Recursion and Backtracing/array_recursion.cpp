#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void inc(int n){
	if(n == 0){
		return;
	}
	inc(n-1);
	cout<<n<<" ";
}
void dec(int n){
	if(n == 0)
		return;
	cout<<n<<" ";
	dec(n-1);
}
int firstOcc(int* arr, int n, int key){
	if(n == 0)
		return -1;
	if(arr[0] == key)
		return 0;
	int ind = firstOcc(arr+1,n-1,key);
	if(ind == -1)
		return -1;
	return 1+ind;
}

int lastOcc(int* arr, int n, int key){
	if(n == 0)
		return -1;
	int ind = lastOcc(arr+1,n-1,key);
	if(ind != -1){
		return 1+ind;
	}
	if(arr[0] == key){
		return 0;
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	firstOcc(arr,n,k);
	return 0;
}