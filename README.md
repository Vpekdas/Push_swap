# Push Swap - Because Swap_push isn’t as natural

```
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⡜⢣⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⣿⡆⢀⣤⡾⠟⠋⢉⣁⡀⢀⣈⡉⠙⠻⢷⣤⡀⢰⣿⣷⠀⠀⠀⠀
⠀⠀⠀⠀⠈⢉⣏⠙⠁⣠⣶⣿⣿⣿⡇⢸⣿⣿⣿⣶⣄⠈⠋⣹⡉⠁⠀⠀⠀⠀
⠀⠀⠀⠀⣠⡿⠁⣠⣄⠙⢿⣿⣿⣿⡇⢸⣿⣿⣿⡿⠋⣠⣄⠈⢿⣄⠀⠀⠀⠀
⠀⠀⠀⢠⡿⠁⣼⣿⣿⣷⣄⠙⠛⢉⣀⣀⡉⠛⠋⣠⣾⣿⣿⣧⠈⢿⡄⠀⠀⠀
⠀⠀⠀⣾⠇⢰⣿⣿⣿⣿⡟⢀⣾⡿⠿⠿⢿⣷⡀⢻⣿⣿⣿⣿⡆⠸⣷⠀⠀⠀
⢾⣿⠶⣉⠀⢈⣉⣉⣉⣉⠀⢸⣿⡇⠀⠀⢸⣿⡇⠀⣉⣉⣉⣉⡁⠀⣉⠶⣿⡷
⠀⠀⠀⢿⡆⠸⣿⣿⣿⣿⣧⠈⢿⣷⣶⣶⣾⡿⠁⣼⣿⣿⣿⣿⠇⢰⡿⠀⠀⠀
⠀⠀⠀⠘⣷⡀⢻⣿⣿⡿⠋⣠⣤⣈⠉⠉⣁⣤⣄⠙⢿⣿⣿⡟⢀⣾⠃⠀⠀⠀
⠀⠀⠀⠀⠙⣷⡀⠙⠋⣠⣾⣿⣿⣿⡇⢸⣿⣿⣿⣷⣄⠙⠋⢀⣾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣈⣏⣠⡀⠙⠿⣿⣿⣿⡇⢸⣿⣿⣿⠿⠋⢀⣄⣹⣁⡀⠀⠀⠀⠀
⠀⠀⠀⠀⢿⣿⠇⠈⠛⢷⣦⣄⣈⡉⠁⠈⢉⣁⣠⣴⡾⠛⠁⠸⣿⡿⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⢣⡜⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
```

Ahoy, fellow coders! Welcome to the Push Swap project, a challenging expedition into the world of sorting algorithms and optimization. In this quest, you will harness the power of stacks and embark on a journey to sort integers with the fewest possible operations.

# Table of Contents

- [Push Swap - Because Swap_push isn’t as natural](#push-swap---because-swap_push-isnt-as-natural)
  - [Overview](#overview)
  - [Key Features](#key-features)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
  - [Usage](#usage)
  - [License](#license)

## Overview

Push Swap is a project that challenges you to sort a stack of integers using two stacks and a set of predefined operations. Your ultimate goal is to arrange the numbers in ascending order on one of the stacks using the most efficient sequence of operations.

## Key Features

- **Two Stacks:** Utilize two stacks, Stack A and Stack B, to manipulate and sort the integers.
- **Optimization:** Minimize the number of operations to achieve a sorted stack.

## Getting Started

To embark on the Push Swap adventure, follow these instructions:

### Prerequisites

Before you begin, ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/).

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/Vpekdas/push_swap
    ```

2. Navigate to the project directory:

    ```bash
    cd push_swap
    ```

3. Compile the project using `make` and `make bonus` if you want to use my own checker:

    ```bash
    make
    ```

    This will generate two executables, `push_swap` and `checker`.

## Usage

1. Execute the `push_swap` program with a list of integers as arguments:

    ```bash
    ./push_swap 3 1 4 2
    ```

    This will output a series of operations to sort the stack.

2. Optionally, you can use the `checker` program to validate the sorting:

    ```bash
    ./push_swap 3 1 4 2 | ./checker 3 1 4 2
    ```

    The `checker` program reads the operations from standard input and verifies if the stack is sorted.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
