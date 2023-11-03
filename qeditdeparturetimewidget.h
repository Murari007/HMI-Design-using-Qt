#ifndef QEDITDEPARTURETIMEWIDGET_H
#define QEDITDEPARTURETIMEWIDGET_H

#include <QWidget> // Include QWidget header to derive from QWidget

class QEditDepartureTimeWidget : public QWidget { // Derive from QWidget
    Q_OBJECT

public:
    QEditDepartureTimeWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};

#endif // QEDITDEPARTURETIMEWIDGET_H
