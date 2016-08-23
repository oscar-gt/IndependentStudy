#include "opencv2/highgui/highgui.hpp"	
#include "opencv2/imgproc/imgproc.hpp" 	

// Oscar Garcia-Telles
// Code is a combination of provided
// code from the OpenCV by Example
// and OpenCV Essentials texts.
// However, I (Oscar) heavily 
// modified it to modularize the 
// code and to make it do exactly
// what I wanted it to do. 

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

// Prototyping
void grayHistEq(); 	// Gray scale histogram equalization
void colorHistEq();	// Color histogram equalization
// Helps create histogram graphs. 
void createHistGraph(Mat histSrc, Mat &histResult, int histSize, int binW);

void junk();

int main( int argc,  char *argv[] )
{
	int mode = 1;
	
	if(mode == 0)
	{
		cout << "Gray scale mode commencing..." << endl;
		grayHistEq();
		waitKey();
		return 0;
	}
	else if(mode == 1)
	{
		cout << "Color mode commencing..." << endl;
		colorHistEq();
		waitKey();
		return 0;
	}
	else
	{
		cout << "Invalid mode, must be 0 for gray scale, 1 for color." << endl;
		waitKey();
		return 0;
	}
	
}

// Displays gray scale histogram equalization results
void grayHistEq()
{
	Mat src, image, hist;
	int histSize = 255;
	long int dim;
	Mat histSrc; // My code


	// Read original image
	src = imread( "sequim.jpg");	// Originally imread("fruits.jpg");
	if(src.data == NULL)
	{
		cout << "imread(sequim) failed" << endl;

	}

	
	

	/// Convert to grayscale
	cvtColor( src, src, COLOR_BGR2GRAY );

	// Apply Histogram Equalization
	equalizeHist( src, image );

	// Display results
	namedWindow("Source image", 0 );
	namedWindow("Equalized Image", 0 );

	imshow( "Source image", src );
	imshow( "Equalized Image", image );

	// Calculate Histogram of the Equalized Image and display
	calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, 0);
	dim=image.rows *image.cols;
	Mat histImage = Mat::ones(255, 255, CV_8U)*255;
	
	// 
	// Showing original histogram
	calcHist(&src, 1, 0, Mat(), histSrc, 1, &histSize, 0);
	Mat histImageSrc = Mat::ones(255, 255, CV_8U)*255;
	normalize(histSrc, histSrc, 0, histImage.rows, NORM_MINMAX, CV_32F);
	histImageSrc = Scalar::all(255);
  	int binW = cvRound((double)histImageSrc.cols/histSize);

	
  	for( int i = 0; i < histSize; i++ )
	{
		rectangle( histImageSrc, Point(i*binW, histImageSrc.rows),
                 Point((i+1)*binW, histImageSrc.rows - cvRound(histSrc.at<float>(i))),
                 Scalar::all(0), -1, 8, 0 );
	}
	
      
  	namedWindow("Histogram Source Image", WINDOW_AUTOSIZE);
  	imshow("Histogram Source Image", histImageSrc);
	
	// 

  	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, CV_32F); // Originally (... histImage.rows, CV_MINMAX, CV_32F);

  	histImage = Scalar::all(255);
  	//int binW = cvRound((double)histImage.cols/histSize); // Already declared above

	// Creating the histogram graph
	// ***
	createHistGraph(hist, histImage, histSize, binW);
	
  	//for( int i = 0; i < histSize; i++ )
    //  rectangle( histImage, Point(i*binW, histImage.rows),
   //              Point((i+1)*binW, histImage.rows - cvRound(hist.at<float>(i))),
     //            Scalar::all(0), -1, 8, 0 );
  	namedWindow("Histogram Equalized Image", WINDOW_AUTOSIZE);
  	imshow("Histogram Equalized Image", histImage);

  	// Wait until user exits the program
  	waitKey();
}

// Displays color image histogram equalization results
void colorHistEq()
{
	Mat img, result, ycrcb;
	int histSize = 255;
	long int dim;
	
	// Read original image
	img = imread( "sequim.jpg");	// Originally imread("fruits.jpg");
	cvtColor(img, ycrcb, COLOR_BGR2YCrCb);
	
	// Showing original image
	namedWindow("Original Image", 0);
	imshow("Original Image", img);
	
	// Split into channels.
	vector<Mat> channels;
	split(ycrcb, channels);
	
	// Equalize y channel only
	equalizeHist(channels[0], channels[0]);
	
	// Merge result channels
	merge(channels, ycrcb);
	
	// Convert back to BGR
	cvtColor(ycrcb, result, COLOR_YCrCb2BGR);
	
	// Show image
	namedWindow("Color Equalized Image", 0 );
	imshow("Color Equalized Image", result);
	
	
}

// Takes source image and helps create histogram graph
void createHistGraph(Mat histSrc, Mat &histResult, int histSize, int binW)
{
	cout << "Calling createHistGraph() !!!!!!!!!!!!!!!!!" << endl;
	for( int i = 0; i < histSize; i++ )
	{
		rectangle( histResult, Point(i*binW, histResult.rows),
                 Point((i+1)*binW, histResult.rows - cvRound(histSrc.at<float>(i))),
                 Scalar::all(0), -1, 8, 0 );
	}
}



