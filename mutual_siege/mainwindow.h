#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>

#include "castle.h"
#include "card.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    constexpr static unsigned CARDS = 8;
    static unsigned long long round_counter;

    Ui::MainWindow *ui;
    Castle player1{}, player2{};
    Castle* player;
    Castle* enemy;
    std::vector <QToolButton*> buttons;


    void update_castles_stats(Castle* = nullptr);
    std::vector<Card*> make_deck();



private slots:
    void use_card();


};
#endif // MAINWINDOW_H
