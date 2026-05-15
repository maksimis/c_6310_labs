# Lab6 TxtFile

## Student
Student number: 1
Variant: 1

## Description

Text file processing library:
- file reading;
- line printing;
- line filtering by substring.

## Build

```bash
make
```

## Run

```bash
./txtfile data/input.txt apple
```

## Valgrind

```bash
valgrind --leak-check=full ./txtfile data/input.txt apple
```
