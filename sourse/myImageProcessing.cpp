#include "myImageProcessing.h"
#include "opencv2/core/types.hpp"
#include <opencv2/core/core.hpp>


using namespace cv;
using namespace std;



myImageProcessing::myImageProcessing()
{

	originalImage=imread(imageName,1);
	
}

void myImageProcessing::setImage(string & imageName)
{
	originalImage=imread(imageName);
	
}
void myImageProcessing::findContour()
{
		Canny(adaptiveTresholdImage,imageCanny, lowTreshold, lowTreshold*2,5);
		findContours(imageCanny,imageContours,imageHierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);	
	
	
}

Mat & myImageProcessing::getContourImage()
{
	contoursImage= Mat::zeros(imageCanny.size(), CV_8UC3); //инициирвали место под контур

	 int in=0; //счетчик условно наружных и внутренних контуров
	 int out=0;
	 cout<<"Contouur number is "<<imageContours.size()<<endl;
	 for (int i=0; i<imageContours.size(); i++)//пробегаемся по всем контурам
		 { 

			if (imageHierarchy[i][3] != -1) //выбираем те, которые не имеют родителей
				{ 

				 // Scalar colour((rand()&255), (rand()&255), (rand()&255)); 
				 Scalar colour1(gain, 255, 255); 
				 drawContours(contoursImage, imageContours, i, colour1,2,LINE_8, imageHierarchy,0); 
				  double area0 = contourArea(imageContours[i],true); //считаем и отображаем площади фигур, внутри контура. Значение положительно, значит это родительский контур с обходом по часовой стрелке (если я правильно понял)
				  cout<<"Area of countour "<<i<<" is "<<area0<<endl;
				  out++;
				  
				}
				
			else
				{
				Scalar colour2(gain, 255, 255); 
				//drawContours(contoursImage, imageContours, i, colour2,2, LINE_8, imageHierarchy,0); 
				double area0 = contourArea(imageContours[i],true);
				cout<<"Area of countour "<<i<<" is "<<area0<<endl;
				in++;
					
				}					
		 }

	cout<<"in="<<in<<endl<<"out="<<out<<endl;
	return contoursImage;
	
}


Mat & myImageProcessing::getHullImage ()
{
	vector<vector<Point> >hull(imageContours.size());
	for( int i = 0; i < imageContours.size(); i++ )
      {  
		convexHull(imageContours[i], hull[i], true ); 
	  }

	hullImage = Mat::zeros(contoursImage.size(),CV_8UC3);
	for( int i = 0; i< hull.size(); i++)
      {
        Scalar color = Scalar(gain, 255, 255);
		drawContours(hullImage,hull,i,color);
      }
	return hullImage;
}

Mat & myImageProcessing::getGrayscaleImage()
{
	
	cvtColor(originalImage, BGR2GRAY_image, CV_BGR2GRAY);
	return BGR2GRAY_image;
	
}	

Mat & myImageProcessing::getTresholdImage(int tresh)
{
	
	threshold(BGR2GRAY_image,adaptiveTresholdImage,tresh,255,THRESH_BINARY_INV);
	gain=tresh;
	return adaptiveTresholdImage;
	
	
}	

