#ifndef RECTSELECTOR_H
#define RECTSELECTOR_H

#include <QWidget>

class RectSelector : public QWidget
{
    Q_OBJECT
public:
    explicit RectSelector(QWidget *parent = nullptr);

signals:

private:
    int x, y;
    int width, height;
};

#endif // RECTSELECTOR_H
