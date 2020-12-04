#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}return counter;
}
void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}
void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}
void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}
void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
void crossword_area(char area[15][15] , char *dictionary[] , int coordinate[][4], int counter){
	int i;
	int j;
	int k = 0;
	int l;
	int m;
	int count = 0 ;
	int letter_count;

	for( i = 0 ; i < 15 ; i++){
		for( j = 0 ; j < 15 ; j++){
			area[i][j] = 97 + rand() % 25;
		}
	}

	while(k < 15){
		for(i = 0 ; i < 15 ; i++){
			for(j = 0 ; j < 15 ; j++){
				if(i == coordinate[k][1] && j == coordinate[k][0]){
					if(coordinate[k][3] == coordinate[k][1] && coordinate[k][0] < coordinate[k][2]){ //north the south
					letter_count = coordinate[k][2] - coordinate[k][0];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]+l][coordinate[k][1]] = dictionary[k][l];
						}
					}
					else if(coordinate[k][3] == coordinate[k][1] && coordinate[k][0] > coordinate[k][2]){ //from south to north
					letter_count = coordinate[k][2] - coordinate[k][0];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]-l][coordinate[k][1]] = dictionary[k][l];
						}
					}
					else if(coordinate[k][1] < coordinate[k][3] && coordinate[k][0] == coordinate[k][2]){ //from wset to east
					letter_count = coordinate[k][3] - coordinate[k][1];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]][coordinate[k][1]+l] = dictionary[k][l];
						}
					}
					else if(coordinate[k][1] > coordinate[k][3] && coordinate[k][0] == coordinate[k][2]){ //from east to west
					letter_count = coordinate[k][3] - coordinate[k][1];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]][coordinate[k][1]-l] = dictionary[k][l];
						}
					}
					else if(coordinate[k][1] < coordinate[k][3] && coordinate[k][0] < coordinate[k][2]){ //guneydogu
						letter_count = coordinate[k][3] - coordinate[k][1];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]+l][coordinate[k][1]+l] = dictionary[k][l];
						}
					} 
					else if(coordinate[k][1] > coordinate[k][3] && coordinate[k][0] < coordinate[k][2]){ //kuzeydogu
					letter_count = coordinate[k][0] - coordinate[k][2];
						for(l = 0 ; l < letter_count + 1 ; l++){
							area[coordinate[k][0]-l][coordinate[k][1]+l] = dictionary[k][l];
						}
					}
				}
			}
		}
		k++;
	}

}

int control_users_word(char word[15], char *dict[DICT_SIZE] , int coordinate[][4]);
int compare_function(char users_word[], char *dict[]);
int control_users_coordinate(char area[15][15], int user_coord[2] , char word[10] , int number);
int word_length(char word[15]);
void print_area(char area[15][15]);


int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
    char area[15][15];
	FILE *fp = fopen("word_hunter.dat", "r");
	char users_word[15];
	int ret_control_word = 0;
	int flag_word = 0;
	int counter = 0;
	int number;
	int user_coord[2];
	char ch[10] = "kikirdak";
	int ret_value;

	int i = 0;
	int j;

	int result;
	int exit_result;
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);

	//print_coord(coord);
	
	// WRITE HERE...

	srand(time(NULL));

	crossword_area(area , dict , coord, dict_counter);//to locate words


	do{
		for(; i < 1 ; i++){
			printf("\n");
			print_area(area);
		}
		printf("Enter word : ");
		scanf("%s", users_word);
		ret_control_word= compare_function(users_word , dict);
				if (ret_control_word == 0){

					number = i ;
					printf("Please, enter the row and column numbers.\n");
					for(j = 0 ; j < 2 ; j++){
						scanf("%d",&user_coord[j]);
					}
						ret_value=control_users_coordinate(area, user_coord, users_word, number);
			            
			          		if(ret_value==0){ 
			          		printf("Correct guess\n");
						i = 16;
						counter++;
						printf("\n\n\n");
						print_area(area);            
					        }
			           	
		 				else{
		 					printf("Wrong guess\n");
		 			
		 				}
				
				}
				else{
				printf("Wrong word!\n");
				}
	}
	while(counter < 15);

	printf("Congrulations. You found all words.\n");
	
	return 0;
}

int compare_function(char users_word[10], char *dict[]){
 	int i = 0;
 	int j = 0;
 	int result = -1;
 	char exit_users_word[12] = "exit game";
 	int flag = 0;
	int length = 0;


	    for (i = 0 ; i < 15 ; i++){	
	    	for(j = 0; users_word[j] == dict[i][j] && users_word[j] != '\0' && dict[i][j] != '\0'; j++){
			  
				if(j == word_length(users_word)-1){
			   	return 0;
			
				}
		
		}
	}  
 	return -1;

}

