#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13
typedef enum block_type{start=0,property,fortune,tax,punish}b_type;
typedef enum player_type{none=-1,car,cap}player_type;

typedef struct{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *player_name;
} player;
typedef struct fortune_card{
    int number;
    struct fortune_card *next;
}fortune_card;
typedef struct block
{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
    struct block *next; //for linked list
} block;

int roll_dice(){
    int i=rand()%5+1;
    return i;
}
void show_property_deed(block *board){
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    int count = 0;
    int exit_flag=0,i,j,selection;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        for(j = 0 ; j <= 23 ; j++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
            if (temp->type==property)
                printf("%d -\t%s \n",temp->id,temp->name);
                temp = temp->next;
        }
        temp = board;
        
        printf("0 -\tExit\n");
        scanf("%d",&selection);
        if (selection==0)
            exit_flag=1;
        else {
            for(j = 0 ; j < selection ; j++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
            //temp->next = (block*)malloc(sizeof(block));
                temp = temp->next;
            }
            if (selection > 0 && selection < 24 && temp->type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(temp->name) < 8)
                    printf("|\t\t%s\t\t|\n", temp->name);
                else
                    printf("|\t    %s\t\t|\n", temp->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", temp->rent);
                printf("|\tRent 1 H \t%d$\t|\n", temp->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", temp->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", temp->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", temp->house_price);
                printf("|\tHouse count \t%d\t|\n", temp->h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
            temp = board;
        }
    }
}
void return_show(block *board, int row){
    int k = 0 , m , l ;
    block *temp;
    temp = (block*)malloc(sizeof(block)*2);
    temp = board;
    while(k != row){
        if(temp->next->id == row){
            m = strlen(temp->name) ;
            printf("|       %s",temp->name );
            for(l = 0 ; l < (17 - m) ; l++){
                printf(" ");
            }
        }
        temp = temp->next;
        k++;
    }
   // free(temp);
}
int find_length(block *board , int number){
    int k = 0;
    int counter = 1;
    while(board->id != number){
        if(board->next->id == number){
            if(board->next->price /10 > 0){
            counter++;
            }
        }
        board = board->next;
    }
    return counter;
}
void show_price(block *board, int number_block){
    int k = 0 , m , l;
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    while(k != number_block){
        if(temp->next->id == number_block){
            m = find_length(board ,number_block) ;
            printf("|       %d$",temp->next->price );
            for(l = 0 ; l < (13 - m) ; l++){
                printf(" ");
            }
        }
        temp = temp->next;
        k++;
    }
 //   free(temp);
}
void show_rent(block *board, int number_block){
    int k = 0 , m , l;
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    while(k != number_block){
        if(temp->next->id == number_block){

        temp = temp->next;
            m = find_length(board ,number_block) ;
            printf("|       %d$",temp->rent );
            for(l = 0 ; l < (14 - m) ; l++){
                printf(" ");
            }
        }
        k++;
        temp = temp->next;
        
    }
  //  free(temp);
}
void show9_13_17_21(block *board, int m , int n){
    
    block *head;
    head = (block*)malloc(sizeof(block));
    head = board;
    int l;
    return_show(board , m);
    printf("|");
    for(l = 0 ; l < 124 ; l++){
        printf(" ");
    }
    board = head;
    return_show(board, n);
    printf("|");
   // free(head);
}
void print_of_owner(block *board, player player_one, player player_two , int block_number){//helper function
    int i = 0 , j , k , l , m;
    int count = 0;
    for(i = 0 ; i < 2 ; i++){
        if(player_one.current_block_id == block_number || player_two.current_block_id == block_number){
            printf("|       ");
            if (player_one.current_block_id != player_two.current_block_id){
                if(player_one.current_block_id == block_number){
                    printf("%s",player_one.player_name );
                    for(l = 0 ; l < (17 - strlen(player_one.player_name)) ; l++){
                        printf(" ");
                    }
                }
                else if(player_two.current_block_id == block_number){
                    printf("%s",player_two.player_name );
                    for(l = 0 ; l < (17 - strlen(player_two.player_name)) ; l++){
                        printf(" ");
                    }
                }
                else{
                    for(l = 0 ; l < 17 ; l++){
                        printf(" ");
                    }
                }
            }
            else if(player_one.current_block_id == player_two.current_block_id){
                if(player_one.current_block_id == block_number){
                    printf("car  cap");
                }
                for(m = 0 ; m < 9 ; m++){
                    printf(" ");
                }
            }
            else{
                for(l = 0 ; l < 17 ; l++){
                    printf(" ");
                }
            }
                printf("|");
        }
        else{
            printf("|");
            for(l = 0 ; l < 24 ; l++){
                printf(" ");
            }
            printf("|");
            
        }
        if(count==0){
            for(l = 0 ; l < 124 ; l++){
                printf(" ");
            }
        }
        count++;
        if(block_number == 23){
            block_number = 7;
        }
        if(block_number == 22){
            block_number = 8;
        }
        if(block_number == 21){
            block_number = 10;
        }
        if(block_number == 20){
            block_number = 11;
        }
    }
}
void show_board(block *head, player player_one, player player_two){
    int i , k , l , m;
    int count = 0;
    int number;
    int count_price;
    int count_owner=0;
    int temp_row2 = 0 , len;
    block *board;
    board = (block*)malloc(sizeof(block));
    board = head;
    for(i = 0 ; i < 29 ;i++){
        if(i == 0  || i == 4 || i == 24 || i == 28){
            for(k = 0 ; k < 175 ; k++){
                printf("-");
            }
        }
        else if(i == 1){
            for(k = 0 ; k < 7 ; k++){
                printf("|       %s",board->name );
                for(l = 0 ; l < (17 - strlen(board->name)) ; l++){
                    printf(" ");
                }
                board = board->next;
            }
            printf("|");
            board = head;
        }
        else if(i == 2){
            for(k = 0 ; k < 7 ; k++){
                //printf("|");
                if(k == 0 || k == 3){
                    printf("|");
                    for(m = 0 ; m < 24 ; m++){
                        printf(" ");
                    }
                }
                else if(k == 6){
                    printf("|");
                    for(l = 0 ; l < 24 ; l++){
                        printf(" ");
                    }
                }
                else{
                    show_price(board, temp_row2);
                    if(k == 2)printf(" ");
                }
                temp_row2++;
                board = head;
            }
            printf("|");
        }
        else if(i == 3){
            for(k = 0 ; k < 7 ; k++){
                count_owner = 0;
                printf("|       ");
                if(player_one.current_block_id == k || player_two.current_block_id ==k){
                    if (player_one.current_block_id != player_two.current_block_id){
                        if(player_one.current_block_id == k){
                            printf("%s",player_one.player_name );
                            for(l = 0 ; l < (17 - strlen(player_one.player_name)) ; l++){
                                printf(" ");
                            count_owner++;
                            }
                        }
                        else if(player_two.current_block_id == k){
                            printf("%s",player_two.player_name );
                            for(l = 0 ; l < (17 - strlen(player_two.player_name)) ; l++){
                                printf(" ");
                            }
                        }
                        else{
                            for(l = 0 ; l < 17 ; l++){
                                printf(" ");
                            }
                        }
                    }
                    else if(player_one.current_block_id == player_two.current_block_id){
                        if(player_one.current_block_id == k){
                            printf("car  cap");
                        }
                        for(m = 0 ; m < 9 ; m++){
                            printf(" ");
                        }
                    }
                    else{
                        for(l = 0 ; l < 17 ; l++){
                            printf(" ");
                        }
                    }
                }
                else{
                for(m = 0 ; m < 17 ; m++){
                    printf(" ");
                }
                }
                //printf("|");
            }
        }
        else if(i == 25){
            board = head;
            for(k = 0 ; k < 7 ; k++){
                return_show(board , 19 - k);
                
            }
            printf("|");
        }
        else if(i == 26){
            board = head;
            temp_row2 = 18;
             for(k = 0 ; k < 7 ; k++){
                //printf("|");
                if(k == 0 ){
                    printf("|");
                    for(m = 0 ; m < 24 ; m++){
                        printf(" ");
                    }
                }
                else if(k == 4 || k == 6){
                    show_price(board, 18-k);
                    printf(" ");
                }
                else if(k == 3){
                    printf("|");
                    for(l = 0 ; l < 24 ; l++){
                        printf(" ");
                    }
                }
                else{
                    show_price(board, 18-k);
                }

            board = head;
            }
            printf("|");
        }
        else if(i == 27){
            for(k = 18 ; k > 11 ; k--){
                printf("|");
                printf("       ");
                if(player_one.current_block_id == k || player_two.current_block_id ==k){
                    if (player_one.current_block_id != player_two.current_block_id){
                        if(player_one.current_block_id == k){
                            printf("%s",player_one.player_name );
                            for(l = 0 ; l < (17 - strlen(player_one.player_name)) ; l++){
                                printf(" ");
                            }
                        }
                        else if(player_two.current_block_id == k){
                            printf("%s",player_two.player_name );
                            for(l = 0 ; l < (17 - strlen(player_two.player_name)) ; l++){
                                printf(" ");
                            }
                        }
                        else{
                            for(l = 0 ; l < 17 ; l++){
                                printf(" ");
                            }
                        }
                    }
                    else if(player_one.current_block_id == player_two.current_block_id){
                        if(player_one.current_block_id == k){
                            printf("car  cap");
                        }
                        for(m = 0 ; m < 9 ; m++){
                            printf(" ");
                        }
                    }
                    else{
                        for(l = 0 ; l < 17 ; l++){
                            printf(" ");
                        }
                    }
                }
                else{
                    for(m = 0 ; m < 17 ; m++){
                        printf(" ");
                    }
                }   
            }
            printf("|");
        }
        else if(i == 5){
            for(l = 0 ; l < 23 ; l++){
                board = board->next;
            }
            printf("|       %s",board->name );
            for(l = 0 ; l < (17 - strlen(board->name)) ; l++){
                printf(" ");
            }
            printf("|");
                for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            board = head;
            return_show(board, 8);
            printf("|");
        }
        else if(i == 9){
            board = head;
            show9_13_17_21(board, 23 , 9);
        }
        else if(i == 13){
            board = head;
            show9_13_17_21(board, 22 , 10);
        }
        else if(i == 17){
            board = head;
            show9_13_17_21(board, 21 , 11);
        }
        else if(i == 21){
            board = head;
            show9_13_17_21(board, 20 , 12);
        }
        else if(i == 6){
            board = head;
            for(l = 0 ; l < 23 ; l++){
                board = board->next;
            }
            printf("|       %d$",board->price );

            for(l = 0 ; l < (12 - find_length(board , 23)) ; l++){
                printf(" ");
            }
            printf("|");
                for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            board = head;
            show_price(board, 7);
            printf("|");
        }
        else if( i == 10){
            board = head;
            show_price(board, 22);
            printf(" ");
            printf("|");
            for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            board = head;
            show_price(board, 8);
            printf("|");
        }
        else if(i == 18){
            board = head;       
            show_price(board, 20);
            printf("|");
            for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            board = head;
            show_price(board, 10);
            printf(" ");
            printf("|");            
        }
        else if(i ==14){
            printf("|");
            for(l = 0 ; l < 24 ; l++){
                printf(" ");
            }
            printf("|");
            for(l = 0 ; l < 124 ; l++){
                printf(" ");
            }
            printf("|");
            for(l = 0 ; l < 24 ; l++){
                printf(" ");
            }
        }
        else if(i == 22){
            board = head;
            show_price(board, 19);
            printf("|");
            for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            board = head;
            show_price(board, 11);
            printf("|");
        }
        else if(i == 7 ){
            board = head;
            number = 23;
            print_of_owner(board , player_one , player_two , number);
        }
        else if(i == 11){
            board = head;
            number = 22;
            print_of_owner(board , player_one , player_two , number);
        }
        else if(i == 15){
            board = head;
            printf("|");
            for(k = 0 ; k < 24 ; k++ ){
                printf(" ");      
            }
            printf("|");
            for(l = 0 ; l < 124 ; l++){
                    printf(" ");
                }
            printf("|");
            for(k = 0 ; k < 24 ; k++ ){
                printf(" ");      
            }
            printf("|");
        }
        else if(i == 19){
            board = head;
            number = 21;
            print_of_owner(board , player_one , player_two , number);
        }
        else if(i == 23){
            board = head;
            number = 20;
            print_of_owner(board , player_one , player_two , number);
        }
        else if(i == 8 || i == 12 || i == 16 || i == 20){
            for(k = 0 ; k < 25 ; k++){
                printf("-");
            }
            for(l = 0 ; l < 126 ; l++){
                printf(" ");
            }
            for(k = 0 ; k < 25 ; k++){
                printf("-");
            }
        }
        printf("\n");
    }
    //free(head);
}
void init_board(block *head){
    struct block *board;
    board = (block*)malloc(sizeof(block));
	player temp_player;
	temp_player.type=none;
    board = head;

    board->id=0;
    board->name="Start";
    board->price=0;
    board->rent=0;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->owner= temp_player;
    board->house_price=0;
    board->h_count=0;
    board->owner.type = none;
    board->type=start;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;
   
    board->id=1;
    board->name="Esenyurt";
    board->price=16000;
    board->rent=800;
    board->rent_1=4000;
    board->rent_2=9000;
    board->rent_3=25000;
    board->house_price=10000;
    board->owner.type = none;
    board->h_count=0;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type=tax;
    board->name="Car park";
    board->id=2;
    board->price=1500;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type = fortune;
    board->id = 3;
    board->name="Fortune Card";
    board->rent = 0;
    board->price = 0;
    board->rent_1 = 0;
    board->rent_2 = 0;
    board->rent_3 = 0;
    board->house_price=0;
    board->h_count=0;
    board->owner.type = none;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=4;
    board->name="Tuzla";
    board->price=16500;
    board->rent=850;
    board->rent_1=4250;
    board->rent_2=9500;
    board->rent_3=26000;
    board->house_price=12000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=5;
    board->name="Arnavutkoy";
    board->price=17000;
    board->rent=850;
    board->rent_1=4500;
    board->rent_2=10000;
    board->rent_3=28000;
    board->house_price=12000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type=punish;
    board->name="Wait 2 turn";
    board->price=2;
    board->id=6;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=7;
    board->name="Catalca";
    board->price=20000;
    board->rent=1000;
    board->rent_1=5000;
    board->rent_2=12000;
    board->rent_3=30000;
    board->house_price=13000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=8;
    board->name="Beykoz";
    board->price=23000;
    board->rent=1100;
    board->rent_1=5500;
    board->rent_2=12500;
    board->rent_3=33000;
    board->house_price=13000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type = fortune;
    board->id = 9;
    board->name="Fortune Card";
    board->rent = 0;
    board->price = 0;
    board->rent_1 = 0;
    board->rent_2 = 0;
    board->rent_3 = 0;
    board->house_price=0;
    board->h_count=0;
    board->owner.type = none;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->name="Car fix";
    board->id=10;
    board->price=1750;
    board->type=tax;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=11;
    board->name="Maltepe";
    board->price=30000;
    board->rent=1350;
    board->rent_1=7000;
    board->rent_2=15000;
    board->rent_3=40000;
    board->house_price=15000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->name="Bills";
    board->id=12;
    board->price=2000;
    board->type=tax;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=13;
    board->name="Sisli";
    board->price=33000;
    board->rent=1500;
    board->rent_1=8000;
    board->rent_2=16000;
    board->rent_3=42000;
    board->house_price=16000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->name="Oil";
    board->id=14;
    board->price=2250;
    board->type=tax;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type = fortune;
    board->id = 15;
    board->name="Fortune Card";
    board->rent = 0;
    board->price = 0;
    board->rent_1 = 0;
    board->rent_2 = 0;
    board->rent_3 = 0;
    board->house_price=0;
    board->h_count=0;
    board->owner.type = none;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=16;
    board->name="Atasehir";
    board->price=35000;
    board->rent=1600;
    board->rent_1=8500;
    board->rent_2=17000;
    board->rent_3=45000;
    board->house_price=17000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=17;
    board->name="Sariyer";
    board->price=40000;
    board->rent=1750;
    board->rent_1=9500;
    board->rent_2=19000;
    board->rent_3=48000;
    board->house_price=19000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->name="Wait 1 turn";
    board->price=1;
    board->id=18;
    board->type=punish;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=19;
    board->name="Kadikoy";
    board->price=43000;
    board->rent=1900;
    board->rent_1=11000;
    board->rent_2=21500;
    board->rent_3=55000;
    board->house_price=23000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=20;
    board->name="Besiktas";
    board->price=60000;
    board->rent=2500;
    board->rent_1=15000;
    board->rent_2=28000;
    board->rent_3=60000;
    board->house_price=30000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->type = fortune;
    board->id = 21;
    board->name="Fortune Card";
    board->rent = 0;
    board->price = 0;
    board->rent_1 = 0;
    board->rent_2 = 0;
    board->rent_3 = 0;
    board->house_price=0;
    board->h_count=0;
    board->owner.type = none;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->name="Vocation";
    board->id=22;
    board->price=5000;
    board->type=tax;
    board->next = (block*)malloc(sizeof(block));
    board = board->next;

    board->id=23;
    board->name="Bebek";
    board->price=70000;
    board->rent=3500;
    board->rent_1=20000;
    board->rent_2=35500;
    board->rent_3=65000;
    board->house_price=35000;
    board->h_count=0;
    board->owner.type = none;
    board->type=property;
    board->next = (block*)malloc(sizeof(block));


    board->next = NULL;
    free(board);
}
void show_player_properties(block *board, player current_player){
    int i,j,counter=0,selection; 
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp =board;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
                printf("fghj\n");
                for(j = 0 ; j <= current_player.owned_blocks[i] ; j++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
                    temp = temp->next;
                }
                printf("%d - %s\n", temp->id,temp->name);
                counter++;
            }
            temp = board;
        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {
            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);
            for(j = 0 ; j <= selection ; j++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
            temp = temp->next;
            }
            if (selection!=0) {
                if (temp->owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(temp->name) < 8)
                        printf("|\t\t%s\t\t|\n", temp->name);
                    else
                        printf("|\t    %s\t\t|\n", temp->name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", temp->rent);
                    printf("|\tRent 1 H \t%d$\t|\n", temp->rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", temp->rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", temp->rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", temp->house_price);
                    printf("|\tHouse count \t%d\t|\n", temp->h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
            temp = board;
        }
    }
}
int build_house(block *current_block, player* current_player){
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                //current_player->account-=current_block->house_price;
                current_block->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}
int count_properties(player current_player){
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}
void sell_property(block *board, player* current_player){
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board ;
    int count;
    int property_id,flag=0,is_owned=-1,i,j,index,counter=0;
        if (count_properties(*current_player)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
                    for(j = 1 ; j < current_player->owned_blocks[i] ; j++){
                        temp = temp->next;
                    }
                    printf("%d - %s\n", temp->id , temp->name);
                    counter++;
                }
                temp = board;
            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++){
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        printf("TEST%d\n",i );
                        is_owned=1;
                        index=i;
                        i = PROPERTY_COUNT +1;
                    }
                }
                printf("TEST2\n");
                if(is_owned != -1)
                {
                    printf("TEST\n");
                    temp = board;
                    for(j = 1 ; j < property_id ; j++){
                        temp = temp->next;
                    }
                    current_player->owned_blocks[index]=-1;
                    //player temp;
                    temp->owner.type=none;
                    if(temp->h_count==0)current_player->account+=temp->price/2;
                    else if(temp->h_count==1)
                    {
                        printf("%d 1.durum\n",current_player->account );
                        current_player->account+=(temp->price+temp->house_price)/2;
                        printf("%d 2. durum\n",current_player->account );
                    }
                    else if(temp->h_count==2)
                    {
                        current_player->account+=(temp->price+(2*temp->house_price))/2;
                    }
                    else if(temp->h_count==3)
                    {
                        current_player->account+=(temp->price+(3*temp->house_price))/2;
                    }

                }
            }
        } else
        {
            printf("You don't have any property to sell.\n");
        }
}
int insufficient_fund(block *board, player* current_player,int required_money){
    int selection,flag=1;
    while (selection!=0 && current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(board,current_player);
                break;
            case 2:
                show_player_properties(board,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;
}
void pay_rent(block *board, player* current_player,player * owner){
    int rent=0,owned_property_count;
    rent=board[current_player->current_block_id].rent;
    if (board[current_player->current_block_id].h_count==1)rent=board[current_player->current_block_id].rent_1;
    if (board[current_player->current_block_id].h_count==2)rent=board[current_player->current_block_id].rent_2;
    if (board[current_player->current_block_id].h_count==3)rent=board[current_player->current_block_id].rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}
void add_to_owned(player* current_player){
   for (int i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");                
}
void buy_for_tax(block *board, player *current_player){
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    int result = 0;
    int i,j,count=0;
    int price[13];
    for(i = 0 ; i < 13 ; i++){
        if(temp->owner.type == car) {
            price[count] = temp->id;
            count++;
        }
    }
    if(count == 0){
    }
    else{
        for(i=0;i<count;i++){
             if(price[i] > result)
                result = price[i];
        }
        temp = board;
        for(j = 1 ; j < price[i] ; j++){
            temp = temp->next;
        }
        current_player->owned_blocks[count]=-1;
        temp->owner.type=none;
        if(temp->h_count==0)current_player->account+=temp->price/2;
        else if(temp->h_count==1)
        {
            printf("%d 1.durum\n",current_player->account );
            current_player->account+=(temp->price+temp->house_price)/2;
            printf("%d 2. durum\n",current_player->account );
        }
        else if(temp->h_count==2)
        {
            current_player->account+=(temp->price+(2*temp->house_price))/2;
        }
        else if(temp->h_count==3)
        {
            current_player->account+=(temp->price+(3*temp->house_price))/2;
        }
    }
}
void buy_property(block* current_block, player* current_player){
    int i = 0;
    char control;
    block *temp;
    temp = (block*)malloc(sizeof(block));
    int house_number; //almak istedigi ev sayisi
    int total_price = 0;//kullanıcıdan aldığın ev sayısının total ucreti
    int number;
    temp = current_block;
    for(i = 1 ; i < current_player->current_block_id ; i++){
        temp= temp->next;
    }
    if(temp->type == property){//arsa mı diye bak
        if(temp->owner.type == none ){//bos mu diye bak
            if(current_player->account >= temp->price){//Parası yetiyor mu diye bak
                current_player->account -= temp->price;
                for(i = 0 ; i < PROPERTY_COUNT ; i++){
                    if (current_player->owned_blocks[i]==-1){
                        current_player->owned_blocks[i]=current_player->current_block_id ;
                        i= 25; //for break loop
                    }
                }
                add_to_owned(current_player);
                if(current_player->type == car){//
                    printf("Account : %d$ House Price : %d$\n", current_player->account, temp->house_price);
                    printf("How many house do you build?\n");
                    scanf("%d" , &house_number);
                    while(house_number < 0 || house_number > 3){
                        printf("Wrong number. Please try again.\n");
                        scanf("%d" , &house_number);
                    }
                    if(house_number >= 0 || house_number <= 3){
                        temp->owner.type = current_player->type;
                        if(house_number == 0){
                            return;
                        }
                        else{
                            total_price = (house_number)*(temp->house_price);
                            if(total_price > current_player->account){
                                printf("You don't have enough money.\nYou have %d$ and a house is %d$.\nPlease enter new house number.\n", current_player->account, temp->house_price);
                            }
                            else{
                                temp->owner.type = current_player->type;
                                temp->h_count += house_number;
                                current_player->account -= total_price;
                            }
                        }
                    }
                }
                else if(current_player->type == cap){//
                    if(current_player->account >= temp->house_price){
                        printf("Computer buy this property and build a house.\n");
                        temp->owner.type = current_player->type;
                        temp->h_count += house_number;
                        current_player->account -= total_price;
                    }
                }
            }
            else{
                printf("You don't have enough money.\n");
            }
        }
        else if(temp->owner.type == current_player->type){
            house_number = temp->h_count;
            if (house_number < 3){
                house_number = 3 - house_number;
                printf("You can build %d house.\n", house_number);
                printf("Account : %d$ House Price : %d$\n", current_player->account, temp->house_price);
                scanf("%d", &number);
                if (number <= house_number && number >= 0){
                    if(total_price > current_player->account){
                        printf("You don't have enough money.\nYou have %d$ and a house is %d$.\nPlease enter new house number.\n", current_player->account, temp->house_price);
                        scanf("%d", &number);
                    }
                    else{
                        temp->h_count += number;
                        total_price = (number)*(temp->house_price);
                        current_player->account -= total_price;
                    }
                }
                else{
                    printf("Wrong number.Please try again.\n");
                }
            }
            else{
                printf("You have 3 house. You cant build house.\n");
            }
        }
        else{
            if(temp->owner.type != current_player->type){
                printf("The field is full so you must rent. \n");
            }
        }
    }
}
void copy_owner(player* old, player* new){
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}
/*void house_dialog(block *board, player* current_player){
    block *temp;
    int i;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    for(i = 1 ; i < current_player->current_block_id ; i++){
            temp = temp ->next;
        }
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n", temp->name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        
        if (selection == 1) {

            if (current_player->account < temp->house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<temp->house_price && insuf_flag==1)
                    insuf_flag=insufficient_fund(board,current_player, temp->house_price);
            }
            if (current_player->account >= temp->house_price)
                build_flag=build_house(temp, current_player); //temp te adres olabilir
            else
                house_flag=0;


        } else
            house_flag=0;
    }
}*/
void free_house(block *board , player* current_player, int property_number){
    block *temp;
    temp = (block*)malloc(sizeof(block));
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    int i;
    for(i = 0 ; i <= property_number ; i++){
        temp = temp->next;
    }
    if (current_player->type == temp->owner.type){
        if (temp->h_count<3)
        {
            if (temp->house_price <= current_player->account)
            {
                temp->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
     else
        printf("You don't have permission to build house on this property!\n ");
}
void after_dice_menu(block *board, player* current_player, player* other){
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    int random_fortune_num;
    int count_property = 0;
    int result;
    int property_number; //For free house
    int selection,insuf_flag=1,i;
    int result_dice;
    int flag = 0;
    temp = board;
    for(i = 1 ; i < current_player->current_block_id ; i++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
        temp = temp->next;
    }

    switch(temp->type)
    {
        case start:
        current_player->account += 10000;
        other->account += 10000;
        break;
        case property:
            if(current_player->type == car){//
                printf("%s has arrived %s \n",current_player->player_name,temp->name);
                if (temp->owner.type==none){
                    printf("Do you want to buy %s ?\n",temp->name);
                    printf("1- Yes\n");
                    printf("2- No\n");
                    scanf("%d",&selection);
                    if (selection==1)
                    {
                        printf("%d\n",current_player->account );
                        if (current_player->account < temp->price)
                        {
                            while (count_properties(*current_player)!=0 && current_player->account<temp->price && insuf_flag==1 )
                            {
                                insuf_flag=insufficient_fund(board , current_player, temp->price);
                            }
                        }
                        else{
                            buy_property(board,current_player);
                        }
                        if (current_player->type==temp->owner.type)
                        {
                            //house_dialog(board,current_player);
                        }
                    }
                } else
                {
                    pay_rent(board,current_player,other);
                }
                flag++;
            }
            else if(current_player->type == cap){//
                printf("%s has arrived %s \n",current_player->player_name,temp->name);
                if(temp->owner.type == none){
                    if(temp->price <= 33625){
                        buy_property(board , current_player);
                    }
                    else{
                        result = roll_dice();
                        if(result<=1 || result >=3)
                        buy_property(board , current_player);
                    }
                }
                else if(temp->owner.type == car){
                    if(temp->h_count >=3){
                        printf("Computer has 3 house this property.\n");
                    }
                    else if(temp->h_count < 3 && temp->h_count >= 0){
                        for(i = 0 ; i < PROPERTY_COUNT ; i++){
                            if(current_player->owned_blocks[i]!= -1){
                                count_property++;
                            }
                        }
                        if(count_property >= 4){
                            result = roll_dice();
                            if(result >=1 || result <=3){
                                if(temp->h_count < 3){
                                    temp->h_count += 1;
                                    current_player->account -= (temp->house_price);
                                }
                            }
                        }
                    }
                }
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->player_name,temp->name);
            if(temp->owner.type == car){//
                while (count_properties(*current_player)!=0 && current_player->account<temp->price) {
                    insuf_flag = insufficient_fund(board, current_player,temp->price);
                    if (insuf_flag == 0 && current_player->account < temp->price)
                        printf("You must pay your tax!\n");
                }
                if (current_player->account>temp->price)
                    current_player->account=current_player->account-temp->price;
                else
                {
                    current_player->account=0;
                }
            }
            else if(temp->owner.type == cap){//
                if(current_player->account >= tax){
                    current_player->account -=tax;
                }
                while(current_player->account <= tax){
                    buy_for_tax(board , current_player);
                }
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->player_name,temp->price);
            current_player->turn_to_wait+=temp->price;
            flag++;
            break;
    
        case fortune:
            random_fortune_num = rand() % 5;
            //current_player->account +=3;
            if(random_fortune_num == 0){
                printf("Congrulations. You are in Free House. You build a house free in your property.\nPlease enter the number of property.\n");
                scanf("%d" , &property_number);
                free_house(board,current_player, property_number);
            }
            if(random_fortune_num == 1){
                printf("You are in Time Travel. You roll dice again.\nPlease enter the number of property.\n");
                result_dice = roll_dice();
                if(result_dice >= 1 && result_dice <= 3){
                    current_player->current_block_id = current_player->current_block_id + 2;
                }
                else{current_player->current_block_id = current_player->current_block_id - 2;
              }

            }
            if(random_fortune_num == 2){
                if(current_player->account > 5000){
                    current_player->account -=5000;
                }
                else{
                    sell_property(board, current_player);
                    current_player->account -=5000;
                }
                
            }
            if(random_fortune_num == 3){
                if(current_player->account > 10000){
                    current_player->account -=10000;
                    other->account +=10000;
                }
                else{
                    sell_property(board, current_player);
                    current_player->account -=10000;
                }
            }
            if(random_fortune_num == 4){
                current_player->account += 20000;
            }
            flag++;
            break;
        
        }
    temp = board;
}
void turn(block *board, player* current_player, player *other){
    int i = 0,flag = 1,next_block;
    int a;
    block *temp;
    temp = (block*)malloc(sizeof(block));
    temp = board;
    for(i = 1 ; i < current_player->current_block_id ; i++){//YERİ hER CASE İN İCİNDE DE OLABİLİR
        temp = temp->next;
    }
    while(flag)
    {
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",current_player->player_name);

            scanf("%d",&selection);
            switch(selection)
            {
                case 1:
                    if (current_player->turn_to_wait==0) {
                        a = roll_dice();
                        next_block = (current_player->current_block_id + a);
                        if (next_block>=24)current_player->account+=10000;
                        current_player->current_block_id = next_block % 23;
                        if(current_player->type == car){
                            printf("Computer rolled the dice: %d\n", a);
                        }
                        after_dice_menu(board,current_player,other);
                        flag = 0;
                    } else
                    {
                        printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                        current_player->turn_to_wait-=1;
                        flag=0;
                    }
                    break;
                case 2:
                    printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                    break;
                case 3:
                    show_player_properties(board,*current_player);
                    break;
                case 4:
                    show_property_deed(board);
                    break;
                case 5:
                    if (temp->type==property && temp->owner.type== none)
                    buy_property(temp,current_player); //t4empte adres olabilir
                    else{
                        printf("You don't have permission to buy this block!\n");
                    }
                    break;
                case 6:
                    if (current_player->type==temp->owner.type) {
                        buy_property(temp,current_player);
                        //house_dialog(board,current_player);
                    }else
                    {
                        printf("You don't have permission to build house on this block!\n");
                    }
                    break;
                case 7:
                    sell_property(board,current_player);
                    break;
                default:
                    printf("Wrong selection!\n");
            }
            temp = board;
        }
}
int check_end(player current_player){
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}
void play_game(block *board, player* player_one, player* player_two){
    int is_end=0;
    printf("Welcome to Monopoly! %s will roll the dice first.\n",player_one->player_name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
        turn(board,player_one,player_two);
        show_board(board,*player_one,*player_two);
        is_end = check_end(*player_one);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
            turn(board,player_two,player_one);
            show_board(board,*player_one,*player_two);
            is_end=check_end(*player_two);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_two->player_name,player_two->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->player_name,player_one->player_name);

    }
}
void init_owned(player* current_player){
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }
}
int main(){
    block *head;
    head = (block*)malloc(sizeof(block));
    init_board(head);
    srand(time(NULL));
    player player_one,player_two;

    player_one.player_name="Cap";
	player_one.type=cap;
	player_one.current_block_id=0;
    player_one.turn_to_wait=0;
	player_one.account=90000;
    init_owned(&player_one);

	player_two.player_name="Car";
	player_two.type=car;
	player_two.current_block_id=0;
    player_two.turn_to_wait=0;
	player_two.account=90000;
    init_owned(&player_two);

    show_board(head,player_one,player_two);
    play_game(head,&player_one,&player_two);

    return 0;
}
