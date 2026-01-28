How does a browser’s Back button work using a stack?

#include <stdio.h>
#include <string.h>

#define MAX 5

char history[MAX][50];
int top = -1;

void visitPage(char page[]) {
    if (top == MAX - 1) {
        printf("History full\n");
    } else {
        top++;
        strcpy(history[top], page);
        printf("Visited: %s\n", page);
    }
}

void goBack() {
    if (top <= 0) {
        printf("No previous page to go back\n");
    } else {
        printf("Going back from %s\n", history[top]);
        top--;
        printf("Current page: %s\n", history[top]);
    }
}

void showHistory() {
    if (top == -1) {
        printf("No browsing history\n");
    } else {
        printf("Browser History (latest first):\n");
        for (int i = top; i >= 0; i--) {
            printf("%s\n", history[i]);
        }
    }
}

int main() {
    visitPage("google.com");
    visitPage("youtube.com");
    visitPage("wikipedia.org");

    showHistory();

    goBack();
    goBack();

    return 0;
}
