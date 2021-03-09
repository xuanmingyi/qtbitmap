#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QGridLayout;

    // 第一行控件

    QPushButton *btn1 = new QPushButton("选择文件");
    QPushButton *btn2 = new QPushButton("选择目录");
    QPushButton *btn3 = new QPushButton("加载");
    filePathLineedit = new QLineEdit;
    outputDictLineedit = new QLineEdit;

    filePathLineedit->setDisabled(true);
    outputDictLineedit->setDisabled(true);

    mainLayout->addWidget(btn1, 0, 0);
    mainLayout->addWidget(filePathLineedit, 0, 1);
    mainLayout->addWidget(btn2, 0, 2);
    mainLayout->addWidget(outputDictLineedit, 0, 3);
    mainLayout->addWidget(btn3, 0, 4);

    connect(btn1, SIGNAL(clicked()), this, SLOT(selectFilePath()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(selectOutputDict()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(load()));

    // 第二行控件
    rectSelector = new RectSelector;
    mainLayout->addWidget(rectSelector, 1, 0);

    QPushButton *btn4 = new QPushButton("生成");
    connect(btn4, SIGNAL(clicked()), this, SLOT(generate()));
    mainLayout->addWidget(btn4, 1, 1);

    // 第三行控件
    QScrollArea *originArea = new QScrollArea;
    originContent = new QGridLayout;
    originArea->setLayout(originContent);
    mainLayout->addWidget(originArea, 2, 0, 1, -1);

    // 第四行控件
    QScrollArea *targetArea = new QScrollArea;
    targetContent = new QGridLayout;
    targetArea->setLayout(targetContent);
    mainLayout->addWidget(targetArea, 3, 0, 1, -1);

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
            images.append(movie->currentImage());
            label->setPixmap(movie->currentPixmap().scaledToWidth(100));
            originLabels.append(label);
            originContent->addWidget(label, i / 8, i % 8);
        }
    }

    if(targetLabels.isEmpty()) {
        for(int i = 0 ; i < this->frameCount ;i++) {
            auto label = new QLabel;
            targetLabels.append(label);
        }
    }

    movie->jumpToFrame(0);
    rectSelector->SetImage(movie->currentPixmap());
}


void MyWidget::generate() {
    qDebug() << rectSelector->GetSize() << endl;
    for(int i = 0 ; i < images.length() ; i++) {
        images[i].copy(rectSelector->GetSize()).save(QString("%1.png").arg(i));
    }
}
