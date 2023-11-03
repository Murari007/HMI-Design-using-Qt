#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    CustomWidget(QWidget* parent = nullptr);

private slots:
    void onUpButtonClicked();
    void onDownButtonClicked();
    void onLeftButtonClicked();
    void onRightButtonClicked();

private:
    QGridLayout* layout;
    QPushButton* upButton;
    QPushButton* downButton;
    QPushButton* leftButton;
    QPushButton* rightButton;
    QLabel* displayLabel;
};

#endif // CUSTOMWIDGET_H
