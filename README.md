# push_swap

This project is part of the 42 curriculum and focuses on sorting a list of integers using two stacks and a limited set of operations. The objective is to sort the data with the fewest possible moves.

## Table of Contents

- [Introduction](#introduction)
- [Instruction Set](#instruction-set)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Resources](#resources)

## Introduction

The `push_swap` program is designed to sort a list of integers using two stacks, named `a` and `b`. The program must generate a sequence of operations to sort the stack `a` in ascending order, utilizing stack `b` for temporary storage. The challenge lies in performing the sort with the minimum number of operations.

## Instruction Set

The program uses the following operations to manipulate the stacks:

- `sa`: Swap the first two elements at the top of stack `a`.
- `sb`: Swap the first two elements at the top of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element of stack `b` onto stack `a`.
- `pb`: Push the top element of stack `a` onto stack `b`.
- `ra`: Rotate stack `a` upwards (the first element becomes the last).
- `rb`: Rotate stack `b` upwards.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack `a` (the last element becomes the first).
- `rrb`: Reverse rotate stack `b`.
- `rrr`: Perform `rra` and `rrb` simultaneously.

If an operation cannot be performed, it will be ignored.

## Usage

1. **Compilation**: Compile the program using the provided `Makefile`:

   ```bash
   make
   ```

2. **Execution**: Run the program with a list of integers as arguments:

   ```bash
   ./push_swap 3 2 5 1 4
   ```

   The program will output a sequence of operations to sort the input numbers.

3. **Validation**: To verify the correctness of the generated operations, you can use the `checker` program:

   ```bash
   ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
   ```

   The `checker` will output `OK` if the operations sort the stack correctly, otherwise it will output `KO`.

## Algorithm

For small sets of numbers (typically 5 or fewer), a simple sorting algorithm is implemented. For larger sets, the program uses the Radix sort algorithm, which is efficient for sorting non-negative integers with a time complexity of O(n). The implementation details can be found in the `src` directory.

## Resources

For a detailed walkthrough of the `push_swap` project, you can refer to the following tutorial:

[push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk)
