# Student-Record-Manager# Student Record Manager (C)

A beginner-friendly, menu-driven Student Record Management System developed using the C programming language.

This project allows users to add student records, display saved records, search for students using roll numbers, and identify the student with the highest marks.

## Features

- **Add Student:** Enter a student's name, roll number, and marks.
- **Display Students:** View all saved student records.
- **Search Student:** Find a student using their roll number.
- **Find Topper:** Identify the student with the highest marks.
- **File Storage:** Save records in a text file so they remain available after the program exits.
- **Duplicate Prevention:** Prevent adding another record with an existing roll number.

## Concepts Used

This project demonstrates the following C programming concepts:

- Structures (`struct`)
- User-defined functions
- Pointers and file pointers
- File handling (`fopen`, `fprintf`, `fscanf`, `fclose`)
- Loops (`while`)
- Conditional statements (`if-else`)
- Switch-case statements
- Input validation
- Basic data searching

## Project Structure

```text
Student-Record-Manager/
├── main.c
├── README.md
└── .gitignore
```

The `records.txt` file is automatically created when the first student record is added. It is not included in the GitHub repository.

## How to Compile and Run

You need a C compiler such as GCC.

**1. Clone the repository**

```bash
git clone YOUR_REPOSITORY_URL
```

**2. Open the project directory**

```bash
cd Student-Record-Manager
```

**3. Compile the program**

```bash
gcc main.c -o student_manager
```

**4. Run the program**

On Windows:

```bash
student_manager.exe
```

On Linux/macOS:

```bash
./student_manager
```

## Example Test Cases

| Test | Input / Action | Expected Result |
|---|---|---|
| Add student | Rahul 101 85 | Student record is saved |
| Display records | Select option 2 | All saved records are displayed |
| Search student | Enter roll number 101 | Rahul's details are displayed |
| Find topper | Select option 4 | Student with the highest marks is displayed |
| Duplicate roll | Add another student with roll 101 | Duplicate record is rejected |
| Search missing student | Enter an unknown roll number | No student found message |

## Current Limitations

- Student names are currently limited to single words.
- Records are stored in a plain-text file.
- The program does not currently support editing or deleting student records.

## Future Improvements

- Support full names containing spaces.
- Add options to update and delete student records.
- Improve input validation.
- Organize the project into multiple source and header files.

---

**Author:** Your Name  
**Language:** C  
**Project Type:** Beginner C Programming Project.
