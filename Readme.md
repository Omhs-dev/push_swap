# Push Swap

A solution to the 42 push_swap project. Given a list of integers, the program prints a sequence of stack operations that sorts them. The goal is to minimize the number of operations.

- Program: `push_swap` (prints operations to stdout)
- Optional bonus: `checker` (reads operations from stdin and validates the final stack order)

## Build

```bash
make
```

```bash
make bonus
```

```bash
make clean
make fclean
make re
```

## Usage

```bash
./push_swap 2 1 3
sa
```

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker $ARG
OK
```

Errors:
- Non-integers, duplicates, or values outside 32-bit range print "Error" to stderr and exit non-zero.

Input format:
- Arguments can be given as multiple params or a single quoted string:
  - ./push_swap 3 2 1
  - ./push_swap "3 2 1"

## Supported operations

- Swap: `sa`, `sb`, `ss`
- Push: `pa`, `pb`
- Rotate: `ra`, `rb`, `rr`
- Reverse rotate: `rra`, `rrb`, `rrr`

## Algorithm (explained)

This implementation follows a common greedy insertion strategy with cost optimization:

1) Index normalization
   - Map each value to its rank (0..n-1). This avoids overflow issues and simplifies comparisons.

2) Initial split
   - Push all but three elements from stack A to B (often guided by index ranges). Keeping three in A simplifies the base sort.

3) Sort the small base
   - Sort the remaining 3 elements in A using a tiny, hardcoded routine (≤ 3 moves).

4) Compute targets
   - For each node in B, find its target position in A: the position where it should be inserted (the first element in A with a larger index; or the minimum if none is larger).

5) Cost calculation
   - For each node in B, compute:
     - cost_a: rotations needed to bring the target position in A to the top (positive for `ra`, negative for `rra`).
     - cost_b: rotations needed to bring the node in B to the top (positive for `rb`, negative for `rrb`).

6) Cheapest move execution
   - Pick the node with the minimal total cost and perform rotations:
     - If cost_a and cost_b have the same sign, use combined rotations (`rr` or `rrr`) to save moves.
     - Finish with remaining single-stack rotations, then `pa` to push the node to A.
   - Repeat until B is empty.

7) Final alignment
   - Rotate A so the smallest element (index 0) is on top. A is now fully sorted ascending.

Why this works well:
- The greedy choice plus combined rotations reduces overhead.
- Indexing ensures stable comparisons and consistent target selection.

## Example (5 numbers)

- Sort 5 numbers and see the operations:
  - ARG="5 2 3 1 4"
  - ./push_swap $ARG
    - Outputs a sequence like:
      - sa
      - pb
      - ...
    - The exact sequence depends on the implementation.

- Validate (if checker is built):
  - ARG="5 2 3 1 4"
  - ./push_swap $ARG | ./checker $ARG
    - OK

- Count operations (macOS, zsh/bash):
  - ARG="5 2 3 1 4"
  - OPS="$(./push_swap $ARG)"; echo "$OPS"; echo "Count: $(printf "%s\n" "$OPS" | wc -l)"

## Notes and constraints

- Only 32-bit signed integers are allowed. No duplicates.
- If the input is already sorted, no operations are printed.
- The checker expects one instruction per line with a trailing newline.