#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LaserLine.h"
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LaserLine : public QMainWindow
{
    Q_OBJECT

public:
    LaserLine(QWidget *parent = Q_NULLPTR);
    //labe��ʾMatͼ��ĺ������޸���http://blog.csdn.net/loveaborn/article/details/7680834
    //����1-��ʾͼ���Label������2-Ҫ��ʾ��Mat
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);

private:
    void ProcessSrcImg();//ԭͼ������
    void ProcessThreshold();//��ֵ��������
    void ProcessIdentifi();//ʶ�������ߺ���

private slots:
    void OnLoadImg();//����ͼƬ��ť�����Ӧ
    void OnRotateImg();//��תͼƬ��ť�����Ӧ
    void OnThresholdValue();//��ֵ�༭�س���Ӧ
    void OnReIdentifi();//����ʶ��ť�����Ӧ

private:
    Ui::LaserLine ui;
    std::string m_strSrcImgName;
    int m_iThresHoldValue;
    cv::Mat m_mSrcImg;
    cv::Mat m_mSmoothImg;
    cv::Mat m_mThresholdImg;
};
