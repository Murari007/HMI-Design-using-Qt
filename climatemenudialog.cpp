#include "climatemenudialog.h"
#include <QPainterPath>
#include <QHBoxLayout>
#include <QLabel>
#include "ClickableLabel.h"
#include "qpushbutton.h"

ClimateMenuDialog::ClimateMenuDialog(QWidget *parent) : QDialog(parent)
{
    // Set the desired size
    setFixedSize(900, 400);

    // Set font style for label1
    QFont font;
    font.setFamily("Avenir Next LT Pro");  // Set the font family
    font.setPointSize(10);    // Set the font size
    font.setBold(true);

    // Set a vertical linear gradient background color for the QDialog using a stylesheet
    setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #141e40, stop:1 #141e30);""border: 2px;");

    // Remove the title heading
    setWindowFlags(Qt::FramelessWindowHint);

    // Create a rounded shape for the dialog
    QPainterPath path;
    path.addRoundedRect(rect(), 40, 40);
    setMask(path.toFillPolygon().toPolygon());

    // Create a widget to contain the list of texts
    QWidget *textContainer = new QWidget(this);

    // Create a layout to arrange the texts vertically
    QHBoxLayout *layout = new QHBoxLayout(textContainer);

    // Add the text labels to the layout and center their text
    QStringList textLabels = {"First Row Seats", "Second Row Seats","Air Quality","Pre-entry Climate Control"};
    for (const QString& text : textLabels)
    {
        ClickableLabel* label = new ClickableLabel(text);
        label->setStyleSheet("color:white;""border: none;");
        label->setAlignment(Qt::AlignCenter);
        label->setFont(font);
        layout->addWidget(label);

        // Connect the custom labelClicked signal to a slot for handling the click event
        connect(label, &ClickableLabel::labelClicked, this, &ClimateMenuDialog::handleLabelClick);
    }

    // Set the widget to be scrollable
    textContainer->setMinimumWidth(800);  // Adjust the width as needed
    textContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    textContainer->setLayout(layout);

    // Center the text widget within the dialog
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textContainer, 0,Qt::AlignTop | Qt::AlignJustify); // Center the textContainer widget

    label1 = new QWidget(this);

    label1->setStyleSheet("background-color: #141e50; border: 2px solid #111111; border-radius: 10px;");
    label1->hide();

    QHBoxLayout *label1Layout = new QHBoxLayout(label1);

    label1Layout->setSpacing(10);

    QLabel *label1Text = new QLabel("Edit departure time");
    label1Text->setStyleSheet("color: white;border: none;");
    label1Text->setFont(font);
    label1Text->setFixedSize(180,30);
    label1Layout->addWidget(label1Text);

    QLabel *editIconLabel = new QLabel();
    QPixmap originalPixmap("D:/draw.png");
    QPixmap scaledPixmap = originalPixmap.scaled(20, 20, Qt::KeepAspectRatio);
    editIconLabel->setPixmap(scaledPixmap);  // Set the path to your pencil icon
    editIconLabel->setFixedSize(20, 20);  // Adjust the size as needed
    editIconLabel->setStyleSheet("border:none;");
    label1Layout->addWidget(editIconLabel);

    label1->setLayout(label1Layout);

    // Create label2 as a custom widget with a sliding button
    label2 = new QWidget(this);
    label2->setStyleSheet("background-color: #141e50; border: 2px solid #111111; border-radius: 10px;");
    label2->hide();

    QHBoxLayout *label2Layout = new QHBoxLayout(label2);

    QPushButton *slidingButton = new QPushButton(this);
    slidingButton->setCheckable(true);  // Make it checkable for sliding behavior
    slidingButton->setChecked(false);  // Set the initial state (unchecked)
    slidingButton->setFixedSize(20, 20);  // Adjust the size as needed

    // Define the styles for the sliding button
    const QString styleUnchecked = "background-color: red; color: white;";
    const QString styleChecked = "background-color: green; color: white;";

    // Set the initial style based on the initial state
    slidingButton->setStyleSheet(slidingButton->isChecked() ? styleChecked : styleUnchecked);

    // Connect a slot to handle the button state change
    QObject::connect(slidingButton, &QPushButton::clicked, [=]()
    {
        // Toggle the style when the button is clicked
        slidingButton->setStyleSheet(slidingButton->isChecked() ? styleUnchecked : styleChecked);

    });

    QLabel *label2Text = new QLabel("Activation when unlocked");
    label2Text->setStyleSheet("color: white;border:none;");
    label2Text->setFont(font);
    label2Text->setFixedSize(180,30);
    label2Layout->addWidget(label2Text);
    label2Layout->addWidget(slidingButton);

    label2->setLayout(label2Layout);


    // Add the custom label widgets (label1 and label2) to the layout
    mainLayout->setSpacing(0);
    mainLayout->addWidget(label1, 0, Qt::AlignTop | Qt::AlignJustify);
    mainLayout->addWidget(label2, 0, Qt::AlignTop | Qt::AlignJustify);



}
// Slot for handling label clicks
void ClimateMenuDialog::handleLabelClick()
{
    ClickableLabel* clickedLabel = qobject_cast<ClickableLabel*>(sender());

    if (clickedLabel)
    {
        // Access the text of the clicked label
        QString labelText = clickedLabel->text();

        // Get the current text color from the stylesheet
        QString currentStylesheet = clickedLabel->styleSheet();

        // Check if the current color is "orange"
        bool isOrange = currentStylesheet.contains("color: orange;");


        // Handle the click for the specific label
        if (labelText == "First Row Seats")
        {
            if (isOrange) {
                clickedLabel->setStyleSheet("color: white; border: none;");
            } else {
                clickedLabel->setStyleSheet("color: orange; border: none;");
            }
        }
        else if (labelText == "Second Row Seats")
        {

            if (isOrange) {
                clickedLabel->setStyleSheet("color: white; border: none;");
            } else {
                clickedLabel->setStyleSheet("color: orange; border: none;");
            }
        }
        else if (labelText == "Air Quality")
        {

            if (isOrange) {
                clickedLabel->setStyleSheet("color: white; border: none;");
            } else {
                clickedLabel->setStyleSheet("color: orange; border: none;");
            }
        }
        else if (labelText == "Pre-entry Climate Control")
        {
            // Toggle the visibility of label1 and label2
            bool labelVisible = label1->isVisible();
            label1->setVisible(!labelVisible);
            label2->setVisible(!labelVisible);
            // Change the color of the clicked label based on visibility
            if (labelVisible) {
                clickedLabel->setStyleSheet("color: white;""border: none;");
            } else {
                clickedLabel->setStyleSheet("color: orange;""border: none;");
            }
        }

    }
}
