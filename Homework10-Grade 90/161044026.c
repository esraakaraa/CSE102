#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20//Array size
typedef struct stack{
	int data;
	struct stack *next;
}stack;

typedef struct queue{
	int data;
	struct queue *next;
}queue;
 
typedef struct bst{
	int data;
	struct bst *right;
	struct bst *left;
}bst;

void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]);
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search);
void special_traverse(stack * stack_, queue * queue_, bst * bst_);
void ordered_helper_bst(bst * bst_ , int *data);
int search_bst(bst *bst_ , int value);
void ordered_print(stack * stack_, queue * queue_, bst * bst_);
void ordered_print_bst(bst *bst_);
bst *insert_bst(int value,bst **temp);

int main(){
	int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};
	bst * bst_;
	queue * queue_;
	stack * stack_;

	fill_structures(&stack_, &queue_, &bst_, data);
	ordered_print(stack_, queue_, bst_); 
	search(stack_, queue_, bst_, 5); 
	special_traverse(stack_, queue_, bst_);
	return 0;
}
void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){ //This part is filled structures.
	int i = 0 , j = 0;
	double total_time_q , total_time_s , total_time_bst;
	clock_t begin , end;
	int swap;
	int temp[20];
	(*queue_) = NULL;
	(*stack_) = NULL;
	(*bst_) = NULL;
	stack * temp_stack;
	stack *head;
	stack *top;
	queue * temp_queue;

	(*stack_) = (stack *)malloc(sizeof(stack));
	(*queue_) = (queue *)malloc(sizeof(queue));

	temp_stack=*stack_;
	temp_queue=*queue_;
	for(i = 0 ; i < 80 ; i++){
		printf("-");
	}
	printf("\n\nFill Structures\n");
	begin = clock();
	for(i = 0 ; i < SIZE ; i++){
			(*queue_)->data = data[i];
			(*queue_)->next=(queue*)malloc(sizeof(queue));
			(*queue_) = (*queue_)->next;
	}

	(*queue_) = NULL;
	(*queue_)=temp_queue;
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);

	begin = clock();
	head=(*stack_);
	for (i = 0; i < SIZE; i++){	
		if(i==0){
			(*stack_)->data=data[i];
			(*stack_)->next=NULL;
		}
		else{
			top = malloc(sizeof(stack));
			top->data = data[i];
			top->next = head;
			head = top;
		}
	}
	(*stack_) = top;
	end = clock();
	total_time_s = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	

	begin = clock();

	for(i = 0 ; i < SIZE ; i++){
		*bst_=insert_bst(data[i],bst_);
	}

	end = clock();
	total_time_bst = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	printf("\nStructures\tStack\tQueue\tBST\nExec. Time\t%.3f\t%.3f\t%.3f\n\n" , total_time_s , total_time_q , total_time_bst);
	for(i = 0 ; i < 80 ; i++){
		printf("-");
	}
}

bst *insert_bst(int value,bst **temp){
	if((*temp) == NULL){
		bst *node_bst=(bst*)malloc(sizeof(bst));
		node_bst->data = value;
		node_bst->left=NULL;
		node_bst->right=NULL;
		return node_bst;
	}
	else{
		if(value == (*temp)->data){
			return (*temp);
		}
		if(value < (*temp)->data){
			(*temp)->left=insert_bst(value,&(*temp)->left);
			return (*temp);
		}
		if(value > (*temp)->data){
			(*temp)->right=insert_bst(value,&(*temp)->right);
			return (*temp);	
		}
	}
	return (*temp);
}

void ordered_print(stack * stack_, queue * queue_, bst * bst_){
	int i , j;
	int number;
	int swap;
	clock_t begin , end;
	double total_time_bst , total_time_s , total_time_q;
	stack *temp_stack;
	queue *temp_queue;
	temp_stack = stack_;

	printf("\n\nOrder Structures\n");
	begin = clock();
	for(i = 0 ; i < (SIZE-1) ; i++){
		for(j = 0 ; j < (SIZE-1) ; j++){
			if(stack_->data < stack_->next->data){

				swap = stack_->next->data;
				stack_->next->data = stack_->data;
				stack_->data = swap;
			}
			stack_ = stack_->next;
		}
		stack_ = temp_stack;
	}
	stack_ = temp_stack;

	printf("Stack :\t");
	while(stack_ != NULL){
		printf("%d  ", stack_->data );
		stack_ = stack_->next;
	}
	printf("\n");
	end = clock();
	total_time_s = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	
	begin = clock();
	temp_queue = queue_;
	for(i = 0 ; i < (SIZE-1) ; i++){
		for(j = 0 ; j < (SIZE-1) ; j++){
			if(queue_->data < queue_->next->data){

				swap = queue_->next->data;
				queue_->next->data = queue_->data;
				queue_->data = swap;
			}
			queue_ = queue_->next;
		}
		queue_ = temp_queue;
	}
	queue_ = temp_queue;

	printf("Queue :\t");
	for(i = 0 ; i < SIZE ; i++){
		printf("%d  ", queue_->data );
		queue_ = queue_->next;
	}
	printf("\n");
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	
	begin = clock();
	printf("BST : ");
	ordered_print_bst(bst_);
	printf("\n");
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);

	printf("\nStructures\tStack\tQueue\tBST\nExec. Time\t%.3f\t%.3f\t%.3f\n\n" , total_time_s , total_time_q , total_time_bst);

	for(i = 0 ; i < 80 ; i++){
		printf("-");
	}
}

