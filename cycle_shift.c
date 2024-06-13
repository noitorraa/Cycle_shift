#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *check, int *steps);
void output(int *newArray, int n);
void shift(int *a, int n, int *steps, int *newArray);

int main() {
  int data[NMAX], newArray[NMAX], n, check = 0, steps = 0;
  input(data, &n, &check, &steps);
  if (check == 0) {
    shift(data, n, &steps, newArray);
    output(newArray, n);
  }
}

void input(int *a, int *n, int *check, int *steps) {
  printf("Напиши сколько элементов будешь вводить: ");
  if (scanf("%d", n) == 1 && getchar() == '\n' && *n >= 1 && *n <= 10) {
    for (int i = 0; i < *n; i++) {
      printf("Введи число %d: ", i + 1);
      if (scanf("%d", &a[i]) != 1 || getchar() != '\n') {
        printf("n/a\n");
        *check = 1;
        break;
      }
    }
    *steps = 0;
    printf("Введите чисо, на которое будет произведен сдвиг: ");
    if ((scanf("%d", steps) != 1 || getchar() != '\n' || *steps >= 10 ||
         *steps <= -10) &&
        *check == 0) {
      *check = 1;
      printf("n/a\n");
    }
  } else {
    printf("n/a\n");
    *check = 1;
  }
}

void shift(int *a, int n, int *steps, int *newArray) {
  if (*steps <= 0) {
    *steps *= (-1);
    *steps = n - *steps;
  }

  for (int i = 0; i < *steps; i++) {
    int firstNum = a[0];
    for (int j = 0; j < n - 1; j++) {
      a[j] = a[j + 1];
    }
    a[n - 1] = firstNum;
  }
  for (int i = 0; i < n; i++) {
    newArray[i] = a[i];
  }
}

void output(int *newArray, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", newArray[i]);
  }
  printf("\n");
}