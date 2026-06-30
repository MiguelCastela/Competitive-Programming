# Competitive Programming

Solutions and exercises from two closely related university courses, written
mostly in C++ with a few Python and Java files. The material is organized by
course lessons, contests, and assessments, alongside the original course
handouts.

The two courses covered are:

- Competitive Programming, organized into lessons, contests, and assessments.
- Estrategias Algoritmicas (Algorithmic Strategies), a related course with its
  own top-level folder holding the practice exercises and the two course
  projects.

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
├── estrategias-algoritmicas/  Algorithmic Strategies course
│   ├── exercises/      Practice problems
│   └── projects/       The two graded course projects
│       ├── prob1/          Battle for Piltover
│       └── prob2/          Piltover Towers
├── handouts/       Course PDFs (weekly problem statements)
└── README.md
```

Within each folder, single-letter files (`A.cpp`, `B.cpp`, ...) correspond to
individual problems from that set. An `input.txt` file, when present, holds
sample input used while testing. Files such as `A_bottom_up.cpp` are alternative
solutions to the same problem using a different approach.

## Naming conventions

- `aula` is the Portuguese word for "lesson" or "class".
- `freq` (frequencia) refers to a course assessment.
- `torneio` means "tournament" or "contest".
- Lesson folders are zero padded (`aula01`, `aula02`, ...) so they sort in order.

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
