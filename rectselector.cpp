#include "rectselector.h"

RectSelector::RectSelector(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QGridLayout;

    for(int i = 0 ; i < Max ; i++) {
        QLabel *label;
        QSpinBox *spinBox = new QSpinBox;
        QSlider *slider = new QSlider(Qt::Horizontal);

        spinBoxes.append(spinBox);
        sliders.append(slider);
        connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
        connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(changed()));
        connect(slider, SIGNAL(valueChanged(int)), this, SLOT(changed()));


        switch (i) {
        case X:
            label = new QLabel("X坐标");
            break;
        case Y:
            label = new QLabel("Y坐标");
            break;
        case Width:
            label = new QLabel("宽度");
            break;
        case Height:
            label = new QLabel("高度");
            break;
        }

        mainLayout->addWidget(label, i, 0);
        mainLayout->addWidget(spinBox, i, 1);
        mainLayout->addWidget(slider, i, 2);
    }

    raw = new QLabel;
    preview = new QLabel;

    mainLayout->addWidget(raw, 0, 3, 4, 1);
    mainLayout->addWidget(preview, 0, 4, 4, 1);
    setLayout(mainLayout);
}


void RectSelector::SetImage(QPixmap image) {
    rawImage = image;
    raw->setPixmap(rawImage.scaledToWidth(110));
}


QRect RectSelector::GetSize() {
    QRect rect;
    rect.setX(sliders[X]->value());
    rect.setY(sliders[Y]->value());
    rect.setWidth(sliders[Width]->value());
    rect.setHeight(sliders[Height]->value());
    return rect;
}


void RectSelector::changed() {
    preview->setPixmap(rawImage.copy(GetSize()).scaledToWidth(110));
}
