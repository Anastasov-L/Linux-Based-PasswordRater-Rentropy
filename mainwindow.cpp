#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "raddix.h"  
#include <QString>
#include <QMessageBox>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <QPainterPath>
#include <QPainter>
#include <QRegion>
#include <QMouseEvent>
#include <QDir>
#include <QDebug>

// Constructor for the MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),radixTree(),
    ui(new Ui::MainWindow)
{
    qDebug() << "Current working directory:" << QDir::currentPath();

    loadCsvIntoRadixTree("../data/unigram_freq.csv", radixTree);
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
       titleBar->setFixedSize(425,30);
       titleBar->setStyleSheet("background-color: #333333;");
       titleBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Make it expand across the width

       QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
       titleLayout->setContentsMargins(5, 5, 5, 5);
       titleLayout->setSpacing(10); // button spacing
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

    QString commonStyle =
        "font: italic;"
        "background-color: #222222;"  // Dark background (light black)
        "border: 1px solid #666666;"
        "color: white;";

    ui->firstName->setStyleSheet(commonStyle);

    ui->lastName->setPlaceholderText("Last Name");
    ui->lastName->setStyleSheet(commonStyle);
    ui->password->setPlaceholderText("Password");
    ui->password->setStyleSheet(commonStyle);
    ui->birthDate->setPlaceholderText("Birth Date eg:DD/MM/YYYY");
    ui->birthDate->setStyleSheet(commonStyle);
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
                        "    background-color: #222222;"   /* Dark gray-black background */
                        "    color: white;"                /* White text color */
                        "    border: 5px solid white;"     /* Thin white border */
                        "    border-radius: 25px;"         /* Rounded corners (more rectangular) */
                        "    padding: 10px;"               /* Padding inside the button (larger for a more rectangular shape) */
                        "    width: 200px;"                // Width of the button (make it wider)
                        "    height: 60px;"                // Height of the button (smaller height for oval)
                        "    font-size: 16px;"             /* Font size for the text */
                        "}"
                        "QPushButton:hover {"
                        "    background-color: #444444;"   /* Lighter gray on hover */
                        "    border: 5px solid #AAAAAA;"   /* Change border color on hover */
                        "    border-radius: 25px;"         /* Rounded corners (more rectangular) */
                        "    padding: 10px;"
                "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked() {

    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString birthDate = ui->birthDate->text();
    QString password = ui->password->text();

    double entropy = calculateEntropy(firstName, lastName, password, birthDate);
    std::stringstream result;

    if(entropy == -1.0){
        result << "Please enter all credentials";
    }else if(entropy == -2.0){
        result << "Password must be at least 8 chars";
    }else{
        result.precision(2);
        result << std::fixed << std::setprecision(2) << "Entropy Score: " << entropy;
    }

    ui->entropyLabel->setText(QString::fromStdString(result.str()));
}

void MainWindow::checkContents(int &itr,  QString &password, const QString &firstName, const QString &lastName,const QString birthD, const QString birthM,const QString birthY,const QString birthLY,const QString birthDT,  int &curr1, int &curr2, int &currY, int &currLY, int &currD, int &currM, int &currDT){

    if(password.at(itr) == firstName.at(curr1)){  // check if password is on track to contain firstName
        curr1++;
    }else{
        curr1 = 0;
    }

    if(password.at(itr) == lastName.at(curr2)){  // check if password is on track to contain lastName
        curr2++;
    }else{
        curr2 = 0;
    }

    if(password.at(itr) == birthY.at(currY)){  // check if password is on track to contain birthYear
        currY++;
    }else{
        currY = 0;
    }

    if(password.at(itr) == birthLY.at(currLY)){  // check if password is on track to contain birthLastYear
        currLY++;
    }else{
        currLY = 0;
    }

    if(password.at(itr) == birthD.at(currD)){  // check if password is on track to contain birthDay
        currD++;
    }else{
        currD = 0;
    }

    if(password.at(itr) == birthM.at(currM)){  // check if password is on track to contain birthMonth
        currM++;
    }else{
        currM = 0;
    }

}

