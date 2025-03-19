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

---

### Example Usage of `touch.sh`

1. **Create a new file with default extension (`cpp`):**

   ```
   ./touch.sh -d BOJ -n 12345
   ```

   Output:

   ```
   File created at: ./BOJ/10000~19999/12000~12999/12345.cpp
   ```

2. **Create a new file with a custom extension:**

   ```
   ./touch.sh -d BOJ -n 12345 -e txt
   ```

   Output:

   ```
   File created at: ./BOJ/10000~19999/12000~12999/12345.txt
   ```

3. **Error when the file already exists:**

   ```
   ./touch.sh -d BOJ -n 12345
   ```

   Output:

   ```
   Error: File './BOJ/10000~19999/12000~12999/12345.cpp' already exists.
   ```

4. **Error when the domain folder does not exist:**
   ```
   ./touch.sh -d NON_EXISTENT -n 12345
   ```
   Output:
   ```
   Error: Domain folder 'NON_EXISTENT' does not exist.
   ```
