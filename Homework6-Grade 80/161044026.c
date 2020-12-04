#include <stdio.h>
#define SIZE 50
void printmenu();
void menu();
int find_common_multipliers(int arr1[] , int arr2[] , int count1 , int count2 , int count3 , int count4, int result);
int multipliers(int number, int arr[], int count);
void merge_array(int arr[] , int size , int min , int max);
void merge_sort_number(int arr[] , int size , int min , int max);
int formula_function(int number);
int power(int num, int exponent);
int number_length(int number, int count);
int equal_function(int number , int length , int counter);
char capital_letter(char[] , int , int);
int string_length(char[]);

int main(){
	menu();
	return 0;
}

void menu(){	
	int number1;
	int number2;
	int arr[SIZE];
	int arr1[SIZE];
	int arr2[SIZE];
	int count1 = 0;
	int count2 = 0;
	int num ;
	int i;
	int number;
	int numberofdigit;
	int result = 0;
	int count;
	int res_func;
	int counter = 0;
	char user_input[250];
	char output;
	int length;
	int lengthlist;

	int choice;
	do{
		printmenu();
		scanf("%d",&choice);
		if( choice < 1 || choice > 6){
			printf("\nThis is an invalid choice. Try again!\n \n");
		}
		else{
			switch (choice){ //The menu executes here.
					case 1:
						printf("Please!Enter the numbers.\n");
						scanf("%d%d", &number1, &number2);
						count1 = multipliers(number1, arr1 , count1);
						count2 = multipliers(number2, arr2 , count2);
						if(count1 > count2){ //The comparison finds which one is that have more than multipliers elements. The comparison sends the crowded array to the function.
							result = find_common_multipliers(arr1 , arr2 , count1 , count2 , 0 , 0 , 1);
						}
						else{
							result = find_common_multipliers(arr2 , arr1 , count2 , count1 , 0 , 0 , 1);
						}
						if(result == 1 || result == 0){							
							printf("These numbers dont have common multipliers!\n");
						}
						else
							printf("%d\n", result );
							break;
					case 2:
						printf("Enter the length of the list :\n");
						scanf("%d", &lengthlist);
						printf("Enter the elements of list :\n");
						for(i = 0 ; i < lengthlist ; i++){
							scanf("%d" , &arr[i]);
						}
						printf("I can write only division part.");
						merge_sort_number(arr , lengthlist , 0 , lengthlist -1);
						break;
					case 3:
						printf("Please! Enter the number.\n");
						scanf("%d" , &number);
						while(number < 0){
							printf("Please!Enter positive number.\n");
							scanf("%d" , &number);}
						result = formula_function(number);
						break;
					case 4:
						result = 0;
						count = 1 ;
						counter = 0;
						printf("Please!Enter the number.\n");
						scanf("%d" , &number);
						numberofdigit = number_length(number , count); //The function calculates the number of digit.
						res_func = equal_function(number , numberofdigit , counter);
						if(res_func == number){
							printf("Equal!\n");
						}
						else
							printf("Not Equal!\n");
						break;
					case 5:
						count = 0;
						printf("Please enter a string.\n");
						scanf("%s", user_input); //It takes string.
						length = string_length(user_input); //The function for calculates the length of string.
						output = capital_letter(user_input , count ,length); 
						if(output == '\0'){
							printf("The string doesnt have any capital letter.");
						} 
						else
						printf("%c\n", output);
						break;
			}
		}
	}
	while(choice !=6);
}
int find_common_multipliers(int arr1[] , int arr2[] , int count1 , int count2 , int count3 , int count4 , int result){ //For part1
	result = 1;
	if(count3 < count1){ //The function makes comparison according to arr1.
		if(arr1[count3] == arr2[count4]){ //If the multipliers are equal, the element of arr2 is equaled to 0 to compare the next elements of the arr1.
			arr2[count4] = 0;
			return result = arr1[count3]*find_common_multipliers(arr1 , arr2 , count1 , count2 , count3 + 1 , 0 , result); //The function is continued with the next element of arr1.
			} //The result is equal to elemnet of arr1 and next element of arr1.
		else if(arr1[count3] != arr2[count4]){ //If the numbers are not equal , there are two possibilities.
			if(count4 < count2 -1){ //If the function doesnt reach the end of arr2, it must look the next element of arr2.
				return find_common_multipliers(arr1, arr2 , count1 , count2 , count3 , count4 + 1 , result);
			}
			else{ //If the function doesnt reach  the end of arr2, it must look to the next element of arr1.
				arr1[count3] = 0; 
				return find_common_multipliers(arr1 , arr2 , count1 , count2 , count3 + 1 , 0 , result);
			}
		}
	}
	return result;
}
int multipliers(int number, int arr[15],int count){ //For part1
	int i = 2; //i starts 2 because 1 always divides all numbers.
	while(number > 1 && i <= number){ //The function finds multipliers of a number.
		if(number % i == 0){ //If the number divides by i,
			arr[count] = i; //the number is sent array
			count++;//count increases 1
			number /= i; //the number divides i. i isn't increased because the number can has i multiplier more than one.
		}
		else{
			i++; //If i isnt multipliers of number, i is increased.
		}
	}
	return count;
}
void merge_sort_number(int arr[] , int size , int min , int max){
	int mean;
	if(mean > 1){
		mean = size / 2;
		merge_sort_number(arr , size , min , mean); //to divide the array half. This part is first half.
		merge_sort_number(arr , size , mean + 1, max); //This part is second half.
		merge_array(arr , size , min , max ); 
	}
} //ı cant contiue this part
void merge_array(int arr[] , int size , int min , int max){
	size++;
}
int formula_function(int number){//For part3
	printf("%d\n", number );
	if(number == 1){ //1 is the last element. The function returns void menu.
		return 1;
	}
	else if(number % 2 == 0){ //If the number divides by 2, the function calls same function with number/2.
		return formula_function(number/2);
	}
	else 
		return formula_function((3*number) + 1);
}
int equal_function(int number , int length , int counter ){//For part4
	int ans = 0;
	if(counter <= length){ //If the counter is less than length, all digit of the number doesnt calculate.
		ans = power(number % 10 , length) + equal_function(number / 10 , length , counter + 1);
	}
		return ans;
}
int power(int num , int exponent){//For part4
	if(exponent >= 1){
		return num* power(num , exponent - 1);
	}
	return 1;
}
int number_length(int number, int count){//For part4
	if(number/10 > 0){	//If the number is bigger than 0, the function returns itself and count increases 1.
		return number_length(number / 10 , count + 1);
	}
	return count;
}
char capital_letter(char user_input[] , int count, int length ){ //for part5
	if(user_input[count] >= 'A' && user_input[count] <= 'Z'){//If function meet a capital letter, it returns this letter.
		return user_input[count];
	}
	else if(count == length){//If count equals length , this means the string finishes and the function doesnt find any capital letter.
		return '\0';
	}
	else{
		return capital_letter(user_input,count+1,length); //If the function is here, it still dont find a capital letter. So it returns itself.
	}	
}
int string_length(char str[]){ //The function finds the length of string. //for part5
	int i = 0;
	int counter = 0;
	while(str[i] != '\0'){
		i++;
		counter++;
	}
	return counter;
}

void printmenu(){//The function only print menu.
	printf("\n\n***** MENU *****\n1)Find multipliers of numbers\n2)Sorting array\n3)Calculate the output numbers\n4)Equal or Not Equal\n5)Find the first capital letter\n6)Exit\n");
	return;}