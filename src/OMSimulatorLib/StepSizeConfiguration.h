#ifndef _OMS_STEP_SIZE_CONFIGURATION_H_
#define _OMS_STEP_SIZE_CONFIGURATION_H_

#include "SignalRef.h"

#include <vector>

class ValueIndicator;

class StepSizeConfiguration {
    public:
        StepSizeConfiguration();
        ~StepSizeConfiguration();

        void setMinimalStepSize(double min) {minimalStepSize=min;};
        double getMinimalStepSize() {return minimalStepSize;};
        void setMaximalStepSize(double max) {maximalStepSize=max;};
        double getMaximalStepSize() {return maximalStepSize;};
        void addEventIndicator(const oms2::SignalRef& signal);
        std::vector<oms2::SignalRef> getEventIndicators() {return eventIndicators;};
        void addTimeIndicator(const oms2::SignalRef& signal);
        std::vector<oms2::SignalRef> getTimeIndicators() {return timeIndicators;};
    /*    void addTimeIndicator(oms2::Variable var);
        std::vector<oms2::Variable> getTimeIndicators();
        void addStaticValueIndicator(oms2::Variable var,double lower,double upper, double stepSize);
        //TODO: getFunction
        //TODO: same for dynamic stuff
    */
    private:
        double minimalStepSize;
        double maximalStepSize;
        std::vector<oms2::SignalRef> eventIndicators;
        std::vector<oms2::SignalRef> timeIndicators;
        //std::vector<StaticValueIndicator> staticValueIndicators;
        //std::vector<DynamicValueIndicator> dynamicValueIndicators;
};

/*class StaticValueIndicator {
    public:
        oms2::Variable getVariable() {return var};//TODO: make this a vector
        virtual double getStepSize(double value)=0;//TODO: make parameter a map

    private:
        oms2::Variable var;
};

/*class DynamicValueIndicator {
    public:
        oms2::Variable getVariable() {return var};//TODO: make this a vector
        virtual double getStepSize(double value)=0;//TODO: make parameter a map

    private:
        oms2::Variable var;
};*/

#endif