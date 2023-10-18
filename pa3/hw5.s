.text
# Calculate Fibonacci number
fibonacci:
    # Prepare the stack and save necessary registers
    addiu $sp, $sp, -32 # Allocate stack space for this frame
    sw $ra, 28($sp) # Save return address
    sw $fp, 24($sp) # Save previous frame pointer
    sw $s0, 20($sp) # Save $s0 (used for n value)
    sw $s1, 16($sp) # Save $s1 (used for intermediate calculations)
    move $fp, $sp # Update frame pointer
    move $s0, $a0 # Move argument (n) to $s0 for convenience

    # If n <= 1, return n
    blez $s0, return_n # If n <= 0, return n
    li $t0, 1 # Load 1 into $t0
    ble $s0, $t0, return_n # If n == 1, return n

    # Return fibonacci(n-1) + fibonacci(n-2)
    addi $a0, $s0, -1 # Calculate fibonacci(n-1)
    jal fibonacci
    move $s1, $v0 # Store the result in $s1
    addi $a0, $s0, -2 # Calculate fibonacci(n-2)
    jal fibonacci
    add $v0, $v0, $s1 # Add fibonacci(n-1) and fibonacci(n-2)

    # Restore registers and return
    end_function:
      lw $s0, 20($sp) # Restore $s0
      lw $s1, 16($sp) # Restore $s1
      lw $fp, 24($sp) # Restore previous frame pointer
      lw $ra, 28($sp) # Restore return address
      addiu $sp, $sp, 32 # Deallocate stack space
      jr $ra # Return to caller

    # For base case, return n
    return_n:
      move $v0, $s0
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
  la $a0, r_fibonacci # Load the address of r_fibonacci into $a0
  jal print_str # Print r_fibonacci
  move $a0, $v0 # Move result into $a0
  jal print_int # Print fibonacci result

  jr $ra # Main finished

