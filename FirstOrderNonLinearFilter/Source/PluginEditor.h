/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Components/AutoComponent.h"

//==============================================================================
/**
*/
class FirstOrderNonLinearFilterAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    using APVTS = juce::AudioProcessorValueTreeState;

    FirstOrderNonLinearFilterAudioProcessorEditor (FirstOrderNonLinearFilterAudioProcessor& p, juce::UndoManager& um);
    ~FirstOrderNonLinearFilterAudioProcessorEditor() override;

    //==============================================================================
    void timerCallback() override;
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstOrderNonLinearFilterAudioProcessor& audioProcessor;
    juce::UndoManager& undoManager;

    AutoComponent subComponents;

    juce::ArrowButton undoButton{ "Undo", 0.5f , juce::Colours::white };
    juce::ArrowButton redoButton{ "Redo", 0.0f , juce::Colours::white };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirstOrderNonLinearFilterAudioProcessorEditor)
};
