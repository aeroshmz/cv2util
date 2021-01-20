/*
 *  OpenCV ver2以降を用いたユーティリティ
 *    coded by shimi
 *    ver. 20210118
 */
#define _CRT_SECURE_NO_WARNINGS	
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
#include "cv2util.h"


/*******************
 * Mat を作成する
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 *******************/
cv::Mat
CreateMat( int row, int col, int type )
{
	cv::Mat data;
	switch( type ){
		case CV_8U:
			data=cv::Mat_<char>( row, col );
			break;
		case CV_16S:
			data=cv::Mat_<int>( row, col );
			break;
		case CV_32F:
			data=cv::Mat_<float>( row, col );
			break;
		case CV_64F:
			data=cv::Mat_<double>( row, col );
			break;
		default:
			data=cv::Mat_<double>( row, col );
			break;
	}

	return data;
}

/*************************
 * Mat のtypeを文字列にする
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 *************************/
int
MatType(cv::Mat &mat,
	    char *type) //CV_XXが入る
{
	//CV_8U - 8-ビット符号なし整数 ( 0..255 )
	//CV_8S - 8-ビット符号あり整数 ( -128..127 )
	//CV_16U - 16-ビット符号なし整数 ( 0..65535 )
	//CV_16S - 16-ビット符号あり整数 ( -32768..32767 )
	//CV_32S - 32-ビット符号あり整数 ( -2147483648..2147483647 )
	//CV_32F - 32-ビット浮動小数点数 ( -FLT_MAX..FLT_MAX, INF, NAN )
	//CV_64F - 64-ビット浮動小数点数 ( -DBL_MAX..DBL_MAX, INF, NAN )

	switch( mat.type() ){
		case CV_8U:
			sprintf(type,"CV_8U");
			break;
		case CV_8S:
			sprintf(type,"CV_8S");
			break;
		case CV_16U:
			sprintf(type,"CV_16U");
			break;
		case CV_16S:
			sprintf(type,"CV_16S");
			break;
		case CV_32S:
			sprintf(type,"CV_32S");
			break;
		case CV_32F:
			sprintf(type,"CV_32F");
			break;
		case CV_64F:
			sprintf(type,"CV_64F");
			break;
		default:
			printf("type error\n");
			return 0;
	}

	return 1;
}
/**********************
 * Mat のtypeを表示する
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 **********************/
int
PrintMatType(cv::Mat &mat)
{
	char type[10];
	MatType(mat,
			type);//CV_XXが入る

	printf("type = %s\n",type );
	return 1;
}

/*******************
 *  行列を表示する
 *    OpenCV 2.X
 *******************/
int
PrintMat( cv::Mat &mat , 
		  const char *format) //書式
{
	for(int j=0;j<mat.rows;j++){
		for(int i=0;i<mat.cols;i++){
			switch( mat.type() ){
				case CV_8U:
					printf(format, mat.ptr<unsigned char>(j)[i]);
					break;
				case CV_8S:
					printf(format, mat.ptr<char>(j)[i]);
					break;
				case CV_16U:
					printf(format, mat.ptr<unsigned short>(j)[i]);
					break;
				case CV_16S:
					printf(format, mat.ptr<short>(j)[i]);
					break;
				case CV_32S:
					printf(format, mat.ptr<int>(j)[i]);
					break;
				case CV_32F:
					printf(format, mat.ptr<float>(j)[i]);
					break;
				case CV_64F:
					printf(format, mat.ptr<double>(j)[i]);
					break;
				default:
					printf(format, mat.ptr<unsigned char>(j)[i]);
					break;
			}
		}
		printf("\n");
	}
	return 1;
}

int
PrintMat( cv::Mat &mat, 
		  const char *title, 
		  const char *format)
{
	printf("%s\n",title);
	PrintMat(mat, format);

	return 1;
}

int
MatIs( cv::Mat &mat, 
	   const char *title)
{
	printf("%s\n",title);
	std::cout << mat << std::endl;
	std::cout << "----------\n";

	return 1;
}

/*****************
 * 変数を読み込む
 *  OpenCV 2.X
 *****************/
int
LoadParam(char *filename, char *tag, double *data)
{
	if (fopen(filename, "r") == NULL) {
		printf("File Not Found (%s).\n",filename);
		return 0;
	}
	// (1)open file storage
	//cv::FileStorage cvfs(filename,CV_STORAGE_READ);
	cv::FileStorage cvfs(filename, cv::FileStorage::READ);

	// (2)read data from file storage
	//cv::FileNode node(cvfs.fs, NULL); // Get Top Node
	cv::FileNode node=cvfs.getFirstTopLevelNode();

	*data = node[std::string(tag)];

	return 1;

}
/*****************
 * RECTを読み込む
 * OpenCV 2.X
 *****************/
int
LoadRect(char *filename, cv::Rect &roi)
{
	cv::FileStorage fs( std::string(filename), cv::FileStorage::READ);
	if (!fs.isOpened()){
		std::cout << "File can not be opened." << std::endl;
		return 0;
	}

	fs["x"]>>roi.x;
	fs["y"]>>roi.y;
	fs["width"]>>roi.width;
	fs["height"]>>roi.height;

	 fs.release();

	return 1;
}

