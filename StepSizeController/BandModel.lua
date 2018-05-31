-- A possible band model that can be used for the StepSizeController

BandModel = {}
BandModel.__index = BandModel

function BandModel:create()
	local bm = {}
	setmetatable(bm,BandModel)
	bm.bounds = {} -- maps the lower bound of the band to the upper bound
	bm.stepSizes = {} -- maps the lower bound of the band to the step size
 	return bm
end

function BandModel:addBand(bandMinValue,bandMaxValue,stepSize)
	self.bounds[bandMinValue]=bandMaxValue
	self.stepSizes[bandMinValue]=stepSize
end

function BandModel:getStepSize(value)
	for min,max in pairs(self.bounds)
	do
		if (value >= min and value <=max) then
			return self.stepSizes[min]
		end
	end
	return nil
end
		

