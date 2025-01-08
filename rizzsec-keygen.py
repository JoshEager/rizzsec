import random
import sys

# Parse arguments so we know where to save the key
write_path = ""
for i in range(0, len(sys.argv)):
    if sys.argv[i] == "-o":
        write_path = sys.argv[i + 1]

# Default write Path
if not write_path:
    write_path = "rizz.key"

# Generate an array that contains all the ascii values from 32 to 126
ascii_array = [chr(i) for i in range(32, 127)]

# Shuffle the array
random.shuffle(ascii_array)

# Join the array into a sinlge string
key = "".join(ascii_array)

# Write the file
with open(write_path, 'w') as f:
    f.write(key)
