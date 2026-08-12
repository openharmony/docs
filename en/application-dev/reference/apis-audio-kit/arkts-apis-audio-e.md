# Enums
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AudioVolumeType

Enumerates the audio volume types.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | Audio stream for voice calls.|
| RINGTONE                     | 2      | Audio stream for ringtones.    |
| MEDIA                        | 3      | Audio stream for media purpose.    |
| ALARM<sup>10+</sup>          | 4      | Audio stream for alarming.    |
| ACCESSIBILITY<sup>10+</sup>  | 5      | Audio stream for accessibility.  |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | Audio stream for voice assistant.|

## InterruptMode<sup>9+</sup>

Enumerates the audio interruption modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| SHARE_MODE                   | 0      | Shared mode.|
| INDEPENDENT_MODE             | 1      | Independent mode.|

## DeviceFlag

Enumerates the audio device flags.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |---------------------------|
| OUTPUT_DEVICES_FLAG             | 1      | Output device.                    |
| INPUT_DEVICES_FLAG              | 2      | Input device.                    |
| ALL_DEVICES_FLAG                | 3      | All devices.                    |

## DeviceUsage<sup>12+</sup>

Enumerates the audio device types by usage.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |---------------------------|
| MEDIA_OUTPUT_DEVICES | 1      | Media output device.|
| MEDIA_INPUT_DEVICES  | 2      | Media input device.|
| ALL_MEDIA_DEVICES    | 3      | All media devices.|
| CALL_OUTPUT_DEVICES  | 4      | Call output device.|
| CALL_INPUT_DEVICES   | 8      | Call input device.|
| ALL_CALL_DEVICES     | 12     | All call devices.|

## DeviceRole

Enumerates the device roles.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name         |  Value   | Description          |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | Input role.|
| OUTPUT_DEVICE | 2      | Output role.|

## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                | Value    | Description                                                     |
| ---------------------| ------ | --------------------------------------------------------- |
| INVALID              | 0      | Invalid device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| EARPIECE             | 1      | Earpiece.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEAKER              | 2      | Speaker.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| WIRED_HEADSET        | 3      | Wired headset with a microphone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| WIRED_HEADPHONES     | 4      | Wired headset without a microphone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| BLUETOOTH_SCO        | 7      | Bluetooth device using Synchronous Connection Oriented (SCO) links.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| BLUETOOTH_A2DP       | 8      | Bluetooth device using Advanced Audio Distribution Profile (A2DP) links.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MIC                  | 15     | Microphone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| USB_HEADSET          | 22     | USB headset.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| DISPLAY_PORT<sup>12+</sup>        | 23     | Display port (DP), which is used to connect to external devices.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| REMOTE_CAST<sup>12+</sup>        | 24     | Remote cast device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| USB_DEVICE<sup>18+</sup>        | 25 | USB device (excluding USB headsets).          |
| HDMI<sup>19+</sup>        | 27 | HDMI device (such as HDMI, ARC, and eARC).          |
| LINE_DIGITAL<sup>19+</sup>        | 28 | Wired digital device (such as S/PDIF)          |
| REMOTE_DAUDIO<sup>18+</sup>        | 29 | Distributed device.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| HEARING_AID<sup>20+</sup>        | 30 | Hearing aid device.|
| NEARLINK<sup>20+</sup>        | 31 | NearLink device.|
| SYSTEM_PRIVATE<sup>22+</sup> | 200 | System private device. (This device is a private device within the system, and applications can ignore it.)|
| DEFAULT<sup>9+</sup> | 1000   | Default device type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## BluetoothAndNearlinkPreferredRecordCategory<sup>21+</sup>

Enumerates the preferred device categories available for recording with Bluetooth or NearLink.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                | Value    | Description                                                     |
| ---------------------| ------ | --------------------------------------------------------- |
| PREFERRED_NONE  | 0      | No specific device preference.|
| PREFERRED_DEFAULT | 1      | Prefers using Bluetooth or NearLink devices for recording; whether to use low-latency or high-quality recording depends on the system.|
| PREFERRED_LOW_LATENCY  | 2      | Prefers using Bluetooth or NearLink devices in low-latency mode for recording.|
| PREFERRED_HIGH_QUALITY | 3      | Prefers using Bluetooth or NearLink devices in high-quality mode for recording.|

## NoiseReductionMode

Enumerates the recording noise reduction modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name| Value| Description|
| :--- | :--- | :--- |
| FIDELITY | 0 | Fidelity mode, with no noise reduction applied.|
| PURE_VOCALS | 1 | Pure vocals mode, with strong noise reduction.|
| STANDARD | 2 | Standard mode, with weak noise reduction.|

## CommunicationDeviceType<sup>9+</sup>

Enumerates the device types used for communication.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name         | Value    | Description         |
| ------------- | ------ | -------------|
| SPEAKER       | 2      | Speaker.     |

