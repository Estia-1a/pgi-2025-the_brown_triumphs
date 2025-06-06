#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !!!");
}
void dimension (char *source_path){
    int width;
    int height;
    int channel_count;
    unsigned char *data;
    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (resultat){
        printf("dimension : %d, %d", width, height);
    } 
    else {
        printf("ERROR");
    }
}
void first_pixel (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
   
    if (result){
        printf("first_pixel: %d, %d, %d", data[0], data[1], data[2]);
    } 
    else {
        printf("ERROR");
    }
}
void tenth_pixel (char *source_path) {
    int width, height, channel_count;
    int pixel = 10;
    unsigned char *data;

    int resultat = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (resultat){
    printf("tenth_pixel: %d, %d, %d", data[3*(pixel-1)], data[3*(pixel-1)+1], data[3*(pixel-1)+2]);
    }
    else {
        printf("ERROR");
    }

}
void second_line(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (result) {
    printf("second_line: %d, %d, %d", data[3 * width], data[3 * width + 1],  data[3 * width + 2]);
    }
    else {
        printf("ERROR");
    }
}