int control_users_coordinate(char area[15][15], int user_coord[2] , char word[10] , int number){//the function check that user sents coordinates
	int i;
	int j;
	int r1;
	int c1;
	int r2;
	int c2;
	int length;
	int counter = 0;
	int ret_value = -1;

	r1 = user_coord[0];
	c1 = user_coord[1];


	length = word_length(word);
	counter = 0;
	for(i = 0 ; i < length ; i++){
		if(area[r1][c1 + i] == word[i]|| area[r1][c1 + i] == word[i] - 32){//the condition is for from west to east coordinates.
			counter++;
		}
	}
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1][c1+i] >= 'a' && area[r1][c1+i] <= 'z')
			area[r1][c1+i] -= 32;
		}
		return ret_value;
	}
	counter = 0;
    for(i = 0; i < length ; i++){
    	if(area[r1][c1 - i] == word[length-1-i]|| area[r1][c1 - i] == word[length-1-i] - 32){//the condition is for from east to west
			counter++;
		}
    }
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1][c1-i] >= 'a' && area[r1][c1-i] <= 'z')
			area[r1][c1-i] -= 32;
		}
		return ret_value;
	}
	counter = 0;
	for(i = 0 ; i < length ; i++){
		if(area[r1+i][c1 + i] == word[i] || area[r1+i][c1 + i] == word[i] - 32){//the condition is for fromsouth to east //hepsine koy son sarti
			counter++;
		}
	}
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1+i][c1+i] >= 'a' && area[r1+i][c1+i] <= 'z')
			area[r1+i][c1+i] -= 32;
		}
		return ret_value;
	}
	counter = 0;
   	 for(i = 0; i < length ; i++){
    		if(area[r1-i][c1 - i] == word[length-1-i]|| area[r1-i][c1 - i] == word[length-1-i] - 32){//the condition is for from north to westburada kaldı
			counter++;
		}
   	 }
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1-i][c1-i] >= 'a' && area[r1-i][c1-i] <= 'z')
			area[r1-i][c1-i] -= 32;
		}
		return ret_value;
	}
	counter = 0;
	for(i = 0 ; i < length ; i++){
		if(area[r1+i][c1] == word[i]|| area[r1+i][c1 ] == word[i] - 32){//the condition is for from north to south
			counter++;
		}
	}
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1+i][c1] >= 'a' && area[r1+i][c1] <= 'z')
			area[r1+i][c1] -= 32;
		}
		return ret_value;
	}
	counter = 0;
  	for(i = 0; i < length ; i++){
    	if(area[r1-i][c1] == word[length-1-i] || area[r1-i][c1] == word[length-1-i] - 32){// the condition is for from south to north
			counter++;
		}
	}
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1-i][c1] >= 'a' && area[r1-i][c1] <= 'z')
			area[r1-i][c1] -= 32;
		}
		return ret_value;
	}
	counter = 0;
	for(i = 0 ; i < length ; i++){
		if(area[r1-i][c1 - i] == word[length-1-i] || area[r1-i][c1 -i] == word[length-1-i] - 32){//the condition is for from north to west
			counter++;
		}
	}
	//printf("%dI M HERE\n",counter);
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1-i][c1-i] >= 'a' && area[r1-i][c1-i] <= 'z')
			area[r1-i][c1-i] -= 32;
		}
		return ret_value;
	}
	counter = 0;

    for(i = 0; i < length ; i++){
    	if(area[r1-i][c1 + i] == word[length-1-i] || area[r1-i][c1 + i] == word[i] - 32){//the condition is for from north to east
			counter++;
		}
    }
	if(counter == length){
		ret_value = 0;
		for( i=0 ; i < length ; i++){
			if(area[r1-i][c1+i] >= 'a' && area[r1-i][c1+i] <= 'z')
			area[r1-i][c1+i] -= 32;
		}
		return ret_value;
	}
	return ret_value;
}


void print_area(char area[15][15]){//the function only prints the puzzle area.
	int i;
	int j;
	for(i = 0 ; i < 15 ; i++){
		for(j = 0 ; j < 15 ; j++){
			printf("%c ", area[i][j] );
		}
		printf("\n");
	}
}
int word_length(char word[15]){//for find the word length
	int count = 0;
	int i;

	while(word[count] != '\0'){//if word[count] isn t null, count will increase. So we find word length.
		count++;
	}
	return count;
}
