# ISO8859-7 to ISO8859-1

Convert text written in ISO8859-7 (greek) encoding to ISO8859-1.

## Implementation

Most of the ISO8859-7 letters map directly to the ISO8859-1 ones. A Finite-State Machine is used to convert the rest (greek double letters).

## Compile

```bash
make convert
```

## Typical usage

Read ISO 8859-7 text from input_file, convert it to ISO 8859-1 and write the result to out_file:

```bash
./convert < input_file > out_file
```

## Tests

See [tests](tests). A t1_8859-7.txt input file is provided and its corresponding t1_8859-1.txt out file.

## Profiling

'convert' has been tested for memory leaks with [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer).
