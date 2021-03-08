#ifndef RECTSELECTOR_H
#define RECTSELECTOR_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QGridLayout>


class RectSelector : public QWidget
{
    Q_OBJECT
public:
    explicit RectSelector(QWidget *parent = nullptr);

signals:

private:
    int x, y;
    int width, height;

    QSpinBox *xSpinBox;
    QSpinBox *ySpinBox;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;

    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *widthSlider;
    QSlider *heightSlider;

    QGridLayout *mainLayout;
};

#endif // RECTSELECTOR_H
