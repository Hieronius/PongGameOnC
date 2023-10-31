//
//  main.c
//  PongGameOnC
//
//  Created by Арсентий Халимовский on 31.10.2023.
//

#include <stdio.h>

void printTable(int playerOneRocketView, int playerTwoRocketView, int ballView);

int playerTurn(char key, int currentPosition);

int main() {
  int playerRocket1 = 12;
  int playerRocket2 = 12;
  int currentBallPosition = 1;
  int previousBallPosition;
  int playerOneScore = 0;
  int playerTwoScore = 0;

  while (playerOneScore < 21 || playerTwoScore < 21) {
    if (playerOneScore == 21) {
      printf("Player 1 win! Congratulations!");
      break;
    } else if (playerTwoScore == 21) {
      printf("Player 2 win! Congratulations!");
      break;
    }

    char key;
    key = getchar();
    //
    if (key == 'a' || key == 'z') {
      playerRocket1 = playerTurn(key, playerRocket1);
      if (currentBallPosition == 1 &&
          (playerRocket1 == 11 || playerRocket1 == 12 || playerRocket1 == 13)) {
        previousBallPosition = currentBallPosition;
        currentBallPosition++;
        printTable(playerRocket1, playerRocket2, currentBallPosition);

      } else if (currentBallPosition == 78 &&
                 (playerRocket2 == 11 || playerRocket2 == 12 ||
                  playerRocket2 == 13)) {
        previousBallPosition = currentBallPosition;
        currentBallPosition--;
        printTable(playerRocket1, playerRocket2, currentBallPosition);

      } else if (currentBallPosition == 1 &&
                 (playerRocket1 != 11 && playerRocket1 != 12 &&
                  playerRocket1 != 13)) {
        playerTwoScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore, playerTwoScore);
        currentBallPosition = 1;
        previousBallPosition = 0;
        playerRocket1 = 12;
        playerRocket2 = 12;

      } else if (currentBallPosition == 78 &&
                 (playerRocket2 != 11 && playerRocket2 != 12 &&
                  playerRocket2 != 13)) {
        playerOneScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore, playerTwoScore);
        currentBallPosition = 78;
        previousBallPosition = 0;
        playerRocket1 = 12;
        playerRocket2 = 12;

      } else if (currentBallPosition > 1 && currentBallPosition < 78) {
        if (previousBallPosition < currentBallPosition) {
          previousBallPosition = currentBallPosition;
          currentBallPosition++;
          printTable(playerRocket1, playerRocket2, currentBallPosition);

        } else if (previousBallPosition > currentBallPosition) {
          previousBallPosition = currentBallPosition;
          currentBallPosition--;
          printTable(playerRocket1, playerRocket2, currentBallPosition);
        }

      } else {
        printf("Ball motion mistake!\n");
      }

    } else if (key == 'k' || key == 'm') {
      playerRocket2 = playerTurn(key, playerRocket2);
      {
        if (currentBallPosition == 1 &&
            (playerRocket1 == 11 || playerRocket1 == 12 ||
             playerRocket1 == 13)) {
          previousBallPosition = currentBallPosition;
          currentBallPosition++;
          printTable(playerRocket1, playerRocket2, currentBallPosition);

        } else if (currentBallPosition == 78 &&
                   (playerRocket2 == 11 || playerRocket2 == 12 ||
                    playerRocket2 == 13)) {
          previousBallPosition = currentBallPosition;
          currentBallPosition--;
          printTable(playerRocket1, playerRocket2, currentBallPosition);

        } else if (currentBallPosition == 1 &&
                   (playerRocket1 != 11 && playerRocket1 != 12 &&
                    playerRocket1 != 13)) {
          playerTwoScore++;
          printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore,
                 playerTwoScore);
          currentBallPosition = 1;
          previousBallPosition = 0;
          playerRocket1 = 12;
          playerRocket2 = 12;

        } else if (currentBallPosition == 78 &&
                   (playerRocket2 != 11 && playerRocket2 != 12 &&
                    playerRocket2 != 13)) {
          playerOneScore++;
          printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore,
                 playerTwoScore);
          currentBallPosition = 78;
          previousBallPosition = 0;
          playerRocket1 = 12;
          playerRocket2 = 12;

        } else if (currentBallPosition > 1 && currentBallPosition < 78) {
          if (previousBallPosition < currentBallPosition) {
            previousBallPosition = currentBallPosition;
            currentBallPosition++;
            printTable(playerRocket1, playerRocket2, currentBallPosition);

          } else if (previousBallPosition > currentBallPosition) {
            previousBallPosition = currentBallPosition;
            currentBallPosition--;
            printTable(playerRocket1, playerRocket2, currentBallPosition);
          }
        } else {
          printf("Ball motion mistake!\n");
        }
      }
    } else if (key == ' ') {
      if (currentBallPosition == 1 &&
          (playerRocket1 == 11 || playerRocket1 == 12 || playerRocket1 == 13)) {
        previousBallPosition = currentBallPosition;
        currentBallPosition++;
        printTable(playerRocket1, playerRocket2, currentBallPosition);

      } else if (currentBallPosition == 78 &&
                 (playerRocket2 == 11 || playerRocket2 == 12 ||
                  playerRocket2 == 13)) {
        previousBallPosition = currentBallPosition;
        currentBallPosition--;
        printTable(playerRocket1, playerRocket2, currentBallPosition);

      } else if (currentBallPosition == 1 &&
                 (playerRocket1 != 11 && playerRocket1 != 12 &&
                  playerRocket1 != 13)) {
        playerTwoScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore, playerTwoScore);
        currentBallPosition = 1;
        previousBallPosition = 0;
        playerRocket1 = 12;
        playerRocket2 = 12;

      } else if (currentBallPosition == 78 &&
                 (playerRocket2 != 11 && playerRocket2 != 12 &&
                  playerRocket2 != 13)) {
        playerOneScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore, playerTwoScore);
        currentBallPosition = 78;
        previousBallPosition = 0;
        playerRocket1 = 12;
        playerRocket2 = 12;

      } else if (currentBallPosition > 1 && currentBallPosition < 78) {
        if (previousBallPosition < currentBallPosition) {
          previousBallPosition = currentBallPosition;
          currentBallPosition++;
          printTable(playerRocket1, playerRocket2, currentBallPosition);

        } else if (previousBallPosition > currentBallPosition) {
          previousBallPosition = currentBallPosition;
          currentBallPosition--;
          printTable(playerRocket1, playerRocket2, currentBallPosition);
        }

      } else {
        printf("Ball motion mistake!\n");
      }

    } else if (key == 'q') {
      printf("Player 1: %d\nPlayer 2: %d\n", playerOneScore, playerTwoScore);
      break;
    }
  }
}

int playerTurn(char key, int currentPosition) {
  if ((key == 'a') || (key == 'k') || (key == 'A') || (key == 'K')) {
    if (currentPosition > 2) {
      currentPosition--;
    }
  } else if ((key == 'z') || (key == 'm') || (key == 'Z') || (key == 'M')) {
    if (currentPosition < 22) {
      currentPosition++;
    }
  }
  return currentPosition;
}

void printTable(int playerOneRacketView, int playerTwoRacketView,
                int ballView) {
  for (int height = 0; height < 25; height++) {
    for (int width = 0; width < 80; width++) {
      if (height == 0 || height == 24) {
        printf("-");

      } else if (((height == playerOneRacketView ||
                   height == playerOneRacketView + 1 ||
                   height == playerOneRacketView - 1) &&
                  width == 0) ||
                 ((height == playerTwoRacketView ||
                   height == playerTwoRacketView + 1 ||
                   height == playerTwoRacketView - 1) &&
                  width == 79)) {
        printf("|");

      } else if (height == 12 && width == ballView) {
        printf("o");

      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}


