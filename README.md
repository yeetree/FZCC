# BrainFuzz Compiler Collection (FZCC)
This file contains information about FZCC, how to use it's programs, and how to build it. It does not contain the BrainFuzz documentation. You can find the BrainFuzz documentation in the "docs" directory.
## What is FZCC
The BrainFuzz Compiler Collection is a group of software that I wrote for my programming language BrainFuzz that compiles to BrainF*\*k. 

FZCC contains three programs. `bf`,`bfz`, and `bfd`.

####  `bf`: BrainF*\*k Interpreter:
&emsp;The BrainF*\*k Interpreter is a pretty simple and straight-forward interpreter. You just run `./bf yourfile.bf`and it runs it. That's pretty much it! Of course, you don't have to use ".bf" for the file extension, but this documentation uses it to distinguish between the different file types

####  `bfz`: BrainFuzz Compiler:
&emsp;The BrainFuzz compiler is also pretty simple. You just give it an input file and an output file, like `./bfz input.bfz output.bf`. It compiles BrainFuzz code, (which is designed to be a more readable version of BrainF*\*k,) and compiles it into BrainF*\*k code that can be ran with `bf`. To learn BrainFuzz, go to the "docs" directory.

#### `bfd`: BrainF*\*k Decompiler:
&emsp;The BrainF*\*k Decompiler is a lot like the BrainFuzz Compiler, but in reverse. You just give it an input file and an output file, like `./bfd input.bf output.bfz`. Then, it decompiles your BrainF*\*k code into BrainFuzz code, and even recognizes the extra BrainFuzz instructions. It cannot restore comments, or convert numbers back into characters.
## How to build FZCC
In order to build FZCC, you will need:
* GCC with G++ (or any other compatible C++ compiler)
* Make

Simply go to the root directory of FZCC and run `make`.
All of the FZCC binaries will appear in the "bin" directory.