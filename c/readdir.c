#include <dirent.h>
#include <string.h>
#include <stdio.h>

#define IS_CURRENTDIR(a) (strcmp(a, ".") == 0)
#define IS_PARENTDIR(a)  (strcmp(a, "..") == 0)

int main(int argc, char** argv)
{
    struct dirent *files;
    DIR *dir;
    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("Directory cannot be opened!");
        return 0;
    }
    while ((files = readdir(dir)) != NULL)
    {
        if (IS_PARENTDIR(files->d_name) || IS_CURRENTDIR(files->d_name))
            continue;
        printf("%s\n", files->d_name);
    }
    closedir(dir);
    return 0;
}
