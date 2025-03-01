# Banking Thread Simulation

## Phase 1

#### Objective
Creating threads that represent different banking transactions.

#### Challenges and Solutions
**Challenge 1:**
Setting up the Virtual Machine brought up some issues as it had been a while since I had set one up. My machine did not have a lot of space, which I did not realize initially, so it kept breaking.

**Solution:**
I bought a new SSD and installed ubuntu on it 

**Challenge 2:**
Though not mandatory, I initially tried coding directly in C++ in gedit, which was not the best idea as I barely had any experience with it.

**Solution:**
I decided to code in Python first as it was more familiar to me when it came to setting up Object-Oriented Programming concepts. Then, I used documentation and Artificial Intelligence tools to help me correct syntax and implement my code in C++.

#### Outcomes
- I was able to set up a simulation of accounts processing transactions successfully.
- The transactions were running simultaneously and would sometimes clash during runtime, leading to print statements printing on the same line.
- I increased my understanding of threads and became familiar with C++.

---

## Phase 2
#### Objective
Implement mutexes to control access to bank accounts, preventing multiple threads from accessing the same account simultaneously.

#### Challenges and Solutions
**Challenge 1:**
Doing this in Python was initially easier because I struggled to implement the lock on the right function in C++. I overthought it and tried to create a function housing both deposit and withdrawal.

**Solution:**
I realized that I needed to integrate the lock call in my class and then call it within each method.

#### Outcomes
- Instead of all the threads trying to run simultaneously, the mutex ensured that each thread's task was completed before the next task was executed. This is crucial for real-life scenarios, such as ensuring enough money is deposited before a withdrawal to avoid an overdraft.
- More organized output.
- I learned how mutexes work in both Python and C++ and how they are called differently in each language.

---

## Phase 3
#### Objective
Simulate deadlock by having transactions lock one account and wait for access to another.

#### Challenges and Solutions
**Challenge 1:**
I updated my code significantly in this phase. I relied less on my Python code, but I ran into many stumbling blocks as C++ has a more sophisticated way of passing arguments to functions.

**Solution:**
I decided to focus on simulating the transfer from one account to another by creating two separate functions to handle the process.

**Challenge 2:**
Before starting this phase, a few days had passed, and I lost track and access to my VM. For some reason, I could not get it to open.

**Solution:**
I deleted the Ubuntu instance and created another one, ensuring I allocated the right amount of space and processors.

#### Outcomes
- I used two different methods, but the issue was that I locked each account after the first transaction. This caused a deadlock because the lock prevented another thread from accessing the function.
- The only way to resolve this was to unlock it after the thread finished running, which I implemented in Phase 4.

---

## Phase 4
#### Objective
Resolve the deadlock using timeout mechanisms or by ordering account access to prevent circular waits.

#### Challenges and Solutions
No major challenges were encountered in this phase.

#### Outcomes
- I ensured that after my transactions were complete, I called the unlock function on both accounts to allow the next thread to complete its action.

