#include <stdio.h>
#include <math.h>

int read_vector(int vect[100])
{
    /*

    The function reads the vector from the console

    Input: a vector of integer with length 100 
    Output: The length of the vector that was chosen by the user

    */
    int len;
    printf("\nHow long is the vector? ");
    printf("\n--> ");
    scanf(" %d", &len);
    
    for(int i = 0; i < len; i++)
    {
        printf("\n#%d element --> ", i + 1);
        scanf(" %d", &vect[i]);
    }

    return len;
}

int nr_zero_digits(int nr)
{
    /*
    
    The function counts the number of 0 digits in a number by dividing it by 0 and comparing the remainder with 0

    Input: the munber that is gonna be analysed
    Output: a counter, the nr of 0 digits in the input value

    */
    int count = 0, digit;

    while(nr != 0)
    {
        digit = nr % 10;
        nr = nr / 10;
        if(digit == 0)
            count++;
    }

    return count;
}

int product_of_subsequence()
{
    /*
    
    The function reads a sequence of numbers from the console until the user inputs 0
    While reading it automatically calculates the product of these numbers

    Input: No input values 
    Output: The product of the sequence

    */
    int prod = 1, elem = 1;
    printf("\nGive a sequence of numbers (ended with 0): ");
    while(elem != 0)
    {
        prod = prod * elem;
        printf("\n--> ");
        scanf(" %d", &elem);
    }

    return prod;
}

int is_prime(int nr)
{
    /*
    
    The function determines if a number is prime or not by dividing it by all numbers until its square root

    Input: the number that's gonna be analysed
    Output: 0 - if number is not prime; 1 - if nr is prime

    */
    if(nr <= 1)
        return 0;
    for (int i = 2; i <= sqrt(nr); i++)
        if(nr % i == 0)
            return 0;
    return 1;
}

void find_subsequence(int vect[100], int len, int* seqLen, int* start)
{
    /*
    
    The function finds the longest subsequence where the sum of each consecutive number is prime
    It goes through the array, when it reaches a pair of numbers that satisfies the condition, it starts 
    creating the subsequence until the numbers are no longer respecting the condition set. 
    Then we check if the newly created sequence is longer than the previous one.

    If yes, we memorise it's length and starting index

    Input: a vector of integer, it's length, a pointer to the variables that will contain 
        the values of the starting index of the subseq. and its length
    Output: Nothing; the needed values are returned through pointers
    */
    int subSeqLen = 1;
    int longest = 1;
    int indexStart = 0;

    for(int i = 0; i < len - 1; i++)
    {
        if(is_prime(vect[i] + vect[i + 1]) == 1)
        {
            subSeqLen++;
            if (subSeqLen > longest)
            {
                longest = subSeqLen;
                indexStart = i + 2 - subSeqLen;
            }
        }
        else
            subSeqLen = 1;
    }
    *seqLen = longest;
    *start = indexStart;
}

void print_menu()
{

    printf("\n\nMenu: \n");
    printf("   r - read a vector\n");
    printf("   z - nr of 0 digits of a product of natural numbers\n");
    printf("   l - the longest contiguous subsequence with the sum of any two consecutive elements is a prime number from the given vector\n");
    printf("   x - exit");

}

int main()
{
    int vect[100], len = 0, nr;
    int seqLen, start;
    char choice;

    while(1)
    {
        print_menu();
        printf("\n--> ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'r':
            len = read_vector(vect);
            printf("\nYour vector: ");
            for(int i = 0; i < len; i++)
                printf("%d ", vect[i]);
            break;

        case 'z':
            nr = product_of_subsequence();
            nr = nr_zero_digits(nr);
            printf("\nThe product of the given sequence has %d numbers of 0 digits", nr);
            break;
        
        case 'l':
            find_subsequence(vect, len, &seqLen, &start);
            if(seqLen <= 1)
                printf("No such subsequences in here (that's at least >2)");
            else
            {
                printf("\nVector: ");
                for(int i = start; i < start + seqLen; i++)
                    printf("%d ", vect[i]);
            }
            break;

        case 'x':
            return 0;
        
        default:
            printf("__ERROR__\n");
            break;
        }
    }   
}