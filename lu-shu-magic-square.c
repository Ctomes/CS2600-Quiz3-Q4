//CS2600 Quiz 3 Question 4.2

//create a print function that can print a 3x3 array.

    //takes an int array as an arg
    // display each element aligned for legibility.


//create a function that can determine if an array meets LSMS "Lu Shu Magic Square" requirements.

    //take an array as an arguement.
    //test 3 rows ==15?
    //test 3 columns ==15?
    //test 2 diagonals ==15?

//part 2.
//main:
    //randomly generate some arrays and test each matrix for validity.
    //record each iteration.
    //print total number of squares generated before success.
    //print the successful result.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
void printMatrix(int arr[3][3])//print matrix to screen.
{
    printf("3 x 3  Matrix\n+---+---+---+\n");

    for(int i = 0;i<3;++i)
    {
        for(int j = 0; j<3; ++j)
        {
            int temp = arr[i][j];
            printf("| %d ",temp);
        }
        printf("|\n+---+---+---+\n");
    }

}
int testMatrix(int arr[3][3])
{
    
    for(int i =0; i < 3; i++)
    {
    //test rows
      if(15 != arr[i][0] + arr[i][1] + arr[i][2])
      {
        //printf("Failed in row\n");
        return FALSE;
      }
    //test columns
      if(15 != arr[0][i] + arr[1][i] + arr[2][i])
      {
        //printf("Failed in column\n");
        return FALSE;
      }
    }
    //test diagonals.
    if(15 != arr[0][0] + arr[1][1] + arr[2][2])
    {
        //printf("Failed Diagonal top left -> bottom right\n");
        return FALSE;
    }
    if(15 != arr[0][2] + arr[1][1] + arr[2][0])
    {
        //printf("Failed Diagonal bottom left -> top right\n");
        return FALSE;
    }

return TRUE;
}
int validateSquare(int arr[3][3]){ //validate no longer prints matrix since its called many times. return is now a bool for our loop condition.
    if(testMatrix(arr)){
        //printMatrix(arr);
        //printf("Is a Lu Sho Magix Square\n");
        return TRUE;
    }else{ 
        //printMatrix(arr);
        //printf("Is not a Lu Sho Magix Square\n");
        return FALSE;
    }
}

void swapIndex(int arr[9]){ // swaps the value in two random slots
    int randIndexOne = rand()%9;
    int randIndexTwo = rand()%9;

    int temp = arr[randIndexOne];
    arr[randIndexOne] = arr[randIndexTwo];
    arr[randIndexTwo] = temp;
}
int main(){
    unsigned long counter = 0;
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    srand((unsigned) time(NULL));
    
    do{
        int maxIterations = rand()%50;  //choose a random number of iterations to swap.
          for(int i = 0; rand()%50; i++)
          {
            swapIndex(arr); //swap 2 random values over and over to construct a new matrix.
          }
          counter++;
    }while(!validateSquare(arr)); //validate the matrix.
    printMatrix(arr);//print the resultant matrix.
    printf("The total number of squares generated before success were %lu\n", counter-1); //print the number of iterations.
    
    
return EXIT_SUCCESS;
}