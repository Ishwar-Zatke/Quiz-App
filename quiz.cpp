#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

string player_name;
bool Skip = true ;
int score=0;
int question_score = 10;
int consecutive =0;
int right_answer = 0;
int wrong_answer = 0;
int question_no =1;

class Questions{
    public:
    string question;
    string option_a, option_b, option_c, option_d;
    char answer;
    bool available;
}question[10];

void Answer_func(char Answer, char correct_answer) {
    if(Answer == correct_answer) {
        cout << "Congratulations...! Your answer is right" <<endl;
        cout << "You earned " << question_score << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        right_answer++;
        consecutive++;
        score =score + question_score;
    }
    else if ((Answer == 's') && (Skip)) {
        cout << "You choose the Lifeline SKIP" <<endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        Skip = false;
    }


    else {
        cout << "Sorry...! Your answer is wrong..." <<endl;
        cout << "You lose " <<question_score/2 << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        wrong_answer++;
        consecutive = 0;
        score = score - (question_score/2);
    }
    question_score = question_score*2;
    if(consecutive==3){
        Skip = true;}
}

void ask_question(){
    srand(time(0));
    while(true) {
        system("cls");
        int number = rand()%10;        //Local Variable
        if(question[number].available){
            question[number].available = false;
        cout <<"************************************************************************"<<endl;
        //cout<< endl;
        cout <<"The Question No: "<<question_no << " is for "<<question_score<<"\t\t\t\tBalance: "<<score<<endl;
        cout << "Life Lines:\t" ;
        if(Skip){
            cout << "s == SKIP THE QUESTION" << endl;}
        cout <<endl;
        cout << "***************************  CHOOSE OPTION  ***************************" << endl << endl;
        cout << question[number].question  << endl << endl;
        cout << "a)"<< question[number].option_a<< "\t\t b)" << question[number].option_b << endl << endl;
        cout << "c)"<< question[number].option_c<< "\t\t d)" << question[number].option_d << endl << endl;
        string phrase1 ="Answer the question";
        string command1 = "espeak \""+phrase1+"\"";
        const char* charcommand1=command1.c_str();
        system(charcommand1);
        char answer;
        answer=_getch();
        answer = tolower(answer);   //lowercase
        cout << endl;
        question_no ++;
        Answer_func(answer, question[number].answer);
        break;
        }
    }
}

void result(){
    cout << "****************************** Results *********************************" << endl;
    cout << endl;
    cout << "Player Name: \t\t\t" << player_name << endl;
    cout << "Right Answers: \t\t\t" << right_answer << endl;
    cout << "Wrong Answer: \t\t\t" << wrong_answer << endl;
    if(score>40){
        cout << "Winning Score: " << score << endl;
        string phrase2 ="Congratulations, you win";
        string command2 = "espeak \""+phrase2+"\"";
        const char* charcommand2=command2.c_str();
        system(charcommand2);}
    else{
        cout << "You Lose" << endl;
        string phrase2 ="Sorry, you lose";
        string command2 = "espeak \""+phrase2+"\"";
        const char* charcommand2=command2.c_str();
        system(charcommand2);}
}

void game_rules(){
    cout << "\n========================= RULES AND REGULATIONS ========================\n" << endl<<endl;
    cout << " 1. There will one of he four option correct of the question." << endl<<endl;
    cout << " 2. Question score will be doubled at every next question." << endl<<endl;
    cout << " 3. A skip lifeline can be used to skip the question by paying half of question score." << endl<<endl;
    cout << " 4. The lifeline will be disabled until 3 consecutive three question got correct answer." << endl<<endl;
    cout << " 5. Answer the as maximum questions as you can." << endl<<endl;
    string phrase3 ="Read the following rules and regulations";
        string command3 = "espeak \""+phrase3+"\"";
        const char* charcommand3=command3.c_str();
        system(charcommand3);
        _getch();
        system("cls");
}

int main(){
   system("cls");
   question[0] = {"Which programming structure makes a comparison?", "relation","decision" , "sequence", "repetation",'b', true};
   question[1] = {"A loop within a loop is called?","nested loop","complex loop","infinite loop","finite loop",'a',true};
   question[2] = {"Which acid is formed by ant bite","formic acid","carbonyl acid","carboxylic acid","citric acid",'a',true};
   question[3] = {"Rh factor is fined in","Iris","Lymph","Blood","Sputum",'c',true};
   question[4] = {"Who discovered gravity","Issac Newton","Albert Einstein","Neil Bohr","None of these",'a',true};
   question[5] = {"The statement which activates a function is called?","Function implement","line","Function calling","All of the above",'c',true};
   question[6] = {"Which statement causes the loop to terminate early?","continue","break","pass","sleep",'b',true};
   question[7] = {"The index of first element in an array is?","0","1","-1","2",'a',true};
   question[8] = {"What holds the similar type of data?","constant","string","array","None",'c',true};
   question[9] = {"The fungal derivative used in the treatment of tuberculosis is","Anacin","Tetracyclin","Both A and B","Sptreptomycin",'d',true};
   cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" <<endl;
   cout << "================================== WELCOME TO THE QUIZ =================================" <<endl;
   cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" <<endl;
   cout << "Enter your Name: ";
   string phrase ="Enter your Name";
   string command = "espeak \""+phrase+"\"";
   const char* charcommand=command.c_str();
   system(charcommand);
   cin >> player_name;
   system("cls");
   game_rules();
   while(true) {
    if(question_no>10){
        break;}
    ask_question();
   }
   system("cls");
   result();
   return 0;
}
