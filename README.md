# Competitive Programming

Solutions and exercises from two closely related university courses, written
mostly in C++ with a few Python and Java files. The material is organized by
course lessons, contests, and assessments, alongside the original course
handouts.

The two courses covered are:

- Competitive Programming (3 ECTS extra course), organized into lessons, contests, and assessments.
- Estrategias Algoritmicas (third year), a related course with its
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

## Course projects

The two graded projects from the Algorithmic Strategies course live under
`estrategias-algoritmicas/projects/`. Each folder keeps its problem statement
(PDF) next to the solution.

### prob1 - Battle for Piltover

Objective: given a city grid of empty cells, walls, and outposts, place the
minimum number of turrets so that every empty cell is covered by at least one
turret, each outpost has exactly its requested number of turrets placed in the
orthogonally adjacent cells, and no two turrets share a line of sight (turrets
fire along rows and columns until blocked by a wall or an outpost). If no valid
placement exists, the answer is "noxus will rise!".

Solution: the cells are modelled as empty, wall, or outpost objects. The solver
first satisfies the hard constraints by placing the turrets forced around each
outpost, rejecting any board where an outpost cannot meet its exact count. It
then fills the remaining uncovered empty cells with turrets, checking the four
directions each time so that the no-mutual-line-of-sight rule is never broken,
and reports failure if any cell stays uncovered. To keep the search tractable, a
flood fill first splits the grid into independent regions (groups of cells
reachable from one another without crossing a wall) and copies each into its own
minimal bounding subgrid, so the placement is solved on the small pieces
separately rather than on the whole board at once.

### prob2 - Piltover Towers

Objective: given a weighted graph of towers (nodes) and connections (edges),
find a tree that links a given set of mandatory towers while minimising the
largest edge cost used (a minimum bottleneck connection). Optional towers may be
used as intermediate steps. If the mandatory towers cannot all be connected, the
answer is "Impossible to connect!".

Solution: binary search on the maximum allowed edge cost. For each candidate
threshold, a Disjoint Set Union (union-find) joins only the edges whose cost is
at most the threshold and checks whether all mandatory towers fall in the same
component. The search converges on the smallest threshold that keeps them
connected, which is the minimum possible bottleneck edge.

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
