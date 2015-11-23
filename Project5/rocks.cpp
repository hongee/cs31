#include <iostream>
#include <cstring>
#include "utilities.h"
using namespace std;

const int MAXWORDS = 9000;

int manageOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum);
bool strExists(const char words[][MAXWORDLEN+1], int nWords, const char comp[]);

int main() {

  char wordList[MAXWORDS][MAXWORDLEN+1];
  int noRounds = 0;
  int noWords = loadWords(wordList, MAXWORDS);
  int maxScore = 0, minScore = 999999, totalScore = 0;

  cout.setf(ios::fixed);
  cout.precision(2);

  cout << "How many rounds do you want to play? ";
  cin >> noRounds;
  cin.ignore(100000,'\n');

  if(noWords < 1) {
    cout << "No words were loaded, so I can't play the game.";
    return 1;
  }

  if(noRounds < 0) {
    cout << "The number of rounds must be positive.";
    return 1;
  }

  //main loop
  for(int r=1;r<=noRounds;r++) {
    int selectedWordIndex = randInt(0, noWords-1);

    cout << endl << "Round " << r << endl ;
    cout << "The secret word is " << strlen(wordList[selectedWordIndex]) << " letters long." << endl;
    cerr << wordList[selectedWordIndex] << endl;

    int attemptsThisRound = manageOneRound(wordList, noWords, selectedWordIndex);

    //got the answer!
    //update the min,max,and total score
    if(attemptsThisRound >= maxScore) {
      maxScore = attemptsThisRound;
    }
    if (attemptsThisRound <= minScore) {
      minScore = attemptsThisRound;
    }
    totalScore += attemptsThisRound;

    if(attemptsThisRound == 1) {
      cout << "You got it in 1 try." << endl;
    } else {
      cout << "You got it in " << attemptsThisRound << " tries." << endl;
    }
    cout << "Average: " << (static_cast<double>(totalScore)/r) << ", minimum: " << minScore << ", maximum: " << maxScore << endl;

  }

  return 0;
}

bool strExists(const char words[][MAXWORDLEN+1], int nWords, const char comp[]) {
  //go through entire array of words. if i find comp, it exists! hoorah.
  for(int i =0;i<nWords;++i) {
    if(strcmp(words[i], comp) == 0) return true;
  }
  return false;
}


int manageOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum) {

  int attemptsThisRound = 0;

  if(nWords < 0 || wordnum < 0 || wordnum >= nWords) return -1;

  for(;;) {
      char inputWord[100];
      cout << "Probe word: ";
      cin.getline(inputWord, 101);

      //safe to check if its def a correct case!
      if(strcmp(words[wordnum], inputWord) == 0) {
        attemptsThisRound++;
        return attemptsThisRound;
      }

      //validate input - check for length and character
      if(strlen(inputWord) > MAXWORDLEN || strlen(inputWord) < MINWORDLEN ) {
        cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
        continue;
      } else {
        for(int i=0;inputWord[i] != '\0';++i) {
          if(!islower(inputWord[i])){
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
          }
        }
      }

      //ensure the string exists inside the array
      if(!strExists(words, nWords, inputWord)) {
        cout << "I don't know that word." << endl;
        continue;
      }

      char ansStr[MAXWORDLEN+1];
      strcpy(ansStr, words[wordnum]);

      //iterate through every letter in the word
      //then every char in the other str
      int r = 0, p = 0;

      //2 loops - one to check for rocks, one to check for pebbles
      //since rock >> pebble (purse probe:terse)
      //remove rocks first, then go for pebbles

      //remove rocks
      for(int k=0;inputWord[k] != '\0'; ++k) {
        if(ansStr[k]=='\0') break;

        //is this a match?
        if(inputWord[k] == ansStr[k]) {
          ansStr[k] = ' '; //remove this character to prevent a repeat
          inputWord[k] = '0'; //remove this character to prevent repeat
          ++r;
          //cout << "Rock match :";
          //cout << ansStr << endl;
        }
      }

      for(int i=0;inputWord[i] != '\0';++i) {
        //all rocks removed, now check pebbles
        for(int k=0;ansStr[k] != '\0'; ++k) {
          //is this a match?
          if(inputWord[i] == ansStr[k]) {
            ansStr[k] = ' '; //remove this character to prevent a repeat
            ++p;
            //cout << "Pebble match :";
            //cout << ansStr << endl;
            //go to next letter!
            break;
          }
        }

      }

      cout << "Rocks: " << r << ", Pebbles: " << p << endl;
      ++attemptsThisRound;
  }

  return attemptsThisRound;

}
