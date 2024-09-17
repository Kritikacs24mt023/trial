#!/bin/bash

# Define the executable paths for single and double precision
TARGETS_SINGLE=("bin/matmul_single_jki" "bin/matmul_single_kij" "bin/matmul_single_kji")
TARGETS_DOUBLE=("bin/matmul_double_ijk" "bin/matmul_double_ikj" "bin/matmul_double_jik" "bin/matmul_double_jki" "bin/matmul_double_kij" "bin/matmul_double_kji")

# Input size for matrix multiplication
INPUT_SIZE=2048

# Function to run valgrind cachegrind on an array of targets
run_cachegrind() {
    local targets=("$@")
    local precision=$1
    shift  # Remove the first argument

    for target in "${targets[@]}"; do
        if [ -f "$target" ]; then
            echo "Running Valgrind Cachegrind on $target with $precision precision..."
            valgrind --tool=cachegrind --cache-sim=yes ./"$target" $INPUT_SIZE
            echo "Cachegrind run completed for $target."
        else
            echo "Executable $target not found!"
        fi
    done
}

# Run Cachegrind for single precision
echo "Running Valgrind Cachegrind for single precision targets..."
run_cachegrind "single" "${TARGETS_SINGLE[@]}"

# Run Cachegrind for double precision
echo "Running Valgrind Cachegrind for double precision targets..."
run_cachegrind "double" "${TARGETS_DOUBLE[@]}"

echo "Cachegrind analysis completed!"

