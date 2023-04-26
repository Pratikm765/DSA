# DSA Question List

Refer GeeksForGeeks, Striever(TakeUForward) and Aditya Verma for detailed explanation.

Data Structures

Array(Recursion,Prefix):
1)Maximum Cuts
2)String Subsets
3)Reverse Array
4)Rotate Array
5)Leaders Array
6)Traping Water
7)Stock buy-sell
8)Window Sum
9)Sum of array subsets(Subarray) using prefix Technique
10)Equilibrium
11)SubArray Zero
12)Small subArray Level(all elements less than K and min no of elements combination greater than k)
13)Prime List & consecutive prime sum
14)Common Binary Array
15)Max Modulo Sum
16)Most Frequent no in given ranges
17)Minimum cost for acquiring all coins with k extra coins allowed with every coin
18)Kadane Algorithm to get max sub array
19)Remove Duplicates From Array
20)Reverse in Groups
21)Majority Wins
22)Convert Sorted array to wave Array
23)Sub Array with Given Sum
24)First Repeated digit in Array
25)Find Immediate smaller of a no in given array
26)Find Missing Elements in sequence of array digits
27)Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space
28)Merge Without Extra Space with O(m*n)
29)Merge Without Extra Space with O((n+m)log(n+m)) using sorting
30)Josephus Iterative
31)Josephus Recursive
28)Union of two arrays using merge technique
29)Intersection of two arrays using merge technique
30)Median of two sorted array of different sizes
31)Platform Needed

Matrix:
1)Print Matrix
2)Print Matrix in snake form
3)Matrix Multiplication
4)Transpose of Matrix
5)Rotate matrix by 90 degree anti-clockwise
6)Rotate matrix by 180 degree
7)Spiral Print Matrix
8)Determinant of Matrix Recursive
9)Maximum size rectangle binary sub-matrix(Histogram Technique)

Strings:
1)Check If Anagrams(sorting, two count arrays, one array)
2)First Repeating character
3)First Non-Repeating character
4)Lexiographic Rank
5)String Rotated
6)Search if anagram present in string
7)Pattern Search Naieve
8)Pattern search Rabin Karp
9)Pattern search KMP
10)Store all words from a string into vector<string>
11)Count words in a string
12)Frequency of each word in string
13)Covert to upper and lower alphabets
14)Remove Spaces
15)Convert string to int

Search and Sorting:
1)Binary Search Iterative
2)Binary Search Recursive
3)LeftMost occurence using Binary Search
4)RightMost occurence using Binary Search
5)Total count using Binary Search
6)Binary Search in Sorted but Rotated Array
7)Binary Search in Sorted but Rotated Array with Duplicates
8)Smallest Element in Sorted Rotated Array
9)Binary Search in Infinite array
10)Peak Element in array
11)Find Square Root using Binary Search
12)Print pairs in Sorted Array
13)Pair Exists in Sorted Array
13)Print pairs in Unsorted Array(Using unordered Set)
14)Triplet Exists in Sorted Array
15)Print Triplets in Sorted Array
16)Print Triplets like (a^2+b^2=c^2)in Sorted Array
17)Bubble Sort
18)Selection Sort
19)Insertion Sort
20)Merge Sort With extra Space Array and Time O(n1 + n2)
21)Merge Sort With No extra Space and Time O(n1 + n2) with extra parameter (using a*n+b rule)
22)Merge Sort With No extra Space and Time O(n1*n2)(Like Insertion Sort)
23)Quick sort using partition function(two different algo)
24)Three way quick sort (Dutch Flag Algorithm)
25)Thre way quick sort with known elements 
26)Cycle Sort
27)Minimum Swaps

Stack-Queue:
1)Stack:push,pop,top,isEmpty,isFull
2)Queue:enque,deque,front,isEmpty,isFull
3)Stack using two queues:push,pop,top,isFull,isEmpty
4)Stack using single queue
5)Check Balanced Parentheses
6)Two Stacks in single Array
7)Stock Span Problem
8)Next Greater in Array

Linked List:
1)addFirst,addLast,addAfter
2)deleteLast,deleteFirst, search and delete
3)Display List, Delete List
4)Find Loop
5)Remove Loop(using loop length)
6)Remove Loop(floyd algorithm)
7)Reverse List(iterative)
8)Reverse List(Recursive and Recursive using divide and conquer method)
9)Find Middle
10)Quick Sort on Linked List

Binary Tree and Binary Search Tree:
1)PreOrder,InOrder,PostOrder
2)LevelOrder(iterative & Recursive)
3)ZigZag Level order 
4)Height of Tree
5)Width of Tree
6)Kth Level Nodes
7)Sum Property
8)Balanced Tree 
9)Balanced Tree Optimized solution with extra function parameter(height)
10)Binary tree to Doubly Linked List
11)Maximum Sum to Leaf
12)Diameter of Tree
13)Find Lowest Common Ancestor 
14)Check if Tree is BST(Min and Max values)
15)Check if Tree is BST(Inorder method with prev pointer)
16)Create binary tree from preorder and inorder sequence.
17)Previous Greater - lower bound (another solution is stock span)
18)Kth Smallest using augmented tree
19)Sum Pair exists in BST
20)Reverse In order
21)Checked if nodes are swapped
22)BST- Insert,Search,Delete
23)Floor and Ceil in BST
24)AVL Tree Insertion Deletion

Graph:
1)UnDirected Graph: addEdge,BFS,DFS
2)Directed Graph: addEdge,BFS,DFS
3)Check Cycle in UnDirected Graph
4)Check Cycle in Directed Graph
5)Shortest Distance unweighted Graph using queue of pairs
6)Topological sort Directed Graph using DFS
7)Topological sort Directed Graph Kahn's Algorithm
8)1-2 Weighted Graph Shortest Distance (Using parent array)
9)All Weighted Graph Shortest Distance for all nodes (using Topological sort)
10)Count Islands in Matrix
Minimum Spanning Tree
11)Prims for adjacency list (using priority queue)
12)Kruskal for adjancency list (using priority queue)
13)prims for adjacency matrix
Shortest Path Algorithm
14)Dijkstra for adjacency matrix
15)Bellman Ford
16)Floyd-Warshall 
Strongly Connected
17)KosaRaju (Topological->Transpose->DFS)
18)Tarjan's
19)Find Bridges using Tarjan's Algorithm
20)Find Articulation Point using Tarjan's Algorithm


Variations of 0-1 Knapsack:
1)Subset Sum 
2)Find Partition Subset
3)Count of Subset Sum
4)Minimum Subset Sum Difference
5)Count of Subset Sum with given Difference
6)Target Sum (Same as Problem 5)

Variations of Unbounded Knapsack:
1)Rod Cutting
2)Coin Change(No of ways of change)
3)Coin Change(min coins to change)

Variations of LCS:
1)Print LCS
2)Longest Common Substring
3)Shortest Common Supersequence SCS
4)Print SCS 
5)Minimum Deletions and Insertions to match Strings MinInsDel.cpp
6)Edit String
7)Longest Palidromic Subsequence LPS
8)Minimum Deletions For LPS
9)Minimum Insertions For LPS
    Same as Problem 8;
    for str="adbcbea"
    Min Deletions=2 d and e 
    Min Insertions=2 aedbcdea or adebcbeda
10)Longest Repeating Subsequence LRS
11)Sequence Pattern Matching

Variations of LIS:
1)Max Sum LIS
2)Minimum Insertions to sort

Variations of Mcm:
1) Palindrome Partitioning
2) Evaluate expression to true
3) Scrambled String
4) Egg Dropping

