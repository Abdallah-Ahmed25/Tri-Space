# Tri-space

## About the Project
Tri-space is a versatile desktop application developed using Qt, designed to serve as a centralized hub for three primary workspace functions: **Gaming, Study, and Events**. This application provides an interactive and user-friendly environment for users to engage in these activities efficiently.

### Features
- **Gaming Hub:** Users can access gaming-related content, play multiplayer games, and join game rooms.
- **Study Area:** A distraction-free digital space designed for students to access resources, work on assignments, and collaborate.
- **Event Space:** A dedicated section for organizing and attending events such as webinars, conferences, and meetings.

---

## Project Structure

### 1. **Login Page**
- A simple login interface with fields for username and password.
- Displays appropriate messages for successful and unsuccessful login attempts.

### 2. **Home Page**
- Acts as the central navigation hub for users.
- Provides access to the three main sections: **Gaming, Study, and Events**.

### 3. **Rooms Pages**
#### **Gaming Page**
- Displays available game rooms where users can join sessions.
- Shows active game details, including session duration, cost, and participant information.

#### **Study Page**
- Lists study rooms with available spots.
- Users can join and utilize resources for productive study sessions.

#### **Event Page**
- Displays event rooms for different activities.
- Users can participate in various event types such as **parties** and **meetings**.

### 4. **Detailed Room Pages**
#### **Gaming Room**
- Users can input details such as Name, Email, Number, Handle Name, Age, and Game Title.
- Invalid ID detection and auto ID generation features.

#### **Study Room**
- Displays key details like Name, Email, Study Type, and various room amenities such as lighting, drinks, snacks, and Wi-Fi.

#### **Event Room**
- Two categories: **Party** (with details like Party Type, Number of Invited Guests, Drinks, Music, and Food) and **Meeting** (with details like Number of Invited Guests, Wi-Fi availability, and Supplies).

---

## Technologies Used
- **Qt Framework** (C++)
- **Object-Oriented Programming (OOP) principles**
- **Graphical User Interface (GUI) development**

---

## Installation & Setup
1. Clone the repository:
   ```sh
   git clone https://github.com/Abdallah-Ahmed25/Tri-Space.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Tri-space
   ```
3. Open the project in Qt Creator.
4. Build and run the application.

---

## Running the Program Without Qt
If you want to run the program without installing or opening Qt Creator, follow these steps:
1. Navigate to the `.\build\Desktop_Qt_6_8_0_MinGW_64_bit-Release\release` folder inside the project directory.
2. Locate the `project_54.exe` file generated after building the project.
3. Double-click the `.exe` file to launch the application.
4. Ensure that all required dependencies (DLL files) are present in the same directory.
5. If you encounter missing DLL errors, copy the necessary Qt libraries from the Qt installation directory to the release folder or run this command on the terminal of this directory.
```sh
windeployqt project_54.exe
```

---

## Team Members
- [Abdallah Ahmed](https://github.com/Abdallah-Ahmed25)
- Amr Tamer
- Ibrahim Abdelmohsen Ibrahim
- Renad Hazem Said Ahmed
- Malak Omar

---