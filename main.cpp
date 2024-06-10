#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include "num_of_existence_in_string.h"
using namespace std;

vector<string> guessBoard;
vector<string> word_bank_sort;

int numThisCharCorrect (char c, string g, string a) { 		// count the number of char that is equal to the answer
    int count = 0;
    for (int i=0; i<5; i++) {
        if (a[i] == g[i] && g[i] == c) {
            count += 1;
        }
    }
    return count;
}

void checkAns(string g, string a) { // g: The player's guess, a: The answer word
    string existedChar = "";
    for (int i=0; i<5; i++) { // goes through each letter in the guess
        if (g[i] == a[i]) {
            cout << '=';                         // The guess letter exists at the correct position
        }
        else if (g[i] != a[i] && (g[i]==a[0]||g[i]==a[1]||g[i]==a[2]||g[i]==a[3]||g[i]==a[4]) && ( numThisCharCorrect(g[i], g, a) + count(existedChar.begin(), existedChar.end(), g[i]) < numExistenceInString(g[i], a) )) {
            cout << '/';                         // The guess letter exists at a different position
            existedChar += g[i];
        }
        else {
            cout << 'X';                         // The guess letter does not exist
        }
    }
    cout << endl;
}

void printBoard(int n, string answer) {				// print the board to the screen, showing the current guess and previous guess
    cout << "--------------------------------------- " << endl;
    cout << "Current guess: " << endl;
    for (int i=0; i<=n; i++) {
        if (i>0) {cout << "-----" << endl;}
        cout << guessBoard[i] << endl;
        checkAns(guessBoard[i], answer);
    }
    cout << "--------------------------------------- " << endl;
}

string generate_ans(int level){
    srand(time(NULL));				//using current time as a seed to generate ans
    int pos=rand()%(500*level+1)+1;		// higher difficulty has a larger range of word choice, so the word will be more uncommon and diffcult to guess
    char filename[80] = "word_bank.txt";
    ifstream fin;
	fin.open(filename);
    if (fin.fail()){
        cout << "Please restart the program!!" << endl;
        exit(1);
    }
    string ans;
    for (int i=0; i<=pos; i++){			//loop the whole txt file until the designated word is reach and return it
        fin >> ans;
    }
    return ans;
}

void make_word_list(){				// make a vector list of storing all the sort word list when the game in initialized 
    char filename[50] = "word_bank_sorted.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail()){
        cout << "Please restart the program!!" << endl;
        exit(1);
    }
    string word;
    while (fin >> word){
        word_bank_sort.push_back(word);		// add word in the word list to the vector
    }
}

bool in_word_list(int l, int r, string x){		//check whether the user input is in the word bank so that it is a valid user input, this function return a boolean 
     if (r >= l) {
        int mid = l + (r - l) / 2;
        if (word_bank_sort[mid] == x)
            return true;
        if (word_bank_sort[mid] > x)
            return in_word_list( l, mid - 1, x);
        return in_word_list(mid + 1, r, x);
    }
    return false;
}

void input(string & input_text){
    cout << "Enter a guess: ";
    cin >> input_text;
    int count=0;
    while (true){
        while (input_text.length() != 5) {                              // check length of the input text
            cout << "The word must be 5 letters long! " << endl;
            cin >> input_text;
        }
        count=0;
        for (int i=0; i<5; i++){
            if (isalpha(input_text[i])){                            // check whether the character is a alphabet
                count++;                                            // count the number of character reach the formatting requirement
                input_text[i]=tolower(input_text[i]);
            }
        }
        if (count!=5){						// if not all the charcter is a alphabet, ask user to enter again
            cout << "Please enter a word! " << endl;
            cin >> input_text;
        }
        else{
            break;
        }
    }
    if (!in_word_list(0,word_bank_sort.size(),input_text)){	// check whether the word is a vaild English word
        cout << "please enter a valid word!" << endl;
        input(input_text);
    }
}

int main() {
    cout << "Initializing the game, this takes some time...." << endl;
    make_word_list();
    cout << "Welcome to play C++ Wordle!!! \nIn this game, you need to guess a five-letter word. You have six chances to guess the word and each guess must be a valid English word. \nAfter each guess, a symbol will appear under each characters. \n'=' represents that character is in the word. \n'/' represents that character is in the word but in the wrong position. \n'X' represents that character is not in the word in any position." << endl;
    string answer;
    int level=-1;
    while (level >10 || level < 1){
        cout << "Please enter difficulty (1-10); level 1 is the easiest while level 10 is the hardest!  ";
        cin >> level;
    }
    answer=generate_ans(level);			//generating answer, level of difficulty will be consider
    int numGuess = 0;
    string input_text;
    input(input_text);
    guessBoard.push_back(input_text);		// store each guess in a vector file
    
    while (numGuess <= 5) {
        printBoard(numGuess, answer);
        numGuess += 1;
        if (guessBoard[numGuess-1] == answer) {
            cout << "Bravo! You guessed the right word!" << endl;
            break;
        }
        if (numGuess==6 && guessBoard[numGuess-1] != answer ){
            cout << "You lost the game! The answer was " << answer << "." << endl;
            break;
        }
        cout << "You still have "<< 6-numGuess << " chance(s), Guess again: " << endl;
        input(input_text);
        guessBoard.push_back(input_text);		// store each guess in the vector file
    }
    cout << "Do you want to save game result to .txt file? (y/n): ";
    string printPreference;
    cin >> printPreference;
    while (printPreference!="y" && printPreference!="n") {
        cout << "Invalid input! Do you want to save game result to .txt file? (y/n): ";
        cin >> printPreference;
    }
    if (printPreference == "y") {
        cout << "Sure, see you again!" << endl;
        freopen("game_results.txt","a",stdout);
        printBoard(numGuess-1, answer);
        
    }
    if (printPreference == "n") {
        cout << "Alright, see you again!" << endl;
    }
    return 0;
}
