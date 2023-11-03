#include "SurfaceDialWidget.h"
#include <QPainter>
#include <QLabel>

SurfaceDialWidget::SurfaceDialWidget(QWidget* parent) : QWidget(parent)
{
    // Set the size of the widget
    resize(200, 200);

    // Create a QRegion object for the rounded corners
    QRegion region(0, 0, width(), height(), QRegion::Ellipse);

    // Set the mask of the widget to the QRegion object
    setMask(region);

    // Create directional buttons
    upButton = new QPushButton(QIcon("D:/Arrow_up.png"), "", this);
    downButton = new QPushButton(QIcon("D:/Arrow_down.png"), "", this);
    leftButton = new QPushButton(QIcon("D:/fan_large.png"), "", this);
    rightButton = new QPushButton(QIcon("D:/fan_small.png"), "", this);

    // Set button positions within the circular area
    upButton->setGeometry(75, 0, 50, 50);
    downButton->setGeometry(75, 150, 50, 50);
    leftButton->setGeometry(0, 75, 50, 50);
    rightButton->setGeometry(150, 75, 50, 50);

    // Apply custom styles to the buttons
    QString buttonStyle = "QPushButton {"
                          "    background-color: #0f0f2d;" // Background color
                          "    color: #ffffff;" // Text color
                          "    border: 2px solid #212360;" // Border style
                          "    border-radius: 25px;" // Adjust the radius to change the shape
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #1F2040;" // Hover background color
                          "    border: 2px solid #212360;" // Hover border style
                          "}";

    upButton->setStyleSheet(buttonStyle);
    downButton->setStyleSheet(buttonStyle);
    leftButton->setStyleSheet(buttonStyle);
    rightButton->setStyleSheet(buttonStyle);

    // Connect button signals to slots
    connect(upButton, &QPushButton::clicked, this, &SurfaceDialWidget::onUpButtonClicked);
    connect(downButton, &QPushButton::clicked, this, &SurfaceDialWidget::onDownButtonClicked);
    connect(leftButton, &QPushButton::clicked, this, &SurfaceDialWidget::onLeftButtonClicked);
    connect(rightButton, &QPushButton::clicked, this, &SurfaceDialWidget::onRightButtonClicked);

    // Create a QLabel for displaying the value in the center
    centerLabel = new QLabel("LOW", this);
    centerLabel->setAlignment(Qt::AlignCenter);
    centerLabel->setGeometry(50, 50, 100, 100);
    centerLabel->setFont(QFont("Arial", 24, QFont::Bold));
    centerLabel->setStyleSheet("QLabel { color: #ffffff; }"); // Text color
}

void SurfaceDialWidget::paintEvent(QPaintEvent* event)
{
    // Create a QPainter object
    QPainter painter(this);

    QLinearGradient gradient(0, 0, width() / 2, height());
    gradient.setColorAt(0.0, QColor(15, 15, 45, 255));
    gradient.setColorAt(1.0, QColor(20, 15, 50, 255));

    // Create a QBrush object from the QLinearGradient object
    QBrush brush(gradient);

    // Set the brush color of the QPainter object
    painter.setBrush(brush);

    painter.drawRoundedRect(0, 0, 200, 200, 100, 100); // Outer round region

    QConicalGradient gradient_inner(52 + 95 / 2, 52 + 95 / 2, 0);
    gradient_inner.setColorAt(0, Qt::red);
    gradient_inner.setColorAt(1, Qt::blue);

    QPen pen(gradient_inner, 2);
    painter.setPen(pen);
    painter.drawEllipse(52, 52, 95, 95); // Inner round line with a red-to-blue gradient
}

void SurfaceDialWidget::onUpButtonClicked()
{
    // Update the value in the centerLabel
    int value = centerLabel->text().toInt();
    value++;
    centerLabel->setText(QString::number(value));

    emit upButtonClicked();
}

void SurfaceDialWidget::onDownButtonClicked()
{
    // Update the value in the centerLabel
    int value = centerLabel->text().toInt();
    value--;
    centerLabel->setText(QString::number(value));

    emit downButtonClicked();
}

void SurfaceDialWidget::onLeftButtonClicked()
{
    // Update the value in the centerLabel
    int value = centerLabel->text().toInt();
    value--;
    centerLabel->setText(QString::number(value));

    emit leftButtonClicked();
}

void SurfaceDialWidget::onRightButtonClicked()
{
    // Update the value in the centerLabel
    int value = centerLabel->text().toInt();
    value++;
    centerLabel->setText(QString::number(value));

    emit rightButtonClicked();
}
