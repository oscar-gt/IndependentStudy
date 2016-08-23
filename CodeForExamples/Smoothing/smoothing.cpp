#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <opencv2/opencv.hpp>
#include <stdio.h>

#include <iostream>
using namespace std;
using namespace cv;

// Oscar Garcia-Telles
// Code illustrates the application of 
// box and Gaussian filters. Besides
// referring to my texts and online
// OpenCV resources for function documentation,
// this is my own code. 

// Box filtering
void boxFilterExample();
// Gaussian filter
void gaussianFilterExample();

int main( int argc, char** argv )
{
	int mode = 1;
	if(mode == 0)
	{
		cout << "Box filter method used" << endl;
		boxFilterExample();
		//waitKey();

		
	}
	if(mode == 1)
	{
		cout << "Gaussian filter used" << endl;
		gaussianFilterExample();
		
	}
	else
	{
		cout << "Invalid mode. Set to 0 or 1." << endl;
	}
	
	return 0;
}

void boxFilterExample()
{
	
	namedWindow( "Original Image" , 0);

	// Loading image
	Mat src = imread( "truck.jpg");

	//show the loaded image
	imshow( "Original Image", src );
	
	// Resultant image
	Mat dst;

	
	namedWindow( "Kernel size 3 x 3" , 0 );
	namedWindow( "Kernel size 11 x 11" , 0 );
	namedWindow( "Kernel size 30 x 30" , 0 );
	
	// Different kernel sizes
	blur( src, dst, Size( 3, 3 ) );
	imshow( "Kernel size 3 x 3", dst );
	
	blur( src, dst, Size( 11, 11 ) );
	imshow( "Kernel size 11 x 11", dst );
	
	blur( src, dst, Size( 30, 30 ) );
	imshow( "Kernel size 30 x 30", dst );


	//wait for a key press infinitely
	cout << "at end" << endl;
	waitKey(0);



}

// Function illustrates the effects
// of applying a Gaussian blurr. 
void gaussianFilterExample()
{
	Mat src = imread( "east2.JPG");
	if(src.data == NULL)
	{
		cout << "loading thenos.jpg failed" << endl;
	}
	// Create a destination Mat object
	Mat dst;
	
	namedWindow("Before" , 0);


	// Load the source image
	
	
	// display the source image
	imshow("Before", src);
	cout << "after imshow(src)" << endl;
	namedWindow( "Kernel size 3 x 3" , 0 );
	namedWindow( "Kernel size 17 x 17" , 0 );
	//namedWindow( "Kernel size 30 x 30" , 0 );
	
	// Different kernel sizes
	GaussianBlur( src, dst, Size( 3, 3 ), 2, 2 );
	imshow( "Kernel size 3 x 3", dst );
	
	GaussianBlur( src, dst, Size( 17, 17 ), 5, 5 );
	imshow( "Kernel size 17 x 17", dst );
	
	//GaussianBlur( src, dst, Size( 30, 30 ), 0, 0 );
	//imshow( "Kernel size 30 x 30", dst );
	
	waitKey(0);
	
	

}

	
	
	
