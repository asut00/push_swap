# push_swap 🎯

This project is an algorithmic challenge that involves sorting a stack of integers using the fewest possible moves. The program is built in C and emphasizes efficiency in sorting with specific constraints.

## About the Project

The **push_swap** project is part of the [42 School](https://42.fr/) curriculum and focuses on designing a sorting algorithm tailored for stack-based data. Using only two stacks (`a` and `b`) and a restricted set of operations, the goal is to sort stack `a` with the minimum possible number of moves.

### Key Objectives:

- Implement an efficient sorting algorithm in C.
- Optimize the algorithm to handle larger sets of integers while minimizing move count.
- Develop a deeper understanding of algorithmic complexity and time optimization.

## Project Overview

### Data Structures

- **Stack A**: Contains the unsorted integers at the start and the sorted integers at the end.
- **Stack B**: A temporary stack used to facilitate sorting.

### Allowed Operations

The following operations are allowed to manipulate the stacks:

- `sa`, `sb`, `ss`: Swap the first two elements of stack `a`, stack `b`, or both.
- `pa`, `pb`: Push the top element of stack `b` onto stack `a`, or vice versa.
- `ra`, `rb`, `rr`: Rotate stack `a`, stack `b`, or both upwards.
- `rra`, `rrb`, `rrr`: Rotate stack `a`, stack `b`, or both downwards.

### Sorting Strategy

I began this project by doing a lot of researches about the theory of sorting algorithms. 
I then started coding algorithms, starting from 3 numbers and slowly climbing my way up to bigger numbers, which allowed me to ask myself progressively what assets were the most appropriate to solve the problem. In the end, here are the principal steps of my main algorithm :
- Recursive pre-sorting with median and quartiles: we push everything into b using a recursive pre-sorting that pushes all elements above the 3rd quartile to the bottom of b, all elements between the median and the 3rd quartile to the top of b, and all elements below the median are pushed to the bottom of a. And we repeat this until there are only 3 elements left in a (if we have fewer than 3 elements, we use pa once or twice to ensure we have exactly 3 elements).
- Once only 3 elements are left in stack a, and the rest of the elements are pre-sorted in stack b, we sort the three elements in stack a (with the simple "sort three" function which is 3 conditions)
- Then we loop, transferring values from b back into a, evaluating each time which value will cost the least to place back into a (for each value, we assess its "target" and add the cost of placing the target at the top of stack a plus the cost of placing the current value in stack b at the top of stack b).

## Getting Started

To set up and run **push_swap** on your system:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/asut00/push_swap.git
   cd push_swap
   ```

2. **Compile the program**:
   ```bash
   make
   ```
   This generates an executable `push_swap` that can be used to sort a series of numbers.

## Usage

To use **push_swap**, run the executable with a list of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

The program will output a sequence of operations that sorts the input stack. Each line represents a single operation on the stacks.

For example:

```plaintext
pb
sa
ra
pb
ss
```

This sequence provides a step-by-step solution that sorts stack `a` using stack `b` as a temporary storage.

## 🏃 Performances

The objective set for the exercice was to get fewer than 700 actions to sort 100 numbers and fewer than 5500 actions to sort 500 numbers.

Here are my algorithm's performances :

100 values :

![complexity_100](https://github.com/asut00/Ecole42_Common-core_Push_swap/assets/146354882/4cc72932-7845-47fe-9f95-9b654f213daf)

500 values : 

![complexity_500](https://github.com/asut00/Ecole42_Common-core_Push_swap/assets/146354882/79ee79b4-d725-442c-bd08-1119e4289b65)


Thanks to [push_swap_tester](https://github.com/SimonCROS/push_swap_tester)

## 🧑‍🎨 Graphic visualization 

100 values :

https://github.com/user-attachments/assets/a636ad52-827c-4fa6-9d6a-d8a0c8e51c73

500 values : 

https://github.com/user-attachments/assets/9109e387-219b-4fd4-9cc9-9bed60294879

Thanks to [push_swap_visualiser](https://github.com/Niimphu/push_swap_visualiser)

## Limitations

**push_swap** is designed for integer sorting only and is optimized for limited, stack-based operations. Complex data structures or high memory usage are avoided in favor of stack manipulation efficiency.

## Author

- GitHub: [@asut00](https://github.com/asut00)  
- 42 Intra: `asuteau`