## AudioRingMode

Enumerates the audio ring modes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Device behavior difference**: If this API is set to the vibration mode on a device without a vibration component, no vibration effect is generated.

| Name               |  Value   | Description      |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | Silent mode.|
| RINGER_MODE_VIBRATE | 1      | Vibration mode.|
| RINGER_MODE_NORMAL  | 2      | Normal mode.|

## AudioSampleFormat<sup>8+</sup>

Enumerates the audio sample formats.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                               |  Value   | Description                      |
| ---------------------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID              | -1     | Invalid format.                |
| SAMPLE_FORMAT_U8                   | 0      | Unsigned 8-bit integer.           |
| SAMPLE_FORMAT_S16LE                | 1      | Signed 16-bit integer, little endian.|
| SAMPLE_FORMAT_S24LE                | 2      | Signed 24-bit integer, little endian.<br>Due to system restrictions, only some devices support this sampling format.|
| SAMPLE_FORMAT_S32LE                | 3      | Signed 32-bit integer, little endian.<br>Due to system restrictions, only some devices support this sampling format.|
| SAMPLE_FORMAT_F32LE<sup>9+</sup>   | 4      | Signed 32-bit floating-point number, little endian.<br>Due to system restrictions, only some devices support this sampling format.|

## AudioErrors<sup>9+</sup>

Enumerates the error codes available for audio management.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                | Value     | Description        |
| ---------------------| --------| ----------------- |
| ERROR_INVALID_PARAM  | 6800101 | Invalid parameter.        |
| ERROR_NO_MEMORY      | 6800102 | Memory allocation failure.    |
| ERROR_ILLEGAL_STATE  | 6800103 | Unsupported state.      |
| ERROR_UNSUPPORTED    | 6800104 | Unsupported parameter value.   |
| ERROR_TIMEOUT        | 6800105 | Processing timeout.        |
| ERROR_STREAM_LIMIT   | 6800201 | Too many audio streams.|
| ERROR_SYSTEM         | 6800301 | System error.    |

## AudioChannel<sup>8+</sup>

Enumerates the audio channels.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name     |  Value      | Description  |
| --------- | -------- |------|
| CHANNEL_1 | 1 | One audio channel (mono).|
| CHANNEL_2 | 2 | Two audio channels (stereo).|
| CHANNEL_3<sup>11+</sup> | 3 | Three audio channels.|
| CHANNEL_4<sup>11+</sup> | 4 | Four audio channels.|
| CHANNEL_5<sup>11+</sup> | 5 | Five audio channels.|
| CHANNEL_6<sup>11+</sup> | 6 | Six audio channels.|
| CHANNEL_7<sup>11+</sup> | 7 | Seven audio channels.|
| CHANNEL_8<sup>11+</sup> | 8 | Eight audio channels.|
| CHANNEL_9<sup>11+</sup> | 9 | Nine audio channels.|
| CHANNEL_10<sup>11+</sup> | 10 | Ten audio channels.|
| CHANNEL_12<sup>11+</sup> | 12 | Twelve audio channels.|
| CHANNEL_14<sup>11+</sup> | 14 | Fourteen audio channels.|
| CHANNEL_16<sup>11+</sup> | 16 | Sixteen audio channels.|

## AudioSamplingRate<sup>8+</sup>

Enumerates the audio sampling rates. The sampling rates supported vary according to the device in use.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name             |  Value   | Description           |
| ----------------- | ------ | --------------- |
| SAMPLE_RATE_8000  | 8000   | The sampling rate is 8000. The unit is Hz. |
| SAMPLE_RATE_11025 | 11025  | The sampling rate is 11025. The unit is Hz.|
| SAMPLE_RATE_12000 | 12000  | The sampling rate is 12000. The unit is Hz.|
| SAMPLE_RATE_16000 | 16000  | The sampling rate is 16000. The unit is Hz.|
| SAMPLE_RATE_22050 | 22050  | The sampling rate is 22050. The unit is Hz.|
| SAMPLE_RATE_24000 | 24000  | The sampling rate is 24000. The unit is Hz.|
| SAMPLE_RATE_32000 | 32000  | The sampling rate is 32000. The unit is Hz.|
| SAMPLE_RATE_44100 | 44100  | The sampling rate is 44100. The unit is Hz.|
| SAMPLE_RATE_48000 | 48000  | The sampling rate is 48000. The unit is Hz.|
| SAMPLE_RATE_64000 | 64000  | The sampling rate is 64000. The unit is Hz.|
| SAMPLE_RATE_88200<sup>12+</sup> | 88200  | The sampling rate is 88200. The unit is Hz.|
| SAMPLE_RATE_96000 | 96000  | The sampling rate is 96000. The unit is Hz.|
| SAMPLE_RATE_176400<sup>12+</sup> | 176400  | The sampling rate is 176400. The unit is Hz.|
| SAMPLE_RATE_192000<sup>12+</sup> | 192000  | The sampling rate is 192000. The unit is Hz.|
| SAMPLE_RATE_384000 | 384000  | The sampling rate is 384000. The unit is Hz.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## AudioEncodingType<sup>8+</sup>

