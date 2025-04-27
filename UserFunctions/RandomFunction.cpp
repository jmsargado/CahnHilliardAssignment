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

#include "RandomFunction.hpp"
#include "Core/ObjectFactory.hpp"
#include "Util/readOperations.hpp"

using namespace broomstyx;

registerBroomstyxObject( UserFunction, RandomFunction )

RandomFunction::RandomFunction()
{
    _name = "RandomFunction";
}

double RandomFunction::at( const RealVector& coor, const TimeData& time )
{
    std::uniform_real_distribution<> dis( _min, _max );
    
    return dis( _generator );
}

void RandomFunction::readDataFrom( FILE* fp )
{
    verifyKeyword( fp, "Min", _name );
    _min = getRealInputFrom( fp, "Failed to read minimum value from input file!", _name );

    verifyKeyword( fp, "Max", _name );
    _max = getRealInputFrom( fp, "Failed to read maximum value from input file!", _name );

    verifyKeyword( fp, "Seed", _name );
    _seed = getRealInputFrom( fp, "Failed to read random seed from input file!", _name );

    _generator.seed( _seed );
}
