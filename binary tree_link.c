/*
先动态创建二叉树，注意用到了先序遍历思想，且必须借助叶子节点的特点来唯一确定二叉树。中序遍历一次作为验证。
在动态将二叉树转换为双向链表，随后头尾遍历各遍历一次作为验证即可

*/

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node *lc, *rc;
}Node;

Node *root=NULL;
Node* createTree(){
	int temp;
	Node *n;
	scanf("%d", &temp);
	if(temp){
		n = (Node*)malloc(sizeof(Node));
		n->data = temp;
		n->lc = createTree();
		n->rc = createTree();
		return n;
	}
	else{
		return NULL;
	}
}
void preTraversTree(Node *root){
	if(root == NULL)return;
	printf("%d ", root->data);
	preTraversTree(root->lc);
	preTraversTree(root->rc);
}
void inOrderTraversTree(Node *root){
	if(root == NULL)return;
	inOrderTraversTree(root->lc);
	printf("%d ", root->data);
	inOrderTraversTree(root->rc);
}

//把二分搜索树head转化为双向链表并返回链表头指针
Node* transferList(Node* head){
	Node *l, *r, *tmp;
	if(head == NULL)return NULL;
	
	//获取左子树转化后的双向链表
	l = transferList(head->lc);
	r = transferList(head->rc);
	head->rc = r;
	if(r!=NULL){
		r->lc=head;
	}
	tmp = l;
	if(tmp == NULL){
		head->lc = NULL;
	}
	else{
		while(tmp->rc!=NULL){
			tmp = tmp->rc;
		}
		head->lc = tmp;
		tmp->rc = head;
	}
	if(l == NULL)return head;
	else return l;
}

void traverseList(Node *n){
	Node *t;
	while(n != NULL){
		printf("<-%d->", n->data);
		t = n;
		n = n->rc;
	}
	putchar('\n');
	while(t != NULL){
		printf("<-%d->", t->data);
		t = t->lc;
	}
	putchar('\n');
}

int main(){
	char c = 'y';
	while(c == 'y'){
		root = createTree();
		inOrderTraversTree(root);
		putchar('\n');
		root = transferList(root);
		traverseList(root);
		printf("y or n? \n");
		scanf(" %c", &c);
	}
	
	return 0;
}