/*
 *  OpenCV ver2以降を用いたユーティリティ
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
 * Mat を作成する
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 *******************/
cv::Mat
CreateMat( int row, int col, int type );

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
	    char *type); //CV_XXが入る

/**********************
 * Mat のtypeを表示する
 * type = CV_8U or
 *        CV_16S or
 *        CV_32F or
 *        CV_64F
 *   OpenCV 2.x 
 **********************/
int
PrintMatType(cv::Mat &mat);

/*******************
 *  行列を表示する
 *    OpenCV 2.X
 *******************/
int
PrintMat( cv::Mat &mat , 
		  const char *format); //書式

int
PrintMat( cv::Mat &mat, 
		  const char *title, 
		  const char *format);
int
MatIs( cv::Mat &mat, 
	   const char *title);

/*****************
 * 変数を読み込む
 *  OpenCV 2.X
 *****************/
int
LoadParam(char *filename, char *tag, double *data);

/*****************
 * RECTを読み込む
 * OpenCV 2.X
 *****************/
int
LoadRect(char *filename, cv::Rect &roi);

/*****************
 * 行列を読み込む
 *  OpenCV 2.X
 *****************/
int
LoadMatrix(	char *filename ,//ファイル名
			cv::Mat &matdata,	//読み込む行列
			char *tag);		//読み込む行列のタグ

cv::Mat 
LoadMatrix(	char *filename ,//ファイル名
			char *tag);		//読み込む行列のタグ

/*
 *  ある点mが画像の範囲内かどうか判定
 *   0<=x<w and 0<=y<h --> return 1
 *                         else   0
 */
int
isInMat(cv::Mat &mat, int u, int v);
int
isInMat(cv::Mat &mat, cv::Point m);

/*******************************
*  cv::Matのデータ取得
*  遅いので速度の必要ない時に利用
*  Matのタイプ CV_XXF
*    戻り値：double
********************************/
double
mGet(cv::Mat &mat, int row, int col);


int
CheckFileExist(char filename[]);

//表示用関数
int
DisplayImage(const char wname[], //Windowの名前
			 cv::Mat &img,		 //表示する画像
			 int x, int y,		 //座標
			 double mag=1.0);		 //表示倍率

//カラー画像からある面を抽出する．
int
ExtractColorPlane(
	cv::Mat &src,  //元画像(カラー) 
	cv::Mat &dist, //ある画像面を抽出した結果
	char type);    // type='R', 'G', 'B', 'A'
int
ExtractColorPlane(
	cv::Mat &src,  //元画像(カラー) 
	cv::Mat &dist, //ある画像面を抽出した結果
	cv::Mat &mask, //マスク画像
	char type);    // type='R', 'G', 'B', 'A'

//画素アクセス関数
//u,vのポインタ取得
uchar 
*PixelValue( cv::Mat &img, // CV_8UC3  color plane 3
			 int v,
			 int u );

//CV_16UデータをCV_8UC3で保持するためのエンコーダー
//CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	unsigned short val_16u, 
	unsigned char *b, unsigned char *g, unsigned char *r);

//CV_8UC3で保持したCV_16Uデータを戻すためのデーコーダー
//CV_8UC3(BGR)-->CV_16U
unsigned short
Decode16UTo8UC3(
	unsigned char b, 
	unsigned char g, 
	unsigned char r);

//CV_16UデータをCV_8UC3で保持するためのエンコーダー
//cv::Mat CV_16U-->CV_8UC3(BGR)
void
Encode16UTo8UC3(
	cv::Mat &mat16u,
	cv::Mat &mat8uc3);

//CV_8UC3で保持したCV_16Uデータを戻すためのデーコーダー
//cv::Mat CV_8UC3(BGR)-->CV_16U
void
Decode8UC3To16U(
	cv::Mat &mat8uc3,
	cv::Mat &mat16u);


