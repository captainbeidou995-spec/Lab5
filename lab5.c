#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*3.  Заповнити масив із п'ятнадцяти елементів випадковим чином:
а) речовими значеннями, що лежать в діапазоні від 0 до 1;
б) речовими значеннями x (22 ≤ x < 23);
в) речовими значеннями x (0 ≤ x < 10);
г) речовими значеннями x (–50 ≤ x < 50);
д) цілими значеннями, що лежать в діапазоні від 0 до 10 включно.
*/
void task3(void) {
    printf("Task 3\n");
    double a[15];
    int b[15];
    int i;

    srand((unsigned int)time(NULL));

    /* а) от 0 до 1 */
    printf("a) Real numbers [0, 1):\n");
    for (i = 0; i < 15; i++) {
        a[i] = (double)rand() / RAND_MAX;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    /* б) 22 <= x < 23 */
    printf("b) Real numbers [22, 23):\n");
    for (i = 0; i < 15; i++) {
        a[i] = 22.0 + (double)rand() / RAND_MAX;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    /* в) 0 <= x < 10 */
    printf("c) Real numbers [0, 10):\n");
    for (i = 0; i < 15; i++) {
        a[i] = ((double)rand() / RAND_MAX) * 10.0;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    /* г) -50 <= x < 50 */
    printf("d) Real numbers [-50, 50):\n");
    for (i = 0; i < 15; i++) {
        a[i] = -50.0 + ((double)rand() / RAND_MAX) * 100.0;
        printf("%.2lf ", a[i]);
    }
    printf("\n");

    /* д) целые от 0 до 10 включительно */
    printf("e) Integers [0, 10]:\n");
    for (i = 0; i < 15; i++) {
        b[i] = rand() % 11;
        printf("%d ", b[i]);
    }
    printf("\n");
} 

/*8. Заповнити масив:
а) десятьма першими членами арифметичної прогресії (перший член прогресії — і, її різницю — р);
б) двадцятьма першими членами геометричної прогресії (перший член прогресії — a, її знаменник z);
в) дванадцятьма першими членами послідовності Фібоначчі (послідовності, в якій перші два члени дорівнюють 1, 
а кожен наступний дорівнює сумі двох попередніх).
*/

void task8(void) {
    printf("Task 8\n");
    double arith[10], geom[20];
    int fib[12];
    double a, p, z;
    int i;

    /* а) Арифметическая прогрессия */
    printf("Enter first term (a) and difference (p) for arithmetic progression:\n");
    scanf("%lf %lf", &a, &p);

    arith[0] = a;
    printf("Arithmetic progression: %.2lf ", arith[0]);
    for (i = 1; i < 10; i++) {
        arith[i] = arith[i - 1] + p;
        printf("%.2lf ", arith[i]); 
    }
    printf("\n");

    /* б) Геометрическая прогрессия */
    printf("Enter first term (a) and ratio (z) for geometric progression:\n");
    scanf("%lf %lf", &a, &z);

    geom[0] = a;
    printf("Geometric progression: %.2lf ", geom[0]);
    for (i = 1; i < 20; i++) {
        geom[i] = geom[0] * pow(z, i);
        printf("%.2lf ", geom[i]);
    }
    printf("\n");

    /* в) Последовательность Фибоначчи */
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

/*10. Дано натуральне число п ≤ 999999. Заповнити масив його цифрами, розташованими у зворотному порядку
(перший елемент дорівнює останній цифрі, другий — передостанній і т.д.). Елементи масиву є цифрами числа п вивести на екран.*/
void task10(void) {
    printf("Task 10\n");
    int n;
    int digits[6];
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
        digits[i] = n % 10;
        n = n / 10;
        i++;
    }
    size = i;

    printf("Digits in reverse order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");
}
/*29. Дано послідовність дійсних чисел a1, a2, ..., aп. З'ясувати, чи вона зростає.*/
void task29(void) {
    printf("Task 29\n");
    int n, i;
    double prev, current;
    int is_increasing = 1;

    

    do {
        printf("Enter number of elements: ");
        scanf("%d", &n);
		if  (n < 1) {
			printf("Error\n");
		}
    } while (n < 1);

    printf("Enter element 1: ");
    scanf("%lf", &prev);

    for (i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%lf", &current);
        if (current <= prev) {
            is_increasing = 0;
        }
        prev = current;
    }

    if (is_increasing == 1) {
        printf("The sequence is strictly increasing.\n");
    }
    else {
        printf("The sequence is not increasing.\n");
    }
}
/*66. Знайти добуток всіх елементів масиву цілих чисел менших 0.*/
void task66(void) {
    printf("Task 66\n");
    int n, current_val;
    long long product = 1;
    int has_negative = 0;
    
    do {
        printf("Enter number of elements:\n");
        scanf("%d", &n);
        if (n < 1) {
            printf("Error\n");
        }
	} while (n < 1);
    

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &current_val);

        if (current_val < 0) {
            product *= current_val;
            has_negative = 1;
        }
    }

    if (has_negative) {
        printf("Product of negative elements is %lld\n", product);
    }
    else {
        printf("There are no negative elements in the sequence.\n");
    }
}
/*127. У послідовності дійсних чисел a1, a2, ..., aп є лише позитивні та негативні елементи. 
Обчислити добуток негативних елементів П1 та добуток позитивних елементів Р2. 
Порівняти модуль Р2 з модулем П1, вказати, який із творів за модулем більше.
*/
void task127(void) {
    printf("Task 127\n");
    int n, i;
    double current_val;
    double p1 = 1.0, p2 = 1.0;
    int has_neg = 0;
    int has_pos = 0;

    do {
        printf("Enter number of elements:\n");
        scanf("%d", &n);
		if (n < 1) {
			printf("Error\n");
		}
	} while (n < 1);
    

    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &current_val);
        if (current_val < 0) {
            p1 *= current_val;
            has_neg = 1;
        }
        else if (current_val > 0) {
            p2 *= current_val;
            has_pos = 1; 
        }
        
    }

    if (has_neg == 1) {
        printf("Product of negative elements (P1) = %.2lf\n", p1);
    }
    else {
        printf("There are no negative elements.\n");
    }

    if (has_pos == 1) {
        printf("Product of positive elements (P2) = %.2lf\n", p2);
    }
    else {
        printf("There are no positive elements.\n");
    }

    if (has_neg && has_pos) {
        double abs_p1 = fabs(p1);
        double abs_p2 = fabs(p2);

        if (abs_p2 > abs_p1) {
            printf("The module of positive product is greater than the module of negative product.\n");
        }
        else if (abs_p2 < abs_p1) {
            printf("The module of negative product is greater than the module of positive product.\n");
        }
        else {
            printf("The modules are equal.\n");
        }
    }
    else {
        printf("Cannot compare modules.\n");
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