#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>

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
    QVBoxLayout *mainLayout;

    QHBoxLayout *line1Layout;
    QHBoxLayout *line2Layout;
    QHBoxLayout *line3Layout;
    QHBoxLayout *line4Layout;

    QLineEdit *filePathLineedit;
    QLineEdit *outputDictLineedit;

    QString filePath;
    QString outputDict;

    int frameCount;
    QVector<QLabel*> originLabels;
    QVector<QLabel*> targetLabels;

    RectSelector *rectSelector;

public slots:
    void selectFilePath();
    void selectOutputDict();

    void load();
};

#endif // MYWIDGET_H
