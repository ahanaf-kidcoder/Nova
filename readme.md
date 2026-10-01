# mrtx - Matrix Library in C++

A header-only matrix library written from scratch in C++17.
Supports `std::complex<double>` for real and complex matrices. Made for linear algebra, quantum computing, and machine learning.

## Features
- **Complex Support**: Uses `std::complex<double>` for quantum/engineering use
- **Core Ops**: Addition, Substraction, Multiplication, Identity matrix, Scaler multiplication
- **Advanced**: Kronecker/Tensor Product, Conjugate, Traspose, Dagger, Ifunitary
- **Utils**: Zero matrix, Pretty print, Dynamic sizing, Operators overloading
- **Header-Only**: Just include `mrtx.hpp` and go

## Quick Start

### Include
```cpp
#include "mrtx.hpp"
