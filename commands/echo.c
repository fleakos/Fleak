#include "console/echo.h"

int main (int argc, char *argv[]){ 
    register int i, nflag; 
    nflag = 0; 
    if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n') {
        nflag++;	
        argc--;	
        argv++;
        
    } for(i = 1; i < argc; i++) {	
        collect(argv[i]);
        if (i < argc - 1) collect(" "); } 
        if (nflag == 0) collect("\n"); 
        if (count > 0) write(1, buf, count); 
exit(0);
} 
    collect(s)
    char *s;{
        char c; 
        if (count == SIZE) {write(1, buf, count);
        count = 0;
    } while ( (c = *s++) != 0) {	if (count < SIZE && c != '"') buf[count++] = c; }
    
    }
