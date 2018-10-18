#include "StepSizeConfiguration.h"
#include "SignalRef.h"
#include "Logging.h"

StepSizeConfiguration::StepSizeConfiguration() :minimalStepSize(1.0e-2), maximalStepSize(1.0e-2) {};

StepSizeConfiguration::~StepSizeConfiguration() {};

void StepSizeConfiguration::addEventIndicator(const oms2::SignalRef& signal) {
    eventIndicators.push_back(signal);
}