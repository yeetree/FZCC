# `bf`: BrainF*\*k Interpreter:

&emsp;The BrainF*\*k Interpreter is a pretty simple and straight-forward interpreter. You just run `./bf yourfile.bf`and it runs it. That's pretty much it! Of course, you don't have to use ".bf" for the file extension, but this documentation uses it to distinguish between the different file types
# BrainF**k:
&emsp;BrainF*\*k is an Esoteric Programming Language that only has 8 instructions. It can read and write to a tape, (or an array of 8 bit numbers.)

## Instructions:
* `>` - Move the memory pointer to the right
* `<` - Move the memory pointer to the left
* `+` - Add one to the current value at the memory pointer
* `-` - Subtract one to the current value at the memory pointer
* `[` - Jump past matching `]` if current memory value is 0
* `]` - Jump back to matching `[`
* `.` - Output current memory value as an ASCII character
* `,` - Input ASCII character from keyboard and store it into current memory value