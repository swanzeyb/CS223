.data
get_num: .asciiz "Enter number: "
search_prompt: .asciiz "Enter number to search for: "
found_message: .asciiz "Number found at index: "
not_found_message: .asciiz "Number not in the array.\n"

.text
main:
  addiu $sp, $sp, -40   # Allocate stack space for this frame
  li $s0, 10            # Get 10 numbers from user

input:
  addiu $s0, $s0, -1    # Decrement loop counter

  la $a0, get_num
  li $v0, 4             # Setup syscall to print string
  syscall

  li $v0, 5             # Setup syscall to read int
  syscall               # Syscall stores result in $v0

  li $t0, 4
  multu $s0, $t0       # Get the offset
  mflo $t1              # Store result in $t1

  add $t2, $sp, $t1     # Calculate the address
  sw $v0, 0($t2)        # Store the input on the stack

  bnez $s0, input       # Get next input if not zero

print_nums:
  # Print the numbers in order
  li $s0, 10

  addiu $s0, $s0, -1
  li $t0, 4
  multu $s0, $t0       # Get the offset
  mflo $t1              # Store result in $t1

  add $t2, $sp, $t1     # Calculate the address
  lw $a0, 0($t2)        # Load the number to print
  li $v0, 1             # Setup syscall to print int
  syscall

  bnez $s0, print_nums  # Print next number if not zero

  # Prompt user for search number
  la $a0, search_prompt
  li $v0, 4             # Setup syscall to print string
  syscall

  li $v0, 5             # Setup syscall to read int
  syscall               # Syscall stores the search number in $v0

  move $t3, $v0         # Store the search number in $t3

  # Binary search setup
  li $s0, 0             # low end of search
  li $s1, 9             # high end of search, length - 1

loop:
  addu $t0, $s0, $s1    # Add low + high
  sra $t0, $t0, 1       # Divide by 2

  li $t4, 4
  multu $t0, $t4       # Get the offset for middle element
  mflo $t4

  add $t5, $sp, $t4     # Address of the middle element
  lw $t6, 0($t5)        # Load the middle element

  beq $t6, $t3, has_result   # If found, jump to has_result
  bgt $t6, $t3, greater      # If mid > search, jump to greater
  blt $t6, $t3, less         # If mid < search, jump to less

greater:
  subu $s1, $t0, 1      # Move high to mid - 1
  j loop_check

less:
  addu $s0, $t0, 1      # Move low to mid + 1

loop_check:
  ble $s0, $s1, loop    # Continue loop if low <= high
  j no_result

has_result:
  # Print found message
  la $a0, found_message
  li $v0, 4
  syscall

  move $a0, $t0
  li $v0, 1             # Setup syscall to print int
  syscall

no_result:
  # Print not found message
  la $a0, not_found_message
  li $v0, 4
  syscall

