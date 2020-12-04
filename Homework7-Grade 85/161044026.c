#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
typedef enum{noone , cap , car}player_type;
typedef enum{start, property, tax, punish}block_type;
typedef struct{
	player_type type;
	int current_block_id;
	int owned_block_ids[12];
	int account;
	int turn_to_wait;
	char * name;
}player;

typedef struct{
	int block_id;
	char * name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	block_type type;
}block;
int find_length(block board[20] , int number);
void show_properties(block board[20]);
void init_the_board(block board[20]);
void show_board(block board[20] , player player_one , player player_two);
void buy_property(block* current_block, player* current_player);
void sell_property(block board[20], player* current_player);
void gameplay(block board[20], player player_one, player player_two);

void print_of_owner(block board[20], player player_one, player player_two , int block_number);


int main(){	
	int i;
	block board[20];
	player cap , car , current_player;
	cap.name = "cap";
	car.name = "car";
	srand(time(NULL));
	cap.current_block_id = 0;
	car.current_block_id = 0;
	cap.account = 100000;
	car.account = 100000;
	for(i = 0; i < 12 ; i++){
		cap.owned_block_ids[i] = -5;
		car.owned_block_ids[i] = -5;
	}
	init_the_board(board);
	printf("						Welcome Monopoly\n\n\n\n");
	gameplay(board, cap , car);
	return 0;
}
void init_the_board(block board[20]){
	board[0].block_id = 0;
	board[0].name ="Start";
	board[0].price = 0;
	board[0].rent = 0;
	board[0].rent_1 = 0;
	board[0].rent_2 = 0;
	board[0].rent_3 = 0;
	board[0].house_price = 0;
	board[0].house_count = 0;
	board[0].owner.type = noone;
	board[0].type = start;

	board[1].block_id = 1;
	board[1].name = "Esenyurt";
	board[1].price = 16000;
	board[1].rent = 800;
	board[1].rent_1 = 4000;
	board[1].rent_2 = 9000;
	board[1].rent_3 = 25000;
	board[1].house_price = 10000;
	board[1].house_count = 0;
	board[1].owner.type = noone;
	board[1].type = property;

	board[2].block_id = 2;
	board[2].name = "Car Park";
	board[2].price = 0;
	board[2].rent = 1500;
	board[2].rent_1 = 0;
	board[2].rent_2 = 0;
	board[2].rent_3 = 0;
	board[2].house_price = 0;
	board[2].house_count = 0;
	board[2].owner.type = noone;
	board[2].type = tax;

	board[3].block_id = 3;
	board[3].name = "Tuzla";
	board[3].price = 16500;
	board[3].rent = 850;
	board[3].rent_1 = 4250;
	board[3].rent_2 = 9500;
	board[3].rent_3 = 26000;
	board[3].house_price = 12000;
	board[3].house_count = 0;
	board[3].owner.type = noone;
	board[3].type = property;

	board[4].block_id = 4;
	board[4].name = "Arnavutkoy";
	board[4].price = 17000;
	board[4].rent = 875;
	board[4].rent_1 = 4500;
	board[4].rent_2 = 10000;
	board[4].rent_3 = 28000;
	board[4].house_price = 12000;
	board[4].house_count = 0;
	board[4].owner.type = noone;
	board[4].type = property;

	board[5].block_id = 5;
	board[5].name = "Wait 2 Turn";
	board[5].price = 0;
	board[5].rent = 2;
	board[5].rent_1 = 0;
	board[5].rent_2 = 0;
	board[5].rent_3 = 0;
	board[5].house_price = 0;
	board[5].house_count = 0;
	board[5].owner.type = noone;
	board[5].type = punish;


	board[6].block_id = 6;
	board[6].name = "Catalca";
	board[6].price = 20000;
	board[6].rent = 1000;
	board[6].rent_1 = 5000;
	board[6].rent_2 = 12000;
	board[6].rent_3 = 30000;
	board[6].house_price = 13000;
	board[6].house_count = 0;
	board[6].owner.type = noone;
	board[6].type = property;

	board[7].block_id = 7;
	board[7].name = "Beykoz";
	board[7].price = 23000;
	board[7].rent = 1100;
	board[7].rent_1 = 5500;
	board[7].rent_2 = 12500;
	board[7].rent_3 = 33000;
	board[7].house_price = 13000;
	board[7].house_count = 0;
	board[7].owner.type = noone;
	board[7].type = property;

	board[8].block_id = 8;
	board[8].name = "Car Fix";
	board[8].price = 0;
	board[8].rent = 1750;
	board[8].rent_1 = 0;
	board[8].rent_2 = 0;
	board[8].rent_3 = 0;
	board[8].house_price = 0;
	board[8].house_count = 0;
	board[8].owner.type = noone;
	board[8].type = tax;

	board[9].block_id = 9;
	board[9].name = "Maltepe";
	board[9].price = 30000;
	board[9].rent = 1350;
	board[9].rent_1 = 7000;
	board[9].rent_2 = 15000;
	board[9].rent_3 = 40000;
	board[9].house_price = 15000;
	board[9].house_count = 0;
	board[9].owner.type = noone;
	board[9].type =property;

	board[10].block_id = 10;
	board[10].name = "Bills";
	board[10].price = 0;
	board[10].rent = 2000;
	board[10].rent_1 = 0;
	board[10].rent_2 = 0;
	board[10].rent_3 = 0;
	board[10].house_price = 0;
	board[10].house_count = 0;
	board[10].owner.type = noone;
	board[10].type = tax;

	board[11].block_id = 11;
	board[11].name = "Sisli";	
	board[11].price = 33000;
	board[11].rent = 1500;
	board[11].rent_1 = 8000;
	board[11].rent_2 = 16000;
	board[11].rent_3 = 42000;
	board[11].house_price = 16000;
	board[11].house_count = 0;
	board[11].owner.type = noone;
	board[11].type = property;

	board[12].block_id = 12;
	board[12].name = "Oil";
	board[12].price = 0;
	board[12].rent = 2250;
	board[12].rent_1 = 0;
	board[12].rent_2 = 0;
	board[12].rent_3 = 0;
	board[12].house_price = 0;
	board[12].house_count = 0;
	board[12].owner.type = noone;
	board[12].type = tax;

	board[13].block_id = 13;
	board[13].name = "Atasehir";
	board[13].price = 35000;
	board[13].rent = 1600;
	board[13].rent_1 = 8500;
	board[13].rent_2 = 17000;
	board[13].rent_3 = 45000;
	board[13].house_price = 17000;
	board[13].house_count = 0;
	board[13].owner.type = noone;
	board[13].type = property;

	board[14].block_id = 14;
	board[14].name = "Sariyer";
	board[14].price = 40000;
	board[14].rent = 1750;
	board[14].rent_1 = 9500;
	board[14].rent_2 = 19000;
	board[14].rent_3 = 48000;
	board[14].house_price = 19000;
	board[14].house_count = 0;
	board[14].owner.type = noone;
	board[14].type = property;

	board[15].block_id = 15;
	board[15].name = "Wait 1 Turn";
	board[15].price = 0;
	board[15].rent = 2;
	board[15].rent_1 = 0;
	board[15].rent_2 = 0;
	board[15].rent_3 = 0;
	board[15].house_price = 0;
	board[15].house_count = 0;
	board[15].owner.type = noone;
	board[15].type = punish;


	board[16].block_id = 16;
	board[16].name = "Kadikoy";
	board[16].price = 43000;
	board[16].rent = 1900;
	board[16].rent_1 = 11000;
	board[16].rent_2 = 21500;
	board[16].rent_3 = 55000;
	board[16].house_price = 23000;
	board[16].house_count = 0;
	board[16].owner.type = noone;
	board[16].type = property;


	board[17].block_id = 17;
	board[17].name = "Besiktas";
	board[17].price = 60000;
	board[17].rent = 2500;
	board[17].rent_1 = 15000;
	board[17].rent_2 = 28000;
	board[17].rent_3 = 60000;
	board[17].house_price = 30000;
	board[17].house_count = 0;
	board[17].owner.type = noone;
	board[17].type = property;

	board[18].block_id = 18;
	board[18].name = "Vocation";
	board[18].price = 0;
	board[18].rent = 5000;
	board[18].rent_1 = 0;
	board[18].rent_2 = 0;
	board[18].rent_3 = 0;
	board[18].house_price = 0;
	board[18].house_count = 0;
	board[18].owner.type = noone;
	board[18].type = tax;

	board[19].block_id = 19;
	board[19].name = "Bebek";
	board[19].price = 70000;
	board[19].rent = 3500;
	board[19].rent_1 = 20000;
	board[19].rent_2 = 35500;
	board[19].rent_3 = 65000;
	board[19].house_price = 35000;
	board[19].house_count = 0;
	board[19].owner.type = noone;
	board[19].type = property;
}
void print_of_owner(block board[20], player player_one, player player_two , int block_number){//helper function
	int i = 0 , j , k , l , m;
	int count = 0;
	for(i = 0 ; i < 2 ; i++){
		if(player_one.current_block_id == block_number || player_two.current_block_id == block_number){
			printf("|       ");
			if (player_one.current_block_id != player_two.current_block_id){
				if(player_one.current_block_id == block_number){
					printf("%s",player_one.name );
					for(l = 0 ; l < (17 - strlen(player_one.name)) ; l++){
						printf(" ");
					}
				}
				else if(player_two.current_block_id == block_number){
					printf("%s",player_two.name );
					for(l = 0 ; l < (17 - strlen(player_two.name)) ; l++){
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
			for(l = 0 ; l < 99 ; l++){
				printf(" ");
			}
		}
		count++;
		if(block_number == 19){
			block_number = 6;
		}
		if(block_number == 18){
			block_number = 7;
		}
		if(block_number == 17){
			block_number = 8;
		}
		if(block_number == 16){
			block_number = 9;
		}
	}
}
void show_board(block board[20] , player player_one , player player_two){
	int i = 0 , j , k , l , m;
	int count = 0;
	int temp;
	int len = 0;
	int rotate_count = 0;
	int rotate_count1 = 0;
	int bi = 0;
	int bi2 = 0;
	int number = 0;

	j = 0;
	for(i = 0 ; i < 25 ;i++){
		if(i == 0  || i == 4 || i == 20 || i == 24){
			for(k = 0 ; k < 150 ; k++){
				printf("-");
			}
		}
		else if(i == 1){
			temp = count;
			for(k = 0 ; k < 6 ; k++){
				printf("|       %s",board[temp].name );
				for(l = 0 ; l < (17 - strlen(board[temp].name)) ; l++){
					printf(" ");
				}
					temp++;
			}
			printf("|");
		}
		else if(i == 21){
			for(k = 0 ; k < 6 ; k++){
				printf("|       %s",board[15 - k].name );
				for(l = 0 ; l < (17 - strlen(board[15 - k].name)) ; l++){
					printf(" ");
				}
			}
			printf("|");
		}
		else if(i == 2){
			len = find_length(board,temp);
			temp = count;
			for(k = 0 ; k < 6 ; k++){
				printf("|");
				if(k == 0 || k == 5){
					for(m = 0 ; m < 24 ; m++){
						printf(" ");
					}
				}
				else if(k == 2){
					printf("       ");
					printf("%d$", board[temp].rent );
					for(m = 0 ; m < 12 ; m++){
						printf(" ");
					}
				}
				else{
					printf("       ");
					printf("%d$",board[temp].price );
					for(l = 0 ; l < (12 - len) ; l++){
						printf(" ");
					}
				}

				temp++;
			}
			printf("|");
		}
		else if(i == 22){
			len = find_length(board,(15 - k));
			for(k = 0 ; k < 6 ; k++){
				printf("|");
				if(k == 0){
					for(m = 0 ; m < 24 ; m++){
						printf(" ");
					}
				}
				else if(k == 3|| k == 5){
					printf("       ");
					printf("%d$", board[temp].rent );
					for(m = 0 ; m < 12 ; m++){
						printf(" ");
					}
				}
				else{
					printf("       ");
					printf("%d$",board[15 - k].price );
					for(l = 0 ; l < (12 - len) ; l++){
						printf(" ");
					}
				}
			}
			printf("|");
		}
		else if(i == 3){
			temp = count;
			for(k = 0 ; k < 6 ; k++){
				printf("|       ");
				if(player_one.current_block_id == k || player_two.current_block_id ==k){
					if (player_one.current_block_id != player_two.current_block_id){
						if(player_one.current_block_id == k){
							printf("%s",player_one.name );
							for(l = 0 ; l < (17 - strlen(player_one.name)) ; l++){
								printf(" ");
							}
						}
						else if(player_two.current_block_id == k){
							printf("%s",player_two.name );
							for(l = 0 ; l < (17 - strlen(player_two.name)) ; l++){
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
			temp++;
			}
			printf("|");
			count+=5;
		}
		else if(i == 5 || i == 9 || i == 13 || i == 17){
				printf("|       %s",board[19 - rotate_count].name );
				for(l = 0 ; l < (17 - strlen(board[19 - rotate_count].name)) ; l++){
					printf(" ");
				}
					printf("|");
				for(l = 0 ; l < 99 ; l++){
					printf(" ");
				}
				count++;
				printf("|       %s",board[count].name );
				for(l = 0 ; l < (17 - strlen(board[count].name)) ; l++){
					printf(" ");
				}
					printf("|");
			rotate_count++;
		}
		else if(i == 6 || i == 10 || i == 14 || i == 18){
			printf("|");
			printf("       ");
			if(board[19 - rotate_count1].type == 1){
				printf("%d$",board[19 - rotate_count1].price );
			}
			else if(board[19 - rotate_count1].type != 1){
				printf("%d$",board[19 - rotate_count1].rent);
				if(i == 10){
					printf(" ");
				}
			}
			for(l = 0 ; l < (12 - len) ; l++){
				printf(" ");
			}
			printf("|");
			for(l = 0 ; l < 99 ; l++){
				printf(" ");
			}
			printf("|");
			printf("       ");
			if(board[count].type == 1){
				printf("%d$",board[count].price);
			}
			else if(board[count].type != 1){
				printf("%d$",board[count].rent);
				printf(" ");
			}
			for(l = 0 ; l < (12 - len) ; l++){
				printf(" ");
			}
				printf("|");
			rotate_count1++;
		}
		else if(i == 7 ){
			number = 19;
			print_of_owner(board , player_one , player_two , number);
			temp++;
		}
		else if(i == 11){
			number = 18;
			print_of_owner(board , player_one , player_two , number);
			temp++;
		}
		else if(i == 15){
			number = 17;
			print_of_owner(board , player_one , player_two , number);
			temp++;}
		else if(i == 19){
			number = 16;
			print_of_owner(board , player_one , player_two , number);
			temp++;
		}
		else if(i == 8 || i == 12 || i == 16){
			for(k = 0 ; k < 25 ; k++){
				printf("-");
			}
			for(l = 0 ; l < 101 ; l++){
				printf(" ");
			}
			for(k = 0 ; k < 25 ; k++){
				printf("-");
			}
		}
		else if(i == 23){
			temp = count;
			for(k = 15 ; k > 9 ; k--){
				printf("|");
				printf("       ");
				if(player_one.current_block_id == k || player_two.current_block_id ==k){
					if (player_one.current_block_id != player_two.current_block_id){
						if(player_one.current_block_id == k){
							printf("%s",player_one.name );
							for(l = 0 ; l < (17 - strlen(player_one.name)) ; l++){
								printf(" ");
							}
						}
						else if(player_two.current_block_id == k){
							printf("%s",player_two.name );
							for(l = 0 ; l < (17 - strlen(player_two.name)) ; l++){
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
				temp++;
			}
			printf("|");
			count+=5;
		}
		j++;
		printf("\n");
	}
}
void show_properties(block board[20]){
	printf("Please select a property to see details:\n1 -	Esenyurt \n3 -	Tuzla\n4 -	Arnavutkoy\n6 -	Catalca\n7 -	Beykoz\n9 -	Maltepe\n11 -	Sisli\n13 -	Atasehir\n14 -	Sariyer\n16 -	Kadiköy\n17 -	Besiktas\n19 -	Bebek\n0 -	Exit");
	int i , j;
	int select;
	do{	printf("\n");
		scanf("%d", &select);
		if(select != 0){
			for(j = 0 ; j < 33 ; j++){
				printf("-");
			}
			printf("\n|");
			for(j = 0 ; j < 11 ; j++){
				printf(" ");
			}
			printf("%s",board[select].name);
			for(j = 0 ; j < 21 - strlen(board[select].name) ; j++){
				printf(" ");
			}
			printf("|\n");
			for(j = 0 ; j < 33 ; j++){
				printf("-");
			}
			printf("\n|");
			for(j = 0 ; j < 7 ; j++){
				printf(" ");
			}
			printf("Rent");
			for(j = 0 ; j < 12 ; j++){
				printf(" ");
			}
			printf("%6d$",board[select].house_price);
			printf("  ");
			printf("|\n|");
			for(j = 0 ; j < 7 ; j++){
				printf(" ");
			}
			printf("Rent 1 H");
			for(j = 0 ; j < 8 ; j++){
				printf(" ");
			}
			printf("%6d$",board[select].rent_1);
			for(j = 0 ; j < 2 ; j++){//8- sayının uzunluğu
				printf(" ");
			}
			printf("|\n|");
			for(j = 0 ; j < 7 ; j++){
				printf(" ");
			}
			printf("Rent 2 H");
			for(j = 0 ; j < 8 ; j++){
				printf(" ");
			}
			printf("%6d$",board[select].rent_2);
			for(j = 0 ; j < 2 ; j++){//8- sayının uzunluğu
				printf(" ");
			}
			printf("|\n|");
			for(j = 0 ; j < 7 ; j++){
				printf(" ");
			}
			printf("Rent 3 H");
			for(j = 0 ; j < 8 ; j++){
				printf(" ");
			}
			printf("%6d$",board[select].rent_3);
			for(j = 0 ; j < 2 ; j++){//8- sayının uzunluğu
				printf(" ");
			}
			printf("|\n");
			for(j = 0 ; j < 33 ; j++){
				printf("-");
			}
			printf("\n|");
			for(j = 0 ; j < 7 ; j++){
				printf(" ");
			}
			printf("House Price");
			for(j = 0 ; j < 5 ; j++){
				printf(" ");
			}
			printf("%5d$",board[select].rent_3);
			for(j = 0 ; j < 3 ; j++){//8- sayının uzunluğu
				printf(" ");
			}
			printf("|\n");
			for(j = 0 ; j < 33 ; j++){
				printf("-");
			}
		}
	}
	while(select != 0);
	return;
}
void buy_property(block* current_block, player* current_player){
	int i = 0;
	char control;
	int house_number; //almak istedigi ev sayisi
	int total_price = 0;//kullanıcıdan aldığın ev sayısının total ucreti
	int number;
	if(current_block[current_player->current_block_id].type == property){//arsa mı diye bak
		if(current_block[current_player->current_block_id].owner.type == noone ){//bos mu diye bak
			if(current_player->account >= current_block[current_player->current_block_id].price){//Parası yetiyor mu diye bak
				current_player->account -= current_block[current_player->current_block_id].price;
				printf("Account : %d$ House Price : %d$\n", current_player->account, current_block[current_player->current_block_id].house_price);
				printf("How many house do you build?\n");
				scanf("%d" , &house_number);
				while(house_number < 0 || house_number > 3){
					printf("Wrong number. Please try again.\n");
					scanf("%d" , &house_number);
				}
				if(house_number >= 0 || house_number <= 3){
					current_block[current_player->current_block_id].owner.type = current_player->type;
					if(house_number == 0){
						return;
					}
					else{
						total_price = (house_number)*(current_block[current_player->current_block_id].house_price);
						if(total_price > current_player->account){
							printf("You don't have enough money.\nYou have %d$ and a house is %d$.\nPlease enter new house number.\n", current_player->account, current_block[current_player->current_block_id].house_price);
						}
						else{
							current_block[current_player->current_block_id].owner.type = current_player->type;
							current_block[current_player->current_block_id].house_count += house_number;
							current_player->account -= total_price;
						}
					}
				}
			}
			else{
				printf("You don't have enough money.\n");
			}
		}
		else if(current_block[current_player->current_block_id].owner.type == current_player->type){
			house_number = current_block[current_player->current_block_id].house_count;
			if (house_number < 3){
				house_number = 3 - house_number;
				printf("You can build %d house.\n", house_number);
				printf("Account : %d$ House Price : %d$\n", current_player->account, current_block[current_player->current_block_id].house_price);
				scanf("%d", &number);
				if (number <= house_number && number >= 0){
					if(total_price > current_player->account){
						printf("You don't have enough money.\nYou have %d$ and a house is %d$.\nPlease enter new house number.\n", current_player->account, current_block[current_player->current_block_id].house_price);
						scanf("%d", &number);
					}
					else{
						current_block[current_player->current_block_id].house_count += number;
						total_price = (number)*(current_block[current_player->current_block_id].house_price);
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
			if(current_block[current_player->current_block_id].owner.type != current_player->type){
				printf("The field is full so you must rent. \n");
			}
		}
	}
}
void sell_property(block board[20], player* current_player){
	int property_number;
	int total ;
		printf("Which field do you want to sell?\n");
		scanf("%d", &property_number);
		if(board[property_number].owner.type == current_player->type){
			current_player->account += ((board[property_number].price) / 2) + (((board[property_number].house_price)/2)*board[property_number].house_count);
			board[property_number].house_count = 0;
			board[property_number].owner.type = noone;
			current_player->owned_block_ids[property_number] = -5;
		}
		else{
			printf("The property isn't yours. You cant sell it.\n");
		}
}
void gameplay(block board[20], player player_one, player player_two){
	int j = 5,i,m = 5;
	int number_wait = 0;
	int player_wait ;
	int player_wait2 = noone;
	player current_player;
	current_player = player_one;
	int menu;
	int finish = 2;
	int remaining_tour = 2;
	int temp_reamining_tour;
	int dice;
	int playernumber = 1;
	int flag = 0;
	do{
		if(current_player.type == player_one.type){
			show_board(board , current_player , player_two);
		}
		else if(current_player.type == player_two.type){
			show_board(board , player_one , current_player);
				}
		printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\nPlease press 0 for player substitution.\nPlease select an option to continue:\n\n");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				dice = 1 + rand() % 5;
				if(current_player.current_block_id != 5 && current_player.current_block_id != 15){
					current_player.current_block_id += dice;
					printf("Chosen :1 - Roll the dice\nDice : %d\n", dice);
						if(current_player.current_block_id  >= 19){
							current_player.current_block_id -= 19;
							current_player.account += 10000;
						}
						if(board[current_player.current_block_id].owner.type == property){
							if(board[current_player.current_block_id].owner.type != current_player.type){
								if(board[current_player.current_block_id].owner.type == noone){
									printf("This property is empty. You can buy it.\n");
								}
								else{
									if(board[current_player.current_block_id].house_count == 0){
										current_player.account -= board[current_player.current_block_id].rent;
										if(current_player.type == player_one.type){
											player_two.account += board[current_player.current_block_id].rent;
										}
										else if(current_player.type == player_two.type){
											player_one.account += board[current_player.current_block_id].rent;
										}
									}
									else if(board[current_player.current_block_id].house_count == 1){
										current_player.account -= board[current_player.current_block_id].rent_1;
										if(current_player.type == player_one.type){
											player_two.account += board[current_player.current_block_id].rent_1;
										}
										else if(current_player.type == player_two.type){
											player_one.account += board[current_player.current_block_id].rent_1;
										}
									}
									else if(board[current_player.current_block_id].house_count == 2){
										current_player.account -= board[current_player.current_block_id].rent_2;
										if(current_player.type == player_one.type){
											player_two.account += board[current_player.current_block_id].rent_2;
										}
										else if(current_player.type == player_two.type){
											player_one.account += board[current_player.current_block_id].rent_2;
										}
									}
									else if(board[current_player.current_block_id].house_count == 3){
										current_player.account -= board[current_player.current_block_id].rent_3;
										if(current_player.type == player_one.type){
											player_two.account += board[current_player.current_block_id].rent_3;
										}
										else if(current_player.type == player_two.type){
											player_one.account += board[current_player.current_block_id].rent_3;
										}
									}
								}
							}
						}
						else if(board[current_player.current_block_id].type == tax){
							if(current_player.current_block_id == 2){
								if(current_player.account < 1500){
									printf("You dont have enough money. You must sell a property.\n");
									sell_property(board, &current_player);
								}
									current_player.account -= 1500;
							}
							else if(current_player.current_block_id == 8){
								if(current_player.account < 1750){
									printf("You dont have enough money. You must sell a property.\n");
									sell_property(board, &current_player);
								}
									current_player.account -= 1750;
							}
							else if(current_player.current_block_id == 10){
								if(current_player.account < 2000){
									printf("You dont have enough money. You must sell a property.\n");
									sell_property(board, &current_player);
								}
									current_player.account -= 2000;
							}
							else if(current_player.current_block_id == 18){
								if(current_player.account < 5000){
									printf("You dont have enough money. You must sell a property.\n");
									sell_property(board, &current_player);
								}
									current_player.account -= 5000;
							}
						}
					}
				else if(current_player.current_block_id == 5 || current_player.current_block_id == 15){
					if(current_player.current_block_id == 5 && number_wait == 0){
						current_player.turn_to_wait = 3;}
					else if(current_player.current_block_id == 15 && number_wait == 0){
						current_player.turn_to_wait = 2;}
					if(current_player.current_block_id == 5){
						if(current_player.turn_to_wait > 0){
							printf("\n\n\nYou're in 'Wait 2 Turn'. So you must wait 2 times\nThe remaining number of rounds is %d\n",current_player.turn_to_wait);
							menu = 0;								
							current_player.turn_to_wait--;
							number_wait++;
							break;
						}
						else{
							current_player.current_block_id += dice;
							number_wait = 0;
						}
					}
					else if(current_player.current_block_id == 15){
						if(current_player.turn_to_wait > 0){
							printf("\n\n\nYou're in 'Wait 1 Turn'. So you must wait 1 times\nThe remaining number of rounds is %d\n",current_player.turn_to_wait);
							menu = 0;								
							current_player.turn_to_wait--;
							number_wait++;
							menu = 0;
						}
						else{
							current_player.current_block_id += dice;
							number_wait = 0;
						}
					}
				}
			break;
			case 2:
				printf("Account : %d$\n",current_player.account );
				break;
			case 3:
				for(i = 0 ; i < 20 ; i++){
					if(current_player.owned_block_ids[i] == 5 && i < 19 && board[i].type != tax){
						printf("%s\n", board[i].name);
						if(board[i].house_count >= 0){
							printf("%d House in %s\n",board[current_player.current_block_id].house_count , board[i].name);
						}
						flag++;
					}
					else if(flag == 0 && i == 19 ){
						printf("You dont have any properties.\n");
					}
				}
				break;
			case 4:
					show_properties(board);
				break;
			case 5:
				if(board[current_player.current_block_id].owner.type == noone){
					if(board[current_player.current_block_id].price <= current_player.account){
						buy_property(board , &current_player);
						current_player.owned_block_ids[current_player.current_block_id] = 5;
						board[current_player.owned_block_ids[current_player.current_block_id]].owner.type = current_player.type;
					}
					else{
						printf("You dont have enough money.\n");
					}
				}
				else if(board[current_player.current_block_id].owner.type == current_player.type){
					printf("The property is yours. You can't buy again.\n");
				}
				else{
					printf("Other player has the property.\nYou can't buy this property.\nYou must rent.\n");
				}
				break;
			case 6:
				buy_property(board , &current_player);
				break;
			case 7:
				sell_property(board, &current_player);
				break;
			case 0:
				if(current_player.type == player_one.type){
					player_one = current_player;
					current_player = player_two;}
				else if(current_player.type == player_two.type){
					player_two = current_player;
					current_player = player_one;}
			break;
		}
	}
	while(player_one.account != 0 || player_two.account != 0);

		printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n 6 - Buy house\n7 - Sell property\nPlease select an option to continue:\n");

}

int find_length(block board[20] , int number){
	int i;
	int counter = 1;
	for(i = 0 ; i < 20 ; i++){
		if(board[i].price /10 > 0){
			counter++;
		}
		else{
			i = 21;
		}
	}
	return counter;
}

