#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
 // Open input file
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    int count=0;
     BYTE buffer[512];
     FILE *destination;
     while(fread(&buffer, sizeof(BYTE), 512, inptr))
     {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0)==0xe0)
        {
            char dest_path[3];
            if(count<10){
                sprintf(dest_path, "00%d.jpg", count);
            } else {
                sprintf(dest_path, "0%d.jpg", count);
            }

            //printf("%s \n",dest_path);

             destination = fopen(dest_path, "w");
             if (destination == NULL)
             {
                 printf("Não foi possível criar %s.\n", dest_path);
                 return 1;
             }

             fwrite(&buffer, sizeof(BYTE), 512, destination);

             while(fread(&buffer, sizeof(BYTE), 512, inptr))
             {

                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0)==0xe0)
                {
                     fclose(destination);
                     fseek(inptr, -512, SEEK_CUR);
                     break;
                }

                fwrite(&buffer, sizeof(BYTE), 512, destination);

            }
            count++;
        }

     }
     fclose(destination);
     fclose(inptr);

}