#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include <time.h>

using namespace std;



void gotoxy(int x, int y);
void balance(int bal);

void topUp(int *bal);
void play(int* bal);
void win(int* bal);