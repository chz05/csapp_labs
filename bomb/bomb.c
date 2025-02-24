/***************************************************************************
 * Dr. Evil's Insidious Bomb, Version 1.1
 * Copyright 2011, Dr. Evil Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Dr. Evil Incorporated (the PERPETRATOR) hereby grants you (the
 * VICTIM) explicit permission to use this bomb (the BOMB).  This is a
 * time limited license, which expires on the death of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM.  Unless the PERPETRATOR wants to take credit,
 * that is.  The VICTIM may not distribute this bomb source code to
 * any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BOMB.  BOMB
 * proof clothing may not be worn when handling this program.  The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will all blow up in a
 * spectaculary fiendish explosion. -- Dr. Evil 
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Note to self: remember to port this bomb to Windows and put a 
     * fantastic GUI on it. */

    /* When run with no arguments, the bomb reads its input lines 
     * from standard input. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* When run with one argument <file>, the bomb reads from <file> 
     * until EOF, and then switches to standard input. Thus, as you 
     * defuse each phase, you can add its defusing string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* You can't call the bomb with more than 1 command line argument. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");

    /* Hmm...  Six phases must be more secure than one phase! */
    input = read_line();             /* Get input                   */
    phase_1(input);                  /* Run the phase               */
    phase_defused();                 /* Drat!  They figured it out!
				      * Let me know how they did it. */
    printf("Phase 1 defused. How about the next one?\n");

    /* The second phase is harder.  No one will ever figure out
     * how to defuse this... */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Keep going!\n");

    /* I guess this is too easy so far.  Some more complex code will
     * confuse people. */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Halfway there!\n");

    /* Oh yeah?  Well, how good is your math?  Try on this saucy problem! */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try this one.\n");
    
    /* Round and 'round in memory we go, where we stop, the bomb blows! */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Good work!  On to the next...\n");

    /* This phase will never be used, since no one will get past the
     * earlier ones.  But just in case, make this one extra hard. */
    input = read_line();
    phase_6(input);
    phase_defused();

    /* Wow, they got it!  But isn't something... missing?  Perhaps
     * something they overlooked?  Mua ha ha ha ha! */
    
    return 0;
}


/*
phase_1 is super easy, so we skip it.

Then it is the pesudo_code for phase_2

from main

rax = rdi -> first argument
rsp - 40
rsp = rsi   now location is rsi -> second argument


after run read_six_numbers
if 1 = rsp then good else bomb
goto 52
rbx = rsp + 4 => probably the next element in rsp
rbp = rsp + 24 => probably the sixth element
go back to 27
eax = (rbx - 4) = (rsp) = 1
eax = 2 now
if 2 = (rbx) which is rsp + 4 then good            so we need to make sure rsp = 1, rsp + 4 = 2
goto 41
rbx + 4 which is rsp + 8
compare rbp and rbx => if rbx = rsp + 24 the program will end rsp, rsp + 4, 8, 12, 16, 20
but now go back to 27
eax = (rbx - 4) = 2
eax = 4
compare (rsp + 8) with 4

rbx = rsp + 4
rbp = rsp + 24
goto 27
rbx -4 = eax
eax = eax * 2
eax = rbx then good
goto 41
rbx + 4
rbp != rbx
goto 27 do the loop

call read_six_numbers:
rsp - 24 it will read the arguments from stack?
rsi = rdx
rcx = rsi + 4
rax = rsi + 20
rax = rsp + 8
rax = rsi + 16
rax = rsp
rsi = 


0x0 = eax

if we compare 0x5 and eax, if 0x5 > eax then good
rsp + 24 -> means it pop all rsp
then return


*/

/*
phase_3
readline value send to rax I think
rsp - 24, create space
rcx = rsp + 12 value forth arg
rdx = rsp + 8  value third arg
esi = 0x4025cf probably address, I think it is a format
eax = 0
call sscanf, get data

compare 1 and eax check the sscanf read one number
compare 7 and rsp + 8, value

7 < rsp + 8: 
eax = rsp + 8 value
jump to 0x402470 + 8 * %rax   first arg, this line is very important, we need to see where rax goto
eax = 12 * 16 + 15
jump to 123
compare eax  (rsp + 12)
if equal, success

else:


we need to input two arguments
first argument should < 7

*/
