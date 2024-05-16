# Convolutional Layer for Neural Networks in C

This project implements a basic convolutional layer for neural networks in the C programming language. The convolutional layer is a fundamental building block of Convolutional Neural Networks (CNNs) and is widely used in various computer vision tasks, such as image classification, object detection, and semantic segmentation.

## Features

- Performs 2D convolution on an input matrix using a kernel matrix
- Supports customizable input matrix and kernel matrix sizes
- Generates an output feature map based on the convolution operation
- Provides utility functions for matrix multiplication and element-wise multiplication
- Includes functions for printing matrices of different sizes

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)

### Installation

1. Clone the repository:

```bash
https://github.com/jacklion710/Convolutional-Image-Layer-in-C.git
```

2. Navigate to the project directory:

```bash
cd convolutional-layer-c
```

3. Compile the code:

<i>Varies based on your environment</i>

4. Run the program:

```bash
./conv
```

## Usage

The main function in `conv.c` demonstrates the usage of the convolutional layer. It creates an input matrix and a kernel matrix, and then calls the `myConv2D` function to perform the convolution operation.

```c
int main()
{
 int myInputMat[][6] = { /* ... */ };
 int myKern[][3] = { /* ... */ };
 int featMap[4][4];

 myConv2D(myInputMat, myKern, featMap);

 return 0;
}
```

You can modify the input matrix and kernel matrix values in the `main` function to experiment with different inputs.
Functions

* `printMatrice3x3`: Prints a 3x3 matrix.
* `printMatrice6x6`: Prints a 6x6 matrix.
* `printMatrice4x4`: Prints a 4x4 matrix.
* `matMult`: Performs element-wise multiplication of two 3x3 matrices.
* `matElemSum`: Calculates the sum of all elements in a 3x3 matrix.
* `matDotProdConsolidated`: Performs matrix dot product and prints the result.
* `matDotProdComposed`: Performs matrix dot product within a single function.
* `myConv2D`: Performs 2D convolution on an input matrix using a kernel matrix.