# Audio/Video Overview


OpenHarmony multimedia services help you to develop audio and video playback and recording.


- The media playback module facilitates the development of audio and video playback, including media file and stream playback, volume control, and playback progress control.

- The media recording module supports the development of audio and video recording and provides functions to set the size of captured video, encoding bit rate, encoder type, video frame rate, audio sampling rate, and output file format.


## Basic Concepts

It is considered good practice that you understand the following concepts before starting development:

- Streaming media technology

  The streaming media technology refers to a process to encode continuous video and audio data and store the data on a network server. A viewer can watch and listen to the video and audio during download with no need to wait for the completion of download.

- Video frame rate
  
  The frame rate is used to measure the number of displayed frames, which is the number of images transmitted per second. The more frames per second (FPS), the smoother the video.

- Bit rate

  Bit rate is the number of bits transmitted per unit of time. The commonly used unit is kbit/s.

- Sampling rate

  The sampling rate is the number of samples per second taken from continuous signals to form discrete signals. The unit is hertz (Hz).


## Codec Specifications

Available audio and video codecs vary depending on device types. The following table lists supported specifications for available development boards.

**Table 1** Codec specifications for different development boards

| Device Type| Development Board| Decoding| Encoding|
| -------- | -------- | -------- | -------- |
| Cameras with a screen| Hi3516 | - Audio: MPEG-4 AAC Profile (AAC LC), mono and dual channels, MPEG-4 (.mp4 and .m4a) <br>- Video: The H.265 (HEVC) and H.264 (AVC) (for streams encoded using a chip of the same type) and the MPEG-4 (.mp4) container format are supported.| - Audio: AAC-LC encoding, mono and dual channels, and the MPEG-4 (.mp4) container format are supported.<br>- Video: H.264 and H.265 encoding and the MPEG-4 (.mp4) container format are supported.|
| Cameras without a screen| Hi3518 | - Audio: MPEG-4 AAC Profile (AAC LC), mono and dual channels, and the MPEG-4 (.mp4 and .m4a) container format are supported.<br>- Video: none| - Audio: AAC-LC encoding, mono and dual channels, and the MPEG-4 (.mp4) container format are supported.<br>- Video: H.264 and H.265 encoding and the MPEG-4 (.mp4) container format are supported.|
| WLAN connecting devices| Hi3861 | N/A| N/A|

For details about the codec specifications of Hi3516 and Hi3518, refer to their documentation.
