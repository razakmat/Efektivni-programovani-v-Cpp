#define BOOST_TEST_MODULE PairIntOwnerTest
#include <boost/test/included/unit_test.hpp>

#include "PairInt.h"
#include "PairIntOwner.h"

BOOST_AUTO_TEST_CASE( LookupTableTest )
{
    PairIntOwner emtpy;

    BOOST_TEST( PairInt::constructed() == 0 );
    BOOST_TEST( PairInt::alive() == 0 );
    BOOST_TEST( PairInt::destructed() == 0 );

    {    
        PairIntOwner included(PairIntOwner::INCLUDED, 1, 2);

        BOOST_TEST( PairInt::constructed() == 1 );
        BOOST_TEST( PairInt::alive() == 1 );
        BOOST_TEST( PairInt::destructed() == 0 );
    }

    BOOST_TEST( PairInt::constructed() == 1 );
    BOOST_TEST( PairInt::alive() == 0 );
    BOOST_TEST( PairInt::destructed() == 1 );

    {    
        PairIntOwner dynamic(PairIntOwner::DYNAMIC, 3, 4);

        BOOST_TEST( PairInt::constructed() == 2 );
        BOOST_TEST( PairInt::alive() == 1 );
        BOOST_TEST( PairInt::destructed() == 1 );
    }

    BOOST_TEST( PairInt::constructed() == 2 );
    BOOST_TEST( PairInt::alive() == 0 );
    BOOST_TEST( PairInt::destructed() == 2 );
}
