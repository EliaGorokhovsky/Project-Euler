#include <stdio.h>
#include <stdlib.h>

/**
 * Challenge:
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000. 
 */
int main() {
    /*
     * There are 333 multiples of 3 below 1000: 3, 6, 9, ..., 999
     * Similarly, there are 199 multiples of 5: 5, 10, 15, ..., 995
     * We can generalize this as such: for an integer upper bound a and a number b, there are a / b multiples of b below a
     * Then the sum of them is b (1 + 2 + 3 + ... + a / b) = b(a / b)(a / b + 1) / 2 = a (a + b) / (2 b)
     * We can repeat this calculation for any number of upper bounds and integers, e.g. 1000 and 3, 5
     * Then subtract the sum of all the numbers that are divisible by their product
     * In this case I only implement the case of two relatively prime natural numbers
     */
    //Get upper bound
    char * placeholder = malloc(128 * sizeof(char));
    printf("Enter upper bound: ");
    scanf("%s", placeholder);
    int upperBound = atoi(placeholder) - 1;
    placeholder = malloc(128 * sizeof(char));
    //printf("How many factors? ");
    //scanf("%s", placeholder);
    //int numFactors = atoi(placeholder);
    int numFactors = 2;
    long sum = 0;
    int product = 1;
    //Count sum of all numbers divisible by any of the factors
    for(int i = 0; i < numFactors; i++) {
        //Take input
        placeholder = malloc(128 * sizeof(char));
        printf("Enter factor %d ", i);
        scanf("%s", placeholder);
        int number = atoi(placeholder);
        product *= number;
        int timesOccurring = upperBound / number;
        //See comment above
        sum += number * timesOccurring * (timesOccurring + 1) / 2;
    }
    //Subtract the recurrent ones
    int timesOccurringProduct = upperBound / product;
    sum -= product * timesOccurringProduct * (timesOccurringProduct + 1) / 2;
    
    free(placeholder);
    printf("The sum is %d", sum);
}