//
// Created by Shams Reza Sajid on 2022-11-07.
// Course CMPE 320
//

#include "jumble_19srs12.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Creating the Exception to throw the error
BadJumbleException::BadJumbleException(const string& m): message(m) {}
string& BadJumbleException::what() { return message; }


// ##----------- Accessor Methods ------------##
int JumblePuzzle::getSize() const { return size; }
int JumblePuzzle::getRowPos() const { return row; }
int JumblePuzzle::getColPos() const { return column; }
char JumblePuzzle::getDirection() const { return direction; }
charArrayPtr* JumblePuzzle::getJumble() const {
    charArrayPtr* newMatrix = new char*[size];

    for (int i = 0; i < size; i++)
        newMatrix[i] = new char[size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            newMatrix[i][j] = matrix[i][j];
    }

    return newMatrix;
}


// ##-------------- Main Constructor ---------------##
JumblePuzzle::JumblePuzzle(const string& word, const string& difficulty) {
    if (word.length() < 3 || word.length() > 10)
        throw BadJumbleException( "Size of the hidden word must be between 3 and 10 characters. Please try again.");

    if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard")
        throw BadJumbleException("Invalid difficulty selection. Difficulty selection must be easy, medium or hard.");

    this-> difficulty = difficulty;

    // setting the difficulty levels
    if (difficulty == "hard")
        size = 4 * word.length();

    else if (difficulty == "medium")
        size = 3 * word.length();

    else
        size = 2 * word.length();

    // Generating a table of random characters
    srand(time(nullptr));
    matrix = new char*[size];

    // Making the matrix 2D and then adding columns with available letters
    for (int x = 0; x < size; x++){
        matrix [x] = new char [size];

        for (int y = 0; y < size; y++){
            matrix [x][y] = 'a' + rand()%26;
        }
    }

    // Hiding the word
    row = rand() % size;
    column = rand () % size;

    // Putting the first letter down in the matrix
    matrix [row][column] = word.at(0);

    const char* dir = "nesw"; // String directions
    bool placeWord = 0;

    while (!placeWord){

        // Picking a random direction
        direction = dir [rand() % 4];

        // Placing the characters going upward
        if (direction == 'n'){

            for (int i = 1; i < word.length(); i++){
                // If it is out of bounds then it will try another direction
                if ((row - 1) < 0)
                    break;

                // Final letter of word
                else if (i == (word.length() - 1)){
                       matrix[row - i][column] = word.at(i);
                       placeWord = 1;
                }
                else
                    matrix[row - i][column] = word.at(i);
            }
        }

        // Placing the characters going to the right
        else if (direction == 'e'){
            for (int i = 1; i < word.length(); i++){
                // If it is out of bounds then it will try another direction
                if ((column + 1) > (size - 1))
                    break;

                // Final letter of word
                else if (i == (word.length() - 1)){
                    matrix[row][column + i] = word.at(i);
                    placeWord = 1;
                }
                else
                    matrix[row][column + i] = word.at(i);
            }
        }

        // Placing the characters going down
        else if (direction == 's'){
            for (int i = 1; i < word.length(); i++){
                // If it is out of bounds then it will try another direction
                if ((row + 1) > (size - 1))
                    break;

                // Final letter of word
                else if (i == (word.length() - 1)){
                    matrix[row + i][column] = word.at(i);
                    placeWord = 1;
                }
                else
                    matrix[row + i][column] = word.at(i);
            }
        }

        // Placing the characters going to the left (for direction == 'w')
        else{
            for (int i = 1; i < word.length(); i++){
                // If it is out of bounds then it will try another direction
                if ((column - 1) < 0)
                    break;

                // Final letter of word
                else if (i == (word.length() - 1)){
                    matrix[row][column - i] = word.at(i);
                    placeWord = 1;
                }
                else
                    matrix[row][column - i] = word.at(i);
            }
        }
    }
}

// ##-------------- Copy Constructor ---------------##
JumblePuzzle::JumblePuzzle(const JumblePuzzle& jp) {
    size = jp.getSize();
    row = jp.getRowPos();
    column = jp.getColPos();
    direction = jp.getDirection();

    // Creating individual arrays on the heap and copying values into matrix from other JumblePuzzle
    matrix = new charArrayPtr [jp.size];
    for (int x = 0; x < jp.size; x++)
        matrix [x] = new char[jp.size];

        for (int i = 0; i < jp.size; i++){
            for (int j = 0; j < jp.size; j++){
                matrix[i][j] = jp.matrix[i][j];
            }
        }
}


// ## -------------- Overloading Assignment Operator --------------##
JumblePuzzle& JumblePuzzle::operator = (const JumblePuzzle& jp) {
    if (this != &jp) {
        row = jp.getRowPos();
        column = jp.getColPos();
        size = jp.getSize();
        direction = jp.getDirection();

        // Deleting the old jumble
        for (int i = 0; i < size; i++)
            delete[] matrix[i];
        delete[] matrix;

        // Copying the new jumble over
        for (int x = 0; x < jp.size; x++)
            matrix[x] = new char[jp.size];

        matrix = new charArrayPtr[jp.size];

        for (int i = 0; i < jp.size; i++) {
            for (int j = 0; j < jp.size; j++) {
                matrix[i][j] = jp.matrix[i][j];
            }
        }
    }
    return *this;
}


// ## ---------- Destructor ------------ ##
JumblePuzzle::~JumblePuzzle() {
    for (int i = 0; i < size; i++)
        delete matrix [i];
    delete [] matrix;
}


