#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime_checker(int p) {
    // Checks if the number entered is a prime number or not
    if (p < 2)
        return 0;
    if (p == 2)
        return 1;
    for (int i = 2; i <= sqrt(p); ++i) {
        if (p % i == 0)
            return 0;
    }
    return 1;
}

int primitive_check(int g, int p, int* l, int size) {
    // Checks if the entered number is a primitive root or not
    for (int i = 1; i < p; ++i) {
        l[i - 1] = (int)(pow(g, i)) % p;
    }
    for (int i = 1; i < p; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (l[j] == i)
                count++;
        }
        if (count > 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int* l = NULL;
    int P;

    while (1) {
        printf("Enter P: ");
        scanf("%d", &P);
        if (!prime_checker(P)) {
            printf("Number is not prime. Please enter again!\n");
            continue;
        }
        break;
    }

    int G;
    while (1) {
        printf("Enter the primitive root of %d: ", P);
        scanf("%d", &G);
        int size = P - 1;
        l = (int*)malloc(size * sizeof(int));
        if (!primitive_check(G, P, l, size)) {
            printf("Number is not a primitive root of %d. Please try again!\n", P);
            free(l);
            continue;
        }
        break;
    }

    // Private Keys
    int x1, x2;
    printf("Enter the private key of User 1: ");
    scanf("%d", &x1);
    printf("Enter the private key of User 2: ");
    scanf("%d", &x2);

    while (1) {
        if (x1 >= P || x2 >= P) {
            printf("Private key of both users should be less than %d!\n", P);
            continue;
        }
        break;
    }

    // Calculate Public Keys
    int y1 = (int)pow(G, x1);
    int y2 = (int)pow(G, x2);
    y1 %= P;
    y2 %= P;

    // Generate Secret Keys
    int k1 = (int)pow(y2, x1);
    int k2 = (int)pow(y1, x2);
    k1 %= P;
    k2 %= P;

    printf("\nSecret Key for User 1 is %d\n", k1);
    printf("Secret Key for User 2 is %d\n", k2);

    if (k1 == k2) {
        printf("Keys have been exchanged successfully.\n");
    } else {
        printf("Keys have not been exchanged successfully.\n");
    }

    free(l);
    return 0;
}
