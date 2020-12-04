#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum pokemon{Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby, Null}pokemon;
typedef enum attack_type{Linear, Quadratic}attack_type;


void menu();
int compare_function(char cmp1[], char cmp2[]);

void pokedex(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[]);
void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[10], pokemon *my_Pokemons);
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[10], int pokemon_count);
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[10], pokemon *my_pocket);
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]);
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket);
void show_area(char Pokemon_name[10][11],int area[8][8], int pokemon_staminas[8][8]);


int main(){
	pokemon *my_Pokemons;
	char Pokemon_name[10][11]={"Charmander", "Pikachu", "Squirtle", "Bulbasaur", "Pidgeotto", "Ratata", "Mug", "Caterpie", "Zubat", "Krabby"};
	int range[10]= {1, 3, 4, 3, 2, 2, 1, 2, 3, 2};
	int attack_power[10]={500, 350, 300, 400, 250, 250, 350, 200, 350, 300};
	int stamina[10]={2200, 1500, 1700, 2500, 1900, 2500, 3000, 1200, 1250, 2600};
	attack_type type[10]={Quadratic, Linear, Linear, Linear, Quadratic, Linear, Quadratic, Quadratic, Linear, Linear};
	pokemon Pokemons[10] = {Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby};
	int area[8][8];
	int pokemon_staminas[8][8];
	int select;
	int count = 1;
	while( 1 )
		menu();
	srand(time( NULL ));

	return 0;
}

void menu(){ // It's main menu.
	pokemon *my_Pokemons;
	char Pokemon_name[10][11]={"Charmander", "Pikachu", "Squirtle", "Bulbasaur", "Pidgeotto", "Ratata", "Mug", "Caterpie", "Zubat", "Krabby"};
	int range[10]= {1, 3, 4, 3, 2, 2, 1, 2, 3, 2};
	int attack_power[10]={500, 350, 300, 400, 250, 250, 350, 200, 350, 300};
	int stamina[10]={2200, 1500, 1700, 2500, 1900, 2500, 3000, 1200, 1250, 2600};
	attack_type type[10]={Quadratic, Linear, Linear, Linear, Quadratic, Linear, Quadratic, Quadratic, Linear, Linear};
	pokemon Pokemons[10] = {Charmander, Pikachu, Squirtle, Bulbasaur, Pidgeotto, Ratata, Mug, Caterpie, Zubat, Krabby};
	int area[8][8];
	int pokemon_staminas[8][8];
	int select;
	int count = 1;
	
	printf("\n1) Open Pokedex\n");
	printf("2) Go to Oak’s Laboratory\n");
	printf("3) Enter the tournament\n");

	while(count == 1){// If 'count' is 1, the function repeatly enter 'while'.
		scanf("%d" , &select);

		if(select >= 1 || select <=3){
			count = 0;
		}
		else{ // If 'select' is wrong, 'count' is 1.
			printf("Wrong choice!Try again!\n");
			scanf("%d" , &select);
			count = 1 ;
		}
	} 
	switch (select){
		case 1: 
			pokedex(Pokemon_name, range, type, attack_power, stamina);
			break;
		case 2:
			oaks_laboratory(Pokemon_name,Pokemons,my_Pokemons);
			break;
		case 3:
			battle(Pokemon_name, range,type, attack_power,stamina,my_Pokemons);
			break;
	}
}

void pokedex(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[]){
	char take_name[11];
	int func;
	int flag = -1;
	char exit_str[5] = "exit";
	exit_str[4] = '\0';

	
	do{//
		printf("Please type name of the Pokémon (type exit to close Pokedex)!\n");
		scanf("%s", take_name);
		if(compare_function(take_name, exit_str) == -1)
			break;
		for(int i = 0 ; i < 10 ; i++){
			func = compare_function(take_name , Pokemon_name[i]);
			if(func == -1){
				flag = i;
				break;
			}
		}
	}
	while(flag == -1);

	if(flag != -1){
		printf("Name   : %s \n", Pokemon_name[flag]);
		if(type[flag] == 0){
			printf("A. Type: Linear\n");
		}
		else{
			printf("A. Type: Quadratic\n");
		}
		printf("Range  : %d block\n", range[flag]);
		printf("A. Power : %d \n", attack_power[flag] );
		printf("Stamina: %d\n", stamina[flag]);
	}
}
int compare_function(char cmp1[], char cmp2[]){
 
    int i=0;
    while(*cmp2 == *cmp1)
    {
        if(cmp1[i] == '\0'||cmp2[i] == '\0')
            break;
        i++;
    }
    if(cmp1[i] == '\0' && cmp2[i] == '\0')
        return -1;

    else
        return -2;
}

