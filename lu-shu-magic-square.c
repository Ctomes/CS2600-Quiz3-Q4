//CS2600 Quiz 3 Question 4.1

//create a print function that can print a 3x3 array.

    //takes an int array as an arg
    // display each element aligned for legibility.


//create a function that can determine if an array meets LSMS "Lu Shu Magic Square" requirements.

    //take an array as an arguement.
    //test 3 rows ==15?
    //test 3 columns ==15?
    //test 2 diagonals ==15?

//part 1.
//main:
    //define some arrays and print to screen then run the test function.
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
void printMatrix(int arr[3][3])
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
void validateSquare(int arr[3][3]){
    if(testMatrix(arr)){
        printMatrix(arr);
        printf("Is a Lu Sho Magix Square\n");
    }else{ 
        printMatrix(arr);
        printf("Is not a Lu Sho Magix Square\n");
    }
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; //invalid LSMS
    int arr2[3][3]= {{4,9,2},{3,5,7},{8,1,6}};

    validateSquare(arr);
    validateSquare(arr2);

return EXIT_SUCCESS;
}