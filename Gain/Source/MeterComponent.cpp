/*
  ==============================================================================

    MeterComponent.cpp
    Created: 19 Apr 2016 11:54:38am
    Author:  Ashis Pati

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MeterComponent.h"

MeterComponent::MeterComponent() {
    _peak_meter_value = 0;
}

MeterComponent::~MeterComponent() {
}

void MeterComponent::paint (Graphics& g) {
    g.fillAll (Colours::black);
    if (_peak_meter_value > -12) {
		if (_peak_meter_value >= 0)
			g.setColour(Colours::red);
		else
			g.setColour(Colours::green);
        int position_x = 0;
        int position_y = getHeight() * (- _peak_meter_value / 12);
        int width = getWidth();
        int height = getHeight() - position_y;
        //g.drawRect(position_x, position_y, width, height);
        g.fillRect(position_x, position_y, width, height);
    }
}

void MeterComponent::resized() {
}


Error_t MeterComponent::setValue(float value_to_set) {
    if (value_to_set < 0) {
        return kFunctionInvalidArgsError;
    }
    else if (value_to_set > 1) {
        _peak_meter_value = 0;
    }
    else {
        _peak_meter_value = 20*log10f(value_to_set);
    }
    repaint();
    
    return kNoError;

}