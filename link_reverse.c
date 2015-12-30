#include <stdio.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node* next;
}Node;

Node *head=NULL, *tail=NULL;
int num=0;
void addNode(datatype data){
	Node *n = new Node();
	n->data = data;
	n->next = NULL;
	if(head==NULL){
		head=n;
		tail=n;
	}
	else{
		tail->next = n;
		tail=n;
	}
}

Node* reverse(Node* link){
	Node *pre=NULL, *cur=link, *next;
	next=cur->next;
	while(next!=NULL){
		cur->next = pre;
		pre = cur;
		cur=next;
		next=cur->next;
	}
	cur->next=pre;
	return cur;
}

int main(){
	Node *tmp;
	//建议还是建一个空节点好些
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	
	tmp = head;
	while(tmp!=NULL){
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	putchar('\n');
	head = reverse(head);
	tmp = head;
	while(tmp!=NULL){
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	scanf("%d", &num);
	return 0;
}