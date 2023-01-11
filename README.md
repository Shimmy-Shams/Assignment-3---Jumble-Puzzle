# Jumble-Puzzle
This assignment you will need to create an ISO C++ class and its exception class (header and implementation files) to support a puzzle game. No GUI coding is required. To play the game, the user supplies a word between 3 and 10 characters in length, all lower case, and chooses a difficulty level from "easy", "medium" or "hard". These levels control the size of the puzzle, which will be a square array of 2, 3 or 4 times the size of the supplied word. Here is an example of a medium difficulty puzzle which contains the hidden word "hidden" along with row and column numbers:

```swift
   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 
 0 e  t  h  m  l  s  y  z  p  i  y  i  t  w  e  n  t  o  
 1 m  l  p  t  p  e  e  a  l  i  i  z  z  i  q  s  c  d  
 2 i  p  t  e  v  u  h  u  e  d  x  m  a  y  c  e  d  e  
 3 u  w  e  k  g  f  i  k  r  e  g  t  s  t  s  h  v  p  
 4 d  g  z  m  i  y  x  y  h  e  h  x  p  v  a  o  i  y  
 5 b  f  q  n  c  e  v  u  s  f  i  y  g  t  w  m  s  t  
 6 y  e  z  z  u  s  r  b  u  d  d  p  e  u  g  z  t  q  
 7 w  u  b  j  h  d  g  u  h  h  d  o  r  w  i  n  g  n  
 8 x  v  f  c  u  w  g  f  k  g  e  l  v  j  c  t  r  p  
 9 m  d  x  c  l  z  c  m  t  v  n  j  r  h  u  n  a  s  
10 y  g  r  e  f  p  n  h  j  g  w  m  y  n  w  w  m  b  
11 t  x  z  b  p  q  x  e  e  o  t  w  f  d  k  x  n  t  
12 v  t  a  o  z  b  f  b  u  d  z  x  l  v  e  p  n  o  
13 m  q  y  n  k  d  o  j  p  u  t  o  r  b  j  u  j  f  
14 d  d  c  z  m  j  m  g  a  i  o  z  l  j  v  w  y  e  
15 r  o  m  j  d  e  r  k  b  s  u  l  v  q  l  v  a  g  
16 q  r  p  g  p  i  n  j  w  e  k  r  x  l  w  s  v  o  
17 s  b  d  s  a  v  j  s  v  w  h  b  q  n  b  m  o  w 
```


(In case you can't find the hidden word, it starts at row 4, column 10 and heads down or "south".)

As you can see, the hidden word is placed at random in a 2D array of random, lower case letters. The word can be spelled out going up, down, left or right (or north, south, west or east), but not in a diagonal direction (for simplicity). The game is played against the clock with the user wanting to decrease the time required to solve the puzzle.

The game itself is one of the functions supplied in this code (testJumble.cpp). This program also contains a function to display the puzzle and a function containing a few unit tests that your class, called JumblePuzzle, needs to satisfy. You also need to write the BadJumbleException class, and add to the set of unit tests supplied. Examine the supplied code and its comments to help figure out how your class must behave and the types of unit tests you need to develop. You do not need to use a unit testing framework, just code the tests into the testJumble() function.

in your header file. Now the type of the 2D array of char will be charArrayPtr*. The supplied code uses this typedef, but you may replace it with char** of you wish.

Since you are using the heap for the puzzle, your JumblePuzzle class must have a destructor, a copy constructor and overload the assignment operator - the so-called "Big Three". You must make sure to prevent aliasing, as tested for in the few supplied unit tests. You will probably find out that improper memory management often causes your program to crash without any useful error messages! Of course you will have to figure out how to delete a 2D array, considering you have "delete[]", but not "delete[][]".

Examine the supplied code to see what other public member functions you need and how the normal constructor should work. You may write as many private member functions as you wish to make for a well structured class. Use the const modifier wherever possible to help ensure the proper operation of your code.

Hint: When hiding the word in the array, you might wish to consider the following algorithm:

- Generate a random row and column position between 0 and size-1, where size is the size of the array.
- Choose a random direction from the string "nesw" or something like this.
- Lay down the first letter of the word in the starting position.
- Lay down the remaining letters in the direction obtained.
- If the word will not fit in the given direction, continue the process by going back to the second step and trying again. You have at least a 50% chance of getting a direction in which the word will fit, so you should not need to go back too many times. Just leave the letters from the partial word in the puzzle - just to make it more fun!
