#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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

void max_pixel(char *source_path) {

    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int max_sum = -1 ;
    int max_x= 0, max_y = 0;
    pixelRGB max_pixel ={0, 0, 0};

    for (int y = 0; y <height; y++) {
        for (int x = 0; x < width; x++ ) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int sum = pixel->R + pixel->G + pixel->B;

            if ( sum > max_sum) {
                max_sum = sum;
                max_x = x ; 
                max_y = y;
                max_pixel = *pixel;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);
}
void max_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int max_value = -1; 
    int max_x_component = 0, max_y_component = 0 ;

    for (int y = 0; y < height ; y++ ) { 
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int value ;

            if (component == 'R'){
                value = pixel->R;
            } else if (component == 'G') { 
                value = pixel->G;
            } else {
                value = pixel->B;
            }

            if (value > max_value) { 
                max_value = value;
                max_x_component=x; 
                max_y_component=y;  
            }
        }

    }
    printf("max_component %c ( %d, %d ): %d", component, max_x_component , max_y_component , max_value);
}

void min_pixel(char *source_path) {

    int width, height, channel_count;
    int x = 0;
    int y = 0;
    unsigned char *data = NULL;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_sum = 256*3 ;
    int min_x= 0, min_y = 0;
    pixelRGB min_pixel ={255, 255, 255};


    for ( y=0; y <height; y++) {
        for ( x=0; x < width; x++ ) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int sum = pixel->R + pixel->G + pixel->B;

            if ( sum < min_sum) {
                min_sum = sum;
                min_x = x ; 
                min_y = y;
                min_pixel = *pixel;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
}
void min_component(char *source_path, char component) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int min_value = 256 ; 
    int min_x_component = 0, min_y_component = 0 ;

    for (int y = 0; y < height ; y++ ) { 
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            int value ;

            if (component == 'R'){
                value = pixel->R;
            } else if (component == 'G') { 
                value = pixel->G;
            } else {
                value = pixel->B;
            }

            if (value < min_value) { 
                min_value = value;
                min_x_component=x; 
                min_y_component=y;  
            }
        }

    }
    printf("min_component %c ( %d, %d ): %d", component, min_x_component , min_y_component , min_value);
}

void color_red(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char red = pixel->R;
            new_data[(y * width + x) * channel_count] = red;
            new_data[(y * width + x) * channel_count + 1] = 0;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_green(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char green = pixel->G;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = green ;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void rotate_acw(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++){
            int new_x = y;
            int new_y = width - 1 - x;

            for (int c = 0; c < channel_count; c++){
                new_data[(new_y * height + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, height, width);  
    free(new_data);
    free_image_data(data);
}

void rotate_cw(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++){
            int new_x = height - 1 - y;
            int new_y = x;

            for (int c = 0; c < channel_count; c++){
                new_data[(new_y * height + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, height, width);  
    free(new_data);
    free_image_data(data);
}

