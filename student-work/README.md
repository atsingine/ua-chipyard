# All the necessary dependencies and files are brought to this directory

## MATLAB Model source code is in
- `student-work/models/matlab_model`

## RISC Baseline path
- `student-work/models/software_imp`
- types and complex function defined in
    - complex.h
- test programs are
    - `complex_vector_add_test.c`
    - `complex_vector_mul_test.c`
    - `complex_vector_arithematic.c`: scalar add and mul test; DON'T USE THIS
    - `complex_arithmetic_type.c`: scalar add and mul test using type defined in complex.h; USE THIS PROGRAM

## CMakee Build Commands and Instructions
### Vector Add
``` PowerShell
cmake -S ./ -B ./build -DTEST_SELECT=vector_add
cmake --build ./build/ --target-all
```

### Vector MUL
``` PowerShell
cmake -S ./ -B ./build/ -DTEST_SELECT=vector_add
cmake --build ./build/ --target-all
```

### Simple complex arithmetic and function check
This function needs update
``` PowerShell
cmake -S ./ -B ./build/ -DTEST_SELECT=complex_arith
cmake --build ./build/ --target-all
```

### Clean target
``` PowerShell
cmake --build ./build/ --target-clean
```

### Executable is produced in ./build_riscv dir
To run executable, example for add:

`/workspace/chipyard/sims/verilator/simulator-chipyard.harness-BaselineConfig/workspace/student-work/build/cmplx_v_add.riscv`