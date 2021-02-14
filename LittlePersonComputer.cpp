/**
* @brief Assignment 1
* @name Randy Randall
*/

#include <iostream>
#include "LittlePersonComputer.h"
#include <iomanip>

using namespace std;

//IMPLEMENTATION

//CONSTRUCTOR - NO ARGUMENTS FOR DEFAULT
LittlePersonComputer::LittlePersonComputer(){
    for(int i = 0; i < 20; i++){
       memory[i] = 0;
    }
    accumulator = 0;
    programCounter = 0;
}

//CONSTRUCTOR
LittlePersonComputer::LittlePersonComputer(int instructions[], int numberOfInstructions){
    for(int i = 0; i < 20; i++){
       memory[i] = 0;
    }
    for(int i = 0; i < numberOfInstructions; i++){
       memory[i] = instructions[i];
    }
    accumulator = 0;
    programCounter = 0;
}

//BEHAVIORS - functions
void LittlePersonComputer::printState(){
    cout << "Accumulator: " << accumulator << " " << setw(20)
         << "Program Counter : " << programCounter << endl
         << "Memory: \n";
    for(int i = 0; i < 20; i++){
        cout << setw(3) << i << "  ";
    }
    cout << endl;
    for(int i = 0; i < 20; i++){
        cout << setw(3) << memory[i] << "  ";
    }
    cout << endl << endl;
}
void LittlePersonComputer::loadProgram(int instructions[], int numberOfInstructions){
    for(int i = 0; i < numberOfInstructions; i++){
       memory[i] = instructions[i];
    }
}
int LittlePersonComputer::getMemoryAt(int location){
    return memory[location];
}
void LittlePersonComputer::step(){
    int opCode = 0;
    int index = memory[programCounter]%100;
    opCode = (memory[programCounter]/100);

    switch (opCode){
    case (0):
        accumulator = memory[index] + accumulator;
        break;
    case (1):
        accumulator = memory[index] + accumulator;
        break;
    case (2):
        accumulator = accumulator - memory[index];
        break;
    case (3):
        memory[index] = accumulator;
        break;
    case (5):
        accumulator = memory[index];
        break;
    case (6):
        programCounter = index - 1;
        break;
    case (7):
        if(accumulator == 0)
            programCounter = index -1;
        break;
    case (8):
        if(accumulator >= 0)
            programCounter = index -1;
        break;
    case (9):
        if(memory[programCounter]%10 == 2)
            cout << accumulator << endl;
        else
            cin >> accumulator;
        break;

    }
    programCounter++;
}

int LittlePersonComputer::getProgramCounter(){
    return programCounter;
}
int LittlePersonComputer::getAccumulator(){
    return accumulator;
}
int LittlePersonComputer::getCurrentInstruction(){
    return memory[programCounter];

}
bool LittlePersonComputer::isHalted(){
    if(memory[programCounter]== 0)
        return true;
    else
        return false;

}
