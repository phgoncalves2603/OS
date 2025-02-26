//
//  main.cpp
//  CPPProject
//
//  Created by Pedro Henrique Gonçalves Silva Pinto on 2/26/25.
//

#include "Phases.hpp"

int main() {
    BankAccount acc1(100);
    BankAccount acc2(100);

    std::cout << "\n=== phase 1: basic threads operation===\n";
    phase1_operations(acc1);

    std::cout << "\n=== phase 2: resource protection ===\n";
    phase2_resource_protection(acc1);

    std::cout << "\n=== phase 3: deadlock creation ===\n";
    phase3_deadlock_creation(acc1, acc2);

    std::cout << "\n=== phase 4: deadlock resolution ===\n";
    phase4_deadlock_resolution(acc1, acc2);

    return 0;
}
