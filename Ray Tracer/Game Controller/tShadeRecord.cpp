//
// tShadeRecord.cpp
//

#include "tShadeRecord.h"


//
// constructor()
//
tShadeRecord::tShadeRecord()
: _primitiveIntersected( false ),
  hit_an_object( false )
{
}


//
// constructor()
//
tShadeRecord::tShadeRecord( tScene* scenePtr )
: _primitiveIntersected( false ),
  hit_an_object( false ),
  w( scenePtr )
{
}


//
// destructor()
//
tShadeRecord::~tShadeRecord()
{
}