#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;

    // 第一行控件
    line1Layout = new QHBoxLayout;

    QPushButton *btn1 = new QPushButton("选择文件");
    QPushButton *btn2 = new QPushButton("选择目录");
    QPushButton *btn3 = new QPushButton("加载");
    filePathLineedit = new QLineEdit;
    outputDictLineedit = new QLineEdit;

    filePathLineedit->setDisabled(true);
    outputDictLineedit->setDisabled(true);

    line1Layout->addWidget(btn1);
    line1Layout->addWidget(filePathLineedit);
    line1Layout->addWidget(btn2);
    line1Layout->addWidget(outputDictLineedit);
    line1Layout->addWidget(btn3);


    connect(btn1, SIGNAL(clicked()), this, SLOT(selectFilePath()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(selectOutputDict()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(load()));

    // 第二行控件
    line2Layout = new QHBoxLayout;

    // 第三行控件
    line3Layout = new QHBoxLayout;

    mainLayout->addLayout(line1Layout);
    mainLayout->addLayout(line2Layout);
    mainLayout->addLayout(line3Layout);
    setLayout(mainLayout);
}


void MyWidget::selectFilePath() {
    QString file = QFileDialog::getOpenFileName(nullptr, "sss", ".", "*.gif");
    this->filePath = file;
    this->filePathLineedit->setText(file);
}

void MyWidget::selectOutputDict() {
    QFileDialog *s = new QFileDialog;
    s->setFileMode(QFileDialog::Directory);
    s->show();
}

void MyWidget::load() {
    QMovie *movie = new QMovie(this->filePath);
    this->frameCount = movie->frameCount();

    if(originLabels.isEmpty()) {
        for(int i = 0 ; i < this->frameCount ; i++) {
            auto label = new QLabel;
            movie->jumpToFrame(i);
            label->setPixmap(movie->currentPixmap().scaledToWidth(100));
            originLabels.append(label);
            line2Layout->addWidget(label);
        }
    }

    if(targetLabels.isEmpty()) {
        for(int i = 0 ; i < this->frameCount ;i++) {
            auto label = new QLabel;
            targetLabels.append(label);
            line3Layout->addWidget(label);
        }
    }



    qDebug() << this->filePath << endl;
}
