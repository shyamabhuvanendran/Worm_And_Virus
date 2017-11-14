# Worm_And_Virus
This repository has some simple self replicating programs.

worm_1.c
========

This program modifies its executable. The resulting executable has the source code. You can check worm_1 to see the executable with source code.

Execution Steps
---------------

1. worm_1.c has the source code.
2. Compile the source code using the below command in linux environment:
	gcc worm_1.c -o worm_1
3. Check the compiled file worm_1. It doesn't have the source code.
4. Run the compiled file using the below command:
	./worm_1
5. The program checks if the executable has the source and adds it accordingly. The program prints the below text: 
	"Executable file doesn't contain source code. Creating executable with source code."
6. Check the modified worm_1. The executable has now the entire source code in it.
7. Run the worm_1 executable file again using the command in step 4. Since the executable already has the source code in it, the program prints the below text on console:
	"Executable file contains source code!!!"
  
  
worm.c
======

This program modifies its executable to insert its own source code. Compiling worm.c creates worm executable which doesn't have the source code. Executing worm executable once inserts the source code in the executable. Copy this modified executable to any folder and run it. The executable creates its own source code from just the executable and executes it.

Execution Steps
---------------

1. worm.c has the source code.
2. Compile the source code using the below command in linux environment:
	gcc worm.c -o worm
3. Check the compiled file worm. It doesn't have the source code.
4. Run the compiled file using the below command:
	./worm
5. The program checks if the executable has the source and adds it accordingly. The program prints the below text: 
	"Executable file doesn't contain source code. Creating executable with source code."
6. Check the modified worm. The executable has now the entire source code in it.
7. Run the worm executable file again using the command in step 4. Since the executable already has the source code in it, the program prints the below text on console:
	"Executable file contains source code!!!"
 8. The program also copies its own source code from its executable to worm_source.c, compiles the source code to create worm1 executable and executes it.
  
  
