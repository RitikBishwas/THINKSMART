#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "global.h"
#include <stdio.h>

void setValues(Question *q, char qt[], char a1[], char a2[], char a3[], char a4[], int ca, int pa, int s1, int s2, char h[]);
void setQuestions(int n , int diff);
void askQuestion(Question *q);
void setScore(FILE *file, int score, char *name, float time);
void random_Qnumber();
int compareStudents(const void *s1, const void *s2);
void leaderboard(FILE *file, Student students[], int *numOfPlayers, int score, char *name, float time);

#endif