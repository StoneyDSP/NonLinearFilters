/*
  ==============================================================================

    PluginParameters.h
    Created: 29 May 2022 7:58:00pm
    Author:  Nathan J. Hood

  ==============================================================================
*/

#pragma once

#ifndef PLUGINPARAMETERS_H_INCLUDED
#define PLUGINPARAMETERS_H_INCLUDED

#include <JuceHeader.h>

class SecondOrderNonLinearFilterAudioProcessor;

class Parameters
{
public:
    using APVTS = juce::AudioProcessorValueTreeState;
    using Params = juce::AudioProcessorValueTreeState::ParameterLayout;
    //==========================================================================
    /** Constructor. */
    Parameters(SecondOrderNonLinearFilterAudioProcessor& p);

    //==========================================================================
    /** Create Parameter Layout. */
    static void setParameterLayout(Params& params);

private:
    //==========================================================================
    // This reference is provided as a quick way for the wrapper to
    // access the processor object that created it.
    SecondOrderNonLinearFilterAudioProcessor& audioProcessor;
    APVTS& state;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameters)
};

#endif //PLUGINPARAMETERS_H_INCLUDED