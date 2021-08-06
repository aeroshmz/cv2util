//cv_lib_ver.h
//20170302

//OpenCVのインストールDIR
#ifndef LIB_DIR
#define LIB_DIR	"D:\\UserLocal\\Tools\\OpenCV\\lib\\"
#endif


//OpenCVのバージョン
#ifndef _CV_VER
#define _CV_VER "450"
#endif



#ifdef _CVBLOB
#ifdef _DEBUG
#pragma comment(lib,"C:\\OpenCV\\cvblob\\lib\\x64\\cvblob.lib")
#else
#pragma comment(lib,"C:\\OpenCV\\cvblob\\lib\\x64\\cvblob.lib")
#endif
#endif



// #pragma の引数になる識別子と文字列を作成するマクロ．
#ifdef _DEBUG
#define OPENCV_COMMENT_LIB_FNAME(name) \
comment(lib, LIB_DIR"opencv_"name""_CV_VER"d.lib")
#else
#define OPENCV_COMMENT_LIB_FNAME(name) \
comment(lib, LIB_DIR"opencv_"name""_CV_VER".lib")
#endif


//*****不要なライブラリはコメントにする．*****

//メモリ確保/解放，行列，演算など
#define _CV_CORE_	
//画像処理，一般的なフィルタ処理など
#define _CV_IMGPROC_	
//ウィンドウなどのGUI，ファイル読込/保存，ビデオファイル，カメラなど
#define _CV_HIGHGUI_	
//サポートベクタマシン，ブースティングなどの機械学習
#define _CV_ML_
//SURF，FASTなどの特徴抽出
#define _CV_FEATURES2D_	
//前景/背景分離(background_segm.hpp)
#define _CV_VIDEO_	
//Haar，LBP，HOGなどのオブジェクト検出器
#define _CV_OBJDETECT_	
//カメラキャリブレーション，ステレオカメラなど
#define _CV_CALIB3D_	
//高速最近傍処理(FLANN)など
#define _CV_FLANN_	
//肌検出，MeanShiftなど完全な状態ではない
//#define _CV_CONTRIB_	
//旧関数との互換用
//#define _CV_LEGACY_	
//GPU(CUDA)による行列演算，画像処理など
//#define _CV_GPU_	
//VTKによるPointCloud処理
#define _CV_VIZ_	

//imread,imwrite
#define _CV_IMGCODECS_

//*************************
//メモリ確保/解放，行列，演算，描画など
//core_c.h (C言語用)
//core.hpp (C++用)
#ifdef _CV_CORE_
#pragma OPENCV_COMMENT_LIB_FNAME("core")
#endif


// ライブラリのリンク
//情報ソース  画像処理ソリューション
//http://imagingsolution.blog107.fc2.com/blog-entry-275.html

//画像処理，一般的なフィルタ処理など
//imgproc_c.h (C言語用)
//imgproc.hpp (C++用)
#ifdef _CV_IMGPROC_
#pragma OPENCV_COMMENT_LIB_FNAME("imgproc")
#endif

//ウィンドウなどのGUI，ファイル読込/保存，ビデオファイル，カメラなど
//highgui_c.h (C言語用)，highgui.hpp (C++用)
#ifdef _CV_HIGHGUI_
#pragma OPENCV_COMMENT_LIB_FNAME("highgui")
#endif

#ifdef _CV_IMGCODECS_
#pragma OPENCV_COMMENT_LIB_FNAME("imgcodecs")
#endif

//サポートベクタマシン，ブースティングなどの機械学習
//ml.hpp
#ifdef _CV_ML_
#pragma OPENCV_COMMENT_LIB_FNAME("ml")
#endif

//SURF，FASTなどの特徴抽出
//features2d.hpp
#ifdef _CV_FEATURES2D_
#pragma OPENCV_COMMENT_LIB_FNAME("features2d")
#endif

//前景/背景分離(background_segm.hpp)
//トラッキング(tracking.hpp)
#ifdef _CV_VIDEO_
#pragma OPENCV_COMMENT_LIB_FNAME("video")
#endif

//Haar，LBP，HOGなどのオブジェクト検出器
//objdetect.hpp
#ifdef _CV_OBJDETECT_
#pragma OPENCV_COMMENT_LIB_FNAME("objdetect")
#endif

//カメラキャリブレーション，ステレオカメラなど
//calib3d.hpp
#ifdef _CV_CALIB3D_
#pragma OPENCV_COMMENT_LIB_FNAME("calib3d")
#endif

//高速最近傍処理(FLANN)など
//flann.hpp
#ifdef _CV_FLANN_
#pragma OPENCV_COMMENT_LIB_FNAME("flann")
#endif

//肌検出，MeanShiftなど完全な状態ではない
//contrib.hpp
//#ifdef _CV_CONTRIB_
//#pragma OPENCV_COMMENT_LIB_FNAME("contrib")
//#endif

//旧関数との互換用
//legacy.hpp
//#ifdef _CV_LEGACY_
//#pragma OPENCV_COMMENT_LIB_FNAME("legacy")
//#endif

//GPU(CUDA)による行列演算，画像処理など
//gpu.hpp
//#ifdef _CV_GPU_
//#pragma OPENCV_COMMENT_LIB_FNAME("gpu")
//#endif

//VTKによるPointCloud処理
//viz/vizcore.hpp
#ifdef _CV_VIZ_
#pragma OPENCV_COMMENT_LIB_FNAME("viz")
#endif
