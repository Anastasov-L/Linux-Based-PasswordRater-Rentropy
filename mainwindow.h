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
    double calculateEntropy(const QString &firstName, const QString &lastName, const QString &password);
};

#endif // MAINWINDOW_H
