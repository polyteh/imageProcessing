#pragma once
#include <string> 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using std::string;
using namespace cv;
using std::vector;



class myImageProcessing
{
	public:
	myImageProcessing();//конструктор с картинкой по умолчанию
	void setImage(string & imageName);
	Mat & getOriginalImage(){return originalImage;};//загрузка картинки
	Mat & getGrayscaleImage();	//преобоазование в серый
	Mat & getTresholdImage(int tresh); //преобразование в бинарный с параметром от слайдера
	void findContour();//поиск контуров
	Mat & getContourImage();//отрисовка контура
	Mat & getHullImage();//отрисовка hull


	
	
	
	private:
	string imageName="d:\\Education\\C++\\projects\\image_processing\\sourse\\data\\ellipse.png";
	Mat originalImage;
	Mat BGR2GRAY_image;
	Mat adaptiveTresholdImage;
	Mat contoursImage;
	Mat hullImage;
	int const lowTreshold=100;
	int gain; //сделал переменную, чтобы отслеживать перемещение слайдера
	
	Mat imageCanny; //готовим место для хранения обработанного бинарного изображения
	
	vector< vector<Point> > imageContours; //массив векторов точек для хранения контуров (FindContour), как я понял это вектор из векторов объектов типа Point
	vector<Vec4i> imageHierarchy; //пока с ним мало разобрался, на уровне простых картинок
	





	
	
};




