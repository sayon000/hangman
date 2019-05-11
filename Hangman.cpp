//============================================================================
// Name        : Hangman.cpp
// Author      : Sk Ayon
// Version     :
// Copyright   :
// Description : Hangman in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check(string s, char c){
   for(int i = 0; i < s.size(); i++){
    if(s[i] == c){
        return true;
        }
   }
   return false;
}

void replace(string s, char c, string r){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c){
            r[i] = c;
        }
    }
}

string makeHidden(string s){
    string r = "";
    for(int i = 0; i < s.size(); i++){
        r += "*";
    }
    return r;
}


int main(){
    string myWords[10] = {"water","apple","tacos","fight","shoes","bears","dizzy","pulls","pinch","ninja"};
    cout << "Let's play. A word has been made" << endl;
    int wrong = 0;
    char guess;
    srand(time(0));
    string word = myWords[(rand() % 10 )];
    string hidden = makeHidden(word);
    bool win = false;
    while(wrong < 8 && !win){
        cout << "This is your stuff so far: " << hidden << endl;
        cout << "You have " << 8 - wrong << " guesses" << endl;
        cout << "Put your next guess" << endl;
        cin >> guess;
        if(check(word,guess)){
            for(int i = 0; i < word.size(); i++){
                if(word[i] == guess){
                    hidden[i] = guess;
        }
    }
        }
        else{
            wrong++;
        }
        if(hidden == word){
            win = true;
        }
    }
    cout << "This is the word: " << word << endl;
    if(win){
            cout << "Good job";
    }
    else{
            cout << "You lost";
    }
    return 0;
}
