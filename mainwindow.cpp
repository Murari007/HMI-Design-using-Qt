#include "mainwindow.h"
#include "SurfaceDialWidget.h"
#include "qpainter.h"
#include "qpen.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

bool lineColorToggle1 = false; // Initial color state for iconLabel1
bool lineColorToggle2 = false; // Initial color state for iconLabel2
bool lineColorToggle3 = false; // Initial color state for iconLabel3
bool lineColorToggle4 = false;
bool lineColorToggle5 = false;
bool lineColorToggle6 = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create two instances of your custom widget
    SurfaceDialWidget *leftDialWidget = new SurfaceDialWidget(this);
    SurfaceDialWidget *rightDialWidget = new SurfaceDialWidget(this);


    qDebug() << width();

    qDebug() << height();



    // Create QLabel objects for multiple icons
    iconLabel1 = createIconLabel("D:/heat_max.png", 550, height() / 2 + 490);
    iconLabel2 = createIconLabel("D:/heat_rare.png", 950, height() / 2 + 490);
    iconLabel3 = createIconLabel("D:/sportive-car.png",750, height() / 2 + 490);
    iconLabel4 = createIconLabel("D:/previous.png",900, height() / 2 + 410);
    iconLabel5 = createIconLabel("D:/next.png",1000, height() / 2 + 410);
    iconLabel6 = createIconLabel("D:/left-turn-arrow.png",550, height() / 2 + 415);
    iconLabel7 = createIconLabel("D:/thermometer.png",680, height() / 2 + 570);

    connect(iconLabel1, &QLabel::linkActivated, this, &MainWindow::iconLabelClicked);

    // Connect the click event of iconLabel2 to the iconLabel2Clicked slot
    connect(iconLabel2, &QLabel::linkActivated, this, &MainWindow::iconLabel2Clicked);

    connect(iconLabel3, &QLabel::linkActivated, this, &MainWindow::iconLabel3Clicked);

    // Add the widgets to your main window
    leftDialWidget->setGeometry(200, height() / 2 + 410, 200, 200); // Adjust the position and size as needed
    rightDialWidget->setGeometry(1100, height() / 2 + 410, 200, 200); // Adjust the position and size as needed



    Button = new QPushButton(QIcon("D:/home.png"), "", this);

    Button->setGeometry(750, height() / 2 + 410, 50, 50);

    Button->setIconSize(QSize(32, 32));  // Set the icon size as needed

    // Apply a style sheet to customize the button's appearance
    Button->setStyleSheet("QPushButton {"
                         "   border: 2px solid #141e30;"
                         "   border-radius: 25px;"
                         "   background-color: #141e30;"
                         "   color: #ffffff;"
                         "   font-size: 16px;"
                         "   padding: 10px;"
                         "}"
                         "QPushButton:hover {"
                         "   background-color: #2980b9;"
                         "}");


    // In the constructor, create and set properties for the text label
    textLabel = new QLabel("AUTO", this);
    textLabel->setStyleSheet("color: white; font-size: 16px;");
    textLabel->setAlignment(Qt::AlignCenter);

    // Make the label clickable
    textLabel->setCursor(Qt::PointingHandCursor);
    textLabel->installEventFilter(this);
    connect(textLabel, &QLabel::linkActivated, this, &MainWindow::textLabelClicked);

    textLabel1 = new QLabel("AUTO", this);
    textLabel1->setStyleSheet("color: white; font-size: 16px;");
    textLabel1->setAlignment(Qt::AlignCenter);
    // Make the label clickable
    textLabel1->setCursor(Qt::PointingHandCursor);
    textLabel1->installEventFilter(this);
    connect(textLabel1, &QLabel::linkActivated, this, &MainWindow::textLabel1Clicked);

    textLabel2 = new QLabel("Climate Menu", this);
    textLabel2->setStyleSheet("color: white; font-size: 16px;");
    textLabel2->setAlignment(Qt::AlignCenter);
    // Make the label clickable
    textLabel2->setCursor(Qt::PointingHandCursor);
    textLabel2->installEventFilter(this);
    connect(textLabel2, &QLabel::linkActivated, this, &MainWindow::textLabel2Clicked);

    // Create an instance of ClimateMenuDialog
    climateMenuDialog = new ClimateMenuDialog(this);
    climateMenuDialog->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);

    QPolygon polygon;

    QPolygon polygon1;

    // Get the bounding rectangle of the polygon
    QRect boundingRect = polygon.boundingRect();

    // Create a QLinearGradient with a vertical gradient (top to bottom)
    QLinearGradient gradient(boundingRect.center(), boundingRect.topLeft());
    gradient.setColorAt(0.0, QColor(20, 30, 80, 255));
    gradient.setColorAt(1.0, QColor(20, 30, 50, 255));

    // Create a QLinearGradient with a vertical gradient (top to bottom)
    QLinearGradient gradient1(boundingRect.center(), boundingRect.topLeft());
    gradient1.setColorAt(0.0, QColor(0, 0, 0, 255));
    gradient1.setColorAt(1.0, QColor(0, 0, 0, 255));


    polygon1 << QPoint(0, 0)
            << QPoint(0, height() / 2 + 99)
            << QPoint(width()/2 - 599, height()/2 + 199)
            << QPoint(width()/2 + 599,height()/2 + 199)
            << QPoint(width(),height() / 2 + 99)
            << QPoint(width(),0);

    painter.setPen(QPen(Qt::black, 2));


    polygon << QPoint(0, height() / 2 + 100)
            << QPoint(width()/2 - 600, height()/2 + 200)
            << QPoint(width()/2 + 600,height()/2 + 200)
            << QPoint(width(),height() / 2 + 100)
            << QPoint(width(),height())
            << QPoint(0,height());



    // Create a QBrush object from the QLinearGradient object
    QBrush brush(gradient);
    // Set the brush color of the QPainter object
    painter.setBrush(brush);
    painter.drawPolygon(polygon);

    // Create a QBrush object from the QLinearGradient object
    QBrush brush1(gradient1);
    // Set the brush color of the QPainter object
    painter.setBrush(brush1);
    painter.drawPolygon(polygon1);

    QPixmap image("D:/map.png");
    // Set the desired width and height
    int scaledWidth = width();
    int scaledHeight = 620;

    // Scale the image to the desired dimensions
    QPixmap scaledPixmap = image.scaled(scaledWidth, scaledHeight);

    // Draw the scaled image at the desired position
    painter.drawPixmap(0, 0, scaledPixmap);// Replace "your_image.png" with your image file


    painter.setPen(QPen(lineColorToggle1 ? Qt::red : Qt::white, 2));
    painter.drawLine(iconLabel1->x(), iconLabel1->y() + iconLabel1->height() + 10,iconLabel1->x() + iconLabel1->width(),
                     iconLabel1->y() + iconLabel1->height() + 10);

    painter.setPen(QPen(lineColorToggle2 ? Qt::red : Qt::white, 2));
    painter.drawLine(iconLabel2->x(),iconLabel2->y() + iconLabel2->height() + 10,iconLabel2->x() + iconLabel2->width(),
                     iconLabel2->y() + iconLabel2->height() + 10);

    painter.setPen(QPen(lineColorToggle3 ? Qt::red : Qt::white, 2));
    painter.drawLine(iconLabel3->x(),iconLabel3->y() + iconLabel3->height() + 5,iconLabel3->x() + iconLabel3->width(),
                     iconLabel3->y() + iconLabel3->height() + 5);


    // Draw the line
    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(iconLabel4->x() + iconLabel4->width() + 25, iconLabel4->y() + iconLabel4->height(),
                     iconLabel4->x() + iconLabel4->width() + 25, iconLabel5->y());


    textLabel->setGeometry(iconLabel1->x(), iconLabel1->y() + 90, 50, 20);

     painter.setPen(QPen(lineColorToggle4 ? Qt::red : Qt::white, 2));
    int textLabelStartX = textLabel->x();
    painter.drawLine(textLabelStartX, textLabel->y() + 30, textLabelStartX + textLabel->width(), textLabel->y() + 30);


    textLabel1->setGeometry(iconLabel2->x(), iconLabel2->y() + 90, 50, 20);

    painter.setPen(QPen(lineColorToggle5 ? Qt::red : Qt::white, 2));
    int textLabelStartX1 = textLabel1->x();
    painter.drawLine(textLabelStartX1, textLabel1->y() + 30, textLabelStartX1 + textLabel1->width(),textLabel1->y() + 30);

    textLabel2->setGeometry(iconLabel7->x() + 50, iconLabel3->y() + 90, 100, 20);

    painter.setPen(QPen(lineColorToggle6 ? Qt::red : Qt::white, 2));
    int textLabelStartX2 = textLabel2->x();
    painter.drawLine(textLabelStartX2, textLabel2->y() + 30, textLabelStartX2 + textLabel2->width(), textLabel2->y() + 30);

}

