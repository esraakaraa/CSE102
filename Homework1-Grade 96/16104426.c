#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3
#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3 
#define WHITE 4

double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power);



int main (){

	int shape, color, attack_power;
	double size_of_body, move_length;

	//Determined the name of shape
	shape = CIRCULAR;

	
	//Enter a number for pokemon's color. Variable of color will be used printing color with void function. 
	color = 4;
	color = SetColor(color);

	
	//Calculate the area of shape.
	size_of_body = CreateBody (shape);

	
	//The function is returned for value of move. The value is thrown to move_length and printed on the screen with void.
	move_length = LoadMoves(shape, size_of_body);

	
	//A random attack power is determined based on user-entered intervals.
	attack_power = SetAttackPower (150, 170);

	
	//All are pressed by calling in the Void function.
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
	
	
	return 0;
}

double CreateBody (int shape){ //finding area 
	int side_length,short_side,long_side,radius;
	double area_of_shape;

	
	if(shape == 1){
		printf("Please! Enter the edge length of the square.\n");
		scanf("%d",&side_length);
		area_of_shape = side_length*side_length;
		//1 AREA OF SQUARE 
	}
	else if(shape == 2){
		printf("Please! Enter the edges length of the rectangular.\n");
		scanf("%d %d",&short_side, &long_side);
		area_of_shape=short_side*long_side;
		//2 AREA OF RECTANGULAR
	}
	else if(shape == 3){
		printf("Please! Enter the radius of circular.\n");
		scanf("%d",&radius);
		area_of_shape=PI*radius*radius;
		//3 AREA OF CIRCULAR
	}
	return area_of_shape;
}

int SetColor(int color){ //CALCULATING THE COLOR

	if(color <=1000 && color >=0)
		color = color%5;

	else 
		color = 1;
	return color;
}

double LoadMoves(int shape, double body_size){ //CALCULATING OF MOVEMENT AMOUNT
	double result,sonuc;

	if (shape == 1)
	{
		sonuc = sqrt(body_size);
		result = 4*sonuc;
		//SIDE OF SQUARE
	}

	else if(shape == 2){
		sonuc = body_size/5;
		result = 2*(sonuc+5);
	}

		//SIDE OF RECTENGULAR

	else if(shape == 3){
		sonuc = sqrt((body_size)/PI);
		result = ((2*PI)*sonuc);
		//RADIUS OF CIRCULAR
	}

	return result;
}

int SetAttackPower(int lower_bound, int upper_bound){ //FINDING THE NUMBER OF RANDOM ATTACK
	int bound;

	srand(time(NULL));
	bound = lower_bound + rand()%(upper_bound - lower_bound);

	return bound;
}

