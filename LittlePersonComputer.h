#ifndef LITTLEPERSONCOMPUTER_H
#define LITTLEPERSONCOMPUTER_H

/**
 * @brief Little Computer class represents main memory and values representing the program counter and accumulator
 */

#include <iostream>
#include <iomanip>
using namespace std;

class LittlePersonComputer {
public:

    //DECLARATIONS STARTING WITH CONSTRUCTORS
    /**
     * @brief Initializes accumulator (ACC), program counter (PC) and all memory slots to 0.
     */
    LittlePersonComputer();

    /**
     * @brief Initializes accumulator (ACC), program counter (PC) and all memory slots to 0.
     * @param array of instructions and size of array
     */
    LittlePersonComputer(int instructions[], int numberOfInstructions);

    //FUNCTIONS
    /**
     * @brief integer function to return the current program counter number
     * @return int value in programCounter
     */
    int getProgramCounter();
    /**
     * @brief provides the value inside the current accumulator
     * @return int value in accumulator
     */
    int getAccumulator();
    /**
     * @brief Return the value in memory at the indicated location.
     * @param memory location integer
     * @return memory location
     */
    int getMemoryAt(int location);
    /**
     * @brief Return the value in memory at the location indicated by the program counter.
     * @return memory[programCounter]
     */
    int getCurrentInstruction();
    /**
     * @brief Loads the instructions into main memory
     * @param array of instructions and size of array
     */
    void loadProgram(int instructions[], int numberOfInstructions);
    /**
     * @brief output information to screen
     */
    void printState();
    /**
     * @brief stops program is instructions == 0
     * @return true or false
     */
    bool isHalted();
    /**
     * @brief runs the computer instructions, auto advance PC
     */
    void step();


private:
    //STATE - variables - data members
    int memory[20];
    int accumulator;
    int programCounter;

};
#endif // LITTLEPERSONCOMPUTER_H
