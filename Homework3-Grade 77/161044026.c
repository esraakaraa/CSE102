#include <stdlib.h>
#include <stdio.h>

void main_menu();
int calculator_menu();
int add(int number1,int  number2);
int sub(int number1,int  number2);
int mult(int number1,int  number2);
int division(int number1, int  number2);
int power(int number1,int  number2);
int mod(int number1,int  number2);
int doit(int func(),int first_number,int second_number);


int calculator_grade_menu();
int take_grades(int []);
int take_exam_grades(int[]);
double calculate_homework(int[]); 
double calculate_lab(int[]); 
double calculate_all(int homework,int exams[],int lab);


void shape_menu();
void shape(int up, int down);
void up_traingle(int up);
void down_triangle(int down);

int main(){

main_menu();

return 0;
}

void main_menu() {
    char operation;
    int count=1;

    printf("1: Calculator\n");
    printf("2: Calculator of Grades\n");
    printf("3: Shape\n");
    printf("Please.Enter the operation!\n");

    scanf("%c",&operation);
    while(count==1){

        switch (operation) {
            case '1':
                calculator_menu();
            break;

            case '2':           
         		calculator_grade_menu();
       	    break;

		    case '3':
			shape_menu();
            break;

            case '4':
            break;
        }

        scanf("%c",&operation);

    }
}


int calculator_menu(){
	    char operation[2];
	    int result;
	    char number1;
	    char number2;
	    int num1;
	    int num2;
	    int i = 0;
	    int count = 1;
	    int temp;
	    double result_division;

		    printf("\n\n+ : Add two numbers.\n");
		    printf("- : Subtraction two numbers.\n");
		    printf("/ : Divide two numbers.\n");
		    printf("* : Multiplication two numbers.\n");
		    printf("%% :  Find the remainder numbers. \n");
		    printf("^ : Exponentiaton two numbers.\n");
		    printf("Q : Quit\n\n");

	    for( i = 0 ; i < count ; i++){
	    	printf("Please!Enter the operation!\n");

	        scanf(" %s", operation);

	        switch (*operation) {
	            case '+':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                   	
	                    scanf("%d" , &num1);

	                    printf("\nPlease!Enter the second number!\n"); 
						//scanf("%[^\n]%*c",);

						if(number2 == ' '){
							num2 = 0;
	               		}
	                	else if(number2 != ' '){              		
		                    scanf("%d", &num2);
	                	}
	                }
	                else{
	                    num1 = temp;
	                    printf("\nPlease!Enter the second number!\n"); 						number2 = getchar();
						if(number2 == '\n'){
						num2 = 0;
	               		}
	                	else if(number2 != '\n'){                		
	                    scanf("%d", &num2);
	                	}
	                    scanf("%d", &num2);

	                }
	                result = doit(add, num1, num2);
	                printf("Result : %d\n", doit(add, num1, num2));
	                break;

	            case '-':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                    scanf(" %d",&num1);
	                    printf("\nPlease!Enter the second number!\n"); 
	                    scanf(" %d",&num2);
	                }
	                else{
	                    num1 = temp;
	                    scanf("%d", &num2);

	                }result = doit(sub, num1, num2);
	                printf("Result : %d\n", doit(sub, num1, num2));
	                break;

	            case '*':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                    scanf(" %d",&num1);
	                    printf("\nPlease!Enter the second number!\n"); 
	                    scanf(" %d",&num2);
	                }
	                else{
	                    num1 = temp;
	                    scanf("%d", &num2);

	                }
	                result = doit(mult, num1, num2);
	                printf("Result : %d\n", doit(mult, num1, num2));
	                break;

	            case '/':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                    scanf(" %d",&num1);
	                    printf("\nPlease!Enter the second number!\n"); 
	                    scanf(" %d",&num2);
	                }
	                else{
	                    num1 = temp;
	                    scanf("%d", &num2);

	                }
	                result_division = doit(division, num1, num2);
	                printf("Result : %lf\n", result_division);
	                break;

	            case '^':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                    scanf(" %d",&num1);
	                    printf("\nPlease!Enter the second number!\n"); 
	                    scanf(" %d",&num2);
	                }
	                else{
	                    num1 = temp;
	                    scanf("%d", &num2);

	                }
	                result = doit(power, num1, num2);
	                if(num2 == 0){
	                    printf("1");
	                }
	                else if(num2 < 0){
	                    printf("Result : 1/%d",doit(power,num1 , num2));
	                }
	                else {
	                    printf("Result : %d\n", doit(power, num1, num2));
	                }
	                break;

	            case '%':
	                if(i == 0){
	                    printf("\nPlease!Enter the first number!\n");
	                    scanf(" %d",&num1);
	                    printf("\nPlease!Enter the second number!\n"); 
	                    scanf(" %d",&num2);
	                }
	                else{
	                    num1 = temp;
	                    scanf("%d", &num2);

	                }
	                result = doit(mod, num1, num2);
	                printf("Result : %d\n", doit(mod, num1, num2));
	                break;

	            case 'Q':
	                count = -1;
	                main_menu();
	                break;

	            case 'q':
	                count = -1;
	                main_menu();
	                break;
	        }

	        temp = result;
	        count++;
	    }
	    return 0;
	}

	int doit(int func(),int first_number,int second_number){
	    int result;
	    int sum;
	    result = func(first_number,second_number);

	    return result;
	}

	int add(number1, number2){
	    int sum;
	    sum = number1 + number2;
	    return sum;
	}
	int sub(number1, number2){
	    int sum;
	    sum = number1 - number2;
	    return sum;
	}
	int mult(number1, number2){
	    int sum;
	    sum = number1 * number2;
	    return sum;
	}

	int division(int number1, int number2){
	    double sum;
	    while(number2 == 0){
	        printf("You entered '0' . The result cannot be calculated.\n");
	        printf("Please!Enter the number!\n");
	        scanf("%d", &number2);
	    }
	        sum = number1 / number2;

	    return sum;
	    }

	int power(number1, number2){
	    int sum = 1;

	    if(number2 == 0){
	        sum = 1;
	    }
	    else if(number2<0) {
	        number2 = -number2;
	        for (int i = 0; i < number2; i++) {
	            sum *= number1;
	        }
	    }
	     else if(number2>0){
	         for(int i = 0; i < number2 ; i++){
	             sum *= number1;
	         }
	     }
	    return sum;
	}
	int mod(number1, number2){
	    int sum;
	    sum = number1 % number2;
	    return sum;
	}

