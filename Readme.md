# Evaluation of Energy Consumption in Matrix Computations Using Compressed Data

This repository contains the C source codes used to assess the energy consumption of various compressors, as detailed in the paper "nrj_v1.pdf".

## Elementary Operations
The directory "elementaryOperations" contains C codes implementing elementary matrix computations, such as dot product, addition, multiplication by a matrix, and multiplication by a constant. The following files are available:

- `blaz.c`: Code for blaz compression.
- `zfp.c`: Code for zfp compression.
- `noCompression.c`: Code for uncompressed operations.

## Sequence of Operations
In the "chainedOps" directory, you can find C codes that combine multiple operations. The files provided are as follows:

- `additionsBlaz.c`: Energy consumption evaluation for a sequence of addition operations using blaz compression.
- `additionsZfp.c`: Energy consumption evaluation for a sequence of addition operations using zfp compression.
- `additionsNoCompression.c`: Energy consumption evaluation for a sequence of addition operations without compression.
- `addmulBlaz.c`: Energy consumption evaluation for a sequence of combined addition and multiplication operations using blaz compression.
- `addmulZfp.c`: Energy consumption evaluation for a sequence of combined addition and multiplication operations using zfp compression.
- `addmulNoCompression.c`: Energy consumption evaluation for a sequence of combined addition and multiplication operations without compression.

## Compute Player's Average Heatmap
The "heatmap" folder contains the C code used to measure the energy consumption of computing the average heatmap for the last 10 matches. The matches are represented as 1048x680 matrices.

## Energy Usage Data
Energy consumption measurements are stored in ODS (OpenDocument Spreadsheet) files, providing data for several measures. The corresponding TXT files summarize the average and error for each compressor in the following categories:

Elementary Operations:
- `energyAddition_per_N_Values`: Addition.
- `energyMultiplication_per_N_Values`: Multiplication.
- `energyDot_per_N_Values`: Dot Product.
- `energyMultiplyByC_per_N_Values`: Multiplication by constant.

Sequence of Operations:
- `energyChainedAdditions_per_N`: Additions Only.
- `energyChainedAdditionsMultiplication_per_N`: Addition and multiplication operations.

Average Heatmap:
- `energyAverageHeatmap`: Compute average heatmap.

## Matrix Data
The data used to evaluate Blaz Matrices can be found in the "libraries/blaz-master/data/" directory.
