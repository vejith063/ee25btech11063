import subprocess

# Compile the C code (line.c)
compile_process = subprocess.run(["gcc", "line.c", "-o", "line.out"])

# Check if compilation was successful
if compile_process.returncode == 0:
    print("Compilation successful. Running the program...\n")
    # Run the compiled program
    run_process = subprocess.run(["./line.out"])
else:
    print("Compilation failed.")

