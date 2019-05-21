Brian Rafferty -- cssc0475
Youssef Iraqi -- cssc0428
---------------------
CS 530, Spring 2019
---------------------
Program Assignment #1
---------------------
README.md
---------------------
Manifest:
    README.md
    xbd.cpp
    Makefile
----------------------
Compiling xbd.cpp:
    make
    
    g++ xbd.cpp -o xbd 
----------------------
Convert file to hex:
    xbd <filename>

Convert file to binary:
    xbd -b <filename>
----------------------
List/description of novel/significant design decisions:
We decided to make the program modular, and split the
handling of data between two different functions.
We implemented bit manipulation in both of our algorithms
to calculate the conversions.
----------------------
List/description of any extra features/algorithms/functionality 
you included which were not required:
We added error handlers if the files failed to open, and
also inserted an error message if the user fails to enter
a file on the command line.
----------------------
List/description of all known deficiencies or bugs:
Nothing to report in terms of bugs.
----------------------
Lessons Learned:
We learned how to efficiently manipulate bits in a couple
of ways and how to handle the compilation of the output 
regardless of the input size. 
