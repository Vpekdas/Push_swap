# Push_swap

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Credits](#credits)
5. [Contributing](#contributing)
6. [License](#license)

## Description

Push_swap is a project from the 42 Common Core curriculum designed to create an algorithm that can perform a limited set of operations, such as rotate or reverse rotate, on two stacks to sort multiple numbers. The fewer instructions the algorithm uses, the higher the grade for the project.

As part of the 42 curriculum, this project comes with strict coding guidelines:
- The standard C library is forbidden, requiring the use of custom code for all tasks.
- A strict rule of 5 functions per file and 25 lines per function is enforced.
- There are restrictions such as no assignments on the same line and a focus on clean, maintainable code.

### Purpose

The goal of this program is to sort numbers using specific instructions. The program will output the sequence of instructions required to sort the given list of numbers.

### Technologies used

- C language.
- Make.

### Challenges and Future Features

The main challenges were choosing the appropriate data structure, either a linked list or an array, and then finding an efficient algorithm within the constraints of only being able to use specific instructions, such as rotating the stack, reversing, or swapping the first two numbers.

I’m not planning to add any new features at this time.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

## Run

1. Build the project:
```bash
make
```

2. This will create a `./push_swap` binary.

3. Run the program with the following arguments:

```bash
./push_swap "nb1 nb2 nb3"
```

or 

```bash
./push_swap  nb1 nb2 nb3
```

- Negative numbers, duplicate numbers, or values exceeding `INT_MAX` are forbidden.

4. This will create the checker:
```bash
make bonus
```

5. Then, provide it with a list of numbers, and it will read the standard input to check if the given order can effectively sort the list:
```
ARG="nb1 nb2 nb3"; ./push_swap $ARG | ./checker $ARG
```

## Credits

This solution was inspired by @ayogun's method. His tutorial was impressively clear and insightful, and I am deeply grateful for his willingness to share his knowledge. I highly recommend following his tutorial. All calculations are explored in depth, so don't hesitate to delve into his Medium post.

* [ayogun's Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/push_swap/issues).

If you'd like to contribute, please follow the steps outlined in [CONTRIBUTING.md](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).
