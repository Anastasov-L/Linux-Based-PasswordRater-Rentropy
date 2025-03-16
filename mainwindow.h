// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void on_calculateButton_clicked();  // Slot for Calculate but

private:
    Ui::MainWindow *ui;
    bool isDragging;       // Track if mouse is pressed
    QPoint lastMousePosition;  // Store last mouse position
    // Declare the calculateEntropy function here
    double calculateEntropy(const QString &firstName, const QString &lastName, const QString &password, const QString &birthDate);
    double checkValidity(const QString firstName, const QString lastName, const QString password, const QString birthDate);
    void checkContents(int &itr, const QString &password, const QString &firstName, const QString &lastName, const QString birthD, const QString birthM,const QString birthY,const QString birthLY,const QString birthDT, int &curr1, int &curr2, int &currY, int &currLY, int &currD, int &currM, int &currDT);
    void passwordContains(int &itr, const QString &password, const QString &firstName, const QString &lastName, const QString &birthD, const QString &birthM, const QString &birthY,const QString &birthLY, int &curr1, int &curr2, int &currD, int &currM, int &currY, int &currLY, double &hasFN, double &hasLN, int &backer, int &goal1, int &goal2, int &goalD, int &goalM, int &goalY, int &goalLY, double &hasDigit, double &hasUpper, double &hasLower, double &hasSpecial, double &hasBirthD, double &hasBirthM, double &hasBirthY, double &hasBirthLY);
};

#endif // MAINWINDOW_H
