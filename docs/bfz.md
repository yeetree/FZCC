
# `bfz`: BrainFuzz Compiler:

&emsp;The BrainFuzz compiler is also pretty simple. You just give it an input file and an output file, like `./bfz input.bfz output.bf`. It compiles BrainFuzz code, (which is designed to be a more readable version of BrainF*\*k,) and compiles it into BrainF*\*k code that can be ran with `bf`. To learn BrainFuzz, look below!

# BrainFuzz Programming Language:
&emsp;BrainFuzz was designed to be a readable version of BrainF*\*k, but it has some extra features that can help even more. BrainFuzz compiles directly to BrainF*\*k, so it can run anywhere that a BrainF*\*k interpreter can. 

The basic syntax of BrainFuzz is as follows:
`instruction, argument, argument;`

The comma separates arguments and the semicolon separates lines, so you can have multiple instructions on a single line.

You can also use a character instead of a number. For example:
```
set,a; out;
set,b; out;
set,c; out;
```

Will print:
`abc`.

Here are all of the instructions:
* `left, [num];` or `l, [num];`: Moves pointer to the left by [num]. Moves to the left by 1 if not specified.
* `right, [num];` or `r, [num];`: Moves pointer to the right by [num]. Moves to the right by 1 if not specified.
* `add, [num];` or `a, [num];`: Adds [num] to current memory value. Adds 1 if not specified.
* `sub, [num];` or `s, [num];`: Subtracts [num] from current memory value. Subtracts 1 if not specified.
* `input;` or `in;`: Inputs character from keyboard and stores it into current memory value.
* `output;` or `out;`: Outputs current memory value as ASCII character.
* `set, [num];`: Sets current memory value to [num]. Sets current memory value to 0 if not specified.
* `loop;`: Jumps past matching `end;` if current memory value is 0.
* `end;`: Jumps back to matching `loop;`.
