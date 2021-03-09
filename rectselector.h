#ifndef RECTSELECTOR_H
#define RECTSELECTOR_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QGridLayout>
#include <QVector>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QVector>


enum SelectorPosition {
    X, Y, Width, Height, Max
};


class RectSelector : public QWidget
{
    Q_OBJECT
public:
    explicit RectSelector(QWidget *parent = nullptr);

    void SetImage(QPixmap image);

    QRect GetSize();

public slots:
    void changed();

signals:

private:
    QGridLayout *mainLayout;

    QVector<QSpinBox*> spinBoxes;
    QVector<QSlider*> sliders;

    QPixmap rawImage;

    QLabel *raw;
    QLabel *preview;
};

#endif // RECTSELECTOR_H
