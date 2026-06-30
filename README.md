# Competitive Programming

Solutions and exercises from a competitive programming course, written mostly in
C++ with a few Python scripts. The material is organized by course lessons,
contests, and assessments, alongside the original course handouts.

## Repository structure

```
.
├── lessons/        Exercises worked through in each class (aula)
│   ├── aula01/         Introductory problems (and the PL practical set)
│   ├── aula02/
│   ├── ...
│   ├── aula05-06/      Dynamic programming (top-down and bottom-up variants)
│   └── aula13/
├── contests/       Contest problem sets
│   └── torneio09/
├── assessments/    Graded and practice assessments
│   ├── freq/           Assessment problems
│   └── freq-treino/    Practice assessments
│       ├── freq2024-final/
│       └── freq2025/
├── handouts/       Course PDFs (weekly problem statements)
└── README.md
```

Within each folder, single-letter files (`A.cpp`, `B.cpp`, ...) correspond to
individual problems from that set. An `input.txt` file, when present, holds
sample input used while testing. Files such as `A_bottom_up.cpp` are alternative
solutions to the same problem using a different approach.


## Building and running

Most solutions are single self-contained C++ files. Compile and run a problem
with `g++`:

```sh
g++ -std=c++17 -O2 -o solution lessons/aula03/A.cpp
./solution < lessons/aula03/input.txt
```

Python solutions run directly:

```sh
python3 lessons/aula03/E.py
```

Compiled binaries are intentionally not tracked in git (see `.gitignore`), so
each solution is built locally before running.

## Notes

This is a personal learning archive. Solutions reflect the approach taken at the
time of each lesson and are not necessarily the most optimized version of each
problem.
