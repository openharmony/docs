# Multimedia Subsystem Changelog

## cl.multimedia.1 	The default behavior of OH_AVCodecOnStreamChanged in the audio decoding scenario is changed.

**Access Level**

Public API

**Reason for Change**

If parameters such as the sampling rate change during audio decoding, a callback needs to be invoked to notify the caller.

**Impact of the Change**

This change does not require application adaptation.

Before change: If an application has registered the **OH_AVCodecOnStreamChanged** callback by calling **OH_AudioCodec_RegisterCallback**, this callback is triggered when the sampling rate or number of audio channels changes during audio decoding.

After change: If an application has registered the **OH_AVCodecOnStreamChanged** callback by calling **OH_AudioCodec_RegisterCallback**, this callback is triggered when the sampling rate or number of audio channels changes during audio decoding.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.1.0.50

**Key API/Component Changes**

**OH_AVCodecOnStreamChanged** in **native_avcodec_base.h**, which is registered by **OH_AudioCodec_RegisterCallback** in **native_avcodec_audiocodec.h**

**Adaptation Guide**

No adaptation is required.
