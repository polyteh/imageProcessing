#include <opencv2/opencv.hpp>
#include<iostream>
#include <memory> 
#include <stdlib.h>
#include <stdio.h>

#include "myImageProcessing.h"


using namespace cv;
using namespace std;


unique_ptr<myImageProcessing> myImage(new myImageProcessing);
int thresh = 137;//начальное положение трешслайдера

void tresh_callback(int, void*);//функция для слайдера

int main(int argc, char* argv[])
{
			string imageName(argv[2]);//взяли имя файла из командной строки
			
			(*myImage).setImage(imageName);

			const char* source_window = "Original image";
			namedWindow(source_window);
			imshow(source_window,(*myImage).getOriginalImage());
			imshow("Greyscaled image", (*myImage).getGrayscaleImage());
			
			const int max_thresh = 255;
			createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, tresh_callback);

			tresh_callback(0,0);
			
			waitKey();	
			destroyAllWindows();

        return 0;
}

void tresh_callback(int, void* )	//интерактивное изменение картинок при сдвиге слайдера
{
	
	imshow("Treshold image",(*myImage).getTresholdImage(thresh));
	(*myImage).findContour();
	imshow("Contour image",(*myImage).getContourImage());
	imshow("Hull image",(*myImage).getHullImage());

	
}