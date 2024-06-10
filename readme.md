### Introduction
* **Group members:** 
  * HONG, Yuk Sing 3035927257 
  * FUNG, Ho Sang 3035927386
* Topic: WordlePro
* This is a coursework project that scored full mark (15/15) in HKU.
#
## Game rules
WordlePro is an improved version of the classic wordle game in C++! On top of the normal game rules, WordlePro allows user to select a difficulty level of the hidden word on a scale of 1 to 10. <br /> <br />
A five-letter English word will be randomly picked as the answer of the game. The player must guess the word within six attempts in order to win. After the player made a guess, he/she will know whether the letters exist in the answer word. <br /> <br />
The following symbol will be shown under the letter:
- '=' when the letter exists in the correct position of the answer word
- '/' when the letter exists in the wrong position of the answer word
- 'X' when the letter does not exist in the answer word<br />
#### Example: (Answer word: throw)
![](https://i.imgur.com/2CTGb0N.png)
#### If you want to know more about the rules of a wordle game: https://www.nytimes.com/games/wordle/index.html

## How to play

#### Before playing (Quick start guide):
Save the files in a folder, open terminal, and simply enter the following to play!
- make
- ./main

#### Gameplay procedures:
1. Select the difficulty of the game, ranging from 1 to 10. The higher the difficulty, the higher chance of getting a more obscure answer word.
2. Guess the answer word within six tries

Input algorithm: After each guess is entered, the program will check whether the input is valid or not. The program will first check whether the word is a five-character string or not, then check whether all the character is an alphabet or not. Finally, all the characters will be changed to lowercase and check whether it is an English word or not. If any of the above requirements are not fulfilled, the player will be asked to input a new guess again.

#### Demonstration of WordlePro: https://youtu.be/X0CJcdt2EGY

## Detailed explanation on how the coding requirements support our implemented features
- Coding requirement 1: Generation of random game sets or events <br />
The five-letter answer word is randomly generated from a word bank. <br /> <br />
- Coding requirement 2: Data structures for storing game status <br />
The player's already made guesses (game status) will be stored in a vector. <br /> <br />
- Coding requirement 3: Dynamic memory management <br />
The program contains a string vector that stores all the five-letter English word in alphabetical order, which uses dynamic memory. With this vector, we can use binary search to check whether each guess is an English word or not. Without this arrangement, the run of the program will be very long as simple search of the word list with more than 5000 words will take a very long time. <br /> <br />
- Coding requirement 4: File input/output <br />
Input: The answer word is chosen from a .txt file input. <br />
Output: The player can print the game result to a .txt file. <br /> <br />
- Coding requirement 5: Program codes in multiple files <br />
We used makefile and put some functions in another .cpp file. This allows the execution to be very simple. <br />
##
