#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    /* references */
    /* https://youtu.be/YJB1QnEmlTs */
    /* https://easings.net/ */
    /* https://iquilezles.org/articles/functions/ */
    
    /* change the easing function for a new animation */
    
    a1.easingFunction = [](float t) {
        return t < 0.5f ? 8 * t * t * t * t : 1 - std::pow(-2 * t + 2, 4) / 2.f;
    };
    
    a2.easingFunction = [](float x) {
        return std::sqrt(1.f - std::pow(x - 1.f, 2));
    };
    
    a3.easingFunction = [](float x) {
        float c1 = 1.70158f;
        float c2 = c1 * 1.525f;

        return x < 0.5f
          ? (std::pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2.f
          : (std::pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2.f;
    };
    
    addAndMakeVisible(a1);
    addAndMakeVisible(a2);
    addAndMakeVisible(a3);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    a1.setBounds(0, 0, getWidth() / 3.f, getHeight());
    a2.setBounds(a1.getRight(), 0, getWidth() / 3.f, getHeight());
    a3.setBounds(a2.getRight(), 0, getWidth() / 3.f, getHeight());
}
