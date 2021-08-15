//  It is a method of storing and retrieving data from hash table in O(1) time complexity. 
//  It ease the searching process as compared to other methods like binary search and linear search which take 
//  either O(logn) time or O(n) time.
//  There are various method for hashing: k mod 10, k mod n, mid square, Foldng method
//  If same hash value is found for multiple elements then collision occurs.
//  Collision can be resolved by chaining(Open hashing), open addressing(closed hashing)
//  chaining: Create a linked list from the same node of hash and link it
//  Linear probing: Add element in the next available space.