void oaks_laboratory(char Pokemon_name[][11], pokemon Pokemons[], pokemon *my_Pokemons){
	int pokemon_count = 0;
	int number_of_menu;
	pokemon my_pocket[4] = {Null, Null, Null, Null};
	int area[8][8];
	int pokemon_staminas[8][8];
	int i;
	int j;
		
	do{

	printf("\n\nWelcome to Laboratory of Professor Oak. How can I help you?\n");
	printf("1) Show Pokémons\n");
	printf("2) Catch a Pokémon\n");
	printf("3) Release a Pokémon\n");
	printf("4) Show my pocket\n");
	printf("5) Back\n");			

	scanf("%d" , &number_of_menu);


		switch (number_of_menu){
			case 1:
				pokemon_count =10;
				show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
				
				
				break;
			
			case 2:
				pokemon_count =10;
				show_Pokemons(Pokemon_name, Pokemons, pokemon_count);				
				catch_a_pokemon(Pokemon_name, Pokemons,my_pocket);

				break;

			case 3:
				pokemon_count = 4 ;

				show_Pokemons(Pokemon_name, my_pocket, pokemon_count);
				
				release_a_pokemon(Pokemon_name,Pokemons,my_pocket);
				break;

			case 4:
				pokemon_count = 4 ;

				show_Pokemons(Pokemon_name, my_pocket, pokemon_count);
				
				break;

			case 5:

				break;
		}
	}
	while(number_of_menu != 5);

}

void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[10], int pokemon_count){


	for(int i = 0 ; i < pokemon_count ; i++){
		if(Pokemons[i] != 10 )
		printf("%d - %s\n", Pokemons[i] , Pokemon_name[Pokemons[i]] );
	}

	
}

void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[10], pokemon *my_pocket){
	int i;
	int control = 1;
	int choice;

	for(i=0; i<4; ++i){
		if(my_pocket[i] == Null){
			break;
		}
	}
	if(i == 4){
		printf("You already have 4 pokemons!\n");
		return;
	}
	do{
		control = 1;
		scanf("%d" , &choice);
		for(i = 0; i < 4; ++i){
			if(choice == my_pocket[i]){
				printf("You already have one! Enter another:\n");
				control = 0;
			}
		}
	}while(control != 1);
	for(i=0; i<4; ++i){
		if(my_pocket[i] == Null){
			my_pocket[i] = Pokemons[choice];
			break;
		}
	}

}

void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_pocket){
	int choice;
	int i;
	scanf("%d" , &choice);
	
	for(i = 0; i < 4; ++i){
		if(my_pocket[i] == choice){
			my_pocket[i] = Null;
			break;
		}
	}
	if(i == 4){
		printf("You don't have that pokemon!\n");
	}
}

void show_area(char Pokemon_name[10][11],int area[8][8], int pokemon_staminas[8][8]){

	int x[8] ;
	int y[8] ;
	int m , n ;


	printf(" ------------------------------------------------\n");

	for(int j = 0 ; j < 16 ; j++){

		for(int k = 0; k < 8 ; k ++){
			printf("|");
			printf("      ");				
		}

		printf("\n");
		
		if( j %2 != 0){

			printf(" ------------------------------------------------\n");
		}
	}	
}


void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]){

	int row;
	int column;
	int pokemon_staminas[8][8];
	int area[8][8] ;
	int pokemons_number;
	int i , j;

	for(i = 0 ; i < 8 ; i++)
		for( j = 0 ; j < 8 ; j++){
			area[i][j] = -5 ;
		}

	printf("Please!Enter Pokémons number.\n");
	scanf("%d" , &pokemons_number);

	
	for( i = 0 ; i < 4 ;i++){
		if(pokemons_number == user_Pokemons[i]){	
			printf("Please, Enter the row.\n");		
			scanf("%d" , &row);
			printf("Please, Enter the column.\n");
			scanf("%d" , &column);

			if( area[row-1][column-1] == -5){
				area[row-1][column-1] =user_Pokemons[i];
			}

			else{
				printf("The area is full. Please enter different location.\n");
				i--;
				
			}


		}


	show_area(Pokemon_name, area, pokemon_staminas);


	printf("control_battle\n");

	}
 }


