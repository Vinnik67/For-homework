#include <iostream>




void inputMatrix(int arr[][100], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cin >> arr[i][j];
        }
    }
}


int fillArray(int arr[][100], int rows, int cols, int oneD[], int& size) 
{
    size = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            oneD[size++] = arr[i][j];
        }
    }
}


int findCommonElements(int A[], int sizeA, int B[], int sizeB, int C[], int sizeC, int common[], int& sizeCommon) 
{
    sizeCommon = 0;
    for (int i = 0; i < sizeA; i++) 
    {
        for (int j = 0; j < sizeB; j++) 
        {
            for (int k = 0; k < sizeC; k++) 
            {
                if (A[i] == B[j] && B[j] == C[k]) 
                {
                    bool found = false;
                    for (int x = 0; x < sizeCommon; x++) 
                    {
                        if (common[x] == A[i])
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found) 
                    {
                        common[sizeCommon++] = A[i];
                    }
                }
            }
        }
    }
}


int findUniqueElements(int A[], int sizeA, int B[], int sizeB, int C[], int sizeC, int unique[], int& sizeUnique) 
{
    sizeUnique = 0;
    for (int i = 0; i < sizeA; i++) 
    {
        bool found = false;
        for (int j = 0; j < sizeB; j++) if (A[i] == B[j]) found = true;
        for (int k = 0; k < sizeC; k++) if (A[i] == C[k]) found = true;
        if (!found) unique[sizeUnique++] = A[i];
    }
    for (int i = 0; i < sizeB; i++) 
    {
        bool found = false;
        for (int j = 0; j < sizeA; j++) if (B[i] == A[j]) found = true;
        for (int k = 0; k < sizeC; k++) if (B[i] == C[k]) found = true;
        if (!found) unique[sizeUnique++] = B[i];
    }
    for (int i = 0; i < sizeC; i++) 
    {
        bool found = false;
        for (int j = 0; j < sizeA; j++) if (C[i] == A[j]) found = true;
        for (int k = 0; k < sizeB; k++) if (C[i] == B[k]) found = true;
        if (!found) unique[sizeUnique++] = C[i];
    }
}


int findCommonAC(int A[], int sizeA, int C[], int sizeC, int commonAC[], int& sizeCommonAC) 
{
    sizeCommonAC = 0;
    for (int i = 0; i < sizeA; i++) 
    {
        for (int j = 0; j < sizeC; j++) 
        {
            if (A[i] == C[j]) 
            {
                bool found = false;
                for (int x = 0; x < sizeCommonAC; x++) 
                {
                    if (commonAC[x] == A[i]) 
                    {
                        found = true;
                        break;
                    }
                }
                if (!found) 
                {
                    commonAC[sizeCommonAC++] = A[i];
                }
            }
        }
    }
}


int findNegativeElements(int A[], int sizeA, int B[], int sizeB, int C[], int sizeC, int negative[], int& sizeNegative) 
{
    sizeNegative = 0;
    for (int i = 0; i < sizeA; i++) if (A[i] < 0) negative[sizeNegative++] = A[i];
    for (int i = 0; i < sizeB; i++) if (B[i] < 0) negative[sizeNegative++] = B[i];
    for (int i = 0; i < sizeC; i++) if (C[i] < 0) negative[sizeNegative++] = C[i];
}

int main() 
{
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
    int A[100][100], B[100][100], C[100][100];
    int oneDA[10000], oneDB[10000], oneDC[10000], sizeA, sizeB, sizeC;

    std::cout << "Enter rows for A: ";
    std::cin >> rowsA >> colsA;
    inputMatrix(A, rowsA, colsA);

    std::cout << "Enter rows for B: ";
    std::cin >> rowsB >> colsB;
    inputMatrix(B, rowsB, colsB);

    std::cout << "Enter rows for C: ";
    std::cin >> rowsC >> colsC;
    inputMatrix(C, rowsC, colsC);

    fillArray(A, rowsA, colsA, oneDA, sizeA);
    fillArray(B, rowsB, colsB, oneDB, sizeB);
    fillArray(C, rowsC, colsC, oneDC, sizeC);

    int commonABC[10000], uniqueABC[10000], commonAC[10000], negativeValues[10000];
    int sizeCommonABC, sizeUniqueABC, sizeCommonAC, sizeNegativeValues;

    findCommonElements(oneDA, sizeA, oneDB, sizeB, oneDC, sizeC, commonABC, sizeCommonABC);
    findUniqueElements(oneDA, sizeA, oneDB, sizeB, oneDC, sizeC, uniqueABC, sizeUniqueABC);
    findCommonAC(oneDA, sizeA, oneDC, sizeC, commonAC, sizeCommonAC);
    findNegativeElements(oneDA, sizeA, oneDB, sizeB, oneDC, sizeC, negativeValues, sizeNegativeValues);

    std::cout << "All variables for A, B, C: ";
    for (int i = 0; i < sizeCommonABC; i++) std::cout << commonABC[i] << " ";
    std::cout << std::endl;

    std::cout << "Uniqe variables for A, B, C: ";
    for (int i = 0; i < sizeUniqueABC; i++) std::cout << uniqueABC[i] << " ";
    std::cout << std::endl;

    std::cout << "General variables for A і C: ";
    for (int i = 0; i < sizeCommonAC; i++) std::cout << commonAC[i] << " ";
    std::cout << std::endl;

    std::cout << "- variables for A, B, C without duplicating: ";
    for (int i = 0; i < sizeNegativeValues; i++) std::cout << negativeValues[i] << " ";
    std::cout << std::endl;

    return 0;
}