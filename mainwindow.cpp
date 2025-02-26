#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <string>
#include <sstream>

// Constructor for the MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button to the slot
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
    ui->firstName->setPlaceholderText("First Name");
    ui->firstName->setStyleSheet(
                "font:italic;"
                "background-color: #444444;"
                "border: 1px solid #666666;"
                 "background-color: #222222;"  // Dark background (light black)
                 "color: white;"                // Text color for user-entered text
                );
    ui->lastName->setPlaceholderText("Last Name");
    ui->lastName->setStyleSheet(
                "font:italic;"
                "background-color: #444444;"
                "border: 1px solid #666666;"
                 "background-color: #222222;"  // Dark background (light black)
                 "color: white;"                // Text color for user-entered text
                );
    ui->password->setPlaceholderText("Password");
    ui->password->setStyleSheet(
                "font:italic;"
                "background-color: #444444;"
                "border: 1px solid #666666;"
                 "background-color: #222222;"  // Dark background (light black)
                 "color: white;"                // Text color for user-entered text
                );
    ui->birthDate->setPlaceholderText("Birth Date eg:YYYY/MM/DD");
    ui->birthDate->setStyleSheet(
                "font:italic;"
                "background-color: #444444;"
                "border: 1px solid #666666;"
                 "background-color: #222222;"  // Dark background (light black)
                 "color: white;"                // Text color for user-entered text
                );
    ui->label->setStyleSheet(
                "    font-size: 32px;"
                "    color: white;"
                "    font-weight: bold;"
                );
    ui->entropyLabel->setStyleSheet(
                "    color: white;"
                );
    ui->calculateButton->setStyleSheet(
                "QPushButton {"
                        "    background-color: #222222;"  /* Dark gray-black background */
                        "    color: white;"                /* White text color */
                        "    border: 5px solid white;"     /* Thin white border */
                        "    border-radius: 25px;"         /* Rounded corners (more rectangular) */
                        "    padding: 10px;"          /* Padding inside the button (larger for a more rectangular shape) */
                "    width: 200px;"                // Width of the button (make it wider)
                      "    height: 60px;"                // Height of the button (smaller height for oval)
                        "    font-size: 16px;"             /* Font size for the text */
                        "}"
                        "QPushButton:hover {"
                        "    background-color: #444444;"  /* Lighter gray on hover */
                        "    border: 5px solid #AAAAAA;"  /* Change border color on hover */
                "    border-radius: 25px;"         /* Rounded corners (more rectangular) */
                "    padding: 10px;"
                "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for button click
void MainWindow::on_calculateButton_clicked() {
    // Retrieve inputs from the QLineEdit widgets (input fields)
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString birthDate = ui->birthDate->text();
    QString password = ui->password->text();

    // Calculate entropy based on the input fields
    int entropy = calculateEntropy(firstName, lastName, password);

    // Display the result in the QLabel widget
    std::stringstream result;
    result << "Entropy Score: " << entropy;
    ui->entropyLabel->setText(QString::fromStdString(result.str()));
}

// Function to calculate entropy based on the input lengths (you can expand this logic)
int MainWindow::calculateEntropy(const QString &firstName, const QString &lastName, const QString &password) {
    int entropy = 0;

    if (firstName.length() >= 3) entropy += 2;
    if (lastName.length() >= 3) entropy += 2;
    if (password.length() >= 8) entropy += 4;

    return entropy;
}
