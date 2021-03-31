#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};
int n;

istream& operator>>(istream& is,node* &head){
	if(n == 0){
		head = NULL;
		return is;
	}
	int d;
	cin>>d;
	head = new node(d);
	node* temp = head;
	// cin>>d;
	int i = n-1;
	while(i--){
		cin>>d;
		temp->next = new node(d);
		temp = temp->next;
		// cin>>d;
	}
	return is;
}
ostream& operator<<(ostream& os,node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return os;
}
void rec_rev(node* head,node*&H){
	if(head == NULL or head->next == NULL){
		H = head;
		return;
	}
	rec_rev(head->next,H);
	head->next->next = head;
	head->next = NULL;
}
node* rec_rev(node* head){
	if(head == NULL or head->next == NULL){
		return head;
	}
	node* temp = rec_rev(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}
void rev(node*&H,int k){
	node *p,*n,*c;
	p = NULL;
	c = H;
	n = H;
	while(c!=NULL and k>0){
		n = n->next;
		c->next = p;
		p = c;
		c = n;
		k--;
		cout<<"yo\n";
	}
}
bool removeCycle(node* head, node* f){
    node* s = head;
    node* temp = f;
    while(s!=f){
        s = s->next;
        f = f->next;
    }
    // cout<<f->data<<endl;
    while(temp->next != f){
        temp = temp->next;
    }
    // cout<<head->next->data<<" "<<head->data<<endl;
    temp->next = NULL;
    return 1;
}
bool floydCycleRemoval(node *head)
{
    /* Code here */
    bool flag = 0;
    node* s, *f;
    s = f = head;
    while(f!= NULL and f->next!= NULL){
        s = s->next;
        f = f->next->next;
        if(s == f){
            flag = 1;
            break;
        }
    }
    if(flag)
        return removeCycle(head,f);
    return 0;
}

node* kthLast(node* head, int k){
	node* s,*f;
	s = f = head;
	for(int i=0;i<k;i++){
		if(f == NULL)
			return NULL;
		f = f->next;
	}
	while(f){
		f = f->next;
		s = s->next;
	}
	return s;
}
int len(node* head){
	int ans = 0;
	while(head){
		ans++;
		head = head->next;
	}
	return ans;
}

bool isPalindrome(node* head){
	node* front, *end;
	front = head;
	end = kthLast(head,1);
	int n = len(head);
	for(int i=0;i<n/2;i++){
			// cout<<front->data<<" "<<end->data<<endl;
		if(front->data != end->data){
			return 0;
		}
		front = front->next;
		end = kthLast(head,i+2);
	}
	return 1;
}

node* merge(node* h1, node* h2){
	if(h1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	if(h1->data < h2->data){
		h1->next = merge(h1->next,h2);
		return h1;
	}
	h2->next = merge(h1,h2->next);
	return h2;
}

void kAppend(node*& head, int k){
	node* temp = kthLast(head,k+1);
	if(temp == NULL)
		return;
	node* h = temp->next;
	temp->next = NULL;
	temp = h;
	while(temp->next)
		temp = temp->next;
	temp->next = head;
	head = h;
}
void insertAtEnd(node* & head, node* d){
	d->next = NULL;
	if(head == NULL){
		head = d;
		return;
	}
	node* t = head;
	while(t->next){
		t = t->next;
	}
	t->next = d;
}
void evenAfterOdd(node* &head){
	if(head == NULL or head->next == NULL)
		return;
	node* h1 = head, *h2 = NULL;
	while(h1->next != NULL){
		if(!(h1->next->data&1)){
			node* temp = h1->next->next;
			insertAtEnd(h2,h1->next);
			h1->next = temp;
		}
		else
			h1 = h1->next;
	}
	if(!(head->data&1)){
		node* temp = head;
		head = head->next;
		temp->next = h2;
		h2 = temp;
	}
	h1->next = h2;
}
void insertionSort(node*&head){
	node* i = head;
	node* h = NULL;
	while(i){
		if(h == NULL){
			h = i;
			i = i->next;
			h->next = NULL;
		}
		else{
			if(h->data >= i->data){
				node* temp = i;
				i = i->next;
				temp->next = h;
				h = temp;
			}
			else{
				node* temp = h->next,*prev = head;
				while(temp!= NULL and temp->data < i->data){
					prev = temp;
					temp = temp->next;
				}
				prev->next = i;
				i = i->next;
				prev->next->next = temp;
			}
		}
	}
	head = h;
}

int main() {
	cin>>n;
	node* head;
	cin>>head;
	// evenAfterOdd(head);
	insertionSort(head);
	// int k;
	// cin>>k;
	// kAppend(head,k);
	cout<<head;
	return 0;
}