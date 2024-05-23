# Log Analyzer

## Overview

Welcome to the Log Analyzer! This program allows you to analyze log files by sorting and searching through log entries based on IP addresses, dates, and times. It offers multiple functionalities including sorting logs using HeapSort, displaying the top IPs by the number of records, and searching for specific IP addresses using a binary search tree.

## Usage

### Compilation

To compile the program, run the following command:

```sh
g++ -o build/main main.cpp -std=c++11 && ./build/main
```

### Options

- `-h, --help`: Show help message and exit.
- `-s-max, --sort-maxheap`: Sort data by IP, date, and time in descending order (Uses HeapSort, MaxHeap).
- `-s-min, --sort-minheap`: Sort data by IP, date, and time in ascending order (Uses HeapSort, MinHeap).
- `-d, --display`: Display the top 10 IPs with the most records in descending order.
- `-s, --search`: Search for an IP in a binary search tree.

### Example Commands

To display the help message:

```sh
./build/main -h
```

To sort logs in descending order using MaxHeap:

```sh
./build/main -s-max
```

To sort logs in ascending order using MinHeap:

```sh
./build/main -s-min
```

To display the top 10 IPs with the most records:

```sh
./build/main -d
```

To search for an IP in the log records:

```sh
./build/main -s
```

## Author

Jesus Raul Jimenez Perez - A01666493

## File Structure

- `main.cpp`: The main source file containing the program's logic.
- `include/Log.h`: The header file containing the `Log` class definition and related functions.
- `data/log601-3.txt`: The input log file.
- `data/output601-1.out`: The output file for logs sorted by MaxHeap.
- `data/output601-2.out`: The output file for logs sorted by MinHeap.

## Additional Notes

- Ensure that the `data` directory contains the necessary input files before running the program.
- Output files will be generated in the `data` directory after sorting operations.

## License

This project is licensed under the MIT License.