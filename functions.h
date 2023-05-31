#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "StructDeclaration.h"

//not important 
int StartUpMenu(int nDecisionOne);
void vAbout();
void vPrintTitle();
void DisplayUnderscore();
void DisplayNewLine();
void DisplayAsterisk();
void DisplayEquals();
void DisplaySemiColon();
void DisplayHashtag();
void vGameIntroduction();
void ChapterTwoStory(char *nNameCharacter);
void ChapterThreeStory(char *nNameCharacter);
void ChapterFourStory(char *nNameCharacter);
void ChapterFiveStory(char *nNameCharacter);
void ChapterSixStory(char *nNameCharacter);
void ChapterSevenStory(char *nNameCharacter);
void ChapterEightStory(char *nNameCharacter);
void ChapterBossSection(char *nNameCharacter);
void GameWonButLoss(char *nNameCharacter);
void Fleeing();

//needed
void nRamdomATTKNumbEasy(int *nRamdomNum);
void nRamdomATTKRangeEasy(int *intnRamdomRange);
void cName(char *nNameCharacter);
void DisplayPlus();
void nPlayerMenu(struct Player *nMainCharacter);
void GameEndLoss(char *nNameCharacter);
void nInventory(int nPassInven, struct Inventory *nMCInventory);
void GameWon(char *nNameCharacter);
int nAttackChoices();
int nItems(struct Inventory *nMCInventory);
int nChoosePlace();
int nAttackChoices();



//important
void nRest(struct Player *nMainCharacter);

void nAliveOrDead(struct Enemy *nColonist, struct Enemy *nChicken, 
                  struct Enemy *nSnake, struct Player *nMainCharacter, 
                  struct Enemy *nAmerikano,  int *nEndGame, int nKey, 
                  char *nNameCharacter, struct Inventory *nMCInventory);

int nHomeChoices(struct Player *nMainCharacter, struct Enemy *nColonist,
                  struct Enemy *nChicken, struct Enemy *nSnake, int 
                  *nDifficulty, struct Enemy*nAmerikano,struct Inventory 
                  *nMCInventory);

int nBattleTakesPlace(struct Player *nMainCharacter, struct Enemy *nColonist, struct Enemy 
                      *nChicken, struct Enemy *nSnake, int nPlaceChoices, int *nDifficulty,
                      struct Enemy *nAmerikano, struct Inventory *nMCInventory);
          
void nEnemyATTK(struct Player *nMainCharacter, int *nRamdomNum, 
                int *nRamdomRange, int *nDifficulty, int nCounterRandom);

int nChaptersOfStory(int *nChapters, struct Player *nMainCharacter, int *nDifficulty);

int nGameBattle(int *nNumToActivate, struct Player *nMainCharacter, 
                struct Enemy *nColonist, struct Enemy *nChicken, 
                struct Enemy *nSnake, int *nDifficulty, struct Enemy 
                *nAmerikano, struct Inventory *nMCInventoryy);

int nLearning(struct Player *nMainCharacter);

void nPlayerATTK(struct Enemy *nColonist,struct Enemy *nChicken,
                 struct Enemy *nSnake, int *nRamdomNum, int 
                 *nRamdomRange, struct Enemy *nAmerikano,
                 int nNumberEnemy);

int EndGameBoss(struct Enemy *nColonist,struct Enemy *nChicken,
                struct Enemy *nSnake, struct Enemy *nAmerikano, 
                struct Player *nMainCharacter, struct Inventory 
                *nMCInventory);


//game

// a function that is used to display the start up menu.
int 
StartUpMenu(int nDecisionOne)
{

    do
    {
      scanf("%d", &nDecisionOne);
    }while(nDecisionOne != 1 && nDecisionOne != 2
           && nDecisionOne != 3);
 
    //starts the game
    if(nDecisionOne == 1 )
    {
      
      return 1;  
    }
    //info about the game
    else if(nDecisionOne == 2)
    {
      return 2;
    }
    //exits
    else if (nDecisionOne == 3)
    {
      printf("\n[EXITING THE GAME]\n");
      printf("\n[GAME CLOSES]\n");
      return 0;
    }

  return 0;
}

