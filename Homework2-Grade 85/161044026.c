#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	void menu();
	int make_a_guess (int trial, int min, int max);
	void show_scores(int score_human, int score_program);
	void draw_hourglass (int height);
	void draw_mountain_road (int length, int max_radius);
	void score(int user, int program);
	int main(){
	srand(time(NULL));
	menu();
	return 0;
}
void menu(){
	int choice;
	int lucky_number;
	int guess_number;
	int trial;
	int difference;
	int distance;
	int min=1;
	int max=1024;
	int height_of_hourglass;
	int length;
	int max_radius;
	int count=0;
	int score_human = 0, score_program = 0;
	int i, j, k;

	while(choice >= 1 && choice <= 4){ //The user chooses menu's section.

	printf("***** MENU *****\n");
	printf("1.Play Lucky Number\n");
	printf("2. Draw Hourglass\n");
	printf("3. Draw Mountain Road\n");
	printf("4. Exit\n");


	scanf("%d",&choice);

	while( choice < 1 || choice > 4){ //If user chooses wrong section, user must choose new section again and again.
		printf("\nThis is an invalid choice. Try again!\n \n");
		printf("***** MENU *****\n");
		printf("1.Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\n");
		scanf("%d",&choice);	
	}

		switch (choice){ //The menu executes here.
			case 1: //Lucky Number
			lucky_number = 1 + rand()% 1023 ; //Computer randomises a number.
			printf("\nPlease!Enter the trial number!\n");
			scanf("%d", &trial); 	//User enter trail number.
			min = 1;
			max = 1024;
			for(i=0;i<trial;i++){ //Loop return trial times.
//			guess_number = 	make_a_guess(trial , min , max);
			if(trial>0){
				if(guess_number == lucky_number){ //If user finds lucky number, trial number becomes -1. So loop ends.
				printf("Distance: 0. You win!!\n");
				count = 1; //If the user finds count becomes 1 instead of 0.
				trial=-1;
				}

				else if(trial>0 && guess_number != lucky_number){//This part prints distance to guess number from lucky number.
				printf("(Trial:%d) ",(i+1) );
				guess_number = 	make_a_guess(trial , min , max);
				//printf("guessing altinda 	%d %d\n", min, guess_number);
					difference = lucky_number - guess_number;	
					if(difference > 0){
						if(difference <= 1023 && difference >= 512){
							min = guess_number ;
						printf("Distance: 10\n");
						}
						else if(difference <= 511 && difference >= 256){
							min = guess_number;
						printf("Distance: 9\n");
						}
						else if(difference <= 255 && difference >= 128){
							min = guess_number;							
						printf("Distance: 8\n");
						}
						else if(difference <= 127 && difference >= 64){
							min = guess_number;
						printf("Distance: 7\n");
						}
						else if(difference <= 63 && difference >= 32){
							min = guess_number;
						printf("Distance: 6\n");
						}
						else if(difference <= 31 && difference >= 16){
							min = guess_number;
						printf("Distance: 5\n");
						}
						else if(difference <= 15 && difference >= 8){
							min = guess_number;
						printf("Distance: 4\n");
						}
						else if(difference <= 7 && difference >= 4){
							min = guess_number;
						printf("Distance: 3\n");
						}
						else if(difference <= 3 && difference >= 2){
							min = guess_number;
						printf("Distance: 2\n");
						}
						else if(difference == 1){
							min = guess_number;
						printf("Distance: 1\n");
						}
					}
					else if(difference < 0){ //If guess number is bigger than lucky number. Difference multiplies -1.
						difference = -difference;
						if(difference <= 1023 && difference >= 512){
							max = guess_number ;
						printf("Distance: 10\n");
						}
						else if(difference <= 511 && difference >= 256){
							max = guess_number;
						printf("Distance: 9\n");
						}
						else if(difference <= 255 && difference >= 128){
							max = guess_number;							
						printf("Distance: 8\n");
						}
						else if(difference <= 127 && difference >= 64){
							max = guess_number;
						printf("Distance: 7\n");
						}
						else if(difference <= 63 && difference >= 32){
							max = guess_number;
						printf("Distance: 6\n");
						}
						else if(difference <= 31 && difference >= 16){
							max = guess_number;
						printf("Distance: 5\n");
						}
						else if(difference <= 15 && difference >= 8){
							max = guess_number;
						printf("Distance: 4\n");
						}
						else if(difference <= 7 && difference >= 4){
							max = guess_number;
						printf("Distance: 3\n");
						}
						else if(difference <= 3 && difference >= 2){
							max = guess_number;
						printf("Distance: 2\n");
						}
						else if(difference == 1){
							max = guess_number;
						printf("Distance: 1\n");
						}
					}
				}	
			}			
	}
			if(count == 1){ // If count is 1, score of human increases one time.
				score_human++;
				show_scores(score_human, score_program);
			}
			else if(count== 0 ){ //If the user doesn't find lucky number, count remains 0.If count is 0, scor of program increases one time.
				score_program++;
				show_scores(score_human, score_program);
			}
			count = 0;//Count becomes 0 for next games.
			break;//The Lucky number game finishes here.

			case 2: //Draw Hourglass
				printf("Please!Enter the number of hourglass.\n");
				j=1;	
					for(i=0;i<j;i++){//The for loop executes differently depending on whether the entered number is odd or even.
						scanf("%d",&height_of_hourglass); 
						if( height_of_hourglass % 2 == 0){//If the entered number is even, j increases repeatedly.
							printf("Please!Enter a odd number.\n");
							j++;
						}
						if( height_of_hourglass % 2 ==1){//If the entered number is odd, j becomes 1. So the loop stops.
							draw_hourglass(height_of_hourglass);
							j=i;
						}
					}				
			break;
			
			case 3: //Draw Mountain Road
				scanf("%d %d", &length, &max_radius);
				draw_mountain_road (length,max_radius);
				break;

			case 4: 
			choice=0;
				break;
		}
	}
}
int make_a_guess (int trial, int min, int max){//The function prints the estimation interval and returns the predicted number to the menu.
	int guess_number;
	printf("Make a guess between %d and %d:", min , max);
	scanf("%d", &guess_number);
	return guess_number;
}
void show_scores(int score_human, int score_program){
	printf("User Score : %d. Program Score: %d\n",score_human,score_program); //example
	printf("\n");
	menu();
}
void draw_hourglass (int height){//The function prints the hourglass in two pieces. 
	int length;
	int dikey;
	int temp=height;
	int vertical_length;
	int gap_length;
	int star_length;
	int count=0;
	int i,j,k;

	dikey=(height/2)+1;
	printf("\n");
	for(i = 0 ; i < dikey ; i++ ){//This for loop first piece. The loop determines the number of rows.
		for(j=0;j<count;j++){
			printf(" ");
			}
		for(k=height;k>0;k--){
			printf("*");
			}
		count++;
		height-=2; // Height decreases two times. So we can get the triangle.
		printf("\n");
	}
	height=temp;
	vertical_length=(height/2);
	gap_length=(height/2)-1;
	star_length=3;

	for(i=0;i<vertical_length;i++){//The loop determines the number of rows.
		for(j=0;j<gap_length;j++){
			printf(" ");
		}
		for(k=0;k<star_length;k++){
			printf("*");
		}
		printf("\n");

	star_length+=2;
	gap_length--;
	}
	printf("\n");
	menu();
	}

