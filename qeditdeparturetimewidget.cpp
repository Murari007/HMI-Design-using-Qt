#include "qeditdeparturetimewidget.h"
#include <QLabel>
#include <QTimeEdit>
#include <QCheckBox>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QApplication>

QEditDepartureTimeWidget::QEditDepartureTimeWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* label = new QLabel("Edit departure time", this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(10, 10, 180, 20);

    QTimeEdit* timeEdit = new QTimeEdit(QTime::currentTime(), this);
    timeEdit->setGeometry(10, 40, 180, 30);

    QCheckBox* checkBox = new QCheckBox("Activation when unlocked", this);
    checkBox->setGeometry(10, 80, 180, 20);
}

void QEditDepartureTimeWidget::paintEvent(QPaintEvent *event)
{
    // Custom painting code if needed
    QWidget::paintEvent(event);
}

void QEditDepartureTimeWidget::mousePressEvent(QMouseEvent *event)
{
    // Handle mouse press event if needed
    QWidget::mousePressEvent(event);
}

void QEditDepartureTimeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    // Handle mouse release event if needed
    QWidget::mouseReleaseEvent(event);
}
