#!/bin/bash

echo "=== Started the Unit testing ==="

# Run tests
cmake -S . -B build
cmake --build build
echo "===== Running Tests ====="
cd build && ctest --output-on-failure

echo "=== Unit testing ended gracefully ==="