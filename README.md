# Push_Swap

# Table of Contents
1. [Description](#description)
2. [Installation Instructions](#installation-instructions)
3. [Usage Instructions](#usage-instructions)
4. [Key Features](#key-features)
5. [Contribution Guidelines](#contribution-guidelines)
6. [Acknowledgments](#acknowledgments)
7. [License Information](#license-information)
8. [Contact Information](#contact-information)
9. [Project Development](#project-development)

## Description

Push Swap is a sorting algorithm project that utilizes two stacks and a set of predefined operations to sort a list of integers. The project is part of the 42 curriculum and is implemented in C. The primary challenge lies in sorting the stack with the least possible number of operations. This project not only tests your programming skills but also your ability to devise and implement optimized algorithms under specific constraints.

## Installation Instructions

Before you begin, ensure you have met the following requirements:

1. **Download the library**: You can clone the library from GitHub using the following command in your terminal:
```bash
git clone https://github.com/Vpekdas/push_swap.git
```

2. **Install a C compiler**: If you don't already have a C compiler installed, you will need one to build and use this library. You can install the [Clang compiler](https://clang.llvm.org).
   
- On a Mac, you should already have Clang installed as part of Xcode Command Line Tools. You can confirm this by running clang --version in your terminal. If it's not installed, you'll be prompted to install it.

- On a Linux machine, use the package manager for your distribution. For example, on Ubuntu:
```bash
sudo apt install clang
```

## Usage Instructions

To use the Push Swap project, follow these steps:

1 - Clone the repository: Clone this repository to your local machine. You can do this by running the following command in your terminal:
```bash
git clone https://github.com/Vpekdas/push_swap.git
```

2 - Compile the project: Navigate to the cloned repository and compile the project using the provided Makefile. Run the following command in your terminal:
```bash
make && make bonus
```
This will create two executables: push_swap and checker.

3 - Run the push_swap program: The push_swap program takes a list of integers as arguments and returns a series of operations that would sort the list. Here's an example:
```bash
./push_swap 3 2 1 0
```
This will output a series of operations, like sa, rra, etc.

4 - Verify the sort with the checker program: The checker program takes a list of integers as arguments and then reads operations from the standard input. It executes these operations and then checks if the list of integers is sorted. Here's an example:
You can either create an environment variable like ARG="1 3 2 10", then execute ./push_swap $ARG | ./checker $ARG. This will feed the output of push_swap (the operations) into checker.

```bash
ARG="1 3 2 10"; ./push_swap $ARG | ./checker $ARG
```

Alternatively, you can manually input the operations into checker. If you launch checker alone with a list of numbers, it will wait for you to input some instructions. To exit properly, just press ctrl + D. Here's an example:
```bash
echo "sa\nrra" | ./checker 3 2 1 0
```
This will output OK if the operations sorted the list, or KO if no

## Key Features

***Structure used:***
I chose to implement this project using a linked list. This decision was driven by my desire to gain more experience with this data structure, which I initially found challenging. I can assure you that after this project, you'll appreciate the versatility of linked lists over arrays. Essentially, we create a node for each argument and append it to the list using our Libft function. One advantage of this approach is that we don't need to pre-calculate the number of nodes to allocate; we can simply allocate and push nodes one by one. This method is particularly effective for instructions like push_to_a or push_to_b, where we are essentially detaching a node and attaching it elsewhere. For rotate and other instructions, I'm not actually moving the nodes themselves, but rather swapping the content variable within my node structure. I found this approach to be simpler and more intuitive.

There is my structure
```C
typedef struct s_list
{
    int           content; // This field holds the content of the node, which in this case is an integer.
    struct s_list	*next;   // This is a pointer to the next node in the linked list.
}					t_list;
```

***Sorting Strategy:***
The Push Swap project is optimized using a specific strategy that involves sorting from larger to smaller numbers in stack B before pushing them into stack A. This approach is beneficial because the first number to be pushed will be at the deep end of the list.

***Move Determination:***
The next step involves determining the optimal move to make. This requires identifying the position of a number in a stack and where it should go. This process allows us to "count" moves for every number and then make a decision.

This is the function i use to determine where a number should be placed. find bigger and smaller are simple function what will return the concerned number.
How do I know where a number should be placed ? So our goal is to sort stack b from bigger to smaller.

1 -> The first check involves determining if a number should be placed at the top of the stack, i.e., at index 0. If our number is greater than the first index (0) and smaller than the last, it means it should go at the top. Note that the stack behaves like a circular linked list, meaning the last element is followed by the first. For example, consider the number 7 in stack A, and stack B contains three numbers [1, 0, 9]. We are only concerned with fitting a number correctly, not necessarily sorting the stack. If we place the number 7 at index 0, we get [7, 1, 0, 9]. If we rotate the stack, we get [9, 7, 1, 0]. The number 7 doesn't disrupt the stack; we are still sorting this stack from larger to smaller. So, even if the stack doesn't appear to be sorted from larger to smaller, we are only concerned with the position of the numbers.

2 -> The second check is as follows: If the number we want to place is larger than the largest number in stack B or smaller than that, it should be placed at its correct position. Let's take the same example as before, but this time our number is 10 and stack B is [1, 0, 9]. To maintain a sorted stack, our number should go at the index of the largest number in stack B (3rd index), resulting in [1, 0, 10, 9]. The same rule applies for the smallest number. If our number is 0 and stack B is [7, 1, 9], it should also be placed next to the largest number, at its correct index, resulting in [7, 1, 0, 9].

3 -> With the above checks, we now know that the number we want to place is likely between two consecutive numbers. We will use a while loop to check if our number fits between these two numbers. We start the variable i at 1 because we begin by comparing the first and second numbers. At the very least, the index should be 1 if it fits. If we start the index at 0 and neither of the previous checks were correct, the function could incorrectly return 0 when comparing the first two numbers.

So, if our number is larger than the first compared number or smaller than the next one, we will continue. For example, let's say stack B is [7, 1, 9, 3, 10, 4] and the number in stack A is 8. It's neither smaller nor larger than any number in stack B, so it will go somewhere between two numbers.

If we do the first comparison, is 8 > 7? Yes, then let's compare it with 1 and 9. We will increment the pointer of the "a" variable, which was the first node, now it's pointing to the number 1, and next is pointing to 9. Is 8 > 1? Yes, so let's compare if it fits between 9 and 3. Is 8 > 9? No, but we have incremented i two times. It started at 1, so 2 + 1 = 3, which is our index to maintain our descending stack. We can conclude that a number from stack A should be placed immediately after a number in stack B that is larger than it.
```C
int	ft_find_right_pos(t_list *a, int c)
{
	int		i;
	t_list	*next;

	i = 1;
	next = a->next;
	if (c > a->content && c < ft_lstlast(a)->content)
		return (0);
	if (c > ft_find_biggest(a) || c < ft_find_smaller(a))
		return (ft_num_pos(a, ft_find_biggest(a)));
	while (a->content < c || next->content > c)
	{
		a = a->next;
		next = a->next;
		i++;
	}
	return (i);
}

int	ft_find_biggest(t_list *a)
{
	int		num;
	t_list	*current;

	current = a;
	num = current->content;
	while (current)
	{
		if (current->content > num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

int	ft_find_smaller(t_list *a)
{
	int		num;
	t_list	*current;

	current = a;
	num = current->content;
	while (current)
	{
		if (current->content < num)
			num = current->content;
		current = current->next;
	}
	return (num);
}
```

***Move Scenarios:***
We have four move scenarios, each ending at the same position but using a different set of moves. For example, one scenario might involve placing a number where we want using only ra and rb, while another might use only ra and rrb. This approach also integrates optimized moves like rr, which counts as one move but actually moves two numbers.

Here, I have four functions that calculate the number of moves needed for each combination set. Essentially, to count the moves, I need two factors: the index where my number should go and its current position in the stack. Therefore, we need a function that returns the index of the number (ft_num_pos).

Let's calculate how many moves I need by using just the ra and rb instructions. Suppose my number is at the 4th index in stack A. I use my function ft_num_pos and pass it the number that I want to push. Next, I need to know the index where it should go in stack B, so I call ft_find_right_pos. Let's assume our number must go to the 3rd position. So, it's at index 4 in stack A and must go to index 3 in stack B.

By using only ra and rb, I first initialize at the index where it should go, because I know that at least, I need to make 3 moves if it needs to go to the 3rd index. The optimization part comes next. For instructions that go in the same direction (ra-rb and rra-rrb), I can use rr for the first case and rrr for the second case, because I know that I will rotate both stacks in the same direction, probably not the same amount for each stack, but I can check that.

So, I know that I need at least 3 moves to go to index 3 in stack B. If the index where it should go is less than its current index in stack A, I know that my minimum move will be the smaller between its index and where it should go. Why? Because I know that I can push numbers only if they are at the top of a stack. So, my number is at index 4, so I need to make 4 moves. But I said my number must go to index 3 in stack B. I can do 4 ra and 3 rb, but I can also do 3 rr and 4 ra, which is twice as efficient. By comparing which index is smaller (its index in stack A or the index of where it should go in stack B), I can estimate my minimum move because I know that I can use rr or rrr.

Let's do the same thing for rra-rb, which are not moving in the same direction, so we need to calculate differently. Overall, I'm using ft_find_right_pos to calculate the moves I should make in stack B and ft_num_pos to count moves in stack A. As you might have guessed, if I add these two numbers, I will have my move count. I can't really use rr here since we will move the stack in the opposite direction.

First, let's count the moves in stack B using our function ft_find_right_pos. Now we will add the move number in stack A. In the case of rra, it will be the size of the list minus its position because we will rotate the list in the opposite direction. (In the case of ra, it will be just its position). We can simply add this number to our right position index and there we have our move count.
```C
int	ft_case_ra_rb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_right_pos(b, c);
	if (i < ft_num_pos(a, c))
		i = ft_num_pos(a, c);
	return (i);
}

int	ft_case_rra_rb(t_list	*a, t_list *b, int c)
{
	int	i;

	i = ft_find_right_pos(b, c);
	if (ft_num_pos(a, c) > 0)
		i += ft_lstsize(a) - ft_num_pos(a, c);
	return (i);
}

int	ft_case_rra_rrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_right_pos(b, c) > 0)
		i = ft_lstsize(b) - ft_find_right_pos(b, c);
	if (i < (ft_lstsize(a) - ft_num_pos(a, c)) && ft_num_pos(a, c) > 0)
		i = ft_lstsize(a) - ft_num_pos(a, c);
	return (i);
}

int	ft_case_ra_rrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_num_pos(a, c);
	if (ft_find_right_pos(b, c) > 0)
		i += ft_lstsize(b) - ft_find_right_pos(b, c);
	return (i);
}

int	ft_num_pos(t_list *a, int num)
{
	t_list	*current;
	int		pos;

	current = a;
	pos = 0;
	while (current)
	{
		if (current->content == num)
			return (pos);
		current = current->next;
		pos++;
	}
	return (pos);
}
```

***Sorting Small Lists:***
An algorithm for sorting three numbers has been hardcoded, so the algorithm for larger lists is based on this. The goal is to push until we have three numbers left, then sort them using the algorithm for three numbers.


Not much to say here, i have hardcoded this part, thanks a lot to @JamieDawson for his [illustration](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) which is very clear !

```C
void	ft_sort_three(t_list **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;
	if (top > mid && mid < bot && bot > top)
		ft_sa(a, PRINT);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_sa(a, PRINT);
		ft_rra(a, PRINT);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_ra(a, PRINT);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_sa(a, PRINT);
		ft_ra(a, PRINT);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(a, PRINT);
}
```

***Final Steps:***
Once this is done, we can push from stack B to A, repeating the same calculations but now aiming to create a list sorted from smallest to largest - the opposite approach to before. Finally, we locate the smallest number. If it is located in the first half of the list, we will use either ra or rra to make the fewest moves. This strategy ensures the efficiency of the sorting process.

So i did a while loop till i have 3 numbers left, new thing here we know which move is the best but how to apply this move and calculating on the updated list ? Well as our 4 scenarios for calculating, we have also 4 applying scenarios. The idea we call at first our function that we return the lest move (ft_which_move_b). he will compare 4 scenarios for each numbers and his return vaalue will be a certain number of moves, which will be surely the least but for zhich number in stack a ? we dont know pretty much haha. But we know one thing, his moves number,

SO in ft_sort_till_3_remains function, we will at first store the least moves in i variables (not a great name for a variable, i m trying to clean code now i promise !), next we will call our 4 functions that calculates moves, and if it fits with a number, it means we have found our number !. Next step -> applying (scroll down please).

```C
int	ft_which_move_b(t_list *a, t_list *b)
{
	t_list	*current;
	int		cost;
	int		move;

	current = a;
	cost = ft_case_ra_rb(a, b, current->content);
	move = 0;
	while (current)
	{
		move = ft_case_ra_rb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_ra_rrb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rb(a, b, current->content);
		if (cost > move)
			cost = move;
		move = ft_case_rra_rrb(a, b, current->content);
		if (cost > move)
			cost = move;
		current = current->next;
	}
	return (cost);
}

void	ft_sort_till_3_remains(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	while (ft_lstsize(*a) > 3 && ft_check_sorted(*a) == 1)
	{
		current = *a;
		i = ft_which_move_b(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_ra_rb(*a, *b, current->content))
				i = ft_apply_ra_rb(a, b, current->content);
			else if (i == ft_case_ra_rrb(*a, *b, current->content))
				i = ft_apply_ra_rrb(a, b, current->content);
			else if (i == ft_case_rra_rb(*a, *b, current->content))
				i = ft_apply_rra_rb(a, b, current->content);
			else if (i == ft_case_rra_rrb(*a, *b, current->content))
				i = ft_apply_rra_rrb(a, b, current->content);
			else
				current = current->next;
		}
	}
}
```

Let's revisit our ra-rb combination set. The idea is to call the appropriate function for the given scenario, which is somewhat hardcoded.

The first while loop allows us to rotate both stacks as needed simultaneously. As long as the first number in stack A is not the one we want (given in parameter) and as long as the function ft_find_right_pos doesn't return 0 (which means the stack B hasn't moved enough to accommodate our number), we will rotate both stacks.

For example, if I need to move stack A 3 times and stack B 4 times, the while loop will be executed 3 times. Each time, ft_find_right_pos will return a decreased value, and of course, the first number of stack A will be the one we want to push.

The next two while loops will move stack A and stack B separately. In our example, we won't rotate stack A anymore, but we need to rotate stack B more. After that, we know that our two stacks are positioned correctly to push a number. So, let's just push.
```C
int	ft_apply_ra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c && ft_find_right_pos(*b, c) > 0)
		ft_rr(a, b, PRINT);
	while ((*a)->content != c)
		ft_ra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_ra_rrb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_ra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_rra_rrb(t_list **a, t_list **b, int c)
{
	while (((*a)->content != c) && (ft_find_right_pos(*b, c) > 0))
		ft_rrr(a, b, PRINT);
	while ((*a)->content != c)
		ft_rra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rrb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}

int	ft_apply_rra_rb(t_list **a, t_list **b, int c)
{
	while ((*a)->content != c)
		ft_rra(a, PRINT);
	while (ft_find_right_pos(*b, c) > 0)
		ft_rb(b, PRINT);
	ft_pb(a, b, PRINT);
	return (-1);
}
```

And here we are, finally at the final step. All of these functions are part of another code. The final adjustment is made with this if statement. We will locate our smallest number and then decide whether to execute ra or rra.
```C
 if (pos < ft_lstsize(*a) / 2)
		while ((*a)->content != ft_find_smaller(*a))
			ft_rra(a, PRINT);
	else
		while ((*a)->content != ft_find_smaller(*a))
			ft_ra(a, PRINT);
```

```C
void	ft_sort_hundred_and_more(t_list **a, t_list **b)
{
	int	smallest;
	int	pos;

	smallest = ft_find_smaller(*a);
	pos = ft_num_pos(*a, smallest);
	ft_pb(a, b, PRINT);
	ft_pb(a, b, PRINT);
	ft_sort_till_3_remains(a, b);
	ft_sort_three(a);
	ft_sort_till_empty(a, b);
	if (pos < ft_lstsize(*a) / 2)
		while ((*a)->content != ft_find_smaller(*a))
			ft_rra(a, PRINT);
	else
		while ((*a)->content != ft_find_smaller(*a))
			ft_ra(a, PRINT);
}
```

## Acknowledgments

This solution was inspired by @ayogun's method. His tutorial was impressively clear and insightful, and I am deeply grateful for his willingness to share his knowledge. I highly recommend following his tutorial. All calculations are explored in depth, so don't hesitate to delve into his Medium post.

* [ayogun's Github](https://github.com/ayogun)
* [ayogun's Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## Contribution Guidelines

I welcome contributions from everyone. Here are some guidelines to follow:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/push_swap.git
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on. Do not make changes directly on the master branch
```bash
git checkout -b your-branch-name
```

4. **Make your changes**: Make your changes in the new branch. Ensure your code follows the [norminette](https://github.com/42School/norminette).

5. **Commit your changes**: Commit your changes regularly with clear, descriptive commit messages.
```bash
git commit -m "Your commit message"
```

6. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

7. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.
Please note that this project has a code of conduct, and contributors are expected to adhere to it. Any contributions you make are greatly appreciated.

## License Information

This project is licensed under the [MIT License](LICENSE).

The MIT License is a permissive license that is short and to the point. It lets people do anything they want with your code as long as they provide attribution back to you and don’t hold you liable.

For the full license text, see the [LICENSE](LICENSE) file.

## Contact Information

If you have any questions, issues, or if you want to contribute, feel free to reach out to me:

- GitHub: [@Vpekdas](https://github.com/Vpekdas)
- Discord: Captain-Plouf#7811

## Project Development

This project started as a simple tool for personal use and is evolving into a full-fledged library. While it has been a solo endeavor so far, contributions from the community are welcome and appreciated.

### Current Status

The project is currently complete and not in active development. However, maintenance and updates will be done as needed.

### Future Plans

Plans for future development include adding more functions, improving performance, and expanding the documentation.

### Known Issues

There are currently no known issues. If you find a bug, please report it in the [issue tracker](https://github.com/Vpekdas/push_swap/issues).

### Contributing

Contributions are always welcome! See the [Contribution Guidelines](#contribution-guidelines) for more information.


