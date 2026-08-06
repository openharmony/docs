# Enhancing Audio Performance Experience

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4575f288d13c429dbede3c0b33d0bfd71bcb7755 translatedAt=2026-08-06T10:45:18.762Z pushedAt=2026-08-06T10:54:38.262Z -->

During the use of various terminal devices, users have different core performance requirements, such as smoothness, response speed, and power saving, for audio-related features in different scenarios. Typical scenarios include:

- When listening to music or audiobooks, users hope for better power efficiency to extend battery life.

- When playing games, users expect extremely fast response times for button sound effects to enhance immersion.

- When singing karaoke, users desire lower latency for in-ear monitoring to improve singing performance.

- During meetings and voice chats, users want real-time voice transmission for seamless communication.

To meet these audio experience requirements, the system provides a series of audio capabilities through APIs, enabling you to leverage the internal hardware and software capabilities of the system to further enhance the performance of audio playback and recording features in applications.

## Enhancing Performance Through System Capabilities

### Understanding the System Audio Channel

Different performance metrics often cannot be optimized simultaneously due to hardware performance and power limitations. For example, shorter audio response times require faster data processing, which leads to increased power consumption and partial loss of certain effects.

Therefore, the audio channel in the system is not static. To cater to different user scenarios, the system offers a variety of channel options with different focuses: some prioritize power saving, others emphasize response speed, and still others strike a relative balance.

The system cannot directly perceive the specific use case for the audio functionality developed by the application. Therefore, you should specify [StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage) and [SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) to provide the corresponding scenario information. The system selects the default audio channel configuration based on the scenario for the output or input channel. If the default configuration is insufficient, you can also adjust it through separate settings APIs.

### Low-Latency Audio Playback and Recording

Latency refers to the time it takes for audio data to be processed and transmitted within the system. In playback scenarios, it is the time from when the system receives the data until the data is output by the hardware. In recording scenarios, it is the time from when the hardware microphone captures the data until the application receives the captured data.

To support low-latency audio scenarios, the system provides a dedicated low-latency audio path. You need to explicitly set it through API parameters. For details, please refer to [Low-Latency Audio Playback (C/C++)](audio-fast-playback.md) and [Low-Latency Audio Recording (C/C++)](audio-fast-recording.md).

Note that low latency typically uses smaller data buffers and requires higher performance for data processing. You need to optimize the performance of audio data production as much as possible to ensure that data is available for processing in a very short time when the system requests it, avoiding buffer underruns that cause noise. Additionally, to minimize latency, the system simplifies data processing at various phases, which may result in some differences in audio quality when compared with other channels. Therefore, you should decide whether to enable low-latency mode based on the actual functional scenarios of your applications. Scenarios such as game sound effects, karaoke in-ear monitoring, short notification sounds, and instrument simulation are more suitable for low-latency channels.

### Audio Workgroup

The audio workgroup is a set of APIs that help the system identify key audio threads within an application through tagging. By providing key audio threads and workgroup runtime information, the system can ensure healthier operation of audio threads.

The goals of the audio working group are to lower audio latency, avoid audio dropouts, reduce audio distortion, and provide a smoother and more reliable audio playback experience.

When developing audio playback applications, you need to create an audio workgroup first and then periodically inform the system of the workgroup's runtime information. After the operation is completed, it is important to clean up the audio workgroup in a timely manner. For more usage examples of audio workgroups, see [Audio Workgroup Management](audio-workgroup.md).

### Audio Timestamp and AV Synchronization

Audio timestamps describe the actual playback or capture time of a frame of audio data, typically used to implement playback progress bars and audio-to-video (AV) synchronization features.

Due to the variety of audio hardware device channels, the time information obtained by the system from devices cannot be guaranteed to be accurate. The timestamp calculation process also involves some estimation. Therefore, it is normal for there to be some discrepancy between the timestamp and the actual hardware data time.

A typical use case is audio-video synchronization.

## Audio Performance Analysis Methods

When you test the audio functionality of your app and encounter issues such as stuttering or noise that fail to meet the real-time data requirements on the consumer side, general logs are usually insufficient for locating these problems. This is because such issues are typically caused by insufficient system performance in certain links of the audio data processing chain, resulting in underrun or overrun.

The following sections provide specific methods for obtaining performance logs and a brief introduction on how to use these logs to identify potential performance issues.

### Performance Logs and Analysis

