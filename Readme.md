/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme.md                                      	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:04:52 by root              #+#    #+#             */
/*   Updated: 2025/05/12 13:14:05 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Empezamos con el main.
Declaramos los stacks con t_stack (a y b)
Luego el array de numeros (int *nums)
Despues, int count que ya lo usaremos mas tarde.


________Primera Etapa(Parsing)_________
	if (argc < 2)
		return (0);
Checkeamos que los argumentos no sean menos de 2 que habrian de ser el nombre del 
programa y luego la cadena de numeros.

	if (!parse_args(argc, argv, &nums, &count))
		return (1);

Llamamos a la funcion parse_args que se encarga de parsear los argumentos.
Como lo hace?
Primero une los argumentos en una sola cadena de caracteres. Si no ha encontrado 
nada que unir, entonces que proceda. Los separa por espacios y se convierte en un 
array de enteros. En *count se guarda la cantidad de numeros que hay en el array,
gracias a count_args. Despues reservamos memoria para el array de num_array. 
Si el array de numeros es NULL, entonces no se puede continuar y el la primera 
memoria (split) sera liberada. Luego se hace un atol masivo a los numeros.
Tras finalizar, se libera la memoria de split y se hace un chequeo para evitar
que haya numeros duplicados. 
Luego un checkeo de ft_strlen que no me cabia en parse_args.

Luego init_variables que inicializa los stacks con sus head a NULL y su size a 0.

Despues inicializamos el stack a y b con los numeros que hemos parseado entrando 
en stack_a a traves de allocate and copy. allocate and copy se encarga de alocar
la memoria suficiente para los datos sorted y los indices dentro de 
la estructura de data hecha unicamente para la inicializacion de los stacks.
Data es resultado de allocate_and_copy y es un puntero a la estructura de datos.
Luego usamos sort_and_index con el array de numeros, un puntero a 
la estructura data con count como argumento.

Mine :D
----------------------------------------------------------------------
AI Made

Program Flow

### 1. Main Function
The program starts in the `main` function:
- **Variables**: Declares two stacks (`a` and `b`) of type `t_stack`, an array of integers (`nums`), and a counter (`count`) to store the number of input numbers.
- **Argument Check**: Ensures there are at least two arguments (program name and numbers). If `argc < 2`, the program exits silently.
- **Parsing**: Calls `parse_args` to process the input arguments.
- **Initialization**: Initializes stacks `a` and `b` with `init_variables` and populates `stack_a` with `init_stacks`.
- **Sorting**: Checks if `stack_a` is already sorted with `check_sorted`. If not, calls `sort` to perform the sorting.
- **Cleanup**: Frees allocated memory (`nums`, `stack_a`, `stack_b`) and exits.

### 2. Parsing Stage (`parse_args`)
The parsing stage ensures valid input and converts arguments into an array of integers:
- **Join Arguments**: `join_args` concatenates all arguments into a single string, separating them with spaces. This handles inputs like `./push_swap "1 2 3"` or `./push_swap 1 2 3`.
- **Split String**: Uses `ft_split` to split the joined string into an array of strings based on spaces.
- **Count Numbers**: `count_args` determines the number of numbers (`count`) in the split array.
- **Validation**: Each string is validated with `is_numr` to ensure it represents a valid integer (digits, optional leading `+` or `-`, no other characters). Checks for integer overflow (`INT_MAX`/`INT_MIN`) using `ft_atol`.
- **Memory Allocation**: Allocates memory for `num_array` to store the integers.
- **Conversion**: Converts each string to an integer with `ft_atoi` and stores it in `num_array`.
- **Duplicate Check**: `check_dups` ensures no duplicate numbers exist. If duplicates are found, it prints "Error" and exits.
- **Cleanup**: Frees the split array and returns the parsed `num_array` and `count`.

If the first argument is empty (`ft_strlen(argv[1]) == 0`), it prints "Error" and exits.

### 3. Stack Initialization
After parsing, the program initializes the stacks:
- **Variable Initialization**: `init_variables` sets `stack_a` and `stack_b` with `head = NULL` and `size = 0`.
- **Stack Population**: `init_stacks` populates `stack_a` with the parsed numbers:
  - **Allocate and Copy**: `allocate_and_copy` creates a `t_sort_data` structure, allocating memory for `sorted` (copy of input numbers) and `indices` (to store sorted indices).
  - **Sort and Index**: `sort_and_index` sorts the `sorted` array using bubble sort and assigns each number in the original array an index based on its position in the sorted array. This index (`s_index`) is used for efficient sorting comparisons.
  - **Push to Stack**: `stack_head_placer` adds each number and its index to `stack_a` as a node (`t_node`), with the most recent number at the head.
- **Memory Management**: Frees `sorted` and `indices` after populating the stack.

### 4. Sorting Stage
The `sort` function determines the appropriate sorting strategy based on the input size (`len`):
- **Already Sorted**: If `check_sorted` returns true (numbers in `stack_a` are in ascending order), the program frees memory and exits.
- **2 Numbers**: If `len == 2`, performs a single `swap` (`sa`) to sort.
- **3 Numbers**: If `len == 3`, uses `simple_sorter` to sort with a combination of `swap`, `rotate`, and `reverse_rotate` based on the position of the minimum index.
- **4–7 Numbers**: If `len <= 7`, uses `s_insertion_sort`:
  - Pushes all but three numbers to `stack_b`, keeping the smallest numbers first.
  - Sorts the remaining three numbers in `stack_a` using `simple_sorter`.
  - Pushes numbers back from `stack_b` to `stack_a`.
- **More than 7 Numbers**: Uses a chunk-based sorting algorithm (`sort1` and `sorter2`):
  - **sort1**: Divides the numbers into chunks based on their indices (size divided by 12). Pushes numbers to `stack_b`, rotating `stack_b` for smaller indices to maintain partial order.
  - **sorter2**: Moves numbers back to `stack_a` in descending index order, choosing the shortest path (rotate or reverse rotate) to bring the target number to the top of `stack_b`.

### 5. Stack Operations
The program uses the following operations, implemented in `commands.c`:
- **Swap (`swap`)**: Swaps the top two elements of a stack (`sa` for `stack_a`, `sb` for `stack_b`).
- **Push (`push`)**: Moves the top element from one stack to the other (`pa` to push to `stack_a`, `pb` to push to `stack_b`).
- **Rotate (`rotate`)**: Moves the top element to the bottom of the stack (`ra` for `stack_a`, `rb` for `stack_b`).
- **Reverse Rotate (`reverse_rotate`)**: Moves the bottom element to the top of the stack (`rra` for `stack_a`, `rrb` for `stack_b`).

Each operation prints its corresponding command (e.g., `sa`, `pb`) if the `bool b` parameter is `true`.

### 6. Utility Functions
- **Stack Management**:
  - `stack_head_placer`: Adds a new node to the top of a stack.
  - `stack_head_taker`: Removes and returns the top node's value, freeing the node.
  - `stack_len`: Returns the number of nodes in a stack.
  - `stack_freer`: Frees all nodes in a stack.
- **Sorting Helpers**:
  - `get_min`: Finds the smallest index in a stack.
  - `counter`: Counts the steps to reach a specific index in a stack.
  - `check_sorted`: Verifies if `stack_a` is sorted in ascending order.
  - `check_rot_sort`: Checks if a three-number stack can be sorted with a single rotation.
- **Parsing Helpers**:
  - `is_numr`: Validates if a string represents a number.
  - `free_split`: Frees a split string array.
  - `check_dups`: Checks for duplicate numbers.

### 7. Memory Management
The program ensures no memory leaks:
- Frees `num_array` after sorting.
- Frees `stack_a` and `stack_b` nodes using `stack_freer`.
- Frees temporary arrays (`split`, `sorted`, `indices`) during parsing and initialization.

## Key Features
- **Input Validation**: Handles edge cases like empty inputs, non-numeric inputs, duplicates, and integer overflows.
- **Efficient Sorting**: Uses tailored algorithms for small (2–7) and large (>7) inputs to minimize operations.
- **Modular Design**: Separates parsing, stack operations, and sorting logic into distinct files (`arg_joiner.c`, `commands.c`, `pars_utils.c`, `push_swap.c`, `sort_utils.c`, `stack_helper.c`, `stackers.c`).
- **Operation Output**: Prints the sequence of operations to achieve the sorted stack.