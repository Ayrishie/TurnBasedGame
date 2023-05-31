#include <stdio.h>
#include <Windows.h>
#include "functions.h"

int main()
{
  int DecisionOne = 0,
      nGameEnd = 1,
      nChapters = 1,
      nDifficulty = 0;

      struct Player nMainCharacter;
      nStatsPlayer(&nMainCharacter);

      struct Enemy nColonist;
      nStatsColonist(&nColonist);

      struct Enemy nChicken;
      nStatsChicken(&nChicken);

      struct Enemy nSnake;
      nStatsSnake(&nSnake);
      
      printf("\n\n");
      vPrintTitle();
      vTitleChoice();
      DecisionOne = StartUpMenu(DecisionOne);
  
      nMainCharacter.nPlayerHealth = 100;

      if(nMainCharacter.nPlayerDefense >= 0)
      {
            nMainCharacter.nPlayerDefense = 100;
      }
      else if (nMainCharacter.nPlayerDefense <= 0)
      {
            nMainCharacter.nPlayerDefense = 0;
      }

      nMainCharacter.nPlayerExperience = 0;
 
      if(DecisionOne == 1)
      {
      
      while(nMainCharacter.nPlayerHealth >= 0 && nGameEnd != 0)
       {
            nGameEnd = nChaptersOfStory(&nChapters, &nMainCharacter, &nDifficulty);
       }

      }
      else if (DecisionOne == 2)
      {
            vAbout();
      }
    
      return 0;
}

