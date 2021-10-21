#ifndef PAIRINTOWNER_H
#define PAIRINTOWNER_H

#include "PairInt.h"

class PairIntOwner
{
    alignas(PairInt) unsigned char buffer_[ sizeof(PairInt) ];
    PairInt * ptr;
public:
    enum Storage { INCLUDED, DYNAMIC };

    PairIntOwner(): ptr(NULL)
    { }

    PairIntOwner(Storage s, int a, int b)  // converitng constructor
    { if (s == INCLUDED)
        {
            new (buffer_) PairInt(a,b);
            ptr = reinterpret_cast<PairInt*>(buffer_); 
        }
      else
        {
            ptr = new PairInt(a,b);
        }
    }

    PairIntOwner(const PairIntOwner&) = delete;
    PairIntOwner(PairIntOwner&&) = delete;
    PairIntOwner operator=(const PairIntOwner&) = delete;
    PairIntOwner operator=(PairIntOwner&&) = delete;

    ~PairIntOwner()  // destructor
    { ptr->~PairInt(); }

    PairInt& value()  // owned objetct accessor
    { return *ptr; }
};

#endif
