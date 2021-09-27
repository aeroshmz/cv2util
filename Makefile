#Makefile

INC="D:\UserLocal\Tools\OpenCV\include"

CV_VER=452

CV_LIB_PATH=/LIBPATH:"D:\UserLocal\Tools\OpenCV\lib"




# user32.lib
LIB_P_OPT1=/LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\um\x64"
# libcpmt.lib
#LIB_P_OPT2=/LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.16.27023\lib\onecore\x64"
LIB_P_OPT2=/LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.28.29333\lib\x64"
# libucrt.lib
LIB_P_OPT3=/LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\ucrt\x64"


LPATH_FLAGS=$(LIB_P_OPT1) $(LIB_P_OPT2) $(LIB_P_OPT3) $(CV_LIB_PATH)


CV_LIBS=opencv_core$(CV_VER).lib\
		opencv_imgcodecs$(CV_VER).lib\
		opencv_imgproc$(CV_VER).lib\
		opencv_highgui$(CV_VER).lib



all: cv2util.obj
	cl.exe /EHsc /O2 /I$(INC) sample.cpp cv2util.obj /link $(LPATH_FLAGS) $(CV_LIBS)


cv2util.obj: cv2util.cpp cv2util.h
    cl.exe /EHsc /O2 /c cv2util.cpp /I$(INC)



clean:
    del *.obj




