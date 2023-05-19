// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of bytes in .wav header
typedef uint8_t BYTE;
typedef int16_t BYTE2;
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE buffer[HEADER_SIZE];

    fread(&buffer, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(&buffer, sizeof(BYTE), HEADER_SIZE, output);


    // TODO: Read samples from input file and write updated data to output file

    BYTE2 buffer_sample;
    //fread(&buffer_sample, sizeof(BYTE), 2, input);

    while(fread(&buffer_sample, sizeof(BYTE2), 1, input)) {
        buffer_sample=buffer_sample*factor;

        fwrite(&buffer_sample, sizeof(BYTE2), 1, output);

    }


    // Close files
    fclose(input);
    fclose(output);
}
