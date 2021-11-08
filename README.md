# Purpose of endian-demo
This C programs shows how your (and my) computer handles they byte order of integers (little endian vs. big endian) and demonstrates the conversion of endianness using `htole32` and `htobe32`.

There are a lot of web pages and other resources that show what *endian* means and the impact on byte order, but there is nothing like having a C program to run to see how your machine deals with endianness.

So many times I have had to think way too much about how to organize 16- and 32-bit integers into stream of data byte-by-byte so that I could know the order of bytes when a pointer is incremented one byte at a time.

This `endian-demo` C program that shows:

- How your computer natively organizes bytes of an unsigned integer value.
- How bit shifting (e.g, >>) affects the values.
- The values returned when when incrementing, for example, an `uint8_t` pointer byte-by-byte.
- Using host-to-little-endian `htole32` and host-to-big-endian `htobe32` to get the desired order of bytes of an integer value consisting of 2+ bytes.

# Example Run

Here is an example output on my PC running Ubuntu Linux on a VirtualBox under Windows on an Intel i7 processor.  As expected, my PC is little endian (and native byte order is the same as the byte order after host-to-little-endian conversion).

```
$ ./endian-demo 

======== Native Value on Host ========
Native Value: ABCDEF12
                                 MSB      LSB
Using bit shifting to get bytes: AB CD EF 12

Using address increment to get bytes:
At address 0x7ffdf7ca90e8: 12
At address 0x7ffdf7ca90e9: EF
At address 0x7ffdf7ca90ea: CD
At address 0x7ffdf7ca90eb: AB
Address of val (uint32_t): 0x7ffdf7ca90e8
Address of pbyte (uint8_t) (first byte of val): 0x7ffdf7ca90e8

======== After Conversion Host-to-Big-Endian ========
                                 MSB      LSB
Using bit shifting to get bytes: 12 EF CD AB

Using address increment to get bytes:
At address 0x7ffdf7ca90ec: AB
At address 0x7ffdf7ca90ed: CD
At address 0x7ffdf7ca90ee: EF
At address 0x7ffdf7ca90ef: 12

======== After Conversion Host-to-Little-Endian ========
                                 MSB      LSB
Using bit shifting to get bytes: AB CD EF 12

Using address increment to get bytes:
At address 0x7ffdf7ca90f0: 12
At address 0x7ffdf7ca90f1: EF
At address 0x7ffdf7ca90f2: CD
At address 0x7ffdf7ca90f3: AB

```

# Compiling and Running the Code

To compile:

`$ gcc main.cpp -o endian-demo`

To run:

`$ ./endian-demo`
