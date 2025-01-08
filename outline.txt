create a header that contains a hash table type and methods to go with it

all hash tables should contian: 
    a pointer to the function used to hash things
    a pointer to the start of an array

to access things with in the hash table you should:
    call the hash table's hashing function, then go the return 
    value of that function (an integer representing an index) in
    the array of the hash table

A hash function might be:
    takes an input of some character, then returns an integer
    that represents the index it should be stored at in an array
    it may do this by (ideas):
        - looking at the ascii value of the character and subtracting some value
        - a bunch of if else statements


A typical array might look like:
    index: value
    0 (a): 
    1 (b):
    3 (c): #
    ...
    25 (A):
    26 (B):
    27 (C):
    ...
    52 (~): 
    53 (!):
    54 (#): 
    55 ($):
    56 (%):
    57 (^):
    58 (*):
    59 (<open brace>):
    60 (<close brace>):
    61 (-):
    62 (+):
    63 (<open square brace>):
    64 (<close square brace>):
    65 (<open curly brace>): 
    66 (<close curly brace>):
    67 (\):
    68 (|):
    69 (<):
    70 (>):
    71 (/):
    72 (?):
    73 (\n):
    74 ( ):
    75 (1):
    76 (2):
    77 (3):
    ...

    - the hash function should take the things in parenthesis
    as arguments and should return the index number
