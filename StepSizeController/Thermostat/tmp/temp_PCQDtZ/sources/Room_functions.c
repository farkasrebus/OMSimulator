#include "Room_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Room_includes.h"


Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_FluidConstants omc_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_FluidConstants(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_FluidConstants tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_FluidConstants(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_FluidConstants__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties omc_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$dryair omc_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$dryair(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$dryair tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$dryair(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$dryair__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$steam omc_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$steam(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$steam tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$steam(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_GasProperties$steam__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_ThermodynamicState omc_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X)
{
  Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._T = omc_T;
  tmp1._X = omc_X;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X)
{
  return mmc_mk_box4(3, &Buildings_Fluid_Interfaces_ConservationEquation$vol$dynBal_Medium_ThermodynamicState__desc, _p, _T, _X);
}

Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_FluidConstants omc_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_FluidConstants(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_FluidConstants tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_FluidConstants(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_FluidConstants__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties omc_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$dryair omc_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$dryair(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$dryair tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$dryair(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$dryair__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$steam omc_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$steam(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$steam tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$steam(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_GasProperties$steam__desc, _MM, _R, _cp, _cv);
}

Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_ThermodynamicState omc_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X)
{
  Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._T = omc_T;
  tmp1._X = omc_X;
  return tmp1;
}

modelica_metatype boxptr_Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X)
{
  return mmc_mk_box4(3, &Buildings_Fluid_MixingVolumes_MixingVolume$vol_Medium_ThermodynamicState__desc, _p, _T, _X);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_FluidConstants omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_FluidConstants(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_FluidConstants tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_FluidConstants(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_FluidConstants__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$dryair omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$dryair(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$dryair tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$dryair(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$dryair__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$steam omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$steam(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$steam tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$steam(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_GasProperties$steam__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_ThermodynamicState omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._T = omc_T;
  tmp1._X = omc_X;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X)
{
  return mmc_mk_box4(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$dynBal$ports_Medium_ThermodynamicState__desc, _p, _T, _X);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_FluidConstants omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_FluidConstants(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_FluidConstants tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_FluidConstants(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_FluidConstants__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$dryair omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$dryair(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$dryair tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$dryair(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$dryair__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$steam omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$steam(threadData_t *threadData, modelica_real omc_MM, modelica_real omc_R, modelica_real omc_cp, modelica_real omc_cv)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$steam tmp1;
  tmp1._MM = omc_MM;
  tmp1._R = omc_R;
  tmp1._cp = omc_cp;
  tmp1._cv = omc_cv;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$steam(threadData_t *threadData, modelica_metatype _MM, modelica_metatype _R, modelica_metatype _cp, modelica_metatype _cv)
{
  return mmc_mk_box5(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_GasProperties$steam__desc, _MM, _R, _cp, _cv);
}

Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_ThermodynamicState omc_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_T, real_array omc_X)
{
  Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._T = omc_T;
  tmp1._X = omc_X;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _T, modelica_metatype _X)
{
  return mmc_mk_box4(3, &Modelica_Fluid_Vessels_BaseClasses_VesselFluidPorts__b$vol$ports_Medium_ThermodynamicState__desc, _p, _T, _X);
}

Modelica_Media_IdealGases_Common_DataRecord omc_Modelica_Media_IdealGases_Common_DataRecord(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$Air omc_Modelica_Media_IdealGases_Common_DataRecord$Air(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$Air tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$Air(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$Air__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$Ar omc_Modelica_Media_IdealGases_Common_DataRecord$Ar(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$Ar tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$Ar(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$Ar__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C2H2__vinylidene omc_Modelica_Media_IdealGases_Common_DataRecord$C2H2__vinylidene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C2H2__vinylidene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C2H2__vinylidene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C2H2__vinylidene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C2H4 omc_Modelica_Media_IdealGases_Common_DataRecord$C2H4(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C2H4 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C2H4(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C2H4__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C2H5OH omc_Modelica_Media_IdealGases_Common_DataRecord$C2H5OH(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C2H5OH tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C2H5OH(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C2H5OH__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C2H6 omc_Modelica_Media_IdealGases_Common_DataRecord$C2H6(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C2H6 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C2H6(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C2H6__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C3H6__propylene omc_Modelica_Media_IdealGases_Common_DataRecord$C3H6__propylene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C3H6__propylene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C3H6__propylene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C3H6__propylene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C3H8 omc_Modelica_Media_IdealGases_Common_DataRecord$C3H8(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C3H8 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C3H8(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C3H8__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C4H10__n__butane omc_Modelica_Media_IdealGases_Common_DataRecord$C4H10__n__butane(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C4H10__n__butane tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C4H10__n__butane(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C4H10__n__butane__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C4H8__1__butene omc_Modelica_Media_IdealGases_Common_DataRecord$C4H8__1__butene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C4H8__1__butene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C4H8__1__butene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C4H8__1__butene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C5H10__1__pentene omc_Modelica_Media_IdealGases_Common_DataRecord$C5H10__1__pentene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C5H10__1__pentene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C5H10__1__pentene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C5H10__1__pentene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C5H12__n__pentane omc_Modelica_Media_IdealGases_Common_DataRecord$C5H12__n__pentane(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C5H12__n__pentane tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C5H12__n__pentane(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C5H12__n__pentane__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C6H12__1__hexene omc_Modelica_Media_IdealGases_Common_DataRecord$C6H12__1__hexene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C6H12__1__hexene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C6H12__1__hexene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C6H12__1__hexene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C6H14__n__hexane omc_Modelica_Media_IdealGases_Common_DataRecord$C6H14__n__hexane(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C6H14__n__hexane tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C6H14__n__hexane(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C6H14__n__hexane__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C6H6 omc_Modelica_Media_IdealGases_Common_DataRecord$C6H6(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C6H6 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C6H6(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C6H6__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C7H14__1__heptene omc_Modelica_Media_IdealGases_Common_DataRecord$C7H14__1__heptene(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C7H14__1__heptene tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C7H14__1__heptene(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C7H14__1__heptene__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C7H16__n__heptane omc_Modelica_Media_IdealGases_Common_DataRecord$C7H16__n__heptane(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C7H16__n__heptane tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C7H16__n__heptane(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C7H16__n__heptane__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C8H10__ethylbenz omc_Modelica_Media_IdealGases_Common_DataRecord$C8H10__ethylbenz(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C8H10__ethylbenz tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C8H10__ethylbenz(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C8H10__ethylbenz__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$C8H18__n__octane omc_Modelica_Media_IdealGases_Common_DataRecord$C8H18__n__octane(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$C8H18__n__octane tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$C8H18__n__octane(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$C8H18__n__octane__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$CH3OH omc_Modelica_Media_IdealGases_Common_DataRecord$CH3OH(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$CH3OH tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$CH3OH(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$CH3OH__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$CH4 omc_Modelica_Media_IdealGases_Common_DataRecord$CH4(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$CH4 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$CH4(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$CH4__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$CL2 omc_Modelica_Media_IdealGases_Common_DataRecord$CL2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$CL2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$CL2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$CL2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$CO omc_Modelica_Media_IdealGases_Common_DataRecord$CO(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$CO tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$CO(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$CO__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$CO2 omc_Modelica_Media_IdealGases_Common_DataRecord$CO2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$CO2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$CO2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$CO2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$F2 omc_Modelica_Media_IdealGases_Common_DataRecord$F2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$F2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$F2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$F2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$H2 omc_Modelica_Media_IdealGases_Common_DataRecord$H2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$H2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$H2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$H2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$H2O omc_Modelica_Media_IdealGases_Common_DataRecord$H2O(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$H2O tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$H2O(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$H2O__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$He omc_Modelica_Media_IdealGases_Common_DataRecord$He(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$He tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$He(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$He__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$N2 omc_Modelica_Media_IdealGases_Common_DataRecord$N2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$N2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$N2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$N2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$N2O omc_Modelica_Media_IdealGases_Common_DataRecord$N2O(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$N2O tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$N2O(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$N2O__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$NH3 omc_Modelica_Media_IdealGases_Common_DataRecord$NH3(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$NH3 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$NH3(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$NH3__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$NO omc_Modelica_Media_IdealGases_Common_DataRecord$NO(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$NO tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$NO(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$NO__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$NO2 omc_Modelica_Media_IdealGases_Common_DataRecord$NO2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$NO2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$NO2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$NO2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$Ne omc_Modelica_Media_IdealGases_Common_DataRecord$Ne(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$Ne tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$Ne(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$Ne__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$O2 omc_Modelica_Media_IdealGases_Common_DataRecord$O2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$O2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$O2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$O2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$SO2 omc_Modelica_Media_IdealGases_Common_DataRecord$SO2(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$SO2 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$SO2(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$SO2__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_IdealGases_Common_DataRecord$SO3 omc_Modelica_Media_IdealGases_Common_DataRecord$SO3(threadData_t *threadData, modelica_string omc_name, modelica_real omc_MM, modelica_real omc_Hf, modelica_real omc_H0, modelica_real omc_Tlimit, real_array omc_alow, real_array omc_blow, real_array omc_ahigh, real_array omc_bhigh, modelica_real omc_R)
{
  Modelica_Media_IdealGases_Common_DataRecord$SO3 tmp1;
  tmp1._name = omc_name;
  tmp1._MM = omc_MM;
  tmp1._Hf = omc_Hf;
  tmp1._H0 = omc_H0;
  tmp1._Tlimit = omc_Tlimit;
  tmp1._alow = omc_alow;
  tmp1._blow = omc_blow;
  tmp1._ahigh = omc_ahigh;
  tmp1._bhigh = omc_bhigh;
  tmp1._R = omc_R;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_IdealGases_Common_DataRecord$SO3(threadData_t *threadData, modelica_metatype _name, modelica_metatype _MM, modelica_metatype _Hf, modelica_metatype _H0, modelica_metatype _Tlimit, modelica_metatype _alow, modelica_metatype _blow, modelica_metatype _ahigh, modelica_metatype _bhigh, modelica_metatype _R)
{
  return mmc_mk_box11(3, &Modelica_Media_IdealGases_Common_DataRecord$SO3__desc, _name, _MM, _Hf, _H0, _Tlimit, _alow, _blow, _ahigh, _bhigh, _R);
}

Modelica_Media_Interfaces_Types_IdealGas_FluidConstants omc_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Modelica_Media_Interfaces_Types_IdealGas_FluidConstants tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Modelica_Media_Interfaces_Types_IdealGas_FluidConstants__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$H2O omc_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$H2O(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$H2O tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$H2O(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$H2O__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$N2 omc_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$N2(threadData_t *threadData, modelica_string omc_iupacName, modelica_string omc_casRegistryNumber, modelica_string omc_chemicalFormula, modelica_string omc_structureFormula, modelica_real omc_molarMass, modelica_real omc_criticalTemperature, modelica_real omc_criticalPressure, modelica_real omc_criticalMolarVolume, modelica_real omc_acentricFactor, modelica_real omc_meltingPoint, modelica_real omc_normalBoilingPoint, modelica_real omc_dipoleMoment, modelica_boolean omc_hasIdealGasHeatCapacity, modelica_boolean omc_hasCriticalData, modelica_boolean omc_hasDipoleMoment, modelica_boolean omc_hasFundamentalEquation, modelica_boolean omc_hasLiquidHeatCapacity, modelica_boolean omc_hasSolidHeatCapacity, modelica_boolean omc_hasAccurateViscosityData, modelica_boolean omc_hasAccurateConductivityData, modelica_boolean omc_hasVapourPressureCurve, modelica_boolean omc_hasAcentricFactor, modelica_real omc_HCRIT0, modelica_real omc_SCRIT0, modelica_real omc_deltah, modelica_real omc_deltas)
{
  Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$N2 tmp1;
  tmp1._iupacName = omc_iupacName;
  tmp1._casRegistryNumber = omc_casRegistryNumber;
  tmp1._chemicalFormula = omc_chemicalFormula;
  tmp1._structureFormula = omc_structureFormula;
  tmp1._molarMass = omc_molarMass;
  tmp1._criticalTemperature = omc_criticalTemperature;
  tmp1._criticalPressure = omc_criticalPressure;
  tmp1._criticalMolarVolume = omc_criticalMolarVolume;
  tmp1._acentricFactor = omc_acentricFactor;
  tmp1._meltingPoint = omc_meltingPoint;
  tmp1._normalBoilingPoint = omc_normalBoilingPoint;
  tmp1._dipoleMoment = omc_dipoleMoment;
  tmp1._hasIdealGasHeatCapacity = omc_hasIdealGasHeatCapacity;
  tmp1._hasCriticalData = omc_hasCriticalData;
  tmp1._hasDipoleMoment = omc_hasDipoleMoment;
  tmp1._hasFundamentalEquation = omc_hasFundamentalEquation;
  tmp1._hasLiquidHeatCapacity = omc_hasLiquidHeatCapacity;
  tmp1._hasSolidHeatCapacity = omc_hasSolidHeatCapacity;
  tmp1._hasAccurateViscosityData = omc_hasAccurateViscosityData;
  tmp1._hasAccurateConductivityData = omc_hasAccurateConductivityData;
  tmp1._hasVapourPressureCurve = omc_hasVapourPressureCurve;
  tmp1._hasAcentricFactor = omc_hasAcentricFactor;
  tmp1._HCRIT0 = omc_HCRIT0;
  tmp1._SCRIT0 = omc_SCRIT0;
  tmp1._deltah = omc_deltah;
  tmp1._deltas = omc_deltas;
  return tmp1;
}

modelica_metatype boxptr_Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$N2(threadData_t *threadData, modelica_metatype _iupacName, modelica_metatype _casRegistryNumber, modelica_metatype _chemicalFormula, modelica_metatype _structureFormula, modelica_metatype _molarMass, modelica_metatype _criticalTemperature, modelica_metatype _criticalPressure, modelica_metatype _criticalMolarVolume, modelica_metatype _acentricFactor, modelica_metatype _meltingPoint, modelica_metatype _normalBoilingPoint, modelica_metatype _dipoleMoment, modelica_metatype _hasIdealGasHeatCapacity, modelica_metatype _hasCriticalData, modelica_metatype _hasDipoleMoment, modelica_metatype _hasFundamentalEquation, modelica_metatype _hasLiquidHeatCapacity, modelica_metatype _hasSolidHeatCapacity, modelica_metatype _hasAccurateViscosityData, modelica_metatype _hasAccurateConductivityData, modelica_metatype _hasVapourPressureCurve, modelica_metatype _hasAcentricFactor, modelica_metatype _HCRIT0, modelica_metatype _SCRIT0, modelica_metatype _deltah, modelica_metatype _deltas)
{
  return mmc_mk_box(27, 3, &Modelica_Media_Interfaces_Types_IdealGas_FluidConstants$N2__desc, _iupacName, _casRegistryNumber, _chemicalFormula, _structureFormula, _molarMass, _criticalTemperature, _criticalPressure, _criticalMolarVolume, _acentricFactor, _meltingPoint, _normalBoilingPoint, _dipoleMoment, _hasIdealGasHeatCapacity, _hasCriticalData, _hasDipoleMoment, _hasFundamentalEquation, _hasLiquidHeatCapacity, _hasSolidHeatCapacity, _hasAccurateViscosityData, _hasAccurateConductivityData, _hasVapourPressureCurve, _hasAcentricFactor, _HCRIT0, _SCRIT0, _deltah, _deltas);
}

#ifdef __cplusplus
}
#endif
