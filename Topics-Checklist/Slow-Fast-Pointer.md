Slow & Fast Pointer — Interview Revision Sheet

The Slow/Fast Pointer pattern is primarily used when you need to reason about position, relative distance, or cycles without using extra memory.

The two pointers usually move at different speeds:

slow → 1 step
fast → 2 steps

But the pattern has several important variations.

⸻

1. Core Pattern

Basic Floyd’s Cycle Detection

ListNode* slow = head;
ListNode* fast = head;
do {
    slow = slow->next;
    fast = fast->next->next;
} while (slow != fast);

The important idea:

If both pointers enter a cycle and fast moves 2× as quickly as slow, they will eventually meet.

Why?

Inside the cycle, fast gains one position per iteration relative to slow.

Eventually:

slow == fast

⸻

2. Pattern Recognition Cheat Sheet

When you see:

Problem clue	Think
Find middle	Slow/Fast
Detect cycle	Floyd
Find cycle entrance	Floyd Phase 2
Find duplicate without modifying array	Array → cycle
Nth node from end	Fast pointer offset
Palindrome linked list	Middle + Reverse
Reorder linked list	Middle + Reverse + Merge
Repeated transformation	Treat values as nodes → Floyd
Different length linked lists	Pointer switching/alignment

⸻

3. Problem 1 — Middle of Linked List

Goal

1 → 2 → 3 → 4 → 5
        ↑
      middle

Approach

slow = head;
fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}

When the loop ends:

slow → middle

Complexity

Time:  O(n)
Space: O(1)

Interview trigger

“Find the middle of a linked list.”

Immediately think:

Slow/Fast.

⸻

4. Problem 2 — Linked List Cycle

Goal

Determine whether:

1 → 2 → 3 → 4
        ↑   ↓
        └───┘

contains a cycle.

Approach

slow = slow->next;
fast = fast->next->next;

If:

slow == fast

→ cycle exists.

If fast reaches nullptr:

→ no cycle.

Complexity

Time:  O(n)
Space: O(1)

Key insight

Don’t use a set if the interviewer expects O(1) space.

⸻

5. Problem 3 — Linked List Cycle II

Goal

Find the entry point of the cycle.

Example:

1 → 2 → 3 → 4 → 5
        ↑       ↓
        └───────┘

Cycle starts at 3.

Phase 1 — Detect cycle

slow = head;
fast = head;
while (...) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        break;
}

Meeting point is not necessarily the cycle entrance.

Phase 2 — Find entrance

Reset one pointer:

slow = head;

Then:

while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}

Meeting point = cycle entrance.

Complexity

Time:  O(n)
Space: O(1)

Important interview concept

You should be able to explain why Phase 2 works, not just memorize it.

⸻

6. Problem 4 — Find the Duplicate Number ⭐

Example:

[1,3,4,2,2]

Key insight

Treat the array as a linked list:

index → nums[index]

For:

0 → 1 → 3 → 2 → 4
            ↑   ↓
            └───┘

The duplicate creates a cycle.

Phase 1

Floyd cycle detection:

slow = nums[slow];
fast = nums[fast];
fast = nums[fast];

Phase 2

slow = 0;
while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
}

Return:

slow

Complexity

Time:  O(n)
Space: O(1)

Pattern

Array
 ↓
Treat values as next pointers
 ↓
Cycle
 ↓
Floyd

This is a very important pattern-recognition problem.

⸻

7. Problem 5 — Remove Nth Node From End

Key idea

Create a distance of n between two pointers.

fast
  ↓
1 → 2 → 3 → 4 → 5
↑
slow

Move fast ahead by n.

Then move both together.

When fast reaches the end:

slow → node before target

Then remove:

slow->next = slow->next->next;

Common improvement

Use a dummy node:

dummy → 1 → 2 → 3 → 4 → 5

This handles:

n == length

cleanly.

Complexity

Time:  O(n)
Space: O(1)

Pattern

Fast pointer offset

Not technically Floyd’s cycle detection, but part of the broader two-pointer family.

⸻

8. Problem 6 — Palindrome Linked List ⭐

Example

1 → 2 → 3 → 2 → 1

Approach

Three steps:

1. Find middle
       ↓
2. Reverse second half
       ↓
3. Compare both halves

Step 1

Slow/Fast:

