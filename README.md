# Link to UVa problems 
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=0

# Problems started/completed so far
Solved Count: 25

| pb id |           name          | solved |     pb type     |                                        current strategy                                       |
|-------|-------------------------|--------|-----------------|-----------------------------------------------------------------------------------------------|
|   100 | 3n+1 pb                 | 1      | Complete Search |                                                                                               |
|   101 | The block problem       | 0      |                 |                                                                                               |
|   102 | Bin packing             | 1      | Ad hoc          | start from total sum                                                                          |
|   108 | max sum                 | 1      | Complete Search | col cum sum & Kadane's algo                                                                   |
|   115 | climbing trees          | 1      | Ad hoc          | compute depth of nodes                                                                        |
|   147 | Dollars                 | 1      | DP              | Top-Down approach R(n, m) where n := remaining money ; m := coin type                         |
|   169 | Xenosemantics           | 0      |                 |                                                                                               |
|   177 | paper folding           | 1      | Ad hoc          |                                                                                               |
|   410 | Station Balance         | 1      | Greedy          | Add (2*C - S) zeros, sort the array, add to chamber i (S[i], S[2*C - 1 - i])                  |
|   441 | Lotto                   | 1      | Complete Search | brute force                                                                                   |
|   624 | CD                      | 1      | BackTracking    | recursive binary tree && return 2 var (sum, mask)                                             |
|   674 | Coin Change             | 1      | DP              | Top-Down approach R(n, m) where n := remaining money ; m := coin type                         |
|   725 | Division                | 1      | Complete Search | reducing the state space search with math constraint && use bitmask to check digit used       |
|   750 | 8_Queen_Chess_Problem   | 1      | BackTracking    | run through the 8! possiblities of queens positioning, prune if the diagonal is already taken |
|  1099 | Sharing Chocolate       | 0      |                 |                                                                                               |
|  1749 | Airport Construction    | almost | Complete Search | prolong every segment (pi, pj)                                                                |
| 10341 | Solve It                | 1      | D&C             | f is decreasing on [0, 1] ; Bisection or Newton Method                                        |
| 10360 | Rat Attack              | 1      | Complete Search | Backwards strategy: for each group of rats compute all square (i, j, d) that can touches it   |
| 10382 | Watering Grass          | 1      | Greedy          | interval covering problem                                                                     |
| 10976 | Fraction Again !        | 1      | Complete Search | use symetry of the equation and run through [k, 2*k]                                          |
| 11172 | Relational Operators    | 1      | Ad hoc          |                                                                                               |
| 11195 | n-Queen_problem         | 1      | BackTracking    | like 750 unless it uses bitmasks to keep track of avaible rows, left diag and right diag      |
| 11498 | Division of Nlogonia    | 1      | As hoc          |                                                                                               |
| 11565 | Simple Equation         | 1      | Complete Search | pruning properties from equation                                                              |
| 11571 | Simple Equation Extreme | 0      | Complete Search | find X by solving a cubic eq && for x in X and solve 2nd quadratic eq depending on x          |
| 11701 | Cantor                  | 1      | D&C             | Ternary search                                                                                |
| 11727 | Cost cutting            | 1      | Ad hoc          |                                                                                               |
| 11742 | Social Constraints      | 1      | Complete Search | brute force                                                                                   |
| 11935 | Through the dessert     | 1      | Ad hoc          |                                                                                               |
| 12455 | Bars                    | 1      | Complete Search | backtracking with bitmask                                                                     |
        