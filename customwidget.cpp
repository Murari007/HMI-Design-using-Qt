#include "customwidget.h"

CustomWidget::CustomWidget(QWidget* parent) : QWidget(parent) {
    // Create the layout for the custom widget
    layout = new QGridLayout(this);

    // Create directional buttons
    upButton = new QPushButton("Up");
    downButton = new QPushButton("Down");
    leftButton = new QPushButton("Left");
    rightButton = new QPushButton("Right");

    // Create and configure the central display label
    displayLabel = new QLabel("Center");
    displayLabel->setAlignment(Qt::AlignCenter);

    // Add widgets to the layout
    layout->addWidget(upButton, 0, 1);
    layout->addWidget(downButton, 2, 1);
    layout->addWidget(leftButton, 1, 0);
    layout->addWidget(rightButton, 1, 2);
    layout->addWidget(displayLabel, 1, 1);

    // Connect button signals to slots for functionality
    connect(upButton, &QPushButton::clicked, this, &CustomWidget::onUpButtonClicked);
    connect(downButton, &QPushButton::clicked, this, &CustomWidget::onDownButtonClicked);
    connect(leftButton, &QPushButton::clicked, this, &CustomWidget::onLeftButtonClicked);
    connect(rightButton, &QPushButton::clicked, this, &CustomWidget::onRightButtonClicked);
}

void CustomWidget::onUpButtonClicked() {
    displayLabel->setText("Up");
}

void CustomWidget::onDownButtonClicked() {
    displayLabel->setText("Down");
}

void CustomWidget::onLeftButtonClicked() {
    displayLabel->setText("Left");
}

void CustomWidget::onRightButtonClicked() {
    displayLabel->setText("Right");
}
