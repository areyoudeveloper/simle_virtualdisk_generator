#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int size;
    int kbsize;
    int x;
    char filename[255];
    char cmd[1000];
    char fstype[255];
    printf("Filename? ");
    scanf("%s", &filename);
    FILE * diskfile; 
    diskfile = fopen (filename, "w");
    printf("Input Disk Size in megabyte: ");
    scanf("%d", &size);
    char format[1];
    char none[255] = " ";
    printf("Format now?(y/n) ");
    scanf("%s", &format[0]);
    kbsize = size * 13000;
    for(x=1;x != 0; x++) {
        if (x!=0) {
            fprintf(diskfile, "0000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
        }
        if (x == kbsize) {
            fclose(diskfile);
            if (format[0] == 'y') {
                printf("filesytem type(ext3/ext4) ");
                scanf("%s", &fstype);
                strcpy (cmd, "mkfs.");
                strcat (cmd, fstype);
                strcat (cmd, none);
                strcat (cmd, filename);
                system(cmd);
            }
            return 0;
            
        } 
        
    }
        return 0;}
        
        
        
