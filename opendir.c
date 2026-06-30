#include <stdio.h>
#include <dirent.h>
int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    d = opendir("..");
    if (d != NULL) {
        printf("Directory opened successfully\n");
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        printf("Error opening directory\n");
    }
    return 0;
}


