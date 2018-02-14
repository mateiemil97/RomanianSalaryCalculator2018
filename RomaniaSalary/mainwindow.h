#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    double mGetAsigurareSanatate() const;
    double mGetAsigurareSociala() const;
    double mGetImpozitVenit() const;
    double mGetSalariuNet() const;
    double mGetDeducerePersoane() const;
    double mGetWage() const;

    void mSetAsigurareSanatate() ;
    void mSetAsigurareSociala() ;
    void mSetImpozitVenit();
    void mSetSalariuNet() ;
    void mSetDeducerePersoane() ;
    void mSetWage(double);

private slots:
    void on_pushButtonCalculeaza_clicked();

private:
    Ui::MainWindow *ui;
    double mWage;
    int mNumberofPersons;
    double mAsigurareSanatate, mAsigurareSociala;
    double mImpozitVenit;
    double mSalariuNet;
    double mDeducerePersoane;
    double mDeducereSpeciala;
    QString persons;
};

#endif // MAINWINDOW_H
