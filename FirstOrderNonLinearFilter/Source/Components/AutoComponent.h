/*
  ==============================================================================

    AutoComponent.h
    Created: 30 May 2022 2:54:47pm
    Author:  StoneyDSP

  ==============================================================================
*/

#ifndef AUTOCOMPONENT_H_INCLUDED
#define AUTOCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//class FirstOrderNonLinearFilterAudioProcessor;

/*
  ==============================================================================

    Look and Feel.

  ==============================================================================
*/

class AutoComponentLookAndFeel : public juce::LookAndFeel_V4
{
public:
    //==========================================================================
    /** Constructor. */
    AutoComponentLookAndFeel();
    ~AutoComponentLookAndFeel();
};

/*
  ==============================================================================

    Define parameter objects.

  ==============================================================================
*/

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
using ComboBoxAttachment = juce::AudioProcessorValueTreeState::ComboBoxAttachment;
using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

struct SliderWithAttachment
{
    juce::Slider slider;
    std::unique_ptr<SliderAttachment> attachment;
};

struct BoxWithAttachment
{
    juce::ComboBox box;
    std::unique_ptr<ComboBoxAttachment> attachment;
};

struct ButtonWithAttachment
{
    juce::TextButton button;
    std::unique_ptr<ButtonAttachment> attachment;
};

/*
  ==============================================================================

    AutoComponent.

  ==============================================================================
*/

class AutoComponent : public juce::Component
{
public:
    using APVTS = juce::AudioProcessorValueTreeState;
    using Lambda = const std::function<void()>;
    using TextFromVal = const std::function<juce::String(double)>;
    using ValFromText = const std::function<double(juce::String)>;
    //==========================================================================
    /** Constructor. */
    AutoComponent(juce::AudioProcessor& p, APVTS& apvts, Lambda& onValueChange = {}, TextFromVal& textFromValue = {}, ValFromText& valueFromText = {});
    ~AutoComponent();

    //==========================================================================
    /** Component methods. */
    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    //==========================================================================
    /** Instantiate members. */
    juce::AudioProcessor& audioProcessor;

    //Lambda& lambda;
    AutoComponentLookAndFeel lookAndfeel;
    juce::OwnedArray<SliderWithAttachment> sliders;
    juce::OwnedArray<BoxWithAttachment> boxes;
    juce::OwnedArray<ButtonWithAttachment> buttons;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AutoComponent)
};

#endif //AUTOCOMPONENT_H_INCLUDED
