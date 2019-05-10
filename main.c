#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function Prototypes
void pixelMean(float *r, float *g, float *b);               //Sets RBG of each pixel to the average (greyscale).

int main() {
    float image[5][5][3];
    int x, y;
    
    /*
    srand(0);
    
    for(y = 0; y < 5; y++) {
        for(x = 0; x < 5; x++) {
            image[x][y][0] = (float)rand()/(float)INT_MAX;
            image[x][y][1] = (float)rand()/(float)INT_MAX;
            image[x][y][2] = (float)rand()/(float)INT_MAX;
        }
    }
    
    */
   
    FILE *imageFile;
    double ColorIntensity;
    int i; 
    int j;

    imageFile=fopen("image.txt", "r");

    for(i = 0; i < 25; i++) {
        for (j = 0 ; j < 3; j++) {
        fscanf(imageFile,"%lf",&ColorIntensity);
        // printf("%f ",ColorIntensity);                    //Add in to make sure it reads correctly.
            switch(i/5) {
                case 0:
                    y = 0;
                    break;
            
                case 1:
                    y = 1;
                    break;
            
                case 2:
                    y = 2;
                    break;
            
                case 3:
                    y = 3;
                    break;
            
                case 4:
                    y = 4;
                    break;
            }
      
            switch(i % 5) {
                case 0:
                    x = 0;
                    break;
            
                case 1:
                    x = 1;
                    break;
            
                case 2:
                    x = 2;
                    break;
            
                case 3:
                    x = 3;
                    break;
            
                case 4:
                    x = 4;
                    break;
            }
        image[x][y][j]=(float)ColorIntensity;
        }
    }

    fclose(imageFile);
   
    //Colourized
    printf("\t\t\tRow 0 & 1, Colourised\n");
    printf("==================================================================\n");
    printf("Color: \t\t\t     R\t\t     G\t\t     B\n");
    
    for(y=0; y<2; y++) {
            printf("Row %d: ", y);
            
            for(x=0; x<5; x++) {
                printf("\t Column %d: \t %f\t %f\t %f\t \n", x, image[x][y][0], image[x][y][1], image[x][y][2]);
                }
            printf("\n");
    }
    
    //Greyscale
    printf("\t\t\tRow 0 & 1, Greyscale\n");
    printf("==================================================================\n");
    printf("Color: \t\t\t     R\t\t     G\t\t     B\n");
    
    for(y=0; y<2; y++) {
            printf("Row %d: ", y);
            
            for(x=0; x<5; x++) {
                pixelMean(&image[x][y][0], &image[x][y][1], &image[x][y][2]);                                       // Color to Greyscale converter
                printf("\t Column %d: \t %f\t %f\t %f\t \n", x, image[x][y][0], image[x][y][1], image[x][y][2]);
                }
            printf("\n");
    }
    

    return 0;

}

// Function Definitions
void pixelMean(float *r, float *g, float *b) {
    float average = (*r+*g+*b)/3;
    *r = average;
    *g = average;
    *b = average;
}
