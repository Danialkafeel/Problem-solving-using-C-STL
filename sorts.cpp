#include<bits/stdc++.h>
using namespace std;

void bubble(int * arr,int n){
	for(int i=0;i<n-1;i++){
		bool flag = 0;
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				flag = 1;
				swap(arr[j],arr[j+1]);
			}
		}
		if(flag == 0)
			break;
	}
}

void insertion(int * arr,int n){
	for(int i=1;i<n;i++){
		// cout<<"i = "<<i<<endl;
		int key = arr[i];
		int j = i-1;
		while(arr[j]>key){
			arr[j+1] = arr[j];
			j--;
			if(j < 0)
				break;
		}
		arr[j+1] = key;
	}
}

void selection(int* arr,int n){
	for(int i=0;i<n-1;i++){
		int mini = arr[i];
		int min_ind = i;
		for(int j=i+1;j<n;j++){
			if(arr[j] < mini){
				mini = arr[j];
				min_ind = j;
			}
		}
		swap(arr[i],arr[min_ind]);
	}
}

int  main(){
	
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}

	bubble(arr,n);
	// insertion(arr,n);
	// selection(arr,n);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\n";
	// cout<<endl;
	return 0;
}