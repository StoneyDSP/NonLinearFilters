/*
  ==============================================================================

    PluginWrapper.h
    Created: 8 May 2022 9:38:17pm
    Author:  StoneyDSP

  ==============================================================================
*/

#pragma once

#ifndef PLUGINWRAPPER_H_INCLUDED
#define PLUGINWRAPPER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Modules/FirstOrderNLFilter.h"

class FirstOrderNonLinearFilterAudioProcessor;

template <typename SampleType>
class ProcessWrapper
{
public:
    //==========================================================================
    /** Constructor. */
    ProcessWrapper(FirstOrderNonLinearFilterAudioProcessor& p);

    //==========================================================================
    /** Initialises the processor. */
    void prepare(juce::dsp::ProcessSpec& spec);

    /** Resets the internal state variables of the processor. */
    void reset();

    //==========================================================================
    void process(juce::AudioBuffer<SampleType>& buffer, juce::MidiBuffer& midiMessages);

    //==========================================================================
    /** Updates the internal state variables of the processor. */
    void update();

private:
    //==========================================================================
    // This reference is provided as a quick way for the wrapper to
    // access the processor object that created it.
    FirstOrderNonLinearFilterAudioProcessor& audioProcessor;

    //==========================================================================
    /** Instantiate objects. */
    juce::dsp::DryWetMixer<SampleType> mixer;
    FirstOrderNLfilter<SampleType> filter;
    juce::dsp::Gain<SampleType> driveUp, driveDn, output;

    //==========================================================================
    /** Parameter pointers. */
    juce::AudioParameterFloat* frequencyPtr{ nullptr };
    juce::AudioParameterFloat* gainPtr{ nullptr };
    juce::AudioParameterChoice* typePtr{ nullptr };
    juce::AudioParameterChoice* linearityPtr{ nullptr };
    juce::AudioParameterFloat* outputPtr{ nullptr };
    juce::AudioParameterFloat* mixPtr{ nullptr };
    juce::AudioParameterFloat* drivePtr{ nullptr };

    //==========================================================================
    /** Init variables. */

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProcessWrapper)
};

#endif //  PLUGINWRAPPER_H_INCLUDED