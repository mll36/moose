#ifndef TENSORMECHANICSPLASTICWEAKPLANESHEAREXPONENTIAL_H
#define TENSORMECHANICSPLASTICWEAKPLANESHEAREXPONENTIAL_H

#include "TensorMechanicsPlasticWeakPlaneShear.h"


class TensorMechanicsPlasticWeakPlaneShearExponential;


template<>
InputParameters validParams<TensorMechanicsPlasticWeakPlaneShearExponential>();

/**
 * Rate-independent associative weak-plane tensile failure
 * with exponential hardening/softening.
 */
class TensorMechanicsPlasticWeakPlaneShearExponential : public TensorMechanicsPlasticWeakPlaneShear
{
 public:
  TensorMechanicsPlasticWeakPlaneShearExponential(const std::string & name, InputParameters parameters);

 protected:

  /// The cohesion
  Real _cohesion;

  /// tan(friction angle)
  Real _tan_phi;

  /// tan(dilation angle)
  Real _tan_psi;

  /// The cohesion_residual
  Real _cohesion_residual;

  /// tan(friction angle_residual)
  Real _tan_phi_residual;

  /// tan(dilation angle_residual)
  Real _tan_psi_residual;

  /// Logarithmic rate of change of cohesion to _cohesion_residual
  Real _cohesion_rate;

  /// Logarithmic rate of change of tan_phi to tan_phi_residual
  Real _tan_phi_rate;

  /// Logarithmic rate of change of tan_psi to tan_psi_residual
  Real _tan_psi_rate;

  /// cohesion as a function of internal parameter
  virtual Real cohesion(const Real internal_param) const;

  /// d(cohesion)/d(internal_param)
  virtual Real dcohesion(const Real internal_param) const;

  /// tan_phi as a function of internal parameter
  virtual Real tan_phi(const Real internal_param) const;

  /// d(tan_phi)/d(internal_param);
  virtual Real dtan_phi(const Real internal_param) const;

  /// tan_psi as a function of internal parameter
  virtual Real tan_psi(const Real internal_param) const;

  /// d(tan_psi)/d(internal_param);
  virtual Real dtan_psi(const Real internal_param) const;

};

#endif // TENSORMECHANICSPLASTICWEAKPLANESHEAREXPONENTIAL_H