**Using DevEco Profiler**

DevEco Profiler is a scenario-based tuning tool that helps you analyze performance issues more efficiently. Integrated into DevEco Studio, it can be used directly during application development.

For details about how to use the tool, see [Understanding Performance Optimization](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-description).

DevEco Profiler is primarily used for analyzing and optimizing the runtime process of applications. The guide provides detailed steps for analysis, which will not be repeated here.

**Using HiSmartPerf**

HiSmartPerf is a standalone performance tuning tool used to collect system, CPU, and GPU performance data during a test period.

It presents the data through a visual interface, making it easier for you to analyze the performance of your applications and identify the causes of performance issues, which can then be used as a basis for in-depth performance optimization to make the application run more smoothly.

This section describes how to use HiSmartPerf to analyze audio playback scenarios.

1. Enter the CPU trace mode.

   Open the HiSmartPerf tool and navigate to the **CPU Trace** page for game performance analysis. Although titled for game performance analysis, the tool is not limited to game scenarios.

2. Configure capture.

   The main configuration items include the data file name, buffer capacity, maximum file size, data items, and capture duration. To capture system audio-related data items, select **zaudio**. The capture duration can be adjusted according to the test scenario. Note that the test duration and the number of selected data items will affect the file size and often need to be adjusted simultaneously.

3. Start capture.

   After the capture is complete, a message is displayed, indicating that the file is sent back. If the file is large, wait patiently.

4. View the trace information.

   View the CPU performance analysis results during the capture period.

5. Locate the audio data processing thread.

   For audio playback services, you can search for the location where the test application inputs playback data to the system using **OnWriteData**, and further analyze the performance of the data production source.

    Runnable indicates that a thread is waiting for scheduling. If data fails to be written in time due to an excessively long Runnable state — including the app's own data production thread — consider joining the audio workflow group to raise the thread priority and ensure CPU resource allocation.

    In CPU Usage, you can view the CPU usage of each task.

    After identifying the cause of the issue from the trace, you can optimize the performance by referring to [Common Performance Issues and Solutions](#common-performance-issues-and-solutions).

## Common Performance Issues and Solutions

### Audio Playback Stuttering

Playback stuttering is one of the most common audio performance issues. The causes are diverse, as the audio data production and playback chain is relatively long, and any link in the chain can lead to playback stuttering.

Audio data processing typically follows the producer-consumer model: the producer generates audio data and writes it into a shared buffer, while the consumer retrieves data from the buffer as needed for further processing. When the consumer attempts to retrieve data and finds it insufficient, it does not block and wait — to avoid affecting subsequent processes — but instead directly processes silent frames. During playback, intermittent silent frames are perceived as crackling noise, while a large number of silent frames are perceived as stuttering.

To diagnose such issues, start from the consumer side and analyze layer by layer upwards. If a buffer layer has silent frames, it is likely due to untimely production in the previous layer. Common causes of untimely data production and their solutions include:

- Network transmission issues: Unstable network transmission can lead to untimely audio data production. Consider pausing playback and resuming when enough playable data is available.

- Excessive data processing complexity: In real-time audio playback scenarios, if data algorithm processing takes too long, the consumer may not be able to fetch data in time. Consider optimizing the algorithm and increasing the buffer size to cover the processing time, although this will increase latency.

- Insufficient thread processing performance: In high-load scenarios or when audio data processing runs concurrently with other tasks, system resource supply may be insufficient, leading to untimely audio data production. While optimizing the overall application performance, you can also integrate the audio workgroup capability to ensure thread resource allocation meets the expected time requirements.

### Noise During Audio Playback Pause and Seek

Issues arising from pausing and seeking are due to the truncated waveform at the end of audio playback. When the audio output hardware plays such a waveform, brief noise may occur.

The system optimizes when the playback pause API is called, but you can also optimize the audio data sent to the system by implementing fade-in and fade-out in these scenarios to further enhance the playback experience.

### High Audio Playback Latency

High audio playback latency is usually due to lengthy data processing or overly large buffer settings.

For latency-sensitive audio scenarios, avoid excessive data preprocessing. Use the system's low-latency mode for playback. For notification sounds, consider using [SoundPool](../../reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md).

### AV Synchronization Issues

There are two common causes of AV synchronization issues: incorrect timestamp usage and excessive output latency. Analyze the specific situation, especially the relative speeds of audio and video, to identify the root cause.