# Data Structures Labs

Solutions and practice programs for the third-semester Data Structures laboratory course.

## Repository layout

```text
Labs/
├── Lab 1/    # introductory array/list activities and tasks
├── Lab 2/    # structures and related tasks
└── Lab 3/    # linked-list operations and tasks
```

Each lab directory contains standalone C++ (`.cpp`) programs. Compile and run the file for the task you want to practice.

## Build and run

Use any C++ compiler with C++17 support. The commands below work in PowerShell, Command Prompt, Fedora, and most Linux shells once `g++` is installed.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic "Lab 1/Activity.cpp" -o activity
./activity
```

On Windows PowerShell, run the generated program as:

```powershell
.\activity.exe
```

On Fedora, install the GNU C++ compiler if needed:

```bash
sudo dnf install gcc-c++
```

## Version-control notes

Source files and useful lab material belong in Git. Generated executables, object files, editor settings, and temporary Code Runner files are intentionally excluded via `.gitignore`, so the repository remains clean on both Windows and Linux.

