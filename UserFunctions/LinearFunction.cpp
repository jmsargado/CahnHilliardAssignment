/*
  This file is part of the BROOMStyx project.

  BROOMStyx is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  BROOMStyx is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with BROOMStyx.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the AUTHORS file
  for the list of copyright holders.
*/

#include "LinearFunction.hpp"
#include "Core/ObjectFactory.hpp"
#include "Util/readOperations.hpp"

using namespace broomstyx;

registerBroomstyxObject( UserFunction, LinearFunction )

LinearFunction::LinearFunction()
{
    _name = "LinearFunction";
}

double LinearFunction::at( const RealVector& coor, const TimeData& time )
{
    return _A + _B * coor( 0 ) + _C * coor( 1 );
}

void LinearFunction::readDataFrom( FILE* fp )
{
    verifyKeyword( fp, "Parameters", _name );
    _A = getRealInputFrom( fp, "Failed to read constant value from input file!", _name );
    _B = getRealInputFrom( fp, "Failed to read x-coefficient from input file!", _name );
    _C = getRealInputFrom( fp, "Failed to read y-coefficient from input file!", _name );
}
