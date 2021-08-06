//cv_lib_ver.h
//20170302

//OpenCV�̃C���X�g�[��DIR
#ifndef LIB_DIR
#define LIB_DIR	"D:\\UserLocal\\Tools\\OpenCV\\lib\\"
#endif


//OpenCV�̃o�[�W����
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



// #pragma �̈����ɂȂ鎯�ʎq�ƕ�������쐬����}�N���D
#ifdef _DEBUG
#define OPENCV_COMMENT_LIB_FNAME(name) \
comment(lib, LIB_DIR"opencv_"name""_CV_VER"d.lib")
#else
#define OPENCV_COMMENT_LIB_FNAME(name) \
comment(lib, LIB_DIR"opencv_"name""_CV_VER".lib")
#endif


//*****�s�v�ȃ��C�u�����̓R�����g�ɂ���D*****

//�������m��/����C�s��C���Z�Ȃ�
#define _CV_CORE_	
//�摜�����C��ʓI�ȃt�B���^�����Ȃ�
#define _CV_IMGPROC_	
//�E�B���h�E�Ȃǂ�GUI�C�t�@�C���Ǎ�/�ۑ��C�r�f�I�t�@�C���C�J�����Ȃ�
#define _CV_HIGHGUI_	
//�T�|�[�g�x�N�^�}�V���C�u�[�X�e�B���O�Ȃǂ̋@�B�w�K
#define _CV_ML_
//SURF�CFAST�Ȃǂ̓������o
#define _CV_FEATURES2D_	
//�O�i/�w�i����(background_segm.hpp)
#define _CV_VIDEO_	
//Haar�CLBP�CHOG�Ȃǂ̃I�u�W�F�N�g���o��
#define _CV_OBJDETECT_	
//�J�����L�����u���[�V�����C�X�e���I�J�����Ȃ�
#define _CV_CALIB3D_	
//�����ŋߖT����(FLANN)�Ȃ�
#define _CV_FLANN_	
//�����o�CMeanShift�ȂǊ��S�ȏ�Ԃł͂Ȃ�
//#define _CV_CONTRIB_	
//���֐��Ƃ̌݊��p
//#define _CV_LEGACY_	
//GPU(CUDA)�ɂ��s�񉉎Z�C�摜�����Ȃ�
//#define _CV_GPU_	
//VTK�ɂ��PointCloud����
#define _CV_VIZ_	

//imread,imwrite
#define _CV_IMGCODECS_

//*************************
//�������m��/����C�s��C���Z�C�`��Ȃ�
//core_c.h (C����p)
//core.hpp (C++�p)
#ifdef _CV_CORE_
#pragma OPENCV_COMMENT_LIB_FNAME("core")
#endif


// ���C�u�����̃����N
//���\�[�X  �摜�����\�����[�V����
//http://imagingsolution.blog107.fc2.com/blog-entry-275.html

//�摜�����C��ʓI�ȃt�B���^�����Ȃ�
//imgproc_c.h (C����p)
//imgproc.hpp (C++�p)
#ifdef _CV_IMGPROC_
#pragma OPENCV_COMMENT_LIB_FNAME("imgproc")
#endif

//�E�B���h�E�Ȃǂ�GUI�C�t�@�C���Ǎ�/�ۑ��C�r�f�I�t�@�C���C�J�����Ȃ�
//highgui_c.h (C����p)�Chighgui.hpp (C++�p)
#ifdef _CV_HIGHGUI_
#pragma OPENCV_COMMENT_LIB_FNAME("highgui")
#endif

#ifdef _CV_IMGCODECS_
#pragma OPENCV_COMMENT_LIB_FNAME("imgcodecs")
#endif

//�T�|�[�g�x�N�^�}�V���C�u�[�X�e�B���O�Ȃǂ̋@�B�w�K
//ml.hpp
#ifdef _CV_ML_
#pragma OPENCV_COMMENT_LIB_FNAME("ml")
#endif

//SURF�CFAST�Ȃǂ̓������o
//features2d.hpp
#ifdef _CV_FEATURES2D_
#pragma OPENCV_COMMENT_LIB_FNAME("features2d")
#endif

//�O�i/�w�i����(background_segm.hpp)
//�g���b�L���O(tracking.hpp)
#ifdef _CV_VIDEO_
#pragma OPENCV_COMMENT_LIB_FNAME("video")
#endif

//Haar�CLBP�CHOG�Ȃǂ̃I�u�W�F�N�g���o��
//objdetect.hpp
#ifdef _CV_OBJDETECT_
#pragma OPENCV_COMMENT_LIB_FNAME("objdetect")
#endif

//�J�����L�����u���[�V�����C�X�e���I�J�����Ȃ�
//calib3d.hpp
#ifdef _CV_CALIB3D_
#pragma OPENCV_COMMENT_LIB_FNAME("calib3d")
#endif

//�����ŋߖT����(FLANN)�Ȃ�
//flann.hpp
#ifdef _CV_FLANN_
#pragma OPENCV_COMMENT_LIB_FNAME("flann")
#endif

//�����o�CMeanShift�ȂǊ��S�ȏ�Ԃł͂Ȃ�
//contrib.hpp
//#ifdef _CV_CONTRIB_
//#pragma OPENCV_COMMENT_LIB_FNAME("contrib")
//#endif

//���֐��Ƃ̌݊��p
//legacy.hpp
//#ifdef _CV_LEGACY_
//#pragma OPENCV_COMMENT_LIB_FNAME("legacy")
//#endif

//GPU(CUDA)�ɂ��s�񉉎Z�C�摜�����Ȃ�
//gpu.hpp
//#ifdef _CV_GPU_
//#pragma OPENCV_COMMENT_LIB_FNAME("gpu")
//#endif

//VTK�ɂ��PointCloud����
//viz/vizcore.hpp
#ifdef _CV_VIZ_
#pragma OPENCV_COMMENT_LIB_FNAME("viz")
#endif
