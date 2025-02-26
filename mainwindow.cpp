// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button to the slot
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
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
