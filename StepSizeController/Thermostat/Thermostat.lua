--[[
package.path = package.path .. ";../StepSizeController.lua"
require("StepSizeController")
--]]


oms2_setLogFile("Thermostat.log")
oms2_setTempDirectory("./tmp")
oms2_newFMIModel("ThermostatExample")

oms2_addFMU("ThermostatExample","advancedThermostat.fmu","Thermostat")