/*****************
 * 行列を読み込む
 *  OpenCV 2.X
 *****************/
int
LoadMatrix(	char *filename ,//ファイル名
			cv::Mat &matdata,	//読み込む行列
			char *tag)		//読み込む行列のタグ
{

	if( fopen(filename,"r") == NULL ){
		printf("File Not Found %s\n",filename);
		return 0;
	}

	// open file storage
	//cv::FileStorage cvfs(filename,CV_STORAGE_READ);
	cv::FileStorage cvfs(filename, cv::FileStorage::READ);
 
	// read data from file storage
	//cv::FileNode node(cvfs.fs, NULL); // Get Top Node
	cv::FileNode node=cvfs.getFirstTopLevelNode();

	cv::FileNode fn = node[ std::string(tag) ];
	
	read( fn, matdata );


	return 1;
}

cv::Mat 
LoadMatrix(	char *filename ,//ファイル名
			char *tag)		//読み込む行列のタグ
{
	cv::Mat matdata;
	cv::FileStorage cvfs(filename, cv::FileStorage::READ);
    if (!cvfs.isOpened()){
		printf("File can not be opened in cv::LoadMatrix().(%s)\n",filename);
        return matdata;
    }
	
	cvfs[tag]>>matdata;

	if (matdata.rows == 0 || matdata.cols == 0) {
		printf("Tag \"%s\" is not found in %s.\n",tag, filename);
		return matdata;
	}

	return matdata;
}

/*
 *  ある点mが画像の範囲内かどうか判定
 *   0<=x<w and 0<=y<h --> return 1
 *                         else   0
 */
int
isInMat(cv::Mat &mat, int u, int v)
{
	if ( (0<= u && u<mat.cols) &&
		 (0<= v && v<mat.rows) ) return 1;
	else return 0;
}
int
isInMat(cv::Mat &mat, cv::Point m)
{
	return isInMat(mat, m.x, m.y);
}

/*******************************
*  cv::Matのデータ取得
*  遅いので速度の必要ない時に利用
*  Matのタイプ CV_XXF
*    戻り値：double
********************************/
double
mGet(cv::Mat &mat, int row, int col)
{
	switch( mat.type() ){
	case CV_8U:
		return mat.ptr<unsigned char>(row)[col];
		break;
	case CV_8S:
		return mat.ptr<char>(row)[col];
		break;
	case CV_16U:
		return mat.ptr<unsigned short>(row)[col];
		break;
	case CV_16S:
		return mat.ptr<short>(row)[col];
		break;
	case CV_32S:
		return mat.ptr<int>(row)[col];
		break;
	case CV_32F:
		return mat.ptr<float>(row)[col];
		break;
	case CV_64F:
		return mat.ptr<double>(row)[col];
		break;
	default:
		printf("type error\n");
		return 0;
	}

}

int
CheckFileExist(char filename[])
{
	FILE *fp;

	fp = fopen(filename, "r");

	if (fp != NULL) {
		fclose(fp);
		return 1;
	}else return 0;
}

//表示用関数
int
DisplayImage(const char wname[], //Windowの名前
			 cv::Mat &img,		 //表示する画像
			 int x, int y,		 //座標
			 double mag)		 //表示倍率
{
	cv::Mat dispImg;

	cv::namedWindow(wname);
	cv::moveWindow(wname, x, y);

	cv::resize(img, dispImg, cv::Size(), mag, mag);
	cv::imshow(wname,dispImg);
	
	return 1;
}

//カラー画像からある面を抽出する．
int
ExtractColorPlane(cv::Mat &src,  //元画像(カラー) 
				  cv::Mat &dist, //ある画像面を抽出した結果
				  char type)     // type='R', 'G', 'B', 'A'
{
	int plane;

	std::vector<cv::Mat> planes;
	cv::split(src, planes);
	
	switch (type) {
		case 'B':
			plane=0;
			break;
		case 'G':
			plane=1;
			break;
		case 'A':
			if( src.channels() != 4){
				std::cout<<"plane must be 4. in ExtractColorPlane()\n";
				return 0;
			}
			plane=3;
			break;
		default://R
			plane=2;
			break;
	}
	dist = planes[plane].clone();

	return 1;

}int
ExtractColorPlane(cv::Mat &src,  //元画像(カラー) 
	cv::Mat &dist, //ある画像面を抽出した結果
	cv::Mat &mask, //マスク画像
	char type)     // type='R', 'G', 'B', 'A'
{
	int plane;

	std::vector<cv::Mat> planes;
	cv::split(src, planes);

	switch (type) {
	case 'B':
		plane = 0;
		break;
	case 'G':
		plane = 1;
		break;
	case 'A':
		plane = 3;
		break;
	default://R
		plane = 2;
		break;
	}
	planes[plane].copyTo(dist,mask!=0);
	return 1;

}

//画素アクセス関数
//u,vのポインタ取得
uchar 
*PixelValue( cv::Mat &img, // CV_8UC3  color plane 3
			 int v,
			 int u )
{
	cv::Vec3b *bgr= img.ptr<cv::Vec3b>(v)+u;

	return (uchar *)bgr;
}