1 → 2 → 3 → 2 → 1
        ↑
       slow

For odd length, skip the middle element when necessary.

Step 2

Reverse:

2 → 1

Step 3

Compare:

1 → 2 → 3
    ↓
1 → 2

Complexity

Time:  O(n)
Space: O(1)

Pattern combination

Slow/Fast
    +
Linked List Reversal
    +
Two Pointers

⸻

9. Problem 7 — Reorder List ⭐⭐⭐

Example:

1 → 2 → 3 → 4 → 5

becomes:

1 → 5 → 2 → 4 → 3

Three-step approach

Find middle
    ↓
Reverse second half
    ↓
Merge alternating

Split:

1 → 2 → 3
4 → 5

Reverse:

5 → 4

Merge:

1 → 5 → 2 → 4 → 3

Complexity

Time:  O(n)
Space: O(1)

Interview takeaway

This is one of the best problems for testing whether you can combine linked-list patterns.

⸻

10. Problem 8 — Intersection of Two Linked Lists

This one does not require slow/fast, but belongs in your two-pointer toolkit.

Example:

A: 1 → 2 → 3
            \
             7 → 8
            /
B:     4 → 5

Trick

Pointer A:

A → B

Pointer B:

B → A

Implementation:

while (p1 != p2) {
    p1 = (p1 == nullptr) ? headB : p1->next;
    p2 = (p2 == nullptr) ? headA : p2->next;
}

Eventually:

p1 == p2

Either:

intersection node

or:

nullptr

Why it works

Both pointers travel:

A + B

Therefore they travel the same total distance, regardless of the original lengths.

Complexity

Time:  O(m+n)
Space: O(1)

⸻

11. Problem 9 — Happy Number ⭐

This is an important variation because there is no linked list.

Define:

next(n) = sum of squares of digits

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

Treat it as:

19 → 82 → 68 → 100 → 1

For an unhappy number, it eventually enters a cycle.

Therefore:

slow = next(slow)
fast = next(next(fast))

Key insight

Floyd doesn’t require a linked list.

It requires:

A deterministic function where repeatedly applying f(x) can produce a cycle.

Complexity

Time:  O(log n) approximately
Space: O(1)

⸻

12. The Most Important Variations You’ve Learned

You can now group your problems into:

A. Different speeds

slow → 1
fast → 2

Used for:

* Middle
* Cycle detection
* Cycle entrance
* Find Duplicate
* Happy Number

⸻

B. Fixed distance

slow ←──── n ────→ fast

Used for:

* Nth node from end

⸻

C. Find middle + transformation

Slow/Fast
    ↓
Middle
    ↓
Reverse

Used for:

* Palindrome
* Reorder List

⸻

D. Pointer alignment

A → B
B → A

Used for:

* Intersection of Linked Lists

⸻

🔥 Interview Decision Tree

When you see a linked-list problem, ask:

                Linked List
                    │
          ┌─────────┴─────────┐
          │                   │
       Position?             Cycle?
          │                   │
       Slow/Fast          Floyd
          │                   │
    ┌─────┴─────┐       ┌─────┴─────┐
    │           │       │           │
 Middle      Nth End   Detect     Find Entry
                            │
                          Cycle II

If you see:

Palindrome

think:

Middle → Reverse → Compare

If you see:

Reorder

think:

Middle → Reverse → Merge

If you see:

Two linked lists
+
intersection

think:

A → B
B → A

If you see:

Repeated transformation

think:

Can I model this as:
x → f(x) → f(f(x)) ...
?

If yes → Floyd may work.

⸻

🧠 Templates to Memorize

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

// Phase 1: detect collision
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

while (p1 != p2) {
    p1 = p1 ? p1->next : headB;
    p2 = p2 ? p2->next : headA;
}
return p1;

⸻

🎯 Problems You’ve Completed

Your current progress:

Problem	Pattern	Status
Middle of LL	Slow/Fast	🟢
Linked List Cycle	Floyd	🟢
Linked List Cycle II	Floyd + Phase 2	🟢
Find Duplicate Number	Array → Cycle	🟢
Remove Nth From End	Pointer Offset	🟢
Palindrome LL	Middle + Reverse	🟢
Reorder List	Middle + Reverse + Merge	🟢
Intersection of LL	Pointer Alignment	🟢
Happy Number	Floyd on sequence	🟢