#pragma once
#include <string> 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

//using std::string;
//using namespace cv;
//using std::vector;



class myImageProcessing
{
	public:
	myImageProcessing();//конструктор с картинкой по умолчанию
	void setImage(std::string & imageName);
	cv::Mat & getOriginalImage(){return originalImage;};//загрузка картинки
	cv::Mat & getGrayscaleImage();	//преобоазование в серый
	cv::Mat & getTresholdImage(int tresh); //преобразование в бинарный с параметром от слайдера
	void findContour();//поиск контуров
	cv::Mat & getContourImage();//отрисовка контура
	cv::Mat & getHullImage();//отрисовка hull


	
	
	
	private:
	std::string imageName="d:\\Education\\C++\\projects\\image_processing\\sourse\\data\\ellipse.png";
	cv::Mat originalImage;
	cv::Mat BGR2GRAY_image;
	cv::Mat adaptiveTresholdImage;
	cv::Mat contoursImage;
	cv::Mat hullImage;
	int const lowTreshold=100;
	int gain; //сделал переменную, чтобы отслеживать перемещение слайдера
	
	cv::Mat imageCanny; //готовим место для хранения обработанного бинарного изображения
	
	std::vector< std::vector<cv::Point> > imageContours; //массив векторов точек для хранения контуров (FindContour), как я понял это вектор из векторов объектов типа Point
	std::vector<cv::Vec4i> imageHierarchy; //пока с ним мало разобрался, на уровне простых картинок
	





	
	
};




