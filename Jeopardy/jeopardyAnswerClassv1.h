#ifndef jQuestions
#define jQuestions
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

int dispCount = 0;


class usrCategory {
public:
    int Qlocation;
    void DispVec();
    void setCat(int roundNum);      // Populates a vector with 6 randomly selected categories
    int FindQuestion(int usrRound);
    string GiveString();
    usrCategory();
private:
    int CATEGORY_OG_SIZE;
    int roundNumber;
    vector<string> firstRound;
    vector<string> secondRound;
    vector<string> CATEGORIES;      // UpperCase is not a constant!!!
    vector<string> const catagory = {"University of Cincinnati", "U.S. Presidents", "Game shows", "The year of 1958", "Cincinnati", "Local Buisness", "Kings Island", "Spongebob", "Filmed near Cincinnati", "Coins", "70's Music", "80's Music", "90's Music", "Classic Rap", "Classic Consoles"};
    
  
};

usrCategory::usrCategory(){
  firstRound = {};
  CATEGORY_OG_SIZE = -1;
  Qlocation;
  return;
}

void usrCategory::setCat(int roundNum){
    CATEGORIES = {"University of Cincinnati", "U.S. Presidents", "Game shows", "The year of 1958", "Cincinnati", "Local Buisness", "Kings Island", "Spongebob", "Filmed near Cincinnati", "Coins", "70's Music", "80's Music", "90's Music", "Classic Rap", "Classic Consoles"};

    roundNumber = roundNum;
    int CATEGORY_SIZE = CATEGORIES.size();
    firstRound;
    secondRound;
    string thirdRound;
     

    srand(time(NULL));

    for (int i = 0; i < 6; ++i){
        CATEGORY_SIZE = CATEGORIES.size();
        int value1 = rand() % CATEGORY_SIZE;
        int value2 = rand() % CATEGORY_SIZE;

        firstRound.push_back(CATEGORIES[value1]);
        CATEGORIES.erase(CATEGORIES.begin()+value1);
        secondRound.push_back(CATEGORIES[value2]);
        CATEGORIES.erase(CATEGORIES.begin()+value2);
        
        CATEGORY_OG_SIZE = CATEGORY_SIZE;
    }
    return;
}

void usrCategory::DispVec(){
//  int dispCount = 0;
  if (roundNumber == 1){
        for(int i = 0; i < 6; ++i){
            cout << i+1 << ". " << firstRound[i] << endl;
            
        }
        cout << endl;
    }
    else if (roundNumber == 2) {
        for(int i = 0; i < 6; ++i){
            cout << i+1 << ". " << secondRound[i] << endl;
          
        }
        cout << endl;
    }
    dispCount += 1;
  return;
}

int usrCategory::FindQuestion(int usrRound){
    string foundString = firstRound[usrRound - 1];
    int localSearch = 0;
    //int Qlocation = 0;
    for (int i = 0; i < 14; ++i){
        if(foundString == catagory[i]){
            localSearch = i;
        }
    }
    Qlocation = localSearch+1;
    return Qlocation;
}

string usrCategory::GiveString(){
  string categoryString = catagory[Qlocation-1];
  return categoryString;
}

//---------------------------------------------------------------------------------------------------------^^^--- USR QUESTION ---^^^-----------------------------------------------------------------------------------------------------------------------------------------------

class usrAnswer{
public:
    int usrWager;
    int AIans;
    int cptWager;
    int catLocation;
    int usrBalance;
     int valofgame;
    string usrStr;
    string answerString;
    int aiBalance;
    int roundNumber;
    void innerSwitch(int value, vector<string> answer);
    bool strCmp(string usrStr, string answerString, double accuracy);
    void usrSelect(int catLocation, string questionString,int roundNum);
    int QandA(int usrWager, int catLocation);
    usrAnswer();
    vector<string> const catagory = {"University of Cincinnati", "U.S. Presidents", "Game shows", "The year of 1958", "Cincinnati", "Local Buisness", "Kings Island", "Spongebob", "Filmed near Cincinnati", "Coins", "70's Music", "80's Music", "90's Music", "Classic Rap", "Classic Consoles"};
private:
    double accuracy = 70;
    int value;
};

