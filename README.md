## C/C++ string parser project

Math Expression Parsers

Algebric Parsers

SQL Query Parsers

Lex is a lexical analysis tool using to generte tokens from an input string, used extensively in compiler design/NLP etc.

prerequisite:
Linux: 
```
sudo apt install lex
```

MacOS: 
```
brew install lex
```

Once you compile Parser.l with ```lex```, it automatically generates a ```lex.yy.c``` file. You should compile this file with ```gcc/g++```.

```
g++ -g -c lex.yy.c -o lex.yy.o
```

On Linux:
```
g++ -g lex.yy.o  -o exe -lfl
```

on MacOS:
```
g++ -g lex.yy.o  -o exe -ll
```

Note that ```-lfl / -ll``` is the lex library we are linking our code to.