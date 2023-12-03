# Bubble Sort in C

This program implements the Bubble Sort algorithm in C. It sorts an array of integers in ascending order.

## Usage

The program takes command-line arguments. The usage is as follows:
```program_name -d <debug> <array_elements>```

- `program_name` is the name of the executable.
- `-d <debug>` is an option to enable or disable debug logs. Use '1' to enable and '0' to disable.
- `<array_elements>` are one or more integers to be sorted. Separate multiple elements with spaces.

For example:
program_name -d 1 64 34 25 12 22 11 90
This command will enable debug logs and sort the array `[64, 34, 25, 12, 22, 11, 90]`.

## Implementation

The Bubble Sort algorithm works by repeatedly swapping the adjacent elements if they are in the wrong order. This process continues until the entire array is sorted.

In the context of this program, the Bubble Sort algorithm is implemented in a function called `bubble_sort`. This function takes an array of integers and the size of the array as parameters. It sorts the array in place, meaning the original array is modified.

The `main` function parses the command-line arguments, calls the `bubble_sort` function to sort the array, and then prints the sorted array.

## Debug Logs

If the `-d 1` option is used, the program will print debug logs to the console. These logs include the state of the array after each pass of the Bubble Sort algorithm.

## Note

Please note that Bubble Sort is not suitable for large datasets as its average and worst-case complexity are of Ο(n^2) where n is the number of items.