void ordered_print_bst(bst *bst_){
    if (bst_ == NULL)
        return;

    ordered_print_bst(bst_->right);     
    printf("%d  ", bst_->data);      
    ordered_print_bst(bst_->left);    
}

void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search){
	int i;
	int count = 0;
	int result_bst;
	int flag = 28;
	clock_t begin , end;
	double total_time_bst , total_time_s , total_time_q;
	
	stack * temp_stack;
	queue * temp_queue;
	temp_stack=(stack *)malloc(sizeof(stack));
	temp_queue=(queue *)malloc(sizeof(queue));

	temp_stack = stack_;
	temp_queue = queue_;
	printf("\n\nSearch Structures\n");

	begin = clock();
	for(i = 0 ; i < (SIZE-1) ; i++){
		if(temp_stack->data != val_to_search){
			temp_stack = temp_stack->next;
		}
		else{
			flag = 5;
			printf("%d result founded on %d. step.(stack)\n", temp_stack->data , (i+1));
			temp_stack = temp_stack->next;
			count++;
		}
	}
	if(flag!=5){
		printf("There isn't the number.\n");
	}
	count = 0;
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);

	begin = clock();
	for(i = 0 ; i < SIZE ; i++){
		if(temp_queue->data != val_to_search){
			temp_queue = temp_queue->next;
		}
		else{
			flag = 5;
			printf("%d result founded on %d. step.(queue)\n", temp_queue->data , ((SIZE-1) - i));
			temp_queue = temp_queue->next;
			count++;
		}
	}
	if(flag!=5){
		printf("There isn't the number.\n");
	}
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);

	begin = clock();
	result_bst = search_bst(bst_, val_to_search);

	if(result_bst == 1){
		printf("%d result founded.(bst)\n\n", val_to_search);
	}
	else if(result_bst == 0){
		printf("There isn't the number.\n\n");
	}
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	printf("Structures\tStack\tQueue\tBST\nExec. Time\t%.3f\t%.3f\t%.3f\n\n" , total_time_s , total_time_q , total_time_bst);

	for(i = 0 ; i < 80 ; i++){
		printf("-");
	}
}
int search_bst(bst *node_bst , int value ){//We use this function for search bst. This function is a recursive function. 
	if(node_bst == NULL)
		return 0;
	if(node_bst->data == value)
		return 1;
	if(search_bst(node_bst->left,value)==1)
		return 1;
	if(search_bst(node_bst->right,value)==1)
		return 1;
	return 0;
}

void special_traverse(stack * stack_, queue * queue_, bst * bst_){
	int i = 0, j = 0;
	clock_t begin , end;
	double total_time_bst , total_time_s , total_time_q;
	stack *temp_stack;
	queue *temp_queue;
	printf("\n\nSpecial Traverse\nStack : ");
	begin = clock();
	while(i < 10){
		j = 0;
		temp_stack = stack_;
		for(j = 0 ; j < i ; j++){
			temp_stack = temp_stack->next;
		}
		printf("%d  " , temp_stack->data);

		temp_stack = stack_;
		for(j = 0 ; j < ((SIZE-1) - i) ; j++){
			temp_stack = temp_stack->next;
		}
		printf("%d  " , temp_stack->data);
		i++;
	}
	end = clock();
	total_time_s = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	i = 0;
	printf("\nQueue : ");
	begin = clock();
	while(i < 10){
		j = 0;
		temp_queue = queue_;
		for(j = 0 ; j < i ; j++){
			temp_queue = temp_queue->next;
		}
		printf("%d  " , temp_queue->data);

		temp_queue = queue_;
		for(j = 0 ; j < (19 - i) ; j++){
			temp_queue = temp_queue->next;
		}
		printf("%d  " , temp_queue->data);
		i++;
	}
	end = clock();
	total_time_q = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	printf("\n\nStructures\tStack\tQueue\tBST\nExec. Time\t%.3f\t%.3f\t%.3f\n\n" , total_time_s , total_time_q , total_time_bst);
	for(i = 0 ; i < 80 ; i++){
		printf("-");
	}
	printf("\n");
}