#include<bits/stdc++.h>
using namespace std;



int main() {
    
}

//When DP?
//1. Overlaping Subproblems - solutions of same subproblems are needed again and again - example : Fibonacci Numbers
//  https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/
//2. Optimal Substructure - optimal solution of the given problem can be obtained by using optimal solutions of its subproblems - 
//  eg: In a graph if node 'x' is in shortest path between 'a' and 'b' the shrtest path from 'a' to 'b' is same as shortest path from 'a'
//  to 'x' and 'x' to 'b'. But the longest path does not follow this.
//  https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/

//Two different ways to store values
//1. Memoization (Top Down) (Recursive) - preferred when only few subproblems are needed to be solved
//2. Tabulation (Bottom Up) (Looping) - preferred when all subproblems need to be solved
//  Table is filled in demand

// Steps to solve a DP
// 1) Identify if it is a DP problem
// 2) Decide a state expression with 
//    least parameters
// 3) Formulate state relationship    
// 4) Do tabulation (or add memoization)
//  https://www.geeksforgeeks.org/solve-dynamic-programming-problem/

//Simple Problems
//  1. Ugly Numbers - https://www.geeksforgeeks.org/ugly-numbers/
//  2. 