#ifndef SURFACEDIALWIDGET_H
#define SURFACEDIALWIDGET_H

#include "qlabel.h"
#include <QWidget>
#include <QPushButton>

class SurfaceDialWidget : public QWidget
{
    Q_OBJECT

public:
    SurfaceDialWidget(QWidget* parent = nullptr);

    QLabel* getCenterLabel() const {
        return centerLabel;
    }

signals:
    void upButtonClicked();
    void downButtonClicked();
    void leftButtonClicked();
    void rightButtonClicked();

private slots:
    void onUpButtonClicked();
    void onDownButtonClicked();
    void onLeftButtonClicked();
    void onRightButtonClicked();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPushButton* upButton;
    QPushButton* downButton;
    QPushButton* leftButton;
    QPushButton* rightButton;
    QLabel* centerLabel;
public:
    QList<SurfaceDialWidget*> dialWidgets;


};

#endif // SURFACEDIALWIDGET_H
