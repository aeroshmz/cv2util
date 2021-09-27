#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>


#include "cv2util.h"


void
Sample1(void)
{
	unsigned short dat16u=0x01F2;
	unsigned char b=0, g, r;
	
	
	Encode16UTo8UC3(dat16u, &b, &g, &r);
	printf(" %d(0x%X) --> %d(0x%X) , %d(0x%X) , %d(0x%X) \n", dat16u, dat16u, 
		b, b,
		g, g,
		r, r );
	
	printf(" %d(0x%X) , %d(0x%X) , %d(0x%X) --> %d(0x%X) \n", 
		b, b,
		g, g,
		r, r,
		Decode16UTo8UC3( b, g, r), Decode16UTo8UC3( b, g, r)  );
}


int
main(int argc, char *argv[])
{
	
	
	
	cv::Mat mat16u=cv::imread("depth_sample.tiff", -1);
	cv::Mat mat8uc3=cv::Mat(mat16u.rows, mat16u.cols, CV_8UC3);
	
	//printf("depth_sample.tiff  ");
	//PrintMatType(mat16u);
	
	//cv::FileStorage   cvfs("depth_sample.0.xml", cv::FileStorage::WRITE);
	//cv::write(cvfs, "depth", mat16u);
	
	
	cv::Mat mat16ud=10*mat16u;
	//DisplayImage("16u", mat16ud, 0, 0, 0.25 );
	//cv::waitKey(0);
	

	cv::TickMeter meter;


	//
	meter.reset();
	meter.start();

	for( int i=0; i<20; i++ )
		Encode16UTo8UC3( mat16u, mat8uc3);
	//mat8uc3=Encode16UTo8UC3( mat16u );

	meter.stop();
	std::cout << meter.getTimeMilli()/20 << "ms" << std::endl;
	//


	meter.reset();
	//
	meter.start();

	Decode8UC3To16U( mat8uc3 , mat16ud );

	meter.stop();
	std::cout << meter.getTimeMilli() << "ms" << std::endl;
	//


	cv::Mat mat16diff = abs(mat16u - mat16ud);
	mat16diff.setTo(0xFFFF, mat16diff > 0 );
	
	
	
	
	
	//cv::Mat mat8uc3d=10*mat8uc3;
	//DisplayImage("8uc3", mat8uc3d, 0, 0, 0.25 );
	//cv::waitKey(0);

	
	
	DisplayImage("16diff", mat16diff, 0, 0, 0.25 );
	cv::waitKey(0);

	
	
	cv::FileStorage   cvfs("out.xml", cv::FileStorage::WRITE);
	//cvfs.open("out.xml", cv::FileStorage::WRITE);
	cv::write(cvfs, "depth", mat16ud);
	
	
	
	
	return 1;
}
