Rizzsec is a program that can be used for a simple substitution Cipher.

To use the program, you should first specify what mode you want to run the program in.
If you would like to encrypt a text file, you should type ./rizzsec encrypt,
and if you want to decrypt a file you should type decrypt instead.
 
The next thing that you need is -d <path_to_input_file>, which is the file that you would
like to perform an operation on (either encrypt or decrypt). 
 
You will also need to specify a key to use, which you should do with -i <path_to_key>.

If you would like to control the name of the output file, you should type -o <name of file>.

Example use:
    ./rizzsec encrypt -d message.txt -i message.key -o message.enc
To decrypt:
    ./rizzsec decrypt -d message.enc -i message.key -o message.denc

Of course, in order to use the program at all, you first need a key
To generate a key, simply run the script rizzsec-keygen

rizzsec-keygen takes one argument (-o). In -o you should provide the
name for the key. If you don't specify it, it will be rizz.key

Example keygen:
    ./rizzsec-keygen -o message.key
This will create a file called message.key 

