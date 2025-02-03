# Rizzsec

Rizzsec is a program that implements a simple substitution cipher. It allows you to encrypt or decrypt files using a specified key.

## Usage

### Specifying the Mode
To use the program, first specify the mode you want to run the program in:

- To **encrypt** a text file, run:
  ```bash
  ./rizzsec encrypt
  ```
- To **decrypt** a file, run:
  ```bash
  ./rizzsec decrypt
  ```

### Required Arguments

1. **Input File**  
   You need to provide the file you want to encrypt or decrypt using `-d <path_to_input_file>`.  
   Example:
   ```bash
   -d message.txt
   ```

2. **Key File**  
   Specify the key file with `-i <path_to_key>`.  
   Example:
   ```bash
   -i message.key
   ```

3. **Output File**  
   If you want to control the name of the output file, use `-o <name_of_file>`.  
   Example:
   ```bash
   -o message.enc
   ```

### Example Usage

- To **encrypt** a file:
  ```bash
  ./rizzsec encrypt -d message.txt -i message.key -o message.enc
  ```

- To **decrypt** a file:
  ```bash
  ./rizzsec decrypt -d message.enc -i message.key -o message.denc
  ```

## Generating a Key

To use the program, you need a key. To generate a key, run the `rizzsec-keygen` script.

### Key Generation

- The `rizzsec-keygen` script takes one argument: `-o`, where you specify the name for the key file. If you don't provide a name, it will default to `rizz.key`.

Example key generation:
```bash
./rizzsec-keygen -o message.key
```

This will create a file called `message.key`.

---

Now you have everything you need to encrypt and decrypt files with Rizzsec!


