@echo off
cl /EHsc /Ox /openmp /DOMP_NESTED=1 /Iinclude %* /link /MACHINE:X64 /OPT:REF /OPT:ICF