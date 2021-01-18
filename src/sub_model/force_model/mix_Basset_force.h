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
\*---------------------------------------------------------------------------*/

#ifndef __MIX_BASSET_FORCE_H__
#define __MIX_BASSET_FORCE_H__

#include <unordered_map>
#include "./force_model.h"

namespace Foam {

class mixBassetForce : public forceModel {
 public:
  //! \brief Runtime type information
  cfdemTypeName("mixBassetForce");

  cfdemDefineNewFunctionAdder(forceModel, mixBassetForce);

  //! \brief Constructor
  mixBassetForce(cfdemCloud& cloud);

  //! \brief Destructor
  ~mixBassetForce();

  void setForce();

 protected:
  void setForceKernel(const int index, Foam::vector& BstForce);

  //! \brief 计算颗粒 index 处的背景流体的ddtu
  Foam::vector getBackgroundDDtU(const int index, const int findCellID) const;

  //! \brief 计算颗粒 index 处的背景流体速度
  Foam::vector getBackgroundUfluid(const int index, const int findCellID) const;

  //! \brief 计算颗粒 index 处的背景流体空隙率
  double getBackgroundVoidFraction(const int index, const int findCellID) const;

 private:
  //! \note subPropsDict_ should be declared in front of other members
  dictionary subPropsDict_;

  const volVectorField& U_;

  const volScalarField& voidFraction_;

  const surfaceScalarField& phi_;
};

}  // namespace Foam

#endif  // __MIX_BASSET_FORCE_H__