Enumerates the audio encoding types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                 |  Value   | Description     |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | Invalid.   |
| ENCODING_TYPE_RAW     | 0      | PCM encoding.|

## AudioLatencyType<sup>23+</sup>

Enumerates the audio latency types.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name| Value| Description|
| ---- | -- | ---- |
| LATENCY_TYPE_ALL | 0 | Calculates the overall audio processing link latency, including both the software and hardware.|
| LATENCY_TYPE_SOFTWARE | 1 | Calculates the software latency, including the software sound effect.|
| LATENCY_TYPE_HARDWARE | 2 | Calculates the hardware latency, including the HAL, driver, and hardware.|

## AudioChannelLayout<sup>11+</sup>

Enumerates the audio channel layouts of audio files.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                           |  Value             | Description                                         |
| ------------------------------ | ---------------- | --------------------------------------------- |
| CH_LAYOUT_UNKNOWN              | 0x0              | Unknown.                                |
| CH_LAYOUT_MONO                 | 0x4              | Mono.                              |
| CH_LAYOUT_STEREO               | 0x3              | Stereo.                            |
| CH_LAYOUT_STEREO_DOWNMIX       | 0x60000000       | Stereo downmix.                    |
| CH_LAYOUT_2POINT1              | 0xB              | 2.1.                               |
| CH_LAYOUT_3POINT0              | 0x103            | 3.0.                               |
| CH_LAYOUT_SURROUND             | 0x7              | Surround.                          |
| CH_LAYOUT_3POINT1              | 0xF              | 3.1.                               |
| CH_LAYOUT_4POINT0              | 0x107            | 4.0.                               |
| CH_LAYOUT_QUAD                 | 0x33             | Quad.                              |
| CH_LAYOUT_QUAD_SIDE            | 0x603            | Quad side.                         |
| CH_LAYOUT_2POINT0POINT2        | 0x3000000003     | 2.0.2.                             |
| CH_LAYOUT_AMB_ORDER1_ACN_N3D   | 0x100000000001   | First-order FOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D  | 0x100000001001   | First-order FOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER1_FUMA      | 0x100000000101   | First-order FOA file in FUMA (ITU standards).    |
| CH_LAYOUT_4POINT1              | 0x10F            | 4.1.                                 |
| CH_LAYOUT_5POINT0              | 0x607            | 5.0.                               |
| CH_LAYOUT_5POINT0_BACK         | 0x37             | 5.0 back.                          |
| CH_LAYOUT_2POINT1POINT2        | 0x300000000B     | 2.1.2.                             |
| CH_LAYOUT_3POINT0POINT2        | 0x3000000007     | 3.0.2.                             |
| CH_LAYOUT_5POINT1              | 0x60F            | 5.1.                               |
| CH_LAYOUT_5POINT1_BACK         | 0x3F             | 5.1 back.                          |
| CH_LAYOUT_6POINT0              | 0x707            | 6.0.                               |
| CH_LAYOUT_HEXAGONAL            | 0x137            | Hexagonal.                         |
| CH_LAYOUT_3POINT1POINT2        | 0x500F           | 3.1.2.                             |
| CH_LAYOUT_6POINT0_FRONT        | 0x6C3            | 6.0 front.                         |
| CH_LAYOUT_6POINT1              | 0x70F            | 6.1.                               |
| CH_LAYOUT_6POINT1_BACK         | 0x13F            | 6.1 back.                          |
| CH_LAYOUT_6POINT1_FRONT        | 0x6CB            | 6.1 front.                         |
| CH_LAYOUT_7POINT0              | 0x637            | 7.0.                               |
| CH_LAYOUT_7POINT0_FRONT        | 0x6C7            | 7.0 front.                         |
| CH_LAYOUT_7POINT1              | 0x63F            | 7.1.                               |
| CH_LAYOUT_OCTAGONAL            | 0x737            | Octagonal.                         |
| CH_LAYOUT_5POINT1POINT2        | 0x300000060F     | 5.1.2.                             |
| CH_LAYOUT_7POINT1_WIDE         | 0x6CF            | 7.1 wide.                          |
| CH_LAYOUT_7POINT1_WIDE_BACK    | 0xFF             | 7.1 wide back.                     |
| CH_LAYOUT_AMB_ORDER2_ACN_N3D   | 0x100000000002   | Second-order HOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D  | 0x100000001002   | Second-order HOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER2_FUMA      | 0x100000000102   | Second-order HOA file in FUMA (ITU standards).    |
| CH_LAYOUT_5POINT1POINT4        | 0x2D60F          | 5.1.4.                             |
| CH_LAYOUT_7POINT1POINT2        | 0x300000063F     | 7.1.2.                             |
| CH_LAYOUT_7POINT1POINT4        | 0x2D63F          | 7.1.4.                             |
| CH_LAYOUT_10POINT2             | 0x180005737      | 10.2.                              |
| CH_LAYOUT_9POINT1POINT4        | 0x18002D63F      | 9.1.4.                             |
| CH_LAYOUT_9POINT1POINT6        | 0x318002D63F     | 9.1.6.                             |
| CH_LAYOUT_HEXADECAGONAL        | 0x18003F737      | Hexadecagonal.                     |
| CH_LAYOUT_AMB_ORDER3_ACN_N3D   | 0x100000000003   | Third-order HOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D  | 0x100000001003   | Third-order HOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER3_FUMA      | 0x100000000103   | Third-order HOA file in FUMA (ITU standards).    |

