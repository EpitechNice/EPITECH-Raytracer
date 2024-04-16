#!/bin/bash

echo "=== Started the Unit testing ==="

# Run tests
mkdir ./build/
cd ./build/
cmake ..
cmake --build .
echo "===== Running Tests ====="
ctest --output-on-failure || exit 1

echo "=== Unit testing ended gracefully ==="