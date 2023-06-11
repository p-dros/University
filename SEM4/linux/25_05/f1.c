#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
    int f1, c;
    char b[BUFSIZE], *n1;
	
    printf("Liczba argumentow wywolania: %d\n", argc - 1);
     
    c = 100;
    n1 = argv[1];
 
    f1 = open (n1, O_RDONLY);
    
    if (f1 == -1) {
    	fprintf(stderr, "%s", " error. No file detected\n");
   	return -1;
    }
    
    read (f1, b, c);
    printf("%s: Przeczytano %d znaków z pliku %s: \"%s\"\n",
	   argv[0], c, n1, b);
    close(f1);
 
    return(0);
}
