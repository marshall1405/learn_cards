# Learn Cards

### Basic Idea

So this is a small project of mine. I kind have gotten out of touch in C++ programming and I know that writting an application in C++ is not the easiest and that there are languages that are more suitable. But I have been on this low level, object-oriented hype train, which made me interested in just creating something in C++.

The plan is to write an application that would be similar to quizlet. Basically creating card sets that would allow you to learn theory quickly. I also want to put this application on a Raspberry Pi and make it a portable learning gadget.

So the main goals are: Learn C++ and get into Electrical and Computer Engineering.

### How To Get Going

##### Needed Libraries

- wxWidgets

##### How to create sets

- All is done through a text file that is put into the main directory
- The text file has to have this format -> "Term, Answer"
- New Set starts with a line in this format -> "Name of the set"
- To understand this a little better look at the test.txt file

Run the CMakelists to create the executable file. Open the new build directory and open the learn_cards executable.