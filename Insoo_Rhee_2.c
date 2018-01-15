/******************************************************************************
Jan 20, 2018
Insoo Rhee (301075548)
Assignment1. Question2.
*******************************************************************************/
#include <stdio.h>
#define MAX 10
char selection();
void input_I(unsigned int *A, int *size);
void InsertionSort_I(unsigned int *A, const int *size);
void print_I(unsigned int *A, const int *size);
void input_C(char *B, int *size);
void InsertionSort_C(char *B, const int *size);
void print_C(char *B, const int *size);
int main()
{
    if ( 'I' == selection())
    {
        int size = 0;
        unsigned int *A = (unsigned int*)malloc(MAX*sizeof(unsigned int));      
        input_I(A,&size);
        InsertionSort_I(A,&size);
        print_I(A,&size);
        free(A);
    }
    else
    {
        int size = 0;
        char *B = (char*)malloc(MAX*sizeof(char)); 
        input_C(B,&size);
        InsertionSort_C(B,&size);
        print_C(B,&size);
        free(B);
    }

    return 0;
}
char selection()
{
    char c;
    printf("Enter capital 'I' to sort integers or\n");
    printf("Enter capital 'C' to sort characters: ");
    scanf("%c",&c);
    return c;    
}
void input_I(unsigned int *A, int *size)
{
    unsigned int cin;
    int count = MAX;
    *size = 0;
    
    printf("(%d inputs remaining)\n",count);
    printf("Enter an unsigned integer(any alphabet to exit): ");    
    while(scanf("%u",&cin) == 1 && count > 0)
    {
        A[*size] = cin;
        *size = *size + 1;
        count--;
        
        printf("(%d inputs remaining)\n",count);
        printf("Enter an unsigned integer(any alphabet to exit): ");
    }
    if(count == 0)
    {
        printf("You reached ten inputs\n");
    }
}
void InsertionSort_I(unsigned int *A, const int *size)
{
    int i;
    int j;
    unsigned int cur;
    for(i=1;i<*size;i++)
    {
        cur = A[i];
        j = i-1;        
        while(j>=0 && A[j]>cur)
        {
            A[j+1] = A[j];
            j = j -1;
        }
        A[j+1] = cur;
    }
}
void print_I(unsigned int *A, const int *size)
{
    int i;
    printf("The sorted numbers are:\n");
    for(i=0;i<*size;i++)
    {
        printf("%u\n",A[i]);
    }
}
void input_C(char *B, int *size)
{
    getchar();
    char cin;
    int count = MAX;
    *size = 0;
    do
    {
        printf("(%d inputs remaining)\n",count);
        printf("Enter a character(0 to exit): ");
        scanf("%c",&cin);
        getchar();
        
        if(cin != '0')
        {
            B[*size] = cin;
            *size = *size + 1;
        }
        count--;
    }while(cin != '0' && count > 0);
    if(count == 0)
    {
        printf("You have ten inputs\n");
    }
}
void InsertionSort_C(char *A, const int *size)
{
    printf("The sorted characters are:\n");
    int i;
    int j;
    char cur;
    for(i=1;i<*size;i++)
    {
        cur = A[i];
        j = i-1;        
        while(j>=0 && A[j]>cur)
        {
            A[j+1] = A[j];
            j = j -1;
        }
        A[j+1] = cur;
    }
}
void print_C(char *A, const int *size)
{
    int i;
    for(i=0;i<*size;i++)
    {
        printf("%c\n",A[i]);
    }
}