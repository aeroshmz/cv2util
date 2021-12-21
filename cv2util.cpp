/*
 *  OpenCV ver2�ȍ~��p�������[�e�B���e�B
 *    coded by shimi
 *    ver. 20211119
 */
#define _CRT_SECURE_NO_WARNINGS	
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
#include <ppl.h>
#include "cv2util.h"


/*************************
 * Mat ��type�𕶎���ɂ���
 * type = CV_8U or
 *        CV_16U or
 *        CV_16S or
 *        CV_32S or
 *        CV_32F or
 *        CV_32FC2 or
 *        CV_32FC3 or
 *        CV_64F or
 *        CV_64FC2 or
 *        CV_64FC3
 *************************/
int
MatType(cv::Mat &mat,
	    char *type) //CV_XX������
{
	//CV_8U - 8-�r�b�g�����Ȃ����� ( 0..255 )
	//CV_8S - 8-�r�b�g�������萮�� ( -128..127 )
	//CV_16U - 16-�r�b�g�����Ȃ����� ( 0..65535 )
	//CV_16S - 16-�r�b�g�������萮�� ( -32768..32767 )
	//CV_32S - 32-�r�b�g�������萮�� ( -2147483648..2147483647 )
	//CV_32F - 32-�r�b�g���������_�� ( -FLT_MAX..FLT_MAX, INF, NAN )
	//CV_64F - 64-�r�b�g���������_�� ( -DBL_MAX..DBL_MAX, INF, NAN )

	switch( mat.type() ){
		case CV_8U:
			sprintf(type,"CV_8U");
			break;
		case CV_8UC2:
			sprintf(type,"CV_8UC3");
			break;
		case CV_8UC3:
			sprintf(type,"CV_8UC3");
			break;
		case CV_8UC4:
			sprintf(type,"CV_8UC4");
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
		case CV_32FC2:
			sprintf(type,"CV_32FC2");
			break;
		case CV_32FC3:
			sprintf(type,"CV_32FC3");
			break;
		case CV_64F:
			sprintf(type,"CV_64F");
			break;
		case CV_64FC2:
			sprintf(type,"CV_64FC2");
			break;
		case CV_64FC3:
			sprintf(type,"CV_64FC3");
			break;
		default:
			printf("type error\n");
			return 0;
	}

	return 1;
}
/**********************
 * Mat ��type��\������
 * type = CV_8U or
 *        CV_16U or
 *        CV_16S or
 *        CV_32S or
 *        CV_32F or
 *        CV_32FC2 or
 *        CV_32FC3 or
 *        CV_64F or
 *        CV_64FC2 or
 *        CV_64FC3
 **********************/
int
PrintMatType(cv::Mat &mat)
{
	char type[10];
	MatType(mat,
			type);//CV_XX������

	printf("type = %s\n",type );
	return 1;
}

/*******************
 *  �s���\������
 *******************/
int
PrintMat( cv::Mat &mat , 
		  const char *format) //����
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
 * �ϐ���ǂݍ���
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
 * RECT��ǂݍ���
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
 * �s���ǂݍ���
 *****************/
int
LoadMatrix(	char *filename ,//�t�@�C����
			cv::Mat &matdata,	//�ǂݍ��ލs��
			char *tag)		//�ǂݍ��ލs��̃^�O
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
LoadMatrix(	char *filename ,//�t�@�C����
			char *tag)		//�ǂݍ��ލs��̃^�O
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

cv::Mat 
LoadMatrix(	char *filename ,//�t�@�C����
			char *tag,		//�ǂݍ��ލs��̃^�O
			int  type)		//CV_32F, CV_64F
{
	cv::Mat tmp;
	cv::Mat matdata;
	cv::FileStorage cvfs(filename, cv::FileStorage::READ);
    if (!cvfs.isOpened()){
		printf("File can not be opened in cv::LoadMatrix().(%s)\n",filename);
        return tmp;
    }
	
	cvfs[tag]>>tmp;

	if (tmp.rows == 0 || tmp.cols == 0) {
		printf("Tag \"%s\" is not found in %s.\n",tag, filename);
		return tmp;
	}

	switch( type ){
	case CV_32F:
		tmp.convertTo(matdata, CV_32F, 1.0 );
		break;
	case CV_64F:
		tmp.convertTo(matdata, CV_64F, 1.0 );
		break;
	default:
		tmp.convertTo(matdata, CV_32F, 1.0 );
	}
	
	
	return matdata;
}



