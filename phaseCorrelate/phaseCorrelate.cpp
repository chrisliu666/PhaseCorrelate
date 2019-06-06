#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
	Mat src1, src2,src11,src22,src111,src222;
	Mat dst1, dst2,dst11,dst22,dst111,dst222;
	//if( argc != 3 || !(src1=imread(argv[1], 1)).data || !(src2=imread(argv[2], 1)).data)
		//return -1;
 	src1=imread(argv[1],1);
	src2=imread(argv[2],1);
	cvtColor( src1, src1, CV_BGR2GRAY );     //转换为灰度图像
        src1.convertTo(dst1,CV_32FC1);       //转换为32位浮点型
	cvtColor( src2, src2, CV_BGR2GRAY );
        src2.convertTo(dst2,CV_32FC1);
 
	Point2d phase_shiftXY;
        phase_shiftXY = phaseCorrelate(dst1,dst2);//fushi
        cout<<endl<<"warp :"<<endl<<"\tX shift : "<<phase_shiftXY.x<<"\tY shift : "<<phase_shiftXY.y<<endl;


	src11=imread(argv[3],1);
	src22=imread(argv[4],1);
	cvtColor( src11, src11, CV_BGR2GRAY );     //转换为灰度图像
        src11.convertTo(dst11,CV_32FC1);       //转换为32位浮点型
	cvtColor( src22, src22, CV_BGR2GRAY );
        src22.convertTo(dst22,CV_32FC1);



	Point2d phase_shiftXZ;
        phase_shiftXZ = phaseCorrelate(dst11,dst22);//zhengshi
	cout<<endl<<"warp :"<<endl<<"\tX shift : "<<phase_shiftXZ.x<<"\tZ shift : "<<phase_shiftXZ.y<<endl;


	src111=imread(argv[5],1);
	src222=imread(argv[6],1);
	cvtColor( src111, src111, CV_BGR2GRAY );     //转换为灰度图像
        src111.convertTo(dst111,CV_32FC1);       //转换为32位浮点型
	cvtColor( src222, src222, CV_BGR2GRAY );
        src222.convertTo(dst222,CV_32FC1);

	Point2d phase_shiftYZ;
        phase_shiftYZ = phaseCorrelate(dst111,dst222);//ceshi
	cout<<endl<<"warp :"<<endl<<"\tY shift : "<<phase_shiftYZ.x<<"\tZ shift : "<<phase_shiftYZ.y<<endl;
	
	double x,y,z;
	x=(phase_shiftXY.x+phase_shiftXZ.x)/2.0;
	y=(phase_shiftXY.y+phase_shiftYZ.x)/2.0;
	z=(phase_shiftXZ.y+phase_shiftYZ.y)/2.0;
	cout<<x<<endl<<y<<endl<<z<<endl;
        waitKey(0);
 
        return 0;
}
