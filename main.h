//
// Created by ashkore on 23-6-13.
//

#ifndef CHROME_DINO_NCURSES_MAIN_H
#define CHROME_DINO_NCURSES_MAIN_H

#endif //CHROME_DINO_NCURSES_MAIN_H
// Dino struct
typedef struct {
    double X;
    int Y;
    int length;
    int height;
} Dino;

// Obstacle struct
typedef struct {
    int ID;
    double X;
    int Y;
    int length;
    int height;
} Obstacle;

// Background struct
typedef struct {
    int ID;
    double X;
    int Y;
    double speed;
    int RandRange_X;
    int RandRange_Y;
    int RandOffset_X;
    int RandOffset_Y;
} Background;