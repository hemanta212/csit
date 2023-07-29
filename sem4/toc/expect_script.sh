# expect script for C program output
# usage : expect expect_script.sh

# ------------- dfa_abb 1----------------

# spawn ./dfa_abb
# expect "Enter input string: "
# send "abba\r"
# expect "Accepted"

# spawn ./dfa_abb
# expect "Enter input string: "
# send "abbb\r"
# expect "Accepted"

# spawn ./dfa_abb
# expect "Enter input string: "
# send "abab\r"
# expect "Rejected"

# spawn ./dfa_abb
# expect "Enter input string: "
# send "abbaab\r"
# expect "Accepted"

# spawn ./dfa_abb
# expect "Enter input string: "
# send "ababaa\r"
# expect "Rejected"


# ------------- dfa_start_ab_end_b----------------
# should accept strings starting with ab and ending with b
# spawn ./dfa_start_ab_end_b
# expect "Enter input string: "
# send "abbb\r"
# expect "Accepted"

# spawn ./dfa_start_ab_end_b
# expect "Enter input string: "
# send "abba\r"
# expect "Rejected"

# spawn ./dfa_start_ab_end_b
# expect "Enter input string: "
# send "abb\r"
# expect "Accepted"

# spawn ./dfa_start_ab_end_b
# expect "Enter input string: "
# send "babb\r"
# expect "Rejected"

# spawn ./dfa_start_ab_end_b
# expect "Enter input string: "
# send "ab\r"
# expect "Rejected"

#------------- dfa_even_strings ----------------
# should accept even length strings

# spawn ./dfa_even_strings
# expect "Enter input string: "
# send "abba\r"
# expect "Accepted"

# spawn ./dfa_even_strings
# expect "Enter input string: "
# send "abc\r"
# expect "Rejected"

# spawn ./dfa_even_strings
# expect "Enter input string: "
# send "abcd\r"
# expect "Accepted"

# spawn ./dfa_even_strings
# expect "Enter input string: "
# send "abcdefg\r"
# expect "Rejected"

#---------------------- lab4 ------------------
# dfa to accept for and while keywords
# spawn ./lab4
# expect "Enter input string: "
# send "for\r"
# expect "Accepted"

# spawn ./lab4
# expect "Enter input string: "
# send "while\r"
# expect "Accepted"

# spawn ./lab4
# expect "Enter input string: "
# send "fore\r"
# expect "Rejected"

# spawn ./lab4
# expect "Enter input string: "
# send "whilee\r"
# expect "Rejected"

# spawn ./lab4
# expect "Enter input string: "
# send "forwhile\r"
# expect "Rejected"

# --------------------- lab5 -------------------
# DFA THAT ACCPETS ALL THE VALID IDENTIFIERS IN C LANGUAGE*/
# spawn ./lab5
# expect "Enter input string: "
# send "a\r"
# expect "Accepted"

# spawn ./lab5
# expect "Enter input string: "
# send "1a\r"
# expect "Rejected"

# spawn ./lab5
# expect "Enter input string: "
# send "for\r"
# expect "for is a keyword, Rejected"

# spawn ./lab5
# expect "Enter input string: "
# send "myfunc\r"
# expect "Accepted"

# --------------------- lab6 -------------------
#PDA THAT ACCEPTS THE STRING A^nB^n
# spawn ./lab6
# expect "Enter input string: "
# send "aabb\r"
# expect "Accepted"

# spawn ./lab6
# expect "Enter input string: "
# send "aabbb\r"
# expect "Rejected"

# spawn ./lab6
# expect "Enter input string: "
# send "aaabbb\r"
# expect "Accepted"

# --------------------- lab7 -------------------
#PDA THAT ACCEPTS THE STRING A^nB^2n
# spawn ./lab7
# expect "Enter input string: "
# send "aabbbb\r"
# expect "Accepted"

# spawn ./lab7
# expect "Enter input string: "
# send "aabbb\r"
# expect "Rejected"

# spawn ./lab7
# expect "Enter input string: "
# send "aaabbbbbb\r"
# expect "Accepted"

# spawn ./lab7
# expect "Enter input string: "
# send "aaaabb\r"
# expect "Rejected"

# --------------------- lab8 -------------------
#/*IMPLEMENTATION OF PDA FOR A^N c B^N*/
# spawn ./lab8
# expect "Enter input string: "
# send "aacbb\r"
# expect "Accepted"

# spawn ./lab8
# expect "Enter input string: "
# send "aabb\r"
# expect "Rejected"

# spawn ./lab8
# expect "Enter input string: "
# send "aaacbbb\r"
# expect "Accepted"

# spawn ./lab8
# expect "Enter input string: "
# send "aaacbb\r"
# expect "Rejected"

# --------------------- lab9 -------------------
#/*IMPLEMENTATION OF PDA THAT ACCEPTS ODD PALINDROME*/
# spawn ./lab9
# expect "Enter input string: "
# send "aabcbaa\r"
# expect "Accepted"

# spawn ./lab9
# expect "Enter input string: "
# send "abacba\r"
# expect "Rejected"

# --------------------- lab10 -------------------
#/*TURING MACHINE FOR palindrome*/
# spawn ./lab10
# expect "Enter input string: "
# send "ababa\r"
# expect "Accepted"

# spawn ./lab10
# expect "Enter input string: "
# send "aabba\r"
# expect "Rejected"

# spawn ./lab10
# expect "Enter input string: "
# send "abba\r"
# expect "Accepted"

#---------------------- lab11 ------------------
#/* Turing Machine for equal number of a's and b's*/
# spawn ./lab11
# expect "Enter input string: "
# send "abab\r"
# expect "Accepted"

# spawn ./lab11
# expect "Enter input string: "
# send "abbaa\r"
# expect "Rejected"

# --------------------- lab12 -------------------
#/*TURING MACHINE FOR A^N B^N*/
# spawn ./lab12
# expect "Enter input string: "
# send "aaabbb\r"
# expect "Accepted"

# spawn ./lab12
# expect "Enter input string: "
# send "aabbb\r"
# expect "Rejected"

#---------------------- lab13 ------------------
#/*TURING MACHINE FOR A^N B^N+1*/
# spawn ./lab13
# expect "Enter input string: "
# send "aabbb\r"
# expect "Accepted"

# spawn ./lab13
# expect "Enter input string: "
# send "aaabbb\r"
# expect "Rejected"

#---------------------- lab14 ------------------
#/*Turing machine for string a^n b^2n*/
# spawn ./lab14
# expect "Enter input string: "
# send "aabbbb\r"
# expect "Accepted"

# spawn ./lab14
# expect "Enter input string: "
# send "aabbb\r"
# expect "Rejected"

#---------------------- lab15 ------------------
#/*Turing machine for string a^2n b^n*/
# spawn ./lab15
# expect "Enter input string: "
# send "aaaabb\r"
# expect "Accepted"

# spawn ./lab15
# expect "Enter input string: "
# send "aaabb\r"
# expect "Rejected"

#---------------------- lab16 ------------------
#/*IMPLEMENTATION OF STORAGE IN STATE TURING MACHINE THAT ACCEPTS STRING ab* + ba*  */
spawn ./lab16
expect "Enter input string: "
send "abbbbbb\r"
expect "Accepted"

spawn ./lab16
expect "Enter input string: "
send "abab\r"
expect "Rejected"

spawn ./lab16
expect "Enter input string: "
send "baaaaaa\r"
expect "Accepted"

spawn ./lab16
expect "Enter input string: "
send "baaba\r"
expect "Rejected"