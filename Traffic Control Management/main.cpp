#include <cv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "caliberate.h"	
#include <iostream>
#include <ctime>				
#include <cmath>


using namespace std;
using namespace cv;
VideoCapture capture;		//The capture class captures video either from harddisk(.avi) or from camera
Mat frameImg;				
Mat g_image;				

double dist(Point2i x1, Point2i x2)	
{	
	return sqrt( pow((x1.x-x2.x),2) + pow((x1.y-x2.y),2) ); 
}