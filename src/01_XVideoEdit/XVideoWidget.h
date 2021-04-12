#pragma once
#include <QOpenGLWidget>
#include <opencv2/core.hpp>
#include <QPaintEvent>
#include <QImage>
class XVideoWidget:public QOpenGLWidget
{
	Q_OBJECT

public:
	XVideoWidget(QWidget* p);
	void paintEvent(QPaintEvent* e);
	virtual ~XVideoWidget();
public slots:
	//界面刷新
	void SetImage(cv::Mat mat);
protected:
	QImage img;
};

