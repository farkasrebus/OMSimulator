#ifndef _OMS_STEP_SIZE_CONFIGURATION_H_
#define _OMS_STEP_SIZE_CONFIGURATION_H_

#include "SignalRef.h"

#include <vector>

class ValueIndicator;

class StepSizeConfiguration {
    public:
        StepSizeConfiguration(const oms2::SignalRef& var);
        ~StepSizeConfiguration();

        const oms2::SignalRef* getCriticalVariable() {return critical;};
    /*
        void addEventIndicator(oms2::Variable var);
        std::vector<oms2::Variable> getEventIndicators();
        void addTimeIndicator(oms2::Variable var);
        std::vector<oms2::Variable> getTimeIndicators();
        void addStaticValueIndicator(oms2::Variable var,double lower,double upper, double stepSize);
        //TODO: getFunction
        //TODO: same for dynamic stuff
    */
    private:
       /* std::vector<oms2::Variable> eventVariables;
        std::vector<oms2::Variable> timeIndicators;
        std::vector<ValueIndicator> valueIndicators;*/
        const oms2::SignalRef* critical;
        
};
/*
//TODO: this is an ugly part
class ValueIndicator {
    public:
        oms2::Variable getVariable() {return var};//TODO: make this a vector
        virtual double getStepSize(double value)=0;//TODO: make parameter a map

    protected:
        oms2::Variable var;
};

//TODO: make it nicer
struct IntervalEntry {
    double lower;
    double upper;
    double stepSize;
}

class StaticIntervalValueIndicator : protected ValueIndicator {
    public:
        oms2::Variable getVariable() {return var};
        double getStepSize(double value);
    
    private:
        std::vector<IntervalEntry> intervals;
};

//TODO: Add possibility for dynamic stuff
/*class DynamicIntervalValueIndicator : protected ValueIndicator {
    public:
        oms2::Variable getVariable() {return var};
        double getStepSize(double value);

    private:
        
};*/

#endif