/*
 *  ����_m���摜�͈͓̔����ǂ�������
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
*  cv::Mat�̃f�[�^�擾
*  �x���̂ő��x�̕K�v�Ȃ����ɗ��p
*  Mat�̃^�C�v CV_XXF
*    �߂�l�Fdouble
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

//�\���p�֐�
int
DisplayImage(const char wname[], //Window�̖��O
			 cv::Mat &img,		 //�\������摜
			 int x, int y,		 //���W
			 double mag)		 //�\���{��
{
	cv::Mat dispImg;

	cv::namedWindow(wname);
	cv::moveWindow(wname, x, y);

	cv::resize(img, dispImg, cv::Size(), mag, mag);
	cv::imshow(wname,dispImg);
	
	return 1;
}

//�J���[�摜���炠��ʂ𒊏o����D
int
ExtractColorPlane(cv::Mat &src,  //���摜(�J���[) 
				  cv::Mat &dist, //����摜�ʂ𒊏o��������
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
}

//�J���[�摜����̒��o
int
ExtractColorPlane(cv::Mat &src,  //���摜(�J���[) 
	cv::Mat &dist, //����摜�ʂ𒊏o��������
	cv::Mat &mask, //�}�X�N�摜
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

//��f�A�N�Z�X�֐�
//u,v�̃|�C���^�擾
uchar 
*PixelValue( cv::Mat &img, // CV_8UC3  color plane 3
			 int v,
			 int u )
{
	cv::Vec3b *bgr= img.ptr<cv::Vec3b>(v)+u;

	return (uchar *)bgr;
}

//CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3( 
	unsigned short val_16u, 
	unsigned char *b, unsigned char *g, unsigned char *r)
{
	*g=val_16u>>8;
	*r=val_16u&(0x00FF);
}

//CV_8UC3�ŕێ�����CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//CV_8UC3(BGR)-->CV_16U
unsigned short
Decode16UTo8UC3(  unsigned char b, unsigned char g, unsigned char r)
{
	unsigned short val_16u = ( g<<8 ) |  r ;
	return val_16u;
}

//CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//cv::Mat CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	cv::Mat &mat16u,
	cv::Mat &mat8uc3)
{
	ushort val_16u;
	uchar val_b=0, val_r=0, val_g=0;
	

	// ����NG
	//printf("mat16u.rows=%d\n", mat16u.rows );
	/*
	Concurrency::parallel_for( 0, mat16u.rows, [&]( int v ){
		for( int u = 0; u < mat16u.cols; u++ ){
			cv::Vec3b *pix = mat8uc3.ptr<cv::Vec3b>(v);
			//unsigned short *pshort=mat16u.ptr<unsigned short>(v);
			val_16u=mat16u.ptr<unsigned short>(v)[u];
			val_g=(uchar)(val_16u>>8);
			val_r=(uchar)(val_16u&0xFF);
			pix[u]=cv::Vec3b(val_b, val_g, val_r );

			//printf(" %d %d  %d(%x)--> %x %x %x\n", u, v, val_16u, val_16u,
			//	pix[u][0], pix[u][1], pix[u][2] );
				//mat8uc3.ptr<unsigned char>(0)[colorIndex  ],
				//mat8uc3.ptr<unsigned char>(0)[colorIndex+1],
				//mat8uc3.ptr<unsigned char>(0)[colorIndex+2] );
		}
    } );
    */


    // �ȉ����񉻂��Ȃ��o�[�W����  ����OK
    for( int v = 0; v < mat16u.rows; v++ ){
		cv::Vec3b *pix = mat8uc3.ptr<cv::Vec3b>(v);
		ushort *us16 = mat16u.ptr<unsigned short>(v);
		for( int u = 0; u < mat16u.cols; u++ ){
			val_16u= us16[u];
			val_g=val_16u>>8;
			val_r=val_16u&0xFF;
			
			//pix[u]=cv::Vec3b(val_b, val_g, val_r );  �x
			pix[u][0]=0;
			pix[u][1]=val_g;
			pix[u][2]=val_r;
		}
	}

}


//CV_8U, CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//cv::Mat CV_8U , CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	cv::Mat &mat16u,
	cv::Mat &mat8u,
	cv::Mat &mat8uc3)
{
	ushort val_16u;
	uchar val_b=0, val_r=0, val_g=0;
	
    // �ȉ����񉻂��Ȃ��o�[�W����  ����OK
    for( int v = 0; v < mat16u.rows; v++ ){
		cv::Vec3b *pix = mat8uc3.ptr<cv::Vec3b>(v);
		ushort *us16 = mat16u.ptr<unsigned short>(v);
		uchar  *uc8  = mat8u.ptr< unsigned char >(v);
		for( int u = 0; u < mat16u.cols; u++ ){
			val_16u= us16[u];
			val_g=val_16u>>8;
			val_r=val_16u&0xFF;
			//pix[u]=cv::Vec3b(val_b, val_g, val_r );  �x
			pix[u][0]=uc8[u];
			pix[u][1]=val_g;
			pix[u][2]=val_r;
		}
	}

}


//CV_8UC3�ŕێ�����CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//cv::Mat CV_8UC3(BGR)-->CV_16U
void
Decode8UC3To16U(
	cv::Mat &mat8uc3,
	cv::Mat &mat16u)
{
	ushort val_16u;
	uchar val_r, val_g;
	
    
    for( int v = 0; v < mat16u.rows; v++ ){
        cv::Vec3b *pix = mat8uc3.ptr<cv::Vec3b>(v);
		for( int u = 0; u < mat16u.cols; u++ ){
			cv::Vec3b bgr=pix[u];
			val_g=bgr[1];
			val_r=bgr[2];

            val_16u = ( val_g<<8 ) |  val_r ;
            mat16u.ptr<unsigned short>(v)[u]=val_16u;
		}
	}


}

//CV_8UC3�ŕێ�����CV_8U+CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//cv::Mat CV_8UC3(BGR)-->CV_16U
void
Decode8UC3To16U(
	cv::Mat &mat8uc3,
	cv::Mat &mat16u,
	cv::Mat &mat8u)
{
	ushort val_16u;
	uchar val_b, val_r, val_g;
	
    
    for( int v = 0; v < mat16u.rows; v++ ){
        cv::Vec3b *pix = mat8uc3.ptr<cv::Vec3b>(v);
		for( int u = 0; u < mat16u.cols; u++ ){
			cv::Vec3b bgr=pix[u];
			val_b=bgr[0];
			val_g=bgr[1];
			val_r=bgr[2];

            val_16u = ( val_g<<8 ) |  val_r ;
            mat16u.ptr<unsigned short>(v)[u]=val_16u;
            mat8u.ptr<unsigned char>(v)[u]=val_b;
		}
	}


}
