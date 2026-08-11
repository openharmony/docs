# Troubleshooting Audio Playback Stuttering and Noise Issues

 <!--Kit: Audio Kit-->
 <!--Subsystem: Multimedia-->
 <!--Owner: @boxwell-->
 <!--Designer: @magekkkk-->
 <!--Tester: @Filger-->
 <!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1fbb3c5295b854c479b5b3f61badd31b93df018d translatedAt=2026-08-06T13:41:39.745Z pushedAt=2026-08-07T02:11:28.601Z -->

When implementing audio playback functionality, you may encounter issues such as stuttering, noise, and audio distortion. This topic describes common causes of playback stuttering and noise, along with troubleshooting methods, and provides reference code examples and a diagnostic workflow.

## Symptom

Common symptoms of stuttering and noise during app playback are as follows:

- Persistent noise during playback.

- Sudden stuttering, audio distortion, or noise during playback.

- Audio distortion or noise at the start or end of playback.

- Audio distortion or noise when seeking to a different position.

## Possible Causes

**1. The audio instance parameters created by the app do not match the actual audio source format.**

   You need to refer to the [supported audio formats](audio-kit-intro.md#supported-audio-formats) of the current system when configuring parameters. If the actual audio source format does not match the specified audio format, unexpected behaviors such as persistent noise and abnormal playback speed may occur.

**2. The audio source data itself is abnormal.**

   In addition to noise and stuttering present in the audio source file itself, abnormal audio source data also includes cases where the app passes data containing noise or stuttering to the system through `audioData` in the `OH_AudioRenderer_OnWriteDataCallback` callback function. Examples include failing to fill `audioData` completely, filling it with dirty data, or filling it with all-zero data.

**3. High system load causes delayed data delivery.**

   Under high system load, processes in the system are scheduled for CPU resources based on their priority. If the app's internal process has a low priority, issues such as delayed data production and delayed data delivery may occur, resulting in stuttering.

**4. Abnormal audio playback instance state.**

   In normal playback scenarios, you are not expected to frequently call APIs such as Start, Stop, or Pause to change the state of the audio instance. Rapid start-stop cycles within a short period (Pause--Start--Pause) or abnormal calls to audio APIs can also cause perceived stuttering.

## Locating Process

Audio data processing typically follows the producer-consumer model: the producer generates audio data and writes it into a shared buffer, while the consumer retrieves data from the buffer as needed for further processing. When the consumer attempts to retrieve data and finds it insufficient, it does not block and wait — to avoid affecting subsequent processes — but instead directly processes silent frames. During playback, intermittent silent frames are perceived as crackling noise, while a large number of silent frames are perceived as stuttering.

Follow the sequence below to troubleshoot step by step. At each step, first confirm an observable result, and then proceed to the next step or jump to the corresponding document based on that result.

1. Verify whether the audio source file itself has any issues.

   The check items are as follows:

   - File format: The system internally supports only Pulse Code Modulation (PCM) audio source data. Verify whether the audio source data passed to the system is in PCM format.

   - File decoding: If you have decoded other audio formats on your own, verify that the decoded data is normal PCM data that is playable and free of noise. You can copy the audio source data to `audioData` in the `OH_AudioRenderer_OnWriteDataCallback` callback function and then write it to a local file to check whether the noise is caused by an abnormal audio source.

   - Parameter configuration: Check whether the sample rate, channel count, sample format, encoding format, and other parameters set during creation are consistent with the actual format of the audio source file.

- Network transmission: Unstable network transmission may cause delayed audio data production on the app client. You can print logs when data is missing to further identify the blocking point.

You can refer to the following example for audio parameter configuration.

   <!-- @[Render_ConfigStream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

   ``` C++
   // Set the audio sample rate.
   // Starting from API version 26.0.0, the audio rendering extension supports sample rate values from 8000 Hz to 384000 Hz in steps of 10 Hz. The supported sample rate specifications vary by device.
   const int SAMPLING_RATE_48K = 48000;
   OH_AudioStreamBuilder_SetSamplingRate(builder, SAMPLING_RATE_48K);
   // Set the audio channel.
   const int channelCount = 2;
   OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
   // Set the audio sample format.
   OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
   // Set the encoding type of the audio stream.
   OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
   // Set the working scenario for the output audio stream.
   OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
   ```

2. Verify the data transmission behavior in the `OH_AudioRenderer_OnWriteDataCallback` callback function.

   The check items are as follows:

   - Callback interval: Audio playback uses streaming transmission. Do not execute time-consuming processing logic in the callback function. It is recommended that a single callback takes no more than 15 ms. In low-latency mode, an even shorter interval is required. A callback that takes too long to return may leave the system with no data to play. It is recommended that you add timestamp recording in complex function logic to observe the actual time consumption of the function in real playback scenarios.

   - Returning zero data: Do not fill `audioData` in the callback function with zero data and return `AUDIO_DATA_CALLBACK_RESULT_VALID` when data is not generated in time. The system treats this as valid audio data and plays it normally, causing perceived stuttering and audio distortion.

   - Not filling data completely: When data is not generated in time and the callback cannot be filled with the required length of data, it is recommended that you return `AUDIO_DATA_CALLBACK_RESULT_INVALID`. The system does not process this audio data and then requests data from the app again. When playback ends and the final audio data is insufficient to fully fill `audioData`, you need to fill the remaining area with silence data. When the audio bit width format is `SAMPLE_FORMAT_U8`, `0x80` is the silence data; for other sample formats, 0 is the silence data. For the bit width formats supported by the system, see [AudioSampleFormat](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosampleformat8).

3. Confirm the current overall system load.

   The check items are as follows:

   The current overall system load is heavy: Confirm whether the current stuttering and noise mainly occur in load scenarios such as foreground/background switching, multiple apps running in the background, or opening the camera. If confirmed, while optimizing the overall processing performance of the app, you can also integrate the [audio workgroup management](audio-workgroup.md) capability, so that the system ensures thread resource allocation meets the expected time requirements.

4. Confirm whether audio APIs are being called abnormally.

    When the play/pause API is called, the system performs fade-out/fade-in processing on the first/last audio frame. You can also optimize the fade-out and fade-in of audio data sent to the system in this scenario to further improve the playback experience.

   The check items are as follows:

   - Rapid short-duration start/stop: When the system quickly responds to an app's start/stop operations, it briefly sends or stops sending valid audio data during the running/paused period as expected, resulting in perceived noise or audio distortion. You can use `OH_AudioRenderer_GetCurrentState` to obtain the current audio stream state to troubleshoot this situation.

   - Calling Pause/Stop immediately after Flush without sending data: Under normal circumstances, when the system receives a Pause or Stop command, it performs fade-out processing on the next frame after the command to reduce perceived noise or audio distortion. If you call Flush first and then immediately call Pause/Stop, the framework has already cleared the buffer due to the Flush command. In this case, there is no buffered data available for the fade-out operation in the Pause/Stop scenario, resulting in a brief truncation noise. It is recommended that you call the Flush API after Pause.

   - Not calling Flush after a seek operation: The system's internal buffer is not cleared until Flush is received. Therefore, after the Pause of the previous seek operation is completed, several frames of buffered data that have been sent to the system but not yet played remain at the lower layer. When seeking to a new position, the previously unplayed buffered data continues to be played, resulting in brief noise. For seek operations, it is recommended that you first call Pause, then call Flush to clear the buffer, and then call Start.

   - The system's fade-in/fade-out operation is not applied to valid data: The current system performs fade-out processing only when the Pause/Stop API is called. If the app does not send data before Pause/Stop is called, causing no data to write, the system fills in silent data. Alternatively, if the last frame of the audio source data is an empty frame and is discontinuous with the preceding valid data, the fade-in/fade-out processing also becomes ineffective.

## References

- For sample code of using OHAudio for playback, refer to [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

- For sample code of using AudioRenderer for playback, refer to [Using AudioRenderer for Audio Playback (ArkTS)](using-audiorenderer-for-playback.md).

- It is recommended that you capture Trace logs for further performance analysis. For details, refer to [Audio Performance Analysis Methods](audio-performance.md#audio-performance-analysis-methods).

- In load scenarios, you can improve the scheduling priority of your app by integrating the [audio workgroup management](audio-workgroup.md) capability, so that the system ensures thread resource allocation meets the expected time requirements.