void ShowPokemon(int shape,double size_of_body, int color, double move_length, int attack_power){ //EKRANA BASTIRMA
	int move;
	int size;
	int count;
	int count2;
	int bosluk_uzunluk=(size/2)-1;
	int i,j,k,l,m,n=0;
	int dikey_uzunluk;
	int yatay_uzunluk;
	int count3;
	

	if(shape == 1){
		count = move_length/4;
		//move_length equals perimeter of the square. we can calculate a side of square.
		//we use a side of square to print the figure of square.

		for(i = 0;i < count; i++){
			for(j = 0; j < count; j++){
			printf("X");
		}
		printf("\n");
		}

		printf("Name:Square Pokemon\n");
		printf("Size:%lf\n",size_of_body);
	}

	else if(shape == 2){
		count = size_of_body/5;
		//size_of_body equals area of the rectengular. we can calculate a side of rectengular.
		//we know two sides of rectengular and we can print the figure of rectengular.

		for(i = 0;i < 5; i++){
			for (j = 0 ;j < count; j++)
			{
				printf("X");
			}
			printf("\n");
		}
		printf("Name:rectangular Pokemon\n");
		printf("Size:%lf\n",size_of_body);
	}
	else if(shape == 3){
		size = (sqrt(size_of_body/PI));
		//size_of_body equals area of the circle. we can calculate radius of the circle.
		//we know radius of circle and we can print the figure of circle.		

		//The algorithm runs differently by odd and even numbers.

	dikey_uzunluk = (size/2)+1;
	yatay_uzunluk = (size/2)+1;
	count = 0;
	count2 = 0;
	count3 = (size-3);

	if(size % 2 == 1){

		for(i = 0; i < dikey_uzunluk; i++){
			for(j = 1 ;j < yatay_uzunluk; j++){
				printf("	");
				//we should spacing. First row 
			}
			for(k = 0; k < 1; k++){
				printf("X");
				//the figure has only one 'X'.So the loop runs one time.
			}
			for(l = 0; l < count; l++){
				printf("	");
			}
			for(m = 0; m < count2 ; m++){
				printf("X");
			}
			printf("\n");
			
			for(; n<1; n++){
			count2++;
			}
			count+=2;
			yatay_uzunluk--;
		}

		count = 1;
		count2 = 1;
		n = 0;
		dikey_uzunluk = (size/2);

		for(i = 0; i < dikey_uzunluk ; i++){
			for(j = 0; j < count; j++){
				printf("	");
			}
			for(k = 0; k < 1; k++){
				printf("X");
			}
			for(l = 0;l < count3; l++){
				printf("	");
			}
			for(m = 0; m < count2; m++){
				if(i == (dikey_uzunluk-1)){
					printf("	");
				}
				else{
				printf("X");
			}

			}
			count++;
			count3-=2;
			printf("\n");
		}
		}
		
		k = 0;
		n = 0;
		int part_1_tab = (size/2)-1;
		int part_2_tab = (size/2)-1;
		dikey_uzunluk = (size/2)+1;
		yatay_uzunluk = (size/2)+1;
		count3 = (size-3);
		count = 1;
		count2 = 1;
if(size % 2 == 0){

	for(i = 0;i <= (size/2)-1; i++){
		if(i == (size/2)-1){
			printf("    ");
		}
		else{
		printf("	");
	
		}
	}
	printf("X\n");

	for (i = 1; i < dikey_uzunluk; i++)
	{
		for(j = 0;j < part_2_tab; j++){
			printf("    ");
			printf("	");
		}
		for(k = 0;k < 1; k++){
			printf("X");
		}
		for(l = 0;l < count; l++){
			printf("	");
		}
		for(m = 0 ;m < 1; m++){
			printf("X");
		}
		printf("\n");

		count+=2;
		part_2_tab--;

	}

	dikey_uzunluk = (size/2)-1;
	count3 = size-3;
	count2 = 1;

	for(i = 0;i < dikey_uzunluk; i++){
		for(j=0 ; j<count2; j++){
			printf("	");
		}

		for(k = 0; k < 1; k++){
			printf("X");
		}

		for(l = 0; l < count3; l++){
			printf("	");
		}

		for(m = 0;m < 1; m++){
			printf("X");
		}
		count2++;
		count3-=2;
		printf("\n");
	}
	for(i = 0 ;i <= (size/2)-1; i++){
		if(i == (size/2)-1){
			printf("    ");
		}
		else{
		printf("	");
	
		}
	}
	
	printf("X\n");

}
		printf("Name:Circle Pokemon\n" );
		printf("Size:%lf\n",size_of_body);
	}



	if(color == RED)
	printf("Color:RED\n");
	else if(color == YELLOW)
		printf("Color:YELLOW\n");
	else if(color == BLUE)
		printf("Color:BLUE\n");
	else if(color == BLACK)
		printf("Color:BLACK\n");
	else if(color == WHITE)
		printf("Color:WHITE\n");

	move = move_length;
	printf("Move:%d\n",move );

	printf("Attack Power:%d\n",attack_power );
}

 