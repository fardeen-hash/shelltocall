#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    struct stat file;
    printf("Enter the file name");
    char val[100];
    scanf("%s", val);
    int fd = open(val, O_RDONLY);
    if (fd == -1)
    {
        printf("file doesnt exist;");
        exit(1);
    }
    stat(val,&file);
    printf("User permissions ");
    //user
    if (file.st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    printf("-");
    if (file.st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    printf("-");
    if (file.st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    printf("-");
    printf("\n");
    //group
    printf("Group permissions ");
    if (file.st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    printf("-");
    if (file.st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    printf("-");
    if (file.st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    printf("-");
    printf("\n");
     //group
    printf("OTHER user ");
    if (file.st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    printf("-");
    if (file.st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    printf("-");
    if (file.st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    printf("-");
    printf("\n");
}
