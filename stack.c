#include<stdio.h>
#include<stdlib.h>
struct item{
	int value;
	struct item* last;	
	struct item* next; 
};
struct item * bottem;
struct item * top;
int num;
int maxnum;
int initial(int len){
	//bottem = new struct item;
	//top = new struct item;
	bottem = malloc(sizeof(struct item));
	top = malloc(sizeof(struct item));	
	bottem->next = top;
	top->last = bottem;
	num = 0;	
	maxnum = len;
	
}
int push(int data){
	if (num==maxnum){
		printf("stack has been full, num is %d\n",num);	
		return 0;	
	}
	top->value = data;
	top->next = malloc(sizeof(struct item)); //new struct item;
	top->next->last = top;
	top = top->next;
	num = num + 1;
	if (num == maxnum){
		printf("stack is full\n");
	}else{
		printf("stack is not full\n");
	}
	
}
int pop(){
	if (num==0){
		printf("stack has been empty\n");
		return 0;	
	}	
	printf("top value is %d\n",top->last->value);
	top=top->last;
	//delete top->next;
	free(top->next);	
	num--;
	if (num==0){
		printf("stack is empty\n");	
	}

}

int main(){
	initial(5);
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	printf("hello world\n");
}
