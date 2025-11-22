#include <iostream>
#include "user.hpp"
#include "inventori/keranjang.hpp"
#include "audit/audit.hpp"

Kasir::Kasir(User &usr) : User(usr) {
    this->sales = 0;

}

void Kasir::commit_transaction(User *usr, Keranjang *cart, Logger *audit) {

    long totalBelanja = cart->totalBelanja();

    Transaction *transact = new Transaction("In", usr->nama);
    audit->updateTransList(transact->addTransaction(totalBelanja));
    delete transact;

}
