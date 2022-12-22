#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "How many word in list?" << endl;                           //How many words?
    cin >> n;

    string* words = new string[n];
    cout << "Write words:" << endl;

    for (int i = 0; i < n; i++) {                                 //Write words in massiw with words
        cin >> words[i];
    }

    int howManyWords = 1;
    string* answer = new string[2];


    string firstWord;
    int letter = 3;

    for (int i = 0; i < n; i++) {                               //Cikl for finding 3-letter word
        if (words[i].length() == letter) {
            answer[howManyWords-1] = words[i];

        }
    }

    string anotherLetter;

    letter++;
    int letterSacesfull = 0;
    bool taskOff = false;


    while(taskOff == false)
    {
        taskOff = true;
        for (int i = 0; i < n; i++) {
            if (words[i].length() == letter) {                                                  //Finding 4,5,...-letter word
                for (int k = 0; k < letter - 1; k++) {
                    for (int j = 0; j < letter; j++) {
                        if (answer[howManyWords - 1][k] == words[i][j]) {                      //Match check (letter - 1)
                            letterSacesfull++;
                        }
                    }
                }

            }
            if ((letterSacesfull+1) == letter) {                                               //write answer on massiw "answer[]" if true
                howManyWords = howManyWords + 1;
                answer[howManyWords - 1] = words[i];
                letterSacesfull = 0;
                taskOff = false;

                for (int k = 0; k < letter; k++) {                                     //Finding another letter
                    for (int j = 0; j < letter - 1; j++) {                             //########################
                        if (words[i][k] == answer[howManyWords - 2][j]) {
                            letterSacesfull++;
                        }
                    }
                    if (letterSacesfull < 1) {
                        letterSacesfull = 0;
                        anotherLetter = anotherLetter + words[i][k];
                    }
                    else {
                        letterSacesfull = 0;
                    }
                }
                letter = letter + 1;                                                    //#########################
            }
        }
    }
    cout << answer[0];                                    //cout answer on task
    for (int i = 1; i < howManyWords; i++) {
        cout << " + " << anotherLetter[i-1] << " -> " << answer[i] ;
    }

    return 0;
}
