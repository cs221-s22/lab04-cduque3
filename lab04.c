#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//set default values within tic-tac-toe board
char* position[] = {" ","?", "?", "?", "?", "?", "?", "?", "?", "?"};

//print the board, values vary based on input
void printBoard() {

   printf("%s | %s | %s\n", position[1], position[2], position[3]);
   printf("--+---+--\n");
   printf("%s | %s | %s\n", position[4], position[5], position[6]);
   printf("--+---+--\n");
   printf("%s | %s | %s\n", position[7], position[8], position[9]);

}


//fills values of board with given input
void fillValues(int fill, char* input) {
   position[fill] = input;
}

//go through each winning combination, message displayed + program ends if one is found
int checkWin(char* input) {

   //Horizontal Wins
   if((strcmp(position[1], input) == 0) && (strcmp(position[2], input) == 0 ) && (strcmp(position[3], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
   if((strcmp(position[4], input) == 0) && (strcmp(position[5], input) == 0 ) && (strcmp(position[6], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
   if((strcmp(position[7], input) == 0) && (strcmp(position[8], input) == 0 ) && (strcmp(position[9], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }

   //Vertical Wins
   if((strcmp(position[1], input) == 0) && (strcmp(position[4], input) == 0 ) && (strcmp(position[7], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
   if((strcmp(position[2], input) == 0) && (strcmp(position[5], input) == 0 ) && (strcmp(position[8], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
   if((strcmp(position[3], input) == 0) && (strcmp(position[6], input) == 0 ) && (strcmp(position[9], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }

   //Diagonal Wins
   if((strcmp(position[1], input) == 0) && (strcmp(position[5], input) == 0 ) && (strcmp(position[9], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
   if((strcmp(position[3], input) == 0) && (strcmp(position[5], input) == 0 ) && (strcmp(position[7], input) == 0 )) {
      printf("%s wins\n", input);
      exit(0); }
}

int main(int argc, char *argv[]) {

   //error handling: user must enter correct number of arguments
   if(argc != 10) {
      printf("Invalid number of arguments");
      return -1; }

   //error handling: user must enter correct values
   for(int i = 1; i <= 9; i++) {
      if((strcmp(argv[i],"O") == 0) || (strcmp(argv[i],"X") == 0) || (strcmp(argv[i],"?") == 0)) {
         continue; }
      else {
         printf("Accepted arguments: ? , X , O");
         return -1; }
   }

   //use loop to fill values
   for(int i = 1; i <= 9 ; i++) {
      fillValues(i, argv[i]);
   }

   //variable to determine is board is filled
   bool finished = true;

   //a "?" indicates that the board hasn't filled up yet, prevents a draw
   for(int i = 1; i <= 9 ; i++) {
      if(strcmp(argv[i], "?") == 0) {
         finished = false; }
   }

   printBoard();

   //check if X won
   checkWin("X");

   //check if O won
   checkWin("O");

   //draw printed if neither have won
   if(finished){
    printf("draw");
   return 0; }
}
