#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename) {
    FILE *fin = fopen(filename, "r");
    if(!fin) {
        return NULL;
    }

    ImagePPM* imagePPM = malloc(sizeof(ImagePPM));
    fscanf(fin, "%s", imagePPM->magic); // Magic Number

    fscanf(fin, "%d %d", &imagePPM->numCols, &imagePPM->numRows); // Number of rows and columns

    fscanf(fin, "%d", &imagePPM->maxVal);

    Pixel** pixelMatrix = malloc(sizeof(Pixel*) * imagePPM->numRows);
    for(int i = 0; i < imagePPM->numRows; i++) {
        pixelMatrix[i] = malloc(sizeof(Pixel) * imagePPM->numCols);
    }

    for(int i = 0; i < imagePPM->numRows; i++) {
        for(int j = 0; j < imagePPM->numCols; j++) {
            fscanf(fin, "%d %d %d", &pixelMatrix[i][j].red, &pixelMatrix[i][j].green, &pixelMatrix[i][j].blue);
        }
    }

    imagePPM->pixels = pixelMatrix;

    fclose(fin);
    return imagePPM;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename) {
    FILE *fout = fopen(filename, "w");
    if(!fout) {
        return 0;
    }

    fprintf(fout, "%s\n", pImagePPM->magic);

    fprintf(fout, "%d %d\n", pImagePPM->numCols, pImagePPM->numRows);

    fprintf(fout, "%d\n", pImagePPM->maxVal);

    for(int i = 0; i < pImagePPM->numRows; i++) {
        for(int j = 0; j < pImagePPM->numCols; j++) {
            fprintf(fout, "%d %d %d", pImagePPM->pixels[i][j].red, pImagePPM->pixels[i][j].green, pImagePPM->pixels[i][j].blue);
            if(j + 1 != pImagePPM->numCols) {
                fprintf(fout, "  ");
            }
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
    return 1;
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM) {
    for(int i = 0; i < pImagePPM->numRows; i++) {
            free(pImagePPM->pixels[i]);
    }
    free(pImagePPM->pixels);
    free(pImagePPM);
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename) {
    FILE *fin = fopen(filename, "r");
    if(!fin) {
        return NULL;
    }

    ImagePGM* imagePGM = malloc(sizeof(ImagePGM));
    fscanf(fin, "%s", imagePGM->magic);

    fscanf(fin, "%d %d", &imagePGM->numCols, &imagePGM->numRows);

    fscanf(fin, "%d", &imagePGM->maxVal);

    int** pixelMatrix = malloc(sizeof(int*) * imagePGM->numRows);
    for(int i = 0; i < imagePGM->numRows; i++) {
            pixelMatrix[i] = malloc(sizeof(int) * imagePGM->numCols);
    }

    for(int i = 0; i < imagePGM->numRows; i++) {
        for(int j = 0; j < imagePGM->numCols; j++) {
            fscanf(fin, "%d", &pixelMatrix[i][j]);
        }
    }

    imagePGM->pixels = pixelMatrix;

    fclose(fin);
    return imagePGM;
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename) {
    FILE *fout = fopen(filename, "w");
    if(!fout) {
        return 0;
    }

    fprintf(fout, "%s\n", pImagePGM->magic);

    fprintf(fout, "%d %d\n", pImagePGM->numCols, pImagePGM->numRows);

    fprintf(fout, "%d\n", pImagePGM->maxVal);

    for(int i = 0; i < pImagePGM->numRows; i++) {
        for(int j = 0; j < pImagePGM->numCols; j++) {
            fprintf(fout, "%d", pImagePGM->pixels[i][j]);
            if(j + 1 != pImagePGM->numCols) {
                fprintf(fout, "  ");
            }
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
    return 1;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM) {
    for(int i = 0; i < pImagePGM->numRows; i++) {
        free(pImagePGM->pixels[i]);
    }
    free(pImagePGM->pixels);
    free(pImagePGM);
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM) {
    ImagePGM* imagePGM = malloc(sizeof(ImagePGM));

    strcpy(imagePGM->magic, "P2");

    imagePGM->numCols = pImagePPM->numCols;
    imagePGM->numRows = pImagePPM->numRows;

    imagePGM->maxVal = pImagePPM->maxVal;

    int** pixelMatrix = malloc(sizeof(int*) * imagePGM->numRows);
    for(int i = 0; i < imagePGM->numRows; i++) {
        pixelMatrix[i] = malloc(sizeof(int) * imagePGM->numCols);
    }

    imagePGM->pixels = pixelMatrix;

    int newPixelVal;
    for(int i = 0; i < pImagePPM->numRows; i++) {
        for(int j = 0; j < pImagePPM->numCols; j++) {
            newPixelVal = pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].green + pImagePPM->pixels[i][j].blue;
            imagePGM->pixels[i][j] = newPixelVal / 3;
        }
    }

    return imagePGM;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM) {
        ImagePGM* imagePGM = malloc(sizeof(ImagePGM));

        strcpy(imagePGM->magic, "P2");

        imagePGM->numCols = pImagePGM->numCols / 2;
        imagePGM->numRows = pImagePGM->numRows / 2;

        imagePGM->maxVal = pImagePGM->maxVal;

        int** pixelMatrix = malloc(sizeof(int*) * (imagePGM->numRows));
        for(int i = 0; i < imagePGM->numRows; i++) {
            pixelMatrix[i] = malloc(sizeof(int) * (imagePGM->numCols));
        }

        imagePGM->pixels = pixelMatrix;

        int newPixelVal;
        int shrinkIndexi = 0, shrinkIndexj = 0;
        for(int i = 0; i < pImagePGM->numRows - 1; i+=2, shrinkIndexi++) {
            for(int j = 0; j < pImagePGM->numCols - 1; j+=2, shrinkIndexj++) {
                newPixelVal = pImagePGM->pixels[i][j] + pImagePGM->pixels[i + 1][j] + pImagePGM->pixels[i][j + 1] + pImagePGM->pixels[i + 1][j + 1];
                pixelMatrix[shrinkIndexi][shrinkIndexj] = newPixelVal / 4;
            }
            shrinkIndexj = 0;
        }

        return imagePGM;
}
