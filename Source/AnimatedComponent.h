/*
  ==============================================================================

    AnimatedComponent.h
    Created: 12 May 2023 7:57:39am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
class AnimatedComponent
:   public juce::Component,
    private juce::Timer
{
public:
    //==============================================================================
    AnimatedComponent();
    
    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;
    
    //==============================================================================
    bool isAnimationDone();
    std::function<float(float)> easingFunction;
    float t = 1.f;     /* you can choose where to start the animation */
    float dt = -0.05f; /* adjust dt to change the animation speed */
    
private:
    //==============================================================================
    void timerCallback() override;
    void step();
    
    const int FPS = 30;
    
    /* the animation can control any value really. for the sake of this example,
     it will control the y position of the component */
    int y;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedComponent)
};
