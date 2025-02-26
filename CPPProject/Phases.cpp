#include "Phases.hpp"
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

// Phase 1: Basic Operations
void phase1_operations(BankAccount &account) {
    auto depositTask = [&]() {
        for (int i = 0; i < 5; i++) {
            account.deposit(10);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    };

    auto withdrawTask = [&]() {
        for (int i = 0; i < 5; i++) {
            account.withdraw(10);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    };

    std::thread t1(depositTask);
    std::thread t2(withdrawTask);
    t1.join();
    t2.join();
}

// Phase 2: Resource Protection
void phase2_resource_protection(BankAccount &account) {
    auto safeWithdraw = [&](int amount, BankAccount &acc) {
        std::lock_guard<std::mutex> lock(acc.mtx);
        std::cout << "Thread attempting to withdraw: " << amount << "\n";
        acc.withdraw(amount);
    };

    std::cout << "Creating threads...\n";
    std::thread t1(safeWithdraw, 20, std::ref(account));  // Pass by reference
    std::thread t2(safeWithdraw, 30, std::ref(account));  // Pass by reference

    std::cout << "Waiting for threads to join...\n";
    t1.join();
    t2.join();

    std::cout << "Threads finished\n";
}

// Phase 3: Deadlock Creation
void transfer(BankAccount &from, BankAccount &to, int amount) {
    std::unique_lock<std::mutex> lock1(from.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.mtx, std::defer_lock);

    while (true) {
        // Try to lock both mutexes
        if (std::try_lock(lock1, lock2) == -1) {  // -1 means both locks were successful
            if (from.withdraw(amount)) {
                to.deposit(amount);
                std::cout << "Transferência de " << amount << " concluída!\n";
            }
            break;
        } else {
            std::cout << "Deadlock detected. Retrying transfer.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Retry after a short delay
        }
    }
}
void phase3_deadlock_creation(BankAccount &acc1, BankAccount &acc2) {
    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 10);

    t1.join();
    t2.join();
}

// Phase 4: Deadlock Resolution
void safe_transfer(BankAccount &from, BankAccount &to, int amount) {
    std::unique_lock<std::mutex> lock1(from.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.mtx, std::defer_lock);

    // Avoid deadlock by locking both in the same order
    std::lock(lock1, lock2);

    if (from.withdraw(amount)) {
        to.deposit(amount);
        std::cout << "Transferência segura de " << amount << " concluída!\n";
    }
}

void phase4_deadlock_resolution(BankAccount &acc1, BankAccount &acc2) {
    std::thread t1(safe_transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(safe_transfer, std::ref(acc2), std::ref(acc1), 10);

    t1.join();
    t2.join();
}
