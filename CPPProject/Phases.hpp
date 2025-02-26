//
//  Phases.hpp
//  CPPProject
//
//  Created by Pedro Henrique Gonçalves Silva Pinto on 2/26/25.
//

#ifndef Phases_hpp
#define Phases_hpp

#include "BankAccount.h"

void phase1_operations(BankAccount &account);//&pass by reference
void phase2_resource_protection(BankAccount &account);
void phase3_deadlock_creation(BankAccount &acc1,BankAccount &acc2);
void phase4_deadlock_resolution(BankAccount &acc1, BankAccount&acc2);

#endif /* Phases_hpp */
