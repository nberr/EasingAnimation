/*
  ==============================================================================

    AnimatedComponent.cpp
    Created: 12 May 2023 7:57:39am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#include "AnimatedComponent.h"

//==============================================================================
AnimatedComponent::AnimatedComponent()
{
    
}

//==============================================================================
void AnimatedComponent::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::green);
    g.drawRect(getLocalBounds());
    
    g.setColour(juce::Colours::red);
    g.fillRect(getLocalBounds().withY(y));
}

void AnimatedComponent::resized()
{
    y = getHeight();
}

void AnimatedComponent::mouseEnter(const juce::MouseEvent& event)
{
    /* only start the timer if needed */
    if (!isTimerRunning()) {
        startTimerHz(FPS);
    }
    
    /* reverse the step direction if needed */
    if (dt > 0) {
        dt = -dt;
    }
}

void AnimatedComponent::mouseExit(const juce::MouseEvent& event)
{
    /* only start the timer if needed */
    if (!isTimerRunning()) {
        startTimerHz(FPS);
    }
    
    /* reverse the step direction if needed */
    if (dt < 0) {
        dt = -dt;
    }
}

//==============================================================================
bool AnimatedComponent::isAnimationDone()
{
    return t == 0.f || t == 1.f;
}

//==============================================================================
void AnimatedComponent::timerCallback()
{
    step();
    repaint();
    
    if (isAnimationDone()) {
        stopTimer();
    }
}

void AnimatedComponent::step()
{
    /* calculations necessary for the animation */
        
    /* calculate change in time but snap it to 0 or 1 if it's out of bounds */
    t += dt;
    t = juce::jmin(1.f, juce::jmax(t, 0.f));
    
    /* check to make sure the easing function has been set */
    jassert(easingFunction != nullptr);
    
    /* get the next value */
    float easing_value = easingFunction(t);
    
    y = getHeight() * easing_value;
}
