#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){

    int num;
    int guess;
    int tries;
    

    srand(time(NULL));
    num = (rand() % 100) + 1;

   
    cout<<"********* GUESS THE NUMBER GAME *********"<<endl;
    cout<<"Welcome to the game\nTry to guess the number ranging from 1-100 in 7 tries "<<endl;
    cout<<"----Lets start the game----"<<endl;
  
    for(tries = 7;tries >= 1;tries--){

        cout<<"Enter your Guess: ";
        cin>>guess;

        if(tries == 6 || tries == 4){
            if(guess > num){
                cout<<"Too High! Try Again...."<<endl;
            }
            else if(guess < num){
                cout<<"Too Low! Try Again....."<<endl;
            }
            else{
                cout<<"CORRECT!!!!"<<endl;
                break;
            }
            cout<<"tries left: "<<tries-1<<endl;
            cout<<"************************"<<endl;
        }
         
        else if(tries == 7){
            if(guess > num){
                cout<<"Too High!"<<endl;
            }
            else if(guess < num){
                cout<<"Too Low!"<<endl;
            }
            else{
                cout<<"CORRECT!!!!"<<endl;
                break;
            }
           
            if(num > 50)
            cout<<"Hint: The number is greater than 50"<<endl;
            else
            cout<<"Hint: The number is less than 50"<<endl;
            cout<<"tries left: "<<tries-1<<endl;
            cout<<"************************"<<endl;
        }

        
        else if(tries == 5){
            if(guess > num){
                cout<<"Too High!"<<endl;
            }
            else if(guess < num){
                cout<<"Too Low!"<<endl;
            }
            else{
                cout<<"CORRECT!!!!"<<endl;
                break;
            }
           
            if(num % 2 == 0)
            cout<<"Hint: The number is even"<<endl;
            else
            cout<<"Hint: The number is odd"<<endl;
            cout<<"tries left: "<<tries-1<<endl;
            cout<<"************************"<<endl;
        }

        
        else if(tries == 3 || tries == 2){

             if(guess > num){
                cout<<"Go Higher!";
            }
            else if(guess < num){
                cout<<"Go Lower!";
            }
            else{
                cout<<"CORRECT!!!!"<<endl;
                break;
            }


            if(abs(guess - num) <= 2 ){
                cout<<"Very Close!"<<endl;
            }
            else if(abs(guess - num) <= 5){
                cout<<"Close!"<<endl;
            }
            else if(abs(guess - num) <= 10){
                cout<<"Still Far...";
            }
            
            cout<<"tries left: "<<tries-1<<endl;
            cout<<"************************"<<endl;
        }

        
        else if(tries == 1){
            if(guess > num){
                cout<<"Too High!"<<endl;
            }
            else if(guess < num){
                cout<<"Too Low!"<<endl;
            }
            else{
                cout<<"CORRECT!!!!"<<endl;
                break;
            }
           
            cout<<"YOU LOST"<<endl;
            cout<<"tries left: "<<tries-1<<endl;
            cout<<"************************"<<endl;
        }
        
    }
     cout<<"-----Game Over-----";
    return 0;
}