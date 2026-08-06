# Low-Power Audio Playback

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=233316920aae5dc32b6b09f705ac05617f921672 translatedAt=2026-08-06T01:51:05.280Z pushedAt=2026-08-06T11:35:00.212Z -->

Starting from API version 11, low-power audio playback is available.

Low-power audio playback is an audio rendering solution implemented through software-hardware co-design. Its core mechanism is to enlarge the internal buffer of the audio renderer, allowing the system to fill a large amount of audio data at once. This enables the main processor to stay in sleep mode for extended periods, reducing the power consumption caused by frequent audio data processing and significantly lowering the system-level power load.

## Prerequisites

Currently, the low-power feature is supported for speakers, wired headsets, and some Bluetooth headsets.

## Development Guidelines

The low-power audio renderer uses the same APIs as the standard audio renderer, but you need to pay attention to the app data cycle and playback progress. For details about using the audio renderer, see [Using AudioRenderer for Audio Playback (ArkTS)](using-audiorenderer-for-playback.md) and [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

**Data cycle diagram**

![power-saving-data-period](figures/power-saving-data-period.png)

During the data cycle, when data is quickly requested to fill the buffer, the system enters a sleep state. When the buffer data is consumed, the next cycle is triggered.

**Playback progress diagram**

![power-saving-data-progress](figures/power-saving-data-progress.png)

During the data cycle, when data is quickly requested to fill the buffer, playback progress is calculated based on the actual playback amount. When the buffer data is consumed (for example, playback progress reaches the amount of data written), the next cycle is triggered.

### Precautions

1. For stream types using [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), [STREAM_USAGE_AUDIOBOOK](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), [AUDIOSTREAM_USAGE_MUSIC](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage), or [AUDIOSTREAM_USAGE_AUDIOBOOK](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage), the low-power renderer is used by default.

2. Low-power renderer buffer: up to 1000 ms in screen-on scenarios; up to 10000 ms in screen-off scenarios. The main processor is woken up when the buffer data is consumed, triggering the app to deliver data. The data delivery cycle matches the buffer size.

    > - It is normal for the app not to request data within the data cycle. There is no need to stop the stream. The system automatically determines when data has not been received for an extended period and stops the stream. When the app sends data again, the system resumes the stream state.
    > - In screen-off scenarios, the main processor enters sleep mode after the data buffer is full, and the app enters a suspended state. If you need background playback or screen-off playback, see [Development Precautions for Background Playback](audio-playback-overview.md#development-precautions-for-background-playback).
    > - For the low-power renderer, you are advised to fill the buffer completely at once to reduce the number of wake-ups. If the app cannot provide data quickly enough, it will fall back to the standard renderer. If the standard renderer cannot ensure data timeliness, you need to optimize data processing in the app.
    > - When the app data is less than one callback length, do not fill empty data to avoid playback stuttering (except when reaching EOS). You are advised to wait until sufficient data is available or return an error code. For details, see [AudioRenderer audio data callback](using-audiorenderer-for-playback.md#how-to-develop) and [OHAudio audio data callback](using-ohaudio-for-playback.md#how-to-develop).

3. Low-power renderers and low-latency renderers do not support concurrency, following the first-come, first-served principle, meaning the first one to start takes effect, and the later one is downgraded to a regular renderer. Specific examples are as follows:

    >- If low-power renderer A is started first, followed by low-power renderer B, then B is downgraded to a regular renderer.
    >- If a low-power renderer is started first, followed by a low-latency renderer, then the low-latency renderer is downgraded to a regular renderer.
    >- If a low-latency renderer is started first, followed by a low-power renderer, then the low-power renderer is downgraded to a regular renderer.

4. Writing application data does not mean that the playback is complete. You need to call [getAudioTimestampInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#getaudiotimestampinfo19) or [OH_AudioRenderer_GetAudioTimestampInfo()](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_getaudiotimestampinfo) to obtain the audio timestamp to determine the actual playback progress.

    > - You are advised to call the timestamp API at intervals greater than 200 ms to avoid affecting system performance.
    > - After the app calls [flush](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#flush11) or [OH_AudioRenderer_Flush()](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_flush), the amount of played data is reset to 0.
    > - The amount of played data is always less than the amount of written data. Due to the system frame length and latency mechanism, the amount of played data does not equal the amount of written data.
    > - After writing data, obtain the timestamp. If the timestamp remains unchanged for two cycles, playback is complete. Alternatively, calculate the remaining playback duration based on the configured playback speed. If the corresponding duration has elapsed, playback is complete. (For example, let the total amount of written data be p<sub>1</sub>, the timestamp obtained after writing be p<sub>2</sub>, the configured playback speed be α where α>0, and the audio sampling rate be f<sub>s</sub> where f<sub>s</sub>>0. The remaining playable duration is t. Formula: ![formula_not_played_data_length](figures/formula_not_played_data_length.png))