QLabel* MainWindow::createIconLabel(const QString& iconPath, int x, int y)
{
    // Create a QLabel for the icon
    QLabel *iconLabel = new QLabel(this);

    // Set the size of the label
    int iconSize = 45; // Set the size you want
    iconLabel->setFixedSize(iconSize, iconSize);

    // Load the icon image and set it as the label's pixmap, scaled to the icon size
    QPixmap originalPixmap(iconPath);
    QPixmap scaledPixmap = originalPixmap.scaled(iconSize, iconSize, Qt::KeepAspectRatio);
    iconLabel->setPixmap(scaledPixmap);

    // Make the label clickable
    iconLabel->setCursor(Qt::PointingHandCursor);
    iconLabel->installEventFilter(this); // Install an event filter to handle click events

    // Set the label's background color
    iconLabel->setStyleSheet("background-color: #141e50;");

    // Position the icon label at the specified coordinates
    iconLabel->setGeometry(x, y, iconSize, iconSize);


    return iconLabel;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == iconLabel1)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            iconLabelClicked();
            return true;
        }
    }
    else if (obj == iconLabel2)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            iconLabel2Clicked();
            return true;
        }

    }
    else if (obj == iconLabel3)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            iconLabel3Clicked();
            return true;
        }
    }
    else if (obj == textLabel)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            textLabelClicked();
            return true;
        }
    }
    else if (obj == textLabel1)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            textLabel1Clicked();
            return true;
        }
    }
    else if (obj == textLabel2)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            textLabel2Clicked();
            return true;
        }
    }


    return QMainWindow::eventFilter(obj, event);
}
void MainWindow::iconLabelClicked()
{
    lineColorToggle1 = !lineColorToggle1; // Toggle the color state for iconLabel3
    update();
}

void MainWindow::iconLabel2Clicked()
{
    lineColorToggle2 = !lineColorToggle2; // Toggle the color state for iconLabel3
    update();
}
void MainWindow::iconLabel3Clicked()
{
    lineColorToggle3 = !lineColorToggle3; // Toggle the color state for iconLabel3
    update();
}
void MainWindow::textLabelClicked()
{
    lineColorToggle4 = !lineColorToggle4; // Toggle the color state for iconLabel3
    update();
}
void MainWindow::textLabel1Clicked()
{
    lineColorToggle5 = !lineColorToggle5; // Toggle the color state for iconLabel3
    update();
}
void MainWindow::textLabel2Clicked()
{
    lineColorToggle6 = !lineColorToggle6; // Toggle the color state for iconLabel3
    update();
    if (climateMenuDialog->isVisible()) {
        climateMenuDialog->hide(); // Hide the dialog if it's visible
    } else {
        climateMenuDialog->show(); // Show the dialog if it's not visible
    }
}
