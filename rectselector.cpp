#include "rectselector.h"

RectSelector::RectSelector(QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;


    mainLayout = new QGridLayout;

    int nMin = 0;
    int nMax = 200;
    int nSingleStep = 10;

    // 微调框
    xSpinBox = new QSpinBox();
    xSpinBox->setMinimum(nMin);  // 最小值
    xSpinBox->setMaximum(nMax);  // 最大值
    xSpinBox->setSingleStep(nSingleStep);  // 步长

    // 滑动条
    xSlider = new QSlider();
    xSlider->setOrientation(Qt::Horizontal);  // 水平方向
    xSlider->setMinimum(nMin);  // 最小值
    xSlider->setMaximum(nMax);  // 最大值
    xSlider->setSingleStep(nSingleStep);  // 步长

    // 连接信号槽（相互改变）
    connect(xSpinBox, SIGNAL(valueChanged(int)), xSlider, SLOT(setValue(int)));
    connect(xSlider, SIGNAL(valueChanged(int)), xSpinBox, SLOT(setValue(int)));

    xSpinBox->setValue(10);

    mainLayout->addWidget(xSpinBox);
    mainLayout->addWidget(xSlider);

    setLayout(mainLayout);
}
