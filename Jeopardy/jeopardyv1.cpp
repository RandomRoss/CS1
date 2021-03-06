#include <iostream>
#include <string> 
#include <vector>
#include <cctype>
#include "jeopardyAnswerClass.h"
//#include "jeopardyQuestionClass.h"
using namespace std; 
//Game Project: Jeopardy
void introDisp(int &diff);

int main(){
    
    int difficulty = 1;             // variable to declare the difficulty
    int playerammount;              // variable that stores the players ammount 
    int aiammount;                  // variable that stores the AI's ammount 
    int usrRound;
    int roundNum;
    
    introDisp(difficulty);          // Welcoming Screen
    
    // ---------------------------------------------------------------------------------------------------------------- FIRST ROUND 
    roundNum = 1;
    usrCategory usrVec;
    usrVec.setCat(roundNum);
    usrAnswer usrQuestions;
    for (int i = 0; i < 1; ++i){
        cout << endl << "Question " << i+1 << "/10 of JEOPARDY" <<endl;
        cout << endl << "Select one of the following categories." << endl;
        
        usrVec.DispVec();
        cout << "Enter your choice: ";
        cin >> usrRound; //user entering information 
        int catLocation = usrVec.FindQuestion(usrRound);
        usrCategory questionString;
        string categoryString = questionString.GiveString();
        
        
        usrQuestions.usrSelect(catLocation, categoryString,roundNum);
    }

    
    
    // ---------------------------------------------------------------------------------------------------------------- SECOND ROUND -- Double Jeopardy
    cout << endl << "DOUBLE JEOPARDY!" << endl;
    roundNum = 2;
    usrVec.setCat(roundNum);
    usrVec.DispVec();
    for (int i = 0;i < 1; ++i){
        cout << endl << "Question " << i+1 << "/10 of Double JEOPARDY" <<endl;
        cout << endl << "Select one of the following categories." << endl;
        
        usrVec.DispVec();
        cout << "Enter your choice: ";
        cin >> usrRound;
        int catLocation = usrVec.FindQuestion(usrRound);
        usrCategory questionString;
        string categoryString = questionString.GiveString();
        
        
        usrQuestions.usrSelect(catLocation, categoryString,roundNum);
    
    }
    roundNum = 3;
    // ---------------------------------------------------------------------------------------------------------------- THIRD ROUND -- Final Jeopardy
    usrVec.setCat(roundNum);
    usrVec.DispVec();
    for (int i = 0;i < 1; ++i){
        usrVec.DispVec();
        int catLocation = usrVec.FindQuestion(1);
        usrCategory questionString;
        string categoryString = questionString.GiveString();
        
        
        usrQuestions.usrSelect(catLocation, categoryString,roundNum);
    
    }
    
    return 0;
}



void introDisp(int &diff){
    int difficulty = 1;
    int entergame;
    string misc;
    
    // welcoming the player to the game 
    cout << endl << "Welcome to Jeopardy!!" << endl; 
    cout <<"With your host, oh wait this is a computer -- there is no host" << endl << endl;
    
    //this do while loop acts as the starting screen 
    // asking the player to press 1 to enter the game, 2 will view the rules, and 3 will allow the user to change the difficulty
    do {
    cout <<"-Enter 1 to start" << endl <<"-Enter 2 to view the rules of Jeopardy" << endl  <<"-Enter 3 to change difficulty (default is easy)"<< endl << endl;  
    cout << "Enter Here: ";
    cin >> entergame;
    if(entergame == 2){
        // --------------------------------------------------- displaying the rules of the gameshow jeopardy 
        cout << "The Rules of the Game Show Jeopardy" << endl << endl; 
        cout << "1. You can play by yourself or in a group" << endl; 
        cout << "2. You will pick a catagory and a point value (once the catagory and value has been picked one it cannot be picked again)" << endl; 
        cout << "3. Once you select the category and the value, you will be prompted with a question, your answer to this question will be" << endl << "compared to the correct answer based on your level of difficulty." << endl; 
        // cout << "must be giving in the form of a question, meaning starting with 'what is','who is',and'where is' to recive points" <<endl;
        //cout << "for the question even if the question is right or wrong" <<endl; 
        cout << "4. If the player is correct then the value of that category is added to the players total score" << endl; 
        cout << "5. If the player is incorrect then the question is asked to the AI (The percentage of The AI getting the answer right depends on difficulty)" << endl; 
        cout << "6. At the end of each question the amount of money the player and the AI have will be displayed" << endl; 
        cout << "7. There will be three rounds consisting of" <<endl; 
        cout << "   - Jeopardy" <<endl;
        cout << "   - Double Jeopardy" <<endl;
        cout << "   - Final Jeopardy" << endl << endl; 
        cout << "During final Jeopardy the player and the AI wager an ammount. If the player answers the question correctly, the amount wagered will be added." <<endl; 
        cout << "If the player gets the question incorrect, the amount wagered will be taken away from the users total amount" << endl << endl; 
        cout << "Enter anything to return to game: ";
        cin >> misc;
    }
    else if (entergame == 3){
    //changing the difficulty of the game 
    //1 being easy 70 percent must be correct 
    //2 being medium 80 percent must be correct 
    //3 being hard 90 percent must be correct
    cout <<"Difficulty" << endl << "1 Easy" << endl << "2 Medium" <<endl <<"3 Hard" <<endl;
    cout << "Please Enter the Value related with the difficulty: " ;
    cin >> difficulty;
    }
    
    }while(entergame != 1);
    
    return;
}
