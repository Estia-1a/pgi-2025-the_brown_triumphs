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

void color_desaturate(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);

            unsigned char R = pixel->R;
            unsigned char G = pixel->G;
            unsigned char B = pixel->B;

             unsigned char value = (R+G +B) / 3;

            new_data[(y * width + x) * channel_count] = value;
            new_data[(y * width + x) * channel_count + 1] =value;
            new_data[(y * width + x) * channel_count + 2] = value ;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void scale_nearest(char *source_path, float scale) {
    int original_width, original_height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &original_width, &original_height, &channel_count);

    int new_width = (int)(original_width * scale);
    int new_height = (int)(original_height * scale);

    unsigned char *new_data = (unsigned char*)malloc(new_width * new_height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < new_height; y++) {
        int nearest_y = (int)(y / scale);
        for (int x = 0; x < new_width; x++) {
            int nearest_x = (int)(x / scale);
            for (int c = 0; c < channel_count; c++) {
                new_data[(y * new_width + x) * channel_count + c] = data[(nearest_y * original_width + nearest_x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, new_width, new_height);
    free(new_data);
    free_image_data(data);
}

void mirror_vertical(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) { 
        for (int x = 0; x < width; x++) {
            int new_x = x;
            int new_y = height - 1 - y;

            for (int c = 0; c < channel_count; c++) {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}
void scale_crop(char *source_path, int center_x, int center_y, int width, int height) {
    int original_width, original_height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &original_width, &original_height, &channel_count);

    int x_start = center_x - width / 2;
    int y_start = center_y - height / 2;

    if (x_start < 0) {
        x_start = 0;
    } else if (x_start + width > original_width) {
        x_start = original_width - width;
    }

    if (y_start < 0) {
        y_start = 0;
    } else if (y_start + height > original_height) {
        y_start = original_height - height;
    }

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int new_x = x_start + x;
            int new_y = y_start + y;

            pixelRGB *pixel = get_pixel(data, original_width, original_height, channel_count, new_x, new_y);
            unsigned char R = pixel->R;
            unsigned char G = pixel->G;
            unsigned char B = pixel->B;

            new_data[(y * width + x) * channel_count] = R;
            new_data[(y * width + x) * channel_count + 1] = G;
            new_data[(y * width + x) * channel_count + 2] = B;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}


void color_gray(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char gray = (pixel->R + pixel->G + pixel->B) / 3;
            new_data[(y * width + x) * channel_count] = gray;
            new_data[(y * width + x) * channel_count + 1] = gray ;
            new_data[(y * width + x) * channel_count + 2] = gray;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}
void color_gray_luminance(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char value = 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
            new_data[(y * width + x) * channel_count] = value;
            new_data[(y * width + x) * channel_count + 1] =value;
            new_data[(y * width + x) * channel_count + 2] = value ; 
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
            new_data[(y * width + x) * channel_count + 1] = green;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}
void color_blue(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char blue = pixel->B;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = 0;
            new_data[(y * width + x) * channel_count + 2] = blue;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}
void color_invert(char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char *new_data = (unsigned char*)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y=0; y<height; y++){
        for (int x=0; x<width; x++){
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            new_data[(y*width + x) * channel_count]= 255 - pixel->R;
            new_data[(y*width + x) * channel_count + 1]= 255 - pixel->G;
            new_data[(y*width + x) * channel_count + 2]= 255 - pixel->B;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}