Project Description: Convex Hull Using Jarvis March Algorithm (Gift Wrapping)
This C program implements the Jarvis March algorithm (also known as the Gift Wrapping algorithm) to compute the convex hull of a set of 2D points.

🧠 What is a Convex Hull?
In computational geometry, the convex hull of a set of points is the smallest convex polygon that contains all the points. Imagine stretching a rubber band around the outermost points — the shape it forms is the convex hull.

📌 How the Algorithm Works
1. Random Point Generation
The program starts by generating RANDOM (1000) random 2D points and saves them in a file called file.txt.

2. Reading Input
The program reads the generated points from the file and stores them in an array of structs.

3. Finding the Convex Hull
The Jarvis March algorithm is used to compute the convex hull:

Start from the topmost left point (guaranteed to be part of the hull).

At each step, choose the point that is most counterclockwise to the current point (using the orientation function).

Repeat until you return to the starting point.

Save the hull points in convext.txt.

⚙️ Key Functions
orientation(p, q, r)
Determines if the triplet of points (p, q, r) are collinear, clockwise, or counterclockwise.
Time Complexity: O(1)

convexHull(points[], n)
Main function that builds the convex hull using Jarvis March.
Time Complexity: O(n * h), where:

n = number of points

h = number of points on the hull

📁 File Descriptions
File	Purpose
file.txt	Contains randomly generated 2D points
convext.txt	Output file with the number of convex hull points and their coordinates
main.c	Main code file implementing the algorithm

🧪 Output
All generated points are printed to the console.

Convex hull points are printed and saved.

The number of points on the convex hull is displayed.
