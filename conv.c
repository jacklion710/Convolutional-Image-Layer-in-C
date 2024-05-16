/*
 file: 2D_Matrix_Convolution
 generic C code implementation for 2D matrix convolution
 written by: Jacob Leone @jacob0leone@gmail.com
*/

#include <stdio.h>

// Function declarations
void printMatrice3x3(const int matrix[3][3]);
void printMatrice6x6(const int matrix[6][6]);
void printMatrice4x4(int matrix[4][4]);
void matMult(int inMat1[3][3], int inMat2[3][3], int outMat[3][3]);
void matElemSum(int inMat[3][3]);
void matDotProdConsolidated(int inMat[3][3], int kern[3][3], int outmat[3][3]);
void matDotProdComposed(int inMat[3][3], int kern[3][3], int outmat[3][3]);
void myConv2D(const int inMat[6][6], const int inKern[3][3], int featMap[4][4]);

int main()
{
    // 6x6 input matrix
    int myInputMat[][6] = { {5,6,7,5,6,7},
                            {8,9,10,8,9,10},
                            {3,1,2,3,1,2},
                            {5,6,7,5,6,7},
                            {8,9,10,8,9,10},
                            {3,1,2,3,1,2} };
    
    // 3x3 kernel matrix
    int myKern[][3] = { {7,6,5},
                        {10,9,8},
                        {2,1,3} };

    // Output feature map matrix
    int featMap[4][4];
    
    // Perform 2D convolution
    myConv2D(myInputMat, myKern, featMap);

    return 0;
}

// Utility function to print a 3x3 matrix
void printMatrice3x3(const int matrix[3][3])
{
    int row, columns;
    for (row=0; row<3; row++)
    {
        for(columns=0; columns<3; columns++)
        {
             printf("%d     ", matrix[row][columns]);
        }
        printf("\n");
    }
}

// Utility function to print a 6x6 matrix
void printMatrice6x6(const int matrix[6][6])
{
    int row, columns;
    for (row=0; row<6; row++)
    {
        for(columns=0; columns<6; columns++)
        {
             printf("%d     ", matrix[row][columns]);
        }
        printf("\n");
    }
}

// Utility function to print a 4x4 matrix
void printMatrice4x4(int matrix[4][4])
{
    int row, columns;
    for (row=0; row<4; row++)
    {
        for(columns=0; columns<4; columns++)
        {
             printf("%d     ", matrix[row][columns]);
        }
        printf("\n");
    }
}

// Function to perform element-wise multiplication of two 3x3 matrices
void matMult(int inMat[3][3], int kern[3][3], int outMat[3][3])
{
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        outMat[i][j] = inMat[i][j] * kern[i][j];
}

// Function to calculate the sum of all elements in a 3x3 matrix
void matElemSum(int inMat[3][3])
{
    int sum = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            sum = sum + inMat[i][j];
        }
    }
    printf("Sum of all elements = %d\n", sum);
}

// Function to perform matrix dot product and print the result
void matDotProdConsolidated(int inMat[3][3], int kern[3][3], int outMat[3][3])
{
    // Display input matrix and kernel
    printf("First Matrix:\n");
    printMatrice3x3(inMat);
    printf("Second Matrix:\n");
    printMatrice3x3(kern);
    
    // Calculate and display the result of elementwise multiplication
    printf("Matrix multiplication:\n");
    matMult(inMat,kern,outMat);
    printMatrice3x3(outMat);
    
    // Calculate and display the sum of elements
    matElemSum(outMat);
}

// Function to perform matrix dot product
void matDotProdComposed(int inMat[3][3], int kern[3][3], int outMat[3][3])
{
    // Display input matrix and kernel
    printf("First Matrix:\n");
    printMatrice3x3(inMat);
    printf("Second Matrix:\n");
    printMatrice3x3(kern);
    
    // Perform element-wise multiplication
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        outMat[i][j] = inMat[i][j] * kern[i][j];
    printf("Matrix multiplication:\n");
    printMatrice3x3(outMat);

    // Sum the products of the last calculation
    int sum = 0;
    for(int k=0; k<3; k++)
    {
        for(int l=0; l<3; l++)
        {
            sum = sum + outMat[k][l];
        }
    }
    printf("Sum of all elements = %d\n\n", sum);
}

// Function to perform 2D convolution
void myConv2D(const int inMat[6][6], const int inKern[3][3], int featMap[4][4])
{
    // Display input matrix and kernel
    printf("Input Matrix:\n");
    printMatrice6x6(inMat);
    printf("Kernel Matrix:\n");
    printMatrice3x3(inKern);

    int outMat[3][3];

    // Iterate over each position in the output feature map
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            // Perform element-wise multiplication of the submatrix and kernel
            // The submatrix is the 3x3 region of the input matrix corresponding to the current position
            for (int kernelRow = 0; kernelRow < 3; kernelRow++)
            {
                for (int kernelCol = 0; kernelCol < 3; kernelCol++)
                {
                    // Multiply each element of the submatrix with the corresponding element of the kernel
                    // and store the result in the outMat matrix
                    outMat[kernelRow][kernelCol] = inMat[row + kernelRow][col + kernelCol] * inKern[kernelRow][kernelCol];
                }
            }
            
            // Print the result of element-wise multiplication
            printf("Matrix multiplication:\n");
            printMatrice3x3(outMat);

            // Calculate the sum of elements in the outMat matrix
            // This sum represents the convolution result for the current position in the feature map
            int sum = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    sum += outMat[i][j];
                }
            }

            // Print the sum of elements and assign it to the corresponding position in the feature map
            printf("Sum of all elements = %d\n\n", sum);
            featMap[row][col] = sum;
        }
    }

    // Print hte final feature map
    printf("Feature Map:\n");
    printMatrice4x4(featMap);
}

/*
Here's a step-by-step explanation of the convolution process:

1. The function takes the input matrix `inMat`, the kernel matrix `inKern`, and the initialized output feature map to fill `featMap` as parameters.

2. It starts by displaying the input matrix and kernel matrix using the `printMatrice6x6` and `printMatrice3x3` functions, respectively.

3. The function then iterates over each position in the output feature map using nested loops for row and col. These loops define the sliding window over the input matrix.

4. For each position in the feature map, the function performs element-wise multiplication of the corresponding 3x3 submatrix of the input matrix with the kernel matrix. This is done using nested loops for `kernelRow` and `kernelCol`. A stride determines by how many cells the kernel shifts to perform the next calculation.

5. The result of the element-wise multiplication is stored in the `outMat` matrix.

6. The `outMat` matrix is then printed using the `printMatrice3x3` function to display the intermediate result.

7. The function calculates the sum of all elements in the `outMat` matrix, which represents the convolution result for the current position in the feature map.

8. The sum is printed and assigned to the corresponding position in the `featMap` matrix.

9. Steps 4-8 are repeated for each position in the feature map until all positions have been processed.

10. Finally, the resulting feature map is printed using the `printMatrice4x4` function.
*/