"""
@Author: Yogeshwar Shukla 

@Date: 12/05/23 

@Goal: To implement pywc command from coreutils of Linux OS. 
The command accepts text files as input on commnadline argument 
and prints the number of lines, number of words and number of 
characters in each text file and prints the total number of 
lines, words and charactes in case of more than one input file. 

@CommandLine: 
> python pywc.py abc.txt pqr.txt lmn.txt 

10  40  200     abc.txt 
27  57  381     pqr.txt 
68  237 671     lmn.txt 
146 344 1252    total 

> python pywc.py abc.txt
10  40  200     abc.txt 
"""

import sys 

def get_word_count(line:str) -> int: 
    """
    @input: 
    line: string from which words must be counted. 
    @return: the number of words in @line. 
    The function returns the number of words from @line
    """
    if type(line) != str: 
        raise TypeError("Type of @line must str")
    IN = 1 
    OUT = 2 
    state = OUT 
    w_count = 0 
    for c in line: 
        if state == OUT and not c.isspace(): 
            state = IN 
            w_count += 1 
        elif state == IN and c.isspace(): 
            state = OUT 
    return w_count 

def main(argc: int, argv: [str]) -> None: 
    """
    @input: 
        @argc: Command line argument count 
        @argv: Command line argument list 
        The function: 
        a)  does command line validation 
        b)  opens each input file, reads the file 
            in line by line fashion and in doing so 
            counts the number of lines, words and 
            characters from the same. 
        c)  In case of more than one input file 
            accumulates the result 
    """ 
    if argc < 2: 
        print("UsageError:Correct Usage:pywc.py file(s)")
        sys.exit(-1)

    nr_total_lines, nr_total_words, nr_total_chars = 0, 0, 0 
    for file_path in argv[1 : ]: 
        nr_lines, nr_words, nr_chars = 0, 0, 0 
        f_handle = open(file_path, "r")
        for line in f_handle: 
            nr_lines += 1 
            nr_words += get_word_count(line)
            nr_chars += len(line)
        print(nr_lines, nr_words, nr_chars, file_path, sep='\t')
        nr_total_lines += nr_lines 
        nr_total_words += nr_words 
        nr_total_chars += nr_chars 
        f_handle.close() 
    if argc > 2: 
        print(nr_total_lines, nr_total_words, nr_total_chars, "total", sep='\t')
    sys.exit(0)

main(len(sys.argv), sys.argv)
