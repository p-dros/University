#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

#include <errno.h>

#define MAX_CHAR 200

int main(int argc, char **argv)
{
    int t;
    struct direct *e;
    DIR *d;
    struct stat s;
    char p[MAX_CHAR];

    d = opendir(argv[1]);

    if (d == NULL)
    {
        printf("Failed to open directory. %s\n", strerror(errno));
        return -1;
    }

    while ((e = readdir(d)) != 0)
    {
        printf("%d %s", (int)e->d_ino, e->d_name);
        if (strcmp(e->d_name, ".") != 0 &&
            strcmp(e->d_name, "..") != 0)
            printf("\n");
        else
        {
            p[0] = 0;
            strcat(p, argv[1]);
            strcat(p, "/");
            strcat(p, e->d_name);
            t = stat(p, &s);
            if (S_ISDIR(s.st_mode))
                printf("/");
            printf("\n");
        }
    }
    closedir(d);
    return 0;
}