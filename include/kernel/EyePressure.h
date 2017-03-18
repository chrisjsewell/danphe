/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef EYEPRESSURE_H
#define EYEPRESSURE_H

// Including the "Diffusion" Kernel here so we can extend it
#include "Diffusion.h"

class EyePressure;

template<>
InputParameters validParams<EyePressure>();

/**
 * Represents K/mu * grad_u * grad_phi
 *
 * We are inheriting from Diffusion instead of from Kernel because the
 * grad_u * grad_phi is already coded in there and all we need to do
 * is specialize that calculation by multiplying by K/mu.
 */
class EyePressure : public Diffusion
{
public:
  EyePressure(const InputParameters & parameters);
  virtual ~EyePressure();

protected:
  /**
   * Kernels _must_ override computeQpResidual()
   */
  virtual Real computeQpResidual() override;

  /**
   * This is optional (but recommended!)
   */
  virtual Real computeQpJacobian() override;

  /// These references will be set by the initialization list so that
  /// values can be pulled from the Material system.
  const MaterialProperty<Real> & _permeability;
  const MaterialProperty<Real> & _viscosity;
};


#endif // EYEPRESSURE_H
