/******************************************************************************
Jan 20, 2018
Insoo Rhee (301075548)
Assignment1. Question2.
*******************************************************************************/
#include <iostream>
#define MAX 10
using namespace std;
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
        unsigned int *A = new unsigned int;
        input_I(A,&size);
        InsertionSort_I(A,&size);
        print_I(A,&size);
        delete[] A;
    }
    else
    {
        int size = 0;
        char *B = new char; 
        input_C(B,&size);
        InsertionSort_C(B,&size);
        print_C(B,&size);
        delete[] B;
    }

    return 0;
}
char selection()
{
    char c;
    cout<<"Enter capital 'I' to sort integers or\n";
    cout<<"Enter capital 'C' to sort characters: ";
    cin>>c;
    return c;    
}
void input_I(unsigned int *A, int *size)
{
    unsigned int input;
    int count = MAX;
    *size = 0;
    
    cout<<count<<" inputs remaining"<<endl;
    cout<<"Enter an unsigned integer(any alphabet to exit): ";    
    while( cin>>input && count > 0)
    {
        A[*size] = input;
        *size = *size + 1;
        count--;
        
        cout<<count<<" inputs remaining\n";
        cout<<"Enter an unsigned integer(any alphabet to exit): ";
    }
    if(count == 0)
    {
        cout<<"You reached ten inputs\n";
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
    cout<<"The sorted numbers are:\n";
    for(i=0;i<*size;i++)
    {
        cout<<A[i]<<endl;
    }
}
void input_C(char *A, int *size)
{
    char input;
    int count = MAX;
    *size = 0;
    do
    {
        cout<<count<<" inputs remaining\n";
        cout<<"Enter a character(0 to exit): ";
        cin>>input;
        
        if(input != '0')
        {
            A[*size] = input;
            *size = *size + 1;
        }
        count--;
    }while(input != '0' && count > 0);
    if(count == 0)
    {
        cout<<"You have ten inputs\n";
    }
}
void InsertionSort_C(char *A, const int *size)
{
    cout<<"The sorted characters are:\n";
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
        cout<<A[i]<<"\n";
    }
}