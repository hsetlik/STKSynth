/*
  ==============================================================================

    StkUtil.cpp
    Created: 18 Apr 2021 1:14:20pm
    Author:  Hayden Setlik

  ==============================================================================
*/

#include "StkUtility.h"

void StkUtil::fillBufferFrom(AudioBuffer<float> &buffer, stk::StkFrames &frames, bool checkForResize)
{
    unsigned int juceChannels = buffer.getNumChannels();
    unsigned int juceBufferLength = buffer.getNumSamples();
    if(checkForResize)
    {
        if(juceChannels != frames.channels() || juceBufferLength != frames.frames())
        {
            juceChannels = frames.channels();
            juceBufferLength = frames.frames();
            buffer.setSize((int)juceChannels, (int)juceBufferLength);
        }
    }
    for(int channel = 0; channel < juceChannels; ++channel)
    {
        for(int sample = 0; sample < juceBufferLength; ++sample)
        {
            buffer.setSample(channel, sample, frames((size_t)sample, channel));
        }
    }
}

void StkUtil::fillFramesFrom(stk::StkFrames &frames, AudioBuffer<float>& buffer)
{
    for(auto channel = 0; channel < frames.channels(); ++channel)
    {
        for(auto frame = 0; frame < frames.frames(); ++frame)
        {
            frames((size_t)frame, channel) = buffer.getSample(channel, frame);
        }
    }
}

stk::StkFrames StkUtil::fromBuffer(AudioBuffer<float> &buffer)
{
    auto frames = stk::StkFrames(0.0f, buffer.getNumSamples(), buffer.getNumChannels());
    fillFramesFrom(frames, buffer);
    return frames;
}
