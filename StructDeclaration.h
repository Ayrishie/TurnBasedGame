#include <stdio.h>

struct Player
{
        int nPlayerHealth;
        int nPlayerDefense;
        int nPlayerAttack;
        int nPlayerMaxhealth;
        int nPlayerMaxdefense;
        int nPlayerExperience;
        int nPlayerMaxExperience;
};

struct Enemy
{

        int nEnemyHealth;
        int nEnemyDefense;
        int nEnemyAttack;
        int nEnemyMaxhealth;
        int nExperiencePoints;

};

struct Inventory
{
        int nActiveOne;
        int nActiveTwo;
        int nActiveThree;
        int nSword; 
        int nHealthPotion;
        int nArmor;
};

void nStatsPlayer(struct Player *nMainCharacter)
{
    nMainCharacter->nPlayerMaxhealth = 100;
    nMainCharacter->nPlayerMaxdefense = 100;
    nMainCharacter->nPlayerMaxExperience = 800;
}

void nStatsColonist(struct Enemy *nColonist)
{
        nColonist->nEnemyHealth = 70;
        nColonist->nEnemyMaxhealth = 70;
        nColonist->nExperiencePoints = 180;
}

void nStatsChicken(struct Enemy *nChicken)
{
        nChicken->nEnemyHealth = 30;
        nChicken->nEnemyMaxhealth = 30;
        nChicken->nExperiencePoints = 90;
}

void nStatsSnake(struct Enemy *nSnake)
{
        nSnake->nEnemyHealth = 50;
        nSnake->nEnemyMaxhealth = 50;  
        nSnake->nExperiencePoints = 120;
}


void nStatsFinalBoss(struct Enemy *nAmerikano)
{
        nAmerikano->nEnemyHealth = 200;
        nAmerikano->nEnemyMaxhealth = 200;
}

