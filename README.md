# Lab15 Simple Archive Utility

## Overview

This simple archive utility is a command-line tool for creating, extracting, and listing the contents of a custom archive file format. It's written in C and designed to handle basic archiving tasks without file compression.

## Features

- **Create Archive**: Combine multiple files into a single archive file.
- **Extract Archive**: Extract all files from an archive back to their original format.
- **List Archive Contents**: Display a list of files contained in an archive.

## Installation

To install this program, you will need a C compiler like GCC. Compile the program with the following command:

```bash
gcc -o arc main.c
```

This will create an executable named `arc`.

## Usage

The program can be used with the following command-line arguments:

- `--file <archive_name.arc>`: Specify the archive file name.
- `--create`: Create an archive file.
- `--extract`: Extract files from an archive.
- `--list`: List files in an archive.
- `FILE1 FILE2 ... FILEN`: Specify files for archiving.

### Examples

1. **Creating an Archive**

   To create an archive named `data.arc` with files `a.txt`, `b.bin`, and `c.bmp`:

   ```bash
   ./arc --file data.arc --create a.txt b.bin c.bmp
   ```

2. **Extracting from an Archive**

   To extract files from `data.arc`:

   ```bash
   ./arc --file data.arc --extract
   ```

3. **Listing Contents of an Archive**

   To list the contents of `data.arc`:

   ```bash
   ./arc --file data.arc --list
   ```

## Limitations

- The program does not support file compression.
- Maximum file name length is limited to 256 characters.
- The program is designed for educational purposes and may not be suitable for production use.
