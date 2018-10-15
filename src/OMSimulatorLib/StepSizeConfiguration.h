#ifndef _OMS_STEP_SIZE_CONFIGURATION_H_
#define _OMS_STEP_SIZE_CONFIGURATION_H_

#include "Variable.h"

#include <vector>

class ValueIndicator;

class StepSizeConfiguration {
    public:
        StepSizeConfiguration();
        ~StepSizeConfiguration();

        //TODO: add functions, get functions, etc

    private:
        std::vector<oms2::Variable> eventVariables;
        std::vector<oms2::Variable> timeIndicators;
        std::vector<ValueIndicator> valueIndicators;
        
};

//TODO: this is an ugly part
class ValueIndicator {
    public:
        oms2::Variable getVariable() {return var};
        virtual getStepSize(double value)=0;

    protected:
        oms2::Variable var;
};

class StaticIntervalValueIndicator : protected ValueIndicator {
    //TODO: static interval model
};

class DynamicHysteresisValueIndicator : protected ValueIndicator {
    //TODO: dynamic band model
};

#endif