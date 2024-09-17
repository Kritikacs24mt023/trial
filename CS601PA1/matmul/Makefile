# Compiler and flags
CC = g++
CFLAGS = -g -std=c++17 # $(BLAS_INCLUDE)


# Paths for BLAS library and headers
# BLAS_INCLUDE = -I/home/CS601/blas/include
# BLAS_LIB = -L/home/CS601/blas/lib -lopenblas

# Flags for single and double precision
SINGLE_FLAGS = -DSINGLE
DOUBLE_FLAGS = -DDOUBLE

# Flags for different loop orders
LOOP_IJK = -DLOOP_ORDER_IJK
LOOP_IKJ = -DLOOP_ORDER_IKJ
LOOP_JIK = -DLOOP_ORDER_JIK
LOOP_JKI = -DLOOP_ORDER_JKI
LOOP_KIJ = -DLOOP_ORDER_KIJ
LOOP_KJI = -DLOOP_ORDER_KJI

# Targets for single and double precision
TARGETS_SINGLE = bin/matmul_single_ijk bin/matmul_single_ikj bin/matmul_single_jik bin/matmul_single_jki bin/matmul_single_kij bin/matmul_single_kji
TARGETS_DOUBLE = bin/matmul_double_ijk bin/matmul_double_ikj bin/matmul_double_jik bin/matmul_double_jki bin/matmul_double_kij bin/matmul_double_kji

# Target for BLAS usage
# TARGET_BLAS = bin/matmul_blas

# Default target to build everything
all: build_matmul_single build_matmul_double # build_matmul_blas

# Build single precision targets
build_matmul_single: $(TARGETS_SINGLE)

bin/matmul_single_ijk: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_IJK) -o $@ src/matmul.cpp

bin/matmul_single_ikj: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_IKJ) -o $@ src/matmul.cpp    

bin/matmul_single_jik: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_JIK) -o $@ src/matmul.cpp

bin/matmul_single_jki: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_JKI) -o $@ src/matmul.cpp

bin/matmul_single_kij: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_KIJ) -o $@ src/matmul.cpp

bin/matmul_single_kji: src/matmul.cpp
	$(CC) $(CFLAGS) $(SINGLE_FLAGS) $(LOOP_KJI) -o $@ src/matmul.cpp

# Build double precision targets
build_matmul_double: $(TARGETS_DOUBLE)

bin/matmul_double_ijk: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_IJK) -o $@ src/matmul.cpp

bin/matmul_double_ikj: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_IKJ) -o $@ src/matmul.cpp

bin/matmul_double_jik: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_JIK) -o $@ src/matmul.cpp

bin/matmul_double_jki: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_JKI) -o $@ src/matmul.cpp

bin/matmul_double_kij: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_KIJ) -o $@ src/matmul.cpp

bin/matmul_double_kji: src/matmul.cpp
	$(CC) $(CFLAGS) $(DOUBLE_FLAGS) $(LOOP_KJI) -o $@ src/matmul.cpp


# Build BLAS target
# build_matmul_blas: $(TARGET_BLAS)

# bin/matmul_blas: src/matmul.cpp
#	$(CC) $(CFLAGS) $(BLAS_INCLUDE) -DUSE_BLAS $(BLAS_LIB) -o $@ src/matmul.cpp

# Run targets for single precision
run_matmul_single: $(TARGETS_SINGLE)
	@for target in $(TARGETS_SINGLE); do \
                echo "Running $$target with single precision..."; \
                ./$$target 2048; \
        done

# Run targets for double precision
run_matmul_double: $(TARGETS_DOUBLE)
	@for target in $(TARGETS_DOUBLE); do \
                echo "Running $$target with double precision..."; \
                ./$$target 2048; \
        done

# Run target for BLAS
# run_matmul_blas: $(TARGET_BLAS)
#	@echo "Running BLAS-based matrix multiplication..."; \
        ./$(TARGET_BLAS) 2048;

# Clean up built files
clean:
	rm -f obj/*.o bin/*

.PHONY: all build_matmul_single build_matmul_double run_matmul_single run_matmul_double clean # run_matmul_blas

