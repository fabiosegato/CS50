#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0;i<height;i++){
        for(int j=0;j<width;j++){
            int average = round((float) (image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_aux;
    for(int i =0;i<height;i++){

        for(int j=0;j<width/2;j++){

            image_aux = image[i][j];

            image[i][j] = image[i][width-j-1];

            image[i][width-j-1]= image_aux;
       }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

RGBTRIPLE image_aux[height][width];


    for(int i =0;i<height;i++){

        for(int j=0;j<width;j++){

            //canto superior esquerdo
            if(i==0 && j==0){

                //printf("canto superior esquerdo i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/4);
                image_aux[i][j].rgbtRed = round((float)(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/4);
                image_aux[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/4);

            }

            //canto superior direito
            if(i==0 && j==width-1){

                //printf("canto superior direito i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j-1].rgbtBlue)/4);
                image_aux[i][j].rgbtRed = round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j-1].rgbtRed)/4);
                image_aux[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j-1].rgbtGreen)/4);

            }

            //canto inferior esquerdo
            if(i==height-1 && j==0){

                //printf("canto inferior esquerdoo i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue)/4);
                image_aux[i][j].rgbtRed = round((float)(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/4);
                image_aux[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen)/4);

            }

            //canto inferior direito
            if(i==height-1 && j==width-1){

                //printf("canto inferior direito i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue)/4);
                image_aux[i][j].rgbtRed = round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed)/4);
                image_aux[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen)/4);

            }

            //lateral esquerda
            if(j==0 && (i>0 && i<height-1) ){

                //printf("lateral esquerda i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtGreen = round((float)(image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6);
                image_aux[i][j].rgbtBlue = round((float)(image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6);
                image_aux[i][j].rgbtRed = round((float)(image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6);

            }

            //lateral direita
            if(j==width-1 && (i>0 && i<height-1) ){

                //printf("lateral esquerda i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtGreen = round((float)(image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/6);
                image_aux[i][j].rgbtBlue = round((float)(image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/6);
                image_aux[i][j].rgbtRed = round((float)(image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/6);

            }

            //topo
            if(i==0 && (j>0 && j<width-1) ){

                //printf("topo i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtGreen = round((float)(image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/6);
                image_aux[i][j].rgbtBlue = round((float)(image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/6);
                image_aux[i][j].rgbtRed = round((float)(image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/6);

            }

            //rodape
            if(i==height-1 && (j>0 && j<width-1) ){

                // printf("rodape i:%i j:%i\n",i,j);

                image_aux[i][j].rgbtGreen = round((float)(image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen)/6);
                image_aux[i][j].rgbtBlue = round((float)(image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue)/6);
                image_aux[i][j].rgbtRed = round((float)(image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed)/6);

            }

            //meio
            if((i>0 && j>0) && (i<height-1) && (j<width-1)){


                image_aux[i][j].rgbtBlue = round((float) (image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/9);
                image_aux[i][j].rgbtRed = round((float) (image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/9);
                image_aux[i][j].rgbtGreen = round((float) (image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/9);


            }

       }
    }

     for(int i =0;i<height;i++){

        for(int j=0;j<width;j++){
            image[i][j] = image_aux[i][j];

        }

     }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

RGBTRIPLE image_aux[height][width];

    for(int i =0;i<height;i++){

        for(int j=0;j<width;j++){

            //canto superior esquerdo
            if(i==0 && j==0){

                int aux_blue_gx= ((image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j+1].rgbtBlue*1));
                int aux_blue_gy= ((image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j+1].rgbtBlue*1));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= ((image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2)+(image[i+1][j].rgbtRed*0)+(image[i+1][j+1].rgbtRed*1));
                int aux_red_gy= ((image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0)+(image[i+1][j].rgbtRed*2)+(image[i+1][j+1].rgbtRed*1));
                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= ((image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j+1].rgbtGreen*1));
                int aux_green_gy= ((image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j+1].rgbtGreen*1));
                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }


            }

            //canto superior direito
            if(i==0 && j==width-1){

                int aux_blue_gx= ((image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*-2)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j-1].rgbtBlue*-1));
                int aux_blue_gy= ((image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*0)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j-1].rgbtBlue*1));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= ((image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*-2)+(image[i+1][j].rgbtRed*0)+(image[i+1][j-1].rgbtRed*-1));
                int aux_red_gy= ((image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*0)+(image[i+1][j].rgbtRed*2)+(image[i+1][j-1].rgbtRed*1));
                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= ((image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*-2)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j-1].rgbtGreen*-1));
                int aux_green_gy= ((image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*0)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j-1].rgbtGreen*1));
                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }


            }

            //canto inferior esquerdo
            if(i==height-1 && j==0){

                int aux_blue_gx= ((image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2)+(image[i-1][j].rgbtBlue*0)+(image[i-1][j+1].rgbtBlue*1));
                int aux_blue_gy= ((image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0)+(image[i-1][j].rgbtBlue*-2)+(image[i-1][j+1].rgbtBlue*-1));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));

                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                    //image_aux[i][j].rgbtBlue=0;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                    //image_aux[i][j].rgbtBlue=0;
                }

                int aux_red_gx= ((image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2)+(image[i-1][j].rgbtRed*0)+(image[i-1][j+1].rgbtRed*1));
                int aux_red_gy= ((image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0)+(image[i-1][j].rgbtRed*-2)+(image[i-1][j+1].rgbtRed*-1));

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                    //image_aux[i][j].rgbtRed=0;
                } else {
                    image_aux[i][j].rgbtRed=255;
                    //image_aux[i][j].rgbtRed=0;
                }

                int aux_green_gx= ((image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2)+(image[i-1][j].rgbtGreen*0)+(image[i-1][j+1].rgbtGreen*1));
                int aux_green_gy= ((image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0)+(image[i-1][j].rgbtGreen*-2)+(image[i-1][j+1].rgbtGreen*-1));

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                    //image_aux[i][j].rgbtGreen=0;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                    //image_aux[i][j].rgbtGreen=0;
                }


            }

            //canto inferior direito
            if(i==height-1 && j==width-1){

                int aux_blue_gx= ((image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*-2)+(image[i-1][j].rgbtBlue*0)+(image[i-1][j-1].rgbtBlue*-1));
                int aux_blue_gy= ((image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*0)+(image[i-1][j].rgbtBlue*-2)+(image[i-1][j-1].rgbtBlue*-1));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= ((image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*-2)+(image[i-1][j].rgbtRed*0)+(image[i-1][j-1].rgbtRed*-1));
                int aux_red_gy= ((image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*0)+(image[i-1][j].rgbtRed*-2)+(image[i-1][j-1].rgbtRed*-1));

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= ((image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*-2)+(image[i-1][j].rgbtGreen*0)+(image[i-1][j-1].rgbtGreen*-1));
                int aux_green_gy= ((image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*0)+(image[i-1][j].rgbtGreen*-2)+(image[i-1][j-1].rgbtGreen*-1));

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }


            }

            //lateral esquerda
            if(j==0 && (i>0 && i<height-1) ){


                int aux_blue_gx= (image[i-1][j].rgbtBlue*0)+(image[i-1][j+1].rgbtBlue*1)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j+1].rgbtBlue*1);
                int aux_blue_gy= (image[i-1][j].rgbtBlue*-2)+(image[i-1][j+1].rgbtBlue*-1)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j+1].rgbtBlue*1);

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= (image[i-1][j].rgbtRed*0)+(image[i-1][j+1].rgbtRed*1)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2)+(image[i+1][j].rgbtRed*0)+(image[i+1][j+1].rgbtRed*1);
                int aux_red_gy= (image[i-1][j].rgbtRed*-2)+(image[i-1][j+1].rgbtRed*-1)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0)+(image[i+1][j].rgbtRed*2)+(image[i+1][j+1].rgbtRed*1);

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= (image[i-1][j].rgbtGreen*0)+(image[i-1][j+1].rgbtGreen*1)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j+1].rgbtGreen*1);
                int aux_green_gy= (image[i-1][j].rgbtGreen*-2)+(image[i-1][j+1].rgbtGreen*-1)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j+1].rgbtGreen*1);

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }

            }

            //lateral direita
            if(j==width-1 && (i>0 && i<height-1) ){


                int aux_blue_gx= (image[i-1][j].rgbtBlue*0)+(image[i-1][j-1].rgbtBlue*-1)+(image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*-2)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j-1].rgbtBlue*-1);
                int aux_blue_gy= (image[i-1][j].rgbtBlue*-2)+(image[i-1][j-1].rgbtBlue*-1)+(image[i][j].rgbtBlue*0)+(image[i][j-1].rgbtBlue*0)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j-1].rgbtBlue*1);

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= (image[i-1][j].rgbtRed*0)+(image[i-1][j-1].rgbtRed*-1)+(image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*-2)+(image[i+1][j].rgbtRed*0)+(image[i+1][j-1].rgbtRed*-1);
                int aux_red_gy= (image[i-1][j].rgbtRed*-2)+(image[i-1][j-1].rgbtRed*-1)+(image[i][j].rgbtRed*0)+(image[i][j-1].rgbtRed*0)+(image[i+1][j].rgbtRed*2)+(image[i+1][j-1].rgbtRed*1);

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= (image[i-1][j].rgbtGreen*0)+(image[i-1][j-1].rgbtGreen*-1)+(image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*-2)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j-1].rgbtGreen*-1);
                int aux_green_gy= (image[i-1][j].rgbtGreen*-2)+(image[i-1][j-1].rgbtGreen*-1)+(image[i][j].rgbtGreen*0)+(image[i][j-1].rgbtGreen*0)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j-1].rgbtGreen*1);

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }

            }

            //topo
            if(i==0 && (j>0 && j<width-1) ){

                int aux_blue_gx= ((image[i][j-1].rgbtBlue*-2)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2)+(image[i+1][j-1].rgbtBlue*-1)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j+1].rgbtBlue*1));
                int aux_blue_gy= ((image[i][j-1].rgbtBlue*0)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0)+(image[i+1][j-1].rgbtBlue*1)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j+1].rgbtBlue*1));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));

                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= ((image[i][j-1].rgbtRed*-2)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2)+(image[i+1][j-1].rgbtRed*-1)+(image[i+1][j].rgbtRed*0)+(image[i+1][j+1].rgbtRed*1));
                int aux_red_gy= ((image[i][j-1].rgbtRed*0)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0)+(image[i+1][j-1].rgbtRed*1)+(image[i+1][j].rgbtRed*2)+(image[i+1][j+1].rgbtRed*1));

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= ((image[i][j-1].rgbtGreen*-2)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2)+(image[i+1][j-1].rgbtGreen*-1)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j+1].rgbtGreen*1));
                int aux_green_gy= ((image[i][j-1].rgbtGreen*0)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0)+(image[i+1][j-1].rgbtGreen*1)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j+1].rgbtGreen*1));

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }

            }

            //rodape
            if(i==height-1 && (j>0 && j<width-1) ){


                int aux_blue_gx= ((image[i-1][j-1].rgbtBlue*-1)+(image[i-1][j].rgbtBlue*0)+(image[i-1][j+1].rgbtBlue*1)+(image[i][j-1].rgbtBlue*-2)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2));
                int aux_blue_gy= ((image[i-1][j-1].rgbtBlue*-1)+(image[i-1][j].rgbtBlue*-2)+(image[i-1][j+1].rgbtBlue*-1)+(image[i][j-1].rgbtBlue*0)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0));

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));

                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= ((image[i-1][j-1].rgbtRed*-1)+(image[i-1][j].rgbtRed*0)+(image[i-1][j+1].rgbtRed*1)+(image[i][j-1].rgbtRed*-2)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2));
                int aux_red_gy= ((image[i-1][j-1].rgbtRed*-1)+(image[i-1][j].rgbtRed*-2)+(image[i-1][j+1].rgbtRed*-1)+(image[i][j-1].rgbtRed*0)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0));

                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= ((image[i-1][j-1].rgbtGreen*-1)+(image[i-1][j].rgbtGreen*0)+(image[i-1][j+1].rgbtGreen*1)+(image[i][j-1].rgbtGreen*-2)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2));
                int aux_green_gy= ((image[i-1][j-1].rgbtGreen*-1)+(image[i-1][j].rgbtGreen*-2)+(image[i-1][j+1].rgbtGreen*-1)+(image[i][j-1].rgbtGreen*0)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0));

                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }


            }

            if((i>0 && j>0) && (i<height-1) && (j<width-1)){

                int aux_blue_gx= (image[i-1][j-1].rgbtBlue*-1)+(image[i-1][j].rgbtBlue*0)+(image[i-1][j+1].rgbtBlue*1)+(image[i][j-1].rgbtBlue*-2)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2)+(image[i+1][j-1].rgbtBlue*-1)+(image[i+1][j].rgbtBlue*0)+(image[i+1][j+1].rgbtBlue*1);
                int aux_blue_gy= (image[i-1][j-1].rgbtBlue*-1)+(image[i-1][j].rgbtBlue*-2)+(image[i-1][j+1].rgbtBlue*-1)+(image[i][j-1].rgbtBlue*0)+(image[i][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*0)+(image[i+1][j-1].rgbtBlue*1)+(image[i+1][j].rgbtBlue*2)+(image[i+1][j+1].rgbtBlue*1);

                int aux_blue = round(sqrt(pow((double) aux_blue_gx,2)+pow((double) aux_blue_gy,2)));


                if(aux_blue<=255){
                    image_aux[i][j].rgbtBlue=aux_blue;
                } else {
                    image_aux[i][j].rgbtBlue=255;
                }

                int aux_red_gx= (image[i-1][j-1].rgbtRed*-1)+(image[i-1][j].rgbtRed*0)+(image[i-1][j+1].rgbtRed*1)+(image[i][j-1].rgbtRed*-2)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2)+(image[i+1][j-1].rgbtRed*-1)+(image[i+1][j].rgbtRed*0)+(image[i+1][j+1].rgbtRed*1);
                int aux_red_gy= (image[i-1][j-1].rgbtRed*-1)+(image[i-1][j].rgbtRed*-2)+(image[i-1][j+1].rgbtRed*-1)+(image[i][j-1].rgbtRed*0)+(image[i][j].rgbtRed*0)+(image[i][j+1].rgbtRed*0)+(image[i+1][j-1].rgbtRed*1)+(image[i+1][j].rgbtRed*2)+(image[i+1][j+1].rgbtRed*1);
                int aux_red = round(sqrt(pow((double) aux_red_gx,2)+pow((double) aux_red_gy,2)));

                //printf("red: %i \n",aux_red);

                if(aux_red<=255){
                    image_aux[i][j].rgbtRed=aux_red;
                } else {
                    image_aux[i][j].rgbtRed=255;
                }

                int aux_green_gx= (image[i-1][j-1].rgbtGreen*-1)+(image[i-1][j].rgbtGreen*0)+(image[i-1][j+1].rgbtGreen*1)+(image[i][j-1].rgbtGreen*-2)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2)+(image[i+1][j-1].rgbtGreen*-1)+(image[i+1][j].rgbtGreen*0)+(image[i+1][j+1].rgbtGreen*1);
                int aux_green_gy= (image[i-1][j-1].rgbtGreen*-1)+(image[i-1][j].rgbtGreen*-2)+(image[i-1][j+1].rgbtGreen*-1)+(image[i][j-1].rgbtGreen*0)+(image[i][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*0)+(image[i+1][j-1].rgbtGreen*1)+(image[i+1][j].rgbtGreen*2)+(image[i+1][j+1].rgbtGreen*1);
                int aux_green = round(sqrt(pow((double) aux_green_gx,2)+pow((double) aux_green_gy,2)));

                //printf("green: %i \n",aux_green);

                if(aux_green<=255){
                    image_aux[i][j].rgbtGreen=aux_green;
                } else {
                    image_aux[i][j].rgbtGreen=255;
                }


            }

       }
    }

     for(int i =0;i<height;i++){

        for(int j=0;j<width;j++){
            image[i][j] = image_aux[i][j];

        }

     }
    return;
}

// Sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i =0;i<height;i++){

        for(int j=0;j<width;j++){

           int sepiaRed = round((image[i][j].rgbtRed*0.393)+(image[i][j].rgbtGreen*0.769)+(image[i][j].rgbtBlue*0.189));
           int sepiaGreen = round((image[i][j].rgbtRed*0.349)+(image[i][j].rgbtGreen*0.686)+(image[i][j].rgbtBlue*0.168));
           int sepiaBlue = round((image[i][j].rgbtRed*0.272)+(image[i][j].rgbtGreen*0.534)+(image[i][j].rgbtBlue*0.131));

            if(sepiaRed<=255){
                image[i][j].rgbtRed = sepiaRed;
            } else {
                image[i][j].rgbtRed=255;
            }

            if(sepiaGreen<=255){
                image[i][j].rgbtGreen = sepiaGreen;
            } else {
                image[i][j].rgbtGreen=255;
            }

            if(sepiaBlue<=255){
                image[i][j].rgbtBlue = sepiaBlue;
            } else {
                image[i][j].rgbtBlue=255;
            }

        }

     }

    return;
}

