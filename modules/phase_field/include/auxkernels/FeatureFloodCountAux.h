/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef FEATUREFLOODCOUNTAUX_H
#define FEATUREFLOODCOUNTAUX_H

#include "AuxKernel.h"
#include "FeatureFloodCount.h"

//Forward Declarations
class FeatureFloodCountAux;

template<>
InputParameters validParams<FeatureFloodCountAux>();

/**
 * Function auxiliary value
 */
class FeatureFloodCountAux : public AuxKernel
{
public:
  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  FeatureFloodCountAux(const InputParameters & parameters);

  virtual ~FeatureFloodCountAux() {}

protected:
  virtual Real computeValue();

  /// Function being used to compute the value of this kernel
  const FeatureFloodCount & _flood_counter;

  const unsigned int _var_idx;
  const MooseEnum _field_display;
  bool _var_coloring;

  const FeatureFloodCount::FieldType _field_type;
};

#endif //FEATUREFLOODCOUNTAUX_H
