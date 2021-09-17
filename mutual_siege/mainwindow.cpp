#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "castle.h"
#include "card.h"
#include "attackcard.h"

#include <QCursor>
#include <QMouseEvent>
#include <QPixmap>
#include <qpainter.h>
#include <QScreen>
#include <QSlider>
#include <QToolButton>


#include <thread>
#include <algorithm>
#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>


unsigned long long MainWindow::round_counter = 1;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto main_pic_height = ui->MainPicture->height();
    auto main_pic_width  = ui->MainPicture->width();
    ui->MainPicture->setPixmap(QPixmap("../pictures/background_map.png").scaled(main_pic_width, main_pic_height, Qt::KeepAspectRatio));


    player1.get_cards() = make_deck();
    player2.get_cards() = make_deck();
    buttons.resize(CARDS);
    QString button_prefix = "card";
    QString button_sufix = "_button";
    for (auto i = 0u; i < 8u; ++i) {

        QString button_name = button_prefix + QString::number(i + 1) + button_sufix;
        buttons[i] = MainWindow::findChild<QToolButton*>(button_name);
        buttons[i]->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        buttons[i]->setIcon(QIcon(QPixmap(QString("../pictures/") + QString::fromStdString( player1.get_cards()[i]->get_icon_name() ))));
        connect(buttons[i], SIGNAL(pressed()), this, SLOT(use_card()));

    }

    update_castles_stats();
    player = &player1;
    enemy = &player2;
}



void MainWindow::use_card(){
    QString button_prefix = "card";
    QString button_sufix = "_button";
    for (auto i = 0u; i < 8u; ++i) {
        QString button_name = button_prefix + QString::number(i + 1) + button_sufix;
        auto* button = MainWindow::findChild<QToolButton*>(button_name);
        if(button->isDown()){
            if( (*player->get_cards()[i])(*player, *enemy) ){
                ++round_counter;
                update_castles_stats(enemy);
                Castle* tmp_castle_ptr = player;
                player = enemy;
                enemy = tmp_castle_ptr;
                return;
            }
            else{
                return;
            }
        }
    }

}

void MainWindow::update_castles_stats(Castle* enemy_castle){
    QString round_info_sufix = {" Player turn"};
    if(round_counter % 2){
        ui->player_round->setText(QString("First") + round_info_sufix);
    }
    else{
        ui->player_round->setText(QString("Second") + round_info_sufix);
    }

    if(enemy_castle){
        enemy_castle->update_supplies();
    }


    ui->castle1_hp_field->setText(QString::number(player1.get_hp()));
    ui->castle1_weapons_field->setText(QString("Owned: ") + QString::number(player1.get_weapons()) + QString("\nIncome: ") + QString::number(player1.get_weapons_inc()));
    ui->castle1_magic_field->setText(QString("Owned: ") + QString::number(player1.get_magic()) + QString("\nIncome: ") + QString::number(player1.get_magic_inc()));
    ui->castle1_bricks_field->setText(QString("Owned: ") + QString::number(player1.get_bricks()) + QString("\nIncome: ") + QString::number(player1.get_bricks_inc()));

    ui->castle2_hp_field->setText(QString::number(player2.get_hp()));
    ui->castle2_weapons_field->setText(QString("Owned: ") + QString::number(player2.get_weapons()) + QString("\nIncome: ") + QString::number(player2.get_weapons_inc()));
    ui->castle2_magic_field->setText(QString("Owned: ") + QString::number(player2.get_magic()) + QString("\nIncome: ") + QString::number(player2.get_magic_inc()));
    ui->castle2_bricks_field->setText(QString("Owned: ") + QString::number(player2.get_bricks()) + QString("\nIncome: ") + QString::number(player2.get_bricks_inc()));
}

std::vector<Card*> MainWindow::make_deck(){
    std::vector<Card*> deck(7, new AttackCard(5,2));
    deck.push_back(new ConstructCard(1, 1));
    return deck;
}

MainWindow::~MainWindow()
{
    delete ui;
}

