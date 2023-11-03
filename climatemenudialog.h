#ifndef CLIMATEMENU_H
#define CLIMATEMENU_H

#include <QDialog>

class ClimateMenuDialog : public QDialog
{
    Q_OBJECT

public:
    ClimateMenuDialog(QWidget *parent = nullptr);
    void handleLabelClick();

private:
    // Add preEntryControlLabels as a private member
    QWidget *label1;
    QWidget *label2;

};

#endif
