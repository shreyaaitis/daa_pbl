#Problem Statement
Given a list of cities and the distances between each pair, find the most efficient route that visits each city exactly once and returns to the starting point. The goal is to minimize the total travel distance or cost.

Techniques to Solve TSP
Brute Force:

Generate all possible permutations of cities and calculate the total distance for each route.
This guarantees the optimal solution but has a time complexity of 
𝑂
(
𝑁
!
)
O(N!), making it impractical for large datasets.
Greedy Algorithm:

At each step, select the nearest unvisited city.
Though faster than brute force, this method does not guarantee an optimal solution.
Dynamic Programming (Held-Karp Algorithm):

Uses memoization to store intermediate results and reduce redundant calculations.
Time complexity: 
𝑂
(
𝑁
2
⋅
2
𝑁
)
O(N 
2
 ⋅2 
N
 ), making it feasible for moderate-sized problems but still computationally expensive for large instances.
Backtracking with Recursion:

Recursively explore all possible routes while pruning paths that cannot lead to an optimal solution.
Efficient for smaller instances of TSP, as it explores the search space systematically and guarantees an optimal solution.
Approach Used in This Project
In this project, we use Backtracking with Recursion to solve the TSP. The algorithm systematically explores all possible routes by recursively placing cities in the current path and backtracking when a route exceeds the current best known distance.

Key Features
Optimal Solution: Guarantees the optimal solution by exploring all possible configurations.
Efficient Exploration: Prunes unpromising paths early to save computational time.
Recursive Approach: Uses recursion to explore and backtrack, ensuring all possible routes are tested.
Visualizing the Solution
This project includes a graphical visualization of the TSP solution, which helps in understanding how the algorithm systematically explores different routes and finds the optimal one.

Contributions
Contributions to improve the algorithm and add new features are welcome. Feel free to open an issue or submit a pull request.
