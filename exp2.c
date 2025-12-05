#include <stdio.h>
#include <string.h>

int main() {
    char non_terminal;
    char prod1[100], prod2[100];
    char common[100];
    int i = 0;

    printf("Enter the non-terminal (e.g., A): ");
    scanf(" %c", &non_terminal);

    printf("Enter the first production (e.g., abc): ");
    scanf("%s", prod1);

    printf("Enter the second production (e.g., abd): ");
    scanf("%s", prod2);

    // Find the common prefix
    while (prod1[i] && prod2[i] && prod1[i] == prod2[i]) {
        common[i] = prod1[i];
        i++;
    }
    common[i] = '\0';

    // Remaining parts after common prefix
    char beta1[100], beta2[100];
    strcpy(beta1, prod1 + i);
    strcpy(beta2, prod2 + i);

    // Print the result after left factoring
    printf("\nAfter Left Factoring:\n");
    printf("%c -> %s%c'\n", non_terminal, common, non_terminal);
    printf("%c' -> %s | %s\n", non_terminal,
           strlen(beta1) ? beta1 : "e",
           strlen(beta2) ? beta2 : "e");

    return 0;
}
