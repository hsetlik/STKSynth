/*
  ==============================================================================

    StkUtility.h
    Created: 18 Apr 2021 1:12:14pm
    Author:  Hayden Setlik

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace StkUtil {

//! Loads data from an \c StkFrames object into a \c JUCE::AudioBuffer object and returns the buffer reference
static void fillBufferFrom(AudioBuffer<float>& buffer, stk::StkFrames& frames, bool checkForResize=true);
static void fillFramesFrom(stk::StkFrames& frames, AudioBuffer<float>& buffer);
static stk::StkFrames fromBuffer(AudioBuffer<float>& buffer);

}
