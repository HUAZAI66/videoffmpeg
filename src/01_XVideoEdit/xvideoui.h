#pragma once

#include <QtWidgets/QWidget>
#include "ui_xvideoui.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QPoint>

class XVideoUI : public QWidget
{
    Q_OBJECT

public:
    XVideoUI(QWidget *parent = Q_NULLPTR);
    void timerEvent(QTimerEvent* e);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
public slots:
    //打开视频源事件
    void Open();
    void Play();
    void Pause();
    void SliderPress();
    void SliderRelease();
    //滑动条拖动
    void SetPos(int);
    void Left(int pos);
    void Right(int pos);

    //设置过滤器
    void Set();
    //导出视频
    void Export();

    //导出结束
    void ExportEnd();
    //水印
    void Mark();
    //融合
    void Blend();
    //合并
    void Merge();

private:
    Ui::XVideoUIClass ui;
    QPoint z;
};
