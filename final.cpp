#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{

Mat image;
image= imread("samir7.jpg",CV_LOAD_IMAGE_COLOR);
if(! image.data)
{
  cout<< "Could not open image" << std::endl;
  return -1;
}


Mat gray_image;
cvtColor(image, gray_image, CV_BGR2GRAY);

Rect myROI(146,576,657,520);
Mat croppedImage=gray_image(myROI);


Mat dst; Mat dst1; Mat img_bw;
Ptr<CLAHE> clahe=createCLAHE();
clahe->setClipLimit(2.0);
clahe->setTilesGridSize(Size(8,8));
clahe->apply(croppedImage,dst);
clahe->apply(dst,dst1);

threshold(dst1,img_bw,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);


Mat med;
medianBlur(img_bw,med,3);


int i;
for(i=1;i<21;i++)
{
  medianBlur(med,med,3);
}

int cols;
int col; int row;
col=med.cols;
row=med.rows;
cout << "rows and columns " << row<<" "<< col<<endl;
cols=col/2;
int rows=row/2;
//cout << "rows and columns " << col<<" "<< row<<endl;
//Scalar intensity = med.at<uchar>(col,row);
//Scalar intensity1 = med.at<uchar>(col-5,row-5);
//Scalar intensity2 = med.at<uchar>(col-20,row-20);


//cout << "display co-ordiantes of 0"<< intensity[0]<< endl;
//cout << "display co-ordiantes of 1"<< intensity1[0]<< endl;
//cout << "display co-ordiantes of 2"<< intensity2[0]<< endl;

Scalar intensity; Scalar preintensity;
int count,strtpx,max,endpx,len, max_st,max_ed;
max_st=0; max_ed=0;
max=0; strtpx=0; endpx=0; count=0;
preintensity = med.at<uchar>(0,row);
for(i=0;i<row;i++)
{
  intensity = med.at<uchar>(i,cols);
 if(intensity[0]==0)
 {
   count=count+1;
   if((i>2) && (preintensity[0]!=0))
   {
	strtpx=i;
        cout<<"strtpx"<<strtpx<<endl;
   }
 }
 else
 {
   count=0;
  if(i>2 && (preintensity[0]==0))
  {
	endpx=i;
	len=endpx-strtpx+1;
	cout << "length " << len << endl;
	if(len>max && strtpx<endpx && len>30 && len<170)
	{
		max=len;
		cout<< "if length" << len <<endl;
		max_st=strtpx;
		max_ed=endpx;
	//	cout<< "here"<<endl;
	}
  } 
 }
  preintensity=intensity;
}

cout<<"start index= "<< max_st<<endl;
cout<<"end index= "<< max_ed<<endl;

ofstream myfile;
myfile.open("example.txt");
myfile<< max_st;
myfile.close();
ofstream myfile1;
myfile1.open("example1.txt");
myfile1<< max_ed;
myfile1.close();


imwrite("/home/pi/cropped.jpg",croppedImage);
imwrite("/home/pi/gray.jpg", gray_image);
imwrite("/home/pi/clahe1.jpg", dst);
imwrite("/home/pi/clahe2.jpg", dst1);
imwrite("/home/pi/median.jpg", med);



waitKey(0);
return 0;

}