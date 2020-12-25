/*---------------------------------------------------------------------------*\
  CFDEMcoupling - Open Source CFD-DEM coupling

  CFDEMcoupling is part of the CFDEMproject
  www.cfdem.com
                              Christoph Goniva, christoph.goniva@cfdem.com
                              Copyright 2009-2012 JKU Linz
                              Copyright 2012-     DCS Computing GmbH, Linz
------------------------------------------------------------------------------
License
  This file is part of CFDEMcoupling.

  CFDEMcoupling is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 3 of the License, or (at your
  option) any later version.

  CFDEMcoupling is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
  for more details.

  You should have received a copy of the GNU General Public License
  along with CFDEMcoupling; if not, write to the Free Software Foundation,
  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Description
  cfdemCloudIBLmpf derived from Foam::cfdemCloudIBOpti

Class
  Foam::cfdemCloudIBLmpf
\*---------------------------------------------------------------------------*/

#ifndef __CFDEM_CLOUD_IB_LMPF_H__
#define __CFDEM_CLOUD_IB_LMPF_H__

#include "cloud/cfdem_cloud_IB_opti.h"

namespace Foam {

class cfdemCloudIBLmpf : public cfdemCloudIBOpti {
 public:
  //! \brief Constructed from mesh
  cfdemCloudIBLmpf(const fvMesh& mesh);

  //! \brief Destructor
  ~cfdemCloudIBLmpf();

  void calcLmpf(const volVectorField& U, const volScalarField& rho, const volScalarField& volumefraction,
                volVectorField& lmpf) const;
};

}  // namespace Foam

#endif  // __CFDEM_CLOUD_IB_LMPF_H__
