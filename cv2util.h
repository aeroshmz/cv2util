/*
 *  OpenCV ver2�ȍ~��p�������[�e�B���e�B
 *    coded by shimi
 *    ver. 20210118
 */
union _data_pointer{
	unsigned char *p8u;
	char *p8s;
	unsigned short *p16u;
	short *p16s;
	int *p32s;
	float *p32f;
	double *p64f;
};

/*******************
 * Mat ���쐬����
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 *******************/
cv::Mat
CreateMat( int row, int col, int type );

/*************************
 * Mat ��type�𕶎���ɂ���
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 *************************/
int
MatType(cv::Mat &mat,
	    char *type); //CV_XX������

/**********************
 * Mat ��type��\������
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 **********************/
int
PrintMatType(cv::Mat &mat);

/*******************
 *  �s���\������
 *    OpenCV 2.X
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
 *  OpenCV 2.X
 *****************/
int
LoadParam(char *filename, char *tag, double *data);

/*****************
 * RECT��ǂݍ���
 * OpenCV 2.X
 *****************/
int
LoadRect(char *filename, cv::Rect &roi);

/*****************
 * �s���ǂݍ���
 *  OpenCV 2.X
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


