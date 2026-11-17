#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct{
    int32_t packedComplex;
}complex_t;

static inline complex_t makeComplex(int16_t realN, int16_t imgN){
    complex_t complexN;
    complexN.packedComplex = (int32_t)(realN << 16) | (int32_t) (imgN & 0xFFFF);
    printf("Packed complex is : 0x%8x\n", complexN.packedComplex);
    return complexN;
}

void unPackComplex(complex_t z){
    int16_t real = (int16_t)((int32_t) z.packedComplex >> 16);
    int16_t img = (int16_t)(z.packedComplex & 0xFFFF);
    printf("Unpacked Real in Decimal : %d \t in HEX : 0x%4x\n", real, real);
    printf("Unpacked Imaginary in Decimal : %d \t in HEX : 0x%4x\n", img, img);

    printf("Unpacked Real : 0x%4x\n", z.packedComplex >> 16);
    printf("Unpacked Imaginary : 0x%4x\n", (int16_t)(z.packedComplex & 0xFFFF));
    return z.packedComplex;
}

static inline int16_t getReal(complex_t z){
    return (int16_t)(z.packedComplex >> 16);
}

static inline int16_t getImaginary(complex_t z){
    return (int16_t)(z.packedComplex & 0xFFFF);
}

// z = z1 + z2 = (a+c) + (b+d)i
complex_t cAdd(complex_t z1, complex_t z2){
    int16_t z1Real = getReal(z1);
    int16_t z2Real = getReal(z2);

    int16_t z1Imag = getImaginary(z1);
    int16_t z2Imag = getImaginary(z2);

    int16_t realResult = (z1Real + z2Real) & 0xFFFF;
    int16_t imagResult = (z1Imag + z2Imag) & 0xFFFF;
    
    complex_t addResult = makeComplex(realResult, imagResult);
    return addResult;
}

void cVectAdd(complex_t z1[], complex_t z2[], complex_t result[], int size){
    for(int i = 0; i < size; i++){
        result[i] = cAdd(z1[i], z2[i]);
        printf("realResult[%d] : %d \t imagResult[%d] : %d\n", i, getReal(result[i]), i, getImaginary(result[i]));
    }
}

complex_t cMul(complex_t z1, complex_t z2){
    int16_t z1Real = getReal(z1);
    int16_t z2Real = getReal(z2);
    int16_t z1Imag = getImaginary(z1);
    int16_t z2Imag = getImaginary(z2);

    int16_t realResult = (z1Real * z2Real) - (z1Imag*z2Imag);
    int16_t imagResult = (z1Real * z2Imag) + (z1Imag*z2Real);
    complex_t cMulResult = makeComplex(realResult, imagResult);
    return cMulResult;
}

void cVectMul(complex_t z1[], complex_t z2[], complex_t result[], int size){
    for(int i = 0; i < size; i++){
        result[i] = cMul(z1[i], z2[i]);
        printf("realResult[%d] : %d \t imagResult[%d] : %d\n", i, getReal(result[i]), i, getImaginary(result[i]));
    }
}

void printComplexForm(complex_t z){
    int16_t real = getReal(z);
    int16_t img = getImaginary(z);

    if(real >= 0 && img >= 0){
        printf("\t Falls in 1st Quadrant -> Complex number : %d + %dj\n", real, img);
    }
    else if(real < 0 && img >= 0){
        printf("\t Falls in 2nd Quadrant -> Complex number : %d + %dj\n", real, img);
    }
    else if(real < 0 && img < 0){
        printf("\t Falls in 3rd Quadrant -> Complex number : %d + %dj\n", real, img);
    }
    else{
        printf("\t Falls in 4th Quadrant -> Complex number : %d + %dj\n", real, img);
    }
}

void printComplexVector(complex_t z[], int size){
    for(int i = 0; i < size; i++){
        printf("z[%d]", i);
        printComplexForm(z[i]);
    }
}

#endif