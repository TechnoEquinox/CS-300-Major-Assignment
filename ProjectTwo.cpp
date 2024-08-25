// Connor Bailey
// Project Two
// Professor Adamo
// 18 August 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Define data for a Course
class Course {
public: 
    string courseNumber;
    string title;
    vector<string> prerequisites;

    // Default constructor
    Course() {}

    // Constructor
    Course(string courseNumber, string title, vector<string> prerequisites) {
        this->courseNumber = courseNumber;
        this->title = title;
        this->prerequisites = prerequisites;
    }
};

// Define data for a node in a BST
class TreeNode {
public:
    Course course;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(Course course) : course(course), left(nullptr), right(nullptr) {}
};

// Defines the BST
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper Functions
    void insert(TreeNode*& node, Course course) {
        if (node == nullptr) {
            // Base case
            node = new TreeNode(course);
        } else if (course.courseNumber < node->course.courseNumber) {
            // Traverse left
            insert(node->left, course);
        } else {
            // Traverse right
            insert(node->right, course);
        }
    }

    void inOrderTraversal(TreeNode* node) {
        // Base case
        if (node == nullptr) {
            return;
        }
        // LHS
        inOrderTraversal(node->left);
        // Print the node
        cout << node->course.courseNumber << ", " << node->course.title << endl;
        // RHS
        inOrderTraversal(node->right);
    }

    TreeNode* search(TreeNode* node, string courseNumber) {
        // Base case
        if (node == nullptr || node->course.courseNumber == courseNumber) {
            return node;
        }

        if (courseNumber < node->course.courseNumber) {
            // LHS
            return search(node->left, courseNumber);
        } else {
            // RHS
            return search(node->right, courseNumber);
        }
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(Course course) {
        insert(root, course);
    }

    void printAlphanumericCourseList() {
        inOrderTraversal(root);
    }

    void printCourseInformation(string courseNumber) {
        TreeNode* node = search(root, courseNumber);
        if (node != nullptr) {
            cout << "Course Number: " << node->course.courseNumber << endl;
            cout << "Course Title: " << node->course.title << endl;
            cout << "Prerequisites: ";

            if (node->course.prerequisites.empty()) {
                // No prereqs exist for this class
                cout << "NONE" << endl;
            } else {
                // Prereqs exist for this class
                for (size_t i = 0; i < node->course.prerequisites.size(); i++) {
                    cout << node->course.prerequisites[i] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Course not found." << endl; 
        }
    }
};

// Load the course file and extract the data
void loadCourseFile(string fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening the file: " << fileName << endl;
        return;
    }

    string currentLine;
    // Loop over each line
    while(getline(file, currentLine)) {
        string courseNumber;
        string title;
        string prereq;
        vector<string> prerequisites;
        stringstream ss(currentLine);

        getline(ss, courseNumber, ',');
        getline(ss, title, ',');

        // Loop over each prerequisit 
        while(getline(ss, prereq, ',')) {
            prerequisites.push_back(prereq);
        }

        Course course(courseNumber, title, prerequisites);
        bst.insert(course);
    }
    file.close();
    cout << "Successfully loaded data from " << fileName << endl;
}

void displayMenu() {
    cout << "Main Menu:" << endl;
    cout << "1. Load course data" << endl;
    cout << "2. Print alphanumeric list of all courses" << endl;
    cout << "3. Print course information and prerequisites" << endl;
    cout << "9. Exit" << endl;
}

void handleMenuOption(int option, BinarySearchTree& bst) {
    switch (option) {
        case 1: {
            string fileName;
            cout << "Enter the file name to load course data: ";
            cin >> fileName;
            loadCourseFile(fileName, bst);
            break;
        }
        case 2:
            // Print the course list
            cout << "Printing course list in alphanumeric order..." << endl;
            bst.printAlphanumericCourseList();
            break;
        case 3: {
            string courseNumber;
            cout << "Enter course number: ";
            cin >> courseNumber;
            bst.printCourseInformation(courseNumber);
            break;
        }
        case 9:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
    }
}

int main() {
    BinarySearchTree bst;
    int option = 0;

    // Enter the loop for the menu
    while (option != 9) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        // Basic input validation
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Get rid of the invalid input
            cout << "Invalid input. Please try again." << endl;
            continue;
        }
        handleMenuOption(option, bst);
    }
    return 0;
}