void draw_mountain_road (int length, int max_radius){
	printf("%d %d\n",length,max_radius );
	int random_radius;
	int random_min_radius=1;
	int random_max_radius=max_radius;
	int count;
	int counter;
	int number_of_row=0;
	int i , j , k , l, m =0, n , r;
	int max_possibility = -1;
	int temp = 1;
	int temp_random_radius1;
	int temp_random_radius2;
	int real_radius ;
	int temp_real_radius;
	int temp_random_radius3;
	int temp_random_radius;
	int r_r;

	printf("\n");

	for(i = 0; i < length; i++){
		count=1;
		if(m == 0){
		random_radius = random_min_radius + rand()% max_radius;
		real_radius = random_radius ;
		temp_real_radius = random_radius;
		temp_random_radius1 = random_radius-1;
		temp_random_radius3 = 1;
		temp_random_radius2 = random_radius;
		r_r = random_radius;
		}	

		if(number_of_row%2==0 && number_of_row == 0){
			if(m != 0){
				//random_radius = max_radius - max_possibility -1;
				random_radius = random_min_radius+ rand() % real_radius;	
				temp_random_radius1 = real_radius - 1;			
				temp_random_radius3 = real_radius - random_radius -3;	
				temp_random_radius2 = random_radius;
				temp_random_radius = real_radius- random_radius ;
			}				
			for (n = random_radius  ; n > 0; n--){			
				for(j=0;j<temp_random_radius1 +1;j++){
					printf(" ");
				}		
				temp_random_radius1--;
				printf("/\n");
			}

			for(l=0;l<1;l++){
				for(j = 0; j < temp_random_radius ; j++){
					printf(" ");
				}
				printf("|\n");
				}

			for(r = 0 ; r < temp_random_radius2 +1 ; r++){
				for(k = 0; k < count ; k++){
					printf(" ");
				}
				printf("\\\n");
				count++;
			}
		}

			if(number_of_row % 2 == 0 && number_of_row != 0){
				if(m != 0){
				//random_radius = max_radius - max_possibility -1;
				random_radius = random_min_radius+ rand() % real_radius;	
				temp_random_radius1 = r_r - 1;			
				temp_random_radius3 = real_radius - random_radius -3;	
				temp_random_radius2 = random_radius;
				temp_random_radius = real_radius- random_radius ;
			}				
			for (n = random_radius  ; n > 0; n--){			
				for(j=0;j<temp_random_radius1 + 2;j++){
					printf(" ");
				}		
				temp_random_radius1--;
				printf("/\n");
			}

			for(l=0;l<1;l++){
				for(j = 0; j < temp_random_radius +1; j++){
					printf(" ");
				}
				printf("|\n");
				}

			for(r = 0 ; r < temp_random_radius2 +1 ; r++){
				for(k = 0; k < temp_random_radius1 + 3 ; k++){
					printf(" ");
				}
				printf("\\\n");
				temp_random_radius1++;
			}

			}
			random_max_radius = max_radius - real_radius - 1 ;
			
			if(number_of_row%2==1){

				if(m != 0){
					//random_radius = random_min_radius+ rand() % random_max_radius;
					random_radius = (random_min_radius+ rand() % real_radius)+1;	
					temp_random_radius1 = real_radius ;			
					temp_random_radius3 = real_radius - random_radius -3;
					temp_random_radius = real_radius - random_radius + 1 ;
				}				
				temp_random_radius2 = random_radius;
				random_radius++;

				for (n = random_radius; n > 0; n--){
					for(j =temp_real_radius +2; j > 0 ; j --){
						printf(" ");

					}
					printf("\\\n");
					temp_real_radius++;
					j++;

					}
					for(l = 0; l < temp_real_radius + 2; l++){
						printf(" ");
					}
					
					printf("|\n");

				for(n = random_radius; n > 0; n-- ){
					for(l = 0; l < temp_real_radius+1; l++){
						printf(" ");
						}
					temp_real_radius--;

					printf("/\n");
					}
			}

			number_of_row++;
			m++;

	}
}