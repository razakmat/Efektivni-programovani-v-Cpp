#ifndef PAIRINTOWNER_H
#define PAIRINTOWNER_H

#include "PairInt.h"

class PairIntOwner
{
    // private members

public:
    enum Storage { INCLUDED, DYNAMIC };

    PairIntOwner()  // default constructor
    { }

    PairIntOwner(Storage s, int a, int b)  // converitng constructor
    { }

    PairIntOwner(const PairIntOwner&) = delete;
    PairIntOwner(PairIntOwner&&) = delete;
    PairIntOwner operator=(const PairIntOwner&) = delete;
    PairIntOwner operator=(PairIntOwner&&) = delete;

    ~PairIntOwner()  // destructor
    { }

    PairInt& value()  // owned objetct accessor
    { }
};

#endif