void MainWindow::passwordContains(int &itr,  QString &password, const QString &firstName, const QString &lastName, const QString &birthD, const QString &birthM, const QString &birthY,const QString &birthLY, int &curr1, int &curr2, int &currD, int &currM, int &currY, int &currLY, double &hasFN, double &hasLN, int &backer, int &goal1, int &goal2, int &goalD, int &goalM, int &goalY, int &goalLY, double &hasDigit, double &hasUpper, double &hasLower, double &hasSpecial, double &hasBirthD, double &hasBirthM, double &hasBirthY, double &hasBirthLY, std::vector<int>&index, std::vector<int>&size){

    if(curr1 == goal1 || curr2 == goal2 || currD == goalD || currM == goalM || currY == goalY || currLY == goalLY){  // password contains personal data

       if(curr2 == goal2){  // what type of data
           hasLN++;
           backer = lastName.size();
           curr2 = 0;
       }
       if(curr1 == goal1){
           hasFN++;
           backer = firstName.size();
           curr1 = 0;
       }
       if(currD == goalD){
           hasBirthD++;
           backer = birthD.size();
           currD = 0;
       }
       if(currM == goalM){
           hasBirthM++;
           backer = birthM.size();
           currM = 0;
       }
       if(currY == goalY){
           hasBirthY++;
           backer = birthY.size();
           currY = 0;
       }else if(currLY == goalLY){
           hasBirthLY++;
           backer = birthLY.size();
           currLY = 0;
       }

       for(int i = itr - (backer - 1); i <= itr; i++){ // removing previous entropy points from password because of present personal information (non random choice)
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
       index.push_back(itr - (backer-1));
       size.push_back(itr);
       qDebug() << itr - (backer-1) << " " << itr ;
    }                             // end of password contains epersonal data
}

double MainWindow::checkValidity(const QString firstName, const QString lastName, const QString password, const QString birthDate){
    if(firstName.size() < 1 || lastName.size() < 1 || password.size() < 1 || birthDate.size() < 1){
        return -1.0;
    }//else if(password.size()<8){
     //   return -2.0;
   // }
    return 0.0;
}
double MainWindow::calculateEntropy(const QString &firstName, const QString &lastName, const QString &password, const QString &birthDate) {
   double valid = checkValidity(firstName, lastName, password, birthDate);
   QString passwordM = password;
    if(valid!=0){
        return valid;
    }

   const QString birthD = QString(birthDate.at(0)) + birthDate.at(1);
   const QString birthM = QString(birthDate.at(3)) + birthDate.at(4);
   const QString birthDT = QString(birthDate.at(0)) + birthDate.at(1) + birthDate.at(3) + birthDate.at(4);
   const QString birthY = QStringLiteral("%1%2%3%4").arg(birthDate.at(6)).arg(birthDate.at(7)).arg(birthDate.at(8)).arg(birthDate.at(9));
   const QString birthLY = QStringLiteral("%1%2").arg(birthDate.at(8)).arg(birthDate.at(9));

    double entropy = 1.0;
    int goal1 = firstName.size(); // goal variable for each name ->  if we get to goal variable we have a name present in password
    int goal2 = lastName.size();
    int goalD = 2;
    int goalM = 2;
    int goalY = 4;
    int goalLY = 2;

    int curr1 = 0;//current name counter
    int curr2 = 0;//current lastName counter
    int currY = 0;
    int currLY = 0;
    int currD = 0;
    int currM = 0;
    int currDT = 0;
    double hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0, hasFN = 0, hasLN = 0, hasBirthY = 0, hasBirthLY = 0, hasBirthD = 0, hasBirthM = 0;
    int backer;


    int itr=0; // iterator
    std::vector<int>index;
    std::vector<int>size;
    for (int itr = 0; itr < passwordM.size(); ++itr) {
        const QChar &ch = passwordM.at(itr); 
            checkContents(itr, passwordM, firstName, lastName, birthD, birthM, birthY, birthLY, birthDT, curr1, curr2, currY, currLY, currD, currM, currDT);

            if (ch.isLower()) hasLower++;             // add symbol count bas
            else if (ch.isUpper()) hasUpper++;
            else if (ch.isDigit()) hasDigit++;
            else hasSpecial++;

            

            passwordContains(itr, passwordM, firstName, lastName, birthD, birthM, birthY, birthLY, curr1, curr2, currD, currM, currY, currLY, hasFN, hasLN, backer, goal1, goal2, goalD, goalM, goalY, goalLY, hasDigit, hasUpper, hasLower, hasSpecial, hasBirthD, hasBirthM, hasBirthY, hasBirthLY, index, size);
            
            
        }

         



        const std::string find = passwordM.toStdString();
       //
         std::vector<std::tuple<std::string, int, int>> words  = radixTree.contains_known_words(find, index, size);
      // if(radixTree.search(find)==-1){  
        const double max_frequency = 23135851162.0;
       if(words.size()==0){    // no words in password
               
            }else { // Words are present in the password

                for (const auto& triplet : words) {
                    std::string foundWord = std::get<0>(triplet);  // Extract word
                    int wordFrequency = std::get<1>(triplet);      // Extract frequency
                    int startIndex = std::get<2>(triplet);      // Extract starting index
            
                    if (wordFrequency > 0) {
                        entropy *= log2(1 + max_frequency / wordFrequency);
                    }

                    for (int i = startIndex; i < startIndex + foundWord.length(); ++i) {
                        if ((passwordM.at(i).isDigit())) hasDigit--;      // Decrement digit counter
                     else if ((passwordM.at(i).isLower())) hasLower--; // Decrement lowercase counter
                        else if ((passwordM.at(i).isUpper())) hasUpper--; // Decrement uppercase counter
                        else hasSpecial--;                              // Decrement special character counter
                    }
                    
                }
            }
    qDebug() << "hasFN: " << hasFN << " hasLN: " << hasLN << "firstname:" << firstName << "lastname:" << lastName << " " << hasLower << " " << hasUpper << " " <<hasDigit << " "<< hasBirthD << " " <<hasBirthM << " "<< hasBirthY << " "<< hasBirthLY << " ";
                if (hasLower > 0) entropy *= pow(26.0, hasLower);                           // final entropy calculations for now
                if (hasUpper > 0) entropy *= pow(26.0, hasUpper);
                if (hasDigit > 0) entropy *= pow(10.0, hasDigit);
                if (hasSpecial > 0) entropy *= pow(32.0, hasSpecial);
                if (hasFN > 0) entropy *= 1;               
                if (hasLN > 0) entropy *= 1;
                if (hasBirthD>0) entropy *= password.size() - birthD.size() + 1;
                if (hasBirthM>0) entropy *= password.size() - birthM.size() + 1;
                if (hasBirthY>0) entropy *= password.size() - birthY.size() + 1;
                if (hasBirthLY>0) entropy *= password.size() - birthLY.size() + 1;



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
