#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

void process_file(FILE *file);

int IMG_BLOCK_SIZE = 512;

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Could not open file.\n");
        return 1;
    }

    process_file(file);

    fclose(file);
}

void process_file(FILE *file)
{
    int jpeg_num = 0;
    FILE *img;

    while (true)
    {
        BYTE img_block[IMG_BLOCK_SIZE];
        int read_bytes = fread(&img_block, IMG_BLOCK_SIZE, 1, file);

        if (read_bytes != 1)
        {
            break;
        }

        // Check jpeg image found
        if (img_block[0] == 0xff && img_block[1] == 0xd8 && img_block[2] == 0xff
            && (img_block[3] >= 0xe0 && img_block[3] <= 0xef))
        {
            if (jpeg_num > 0)
            {
                fclose(img);
            }

            // Allocate 7 byte of memory for string and 1 byte for null
            char filename[8];

            // Open a new imamge and write into it
            sprintf(filename, "%03i.jpg", jpeg_num);
            jpeg_num++;
            img = fopen(filename, "w");
        }

        if (jpeg_num > 0)
        {
            fwrite(img_block, IMG_BLOCK_SIZE, 1, img);
        }
    }

    if (img > 0)
    {
        fclose(img);
    }
}
