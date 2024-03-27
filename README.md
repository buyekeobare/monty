# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
pall $
push 4$
push 5 $
      push    6        $
pall$
julien@ubuntu:~/monty$
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$

## The monty program

Usage: monty file

- where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  where is the line number where the instruction appears.
  Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  it executed properly every line of the file
  it finds an error in the file
  an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Tasks

- Implement the push and pall opcodes.The opcode push pushes an element to the stack.The opcode pall prints all the values on the stack, starting from the top of the stack.
- Implement the pint opcode.The opcode pint prints the value at the top of the stack, followed by a new line.
- Implement the pop opcode.The opcode pop removes the top element of the stack.
- Implement the swap opcode.The opcode swap swaps the top two elements of the stack.
- Implement the add opcode.The opcode add adds the top two elements of the stack.
- Implement the nop opcode.The opcode nop doesn’t do anything.
- Implement the sub opcode.The opcode sub subtracts the top element of the stack from the second top element of the stack.
- Implement the div opcode.The opcode div divides the second top element of the stack by the top element of the stack.
- Implement the mul opcode.The opcode mul multiplies the second top element of the stack with the top element of the stack.
- Implement the mod opcode.The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.
- Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).
- Implement the pchar opcode.The opcode pchar prints the char at the top of the stack, followed by a new line.
- Implement the pstr opcode.The opcode pstr prints the string starting at the top of the stack, followed by a new line.
- Implement the rotl opcode.The opcode rotl rotates the stack to the top.
- Implement the rotr opcode.The opcode rotr rotates the stack to the bottom.
- Implement the stack and queue opcodes.The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.The opcode queue sets the format of the data to a queue (FIFO).
- Write a Brainf\*ck script that prints School, followed by a new line.
- Add two digits given by the user.Read the two digits from stdin, add them, and print the result.The total of the two digits with be one digit-long (<10).
- Multiply two digits given by the user.Read the two digits from stdin, multiply them, and print the result.
- Multiply two digits given by the user.Read the two digits from stdin, multiply them, and print the result, followed by a new line.
