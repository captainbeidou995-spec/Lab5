#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*3.*/
void task3(void) {
    printf("Task 3\n");
    double a[15];
    int b[15];
    int i;

    srand((unsigned int)time(NULL));

    printf("a) Real numbers [0, 1):\n");
    for (i = 0; i < 15; i++) {
        a[i] = (double)rand() / RAND_MAX;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    printf("b) Real numbers [22, 23):\n");
    for (i = 0; i < 15; i++) {
        a[i] = 22.0 + (double)rand() / RAND_MAX;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    printf("c) Real numbers [0, 10):\n");
    for (i = 0; i < 15; i++) {
        a[i] = ((double)rand() / RAND_MAX) * 10.0;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    printf("d) Real numbers [-50, 50):\n");
    for (i = 0; i < 15; i++) {
        a[i] = -50.0 + ((double)rand() / RAND_MAX) * 100.0;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    printf("e) Integers [0, 10]:\n");
    for (i = 0; i < 15; i++) {
        b[i] = rand() % 11;
        printf("%d ", b[i]);
    }
    printf("\n");
} 

/*8.*/

void task8(void) {
    printf("Task 8\n");
    double ar[10], geom[20];
    int fib[12];
    double a, p, z;
    int i;

    printf("Enter first term (a) and difference (p) for arithmetic progression:\n");
    scanf("%lf %lf", &a, &p);

    ar[0] = a;
    printf("Arithmetic progression: %.2lf ", ar[0]);
    for (i = 1; i < 10; i++) {
        ar[i] = ar[i - 1] + p;
        printf("%.2lf ", ar[i]); 
    }
    printf("\n");

    printf("Enter first term (a) and ratio (z) for geometric progression:\n");
    scanf("%lf %lf", &a, &z);

    geom[0] = a;
    printf("Geometric progression: %.2lf ", geom[0]);
    for (i = 1; i < 20; i++) {
        geom[i] = geom[0] * pow(z, i);
        printf("%.2lf ", geom[i]);
    }
    printf("\n");

    fib[0] = 1;
    fib[1] = 1;

    printf("Fibonacci sequence (12 terms):\n");
    printf("%d %d ", fib[0], fib[1]);
    for (i = 2; i < 12; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d ", fib[i]);
    }
    printf("\n");
}

/*10. */
void task10(void) {
    printf("Task 10\n");
    int n;
    int a[6];
    int i = 0;
    int size;


    do {
        printf("Enter a natural number n (n <= 999999):\n");
        scanf("%d", &n);
        if (n < 1 || n > 999999) {
            printf("Error\n");
        }
    } while (n < 1 || n > 999999);

    while (n > 0) {
        a[i] = n % 10;
        n = n / 10;
        i++;
    }
    size = i;

    printf("Digits in reverse order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
/*29. */
void task29(void) {
    printf("Task 29\n");
    double a[100];
    int n, i;
    double prev, current;
    int incr = 1;   

    do {
        printf("Enter number of elements: ");
        scanf("%d", &n);
		if  (n < 1 || n > 100) {
			printf("Error\n");
		}
    } while (n < 1 || n > 100);

    printf("Enter %d real numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            incr = 0;
            break;
        }
    }

    if (incr == 1) {
        printf("The sequence is strictly increasing.\n");
    }
    else {
        printf("The sequence is not increasing.\n");
    }
}
/*66. */
void task66(void) {
    printf("Task 66\n");
    int n, a[100], i;
    long long product = 1;
    int neg = 0;
    
    do {
        printf("Enter number of elements:\n");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("Error\n");
        }
	} while (n < 1 || n > 100);
    

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            product = product * a[i];
            neg = 1;
        }
    }

    if (neg == 1) {
        printf("Product of negative elements is %lld\n", product);
    }
    else {
        printf("There are no negative elements.\n");
    }
}
/*127. */
void task127(void) {
    printf("Task 127\n");
    int n, i;
    double a[100];
    double p1 = 1.0, p2 = 1.0;
    double abs_p1;
	int neg = 0, pos = 0;


    do {
        printf("Enter number of elements:\n");
        scanf("%d", &n);
		if (n < 1 || n > 100) {
			printf("Error.\n");
		}
	} while (n < 1 || n > 100);
    

        printf("Enter %d real numbers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            if (a[i] == 0) {
                printf("Error.\n");
                return;
            }
        }
        
    for (i = 0; i < n; i++) {
        if (a[i] < 0) {
            p1 = p1 * a[i];
			neg = 1;
        }
        else {
            p2 = p2 * a[i];
			pos = 1;
        }
    }

    if (neg > 0) {
        printf("Product of negative elements (P1) = %.2lf\n", p1);
    }
    else {
        printf("There are no negative elements.\n");
    }

    if (pos > 0) {
        printf("Product of positive elements (P2) = %.2lf\n", p2);
    }
    else {
        printf("There are no positive elements.\n");
    }

	if (neg == 0 || pos == 0) {
		printf("One of the products is missing.\n");
		return;
	}

    abs_p1 = p1;
    if (abs_p1 < 0) {
        abs_p1 = -abs_p1;
    }

    if (abs_p1 > p2) {
        printf("Modulus of negative elements product (|P1|) is greater.\n");
    }
    else if (p2 > abs_p1) {
        printf("Modulus of positive elements product (|P2|) is greater.\n");
    }
    else {
        printf("Moduli of both products are equal.\n");
    }
}


int main(void) {
    task3();
    task8();
    task10();
    task29();
    task66();
    task127();

    return 0;
}
