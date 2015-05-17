#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

void disp(Node * head){
	while (head->next != NULL) {
		printf("%d\n",head->data);
		head = head->next;
	}
	printf("%d\n",head->data);
}

void creat_new(Node ** node) {
    *node = (Node *)malloc (sizeof (Node));
}

Node * roll(Node ** p_head){
	Node * p_pre = (*p_head);
	Node * p_now = (*p_head)->next;

	if (p_now == NULL || p_pre == NULL) return p_pre;
	
	while (p_now->next != NULL) {
		//printf("DEBUG:now->next=%p\n",p_now->next);
		//printf("DEBUG:hea->next=%p\n",(*p_head)->next);
		(*p_head)->next = p_now->next;
		p_now->next = p_pre;
		p_pre = p_now;
		p_now = (*p_head)->next;
	}

	p_now->next = p_pre;
	(*p_head)->next = NULL;
	return p_now;
}

int main(){

//	int i = 0;
	Node *head = NULL;
	Node *p = NULL;
	Node *new = NULL;
	
	for (int i = 0; i<5; ++i) {
		creat_new(&new);
		new->data = i;
		if (i == 0){
			head = new;
			p = new;
			new->next = NULL;
		}
		else {
			p->next = new;
			new->next = NULL;
			p = new;
		}
	}

	printf("before\n");
	disp(head);

	head = roll(&head);

	printf("now\n");
	disp(head);

	return 0;
}