int calculator_grade_menu(){
		int hw_grades[10] ;
		int lab_grades[10] ;
		int exams[2] ;
		int homework;
		int lab;
		double total;
	
		printf("\nPlease!Enter the homework grades.\n");	
		homework = calculate_homework(hw_grades);//call the function for the grades of lab
			
		printf("\nPlease!Enter the lab grades.\n");
		lab = calculate_lab(lab_grades);//call the function for the grades of lab

		total = calculate_all(homework, exams,lab);
			
		printf("\nORT = %lf\n", total );

		main_menu();
	}
	int take_grades(int grades[]){
	int i;
	
	for(i = 0; i < 10; i++){//The loop scans the grades of homework
	scanf("%d",&grades[i]);
	}
}

	int take_exam_grades(int grades[]){
		int i;
		for(i = 0; i < 2 ; i++){
			scanf("%d",&grades[i]);
			printf("%d\n",grades[i] );
		}
	}

	double calculate_homework(int hw_grades[]){ //The function calculates the average of homework.
		int i;
		double sum = 0;
		take_grades(hw_grades);
		for(i = 0 ; i < 10 ; i++){
			sum += hw_grades[i];
		}
		sum = sum /10.0;
		printf("%lf\n",sum );
		return sum;
	}

	double calculate_lab(int lab_grades[]){//The function calculates the average of lab.

		int i;
		double sum = 0;
		take_grades(lab_grades );
		for(i = 0 ; i < 10 ; i++){
			sum += lab_grades[i];
		}

		sum=sum /10.0;
		printf("%lf\n",sum );

		return sum;
	}
	 double calculate_all(int homework, int exams[],int lab){
	 	double total = 0;
	 	double midterm;
	 	double final,hw,l;

	 	take_exam_grades(exams);
	 	printf("%d\n",exams[0] );
			midterm = (exams[0] * 30) / 100.0;
			printf("midterm : %.lf\n",midterm );
		
			final = (exams[1] * 40) / 100.0;
			printf("Final : %.lf\n",final );

			hw = (homework * 10) / 100.0;
			printf("Hw : %.1f\n",hw );

			l = (lab * 20 ) /100.0;
	        printf("Lab : %.1f\n",l );

		total = midterm + final + hw + l ;

	 	return total;
	 }


void shape_menu(){
	int height;
	int down;

	printf("\nPlease!Enter the height\n");
	scanf("%d",&height);
	down = height ;
	shape(height, down);
	main_menu();
}


void shape(int up, int down){
	up_traingle(up);
	down_triangle(down);


}

void up_traingle(int up){
	int i, j ;
	int star_counter = 1;
	int space = up;

	for(i = 0 ; i < up ; i++){
		for(j = 0 ; j < (space-1) ; j ++){
			printf(" ");
		}
		space--;
		printf("/");
		if(i != 0){
			for(j = 0; j < star_counter; j++){
				printf("**");
			}
			star_counter++;
		}
		printf("\\\n");
	}
}
void down_triangle(int down){
	int i , j;
	int star_counter = (down)-1;
	int space = 1;

	for(i = 0; i < down ; i++){
		if(i != 0){
			for(j = 0 ; j < space ; j++){
				printf(" ");
			}
			space++;
		}
			printf("\\");
		for(j = 0 ; j < star_counter ; j++){
			printf("**");
		}
		star_counter--;
		printf("/\n");
	}
}

