# **LIBRARY MANAGEMENT SYSTEM (C Programming)**
##📄 **ABSTRACT**

The **Library Management System** is a terminal-based **C** application designed to efficiently manage library book records.
It provides essential operations such as **adding**, **viewing**, **searching**, **updating**, and deleting books from the library database.

All records are stored permanently in a binary file (`library.dat`) to ensure that data is preserved across multiple program runs.

This project demonstrates core C programming concepts including **structures**, **file handling**, **conditional logic**, **loops**, **menus**, and **modular programming**, making it ideal for **beginners**, **academic assignments**, and **practical C learning**.
---
## ✨ **FEATURES**
### **Core Functionalities**

-➕** Add new book records** (Book ID, Title, Author, Quantity)
-📋 **Display all books** in a neat table format
-🔍**Search a book using unique Book ID**
-✏️ **Update existing book details**
-❌ **Delete book records permanently**
-💾 Persistent binary file storage (library.dat)
-🖥️ Fully terminal-based, menu-driven system
-👨‍💻 Beginner-friendly modular C code
-⚙️ Auto-creates data file if missing
-⚠️ Includes basic input validation and error handling
---
## 🛠️ **TECHNICAL REQUIREMENTS**
### **System Requirements**
-Operating System: **Windows / Linux / macOS**
-Terminal / Command Prompt
-At least **4 MB RAM**
-Minimal disk space for `library.dat`

### **Software Requirements**

-C Compiler: **GCC / MinGW / Clang / MSVC**
-Code Editor/IDE: VS Code, Code::Blocks, Dev-C++, etc.
-(Optional): **Make utility** for Makefile

### **Programming Requirements**
-Language: **C**
-Supported Standards: **C89 / C99 / C11**
-Required header files:
- `stdio.h`
- `stdlib.h`
- `string.h`

### **File Handling**

-Binary file read/write access
-Records stored in library.dat
-File automatically created if absent
---
## 📌 **FUNCTIONAL REQUIREMENTS**
### **User Interface**

-Clean, menu-driven terminal interface
-Validates user inputs
-Displays clear success/error messages
---
## 📚 **Library Operations**
## ➕ **Add Book**

-Enter Book ID, Title, Author, Quantity
-Saves data into `library.dat`

### 📋 **Display Books**
-Shows all stored book records in a formatted table

### 🔍 **Search Book**
-Search using unique Book ID

### ✏️ **Update Book**
-Modify Title, Author, Quantity, etc.

### ❌ **Delete Book**
-Permanently removes a book using a temporary-file technique

### 🔧**DATA MANAGEMENT**
-Binary file storage → fast, efficient access
-Safe update & delete using temporary files
-Handles empty or missing file smoothly

### 🔄 **PROGRAM FLOW**
-Menu runs inside a **loop**
-Clear options for each operation
-Graceful exit included
---
### ▶️ **Running the Program**
### 1️⃣ **Compile**
```bash
gcc library.c -o library
````
### 2️⃣ Run
**Linux / macOS**
```bash
./library
```
**Windows**
```bash
library.exe
````
### 3️⃣ Data File
*Automatically creates `library.dat`
*Stores all book records in binary format
---
## 📸 **Screenshots (Optional)**
*Add Book

*<img width="428" height="376" alt="Screenshot 2025-11-26 142147" src="https://github.com/user-attachments/assets/0d8476df-feeb-4ae8-acf8-06a66508b89d" />

*Display all books

*<img width="375" height="665" alt="Screenshot 2025-11-26 142227" src="https://github.com/user-attachments/assets/64e16480-530e-4b56-ad01-71af63a5faef" />

*Search book by ID

*<img width="367" height="409" alt="Screenshot 2025-11-26 142256" src="https://github.com/user-attachments/assets/be89a610-fe4a-408c-858f-04610bc45b6a" />

*Search book by author

*<img width="380" height="451" alt="Screenshot 2025-11-26 142319" src="https://github.com/user-attachments/assets/8661c383-ff89-447a-b7d0-6a0922697383" />

*Delete book

*<img width="404" height="313" alt="Screenshot 2025-11-26 142344" src="https://github.com/user-attachments/assets/9397edf4-6fae-4dec-83ad-3c434f0c2360" />

*Update book

*<img width="435" height="418" alt="Screenshot 2025-11-26 142406" src="https://github.com/user-attachments/assets/6d6fa8a0-38cd-442f-b0bb-d0578ee76760" />

*Exit

*
---
## **Author**
**M.Santhosh**
