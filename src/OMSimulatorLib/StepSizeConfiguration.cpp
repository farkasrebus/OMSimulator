#include "StepSizeConfiguration.h"
#include "SignalRef.h"
#include "Logging.h"

StepSizeConfiguration::StepSizeConfiguration(const oms2::SignalRef& var) :critical(new oms2::SignalRef(var)) {
};

StepSizeConfiguration::~StepSizeConfiguration() {
    delete critical;
};

oms2::SignalRef* StepSizeConfiguration::getCriticalVariable() {
    return critical;
}
