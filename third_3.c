#include "third_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creat_new(P_Node head, int number){
	int i = 0;
	P_Node new = NULL;
	P_Node now = NULL;

	new = (Node *)malloc(sizeof(Node));
	if (new == NULL) return;
	memset(new, 0, sizeof(Node));

	head->next = new;
	now = new;

	for (i = 1; i < number+1; ++i){
		new = (Node *)malloc(sizeof(Node));
		if (new == NULL) return;
		memset(new, 0, sizeof(Node));
		
		if (i == 1) head->next = new;

		new->data = i;
		new->next = NULL;
		printf("new:%p,%d,%p\n",new,new->data,new->next);
		
		now->next = new;
		printf("now:%p,%d,%p\n",now,now->data,now->next);
		now = now->next;
		printf("now:%p,%d,%p\n",now,now->data,now->next);
	}

	now->next = head->next;
}

P_Node  delete(P_Node head, P_Node start, int target){
	int i = 0;
	P_Node p = start;
	P_Node t = NULL;
	P_Node d = NULL;

	for (i = 0; i<target-1; ++i) {
		t = p;
		p = p->next;
	}

	d = p;

	t->next = p->next;
	
	if (d == head->next) head->next = t->next;
	free(d);

	return t->next;
}

void disp(P_Node head){
	P_Node h = head->next;
	unsigned char safe = 0;
	
	printf("%d\t", h->data);
	h = h->next;

	while (h != head->next && --safe ) {
		//printf("h:%p,%d,%p\n",h,h->data,h->next);
		printf("%d\t", h->data);
		h = h->next;
	}
	
	printf("\n");
}

int main(){
	unsigned int safe = 0;
	
	P_Node p = NULL;
	Node head;
	head.data = 0;

	creat_new(&head,5);
	p = head.next;
	printf("head:%d\n",p->data);
	disp(&head);
	
	while (head.next->next != head.next && --safe) {
		p = delete(&head,p,2);
		printf("head:%d\n",p->data);
		disp(&head);
	}
	
	return 0;
}
