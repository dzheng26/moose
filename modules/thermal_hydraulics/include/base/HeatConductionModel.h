#pragma once

class THMProblem;
class ThermalHydraulicsApp;
class Factory;
class HeatStructureBase;

#include "MooseObject.h"
#include "NamingInterface.h"
#include "libmesh/fe_type.h"

/**
 * Provides functions to setup the heat conduction model.
 *
 * This is a proxy class for the MOOSE Modules' heat conduction model
 */
class HeatConductionModel : public MooseObject, public NamingInterface
{
public:
  HeatConductionModel(const InputParameters & params);

  /**
   * Add field variables used by this model
   */
  virtual void addVariables();

  /**
   * Add initial conditions
   */
  virtual void addInitialConditions();

  /**
   * Add materials used by this model
   */
  virtual void addMaterials();

  /**
   * Add heat conduction equation for cartesian coordinate system
   */
  virtual void addHeatEquationXYZ();

  /**
   * Add heat conduction equation for RZ coordinate system
   */
  virtual void addHeatEquationRZ();

  /**
   * Get the FE type used for heat conduction
   * @return The finite element type
   */
  static const FEType & feType() { return _fe_type; }

protected:
  THMProblem & _sim;
  /// The Factory associated with the MooseApp
  Factory & _factory;
  /// The heat structure component that built this class
  HeatStructureBase & _hs;
  /// Name of the component
  const std::string _comp_name;

public:
  // variable names
  static const std::string DENSITY;
  static const std::string TEMPERATURE;
  static const std::string THERMAL_CONDUCTIVITY;
  static const std::string SPECIFIC_HEAT_CONSTANT_PRESSURE;

  static InputParameters validParams();

protected:
  // FE type used for heat conduction
  static FEType _fe_type;

  friend class Simulation;
};