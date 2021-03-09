#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>
#include <QScrollArea>
#include <QMovie>
#include <QVector>
#include "rectselector.h"


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

signals:
private:
    QGridLayout *mainLayout;

    QLineEdit *filePathLineedit;
    QLineEdit *outputDictLineedit;

    QString filePath;
    QString outputDict;

    int frameCount;
    QVector<QImage> images;
    QGridLayout *originContent;
    QGridLayout *targetContent;
    QVector<QLabel*> originLabels;
    QVector<QLabel*> targetLabels;

    RectSelector *rectSelector;

public slots:
    void selectFilePath();
    void selectOutputDict();

    void load();
    void generate();
};

#endif // MYWIDGET_H