## StreamUsage

Enumerates the types of audio streams played.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                     |  Value   | Description                                                                            |
| ------------------------------------------| ------ |--------------------------------------------------------------------------------|
| STREAM_USAGE_UNKNOWN                      | 0      | Unknown content.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_MEDIA<sup>(deprecated)</sup> | 1      | Media.<br> This enumerated value is supported since API version 7 and deprecated since API version 10. You are advised to use **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, **STREAM_USAGE_GAME**, or **STREAM_USAGE_AUDIOBOOK** instead.|
| STREAM_USAGE_MUSIC<sup>10+</sup>          | 1      | Music.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_VOICE_COMMUNICATION          | 2      | VoIP voice call. (The 3A algorithm is enabled when this stream starts.)<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_VOICE_ASSISTANT<sup>9+</sup> | 3      | Voice assistant.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_ALARM<sup>10+</sup>          | 4      | Audio stream for alarming.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_VOICE_MESSAGE<sup>10+</sup>  | 5      | Voice message.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_NOTIFICATION_RINGTONE<sup>(deprecated)</sup> | 6      | Notification tone.<br> This enumerated value is supported since API version 7 and deprecated since API version 10. You are advised to use **STREAM_USAGE_RINGTONE** instead.|
| STREAM_USAGE_RINGTONE<sup>10+</sup>       | 6      | Ringtone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_NOTIFICATION<sup>10+</sup>   | 7      | Notification.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_ACCESSIBILITY<sup>10+</sup>  | 8      | Accessibility.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_MOVIE<sup>10+</sup>          | 10     | Movie or video.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_GAME<sup>10+</sup>           | 11     | Gaming.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_AUDIOBOOK<sup>10+</sup>      | 12     | Audiobooks (including crosstalks and storytelling), news radio, and podcasts.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_NAVIGATION<sup>10+</sup>     | 13     | Navigation.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_VIDEO_COMMUNICATION<sup>12+</sup>     | 17     | VoIP video call. (The 3A algorithm is enabled when this stream starts.)<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## AudioState<sup>8+</sup>

Enumerates the audio states.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name          | Value    | Description            |
| -------------- | ------ | ---------------- |
| STATE_INVALID  | -1     | Invalid state.      |
| STATE_NEW      | 0      | Creating instance state.|
| STATE_PREPARED | 1      | Prepared.      |
| STATE_RUNNING  | 2      | Running.|
| STATE_STOPPED  | 3      | Stopped.      |
| STATE_RELEASED | 4      | Released.      |
| STATE_PAUSED   | 5      | Paused.      |

## AudioEffectMode<sup>10+</sup>

Enumerates the audio effect modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Value    | Description      |
| ------------------ | ------ | ---------- |
| EFFECT_NONE        | 0      | The audio effect is disabled.|
| EFFECT_DEFAULT     | 1      | The default audio effect is used.|

## AudioRendererRate<sup>8+</sup>

Enumerates the audio renderer rates.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Value    | Description      |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | Normal rate.|
| RENDER_RATE_DOUBLE | 1      | Double rate.   |
| RENDER_RATE_HALF   | 2      | 0.5x rate. |

## InterruptType

Enumerates the audio interruption types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                |  Value    | Description                  |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | Audio interruption started.|
| INTERRUPT_TYPE_END   | 2      | Audio interruption ended.|

## InterruptForceType<sup>9+</sup>

Enumerates the types of force that causes audio interruption.

