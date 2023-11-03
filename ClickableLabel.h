#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    ClickableLabel(const QString& text, QWidget* parent = nullptr) : QLabel(text, parent) {}



signals:
    void labelClicked(); // Custom signal for label clicks

protected:
    void mouseReleaseEvent(QMouseEvent* event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            emit labelClicked(); // Emit the custom signal when clicked
        }
    }
};
