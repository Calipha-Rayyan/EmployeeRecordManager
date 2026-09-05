# EmployeeRecordManager

A C++ console-based **Employee Record Management System** designed to demonstrate fundamental programming concepts through an interactive menu-driven application.

The system allows users to manage employee records containing a name and ID. Records can be added, displayed, searched, sorted, modified, and deleted directly from the console.

## Features

* Add employee records
* Display employee records
* Search records by name
* Search records by ID
* Sort records by name
* Sort records by ID
* Delete records by name
* Delete records by ID
* Modify records by name
* Modify records by ID
* Interactive console menu
* Windows console cursor positioning
* Basic invalid-option handling

The program defines an `employee` structure containing a name and ID and stores up to 50 employee records in memory.

## Menu

The application provides the following options:

```text
A - Add Record
O - Sort All Records
S - Search for a Record
D - Display Records
T - Delete / Undelete
M - Update Record
Q - Quit
```

The menu is implemented as an interactive command-line interface and accepts both uppercase and lowercase commands.

## Operations

### Add Records

Users can enter an employee name and ID and continue adding records until they choose to stop.

### Search Records

Records can be searched using either:

* Employee Name
* Employee ID

The program compares the entered value against stored records and reports whether a matching record is found.

### Sort Records

Employee records can be sorted using:

* Name
* ID

The implementation uses a comparison-based sorting approach to reorder the records.

### Delete Records

Records can be deleted by either employee name or employee ID. When a record is removed, subsequent records are shifted to fill its position.

### Modify Records

Existing records can be updated by searching for an employee using either name or ID and then entering the new information.

## Technologies Used

* **Language:** C++
* **Application Type:** Console Application
* **Platform:** Windows
* **Standard Libraries:** `iostream`, `iomanip`, `cstring`, `cstdlib`
* **Windows APIs:** `conio.h`, `windows.h`

The project uses Windows-specific functions such as `getch()`, `getche()`, `system("cls")`, and `SetConsoleCursorPosition()`.

## Project Structure

```text
EmployeeRecordManager/
│
├── EmployeeRecordManager.cpp
├── README.md
└── .gitignore
```

## Requirements

Because the application uses Windows-specific headers and console APIs, it is intended to run on **Windows**.

Recommended compilers:

* Microsoft Visual C++
* MinGW G++
* Visual Studio

## Compilation

Using MinGW G++:

```bash
g++ -std=c++17 EmployeeRecordManager.cpp -o EmployeeRecordManager
```

## Run

```bash
EmployeeRecordManager.exe
```

## Example Workflow

```text
------------- 
| MAIN MENU |
-------------

Please choose one of the options below:

(A) add record
(O) sort all records
(S) search for a record
(D) display a record
(T) delete / undelete
(M) update record
(Q) Quit
```

The user selects an operation and interacts with the system through the console.

## Data Model

Each employee record contains:

```cpp
struct employee
{
    char name[40];
    int id;
};
```

The current implementation stores employee records in a fixed-size array:

```cpp
employee emp[50];
```

## Concepts Demonstrated

This project demonstrates several important C++ programming concepts:

* Structures
* Arrays
* Functions
* Function parameters
* Loops
* Conditional statements
* String manipulation
* Searching
* Sorting
* Record modification
* Record deletion
* Console input/output
* Windows console APIs

## Limitations

This is an educational console application rather than a production database system.

Current limitations include:

* Maximum of 50 employee records
* Data is stored only in memory
* Records are lost when the program exits
* Uses fixed-size character arrays
* Windows-specific dependencies
* No persistent database or file-based storage
* Limited validation of employee input

The fixed record capacity is defined directly in the global array declaration.

## Future Improvements

Potential improvements include:

* Store records using `std::vector`
* Replace character arrays with `std::string`
* Add file/database persistence
* Add employee uniqueness validation
* Improve input validation
* Add confirmation before deletion
* Add a proper undelete/recovery mechanism
* Separate the project into header and implementation files
* Add automated tests
* Remove Windows-only dependencies for cross-platform support

## Educational Purpose

This project is intended to practice basic C++ programming and data-management concepts through a practical employee-record application.

## Author

**Muhammad Rayyan Bhatti**

GitHub: [Calipha-Rayyan](https://github.com/Calipha-Rayyan)

## License

This project is intended for educational and personal use.
