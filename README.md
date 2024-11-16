Here’s a well-structured README file for your academic project:

---

# Multithreaded Number Listing in C

## Description

This program demonstrates the use of multithreading in C to list numbers from 0 to \( n \) using a minimum of 10 threads. Each thread is responsible for processing a specific range of numbers. The program divides the workload among threads to efficiently handle large values of \( n \) (minimum \( n = 1,000,000 \)).

This project serves as a practical example of parallel processing using the POSIX thread library (`pthread`).

---

## Features

- Accepts user input for the value of \( n \).
- Divides the range of numbers evenly across 10 threads.
- Uses multithreading to process ranges in parallel.
- Demonstrates efficient computation for large-scale problems.

---

## Requirements

- GCC compiler
- POSIX thread library (`pthread`)

---

## How It Works

1. The program prompts the user to enter a large number (\( n \)).
2. The range from 0 to \( n \) is divided equally among 10 threads.
3. Each thread processes its assigned range independently.
4. After all threads complete their tasks, the program displays a completion message.

---

## Program Flow

1. Input: The user specifies the value of \( n \) (e.g., 1,000,000).
2. Thread Creation:
   - Each thread is assigned a range of numbers to process.
   - Threads execute concurrently to process their ranges.
3. Synchronization:
   - The main thread waits for all worker threads to complete using `pthread_join`.
4. Output:
   - Each thread prints the range it has processed.
   - The program confirms that all threads have finished their tasks.

---

## Compilation and Execution

### Compilation
Use the GCC compiler with the `-pthread` flag to compile the program:
```bash
gcc -pthread -o multithreaded_list multithreaded_list.c
```

### Execution
Run the compiled program:
```bash
./multithreaded_list
```

### Example
#### Input:
```
Enter the value of n (minimum 1,000,000): 1000000
```
#### Output:
```
Thread 0 finished processing from 0 to 99999
Thread 1 finished processing from 100000 to 199999
...
Thread 9 finished processing from 900000 to 1000000
All threads have completed their tasks.
```

---

## Code Structure

### `main`
- Prompts the user for input.
- Divides the range among threads.
- Creates and manages threads using `pthread_create` and `pthread_join`.

### `list_numbers`
- Processes a range of numbers.
- Prints completion messages for each thread.

### `ThreadData`
- Structure used to pass data (range and thread ID) to each thread.

---

## Key Concepts

1. **Multithreading**:
   - Demonstrates parallel computation using the `pthread` library.
2. **Thread Synchronization**:
   - Ensures all threads complete using `pthread_join`.
3. **Efficient Range Division**:
   - Divides work equally to optimize computation.

---

## References

- [POSIX Threads Documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- Course material on multithreading in C.

---

## Author

- **Joshua Alana**
- African Leadership University
- Low-Level Programming
- 16th/11/2024

---

## License

This project is for educational purposes only and adheres to the institution's academic integrity guidelines. Redistribution or use outside the academic context is prohibited.

---

