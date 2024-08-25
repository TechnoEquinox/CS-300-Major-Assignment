# CS-300-Major-Assignment

This repo was the major assignment for my CS 300: Data Structures and Algorithms at Southern New Hampshire University. This project was completed in C++ and included a runtime analysis in Big(O) notation.

## Evaluation and Analysis

### Analysis of Reading and Parsing the data file

| Code  | Line Cost | Number of Times Executed | Total Cost |
| ------------- | ------------- | ------------- | ------------- |
| open file | 1 | 1 | 1 |
| If the file is not open | 1 | 1 | 1 |
| For each line in the file | 1 | n | n |
| Split the line by commas | 1 | n | n |
| If the number of components < 2 | 1 | n | n |
| If course number is not correct | 1 | n | n |
| If course title is empty | 1 | n | n |
| Create a course object | O(1) | n | n |
| Add the course to the data structure | O(1) | n | n |
| Close the file | 1 | 1 | 1 |
| Total Cost | | | 7n + 3 |
| Run Time | | | O(n) |

### Creating Course Objects

| Code  | Line Cost | Number of Times Executed | Total Cost |
| ------------- | ------------- | ------------- | ------------- |
| Get course number | 1 | 1 | 1 |
| Get course title | 1 | 1 | 1 |
| Initialize prerequisite list | 1 | 1 | 1 |
| If there are prerequisites | 1 | 1 | 1 |
| Add each prerequisite | 1 | p | p |
| Return course object | 1 | 1 | 1 |
| Total Cost | | | p + 5 |
| Run Time | | | O(p) |

### Data Structure Analysis

#### Vector
The primary advantage of the vector data structure is its simplicity and ease of use when storing and iterating through data. Vectors allow for direct access to elements within them via traditional indices which make then great for traversing and sorting, however this also requires manually sorting the data. We can see this in the O(n^2) complexity of the selection sort we implemented. As the number of courses (n) increase, we can expect the runtime to increase.

#### Hash Tables
Hash tables excel in providing fast look ups, insertions, and deletions because the data is not stored with indices, but rather is distributed across the table via a hash function. Normally we would expect O(1) time complexity when accessing the hash table, however, because they do not maintain any kind of order and the data is spread quasi randomly, a hash table cannot be sorted. The only way to sort data in a hash table is to extract the data into a data structure that is capable of maintaining order (i.e. Vector) and then sort the data. While we are accessing the data incredibly fast, we are inevitably bottlenecked by the time complexity of the data structure and the sorting algorithm we load the data into. 

#### Binary Search Tree (BST)
Binary Search Trees (BSTs) inherently maintains its elements in sorted order, allowing very efficient in order traversal to retrieve courses in order with a time complexity of O(log n). This data structure removes the need for additional sorting algorithms which in this application is incredibly advantageous. However, there is additional complexity in ensuring that the BST is kept balanced. Should a BST become unbalanced, the time complexity would change from O(log n) to O(n) in the worst case. 

#### Recommended Data Structure for this Project
Based on this analysis, I believe using a Binary Search Tree is best for this application. The BST’s ability to maintain a sorted order makes them ideal for the advisor’s requirements because these task will require frequent retrieval and printing of courses in alphanumeric order. 








