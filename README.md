# 🌐 QS Ranking Project 🌐

![image](https://github.com/user-attachments/assets/bc879a36-1426-4a00-8906-895f97717c39)


The **QS Ranking Project** is a C++ program designed to manage and sort a list of universities based on specific criteria such as name and rank. This project showcases sorting algorithms, user management, and a simple user interface, providing an interactive way to explore university rankings.

## 📚 Table of Contents
- [✨ Features](#-features)
- [🛠️ Installation](#️-installation)
- [🚀 Usage](#-usage)
- [🧩 Code Structure](#-code-structure)
- [👥 User Roles](#-user-roles)
- [🔍 Sorting Algorithms](#-sorting-algorithms)
- [🔮 Future Enhancements](#-future-enhancements)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)

## ✨ Features
- 🏫 **University Management:** Store and manage a list of universities with attributes like name and rank.
- 📊 **Sorting Algorithms:** Implement Bubble Sort and Insertion Sort to order universities by name or rank.
- 👥 **User Roles:** Manage different user roles (Admin and Registered Users) with role-based access control.
- 🖥️ **Console Interface:** Interact with the system using a simple text-based menu interface.

## 🛠️ Installation
To set up and run the project on your local machine, follow these steps:

### Using Visual Studio:
1. **Open Visual Studio** and create a new project.
2. **Import the source files** into the project.
3. **Build and Run** the project using Visual Studio's build tools.

### Using Command Line:
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/qs-ranking-project.git
   ```
2. **Navigate to the project directory:**
   ```bash
   cd qs-ranking-project
   ```
3. **Compile the project using a C++ compiler:**
   ```bash
   g++ -o QSRanking Main.cpp University.cpp UserInterface.cpp UserManager.cpp SortAndSearch.cpp BaseUser.cpp RegisteredUser.cpp AdminUser.cpp DataSeeder.cpp
   ```
4. **Run the executable:**
   ```bash
   ./QSRanking
   ```

## 🚀 Usage
1. Launch the program to access the main menu.
2. Choose to sort universities by name or rank using Bubble Sort or Insertion Sort.
3. View the sorted list of universities displayed in the console.
4. Admin users may have access to additional functionalities like adding or removing universities (if implemented).

## 🧩 Code Structure
- **Main.cpp:** Entry point of the program, handles initialization and user interface.
- **University.cpp & University.h:** Define the `University` class and its attributes.
- **SortAndSearch.cpp & SortAndSearch.h:** Implement sorting algorithms (Bubble Sort and Insertion Sort).
- **UserInterface.cpp & UserInterface.h:** Manage user interaction and menu display.
- **UserManager.cpp & UserManager.h:** Handle user authentication and role management.
- **BaseUser, RegisteredUser, AdminUser:** Define different user roles with varying permissions.
- **DataSeeder.cpp & DataSeeder.h:** Populate the initial list of universities for sorting and display.

## 👥 User Roles
- **Admin User:** 🛡️ Has full control over the system, including adding or removing universities.
- **Registered User:** 🔑 Can view and sort the list of universities.
- **Base User:** ⚙️ A base class for common user functionalities.

## 🔍 Sorting Algorithms
- **Bubble Sort:** Simple comparison-based algorithm with O(n^2) complexity. Suitable for small datasets.
- **Insertion Sort:** Builds the final sorted array one item at a time, with O(n^2) complexity in the average and worst case.

## 🔮 Future Enhancements
- 🚀 Implement more efficient sorting algorithms like Quick Sort or Merge Sort.
- 🎨 Develop a graphical user interface (GUI) for a more user-friendly experience.
- 🛡️ Add error handling and input validation to enhance system robustness.
- 📝 Implement additional user management features, such as registration and profile management.

## ScreenShots
<img width="298" alt="QS-6" src="https://github.com/user-attachments/assets/23776df5-e656-4f3a-b056-dd4cfb53df3f">
<img width="275" alt="QS-5" src="https://github.com/user-attachments/assets/0e77a4ba-7d64-4b07-8219-bf8b33a3e8e6">
<img width="238" alt="QS-4" src="https://github.com/user-attachments/assets/91ae63d7-aff2-437e-bf3e-d137d2d0d2e2">
<img width="272" alt="QS-3" src="https://github.com/user-attachments/assets/42d83795-2bc1-4884-954b-2e833e046a27">
<img width="250" alt="QS-2" src="https://github.com/user-attachments/assets/a25af537-eac6-4572-a54b-7834150a1559">
<img width="247" alt="QS-1" src="https://github.com/user-attachments/assets/3633e4e3-61e8-4195-ac96-4de829db327c">


## 🤝 Contributing
Contributions are welcome! Please fork the repository and create a pull request with your proposed changes.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🔍 SEO Keywords
- QS Ranking Project C++
- University Ranking Management System
- C++ Sorting Algorithms
- User Role Management in C++
- University Data Sorting Program