The force type is obtained when an [InterruptEvent](arkts-apis-audio-i.md#interruptevent9) is received.

This type specifies whether audio interruption is forcibly performed by the system. The operation information (such as audio pause or stop) can be obtained through [InterruptHint](#interrupthint). For details about the audio interruption policy, see [Introduction to Audio Focus](../../media/audio/audio-playback-concurrency.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           |  Value   | Description                                |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | The operation is forcibly performed by the system.  |
| INTERRUPT_SHARE | 1      | The operation will not be performed by the system. [InterruptHint](#interrupthint) is used to provide recommended operations for the application, and the application can determine the next processing mode.|

## InterruptHint

Enumerates the hints provided along with audio interruption.

The hint is obtained when an [InterruptEvent](arkts-apis-audio-i.md#interruptevent9) is received.

The hint specifies the operation (such as audio pause or volume adjustment) to be performed on audio streams based on the focus strategy.

You can determine whether the operation is forcibly performed by the system based on [InterruptForceType](#interruptforcetype9) in **InterruptEvent**. For details, see [Introduction to Audio Focus](../../media/audio/audio-playback-concurrency.md).

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                              |  Value    | Description                                        |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | None.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_RESUME              | 1      | A hint is displayed, indicating that the audio stream is restored. The application can proactively trigger operations related to rendering or recording.<br>This operation cannot be forcibly performed by the system, and the corresponding [InterruptForceType](#interruptforcetype9) must be **INTERRUPT_SHARE**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_PAUSE               | 2      | A hint is displayed, indicating that the audio stream is paused and the audio focus is lost temporarily.<br>When the audio focus is available, the **INTERRUPT_HINT_RESUME** event is received.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_STOP                | 3      | A hint is displayed, indicating that the audio stream stops and the audio focus is lost.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_DUCK                | 4      | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| INTERRUPT_HINT_MUTE<sup>20+</sup> | 6      | A hint is displayed, indicating that the audio is muted.|
| INTERRUPT_HINT_UNMUTE<sup>20+</sup> | 7      | A hint is displayed, indicating that the audio is unmuted.           |

## AudioVolumeMode<sup>19+</sup>

Enumerates the audio volume modes.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name          | Value    | Description          |
| -------------- | ------ |--------------|
| SYSTEM_GLOBAL  | 0 | System-level volume (default mode).|
| APP_INDIVIDUAL | 1 | Application-level volume.      |

## AudioPrivacyType<sup>10+</sup>

Enumerates whether an audio stream can be recorded by other applications.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name                | Value  | Description                            |
| -------------------- | ---- | -------------------------------- |
| PRIVACY_TYPE_PUBLIC  | 0    | The audio stream can be recorded or screen-projected by other applications and is not privacy-related.|
| PRIVACY_TYPE_PRIVATE | 1    | The audio stream cannot be recorded or screen-projected by other applications.|
| PRIVACY_TYPE_SHARED<sup>21+</sup>  | 2    | The audio stream can be recorded or screen-projected by other applications and is privacy-related.<br> For example, if the privacy policy is **PRIVACY_TYPE_PUBLIC**, audio streams of the [STREAM_USAGE_VOICE_COMMUNICATION](#streamusage) type cannot be recorded or screen-projected by other applications.<br> However, if the privacy policy is **PRIVACY_TYPE_SHARED**, these audio streams can be recorded or screen-projected by other applications.|

## ChannelBlendMode<sup>11+</sup>

Enumerates the audio channel blending modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                        |  Value    | Description                  |
| :------------------------------------------- | :----- | :--------------------- |
| MODE_DEFAULT | 0     | No channel mixing. |
| MODE_BLEND_LR | 1      | Blends the left and right channels together.|
| MODE_ALL_LEFT | 2      | Copies the left channel and applies it to both the left and right channels. |
| MODE_ALL_RIGHT | 3 | Copies the right channel and applies it to both the left and right channels. |

## AudioStreamDeviceChangeReason<sup>11+</sup>

Enumerates the reasons for audio stream device changes.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                                       |  Value    | Description             |
|:------------------------------------------| :----- |:----------------|
| REASON_UNKNOWN | 0 | Unknown reason.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| REASON_NEW_DEVICE_AVAILABLE | 1 | A new device is available.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| REASON_OLD_DEVICE_UNAVAILABLE | 2 | The old device is unavailable. When this reason is reported, consider pausing audio playback.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| REASON_OVERRODE | 3 | Forcibly selected.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| REASON_SESSION_ACTIVATED<sup>20+</sup> | 4 | The audio session has been activated.|
| REASON_STREAM_PRIORITY_CHANGED<sup>20+</sup> | 5 | An audio stream with higher priority appears.|

## OutputDeviceChangeRecommendedAction<sup>20+</sup>

Enumerates the recommended actions to take after an output device changes.

Common scenario example: switching between a headset and a loudspeaker device. Upon switching from the loudspeaker device to the headset upon wearing, the system suggests continuing playback and prompts that the application does not need to pause. Upon transitioning from the headset to the loudspeaker device upon removal, the system suggests suspending playback.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                       |  Value    | Description             |
|:------------------------------------------| :----- |:----------------|
| DEVICE_CHANGE_RECOMMEND_TO_CONTINUE | 0 | Suggests continuing playback. (This event serves as a playback maintenance indication, informing the application that audio playback does not need to stop during this device change. However, it must not be used as a criterion for triggering audio playback.)          |
| DEVICE_CHANGE_RECOMMEND_TO_STOP | 1 | Suggests stopping playback.        |

## DeviceChangeType

Enumerates the device connection statuses.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Value  | Description          |
| :--------- | :--- | :------------- |
| CONNECT    | 0    | Connected.    |
| DISCONNECT | 1    | Disconnected.|

## DeviceBlockStatus<sup>13+</sup>

Enumerates the blocked statuses of audio devices.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Value  | Description          |
| :--------- | :--- | :------------- |
| UNBLOCKED  | 0    | The audio device is not blocked.   |
| BLOCKED    | 1    | The audio device is blocked.|

## SourceType<sup>8+</sup>

Enumerates the types of audio streams captured.

| Name                                        |  Value    | Description                  |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_INVALID                          | -1     | Invalid audio source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_MIC                              | 0      | Mic source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup>   | 1      | Voice recognition source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_PLAYBACK_CAPTURE<sup>(deprecated)</sup>   | 2 | Internal audio recording source.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture<br> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [AVScreenCapture](../apis-media-kit/capi-avscreencapture.md) instead. |
| SOURCE_TYPE_VOICE_COMMUNICATION              | 7      | Audio source for voice call scenarios. When recording is started with this stream type, the 3A algorithms are triggered and enabled.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup>      | 10     | Voice message source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_CAMCORDER<sup>13+</sup>          | 13     | Video recording source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_UNPROCESSED<sup>14+</sup>     | 14 |  Audio source for raw microphone recording, where the system does not perform any algorithm processing.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_LIVE<sup>20+</sup>     | 17 |  Audio source in live streaming scenarios. This source type provides system echo cancellation capabilities on supported devices.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|

## AudioPlaybackCaptureMode

Enumerates the internal recording modes (recording audio from applications on the device). Different modes determine the types of playback streams that can be recorded. The enumeration values support bitwise OR combinations. Currently, the supported modes are `MODE_DEFAULT` (0x0), `MODE_MEDIA` (0x1), and `MODE_EXCLUDING_SELF` (0x8000), as well as the bitwise OR combination of `MODE_MEDIA` and `MODE_EXCLUDING_SELF` (0x8001).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name| Value| Description|
| :--- | :--- | :--- |
| MODE_DEFAULT | 0x0 | Default mode. Most audio streams are recorded, excluding the prompt streams and privacy streams.|
| MODE_MEDIA | 0x1 | Media mode. Media, voice messages, and audio streams of unknown types are recorded.|
| MODE_EXCLUDING_SELF | 0x8000 | Self-exclusion mode. All audio streams except for those played by the application itself are recorded.|

## PlaybackCaptureStartState

Enumerates the internal recording start states returned asynchronously after [requestPlaybackCaptureStart](arkts-apis-audio-AudioCapturer.md#requestplaybackcapturestart) is called.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name| Value| Description|
| :--- | :--- | :--- |
| STATE_SUCCESS | 0 | Internal audio recording is started successfully.|
| STATE_FAILED | 1 | Internal audio recording fails to be started. The reason is that the audio interruption request is rejected or an internal system error occurs.|
| STATE_NOT_AUTHORIZED | 2 | Internal audio recording fails to be started due to lack of user authorization.|

## AudioScene<sup>8+</sup>

Enumerates the audio scenes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name                  |  Value    | Description                                         |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT                  | 0      | Default audio scene.                               |
| AUDIO_SCENE_RINGING<sup>12+</sup>    | 1      | Normal mode.|
| AUDIO_SCENE_PHONE_CALL<sup>12+</sup> | 2      | Phone call scene.|
| AUDIO_SCENE_VOICE_CHAT               | 3      | Voice chat scene.                               |

## AudioConcurrencyMode<sup>12+</sup>

Enumerates the audio concurrency modes.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description     |
| :--------------------- |:--|:--------|
| CONCURRENCY_DEFAULT | 0 | Uses the system strategy by default.    |
| CONCURRENCY_MIX_WITH_OTHERS | 1 | Concurrent with other audio streams, that is, audio mixing.  |
| CONCURRENCY_DUCK_OTHERS | 2 | Ducks other audio streams.|
| CONCURRENCY_PAUSE_OTHERS | 3 | Pauses other audio streams.|

## AudioSessionDeactivatedReason<sup>12+</sup>

Enumerates the reasons for deactivating an audio session.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description    |
| :--------------------- |:--|:-------|
| DEACTIVATED_LOWER_PRIORITY | 0 | The application focus is preempted.|
| DEACTIVATED_TIMEOUT | 1 | The audio session times out.   |

## AudioSessionScene<sup>20+</sup>

Enumerates the audio session scenes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description     |
| :--------------------- |:--|:--------|
| AUDIO_SESSION_SCENE_MEDIA | 0 | Media audio session.    |
| AUDIO_SESSION_SCENE_GAME | 1 | Game audio session.    |
| AUDIO_SESSION_SCENE_VOICE_COMMUNICATION  | 2 | VoIP voice call audio session.|

## AudioSessionStateChangeHint<sup>20+</sup>

Enumerates the hints for audio session state changes.

The hint is obtained when an [AudioSessionStateChangedEvent](arkts-apis-audio-i.md#audiosessionstatechangedevent20) is received.

The hint specifies the action (such as audio pause or volume adjustment) to take on the audio session based on the focus strategy.

For details, see [Audio Session Management](../../media/audio/audio-session-management.md).

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                              |  Value    | Description                                        |
| ---------------------------------- | ------ | -------------------------------------------- |
| AUDIO_SESSION_STATE_CHANGE_HINT_RESUME              | 0      | A hint is displayed, indicating that the audio session is resuming. The application can proactively trigger operations such as rendering.|
| AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE               | 1      | A hint is displayed, indicating that the audio session is paused and the audio focus is lost temporarily. When focus is regained, the AUDIO_SESSION_STATE_CHANGE_HINT_RESUME event is received.|
| AUDIO_SESSION_STATE_CHANGE_HINT_STOP                | 2      | A hint is displayed, indicating that the audio session is stopped and the audio focus is lost permanently.|
| AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP                | 3      | A hint is displayed, indicating that the audio session is stopped by the system due to no activity, and the audio focus is lost.|
| AUDIO_SESSION_STATE_CHANGE_HINT_DUCK                | 4      | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.<br>If [enableMuteSuggestionWhenMixWithOthers](./arkts-apis-audio-AudioSessionManager.md#enablemutesuggestionwhenmixwithothers23) is enabled, you can choose to mute the audio.|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK | 5      | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.<br>If [enableMuteSuggestionWhenMixWithOthers](./arkts-apis-audio-AudioSessionManager.md#enablemutesuggestionwhenmixwithothers23) is enabled, you can unmute the audio.|
| AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION<sup>23+</sup>    | 6      |  Mute suggestion.<br>When another application starts playback of non-mixable audio, your application can determine whether to mute.<br> **Model restriction**: This API can be used only in the stage model.|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION<sup>23+</sup>  | 7      | Unmute suggestion.<br>When the non-mixable audio of another application has finished playing, your application can determine whether to unmute.<br> **Model restriction**: This API can be used only in the stage model.|
| AUDIO_SESSION_STATE_CHANGE_HINT_MUTE<sup>24+</sup>    | 8      |  A hint is displayed, indicating that the audio session is muted.<br>This hint is received only when the following conditions are met: The [setAudioSessionBehavior](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24) API is called to set [AudioSessionBehaviorFlags](#audiosessionbehaviorflags24).MUTE_WHEN_INTERRUPTED, the [setAudioSessionScene](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) API is called, and the audio session is activated.<br> **Model restriction**: This API can be used only in the stage model.|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE<sup>24+</sup>  | 9      | A hint is displayed, indicating that the audio session is unmuted.<br>This hint is received only when the following conditions are met: The [setAudioSessionBehavior](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24) API is called to set [AudioSessionBehaviorFlags](#audiosessionbehaviorflags24).MUTE_WHEN_INTERRUPTED, the [setAudioSessionScene](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) API is called, and the audio session is activated.<br> **Model restriction**: This API can be used only in the stage model.|

## AudioDataCallbackResult<sup>12+</sup>

Enumerates the audio data callback results.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                | Value     | Description        |
| ---------------------| --------| ----------------- |
| INVALID  | -1 | The callback data is invalid.     |
| VALID      | 0 | The callback data is valid.    |

## ContentType<sup>(deprecated)</sup>

Enumerates the audio content types.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [StreamUsage](#streamusage) instead.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                              |  Value   | Description      |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | Unknown content.|
| CONTENT_TYPE_SPEECH                | 1      | Speech.    |
| CONTENT_TYPE_MUSIC                 | 2      | Music.    |
| CONTENT_TYPE_MOVIE                 | 3      | Movie.    |
| CONTENT_TYPE_SONIFICATION          | 4      | Notification tone.  |
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | Ringtone.    |

## ActiveDeviceType<sup>(deprecated)</sup>

Enumerates the active device types.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [CommunicationDeviceType](#communicationdevicetype9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name         |  Value    | Description                                                |
| ------------- | ------ | ---------------------------------------------------- |
| SPEAKER       | 2      | Speaker.                                            |
| BLUETOOTH_SCO | 7      | Bluetooth device using Synchronous Connection Oriented (SCO) links.|

## InterruptActionType<sup>(deprecated)</sup>

Enumerates the returned event types for audio interruption events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [InterruptType](#interrupttype) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name          |  Value    | Description              |
| -------------- | ------ | ------------------ |
| TYPE_ACTIVATED | 0      | Focus gain event.|
| TYPE_INTERRUPT | 1      | Audio interruption event.|

## AudioLoopbackMode<sup>20+</sup>

Enumerates the audio loopback modes.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name          | Value    | Description             |
| -------------- | ------ | ----------------- |
| HARDWARE       | 0      | Hardware loopback.|

## AudioLoopbackStatus<sup>20+</sup>

Enumerates the audio loopback statuses.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name              | Value    | Description            |
| ------------------ | ------ | ---------------- |
| UNAVAILABLE_DEVICE | -2     | Loopback is unavailable due to issues with the input or output device (for example, changes in the audio output device).   |
| UNAVAILABLE_SCENE  | -1     | Loopback is unavailable due to restrictions in the audio scene (for example, audio focus or low-latency management).|
| AVAILABLE_IDLE     |  0     | Loopback is available but currently idle.    |
| AVAILABLE_RUNNING  |  1     | Loopback is actively running.  |

## AudioLoopbackReverbPreset<sup>21+</sup>

Enumerates the reverb modes of audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name     | Value    | Description            |
| --------- | ------ | ---------------- |
| ORIGINAL  | 1     | Maintains the original reverb without enhancement.  |
| KTV       | 2     | Provides a Karaoke-style reverb effect.|
| THEATER   | 3     | Provides a theater-style reverb effect (default).|
| CONCERT   | 4     | Provides a concert-style reverb effect.  |

## AudioLoopbackEqualizerPreset<sup>21+</sup>

Enumerates the equalizer types of audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name     | Value    | Description            |
| --------- | ------ | ---------------- |
| FLAT   | 1     | Maintains the original sound without equalization.|
| FULL   | 2     | Enhances the fullness of vocals (default).|
| BRIGHT | 3     | Enhances the brightness of vocals.|

## AudioSessionBehaviorFlags<sup>24+</sup>

Enumerates audio session behaviors.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description     |
| :--------------------- |:--|:--------|
| DEFAULT_BEHAVIOR | 0x00000000 | Default behavior, which is used to clear the audio session behavior settings.|
| MUTE_WHEN_INTERRUPTED | 0x00000002 | When the system needs to stop or pause an audio stream, forced muting is applied as an alternative.<br>When the [setAudioSessionBehavior](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24) API is called to configure this behavior, the [setAudioSessionScene](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) API must also be called. Otherwise, the configuration will not take effect.<br>In an audio session scenario, when an audio stream is muted or unmuted, the application will receive the [AudioSessionStateChangeHint](./arkts-apis-audio-e.md#audiosessionstatechangehint20).AUDIO_SESSION_STATE_CHANGE_HINT_MUTE and [AudioSessionStateChangeHint](./arkts-apis-audio-e.md#audiosessionstatechangehint20).AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE notifications, respectively.<br>In AudioRenderer and AudioCapturer scenarios, when an audio stream is muted or unmuted, the application will receive the [InterruptHint](#interrupthint).INTERRUPT_HINT_MUTE and [InterruptHint](#interrupthint).INTERRUPT_HINT_UNMUTE notifications, respectively.<br>**Note:** This flag cannot coexist with PAUSE_WHEN_INTERRUPTED. If both are set, only PAUSE_WHEN_INTERRUPTED takes effect.|
| PAUSE_WHEN_INTERRUPTED | 0x00000004 | When the system needs to stop the audio stream, pause is used as an alternative.<br>When the [setAudioSessionBehavior](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24) API is called to configure this behavior, the [setAudioSessionScene](./arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) API must also be called. Otherwise, the configuration will not take effect.<br>In an audio session scenario, when an audio stream is paused or resumed, the application will receive the [AudioSessionStateChangeHint](./arkts-apis-audio-e.md#audiosessionstatechangehint20).AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE and [AudioSessionStateChangeHint](./arkts-apis-audio-e.md#audiosessionstatechangehint20).AUDIO_SESSION_STATE_CHANGE_HINT_RESUME notifications, respectively.<br>In AudioRenderer and AudioCapturer scenarios, when an audio stream is paused or resumed, the application will receive the [InterruptHint](#interrupthint).INTERRUPT_HINT_PAUSE and [InterruptHint](#interrupthint).INTERRUPT_HINT_RESUME notifications, respectively.<br>**Note:** This flag cannot coexist with MUTE_WHEN_INTERRUPTED. If both are set, only this flag takes effect.<br>**Since**: 26.0.0|
