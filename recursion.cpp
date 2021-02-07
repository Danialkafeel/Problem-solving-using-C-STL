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
long long power(int a, int n){	// a^n = a * a^n-1;
	return n==0?1ll:a*power(a,n-1);
}

int fast_pow(int a , int n){
	if(n == 0)
		return 1;
	if(n&1){
		return a*fast_pow(a,n-1);
	}
	int temp = fast_pow(a,n/2);
	return temp*temp;
}
int bin_search(int *arr,int s,int e,int key){
	if(s > e)
		return -1;
	int mid = (s+e)>>1;
	cout<<"mid = "<<mid<<endl;
	if(arr[mid] == key){
		return mid;
	}
	if(arr[mid] > key){
		return bin_search(arr,s,mid-1,key);
	}
	return bin_search(arr,mid+1,e,key);
}
int multiply(int a,int b){
	if(a == 0 or b == 0)
		return 0;
	return b==1?a:a+multiply(a,b-1);
}

void numtoSpell(int n){
	if(n/10 == 0){
		cout<<n<<" ";
		return;
	}
	numtoSpell(n/10);
	cout<<n%10<<" ";
}
int strToInt(string str){
	if(str == "")
		return 0;
	string temp = str;
	temp.pop_back();
	return 10*strToInt(temp)+str[str.size()-1] - '0';
}
int tiles_problem(int n){
	if(n>3){
		return tiles_problem(n-1)+tiles_problem(n-4);
	}
	else
		return 1;
}
int ladder_problem(int n){
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 4;
	return ladder_problem(n-1)+ladder_problem(n-2)+ladder_problem(n-3);
}
int noConsecutive1s(int n){
	if(n==0)
		return 0;
	if(n == 1 or n==2)
		return n+1;
	return noConsecutive1s(n-1)+noConsecutive1s(n-2);
}
vector<string> subs;
void subsets(char* str,int i, char* out, int j){
	if(str[i] == '\0'){
		out[j] = '\0';
		// cout<<out<<endl;
		subs.pb(out);
		return;
	}
	subsets(str,i+1,out,j);
	out[j++] = str[i];
	subsets(str,i+1,out,j);
}
void brackets(int n, int m, char* out, int i){
	if(n == 0){
		for(int j=0;j<m;j++)
			out[i++] = ')';
		out[i] = '\0';
		cout<<out<<endl;
		return;
	}
	// if(m == 0){
	// 	return;
	// }
	if(n == m){
		out[i] = '(';
		brackets(n-1,m,out,i+1);
	}
	else{
		out[i] = '(';
		brackets(n-1,m,out,i+1);
		out[i] = ')';
		brackets(n,m-1,out,i+1);
	}
}
int rec_01Knapsack(int cap, int* price, int* wt, int n){
	if(n == 0 || cap==0)
		return 0;
	int inc=0,exc=0;
	if(cap >= wt[0]){
		inc = price[0]+rec_01Knapsack(cap-wt[0],price+1,wt+1,n-1);
	}
	exc = rec_01Knapsack(cap,price+1,wt+1,n-1);
	return max(inc,exc);
}
void keypad(int* arr, int n, char* out, int ind){
	if(n == 0){
		out[ind] = '\0';
		cout<<out<<endl;
		return;
	}
	switch(arr[0]){
		case 0:{
			out[ind] = ' ';
			return	keypad(arr+1,n-1,out,ind+1);
		}
		case 1:{
			out[ind] = '.';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = '+';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = '@';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = '$';
			keypad(arr+1,n-1,out,ind+1);			
			break;
		}
		case 2:{
			out[ind] = 'a';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'b';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'c';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 3:{
			out[ind] = 'd';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'e';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'f';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 4:{
			out[ind] = 'g';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'h';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'i';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 5:{
			out[ind] = 'j';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'k';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'l';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 6:{
			out[ind] = 'm';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'n';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'o';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 7:{
			out[ind] = 'p';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'q';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'r';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 's';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 8:{
			out[ind] = 't';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'u';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'v';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
		case 9:{
			out[ind] = 'w';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'x';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'y';
			keypad(arr+1,n-1,out,ind+1);
			out[ind] = 'z';
			keypad(arr+1,n-1,out,ind+1);
			break;
		}
	}
}
char alph[] = {'a','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void gen_strings(char* str,char* out, int ind){
	if(str[0] == '\0'){
		out[ind] = '\0';
		cout<<out<<endl;
		return;
	}
	if(str[0] == '1'){
		out[ind] = 'A';
		gen_strings(str+1,out,ind+1);
		if(str[1] != '\0'){
			out[ind] = alph[10+str[1]-'0'];
			gen_strings(str+2,out,ind+1);
		}
	}
	else if(str[0] == '2'){
		out[ind] = 'B';
		gen_strings(str+1,out,ind+1);
		if(str[1] != '\0' and str[1] >= '0' and str[1] <='6'){
			out[ind] = alph[20+str[1]-'0'];
			gen_strings(str+2,out,ind+1);
		}
	}
	else{
		out[ind] = alph[str[0]-'0'];
		gen_strings(str+1,out,ind+1);
	}
}
void permute(char* in, int i, set<string> &s){
	if(in[i] == '\0'){
		// cout<<in<<" ";
		s.insert(in);
		return;
	}
	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		permute(in,i+1,s);
		swap(in[i],in[j]);
	}
}
bool check(int board[][10],int row, int col,int n){
	for(int i=0;i<n;i++){
		if(board[i][col])
			return false;
	}
	int i = row-1, j = col-1;
	while(i>=0 and j>=0){
		if(board[i][j])
			return false;
		i--;	j--;
	}
	i = row-1;	j = col+1;
	while(i>=0 and j<n){
		if(board[i][j])
			return false;
		i--;	j++;
	}
	return true;
}
bool NQueens(int board[][10],int i,int n){
	if(i == n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		return 0;
	}
	for(int j=0;j<n;j++){
		if(check(board,i,j,n)){
			board[i][j] = 1;	//	Place the queen assuming it is the right position
			bool succ = NQueens(board,i+1,n);
			if(succ){
				return 1;
			}
			board[i][j] = 0;	// Assumption was wrong and backtrack.
		}
	}
	return 0;	// Tried to place in each cell of the current row, but couldn't.
}

bool isSorted(int* arr, int n){
	if(n==1)
		return 1;
	if(arr[0] > arr[1])
		return 0;
	return isSorted(arr+1,n-1);
}
int all_ind(int* arr, int n, int* out,int i,int j, int m){
	if(n == i)
		return j;
	if(arr[i] == m){
		out[j] = i;
		return all_ind(arr,n,out,i+1,j+1,m);
	}
	return all_ind(arr,n,out,i+1,j,m);
}
void moveXtoEnd(char* s,char* out,int i,int j,int k){
	if(s[k] == '\0'){
		out[k] = '\0';
		return;
	}
	if(s[k] != 'x'){
		out[i] = s[k];
		return moveXtoEnd(s,out,i+1,j,k+1);
	}
	out[j] = 'x';
	moveXtoEnd(s,out,i,j-1,k+1);
}
bool subset_sum_0(int* arr,int n,int i, int sum,bool present){
	if(sum == 0 and present)
		return true;
	if(i == n){
		return false;
	}
	bool b = subset_sum_0(arr,n,i+1,sum,0||present);
	bool a = subset_sum_0(arr,n,i+1,sum+arr[i],1);
	if(a or b)
		return true;
	return false;
}
bool check_sudoku(int arr[][18],int n,int row,int col, int num){
	for(int i=0;i<n;i++){
		if(arr[row][i] == num)
			return false;
		if(arr[i][col] == num)
			return false;
	}
	int gridRow = row/sqrt(n);
	int gridCol = col/sqrt(n);
	// cout<<"=============\n";
	for(int i=gridRow*sqrt(n);i<gridRow*sqrt(n)+sqrt(n);i++)
		for(int j=gridCol*sqrt(n);j<gridCol*sqrt(n)+sqrt(n);j++){
			// cout<<i<<" "<<j<<endl;
			if(arr[i][j] == num)
				return false;
		}
	return true;
}

bool sudoku_solver(int arr[][18],int n,int row, int col){	
	if(row == n)
		return true;
	if(col == n)
		return sudoku_solver(arr,n,row+1,0);
	if(arr[row][col] != 0)
		return sudoku_solver(arr,n,row,col+1);
	for(int i=1;i<=9;i++){
		if(check_sudoku(arr,n,row,col,i)){
			arr[row][col] = i;
			// cout<<"now ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			// for(int i=0;i<n;i++){
			// 	for(int j=0;j<n;j++)
			// 		cout<<arr[i][j]<<" ";
			// 	cout<<endl;
			// }
			if(sudoku_solver(arr,n,row,col+1))
				return true;
		}
		// else
		// 	cout<<"couldn't place "<<i<<" on "<<row<<","<<col<<endl;
	}
	arr[row][col] = 0;
	return false;
}
bool rat_maze(char **maze,int n, int m,int row,int col){
	if(row == n-1 && col == m-1)
		return true;
	if(col+1 < m && maze[row][col+1] != 'X'){
		maze[row][col+1] = '1';
		if(rat_maze(maze,n,m,row,col+1))
			return true;
		maze[row][col+1] = 'O';
	}
	if(row+1 < n && maze[row+1][col] != 'X'){
		maze[row+1][col] = '1';
		if(rat_maze(maze,n,m,row+1,col))
			return true;
		maze[row+1][col] = 'O';
	}
	return false;
}
void print(char** maze,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<maze[i][j]<<" ";
		cout<<endl;
	}
	cout<<"--------------------\n";
}
bool rat_maze_all_directions(char** maze,int n, int m,int row, int col){
	// cout<<"row,col = "<<row<<" "<<col<<endl;
	print(maze,n,m);
	if(row == n-1 && col == m-1)
		return true;
	if(col+1 < m && maze[row][col+1] == 'O'){
		maze[row][col+1] = '1';
		if(rat_maze_all_directions(maze,n,m,row,col+1))
			return true;
		maze[row][col+1] = 'O';
	}
	if(row+1 < n && maze[row+1][col] == 'O'){
		maze[row+1][col] = '1';
		if(rat_maze_all_directions(maze,n,m,row+1,col))
			return true;
		maze[row+1][col] = 'O';
	}
	if(col-1 >=0 && maze[row][col-1] == 'O'){
		maze[row][col-1] = '1';
		if(rat_maze_all_directions(maze,n,m,row,col-1))
			return true;
		maze[row][col-1] = 'O';
	}
	if(row-1 >=0 && maze[row-1][col] == 'O'){
		maze[row-1][col] = '1';
		if(rat_maze_all_directions(maze,n,m,row-1,col))
			return true;
		maze[row-1][col] = 'O';
	}
	return false;
}

int main(){
	char ** maze;
	int n,m;
	cin>>n>>m;
	maze = new char*[n];
	for(int i=0;i<n;i++){
		maze[i] = new char[m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>maze[i][j];
	if(maze[0][0] == 'X'){
		cout<<"NO PATH FOUND\n";
		return 0;
	}
	maze[0][0] = '1';

	if(!rat_maze_all_directions(maze,n,m,0,0)){
		cout<<"NO PATH FOUND\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			maze[i][j]=='1'?cout<<"1 ":cout<<"0 ";
		}
		cout<<endl;
	}
	return 0;
}

/*
5 4
OOOO
XXXO
OOOO
OXXX
OOOO

10 10
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO 
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
XXXXXXXXXX

*/