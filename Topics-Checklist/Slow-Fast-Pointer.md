# Slow & Fast Pointer — Interview Revision

## 1. Core Pattern

Two pointers move at different speeds or maintain a fixed distance.

```cpp
slow = slow->next;
fast = fast->next->next;
```

### Think Slow/Fast when you see:

| Problem Clue | Pattern |
|---|---|
| Find middle | Slow/Fast |
| Detect cycle | Floyd |
| Find cycle entrance | Floyd Phase 2 |
| Find duplicate | Array → Cycle |
| Nth node from end | Fixed distance |
| Palindrome | Middle + Reverse |
| Reorder List | Middle + Reverse + Merge |
| Repeated transformation | Floyd |
| Intersection | Pointer Switching |

---

## 2. Find Middle

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

At the end:

```text
slow → middle
```

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 3. Detect Linked List Cycle — Floyd

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        return true;
}

return false;
```

### Key idea

If a cycle exists, `fast` eventually catches `slow`.

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 4. Find Cycle Entrance

### Phase 1

Detect collision using Floyd.

### Phase 2

```cpp
slow = head;

while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}

return slow;
```

The meeting point is the **cycle entrance**.

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 5. Find Duplicate Number ⭐

Example:

```text
[1,3,4,2,2]
```

### Key Insight

Treat the array as a linked list:

```text
index → nums[index]
```

The duplicate creates a cycle.

### Phase 1 — Detect Cycle

```cpp
int slow = 0;
int fast = 0;

do {
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];
} while (slow != fast);
```

### Phase 2 — Find Cycle Entrance

```cpp
slow = 0;

while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
}

return slow;
```

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 6. Remove Nth Node From End

Maintain a gap of `n` between pointers.

```text
slow ←──── n ────→ fast
```

Move `fast` `n` steps ahead, then move both together.

When `fast` reaches the end:

```text
slow → node before target
```

Use a **dummy node** to handle removing the head.

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 7. Palindrome Linked List ⭐

### Pattern

```text
Find Middle
     ↓
Reverse Second Half
     ↓
Compare Both Halves
```

Uses:

- Slow/Fast
- Linked List Reversal
- Two Pointer comparison

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 8. Reorder List ⭐

Example:

```text
1 → 2 → 3 → 4 → 5

        ↓

1 → 5 → 2 → 4 → 3
```

### Pattern

```text
Find Middle
     ↓
Reverse Second Half
     ↓
Merge Alternately
```

**Time:** `O(n)`  
**Space:** `O(1)`

---

## 9. Intersection of Two Linked Lists

Different length lists can still be aligned.

### Trick

```text
Pointer A: A → B
Pointer B: B → A
```

```cpp
ListNode* p1 = headA;
ListNode* p2 = headB;

while (p1 != p2) {
    p1 = p1 ? p1->next : headB;
    p2 = p2 ? p2->next : headA;
}

return p1;
```

Both pointers travel:

```text
A + B
```

Therefore they align at the intersection.

**Time:** `O(m+n)`  
**Space:** `O(1)`

---

## 10. Happy Number ⭐

No linked list is present, but we can create a sequence:

```text
n → sumSquareDigits(n) → ...
```

Example:

```text
19 → 82 → 68 → 100 → 1
```

If it reaches `1` → **Happy**

If it enters a cycle → **Not Happy**

### Floyd

```cpp
slow = next(slow);
fast = next(next(fast));
```

### Key Insight

Floyd works whenever:

```text
x → f(x) → f(f(x)) → ...
```

can eventually form a cycle.

**Space:** `O(1)`

---

## 11. Templates to Remember

### Find Middle

```cpp
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

### Cycle Detection

```cpp
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
    // cycle
```

### Cycle Entrance

```cpp
slow = head;

while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
```

### Reverse Linked List

```cpp
ListNode* prev = nullptr;
ListNode* curr = head;

while (curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}

return prev;
```

### Intersection

```cpp
p1 = p1 ? p1->next : headB;
p2 = p2 ? p2->next : headA;
```

---

## 12. Problems Completed

| Problem | Pattern |
|---|---|
| Middle of Linked List | Slow/Fast |
| Linked List Cycle | Floyd |
| Linked List Cycle II | Floyd + Phase 2 |
| Find Duplicate Number | Array → Cycle |
| Remove Nth From End | Fixed Distance |
| Palindrome Linked List | Middle + Reverse |
| Reorder List | Middle + Reverse + Merge |
| Intersection | Pointer Switching |
| Happy Number | Floyd on Sequence |

---

## 13. Final Pattern Recognition

```text
Middle?
   → Slow/Fast

Cycle?
   → Floyd

Cycle entrance?
   → Floyd Phase 2

Nth from end?
   → Fixed pointer gap

Palindrome?
   → Middle + Reverse + Compare

Reorder?
   → Middle + Reverse + Merge

Two lists + intersection?
   → A → B / B → A

Repeated transformation?
   → Model x → f(x)
   → Consider Floyd
```

---

## Key Takeaway

> **Don't memorize solutions. Recognize the pattern, then build the solution.**