usrAnswer::usrAnswer(){
    usrBalance = 0;
    aiBalance = 0;
    return;
}

void usrAnswer::usrSelect(int catLocation, string questionString,int roundNum){
    int Q = catLocation;
    int switchQsize;
    roundNumber = roundNum;
    value = 0;
     int AIans;
 if (roundNumber == 3){
     cout <<"This is final Jeopardy" <<endl;
     cout <<"The AI Will only get a turn if you are incorrect" << endl;
     do
     if (usrBalance <= 0 ){
         cout << "You dont have enough to wager in final jeopardy" << endl;
         usrWager = 1;
     }
     else{
     cout <<endl <<"Enter the amount you would like to wager:";
     cin >> valofgame;
     usrWager = 1;
     }
    
     while(valofgame > usrBalance );
 }
 else{
    cout << catagory[catLocation-1] << " for: " << endl
                           << "1. $200.00" << endl << "2. $400.00" << endl << "3. $600.00" << endl << "4. $800.00" << endl << "5. $1000.00" << endl;
    cout << "Choose a number: ";
    cin >> usrWager;
 }
    switch (Q) {
        case 1: // University of Cincinnati
            {
                vector <string> answer = {"cooperative education","mick and mack","benadryl","the tangeman university center","neil armstrong"};
                vector <string> question1 ={"In 1906, UC created this program that combined classroom education with actual work","The two stone lions which adorn the entrance of McMicken Hall","George Rieveschl, a UC graduate and researcher invented this antihistamine","This building was built in 1935, and has a 200 seat movie theater","Taught aerospace engineering at UC from 1971-1980"};
                switchQsize = question1.size();
                value = rand() % switchQsize;
                cout << question1[value] << endl;
                question1.erase(question1.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 2: // U.S. Presidents
            {
                vector <string> answer = {"george washington","andrew johnson","abraham lincoln","lee harvey oswald","john tyler"};
                vector <string> question2 ={"The first president","first to be impeached","Assassinated in fords theatre","accused of te assasination of John F. Kennedy","Was president from 1841-1845"};
                switchQsize = question2.size();
                value = rand() % switchQsize;
                cout << question2[value] << endl;
                question2.erase(question2.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
            
            
        case 3: // Game Shows
            {
                vector <string> answer = {"jeopardy","family feud","the price is right","wheel of fortune","lingo"};
                vector <string> question3 = {"This Game","We asked 100 people","The first episode aired september 4th 1972","The creator is Merv Griffin in 1975","Aired from september 28th, 1987 till august 1st 2011"};
                switchQsize = question3.size();
                value = rand() % switchQsize;
                cout << question3[value] << endl;
                question3.erase(question3.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 4: // The year of 1958
            {
                vector <string> answer = {"44th rosebowl","boac britannia","wmbd tv channel 31","lego company","tim tam"};
                vector <string> question4 = {"Ohio state beats oregon 10-7","Set the record from flying from london to NY","Started broadcasting in peoria IL","Patented design for bricks that are still produced today","84th Kentucky derby winner"};
                switchQsize = question4.size();
                value = rand() % switchQsize;
                cout << question4[value] << endl;
                question4.erase(question4.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 5: // Cincinnati
            {
                vector <string> answer  = {"cincinnati cyclones","cincinnati reds","cincinnati bengals","fc cincinnati","tyler davidson fountain"};
                vector <string> question5 {"They won the 2010 kelly cup finals","This sports team was founded in 1882","This sports team was founded in 1968","This sports team was founded in 2015","This was dedicated was a landmark in 1871"};
                switchQsize = question5.size();
                value = rand() % switchQsize;
                cout << question5[value] << endl;
                question5.erase(question5.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 6: // Local Buisness
            {
                vector <string> answer = {"grippos","rumpke","university of cincinnati","general cable","cintas"};
                vector <string> question6 = {"chip company","family owned commercial waste and recycling firm","public research university that was founded in 1819","Headquarters located in heighland heights kentucky","Uniform supplier in masin, ohio"};
                switchQsize = question6.size();
                value = rand() % switchQsize;
                cout << question6[value] << endl;
                question6.erase(question6.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 7: // Kings Island
            {
                vector <string> answer = {"eiffel tower","cedar fair","paramount studios","top gun","invertigo"};
                vector <string> question7 = {"Kings island has a replica of this","This company bought kings island in 2006","This movie studio owned kings island from 1993-2006","Kings island ride 'the bat' was previously named this","This Kings island ride was manufactured by vexomo"};
                switchQsize = question7.size();
                value = rand() % switchQsize;
                cout << question7[value] << endl;
                question7.erase(question7.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 8: // Spongebob
            {
                vector <string> answer = {"spongebob","glass dome","jelly fish fields","karate island","bubble bass"};
                vector <string> question8 ={"is a sponge","Sandy Cheeks lives here","jelly fish live here","went to this island to learn karate","said 'still no pickles' in episode pickles"};
                switchQsize = question8.size();
                value = rand() % switchQsize;
                cout << question8[value] << endl;
                question8.erase(question8.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 9: // Filmed near Cincinnati
            {
                vector <string> answer = {"little man tate","milk money","traffic", "ides of march","rain man"};
                vector <string> question9 ={"Most of the school scenes were filmed at miami university in oxford,Ohio","The save this money for her services","Filmed on edwards road in Hyde Park","Filmed on the university of cincinnati campus","The famous toothpick scence was shot in newport, KY"};
                switchQsize = question9.size();
                value = rand() % switchQsize;
                cout << question9[value] << endl;
                question9.erase(question9.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break; 
            }
        case 10: // Coins
            {
                vector <string> answer = {"dime","quarter","nickel","sacagawean","cent"};
                vector <string> question10 = {"This coin has a torch and two olive branches on its reverse","Has George Washington on its face and was once made of silver","A buffalo used to be on the reverse of this coin","This coin is worth one dollar and has a femail on it","From 1859-1909 this coin had an indian on its face"};
                switchQsize = question10.size();
                value = rand() % switchQsize;
                cout << question10[value] << endl;
                question10.erase(question10.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 11: // 70's Music
            {
                vector <string> answer = {"american girl","aqualung","baby hold on","band on the run","baracuda"};
                vector <string> question11 = {"Raised on promises She couldn't help thinkin' that there Was a little more to life Somewhere else After all it was a great big world With lots of places to run to Yeah","Sitting on a park bench Eying little girls with bad intent Snots running down his nose Greasy fingers smearing shabby clothes, hey","Baby, what's these things You've been sayin' about me Behind my back Is it true you might want a better life","Stuck inside these four walls Sent inside forever Never seeing no one Nice again like you Mama you, mama you","So this ain't the end, I saw you again today Had to turn my heart away You smiled like the Sun, kisses for everyone"};
                switchQsize = question11.size();
                value = rand() % switchQsize;
                cout << question11[value] << endl;
                question11.erase(question11.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 12: // 80's Music
            {
                vector <string> answer = {"push it","Take on me","jessies girl","whip it","beat it"};
                vector <string> question12 = {"Oooh, baby, baby Baby, baby Oooh, baby, baby Baby, baby Get up on this!","So needless to say I'm odds and ends I'll be stumbling away Slowly learning that life is OK Say after me","I play along with the charade There doesn't seem to be a reason to change You know","Into shape Shape it up Get straight Go forward Move ahead Try to detect it It's not too late","No one wants to be defeated Showin' how funky and strong is your fight It doesn't matter who's wrong or right"};
                switchQsize = question12.size();
                value = rand() % switchQsize;
                cout << question12[value] << endl;
                question12.erase(question12.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 13: // 90's Music
            {
                vector <string> answer = {"creep","tubthumping","waterfalls","pony","iris"};
                vector <string> question13 = {"I don't care if it hurts I want to have control I want a perfect body I want a perfect soul","I get knocked down, but I get up again You are never gonna keep me down","Please stick to the rivers and the lakes that you're used to.I know that you're gonna have it your way","Sitting here flossing Peeping your steelo Just once if I have the chance","And all I can taste is this moment ,And all I can breathe is your life And sooner or later it's over"}; 
                switchQsize = question13.size();
                value = rand() % switchQsize;
                cout << question13[value] << endl;
                question13.erase(question13.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 14: // Classic Rap
            {
                vector <string> answer = {"california love","stan","juicy","regulate","opp"};
                vector <string> question14 = {"In the city of good ol' Watts In the city, the city of Compton We keep it rockin', we keep it rockin","Dear Slim, I wrote you, but you still ain't callin' I left my cell, my pager and my home phone at the bottom","I used to read Word Up magazine Salt'n'Pepa and Heavy D up in the limousine","So I hooks a left on the 21 to Lewis Some brothas shootin dice so I said ‘let's do this’","I'll take it frame by frame it To have y'all all jumping, shouting, saying it"};
                switchQsize = question14.size();
                value = rand() % switchQsize;
                cout << question14[value] << endl;
                question14.erase(question14.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
        case 15: // Classic Consoles
            {
                vector <string> answer = {"vectrex","colecovision","playcable","zemmix","terebikko"};
                vector <string> question15 = {"This console was released in 1982 and was produced by general consumer electronics","This console was released in 1982 by coleco industries","This console was launched in 1981 by mattel, general instrument","This console was manufactured by daewoo electrics in 1985","This console was manufactured by bandai and released in 1988"};
                switchQsize = question15.size();
                value = rand() % switchQsize;
                cout << question15[value] << endl;
                question15.erase(question15.begin()+value);
                innerSwitch(value, answer);
                answer.erase(answer.begin()+value);
                break;
            }
    }
    cout << "Your Balance: $" << usrBalance << endl;
    cout << "The Computers Balance: $" << aiBalance << endl;
    return;
    
}


void usrAnswer::innerSwitch(int value, vector<string> answer){
    answerString = answer[value];
    cout << "Enter your answer: ";
    cin.ignore();
    getline(cin, usrStr);
    cptWager = usrWager;
    
    if(roundNumber == 1){
        valofgame = 200; 
    }
    else{
        valofgame == 400;
    }
    
    
    
    
    
    if (strCmp(usrStr, answerString, accuracy)){
        usrBalance += (usrWager * valofgame);
        cout << "Correct!" << endl;
    }
    else {
        usrBalance -= (usrWager * valofgame);
        cout << "Incorrect." << endl;
        cout << "It is now the computers turn" <<endl;
        AIans = rand() %10;
        if(AIans >= 4){
            cout <<"The computer guessed incorrectly" <<endl;
            aiBalance -= (cptWager * valofgame);
        }
        else{
            cout <<"The computer guessed correctly" <<endl;
            aiBalance += (cptWager * valofgame);
        }
    }
}
bool usrAnswer::strCmp(string usrStr, string answerString, double accuracy){
    int STRING_SIZE = answerString.size();
    int numCorrect = 0;
    for (int i = 0; i < STRING_SIZE; ++i){
        if (usrStr[i] == answerString[i]){
            ++numCorrect;
        }
    }
    
    double percentCorrect = (static_cast<double>(numCorrect)/STRING_SIZE) * 100;
    if (percentCorrect >= accuracy)
        return true;
    else
        return false;
}


#endif
