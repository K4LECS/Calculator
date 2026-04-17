#include "mainwindow.h"
#include <QVBoxLayout>
#include <QGridLayout>

void MainWindow::onButtonClicked() {
    // Figure out which button was clicked
    QPushButton *clicked = qobject_cast<QPushButton*>(sender());
    QString label = clicked->text();

    if (label == "C") {
        display->clear();
    } else if (label == "=") {
        try {
            Calculator calc;
            std::string expression = display->text().toStdString();
            double result = calc.evaluate(expression);

            // Show the result back on the display
            display->setText(QString::number(result));
        } catch (std::exception &e) {
            display->setText("Error");
        }
    } else {
        // Append the button's label to the display
        display->setText(display->text() + label);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Calculator");
    setFixedSize(300,400);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(60);

    mainLayout->addWidget(display);

    const char *labels[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+"
    };

    QGridLayout *gridLayout = new QGridLayout();

    for (int i = 0; i < 16; i++) {
        buttons[i] = new QPushButton(labels[i], this);
        buttons[i]->setFixedSize(60, 60);

        int row = i / 4;  // which row (0-3)
        int col = i % 4;  // which column (0-3)

        gridLayout->addWidget(buttons[i], row, col);
        connect(buttons[i], &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    }

    // Add the grid into the main vertical layout
    mainLayout->addLayout(gridLayout);
}

MainWindow::~MainWindow() {}
