# Audio Overview

You can use APIs provided by the audio module to implement audio-related features, including audio playback and volume management.

## Basic Concepts

- **Sampling**
  Sampling is a process to obtain discrete-time signals by extracting samples from analog signals in a continuous time domain at a specific interval.

- **Sampling rate**
  Sampling rate is the number of samples extracted from a continuous signal per second to form a discrete signal. It is measured in Hz. Generally, human hearing range is from 20 Hz to 20 kHz. Common audio sampling rates include 8 kHz, 11.025 kHz, 22.05 kHz, 16 kHz, 37.8 kHz, 44.1 kHz, 48 kHz, 96 kHz, and 192 kHz.

- **Channel**
  Channels refer to different spatial positions where independent audio signals are recorded or played. The number of channels is the number of audio sources used during audio recording, or the number of speakers used for audio playback.

- **Audio frame**
  Audio data is in stream form. For the convenience of audio algorithm processing and transmission, it is generally agreed that a data amount in a unit of 2.5 to 60 milliseconds is one audio frame. This unit is called sampling time, and its length is specific to codecs and the application requirements.

- **PCM**<br>
  Pulse code modulation (PCM) is a method used to digitally represent sampled analog signals. It converts continuous-time analog signals into discrete-time digital signal samples.
