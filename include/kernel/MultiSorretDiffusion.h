/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef SORETDIFFUSION_H
#define SORETDIFFUSION_H

#include "Kernel.h"

//Forward Declaration
class SoretDiffusion;

template<>
InputParameters validParams<SoretDiffusion>();
/**
 * SoretDiffusion adds the soret effect in the split form of the Cahn-Hilliard
 * equation.
 */
class SoretDiffusion : public Kernel
{
public:
  SoretDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);
  virtual Real computeQpCJacobian();

  /// int label for temperature variable
  unsigned int _T_var;

  /// Coupled variable for the temperature
  VariableValue & _T;

  /// Variable gradient for temperature
  VariableGradient & _grad_T;

  /// int label for the Concentration
  unsigned int _c_var;

  /// Variable value for the concentration
  VariableValue & _c;

  /// Diffusivity material property
  const MaterialProperty<Real> & _D;

  /// Heat of transport material property
  const MaterialProperty<Real> & _Q;

  /// Boltzmann constant
  const Real _kb;
};

#endif //SORETDIFFUSION_H