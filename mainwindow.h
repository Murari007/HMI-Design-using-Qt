#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "climatemenudialog.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event); // Declare the paintEvent function

private:
    Ui::MainWindow *ui;
    QLabel *iconLabel1;
    QLabel *iconLabel2;
    QLabel *iconLabel3;
    QLabel *iconLabel4;
    QLabel *iconLabel5;
    QLabel *iconLabel6;
    QLabel *iconLabel7;
    QLabel *textLabel;
    QLabel *textLabel1;
    QLabel *textLabel2;
    QLabel *mapLabel;

    QLabel* createIconLabel(const QString& iconPath, int x, int y);
    QPushButton* Button;
    ClimateMenuDialog *climateMenuDialog;


protected:
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void iconLabelClicked();
    void iconLabel2Clicked();
    void iconLabel3Clicked();
    void textLabelClicked();
    void textLabel1Clicked();
    void textLabel2Clicked();
};
#endif // MAINWINDOW_H
