## :warning: Disclaimer

[ :uk: ] Please do not copy-paste this code. In this way, you won't learn a lot. Instead, you can use it to understand how to do some tricky part, but try to redo it by your own.
Just to let you know, some files may be incorrect. Some bugs may have passed through, or subject may have changed since I did this project.

[ :fr: ] S'il vous plait, ne copier-coller pas ce code. De cette manière, vous n'apprendrez pas grand chose. A la place, vous pouvez l'utiliser pour comprendre certaines parties plus complexes du sujet, mais essayez de le refaire par vos propres moyens.
Pour information, certains exercices pourraient être incorrects. Quelques bugs pourraient avoir réussi à passer au travers les mailles du filet, ou le sujet a peut-être changé depuis que j'ai complété le projet.

---
# 42-CommonCore_01.2025_PushSwap

The goal of this 42 common core project is to have a first look into the fabulous world of sorting algorithms. The objective here is not about time, but it's about how many operations you need to sort the given numbers using two stacks.

The project also include a checker, that you can compile using `make bonus`. 

In this project, I used the Turk sort algorithm. First, push every number except three in stack B, in descending order. Then, after a quick three-sorter for our three numbers still in stack A, I push everything back in stack A, rotating the stack when needed to include the bottom three numbers where they need to be. But before each push to stack B in the first part, it has to calculate the cost of the action for each number to push : rotations of stack A to access the given number, and rotations of stack B to put in the right place. After every calculation, it takes the number that will cost the least, and does the push.

## Usage

Without checker:
	```bash
	./push_swap [numbers]
	```

With checker:
	```bash
	./push_swap [numbers] | ./checker [same numbers]
	```

_Common Core Rank 02 - Completed in January 2025_  
_Code by me_
