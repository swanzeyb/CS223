.text
# Calculate Fibonacci number
fibonacci:
  addiu $sp, $sp, -12 # Allocate stack space for this frame
  sw $ra, 0($sp) # Push return address
  sw $a0, 4($sp) # Push n

  # If n <= 1, return n
  blez $a0, return_n # If n <= 0, return n
  li $t0, 1 # Load 1 into $t0
  ble $a0, $t0, return_n # If n == 1, return n

  # Return fibonacci(n-1) + fibonacci(n-2)
  addi $a0, $a0, -1 # Calculate fibonacci(n-1)
  jal fibonacci
  sw $v0, 8($sp) # Push n-1 result

  lw $a0, 4($sp) # Load n

  addi $a0, $a0, -2 # Calculate fibonacci(n-2)
  jal fibonacci

  lw $t0, 8($sp) # Load n-1 result
  add $v0, $v0, $t0 # Add fibonacci(n-1) and fibonacci(n-2)

  # Restore registers and return
  end_function:
    lw $ra, 0($sp) # Restore return address
    addiu $sp, $sp, 12 # Deallocate stack space
    jr $ra # Return to caller

  # For base case, return n
  return_n:
    move $v0, $a0
    j end_function

# Ask the user for an int
prompt_int:
  # Ask the user for an int
  li $v0, 5 # Setup syscall to read int
  syscall # Syscall stores result in $v0
  jr $ra # Return to caller

# Print int
print_int:
  li $v0, 1 # Syscall code
  syscall
  jr $ra # Return to caller

# Print string
print_str:
  li $v0, 4 # Setup syscall to print string
  syscall
  jr $ra

.data
endl: .asciiz "\n"
p_fibonacci: .asciiz "Enter number for Fibonacci function: "
r_fibonacci: .asciiz "Result: "

.text
main:
  la $a0, p_fibonacci  # Load the address of p_fibonacci into $a0
  jal print_str # Print p_fibonacci

  jal prompt_int # Read n for fibonacci call
  move $a0, $v0 # Load input into $a0

  jal fibonacci # Call fibonacci with n
  move $s0, $v0 # Store result

  la $a0, r_fibonacci # Load the address of r_fibonacci into $a0
  jal print_str # Print r_fibonacci
  
  move $a0, $s0 # Move result into $a0
  jal print_int # Print fibonacci result

  jr $ra # Main finished

