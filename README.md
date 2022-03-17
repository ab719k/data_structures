# data_structures


## hello_cpp
This is an example code to demonstrate usage of cmake to build a binary which depends on the library. The Hello library implement a string concatenation from stdin/cin adding the words to a vector, and then display on the stdout/cout. The code is in C++ and Hello class is implemented. Demo.cpp creates an instance of the class and add the words to the object, and in the end display all the words on the screen.

```
cd hello_cpp
mkdir _build
cd _build
cmake ..
make
echo "This is the hello world example" >> ./Demo/helloDemo 
```


## queue implementation

## Tree implementation
Create a Demo app, that read a file and load its content into a tree.
```
$ cd tree
$ mkdir _build
$ cd _build
$ cmake -DCMAKE_BUILD_TYPE=Debug .. && make
$ ./TreeDemo/treeDemo ../../data/sgb-words5.txt
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit
Enter your choice: f
Enter name to be found : yummy
The element with name = 'yummy' is present in the tree.
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit
Enter your choice: i
Enter word: amit
 You entered amit
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit
Enter your choice: f
Enter name to be found : sonia
The element with name = 'sonia' is not present in the tree.
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit
Enter your choice: f
Enter name to be found : amit
The element with name = 'amit' is present in the tree.
Menu
i: Insert Name
p: Print Tree
f: Find a Name
x: Exit 
```
### TreeDemo
### Tree

