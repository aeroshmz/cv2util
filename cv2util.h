/*
 *  OpenCV ver2�ȍ~��p�������[�e�B���e�B
 *    coded by shimi
 *    ver. 20211119
 */
 


//cv::Mat�Ƀ|�C���^�ŃA�N�Z�X���邽�߂̃}�N��
#define MAT( cvmat, type, v, u )\
		cvmat.ptr<type>(v)[u]



union _data_pointer{
	unsigned char *p8u;
	char *p8s;
	unsigned short *p16u;
	short *p16s;
	int *p32s;
	float *p32f;
	double *p64f;
};

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
	    char *type); //CV_XX������

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
PrintMatType(cv::Mat &mat);

/*******************
 *  �s���\������
 *******************/
int
PrintMat( cv::Mat &mat , 
		  const char *format); //����

int
PrintMat( cv::Mat &mat, 
		  const char *title, 
		  const char *format);
int
MatIs( cv::Mat &mat, 
	   const char *title);

/*****************
 * �ϐ���ǂݍ���
 *****************/
int
LoadParam(char *filename, char *tag, double *data);

/*****************
 * RECT��ǂݍ���
 *****************/
int
LoadRect(char *filename, cv::Rect &roi);

/*****************
 * �s���ǂݍ���
 *****************/
int
LoadMatrix(	char *filename ,//�t�@�C����
			cv::Mat &matdata,	//�ǂݍ��ލs��
			char *tag);		//�ǂݍ��ލs��̃^�O

cv::Mat 
LoadMatrix(	char *filename ,//�t�@�C����
			char *tag);		//�ǂݍ��ލs��̃^�O

/*
 *  ����_m���摜�͈͓̔����ǂ�������
 *   0<=x<w and 0<=y<h --> return 1
 *                         else   0
 */
int
isInMat(cv::Mat &mat, int u, int v);
int
isInMat(cv::Mat &mat, cv::Point m);

/*******************************
*  cv::Mat�̃f�[�^�擾
*  �x���̂ő��x�̕K�v�Ȃ����ɗ��p
*  Mat�̃^�C�v CV_XXF
*    �߂�l�Fdouble
********************************/
double
mGet(cv::Mat &mat, int row, int col);


int
CheckFileExist(char filename[]);

//�\���p�֐�
int
DisplayImage(const char wname[], //Window�̖��O
			 cv::Mat &img,		 //�\������摜
			 int x, int y,		 //���W
			 double mag=1.0);		 //�\���{��

//�J���[�摜���炠��ʂ𒊏o����D
int
ExtractColorPlane(
	cv::Mat &src,  //���摜(�J���[) 
	cv::Mat &dist, //����摜�ʂ𒊏o��������
	char type);    // type='R', 'G', 'B', 'A'
int
ExtractColorPlane(
	cv::Mat &src,  //���摜(�J���[) 
	cv::Mat &dist, //����摜�ʂ𒊏o��������
	cv::Mat &mask, //�}�X�N�摜
	char type);    // type='R', 'G', 'B', 'A'

//��f�A�N�Z�X�֐�
//u,v�̃|�C���^�擾
uchar 
*PixelValue( cv::Mat &img, // CV_8UC3  color plane 3
			 int v,
			 int u );

//CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	unsigned short val_16u, 
	unsigned char *b, unsigned char *g, unsigned char *r);

//CV_8UC3�ŕێ�����CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//CV_8UC3(BGR)-->CV_16U
unsigned short
Decode16UTo8UC3(
	unsigned char b, 
	unsigned char g, 
	unsigned char r);

//CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//cv::Mat CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	cv::Mat &mat16u,
	cv::Mat &mat8uc3);
//CV_8U, CV_16U�f�[�^��CV_8UC3�ŕێ����邽�߂̃G���R�[�_�[
//cv::Mat CV_8U , CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	cv::Mat &mat16u,
	cv::Mat &mat8u,
	cv::Mat &mat8uc3);

//CV_8UC3�ŕێ�����CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//cv::Mat CV_8UC3(BGR)-->CV_16U
void
Decode8UC3To16U(
	cv::Mat &mat8uc3,
	cv::Mat &mat16u);


//CV_8UC3�ŕێ�����CV_8U+CV_16U�f�[�^��߂����߂̃f�[�R�[�_�[
//cv::Mat CV_8UC3(BGR)-->CV_16U
void
Decode8UC3To16U(
	cv::Mat &mat8uc3,
	cv::Mat &mat16u,
	cv::Mat &mat8u);