// function that is responsible for the story of the game.
int 
nChaptersOfStory(int *nChapters, struct Player *nMainCharacter, int *nDifficulty)
{
  // variable declaration and initialization
  int   nKey = 0,
        nEndGame = 1,
        DefeatOrNot = 0;

  char  nNameCharacter; 

  struct Enemy nColonist;
      nStatsColonist(&nColonist);

  struct Enemy nChicken;
      nStatsChicken(&nChicken);

  struct Enemy nSnake;
      nStatsSnake(&nSnake);

  struct Enemy nAmerikano;
      nStatsFinalBoss(&nAmerikano);

  struct Inventory nMCInventory;
     
  
 /*
  Checking if the value of nChapters is less than or equal and greater than 
  or equal to the required number per chapters. If it is, then certain story 
  lines will only be allowed to play in specific chapers. However, difficulty
  is increased per chapters as well. 
*/
  //1st chapter
  if(*nChapters <= 3 && *nChapters >= 1)
  {
    //Displays the Game's inroduction and ask for the player's name
    if(*nChapters == 1)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 1~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      vGameIntroduction();
      cName(&nNameCharacter); 
    }

    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    if(*nChapters == 3)
    {
      *nDifficulty += 1; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  //2nd Chapter
  else if(*nChapters <= 6 && *nChapters >= 4)
  {
    if(*nChapters == 4)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 2~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterTwoStory(&nNameCharacter);
    } 
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment

    //if nChapters is 6,  enemy difficulty is increase and player health
    if(*nChapters == 6)
    {
      *nDifficulty += 1; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
      
  }
  // 3rd Chapter
  else if(*nChapters <= 9  && *nChapters >= 7)
  {
    if(*nChapters == 7)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 3~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterThreeStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    //if nChapters is 9,  enemy difficulty is increase and player health
    if(*nChapters == 9)
    {
      *nDifficulty += 1; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  // 4th chapter
  else if(*nChapters <= 12  && *nChapters >= 10)
  {
    if(*nChapters == 10)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 4~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterFourStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    //if nChapters is 12,  enemy difficulty is increase and player health
    if(*nChapters == 12)
    {
      *nDifficulty += 1;  
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  //5th chapter
  else if(*nChapters <= 15  && *nChapters >= 13)
  {
    if(*nChapters == 13)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 5~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterFiveStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    //if nChapters is 15,  enemy difficulty is increase and player health
    if(*nChapters == 15)
    {
      *nDifficulty += 1; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  //6th Chapther
  else if(*nChapters <= 18  && *nChapters >= 16)
  {
    if(*nChapters == 16)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 6~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterSixStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
  
    //if nChapters is 18,  enemy difficulty is increase and player health
    if(*nChapters == 18)
    {
      *nDifficulty += 2; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
   
  }
  //7th chapter
  else if(*nChapters <= 21  && *nChapters >= 19)
  {
    if(*nChapters == 19)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 7~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterSevenStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    //if nChapters is 21,  enemy difficulty is increase and player health
    if(*nChapters == 21)
    {
      *nDifficulty += 2; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  //8th Chapter
  else if(*nChapters <= 24  && *nChapters >= 22)
  {
    if(*nChapters == 22)
    {
      printf("\n\n");
      DisplayUnderscore();
      printf("\n\n\t     :~Chapter 8~:\n\n");
      DisplayUnderscore();
      printf("\n\n\n");
      ChapterEightStory(&nNameCharacter);
    }
    nStatsPlayer(&*nMainCharacter); // calls the stuct for player
    nPlayerMenu(&*nMainCharacter);// shows the health, defense and EXP points of the player
    DefeatOrNot = nHomeChoices(&*nMainCharacter, &nColonist, &nChicken, 
                               &nSnake, nDifficulty, &nAmerikano, 
                               &nMCInventory); // asks for the user's inputs
    *nChapters+=1;// increment
    
    //if nChapters is 24,  enemy difficulty is increase and player health 
    if(*nChapters == 3)
    {
      *nDifficulty += 2; 
      nMainCharacter->nPlayerHealth += 10;
    }
    if(DefeatOrNot == 1)
    {
      printf("\n\n[You have died, your journey stops.]\n\n");
      return nEndGame;
    }
    
  }
  else 
  {
    nKey = 1;// nKey is initialized
    nAliveOrDead(&nColonist, &nChicken,&nSnake, 
                 &*nMainCharacter,&nAmerikano,&nEndGame, 
                 nKey, &nNameCharacter, &nMCInventory); 

    return nEndGame;

  }
  
  return 1;
}

/*
  Function that gives out math problems to the player,
  EXP points will be rewarded and wrong answers will be penalized
*/
int
nLearning(struct Player *nMainCharacter)
{
   // variable declaration and initialization
  int   nRand,
        nMathOne,
        nMathTwo,
        nPlayerAnswer,
        nGameAnswer,
        ExperiencePoints = 0; 

  nStatsPlayer(&*nMainCharacter);//calling of stuct character

  srand(time(NULL));
  nRand = rand() % 8;//radomization
  printf("\n\n[SHHH!]\n\n");
  printf("[You Have Discovered an Colonist in Training!]\n\n"); 
  printf("[Watch them carefully to get bonus experience points!]\n");
  printf("\n[MATH QUESTION!]\n\n");
  
  //addition computational question
  if(nRand == 0 || nRand == 1)
  {
    // randomization of numbers        
    nMathOne = rand() % 10;
    nMathTwo = rand() % 20;

    printf(">>> %d + %d: ", nMathOne, nMathTwo);
    scanf("%d", &nPlayerAnswer);
     
    nGameAnswer = nMathOne + nMathTwo;
    
    //if the player has the correct answer, EXP points will be rewarded
    if(nPlayerAnswer == nGameAnswer)
    {
      ExperiencePoints = rand() % 100;
      if(ExperiencePoints > 0)
      {
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += ExperiencePoints;
        printf("[%d EXP Gain!]\n", ExperiencePoints);
      }
      else
      {
        printf("\n[You have won additional experience points!]\n");
        nMainCharacter->nPlayerExperience += 10;
        printf("[%d EXP Gain!]\n", 10);
      }
    }
    //if player has the wrong answer, EXP will be deducted
    else
    {
      ExperiencePoints = rand() % 20;
      printf("[You have been discovered!]\n");
      
      if(nMainCharacter->nPlayerExperience > 0)
      {
        nMainCharacter->nPlayerExperience -= ExperiencePoints;
        printf("[-%d EXP Deduction!]", ExperiencePoints);
      
        // Player's EXP less than 0, it will generate 0 as the default EXP
        if(nMainCharacter->nPlayerExperience <= 0)
        {
          nMainCharacter->nPlayerExperience = 0;
          printf("[-%d EXP Deduction!]", ExperiencePoints);
        }
      }
      else
      {
        nMainCharacter->nPlayerExperience = 0;// displays 0 
        printf("[-%d EXP Deduction!]", ExperiencePoints);
      }         
      
    }
            
  }
  //subtraction computational question
  else if(nRand == 2 || nRand == 3)
  {
    // randomization of numbers
    nMathOne = rand() % 10;
    nMathTwo = rand() % 20;

    printf(">>>%d - %d: ", nMathOne, nMathTwo);
    scanf("%d", &nPlayerAnswer);

    nGameAnswer = nMathOne - nMathTwo;

    //if the player has the correct answer, EXP points will be rewarded
    if(nPlayerAnswer == nGameAnswer)
    {
      ExperiencePoints = rand() % 130;
      if(ExperiencePoints > 0)
      {
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += ExperiencePoints;
        printf("[%d EXP Gain!]\n", ExperiencePoints);
      }
      else
      {
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += 10;
        printf("[%d EXP Gain!]\n", 10);
      }

    }
    //if player has the wrong answer, EXP will be deducted
    else
    {
      ExperiencePoints = rand() % 20;
      printf("[You have been discovered!]\n");
      
      if(nMainCharacter->nPlayerExperience > 0)
      {
        nMainCharacter->nPlayerExperience -= ExperiencePoints;
        printf("[-%d EXP Deduction!]", ExperiencePoints);
        
        // Player's EXP less than 0, it will generate 0 as the default EXP
        if(nMainCharacter->nPlayerExperience <= 0)
        {
          nMainCharacter->nPlayerExperience = 0;
          printf("[-%d EXP Deduction!]", ExperiencePoints);
        }
      }
      else
      {
        nMainCharacter->nPlayerExperience = 0;// displays 0 
        printf("[-%d EXP Deduction!]", ExperiencePoints);
      }         
      
    }
            
  }
  //multiplication computational question
  else if(nRand == 4 || nRand == 5)
  {
    //randomization of numbers 
    nMathOne = rand() % 10;
    nMathTwo = rand() % 20;

    printf(">>>%d * %d: ", nMathOne, nMathTwo);
    scanf("%d", &nPlayerAnswer);
     
    nGameAnswer = nMathOne * nMathTwo;

    //if the player has the correct answer, EXP points will be rewarded
    if(nPlayerAnswer == nGameAnswer)
    {
      ExperiencePoints = rand() % 160;
      if(ExperiencePoints > 0)
      {        
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += ExperiencePoints;
        printf("[%d EXP Gain!]\n", ExperiencePoints);
      }
      else
      {
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += 10;
        printf("[%d EXP Gain!]\n", 10);
      }

    }
    //if player has the wrong answer, EXP will be deducted
    else
    {
      ExperiencePoints = rand() % 20;
      printf("[You have been discovered!]\n");

      if(nMainCharacter->nPlayerExperience > 0)
      {
        nMainCharacter->nPlayerExperience -= ExperiencePoints;
        printf("[-%d EXP Deduction!]", ExperiencePoints);

        // Player's EXP less than 0, it will generate 0 as the default EXP
        if(nMainCharacter->nPlayerExperience <= 0)
        {
          nMainCharacter->nPlayerExperience = 0;
          printf("[-%d EXP Deduction!]", ExperiencePoints);
        }
          
      }
      else
      {
        nMainCharacter->nPlayerExperience = 0;// displays 0
        printf("[-%d EXP Deduction!]", ExperiencePoints);
      }         
      
    }
            
  }
  //division computational question
  else if(nRand == 6 || nRand == 7)
  {
    //randomization of numbers  
    nMathOne = rand() % 10;
    nMathTwo = rand() % 20;

    printf("\n<REMINDER: No, remainder.>\n");
    printf(">>>%d / %d: ", nMathOne, nMathTwo+1);
    scanf("%d", &nPlayerAnswer);
     
    nGameAnswer = nMathOne / nMathTwo+1;
        
    //if the player has the correct answer, EXP points will be rewarded
    if(nPlayerAnswer == nGameAnswer)
    {      
      ExperiencePoints = rand() % 200;
      if(ExperiencePoints > 0)
      {
        printf("\n[You have won additional experience points!]\n\n");
        nMainCharacter->nPlayerExperience += ExperiencePoints;
        printf("[%d EXP Gain!]\n", ExperiencePoints);

      }
      else
      {
        printf("\n[You have won additional experience points!]\\n");
        nMainCharacter->nPlayerExperience += 10;
        printf("[%d EXP Gain!]\n", 10);

      }

    }
    //if player has the wrong answer, EXP will be deducted
    else
    {
      ExperiencePoints = rand() % 20;
      printf("[You have been discovered!]\n");

      if(nMainCharacter->nPlayerExperience > 0)
      {
        nMainCharacter->nPlayerExperience -= ExperiencePoints;
        printf("[-%d EXP Deduction!]", ExperiencePoints);
        
        // Player's EXP less than 0, it will generate 0 as the default EXP
        if(nMainCharacter->nPlayerExperience <= 0)
        {
          nMainCharacter->nPlayerExperience = 0;
          printf("[-%d EXP Deduction!]", ExperiencePoints);
        }
          
      }
      else
      {
        nMainCharacter->nPlayerExperience = 0;// displays 0
        printf("[-%d EXP Deduction!]", ExperiencePoints);
      }         
      
    }
            
  } 
    
    return 0;

}
  
/*
  Function that asks the player on what to
  do based on Exploration, Rest or Train
*/
int 
nHomeChoices(struct Player *nMainCharacter, struct Enemy *nColonist,
                  struct Enemy *nChicken, struct Enemy *nSnake, int 
                  *nDifficulty, struct Enemy*nAmerikano,struct Inventory 
                  *nMCInventory)
{
  //variable declaration
  int   nChoices,
        nPlaceChoices,
        DefeatOrNot;

  //asks the user to choose from the menu
  printf("\n\n");
  DisplayUnderscore();
  printf("\n||Menu:\t\t\t\t\t||\n");
  printf("||\t\t\t\t\t||");
  printf("\n||\t[1] for Exploration\t\t||\n");
  printf("||\t[2] for Rest\t\t\t||\n");
  printf("||\t[3] for Train\t\t\t||\n");
  printf("||\t\t\t\t\t||\n");
  DisplayUnderscore();
  printf("\nPress A Number ==> ");
  scanf("%d", &nChoices);
  
  switch(nChoices)
  {
    //battle
    case 1: DisplayNewLine();
            DisplayEquals();
            printf("\n\t      <Traveling>");
            DisplayEquals();
            nPlaceChoices = nChoosePlace();
            DefeatOrNot = nBattleTakesPlace(&*nMainCharacter, &*nColonist, 
                                            &*nChicken, &*nSnake, nPlaceChoices, 
                                            nDifficulty, &*nAmerikano, &*nMCInventory);//enemy and player battle or items
            return DefeatOrNot;
            break;

    //rest
    case 2: DisplayNewLine();
            DisplayEquals();
            printf("\n\t      <Resting>");
            DisplayEquals();
            printf("\n\n");
            nRest(*&nMainCharacter);//health regeneration
            break;
    //learn    
    case 3: DisplayNewLine();
            DisplayEquals();
            printf("\n\t      <Learning>");
            DisplayEquals();
            nLearning(&*nMainCharacter);//math question
          break;
  }
  return 0;
}

//regenerates player's health
void
nRest(struct Player *nMainCharacter)
{
  //initialized the player's health to be 100
  if(nMainCharacter->nPlayerHealth < nMainCharacter->nPlayerMaxhealth)
  {
    printf("\n[You have rested well, and gained you health back!]\n");
    nMainCharacter->nPlayerHealth = nMainCharacter->nPlayerMaxhealth;
  }
  else
  { 
    printf("\n[You cannot sleep since you are well-rested]\n");
    printf("\n[You have wasted days trying to sleep]\n");

  }
   
}

//The available places where enemies or items can be found
int
nBattleTakesPlace(struct Player *nMainCharacter, struct Enemy *nColonist, struct Enemy 
                  *nChicken, struct Enemy *nSnake, int nPlaceChoices, int *nDifficulty,
                  struct Enemy *nAmerikano, struct Inventory *nMCInventory)
{
  //declaration
  int   nNumToActivate = 0,
        DefeatOrNot = 0;

  srand(time(NULL));
  nNumToActivate = rand() % 3;
  nStatsPlayer(&*nMainCharacter);// struct for character

  //places where enemies or items maybe encountered    
  switch(nPlaceChoices)
  {
    //colonist
    case 1: DisplayNewLine();
            DisplayEquals();
            printf("\n\t     [Rice Fields]");
            DisplayEquals();
            DefeatOrNot = nGameBattle(&nNumToActivate, &*nMainCharacter, &*nColonist, 
                                      &*nChicken, &*nSnake, nDifficulty, &*nAmerikano, 
                                      &*nMCInventory); 
          return DefeatOrNot;
          break;

    //chicken
    case 2: DisplayNewLine();
            DisplayEquals();
            printf("\n\t       [Caves]");
            DisplayEquals();
            DefeatOrNot = nGameBattle(&nNumToActivate, &*nMainCharacter, &*nColonist, 
                                      &*nChicken, &*nSnake, nDifficulty, &*nAmerikano, 
                                      &*nMCInventory); 
            return DefeatOrNot;
            break;
    //snake
    case 3: DisplayNewLine();
            DisplayEquals();
            printf("\n\t       [Forest]");
            DisplayEquals();
            DefeatOrNot = nGameBattle(&nNumToActivate, &*nMainCharacter, &*nColonist, 
                                      &*nChicken, &*nSnake, nDifficulty, &*nAmerikano, 
                                      &*nMCInventory); 
            return DefeatOrNot;
            break;

  }
  return 0;
}

//Player's atack DMG to the enemy
void 
nPlayerATTK(struct Enemy *nColonist,struct Enemy *nChicken,
            struct Enemy *nSnake, int *nRamdomNum, int 
            *nRamdomRange, struct Enemy *nAmerikano,
            int nNumberEnemy)
{
  //variable declaration
  int   nDamageEnemy;
      
  nDamageEnemy = *nRamdomNum;// passing of randomize damage to nDamageEnemy

  printf("\n\n");
  DisplayHashtag();
  printf("\n================Player Turn================\n\n");
  
  //determining the enemy
  if(nNumberEnemy == 1)
  {
    nColonist->nEnemyDefense -= nDamageEnemy;
  }
  else if(nNumberEnemy == 2)
  {
    nChicken->nEnemyHealth -= nDamageEnemy;
  }
  else if(nNumberEnemy == 3)
  {
    nSnake->nEnemyHealth -= nDamageEnemy;
  }
  else if(nNumberEnemy == 4)
  {
    nAmerikano->nEnemyHealth -= nDamageEnemy;
  }

  // if damage is less than 0, 0 will be displayed
  if(nDamageEnemy < 0)
  {
    nDamageEnemy = 0;
  }

  //*nRamdomNum's random numbers the same as *nRamdomRange's random numbers
  if(*nRamdomNum == *nRamdomRange)
  {
    /*
      if randomize number is 0, the attack will be 
      missed else the enemy will be damaged
    */
    if(nDamageEnemy == 0)
    {
      printf("\tYou miss your wild attack!\n");
    } 
    else
    {
      printf("You wildy attack the enemy for |%d| Damage!\n", nDamageEnemy);
    }
  }
  else
  {
    /*
      if randomize number is 0, the attack will be 
      missed else the enemy will be damaged
    */
    if(nDamageEnemy == 0)
    {
      printf("\tYou do no Damage to the enemy!\n");
    }
    else
    {
      printf("      You attack enemy for |%d| Damage!\n", nDamageEnemy);
    }
  }

  nColonist->nEnemyHealth -= nDamageEnemy;// passing of the DMG to the enemy

}

//Enemy's attack DMG to the player
void 
nEnemyATTK(struct Player *nMainCharacter, int *nRamdomNum, 
          int *nRamdomRange, int *nDifficulty, int nCounterRandom)
{
  //variable declaration
  int   nDamagePlayer;

  /* 
    in a turn if the enemy strike the player 
    3 times then the damage will be lesssen
  */
  if(nCounterRandom < 3)
  {
    nDamagePlayer = *nRamdomNum + *nDifficulty;
  }
  else if(nCounterRandom > 4)
  {
     nDamagePlayer = *nRamdomNum - 3 + *nDifficulty;
  }
  
  printf("\n=================Enemy Turn=================\n\n");
      //printf("DIFFICULTY+ %d", *nDifficulty); 

  //no DMG to the player
  if(nDamagePlayer < 0)
  {
    nDamagePlayer = 0;
  }
  /*
    if randomize number is 0, the attack will be 
    missed else the enemy will be damaged
  */
  if(*nRamdomNum == *nRamdomRange)
  {
    if(nDamagePlayer == 0)
    {
      printf("\tEnemy misses his wild attack!\n");
    }
    else
    {
      printf(" Enemy does a wild attack for |%d| damage!\n", nDamagePlayer);
    }
  }
  else
  {
    if(nDamagePlayer == 0)
    {
      printf("\tEnemy does no damage to you!\n");
    } 
    else
    {
      printf("      Enemy attacks you for |%d| damage!\n", nDamagePlayer);
    } 
  }
    //passing of damage to the player's defense
    nMainCharacter->nPlayerDefense -= nDamagePlayer;

  
  //if defense is 0, player's health will receieved DMG instead
  if(nMainCharacter->nPlayerDefense < 0)
  {
    nMainCharacter->nPlayerHealth -= nDamagePlayer;
    nMainCharacter->nPlayerDefense = 0;
  }

}

/*
  This is where the player fights of the enemy or will find an item.
  The enemies will be encountered randomly as well as the items drop. 
*/
int 
nGameBattle(int *nNumToActivate, struct Player *nMainCharacter, 
            struct Enemy *nColonist, struct Enemy *nChicken, 
            struct Enemy *nSnake, int *nDifficulty, struct Enemy 
            *nAmerikano, struct Inventory *nMCInventory)
{
  //nPlayerInventory(&*nMCInventory);
  // variable declaration and initialization
  int   nOneTwoThree,
        nRand,
        nAttckChoices = 0,
        nRamdomNum = 0,
        nRamdomRange = 0,
        nNumberEnemy = 0,
        nPassInven = 0,
        nCounterRandom = 0,
        nInventoryUse = 0;

  nOneTwoThree = *nNumToActivate;// remove this
  srand(time(NULL));

  switch(nOneTwoThree)
  {
    case 0: nNumberEnemy = 1;          
            nRamdomATTKNumbEasy(&nRamdomNum);
            nRamdomATTKRangeEasy(&nRamdomRange);
            nRand = rand() % 11;
            if(nRand <= 3 && nRand >= 0)
            {
              printf("\n   [You have encountered a Colonist!]\n");
              while(nColonist->nEnemyHealth > 0 &&  nMainCharacter->nPlayerHealth > 0)
              {           
                printf("\n");
                DisplayUnderscore();
                printf("\n\n  [-- MainCharacter Health: %d/%d --]\n", nMainCharacter->nPlayerHealth, 
                      nMainCharacter->nPlayerMaxhealth);

                if(nMainCharacter->nPlayerDefense >= 0)
                {
                  printf("  [-- MainCharacter Defense: %d/%d --]\n", nMainCharacter->nPlayerDefense, 
                        nMainCharacter->nPlayerMaxdefense);
                }
                else
                {
                  printf("  [-- MainCharacter Defense: 0/ %d --]\n", nMainCharacter->nPlayerMaxdefense);
                }
                printf("\n\t[-- Enemy Health: %d/%d --]\n", nColonist->nEnemyHealth, nColonist->nEnemyMaxhealth);

                nAttckChoices = nAttackChoices();
                //player attack
                if(nAttckChoices == 1 )
                {               
                  nPlayerATTK(&*nColonist, &*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange, &*nAmerikano,
                              nNumberEnemy);                
                }
                else if(nAttckChoices == 2)
                {
              
                  nPlayerATTK(&*nColonist,&*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange,&*nAmerikano,
                              nNumberEnemy);
                  nRand = rand() % 6;
                  if(nRand < 6 && nRand > 3)
                  { 
                    nColonist->nEnemyHealth -= nRand;
                    printf("\n\t\t[Great Job!]");  
                    printf("\n    [Additional DMG |%d| to the enemy!]\n", nRand);
                  }
                }
                else if(nAttckChoices == 3)
                {
                  printf("[-------------------------------]");
                  printf("\n\t[]Inventory:\n");
                  nInventory(nPassInven,&*nMCInventory);
                  printf("\n\t ==> ");
                  scanf("%d", &nInventoryUse);
                  if(nInventoryUse == 1 && nMCInventory->nActiveOne == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tWeapon: %d+\n", nMCInventory->nSword);
                    nColonist->nEnemyHealth -= nMCInventory->nSword;
                    nMCInventory->nSword -= nMCInventory->nSword;//sword remove
                    printf("      You attack enemy for |%d| Damage!\n", nMCInventory->nSword);
                    nMCInventory->nActiveOne -= 1;
                  }
                  else if(nInventoryUse == 2 && nMCInventory->nActiveTwo == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tHealth: %d+\n", nMCInventory->nHealthPotion );
                    nMainCharacter->nPlayerHealth += nMCInventory->nHealthPotion; 
                    nMCInventory->nHealthPotion -= nMCInventory->nHealthPotion;//potion remove
                    nMCInventory->nActiveTwo -= 1;
                  }
                  else if(nInventoryUse == 3 && nMCInventory->nActiveThree == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tArmor: %d+\n", nMCInventory->nArmor);
                    nMainCharacter->nPlayerDefense += nMCInventory->nArmor; 
                    nMCInventory->nArmor -= nMCInventory->nArmor;// armor remove
                    nMCInventory->nActiveThree -= 1;                 
                  }
                  else
                  {
                    printf("\n\t  [Your turn is wasted!]\n");
                  }           
                }
                else if(nAttckChoices == 4)
                {
                 printf("\n------------->You have Fled!<-------------\n\n"); // flee                 
                  return 0;
                }
                //enemy attack
                if(nAttckChoices == 1 || nAttckChoices == 2 || nAttckChoices == 3)
                {              
                  nRamdomATTKNumbEasy(&nRamdomNum);
                  nRamdomATTKRangeEasy(&nRamdomRange);
                  nEnemyATTK(*&nMainCharacter, &nRamdomNum, &nRamdomRange, nDifficulty, nCounterRandom);
                  nRand = rand() % 6;
                  if(nRand < 2 && nRand > 0 )
                  {
                    nMainCharacter->nPlayerDefense -= nRand;

                    if(nMainCharacter->nPlayerDefense <= 0)
                    {
                      nMainCharacter->nPlayerHealth -= nRand;
                    }
                    printf("\n\t\t[Oh oh!]");    
                    printf("\n    [Additional DMG |%d| to the player!]\n", nRand);
                    nCounterRandom++;    
                  }
                  
                }
                else if(nRand < 5 && nRand > 0)
                {
                  printf("\nThe enemy did no additional damage!\n");
                }

                if(nColonist->nEnemyHealth <= 0)
                {
                  printf("\n===================Result===================\n\n");
                  printf("\n[You have defeated a Colonist!]");
                  printf("\n\n[Colonist EXP : %d]\n\n", nColonist->nExperiencePoints);
                  DisplayHashtag();
                  nMainCharacter->nPlayerExperience += nColonist->nExperiencePoints;
                  nMainCharacter->nPlayerDefense += 30;
                }
                if(nMainCharacter->nPlayerHealth <= 0)
                {
                  printf("\n[You have been Defeated]\n"); 
                  DisplayHashtag();
                  printf("\n");
                  return 1;
                }
              }
            // items  
            }
            else if(nRand <= 10  && nRand >= 4)
            {        
              nPassInven = nItems(&*nMCInventory);// item drop(sword, potion or armor) 
              nInventory(nPassInven, &*nMCInventory);//putting the drop item into the inventory        
            }
          break;
    //chicken
    case 1: nNumberEnemy = 2;          
            nRamdomATTKNumbEasy(&nRamdomNum);
            nRamdomATTKRangeEasy(&nRamdomRange);
            nRand = rand() % 11;
            if(nRand <= 4 && nRand >= 0)
            {
              printf("\n   [You have encountered a Chicken!]\n");
              while(nChicken->nEnemyHealth > 0 &&  nMainCharacter->nPlayerHealth > 0)
              {       
                printf("\n");
                DisplayUnderscore();
                printf("\n\n  [-- MainCharacter Health: %d/ %d --]\n", nMainCharacter->nPlayerHealth, 
                      nMainCharacter->nPlayerMaxhealth);

                if(nMainCharacter->nPlayerDefense >= 0)
                {
                  printf("  [-- MainCharacter Defense: %d/ %d --]\n", nMainCharacter->nPlayerDefense, 
                        nMainCharacter->nPlayerMaxdefense);
                }
                else
                {
                  printf("  [-- MainCharacter Defense: 0/ %d --]\n", nMainCharacter->nPlayerMaxdefense);
                }
                printf("\n\t[-- Enemy Health: %d/%d --]\n", nChicken->nEnemyHealth, nChicken->nEnemyMaxhealth);

                nAttckChoices = nAttackChoices();
                //player attack
                if(nAttckChoices == 1 )
                {             
                  nPlayerATTK(&*nColonist, &*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange, &*nAmerikano,
                              nNumberEnemy);               
                }
                else if(nAttckChoices == 2)
                {              
                  nPlayerATTK(&*nColonist,&*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange,&*nAmerikano,
                               nNumberEnemy);
                  nRand = rand() % 6;
                  if(nRand < 6 && nRand > 3)
                  { 
                    nChicken->nEnemyHealth -= nRand;
                    printf("\n\t\t[Great Job!]");  
                    printf("\n    [Additional DMG |%d| to the enemy!]\n", nRand);
                  }
                }
                else if(nAttckChoices == 3)
                {
                  printf("[-------------------------------]");
                  printf("\n\t[]Inventory:\n");
                  nInventory(nPassInven,&*nMCInventory);
                  printf("\n\t ==> ");
                  scanf("%d", &nInventoryUse);

                  if(nInventoryUse == 1 && nMCInventory->nActiveOne == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tWeapon: %d+\n", nMCInventory->nSword);
                    nChicken->nEnemyHealth -= nMCInventory->nSword;
                    nMCInventory->nSword-= nMCInventory->nSword;// sword remove
                    printf("      You attack enemy for |%d| Damage!\n", nMCInventory->nSword);
                    nMCInventory->nActiveOne -= 1;
                
                  }
                  else if(nInventoryUse == 2 && nMCInventory->nActiveTwo == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tHealth: %d+\n", nMCInventory->nHealthPotion );
                    nMainCharacter->nPlayerHealth += nMCInventory->nHealthPotion;
                    nMCInventory->nHealthPotion -= nMCInventory->nHealthPotion;// potion remove
                    nMCInventory->nActiveTwo -= 1;
                  }
                  else if(nInventoryUse == 3 && nMCInventory->nActiveThree == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tArmor: %d+\n", nMCInventory->nArmor);
                    nMainCharacter->nPlayerDefense += nMCInventory->nArmor;
                    nMCInventory->nArmor -= nMCInventory->nArmor;// armor remove
                    nMCInventory->nActiveThree -= 1;                 
                  }
                  else
                  {
                    printf("\n\t  [Your turn is wasted!]\n");
                  }
            
                }
                else if(nAttckChoices == 4)
                {
                  printf("\n------------->You have Fled!<-------------\n\n");// flee
                  return 0;
                }
                //enemy attack
                if(nAttckChoices == 1 || nAttckChoices == 2 || nAttckChoices == 3)
                {                 
                  nRamdomATTKNumbEasy(&nRamdomNum);
                  nRamdomATTKRangeEasy(&nRamdomRange);
                  nEnemyATTK(*&nMainCharacter, &nRamdomNum, &nRamdomRange, nDifficulty, nCounterRandom);

                  nRand = rand() % 6;
                  if(nRand < 2 && nRand > 0 )
                  {
                    nMainCharacter->nPlayerDefense -= nRand;

                    if(nMainCharacter->nPlayerDefense < 0)
                    {
                      nMainCharacter->nPlayerHealth -= nRand;
                      nMainCharacter->nPlayerDefense = 0;
                    }
                    printf("\n\t\t[Oh oh!]");    
                    printf("\n    [Additional DMG |%d| to the player!]\n", nRand);
                    nCounterRandom++;    
                  }
                  
                }
                else if(nRand < 5 && nRand > 0)
                {
                  printf("\nThe enemy did no additional damage!\n");
                }

                if(nChicken->nEnemyHealth <= 0)
                {
                  printf("\n===================Result===================\n\n");
                  printf("\n[You have defeated a Chicken!]   ");
                  printf("\n[Chicken EXP : %d]\n\n", nChicken->nExperiencePoints);
                  DisplayHashtag();
                  nMainCharacter->nPlayerExperience += nChicken->nExperiencePoints;
                  nMainCharacter->nPlayerDefense += 30;                                  
                }
                if(nMainCharacter->nPlayerHealth <= 0)
                {
                  printf("\n[You have been Defeated]\n");   
                  DisplayHashtag();       
                  printf("\n");                     
                  return 1;
                }
              }
            // items  
            }
            else if(nRand <= 10  && nRand >= 5)
            {                      
              nPassInven = nItems(&*nMCInventory);// item drop(sword, potion or armor) 
              nInventory(nPassInven, &*nMCInventory);//putting the drop item into the inventory                        
            }
            break;

    case 2: nNumberEnemy = 3;
            nRamdomATTKNumbEasy(&nRamdomNum);
            nRamdomATTKRangeEasy(&nRamdomRange);
            nRand = rand() % 11;
            if(nRand <= 3 && nRand >= 0)
            {
              printf("\n   [You have encountered a Snake!]\n");
              while(nSnake->nEnemyHealth > 0 &&  nMainCharacter->nPlayerHealth > 0)
              {
              
                printf("\n");
                DisplayUnderscore();
                printf("\n\n  [-- MainCharacter Health: %d/ %d --]\n", nMainCharacter->nPlayerHealth, 
                      nMainCharacter->nPlayerMaxhealth);

                if(nMainCharacter->nPlayerDefense >= 0)
                {
                  printf("  [-- MainCharacter Defense: %d/ %d --]\n", nMainCharacter->nPlayerDefense, 
                        nMainCharacter->nPlayerMaxdefense);
                }
                else
                {
                  printf("  [-- MainCharacter Defense: 0/ %d --]\n", nMainCharacter->nPlayerMaxdefense);
                }
                printf("\n\t[-- Enemy Health: %d/%d --]\n", nSnake->nEnemyHealth, nSnake->nEnemyMaxhealth);

                nAttckChoices = nAttackChoices();
                //player attack
                if(nAttckChoices == 1 )
                {                
                  nPlayerATTK(&*nColonist, &*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange, &*nAmerikano,
                              nNumberEnemy);               
                }
                else if(nAttckChoices == 2)
                {              
                  nPlayerATTK(&*nColonist,&*nChicken,
                              &*nSnake, &nRamdomNum, 
                              &nRamdomRange,&*nAmerikano,
                              nNumberEnemy);
                  nRand = rand() % 6;
                  if(nRand < 6 && nRand > 3)
                  { 
                    nSnake->nEnemyHealth -= nRand;
                    printf("\n\t\t[Great Job!]");  
                    printf("\n    [Additional DMG |%d| to the enemy!]\n", nRand);
                  }
                }
                else if(nAttckChoices == 3)
                {
                  printf("[-------------------------------]");
                  printf("\n\t[]Inventory:\n");
                  nInventory(nPassInven,&*nMCInventory);
                  printf("\n\t ==> ");
                  scanf("%d", &nInventoryUse);

                  if(nInventoryUse == 1 && nMCInventory->nActiveOne == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tWeapon: %d+\n", nMCInventory->nSword);
                    nSnake->nEnemyHealth -= nMCInventory->nSword;
                    nMCInventory->nSword-= nMCInventory->nSword;// sword remove
                    printf("      You attack enemy for |%d| Damage!\n", nMCInventory->nSword);
                    nMCInventory->nActiveOne -= 1;
                  }
                  else if(nInventoryUse == 2 && nMCInventory->nActiveTwo == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tHealth: %d+\n", nMCInventory->nHealthPotion );
                    nMainCharacter->nPlayerHealth += nMCInventory->nHealthPotion;
                    nMCInventory->nHealthPotion -= nMCInventory->nHealthPotion;//potion remove
                    nMCInventory->nActiveTwo -= 1;
                  }
                  else if(nInventoryUse == 3 && nMCInventory->nActiveThree == 1)
                  {
                    printf("\n================Player Turn================\n\n");
                    printf("\n\t\tArmor: %d+\n", nMCInventory->nArmor);
                    nMainCharacter->nPlayerDefense += nMCInventory->nArmor;
                    nMCInventory->nArmor -= nMCInventory->nArmor;// armor remove
                    nMCInventory->nActiveThree -= 1;                 
                  }
                  else
                  {
                    printf("\n\t  [Your turn is wasted!]\n");
                  }            
                }
                else if(nAttckChoices == 4)
                {
                  printf("\n------------->You have Fled!<-------------\n\n");// flee
                  return 0;
                }
                //enemy attack
                if(nAttckChoices == 1 || nAttckChoices == 2 || nAttckChoices == 3)
                {
                  
                  nRamdomATTKNumbEasy(&nRamdomNum);
                  nRamdomATTKRangeEasy(&nRamdomRange);
                  nEnemyATTK(*&nMainCharacter, &nRamdomNum, &nRamdomRange, nDifficulty, nCounterRandom);
                  nRand = rand() % 6;
                  if(nRand < 2 && nRand > 0 )
                  {
                    nMainCharacter->nPlayerDefense -= nRand;
                    if(nMainCharacter->nPlayerDefense <= 0)
                    {
                      nMainCharacter->nPlayerHealth -= nRand;
                    }
                    printf("\n\t\t[Oh oh!]");    
                    printf("\n    [Additional DMG |%d| to the player!]\n", nRand);
                    nCounterRandom++;    
                  }                  
                }
                else if(nRand < 5 && nRand > 0)
                {
                  printf("\nThe enemy did no additional damage!\n");
                }

                if(nSnake->nEnemyHealth <= 0)
                {
                  printf("\n===================Result===================\n\n");
                  printf("\n[You have defeated a Snake!]");
                  printf("\n[Snake EXP : %d]\n\n", nSnake->nExperiencePoints);
                  DisplayHashtag();
                  nMainCharacter->nPlayerExperience += nSnake->nExperiencePoints;
                  nMainCharacter->nPlayerDefense += 30;                                 
                }
                if(nMainCharacter->nPlayerHealth <= 0)
                {
                  printf("\n[You have been Defeated]\n");     
                  DisplayHashtag();   
                  printf("\n");             
                  return 1;
                }
              }
            }
            else if(nRand <= 10  && nRand >= 4)
            {                        
              nPassInven = nItems(&*nMCInventory);// item drop(sword, potion or armor) 
              nInventory(nPassInven, &*nMCInventory);//putting the drop item into the inventory                          
            }
            break;          
  }
  
  return 0;
}

/*
  Function is for the final boss of the game and the required experience is met 
*/  
int
EndGameBoss(struct Enemy *nColonist, struct Enemy *nChicken,
            struct Enemy *nSnake, struct Enemy *nAmerikano, 
            struct Player *nMainCharacter, struct Inventory 
            *nMCInventory)
{
  // variable declaration and initialization
  int   nRand = 0,
        nNum,
        nAttckChoices,
        nRamdomNum = 0,
        nRamdomRange = 0,
        nPassInven = 0,
        nCounterRandom = 0,
        nInventoryUse = 0,
        nNumberEnemy,
        nDifficulty = 0,
        nFLee = 0; 
      
        nNumberEnemy = 4; 

  //random numbers
  srand(time(NULL));
  nNum = rand() % 3;
  nRand= rand() % 11;
  nRamdomRange = rand() % 70;

  //to get the dmg
  switch (nNum)
  {
    case 0: nRamdomNum = rand() % 10;
            break;
    case 1: nRamdomNum = rand() % 25;
            break;
    case 2: nRamdomNum = rand() % 50;
            break;
  }
  
  // battle choices and results will loop until enemy or player's health is 0 or the choice flee is entered
  do
  {
    printf("\n");
    DisplayUnderscore();
   
    printf("\n\n  [-- MainCharacter Health: %d/ %d --]\n", nMainCharacter->nPlayerHealth, nMainCharacter->nPlayerMaxhealth);
    if(nMainCharacter->nPlayerDefense >= 0)
    {
      printf("  [-- MainCharacter Defense: %d/ %d --]\n", nMainCharacter->nPlayerDefense, nMainCharacter->nPlayerMaxdefense);
    }
    else
    {
      printf("  [-- MainCharacter Defense: 0/ %d --]\n", nMainCharacter->nPlayerMaxdefense);
    }       
    printf("\n\t[-- Enemy Health: %d/%d --]\n", nAmerikano->nEnemyHealth, nAmerikano->nEnemyMaxhealth);
    nAttckChoices = nAttackChoices();
    if(nAttckChoices == 1 )
    {
      //player's normal attack   
      nPlayerATTK(&*nColonist, &*nChicken,
                  &*nSnake, &nRamdomNum, 
                  &nRamdomRange, &*nAmerikano,
                  nNumberEnemy);                
    }
    else if(nAttckChoices == 2)
    {
      //player's wild attack        
      nPlayerATTK(&*nColonist,&*nChicken,
                  &*nSnake, &nRamdomNum, 
                  &nRamdomRange,&*nAmerikano,
                  nNumberEnemy);
      nRand = rand() % 6;
      if(nRand < 6 && nRand > 3)
      { 
        nAmerikano->nEnemyHealth -= nRand;
        printf("\n\t\t[Great Job!]");  
        printf("\n    [Additional DMG |%d| to the enemy!]\n", nRand);

      }                                      
    }
    // inventory
    else if(nAttckChoices == 3)
    {
      printf("[-------------------------------]");
      printf("\n\t[]Inventory:\n");
      nInventory(nPassInven,&*nMCInventory);
      printf("\n\t ==> ");
      scanf("%d", &nInventoryUse);     
      //using the sword
      if(nInventoryUse == 1 && nMCInventory->nActiveOne == 1)
      {
        printf("\n================Player Turn================\n\n");
        printf("\n\t\tWeapon: %d+\n", nMCInventory->nSword);
        nAmerikano->nEnemyHealth -= nMCInventory->nSword;
        nMCInventory->nSword -= nMCInventory->nSword;// sword remove
        printf("      You attack enemy for |%d| Damage!\n", nMCInventory->nSword);
        nMCInventory->nActiveOne -= 1;                
      }
      //using the health potion
      else if(nInventoryUse == 2 && nMCInventory->nActiveTwo == 1)
      {
        printf("\n================Player Turn================\n\n");
        printf("\n\t\tHealth: %d+\n", nMCInventory->nHealthPotion );
        nMainCharacter->nPlayerHealth += nMCInventory->nHealthPotion;
        nMCInventory->nHealthPotion -= nMCInventory->nHealthPotion;//potion remove
        nMCInventory->nActiveTwo -= 1;
                  
      }
      //using the armor
      else if(nInventoryUse == 3 && nMCInventory->nActiveThree == 1)
      {
        printf("\n================Player Turn================\n\n");
        printf("\n\t\tArmor: %d+\n", nMCInventory->nArmor);
        nMainCharacter->nPlayerDefense += nMCInventory->nArmor;
        nMCInventory->nArmor -= nMCInventory->nArmor;// armor remove
        nMCInventory->nActiveThree -= 1;                 
      }
      //if choosing inventory but there's no item
      else
      {
        printf("\n\t  [Your turn is wasted!]\n");
      }
           
    }
    //fleeing
    else if(nAttckChoices == 4)
    {
      printf("\n------------->You have Fled!<-------------\n\n");//flee         
      nFLee = 2;
    }
    //enemy
    if(nAttckChoices == 1 || nAttckChoices == 2 || nAttckChoices == 3)
    {
      nRamdomATTKNumbEasy(&nRamdomNum);
      nRamdomATTKRangeEasy(&nRamdomRange);
      nEnemyATTK(*&nMainCharacter, &nRamdomNum, &nRamdomRange, &nDifficulty, nCounterRandom);
      nRand = rand() % 6;
      if(nRand < 2 && nRand > 0 )
      {
        if(nMainCharacter->nPlayerDefense > 0)
        {
          nMainCharacter->nPlayerDefense -= nRand;
        }
        else
        {
          nMainCharacter->nPlayerHealth -= nRand;
        }      
        printf("\n\t\t[Oh oh!]");    
        printf("\n    [Additional DMG |%d| to the player!]\n", nRand);
              nCounterRandom++;    
      }                 
    }
    else if(nRand < 5 && nRand > 0)
    {
      printf("\nThe enemy did no additional damage!\n");
    }
    if(nAmerikano->nEnemyHealth <= 0)
    {
      printf("\n===================Result===================\n\n");
      printf("\n     [You have defeated the General!]\n\n");
      DisplayHashtag();
      printf("\n\n\n");               
    }
    if(nMainCharacter->nPlayerHealth <= 0)
    {
      printf("\n[You have been Defeated]");
      DisplayHashtag();    
      printf("\n");
      return 0; 
    }
                         
  }while(nAmerikano->nEnemyHealth > 0 &&  nMainCharacter->nPlayerHealth > 0 && nFLee == 0);
      
  return 0;

}

/*
  Function that checks if the acquired EXP of the player is 
  above or equal to the required EXPof the game. An early game
  over may occur or a boss battle shall take place.
*/
void 
nAliveOrDead(struct Enemy *nColonist, struct Enemy *nChicken, 
             struct Enemy *nSnake, struct Player *nMainCharacter, 
             struct Enemy *nAmerikano,  int *nEndGame, int nKey, 
             char *nNameCharacter, struct Inventory *nMCInventory)
{
  int   nFled;

  if (nMainCharacter->nPlayerExperience >= nMainCharacter->nPlayerMaxExperience)
  {
    DisplayNewLine();
    ChapterBossSection(&*nNameCharacter);
    DisplayEquals();  
    printf("\n\t\tQuisao");
    DisplayEquals();          
    nFled = EndGameBoss(&*nColonist, &*nChicken,&*nSnake, &*nAmerikano, &*nMainCharacter,&*nMCInventory);
    
    //if player's EXP is above or equal to 800, a boss battle will appear
    if(nAmerikano->nEnemyHealth <= 0 && nFled != 2)
    {
      GameWon(&*nNameCharacter);  
      vPrintTitle();
      *nEndGame = 0;
    }
    //if player died to the arms of the enemy
    else if(nMainCharacter->nPlayerHealth <= 0 && nFled != 2 )
    {
      GameWonButLoss(&*nNameCharacter);
      vPrintTitle();
      *nEndGame = 0;
    }
    //player chooses to flee
    else if(nFled != 2)
    {
      Fleeing();
      vPrintTitle();
      *nEndGame = 0;
    }
  }
  //if player's EXP is less than 800, a bad ending will commence
  else if( nMainCharacter->nPlayerExperience < nMainCharacter->nPlayerMaxExperience && nKey == 1)
  {
    GameEndLoss(nNameCharacter);
    vPrintTitle();
    *nEndGame = 0;
    nKey = 0;

  }
}

// Asks for input and takes effect in game
int 
nAttackChoices()
{
  int nAttackChoices;
  DisplayUnderscore();
  printf("\nYour turn: \n");
  printf("\n\t  [1] for Normal Attack\n");
  printf("\t  [2] for Chance Attack\n");
  printf("\t  [3] for Inventory\n");
  printf("\t  [4] for Evade\n");
  DisplayHashtag();
  do
  {
    printf("\nPress A Number ==> ");
    scanf("%d", &nAttackChoices);
  }while(nAttackChoices != 1 && nAttackChoices != 2 &&
          nAttackChoices != 3 && nAttackChoices != 4 );
  
  DisplayNewLine();
  return nAttackChoices;

}

int 
nChoosePlace()
{
  int   nPlacePlayerChoosing;
  printf("\n\n");
  DisplayAsterisk();
  printf("Anong lugar ang gusto mong puntahan:\n");
  printf("\t[1] Rice Fields\n");
  printf("\t[2] Caves\n");
  printf("\t[3] Forests\n");
  DisplayAsterisk();
  do
  {
    printf("Press A Number ==> ");
    scanf("%d", &nPlacePlayerChoosing);
  }while(nPlacePlayerChoosing != 1 && nPlacePlayerChoosing != 2 &&
          nPlacePlayerChoosing != 3 && nPlacePlayerChoosing != 4);

  
  return nPlacePlayerChoosing;
}

//Inventory functions
int 
nItems(struct Inventory *nMCInventory)
{
  int nItems;

  srand(time(NULL));
    nItems = rand() % 4;
    printf("\n\n[*beep* *beep*.]\n");
    printf("[You have found...]\n");
    switch(nItems)
    {
      case 0: printf("[You did not get anything.]\n");
              return 0;
              break;
      case 1: printf("[You have gotten a Sword!]\n");
              nMCInventory->nActiveOne = 1;
              return 1;
              break;
      case 2: printf("[You have gotten a HealthPotion!]\n");
              nMCInventory->nActiveTwo = 1;
              return 2;
              break;
      case 3: printf("[You have gotten a Armor!]\n");
              nMCInventory->nActiveThree = 1;
              return 3;
              break;
    };
  return 0;
}

/* 
  This function serves to drop(sword, potion, armor) items, sword gives 40 
  additional DMG, potion gives 50 additional HEALTH,  lastly armor gives 
  70 addtional defense.       
*/
void 
nInventory(int nPassInven, struct Inventory *nMCInventory)
{
  // variable declaration and initialization
  int nSwordCouunter = 1,
      nHealthCounter = 1,
      nArmorCounter = 1;

  //randomly drops items
  switch(nPassInven)
  {
    case 1: nMCInventory->nSword += 40;
            printf("|%d Sword gives you addtional [ATTK]|\n", nSwordCouunter);
            nSwordCouunter++;
            break;
    case 2: nMCInventory->nHealthPotion += 50;
            printf("|%d Potion gives you addtional [HEALTH]|\n",nHealthCounter);
            nHealthCounter++;
            break;
    case 3: nMCInventory->nArmor += 70;
            printf("|%d Armor gives you [DEFENSE]|\n", nArmorCounter);
            nArmorCounter++;
            break;
  }
  
  //checking how many items has been recieved based on the addtional stats
  if(nMCInventory->nActiveOne == 1 || nMCInventory->nActiveTwo == 1 || nMCInventory->nActiveThree == 1)
  {
    if(nMCInventory->nActiveOne == 1)
    {
      printf("\n\t[1] Weapon: %d\n", nMCInventory->nSword);             
    }
    if(nMCInventory->nActiveTwo == 1)
    {
      printf("\n\t[2] Health Potion: %d\n", nMCInventory->nHealthPotion);
    }
    if(nMCInventory->nActiveThree == 1)
    {
      printf("\n\t[3] Armor: %d\n", nMCInventory->nArmor);
    }
  }
  else
  {
    printf("\n[You have no items in Inventory]\n");
  }
 
}


/*functions that loops*/

//gives random numbers as DMG
void 
nRamdomATTKNumbEasy(int *nRamdomNum)
{
    // variable declaration
    int nNum;
    srand(time(NULL));
    nNum = rand() % 3;
    
    switch (nNum)
    {
      case 0: srand(time(NULL));
              *nRamdomNum = rand() % 6;
              break;
      case 1: srand(time(NULL));
              *nRamdomNum = rand() % 11;
              break;
      case 2: srand(time(NULL));
              *nRamdomNum = rand() % 16;
              break;
    }
}

//gives random numbers as range
void 
nRamdomATTKRangeEasy(int *nRamdomRange)
{
    srand(time(NULL));
    *nRamdomRange = rand() % 20;
}

//loops semicolon sign and displays
void
DisplaySemiColon()
{
  // declares a variable
	int   counter; 

	//loops until 40 then prints ';'
	for(counter = 0; counter <= 40; counter++) 
		printf(":");
}

//loops underscore sign and displays
void
DisplayUnderscore()
{
  // declares a variable
	int   counter; 
	  
	//loops until 40 then prints '_'
	for(counter = 0; counter <= 40; counter++) 
		printf("_");
}

//loops addtion sign and displays
void
DisplayPlus()
{
	int   counter; // variable declaration
	  
	//loops until 41 then prints '+'
	for(counter = 0; counter <= 41; counter++) 
		printf("+");
}

//loops asterisk sign and displays
void
DisplayAsterisk()
{
	int		counter;// variable declaration

  //loops until 42 then prints '*'
	for(counter = 0; counter <= 42; counter++)
			printf("*");
	
	printf("\n");
}

//loops equal sign and displays
void
DisplayEquals()
{
	int		counter;// variable declaration
  printf("\n    ");

  //loops until 30 then prints '='
	for(counter = 0; counter <= 30; counter++)
			printf("=");
}

//loops newlines and displays
void
DisplayNewLine()
{
	int 	counter;// variable declaration
  
  //loops until 42 then prints new lines
	for(counter = 0; counter <= 3; counter++)
		printf("\n");
}

//loops greater sign and displays
void
DisplayGreater()
{
	int 	counter;// variable declaration

  //loops until 20 then greater than sign
	for(counter = 0; counter <= 20; counter++)
		printf(">");
}

//loops lesser than sign and displays
void
DisplayLesser()
{
	int 	counter;// variable declaration

  //loops until 20 then lesser than sign
	for(counter = 0; counter <= 20; counter++)
		printf("<");/* prints out new lines*/
}

//loops hashtags and displays
void
DisplayHashtag()
{
	int 	counter;// variable declaration
  
  //loops until 20 then hashtags
  for(counter = 0; counter <= 42; counter++)
		printf("#");
}


/*story(dialogues, title screen, plots)*/

void 
vPrintTitle()
{
  DisplayPlus();
  printf("\n");
  DisplayPlus();
  printf("\n++\t\t\t\t\t++\n");
  printf("++\t  Ang Sakwil ng Anak");
  printf("\t\t++\n++\t\tng Bayan\t\t++\n");
  printf("++\t");
  printf("\t\t\t\t++\n");
  DisplayPlus(); 
  printf("\n");
  DisplayPlus(); 
}

void 
vTitleChoice()
{
  printf("\n\n");
  DisplayGreater();
  DisplayLesser();
  printf("\n||Ang Sakwil ng Anak ng Bayan:\t\t||\n");
  printf("||\t\t    [1] Start Game");
  printf("\t||\n");
  printf("||\t\t    [2] About");
  printf("\t\t||\n");
  printf("||\t\t    [3] Exit Game");
  printf("\t||\n");
  DisplayGreater();
  DisplayLesser();
  printf("\nPress A Number ==> ");
}


void 
vAbout()
{
  DisplayUnderscore();
  DisplayUnderscore();
  printf("\n\n");
  printf("Sympnosis:\n\n");
  printf("\tThe inspiration of this game is about the events of world war 2\n");
  printf("\tand how the Colonists affected the lives of millions of people.\n");
  printf("\t    One of those affected is a young child from Rizal.\n");
  printf("\n");
  printf("Creator: ");
  printf("Irish Jane Ramos(2022)\n");
  DisplayUnderscore();
  DisplayUnderscore();
  printf("\n\n");
}

void
TitleScreen()
{   
    DisplayNewLine(); 
	  DisplayAsterisk();
    printf("\n");
    printf("\tAng ");
    printf("Sakwil na Anak");
    printf(" ng Bayan");
    printf("\n\n");
	  DisplayAsterisk();
    DisplayNewLine();
    
}


//display's player's current attributes
void 
nPlayerMenu(struct Player *nMainCharacter)
{
  nStatsPlayer(&*nMainCharacter);
  printf("\n");
  DisplaySemiColon();
  printf("\n");
  printf("\t    Health: %d/%d\n", nMainCharacter->nPlayerHealth, nMainCharacter->nPlayerMaxhealth );
  printf("\t    Defense: %d/%d\n", nMainCharacter->nPlayerDefense,nMainCharacter->nPlayerMaxdefense);
  printf("\tExperience Points: %d/%d\n", nMainCharacter->nPlayerExperience,nMainCharacter->nPlayerMaxExperience);
  DisplaySemiColon();

}


void
vGameIntroduction()
{
  printf("\n");
  printf("\n???:\n\t...");
  printf("?\n");  
  printf("\n???:\n\tAnong nangyari...?"); 
  printf("\n???:\n\t...Mama? Papa?"); 
  printf("\n???:\n\tAsan po kay--");  
  printf("\n\n");
  printf("\t*thud*");
  printf("\n\n");  
  printf("\n???:\n\tMAMA?! PAPA?!"); 
  printf("\n\n");
  printf("\t*BOOM*");  
  printf("\n");
  DisplayUnderscore();
  printf("\n\n\n\t    ***TIMESKIP***");
  printf("\n???:\n\tPagkatapos nung pangyayari na yun...");
  printf("\n\tMag-isa nalang ako sa buhay");
  printf("\n\tSapagkat ako si");
}

//asks for the player's name assumed to be always 1 char
void 
cName(char *nNameCharacter)
{
  printf("\n\n");
  printf("[Enter a single character for your name: ]");
  printf("\n\t==> ");
  scanf(" %c", nNameCharacter);
  printf("\n");
  printf("\t\t....");
  printf("\n\t  Sapagkat ako si %c\n", *nNameCharacter);
}

void 
ChapterTwoStory(char *nNameCharacter)
{
  printf("[The Americans have enforced a system, where Filipinos are]\n\n");
  printf("[to only think and speak like an American] \n\n[and to defy is to faced death in the eye]\n\n");
  printf("%c:\n\tFighting this Enemies are no different from monster!\n", *nNameCharacter);
  printf("\n\t*huff*\n\n");
  printf("%c:\n\tHope mom and dad are proud...\n", *nNameCharacter);
}

void 
ChapterThreeStory(char *nNameCharacter)
{
  printf("%c:\n\tI'm improving bit by bit\n\n", *nNameCharacter);
  printf("%c:\n\tI should go into the caves tomorrow\n\n", *nNameCharacter); 
  printf("%c:\n\tor should I just rest...\n\n", *nNameCharacter);
  printf("%c:\n\tDon't be an idiot, The enemies aren't resting \n\n", *nNameCharacter);
  printf("[%c has trained for weeks]\n\n", *nNameCharacter);
  printf("[Until one day when they have decided to change the scenery]\n\n");
  printf("[%c has stumbled on an AMERICAN COLONIST in training!]\n\n", *nNameCharacter);
  printf("[They decided to watch it and have gained experience!]\n");

}

void 
ChapterFourStory(char *nNameCharacter)
{
  printf("[%c is at a lake of Laguna]\n\n", *nNameCharacter);
  printf("*wave sounds*\n");
  printf("\n\t*huff* \n\n %c:\n\tThis...will improve...my stamina\n", *nNameCharacter);
  printf("\n\t*swimming sounds*\n\n");
  printf("[They continued to train and train until they need to hunt for food]\n\n");
  printf("%c:\n\tHmmm...I wonder where the chickens are...\n", *nNameCharacter);
  printf("???:\n\t*coo coo*\n");
  printf("%c:\n\tWas that...?!\n", *nNameCharacter);
  printf("???:\n\t*grass sounds*\n");
  printf("%c:\n\tAHA! There you are!\n", *nNameCharacter);
  printf("???:\n\t*coo coo?!*\n");
  printf("%c:\n\tLittle chicken come back here!\n\n", *nNameCharacter);
  printf("[Thus %c has chased the chicken until evening]\n", *nNameCharacter);

}

void 
ChapterFiveStory(char *nNameCharacter)
{
  printf("[%c is at a forest on the outskirts of Malaya, Rizal]\n\n", *nNameCharacter);
  printf("%c:\n\tI'm fighting them wih all I have!", *nNameCharacter); 
  printf("\n\n\t*swoosh sounds*\n\n\t*clang sound*\n\n");
  printf("%c:\n\tMamatay kayo mga Amerikano! Mga Hayop!\n\n", *nNameCharacter);
  printf("%c:\n\tPinipilit niyo kaming mag salita ng ingles\n\n", *nNameCharacter);
  printf("%c:\n\tIpakain ko sainyo tong mga ispada!\n\n", *nNameCharacter);
  printf("[A few days has passed]\n\n");
  printf("[%c found an uprising faction of Filipinos]\n\n", *nNameCharacter);
  printf("[They are working together to fight off the invaders ]\n\n");
  printf("[%c has joined the faction and it's name is Kabataang Makabayan (KM)]\n", *nNameCharacter);

}

void 
ChapterSixStory(char *nNameCharacter)
{
  printf("[Under the shades of a tree, with winds blowing and fishes swimming in]\n\n");
  printf("[the lake is where %c sits]\n\n", *nNameCharacter);
  printf("%c:\n\tBakit parang lalong dumadami pa ang mga kalaban?\n\n", *nNameCharacter);
  printf("[%c swooshing the water whilst looking his reflection.]\n\n", *nNameCharacter);
  printf("%c:\n\tAking mahal na ina at tatay, tama ba ang pinili kong...\n\n", *nNameCharacter); 
  printf("%c:\n\t...landas sa buhay?\n\n", *nNameCharacter); 
  printf("%c:\n\tAko'y nahihirapan na ngunit, kada naalala ko ang\n\n", *nNameCharacter);  
  printf("%c:\n\tpag paslang ng mga hayop na yun\n\n", *nNameCharacter); 
  printf("%c:\n\tkumukulo ang aking dugo...\n\n", *nNameCharacter); 
  printf("%c:\n\tnawa'y ako'y matulungan ninyo aking mahal na magulang\n\n", *nNameCharacter);

}

void 
ChapterSevenStory(char *nNameCharacter)
{
  printf("[%c has found a camp of colonist! Enemies: 4  Location: Teresa, Rizal]\n\n", *nNameCharacter);
  printf("%c:\n\tMGA AMERIKANO!\n\n", *nNameCharacter);
  printf("Americano:\n\tOh look at what we have here\n\n");
  printf("%c:\n\tKayo ay mamatay sa aking kamay!\n\n", *nNameCharacter);
  printf("Americano:\n\tA little boy is squicking! What do you want little boy?\n\n");
  printf("%c:\n\t...I want you to die!\n\n", *nNameCharacter);
  printf("[%c brought out their swords and started slashing left and right]\n\n", *nNameCharacter);
  printf("Americano:\n\tYOU'LL REGRET THAT YOU HAVE LIVED, BOY!\n\n");
  printf("Americano:\n\tYOU'LL SEE GOD IN A BIT!\n\n");
  printf("%c:\n\t...\n", *nNameCharacter);
  printf("\t*sword clanging*\n\n");
  printf("\t*heavy breaths*\n\n");
  printf("\t*cry of pain*\n\n");
  printf("\t*silence*\n\n");
  printf("[%c sustained heavy damage but all the enemies has been slained]\n", *nNameCharacter);
  
}


void 
ChapterEightStory(char *nNameCharacter)
{
  printf("[A final part for the story of %c]\n\n", *nNameCharacter);
  printf("[Will they win against the Americans?]\n\n");
  printf("[Or succumed to the mightiest threats?]\n\n");
  printf("[A fight for freedom for certain people.]\n\n");
  printf("[While for others it is just removing pests]\n\n");
  printf("[Kalayaan o kamatayan?]\n\n");
  printf("[Bayan o sarili?]\n\n");
  printf("[Pumili ka, %c]\n\n", *nNameCharacter);
}

void 
ChapterBossSection(char *nNameCharacter)
{
  printf("\n[July x, xxxx]\n\n");
  printf("[A battle to the death has commence!]\n\n");
  printf("[%c, has managed to exceed all odds and have enough experience]\n\n", *nNameCharacter);
  printf("[to conquer the Final enemy!]\n\n");
  printf("[The one standing in their way]\n\n");
  printf("[for their lands to be liberated against the Americans]\n\n");
  printf("[Ang pag asa ng bayan ay nasa iyo, %c]\n\n", *nNameCharacter);
}

void 
GameWon(char *nNameCharacter)
{
  printf("\n\n");
  DisplayUnderscore();
  printf("\n");
  printf("[%c have defeated the final enemy]\n\n", *nNameCharacter);
  printf("[The one that was the reason on why their parents was slained]\n\n");
  printf("[Despite the low chance of winning]\n\n");
  printf("[%c have gambled and defied fate, they have won!]\n\n", *nNameCharacter);
  printf("[Now the enemies are scattered and confused]\n\n");
  printf("[For their General has perrished.]\n\n");
  printf("[The land that was the reason for %c's misery,]\n\n", *nNameCharacter);
  printf("[is now the land of hope for the future.]\n\n");
  printf("[Because of the bravery and courage of]\n\n");
  printf("[Sakwil ng Anak ng Bayan]\n\n");
  printf("[Good Ending]\n\n");
  printf("[GAME OVER!]\n\n");
  DisplayUnderscore();
  printf("\n\n\n");
}

void 
GameWonButLoss(char *nNameCharacter)
{
  printf("\n\n");
  DisplayUnderscore();
  printf("\n");
  printf("[%c have been defeated by final enemy]\n\n", *nNameCharacter);
  printf("[Their death was not in vain for many has seen how they fell]\n\n");
  printf("[%c's death started a cry for war that lasted for several weeks]\n\n", *nNameCharacter);
  printf("[Though many lives we're lost, the General was defeated]\n\n");
  printf("[And %c was burried in a cemetery for heroes]\n\n",  *nNameCharacter);
  printf("[To forever remember them as what they are].]\n\n");
  printf("[Ang bayani ng bayan]\n\n");
  printf("[Ending]\n\n");
  printf("[GAME OVER!]\n\n");
  DisplayUnderscore();
  printf("\n\n\n");
}

void 
GameEndLoss(char *nNameCharacter)
{
  printf("\n\n");
  DisplayUnderscore();
  printf("\n");
  printf("\n[...]\n");
  printf("\n[You do not have enough experience to defeat the boss.]");
  printf("\n\n[%c, you are killed in battle with a ferocious enemy.]", *nNameCharacter);
  printf("\n\n[Even though you have died.]");
  printf("\n\n[Your ambition will live through others.]");
  printf("\n\n[And perhaps one day, your land will be liberated.]");
  printf("\n\n[Goodbye, %c]", *nNameCharacter);
  printf("\n\n[Bad Ending]");
  printf("\n\n[GAME OVER!]\n\n");
  DisplayUnderscore();
  printf("\n\n\n");
}

void Fleeing()
{
  printf("\n\n");
  DisplayUnderscore();
  printf("\n");
  printf("\n\n[You choose to flee...");
  printf("\n\n[Reasons unknown to the people of Quisao.]");
  printf("\n\n[But they do understand you cowardly act.]");
  printf("\n\n[For they too are scared of the mighty General.]");
  printf("\n\n[Coward's Ending!]");
  printf("\n\n[GAME OVER!]\n\n");
  DisplayUnderscore();
  printf("\n\n\n");

}