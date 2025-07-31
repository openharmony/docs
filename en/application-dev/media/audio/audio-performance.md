# Enhancing Audio Performance Experience

During the use of various terminal devices, users have different core performance requirements, such as smoothness, response speed, and power saving, for audio-related features in different scenarios. Typical scenarios include:

- When listening to music or audiobooks, users hope for better power efficiency to extend battery life.
- When playing games, users expect extremely fast response times for button sound effects to enhance immersion.
- When singing karaoke, users desire lower latency for in-ear monitoring to improve singing performance.
- During meetings and voice chats, users want real-time voice transmission for seamless communication.

To meet these audio experience requirements, the system provides a series of audio capabilities through APIs, enabling you to leverage the internal hardware and software capabilities of the system to further enhance the performance of audio playback and recording features in applications.

## Enhancing Performance Through System Capabilities

### Understanding the System Audio Channel

Different performance metrics often cannot be optimized simultaneously due to hardware performance and power limitations. For example, shorter audio response times require faster data processing, which may lead to increased power consumption and a slight degradation in audio quality.

Therefore, the audio channel in the system is not static. To cater to different user scenarios, the system offers a variety of channel options with different focuses: some prioritize power saving, others focus on response speed, and some aim for a balanced approach.

The choice of channels depends on the scenario, but the system cannot directly perceive the specific use case for the audio functionality developed by the application. Therefore, you need to accurately provide the corresponding scenario information through **StreamUsage** and **SourceType**. The system selects the default audio channel configuration based on the scenario for the output or input channel. If the default configuration is insufficient, you can also adjust it through separate settings APIs.

### Low-Latency Audio Playback and Recording

Latency refers to the time it takes for audio data to be processed and transmitted within the system. In playback scenarios, it is the time from when the system receives the data to when the data is output by the hardware. In recording scenarios, it is the time from when the hardware microphone captures the data to when the data is passed to the application through the system interface.

To support low-latency audio scenarios, the system provides a dedicated low-latency audio channel. You need to explicitly set this through API parameters. For details, see [Audio Latency Management](audio-latency.md).

Note that low latency typically uses smaller data buffers and requires higher performance for data processing. You need to optimize the performance of audio data production as much as possible to ensure that data is available for processing in a very short time when the system requests it, avoiding buffer underruns that cause noise. Additionally, to minimize latency, the system simplifies data processing at various phases, which may result in some differences in audio quality when compared with other channels. Therefore, you should decide whether to enable low-latency mode based on the actual functional scenarios of your applications. Scenarios such as game sound effects, karaoke in-ear monitoring, short notification sounds, and instrument simulation are more suitable for low-latency channels.

### Audio Workgroup

The audio workgroup is a set of APIs that help the system identify key audio threads within an application through tagging. By providing key audio threads and workgroup runtime information, the system can ensure healthier operation of audio threads.

The goals of the audio working group are to lower audio latency, avoid audio dropouts, reduce audio distortion, and provide a smoother and more reliable audio playback experience.

When developing audio playback applications, you need to create an audio workgroup first and then periodically inform the system of the workgroup's runtime information. After the operation is completed, it is important to clean up the audio workgroup in a timely manner. For details about the usage and examples of the audio workgroup, see [Audio Workgroup Management](audio-workgroup.md).

### Audio Timestamp and AV Synchronization

Audio timestamps describe the actual playback or capture time of a frame of audio data, typically used to implement playback progress bars and audio-to-video (AV) synchronization features.

Due to the variety of audio hardware device channels, the time information obtained by the system from devices cannot be guaranteed to be accurate. The timestamp calculation process also involves some estimation. Therefore, it is normal for there to be some discrepancy between the timestamp and the actual hardware data time.

For details about the usage of audio timestamps in typical use cases such as AV synchronization, see [AV Synchronization](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-audio-video-synchronization).

## Audio Performance Analysis Methods

During the test of the audio feature in applications, issues such as stuttering and noise that prevent meeting consumer-end data real-time requirements are often difficult to diagnose using general log files. These issues are usually caused by insufficient system performance in certain stages of audio data processing, leading to underruns or overruns.

The following sections provide specific methods for obtaining performance logs and a brief introduction on how to use these logs to identify potential performance issues.

### Performance Logs and Analysis

**Using DevEco Profiler**

DevEco Profiler is a scenario-based tuning tool that helps you analyze performance issues more efficiently. It is integrated into DevEco Studio
and can be used directly during application development. For details about how to use the tool, see [Performance Profiling](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-insight-description-V5).

DevEco Profiler is primarily used for analyzing and optimizing the runtime process of applications. The guide provides detailed steps for analysis, which will not be repeated here.

## Common Performance Issues and Solutions

### Audio Playback Stuttering

Playback stuttering is one of the most common audio performance issues. The causes are diverse, as the audio data production and playback chain is relatively long, and any link in the chain can lead to playback stuttering.

Audio data processing typically uses a producer-consumer model, where the producer generates audio data and writes it to a shared buffer, and the consumer takes data from the buffer as needed for further processing. When the consumer fetches data and finds it insufficient, to avoid affecting subsequent processes, it does not block and wait. Instead, it uses silent frame data for processing. During playback, intermittent silent frames manifest as electrical noise, and a large number of silent frames result in noticeable stuttering.

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
