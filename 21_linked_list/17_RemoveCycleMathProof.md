# Removing a Cycle in a Linked List – Mathematical Explanation

We use **Floyd’s Cycle Detection Algorithm (Tortoise and Hare)** to detect and remove a cycle. Here's the proof and reasoning behind why this approach works.

---

## **Setup**

Consider a linked list with a cycle:
Head -> … -> Start of Loop-> … -> Cycle End -> Start of Loop …

Define:

- `L1` = distance from **Head** to the start of the loop  
- `C` = length of the **cycle**  
- `k` = distance from **start of loop** to the meeting point of slow & fast pointers inside the cycle  

- `slow` moves **1 step** at a time  
- `fast` moves **2 steps** at a time  

---

## **Step 1: Meeting inside the cycle**

When `slow` and `fast` meet:

\[
\text{Distance travelled by slow} = L_1 + k
\]  

\[
\text{Distance travelled by fast} = L_1 + k + nC \quad \text{(n full cycles)}
\]  

Since `fast` moves twice as fast:

\[
2(L_1 + k) = L_1 + k + nC
\]  

\[
\Rightarrow L_1 + k = nC
\]  

\[
\Rightarrow L_1 = nC - k
\]  

✅ This shows that if we start a pointer from **Head** and a pointer from **meeting point**, both moving **1 step at a time**, they will meet at the **start of the loop**.

---

## **Step 2: Removing the cycle**

- Initialize:  
  - `slow` = Head  
  - `fast` = meeting point inside cycle  
- Move both one step at a time → they meet at **loop start**.  
- Track the previous node (`prev`) of `fast`.  
- Update `prev->next = NULL` → **cycle is removed**.

---

## **Why this works**

1. The relation `L1 = nC - k` ensures the **synchronization** of pointers from head and meeting point.  
2. Moving `fast` with `prev` ensures the exact **node pointing to loop start** is updated.  
3. Complexity is **O(n)** because each node is visited at most **twice**.  

---

## **Key Insight**

The mathematical guarantee:

\[
2(L_1 + k) - (L_1 + k) = L_1 + k = nC \implies L_1 = nC - k
\]  

- Moving from **Head** and **meeting point** collides at **loop start**.  
- Updating `prev->next = NULL` removes the cycle **exactly** without affecting other nodes.  

---

This approach is efficient, precise, and works for **all singly linked lists with cycles**.