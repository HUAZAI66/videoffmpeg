#pragma once
#include <QThread>
#include "opencv2/core.hpp"
#include <QMutex>

class XVideoThread :public QThread
{

	Q_OBJECT

public:
	int fps = 0;
	int width = 0;
	int height = 0;

	int width2 = 0;
	int height2 = 0;
	int totalMs = 0;
	std::string src1file;
	std::string desFile;

	int begin = 0;
	int end = 0;

	void SetBegin(double p);
	void SetEnd(double p);
	//单件模式 获取对象
	static XVideoThread* Get()
	{
		static XVideoThread vt;
		return &vt;
	}
	//打开一号视频源文件
	bool Open(const std::string file);
	//打开二号视频源文件
	bool Open2(const std::string file);

	void Play() { mutex.lock(); isPlay = true; mutex.unlock(); }
	void Pause() { mutex.lock(); isPlay = false;  mutex.unlock();}
	//返回当前播放的位置
	double GetPos();

	//跳转视频 
	///@para frame int 帧位置
	bool Seek(int frame);
	bool Seek(double pos);
	//开始保存视频
	bool StartSave(const std::string filename, int width = 0, int height = 0, bool isColor = true);

	//停止保存视频，写入视频帧的索引
	void StopSave();
	//添加水印
	void SetMark(cv::Mat m) { mutex.lock(); this->mark = m; mutex.unlock(); };


	~XVideoThread();

	//线程入口函数
	void run();

signals:
	//显示原视频图像
	void ViewImage1(cv::Mat mat);
	void ViewImage2(cv::Mat mat);
	//显示生成后图像
	void ViewDes(cv::Mat mat);
	void SaveEnd();
protected:
	QMutex mutex;

	//是否开始写视频
	bool isWrite = false;
	bool isPlay = false;
	cv::Mat mark;
	XVideoThread();
};

