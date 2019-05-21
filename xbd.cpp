/************************************************************
 Names: Brian Rafferty -- cssc0475
        Youssef Iraqi -- cssc0428
 Project: Program Assignment 1 -- Hex Basic Dumper
 File: xbd.cpp
 Notes: This program functions as both a hexadecimal and
 a binary converter. Any file the user enters on the command 
 line will be read in, converted, and printed.
   - For binary conversion: xbd -b <filename> 
   - For hexadecimal conversion: xbd <filename> 
*************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>
using namespace std;

/************************************************************
 FUNCTION: toBinary(string)
 DESCRIPTION: Function starts by receiving the filename as 
 a string and opens the file using ifstream. All of the data 
 within the file is read in line by line, at which point 
 each character is analyzed and converted to its appropriate 
 binary value. Every character has its binary printed in octets
 and no line can contain more than six octets. Memory addresses
 and the binary's original ASCII characters are printed too.
*************************************************************/
void toBinary(string fileName){

    //sets address to the start of the 1st line within file
    string *address = &fileName;
    ifstream userFile(fileName.c_str());
    string currentLine;
    //bitset<8> is what converts strings to binary 
    bitset<8> bits;
    string binOutput = "";
    string inputCutter = "";
    int byteCounter = 0;

    while (getline(userFile, currentLine)){
        int lineSize = currentLine.length();
        try{
            // a for loop with each char turned into binary with 8 bits
            for (int i = 0; i < lineSize; ++i){
                char n = currentLine[i];
                //add each character to the inputCutter string
                inputCutter.push_back(n);
                //convert each character to its 8-bit binary value
                bits = bitset<8>(n);
                binOutput = bits.to_string();

                if (byteCounter == 0){
                    cout << address << ": ";
                }
                cout << binOutput << " ";
                byteCounter++;

                //if input reaches max size, append remaining input to next line
                if (byteCounter%6 == 0){
                    cout << inputCutter << endl;
                    inputCutter = "";
                    byteCounter = 0;
                }

                //if the end of the input line is reached before max size
                if (byteCounter%6 != 0 && i == lineSize - 1){
                    cout << inputCutter << endl;
                    inputCutter = "";
                    byteCounter = 0;
                }
                // keeping up with the address
                address = address + sizeof(currentLine);
            }  
        }
        catch(string error){
            cout << "Error: " << error << endl;
            exit(0);
        }
    }
}

/************************************************************
 FUNCTION: toHex(string)
 DESCRIPTION: Function starts by receiving the filename as 
 a string and opens the file using ifstream. All of the data 
 within the file is read in line by line, at which point 
 each character is analyzed and converted to its appropriate 
 hexadecimal value. Every hex value is stored in an output 
 string and printed, along with the memory address of each 
 line and its original ASCII characters. 
*************************************************************/
void toHex(string fileName){

    ifstream userFile(fileName.c_str());
    string currentLine;
    const char *hex = "0123456789abcdef";
    string hexOutput;
    //sets address to the start of the 1st line within file
    string *address = &fileName;

    while (getline(userFile, currentLine)){
        int lineLength = currentLine.length();
        try{
            hexOutput = "";
            for (int i = 0; i < lineLength; i++){
                //each char must be positive in order to properly manipulate bits
                unsigned char n = currentLine[i];
                if (i%2 == 0){
                    //add a space after every 2 bytes are processed
                    hexOutput.push_back(' ');
                    //shift the char's bits right by 4, then push the n'th element from hex
                    hexOutput.push_back(hex[n >> 4]);
                    //AND the char's bits with 00001111, then push the n'th element from hex
                    hexOutput.push_back(hex[n & 15]);
                }
                else {
                    hexOutput.push_back(hex[n >> 4]);
                    hexOutput.push_back(hex[n & 15]);
                } 
            }
            //prints address: hex output then original output
            cout << address << ":" << hexOutput << " " << currentLine << endl;
            //updates address to start of each subsequent line within file
            address = address + sizeof(currentLine); 
        }
        catch(string error){
            cout << "Error: " << error << endl;
            exit(0);
        }
    }
}

/************************************************************
 FUNCTION: main()
 DESCRIPTION: Driver for program. Takes in input from the
 command line and calls the corresponding functions depending 
 upon which mode is desired.
*************************************************************/
int main(int argc, char* argv[]){
    if(argc == 1){
        cout << "Error: no file selected." << endl;
        return 0;
    }
    string arg = argv[1];
    if(arg == "-b"){
        toBinary(argv[2]);
    }
    else {
        toHex(argv[1]);
    }
}

/**********************[ EOF: xbd.cpp ]**********************/