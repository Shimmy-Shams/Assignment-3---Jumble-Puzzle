//
// Created by Shams Reza Sajid on 2022-11-07.
// Course: CMPE 320
//

#ifndef ASSIGNMENT_3___JUMBLE_PUZZLE_JUMBLE_19SRS12_H
#define ASSIGNMENT_3___JUMBLE_PUZZLE_JUMBLE_19SRS12_H

#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;
typedef char* charArrayPtr;


class BadJumbleException {

public:

    // Exception class to return a message for Jumble Exception
    BadJumbleException(const string&);
    string& what();

private:
    string message;
};


class JumblePuzzle{

public:

    // Creating a constructor
    JumblePuzzle(const string& word, const string& diff);

    // Creating a copy constructor
    JumblePuzzle(const JumblePuzzle&);

    //Destructor
    ~JumblePuzzle();

    // Overloading the Assignment Operator
    JumblePuzzle& operator = (const JumblePuzzle&);

    charArrayPtr* getJumble() const;      // Gets the matrix
    int getSize() const;            // Gets the size for the matrix
    int getRowPos() const;     // Gets the position of the rows
    int getColPos() const;     // Gets the position of the columns
    char getDirection() const;      // Fetches direction of the rest of the word from the user

private:
    int row;
    int size;
    int column;
    int direction;
    string difficulty;
    charArrayPtr* matrix;
};
#endif //ASSIGNMENT_3___JUMBLE_PUZZLE_JUMBLE_19SRS12_H
