#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
	int f1, f2, c;
    int length;
    char b[BUFSIZE], *n1, *n2;
 
    c = 1000;
    n1 = argv[1];
    n2 = argv[2];
 
    f1 = open (n1, O_RDONLY);
    f2 = open (n2, O_WRONLY | O_CREAT | O_TRUNC, 0600);

    while ((length = read(f1, b, c)) != 0) {
        write(f2, b, length);
    }

    
    
    close(f1);
    close(f2);
 
    return(0);
}
