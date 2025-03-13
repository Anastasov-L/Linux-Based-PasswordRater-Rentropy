#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <QPainterPath>
#include <QPainter>
#include <QPainterPath>
#include <QRegion>
#include <QMouseEvent>
#include "mainwindow.h"


// Constructor for the MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(426, 651);  // Prevent resizing
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); // Remove standard window frame but keep buttons
    ui->setupUi(this);

    setStyleSheet(
            "QMainWindow {"
            "background-color: #222222;"  // Explicitly setting transparent background
            "    border: 4px solid #333333;"      // Bottom border style (similar to title bar)
            "}"
        );

    QPainterPath path;
    path.addRoundedRect(this->rect(), 20, 20);  // Adjust 20,20 for smoother corners
    QRegion mask(path.toFillPolygon().toPolygon());
    setMask(mask);

    // Apply rounded corners mask
       QWidget *titleBar = new QWidget(this);
   //    titleBar->setFixedHeight(60);
       titleBar->setFixedSize(425,30);
       titleBar->setStyleSheet("background-color: #333333;");
       titleBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Make it expand across the width

       QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
       titleLayout->setContentsMargins(5, 5, 5, 5);
       titleLayout->setSpacing(10); // Add spacing between buttons
       // Create the label for the title text
           QLabel *titleLabel = new QLabel("Entropy Calculator", this);
           titleLabel->setStyleSheet(
               "font-size: 20px; "
               "color: white; "
               "font-weight: bold;"
               "background-color: transparent;"  // Explicitly setting transparent background
           );
       titleLabel->move(titleLabel->x() + 5, titleLabel->y() + 5);
       titleLabel->setFixedWidth(300);
       QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
       QPushButton *minimizeButton = new QPushButton("-");
       QPushButton *closeButton = new QPushButton("X");

       minimizeButton->setStyleSheet("background-color: #555555; color: white; border: none; padding: 5px;");
       closeButton->setStyleSheet("background-color: red; color: white; border: none; padding: 5px;");

       connect(minimizeButton, &QPushButton::clicked, this, &MainWindow::showMinimized);
       connect(closeButton, &QPushButton::clicked, this, &MainWindow::close);

       titleLayout->addItem(spacer);  // Add spacer first
       titleLayout->addWidget(minimizeButton);
       titleLayout->addWidget(closeButton);

       QVBoxLayout *mainLayout = new QVBoxLayout(this);
       mainLayout->setContentsMargins(0, 0, 0, 0);
       mainLayout->addWidget(titleBar);

    // Connect the button to the slot
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
    ui->verticalLayout->setSpacing(20);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
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

    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString birthDate = ui->birthDate->text();
    QString password = ui->password->text();

    double entropy = calculateEntropy(firstName, lastName, password);
    std::stringstream result;

    if(entropy == 0.0){
        result << "Please enter all credentials";
    }else{
        result.precision(2);
        result << std::fixed << std::setprecision(2) << "Entropy Score: " << entropy;
    }

    ui->entropyLabel->setText(QString::fromStdString(result.str()));
}

// Function to calculate entropy based on the input lengths
double MainWindow::calculateEntropy(const QString &firstName, const QString &lastName, const QString &password) {
    if(firstName.size()<1 || lastName.size()<1 || password.size()<1){
        return 0.0;
    }
    double entropy = 1.0;
    int goal1 = firstName.size(); // goal variable for each name ->  if we get to goal variable we have a name present in password
    int goal2 = lastName.size();
    int curr1 = 0;
    int curr2 = 0;
    std::vector<QChar> container;
    double hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0, hasName = 0;
    //does it contain name?
    int backer;


    int itr=0;
    for (const QChar &ch : password) {

            if(password.at(itr) == firstName.at(curr1)){
                curr1++;
            }else{
                curr1 = 0;
            }

            if(password.at(itr) == lastName.at(curr2)){
                curr2++;
            }else{
                curr2 = 0;
            }



            if (ch.isLower()) hasLower++;
            else if (ch.isUpper()) hasUpper++;
            else if (ch.isDigit()) hasDigit++;
            else hasSpecial++;

            itr++;

            if(curr1 == goal1 || curr2 == goal2){  // password contains either name or lastName
                hasName++;
               if(curr2 == goal2){
                   backer = lastName.size();
                   curr2 = 0;
               }else{
                   backer = firstName.size();
                   curr1 = 0;
               }

               for(int i = itr - backer; i < itr; i++){ // removing entropy from password due to the name being present
                   if(password.at(i).isDigit()){
                       hasDigit--;
                   }else if(password.at(i).isUpper()){
                       hasUpper--;
                   }else if(password.at(i).isLower()){
                       hasLower--;
                   }else {
                       hasSpecial--;
                   }
               }


            }
        }




            if (hasLower > 0) entropy *= pow(26.0, hasLower);    // final entropy calculations for now
            if (hasUpper > 0) entropy *= pow(26.0, hasUpper);
            if (hasDigit > 0) entropy *= pow(10.0, hasDigit);
            if (hasSpecial > 0) entropy *= pow(32.0, hasSpecial);
            if (hasName > 0) entropy += 1.0;


    return log2(static_cast<double>(entropy));
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - lastMousePosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    isDragging = false;
    event->accept();
}
