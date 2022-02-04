#pragma once

#include "Function.h"

/**
 * Ramps up to a value from another value over time.
 *
 * Examples of how this is intended to be used include the time step size,
 * which may need to be smaller at the beginning of a transient, and boundary
 * condition parameters, which may need to start closer to the steady-state
 * values at the beginning of a transient.
 */
class TimeRampFunction : public Function
{
public:
  TimeRampFunction(const InputParameters & parameters);

  virtual Real value(Real t, const Point & p) const;
  virtual RealVectorValue gradient(Real t, const Point & p) const;

protected:
  /// Initial value
  const Real & _initial_value;
  /// Final value
  const Real & _final_value;
  /// Ramp duration
  const Real & _ramp_duration;
  /// Initial time
  const Real & _initial_time;

  /// Ramp end time
  const Real _ramp_end_time;
  /// Ramp slope
  const Real _ramp_slope;

public:
  static InputParameters validParams();
};