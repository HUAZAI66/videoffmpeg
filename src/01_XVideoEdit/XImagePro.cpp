#include "XImagePro.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

//设置原图，会清理处理结果
void XImagePro::Set(cv::Mat mat1, cv::Mat mat2)
{
	if (mat1.empty())return;
	this->src1 = mat1;
	this->src2 = mat2;
	this->src1.copyTo(des);
}

//设置亮度和对比度
///@para bright double 亮度 0~100
///@para contrast int 对比度 1.0 ~ 3.0
void XImagePro::Gain(double bright, double contrast)
{
	if (des.empty())return;
	des.convertTo(des, -1, contrast, bright);
}

void XImagePro::Rotate90()
{
	if (des.empty())return;
	rotate(des, des, ROTATE_90_CLOCKWISE);
}
void XImagePro::Rotate180()
{
	if (des.empty())return;
	rotate(des, des, ROTATE_180);
}
void XImagePro::Rotate270()
{
	if (des.empty())return;
	rotate(des, des, ROTATE_90_COUNTERCLOCKWISE);
}
//左右镜像
void XImagePro::FlipX()
{
	if (des.empty())return;
	flip(des, des, 0);
}

//上下镜像
void XImagePro::FlipY()
{
	if (des.empty())return;
	flip(des, des, 1);
}
void XImagePro::FlipXY()
{
	if (des.empty())return;
	flip(des, des, -1);
}
// 图像尺寸
void XImagePro::Resize(int width, int height)
{
	if (des.empty())return;
	resize(des, des, Size(width, height));
}
void XImagePro::PyDown(int count)
{
	if (des.empty())return;
	for (int i = 0; i < count; i++)
		pyrDown(des, des);
}
void XImagePro::PyUp(int count)
{
	if (des.empty())return;
	for (int i = 0; i < count; i++)
		pyrUp(des, des);

}
void XImagePro::Clip(int x, int y, int w, int h)
{
	if (des.empty())return;
	if (x < 0 || y < 0 || w <= 0 || h <= 0)return;
	if (x > des.cols || y > des.rows)return;
	des = des(Rect(x, y, w, h));

}
//转为灰度图
void XImagePro::Gray()
{
	if (des.empty())return;
	cvtColor(des, des, COLOR_BGR2GRAY);
}
//水印
void XImagePro::Mark(int x, int y, double a)
{
	if (des.empty())return;
	if (src2.empty())return;
	Mat rol = des(Rect(x, y, src2.cols, src2.rows));
	addWeighted(src2, a, rol, 1 - a, 0, rol);
}
//融合
void XImagePro::Blend(double a)
{
	if (des.empty())return;
	if (src2.empty())return;
	if (src2.size() != des.size())
	{
		resize(src2, src2, des.size());
	}
	addWeighted(src2, a, des, 1 - a, 0, des);
}
//合并
void  XImagePro::Merge()
{
	if (des.empty())return;
	if (src2.empty())return;
	if (src2.size() != des.size())
	{
		int w = src2.cols * ((double)src2.rows / (double)des.rows);
		resize(src2, src2, Size(w, des.rows));
	}
	int dw = des.cols + src2.cols;
	int dh = des.rows;
	des = Mat(Size(dw, dh), src1.type());
	Mat r1 = des(Rect(0, 0, src1.cols, dh));
	Mat r2 = des(Rect(src1.cols, 0, src2.cols, dh));
	src1.copyTo(r1);
	src2.copyTo(r2);
}

XImagePro::XImagePro()
{

}


XImagePro::~XImagePro()
{

}
