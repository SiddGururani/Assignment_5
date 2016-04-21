/*
  ==============================================================================

    MeterComponent.h
    Created: 19 Apr 2016 11:54:38am
    Author:  Ashis Pati

  ==============================================================================
*/

#ifndef METERCOMPONENT_H_INCLUDED
#define METERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "ErrorDef.h"

class MeterComponent    : public Component
{
public:
    MeterComponent();
    ~MeterComponent();

    void paint (Graphics&);
    void resized();
    
    Error_t setValue(float value_to_set);

private:
    float _peak_meter_value;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterComponent)
};


#endif  // METERCOMPONENT_H_INCLUDED
