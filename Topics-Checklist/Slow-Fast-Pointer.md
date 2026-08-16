Absolutely. Below is clean GitHub-ready Markdown. You can copy everything inside the code block directly into slow-fast-pointer.md.

# Slow & Fast Pointer — Interview Revision Sheet
> A comprehensive revision sheet for the Slow/Fast Pointer and Two-Pointer patterns used in linked lists, arrays, and cyclic sequences.
---
## 1. Pattern Overview
The **Slow/Fast Pointer** pattern uses two pointers moving at different speeds or maintaining a fixed distance.
Typical movement:
```cpp
slow = slow->next;
fast = fast->next->next;

The pattern is useful for:

* Finding the middle of a linked list
* Detecting cycles
* Finding the beginning of a cycle
* Finding duplicates using cycle detection
* Finding the Nth node from the end
* Palindrome linked lists
* Reordering linked lists
* Detecting cycles in non-linked-list sequences

⸻

2. Pattern Recognition Cheat Sheet

Problem Clue	Pattern
Find middle of linked list	Slow/Fast
Detect cycle	Floyd’s Cycle Detection
Find cycle entrance	Floyd Phase 2
Find duplicate without modifying array	Array → Cycle
Nth node from end	Fast pointer offset
Palindrome linked list	Middle + Reverse
Reorder linked list	Middle + Reverse + Merge
Repeated transformation	Treat values as nodes → Floyd
Intersection of two linked lists	Pointer switching/alignment

⸻

3. Core Concept — Floyd’s Cycle Detection

Also called:

Floyd’s Tortoise and Hare Algorithm

Two pointers move at different speeds:

slow → 1 step
fast → 2 steps

Basic idea:

slow = slow->next;
fast = fast->next->next;

If there is a cycle, eventually:

slow == fast

Why?

Once both pointers are inside the cycle, fast gains one position relative to slow during every iteration.

Eventually they must meet.

⸻

4. Find Middle of Linked List

Problem

Given:

1 → 2 → 3 → 4 → 5

Find the middle node:

1 → 2 → 3 → 4 → 5
        ↑
      middle

Approach

Use:

* slow → moves 1 step
* fast → moves 2 steps

ListNode* slow = head;
ListNode* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}

When the loop finishes:

slow → middle

Complexity

* Time: O(n)
* Space: O(1)

Interview Trigger

“Find the middle of a linked list.”

Immediately think:

Slow/Fast Pointer

⸻

5. Linked List Cycle

Problem

Determine whether a linked list contains a cycle.

Example:

1 → 2 → 3 → 4
        ↑   ↓
        └───┘

Approach

ListNode* slow = head;
ListNode* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        return true;
}
return false;

If:

slow == fast

a cycle exists.

If fast reaches nullptr, there is no cycle.

Complexity

* Time: O(n)
* Space: O(1)

Key Insight

A set can detect visited nodes, but Floyd’s algorithm achieves O(1) extra space.

⸻

6. Linked List Cycle II — Find Cycle Entrance

Problem

Find the node where the cycle begins.

Example:

1 → 2 → 3 → 4 → 5
        ↑       ↓
        └───────┘

Cycle entrance:

3

⸻

Phase 1 — Detect Cycle

Use Floyd’s algorithm:

ListNode* slow = head;
ListNode* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        break;
}

The collision point is somewhere inside the cycle.

It is not necessarily the cycle entrance.

⸻

Phase 2 — Find Entrance

Reset one pointer:

slow = head;

Then move both one step:

while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}

The meeting point is the cycle entrance.

Complexity

* Time: O(n)
* Space: O(1)

Important Interview Concept

Be prepared to explain:

Why does resetting one pointer to head and moving both one step find the cycle entrance?

This is often more important than memorizing the code.

⸻

7. Find the Duplicate Number

Problem

Given:

nums = [1,3,4,2,2]

Return:

2

⸻

Key Insight

Treat the array as a linked list.

index → nums[index]

For:

index:  0  1  2  3  4
nums:   1  3  4  2  2

The links become:

0 → 1 → 3 → 2 → 4
            ↑   ↓
            └───┘

The duplicate creates a cycle.

⸻

Phase 1 — Detect Cycle

int slow = 0;
int fast = 0;
do {
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];
} while (slow != fast);

⸻

Phase 2 — Find Cycle Entrance

slow = 0;
while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
}

Return:

return slow;

Complexity

* Time: O(n)
* Space: O(1)
* Input array is not modified

Pattern

Array
  ↓
Treat values as next pointers
  ↓
Cycle
  ↓
Floyd
  ↓
Cycle entrance
  ↓
Duplicate

This is one of the most important pattern-recognition problems.

⸻

8. Remove Nth Node From End

Problem

Given:

1 → 2 → 3 → 4 → 5

Remove the 2nd node from the end:

1 → 2 → 3 → 5

⸻

Key Idea

Maintain a fixed distance of n between two pointers.

slow ←──── n nodes ────→ fast

Move fast ahead by n nodes.

Then move both together.

When fast reaches the end:

slow → node before target

Remove:

slow->next = slow->next->next;

⸻

Recommended Approach

Use a dummy node:

dummy → 1 → 2 → 3 → 4 → 5

This makes removing the head easier.

Complexity

* Time: O(n)
* Space: O(1)

Pattern

Fast pointer offset

This is part of the broader Two-Pointer family, even though it isn’t Floyd cycle detection.

⸻

9. Palindrome Linked List

Problem

Determine whether:

1 → 2 → 3 → 2 → 1

is a palindrome.

⸻

Approach

Use three steps:

1. Find middle
       ↓
2. Reverse second half
       ↓
3. Compare both halves

⸻

Step 1 — Find Middle

Use slow/fast pointers.

For:

1 → 2 → 3 → 2 → 1

you reach approximately:

1 → 2 → 3 → 2 → 1
        ↑
       slow

For odd-length lists, skip the middle element when appropriate.

⸻

Step 2 — Reverse Second Half

Example:

1 → 2 → 3 → 2 → 1

Second half:

2 → 1

After reversal:

1 → 2

⸻

Step 3 — Compare

Compare:

First half:
1 → 2 → 3
Second half:
1 → 2

If every corresponding value matches, the list is a palindrome.

Complexity

* Time: O(n)
* Space: O(1)

Pattern Combination

Slow/Fast
    +
Linked List Reversal
    +
Two Pointer Comparison

⸻

10. Reorder List

Problem

Given:

1 → 2 → 3 → 4 → 5

Reorder into:

1 → 5 → 2 → 4 → 3

⸻

Approach

Three steps:

Find middle
    ↓
Reverse second half
    ↓
Merge alternating nodes

⸻

Step 1 — Find Middle

1 → 2 → 3 | 4 → 5
          ↑
         slow

Split the list.

First:
1 → 2 → 3
Second:
4 → 5

⸻

Step 2 — Reverse Second Half

5 → 4

⸻

Step 3 — Merge Alternating

First:  1 → 2 → 3
Second: 5 → 4

Result:

1 → 5 → 2 → 4 → 3

Complexity

* Time: O(n)
* Space: O(1)

Interview Pattern

Middle
  ↓
Reverse
  ↓
Merge

This is an excellent linked-list interview problem because it combines multiple patterns.

⸻

11. Intersection of Two Linked Lists

This problem uses Two-Pointer Alignment, rather than traditional slow/fast movement.

Example:

A: 1 → 2 → 3
            \
             7 → 8
            /
B:     4 → 5

The lists may have different lengths.

⸻

Key Trick

Pointer A traverses:

A → B

Pointer B traverses:

B → A

Implementation:

ListNode* p1 = headA;
ListNode* p2 = headB;
while (p1 != p2) {
    p1 = (p1 == nullptr) ? headB : p1->next;
    p2 = (p2 == nullptr) ? headA : p2->next;
}
return p1;

⸻

Why Does This Work?

Suppose:

length(A) = m
length(B) = n

Pointer A travels:

m + n

Pointer B travels:

n + m

Therefore both travel the same total distance.

If an intersection exists, they meet at the same actual node.

If there is no intersection:

p1 == p2 == nullptr

Complexity

* Time: O(m+n)
* Space: O(1)

Pattern

Pointer A → A + B
Pointer B → B + A

⸻

12. Happy Number

This is an important variation because there is no linked list.

Definition

Repeatedly replace a number with the sum of the squares of its digits.

Example:

19
 ↓
82
 ↓
68
 ↓
100
 ↓
1

Since it reaches 1, 19 is a happy number.

⸻

Key Insight

Treat each number as a node:

number → next(number)

where:

next(number)
=
sum of squares of digits

Example:

19 → 82 → 68 → 100 → 1

For an unhappy number, the sequence eventually enters a cycle.

Therefore Floyd’s algorithm can be used.

slow = next(slow);
fast = next(next(fast));

If the sequence reaches 1:

Happy

If slow == fast before reaching 1:

Not Happy

⸻

Helper Function

int sumSquareDigits(int n) {
    int result = 0;
    while (n > 0) {
        int digit = n % 10;
        result += digit * digit;
        n /= 10;
    }
    return result;
}

Complexity

* Time: approximately O(log n) per transformation
* Space: O(1) using Floyd

Important Pattern

Floyd does not require a linked list.

It works whenever you have a deterministic sequence:

x → f(x) → f(f(x)) → f(f(f(x))) → ...

and that sequence can eventually enter a cycle.

⸻

13. Important Variations

A. Different Speeds

slow → 1 step
fast → 2 steps

Used for:

* Middle of Linked List
* Cycle Detection
* Cycle Entrance
* Find Duplicate Number
* Happy Number

⸻

B. Fixed Distance

slow ←──── n ────→ fast

Used for:

* Remove Nth Node From End

⸻

C. Middle + Reversal

Slow/Fast
    ↓
Find Middle
    ↓
Reverse

Used for:

* Palindrome Linked List
* Reorder List

⸻

D. Pointer Alignment

A → B
B → A

Used for:

* Intersection of Two Linked Lists

⸻

14. Interview Decision Tree

When you see a linked-list problem:

                    Linked List
                         |
              +----------+----------+
              |                     |
          Position?               Cycle?
              |                     |
          Slow/Fast              Floyd
              |                     |
       +------+-----+         +-----+------+
       |            |         |            |
    Middle       Nth End    Detect      Find Entry
                                     

If you see:

“Find middle”

→ Slow/Fast

“Detect cycle”

→ Floyd

“Find cycle starting point”

→ Floyd Phase 2

“Nth node from end”

→ Fast pointer offset

“Palindrome”

→ Middle → Reverse → Compare

“Reorder”

→ Middle → Reverse → Merge

“Intersection of two lists”

→ Pointer switching

“Repeated transformation”

→ Ask:

Can I model this as x → f(x)?

If yes, consider Floyd.

⸻

15. Templates to Memorize

Find Middle

ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}

⸻

Detect Cycle

ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        return true;
}
return false;

⸻

Find Cycle Entrance

// Phase 1: Detect collision
// Phase 2:
slow = head;
while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
return slow;

⸻

Reverse Linked List

ListNode* prev = nullptr;
ListNode* curr = head;
while (curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
return prev;

⸻

Intersection

ListNode* p1 = headA;
ListNode* p2 = headB;
while (p1 != p2) {
    p1 = p1 ? p1->next : headB;
    p2 = p2 ? p2->next : headA;
}
return p1;

⸻

16. Problems Completed

Problem	Pattern	Status
Middle of Linked List	Slow/Fast	🟢
Linked List Cycle	Floyd	🟢
Linked List Cycle II	Floyd + Phase 2	🟢
Find Duplicate Number	Array → Cycle	🟢
Remove Nth Node From End	Pointer Offset	🟢
Palindrome Linked List	Middle + Reverse	🟢
Reorder List	Middle + Reverse + Merge	🟢
Intersection of Linked Lists	Pointer Alignment	🟢
Happy Number	Floyd on Sequence	🟢

⸻

17. Final Mental Model

Before coding, ask:

1. Do I need to find a position?
       ↓
   Slow/Fast
2. Could there be a cycle?
       ↓
   Floyd
3. Do I need the cycle entrance?
       ↓
   Floyd Phase 2
4. Do I need a fixed distance between pointers?
       ↓
   Fast Pointer Offset
5. Do I need to compare two halves?
       ↓
   Middle + Reverse
6. Do two linked lists have different lengths?
       ↓
   Pointer Switching
7. Is there a repeated transformation?
       ↓
   Model x → f(x)
       ↓
   Consider Floyd

⸻

18. Complexity Summary

Problem	Time	Space
Middle of Linked List	O(n)	O(1)
Linked List Cycle	O(n)	O(1)
Cycle II	O(n)	O(1)
Find Duplicate	O(n)	O(1)
Remove Nth From End	O(n)	O(1)
Palindrome Linked List	O(n)	O(1)
Reorder List	O(n)	O(1)
Intersection	O(m+n)	O(1)
Happy Number	O(log n) per transformation	O(1)

⸻

19. Key Takeaways

Remember these 5 things:

1. Slow/Fast is not just for cycle detection.
2. Floyd works on any deterministic sequence that can form a cycle.
3. Find Duplicate Number = Array interpreted as a linked list.
4. Palindrome/Reorder = Middle + Reverse + Two Pointer.
5. Intersection = Align pointer distances using A → B and B → A.

Pattern recognition is more important than memorizing individual solutions.

Once you recognize the structure, the implementation usually follows naturally.