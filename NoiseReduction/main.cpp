#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "noise.h"

void printImage(){
    int i,j;
    char **im = image();
    for( i=0; i<100;i++)
    {
        for(j=0; j<=120;j++)
        {
            if(im[i][j]=='1')
            {
                printf("#");
            }
			else
            {
				printf(" ");
			}
		}
    }
}

void erosion(){
	int i,j,x,y,r,c;
	char **im = image();
	char buf[100][120];
	for( x=0;x<100;x++)
    {
		for(y=0;y<120;y++)
		{
		buf[x][y]=' ';
        }
	}
	for( i=1; i<=98;i++)
	{
		for(j=1; j<=118;j++)
		{
            if((im[i][j]=='1'&&im[i+1][j]=='1'&&im[i-1][j]=='1')||(im[i][j]=='1'&&im[i][j+1]=='1'&&im[i][j-1]=='1'))
			{
				if(im[i][j+1]=='0'||im[i][j-1]=='0'||im[i+1][j+1]=='0'||im[i+1][j-1]=='0'||im[i-1][j+1]=='0'||im[i-1][j-1]=='0'||im[i+1][j]=='0'||im[i-1][j]=='0'||im[i+1][j-1]=='0'||im[i-1][j-1]=='0'||im[i+1][j+1]=='0'||im[i-1][j+1]=='0')
				{
					buf[i][j]='#';
				}
			}
			else
			{
				buf[i][j]=' ';
			}
		}
	}
	for( r=0; r<100;r++)
	{
        for(c=0; c<=120;c++)
        {
            printf("%c",buf[r][c]);
        }
    }
}

void median(){
	char **noise = image_n();
	int i,j,d,c,t,x,y;
    //noise reduction
	for( i=1; i<=98;i++)
    {
		for(j=1; j<=118;j++)
		{
			int n = 9;
			char array[n]; // 3 by 3 matrix is going to be saved to array to be sorted
			array[0]=noise[i-1][j-1];
			array[1]=noise[i-1][j+1];
			array[2]=noise[i+1][j-1];
			array[3]=noise[i+1][j+1];
			array[4]=noise[i][j-1]; // median
			array[5]=noise[i][j+1];
			array[6]=noise[i-1][j];
			array[7]=noise[i+1][j];
			array[8]=noise[i][j];
			//insertion sorting (you can use any sorting algorithms):
			for (c = 1 ; c <= n - 1; c++)
			{
                d = c;
                while ( d > 0 && array[d] < array[d-1])
                {
				      t = array[d];
				      array[d] = array[d-1];
				      array[d-1] = t;
				      d--;
                }
            }
			//update array noise with the median
			noise[i][j]=array[4];
		}
	}
    //all edges are going to be equal to zero
	for(i=0;i<100;i++)
	{
		noise[i][0]='0';
		noise[i][119]='0';
	}
	for(j=0;j<120;j++)
	{
		noise[0][j]='0';
		noise[99][j]='0';
	}
    //as a result: clean image
    for( i=0; i<100;i++)
    {
        for(j=0; j<=120;j++)
        {
            if(noise[i][j]=='1')
            {
                printf("#");
            }
			else
            {
				printf(" ");
			}
		}
    }
    //find edges of the shape in image with the help of erosion method
	char **im = noise;
	char buf[100][120];
	for( x=0;x<100;x++)
    {
		for(y=0;y<120;y++)
		{
            buf[x][y]=' ';
        }
	}
	for( i=1; i<=98;i++)
	{
		for(j=1; j<=118;j++)
		{
			if((im[i][j]=='1'&&im[i+1][j]=='1'&&im[i-1][j]=='1')||(im[i][j]=='1'&&im[i][j+1]=='1'&&im[i][j-1]=='1'))
			{
				if(im[i][j+1]=='0'||im[i][j-1]=='0'||im[i+1][j+1]=='0'||im[i+1][j-1]=='0'||im[i-1][j+1]=='0'||im[i-1][j-1]=='0'||im[i+1][j]=='0'||im[i-1][j]=='0'||im[i+1][j-1]=='0'||im[i-1][j-1]=='0'||im[i+1][j+1]=='0'||im[i-1][j+1]=='0')
				{
					buf[i][j]='#';
				}
			}
			else
			{
				buf[i][j]=' ';
			}
		}
	}
    //print the result
    for( x=0; x<100;x++)
    {
        for(y=0; y<=120;y++)
        {
            printf("%c",buf[x][y]);
        }
    }
}

int main()
{
    printImage();
    erosion();
    median();
    getchar();
    return 0;
}
