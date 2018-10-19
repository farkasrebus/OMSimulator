#include "StepSizeConfiguration.h"
#include "SignalRef.h"
#include "Logging.h"

StepSizeConfiguration::StepSizeConfiguration() :minimalStepSize(1.0e-2), maximalStepSize(1.0e-2) {};

StepSizeConfiguration::~StepSizeConfiguration() {};

void StepSizeConfiguration::addEventIndicator(const oms2::SignalRef& signal) {
    eventIndicators.push_back(signal);
}

void StepSizeConfiguration::addTimeIndicator(const oms2::SignalRef& signal) {
    timeIndicators.push_back(signal);
}

void StepSizeConfiguration::addStaticValueIndicator(const oms2::SignalRef& signal, double lowerBound, double upperBound, double stepSize) {
    staticBound bound ={lowerBound,upperBound,stepSize};

    bool isNew=true;
    for (auto& entry: staticIntervals)
    {
        if (entry.first == signal) {
            isNew=false;
            entry.second.push_back(bound);
        }
    }

    if (isNew) {
        std::vector<staticBound> bounds={bound};
        bounds.push_back(bound);
        staticIntervals.push_back(std::pair<const oms2::SignalRef,std::vector<staticBound>>(signal,bounds));
    }
}

void StepSizeConfiguration::addDynamicValueIndicator(const oms2::SignalRef& signal,const oms2::SignalRef& lower,const oms2::SignalRef& upper,double stepSize)
{
    dynamicBound bound={lower,upper,stepSize};

    bool isNew=true;
    for (auto& entry: dynamicIntervals)
    {
        if (entry.first == signal) {
            isNew=false;
            entry.second.push_back(bound);
        }
    }

    if (isNew) {
        std::vector<dynamicBound> bounds;
        bounds.push_back(bound);
        dynamicIntervals.push_back(std::pair<const oms2::SignalRef,std::vector<dynamicBound>>(signal,bounds));
    }

}