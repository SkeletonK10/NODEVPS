# NODEVPS

A project to utilize my Problem Solving

### Initialization

```
git update-index --assume-unchanged a.cpp input.txt output.txt
```

### Example Usage of `ex.sh`

1. **Compile and execute the program (using C++20 standard):**

   ```
   ./ex.sh
   ```

   Output:

   ```
   (No standard output, but the result is saved in output.txt)
   ```

2. **Error when `a.cpp` is missing:**

   ```
   ./ex.sh
   ```

   Output:

   ```
   Error: Source file 'a.cpp' not found.
   ```

3. **Error when `input.txt` is missing:**

   ```
   ./ex.sh
   ```

   Output:

   ```
   Error: Input file 'input.txt' not found.
   ```
