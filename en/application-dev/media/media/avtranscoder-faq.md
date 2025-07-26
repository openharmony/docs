# FAQs About Transcoding

## Why does the audio encoding format change when the application sends a video for transcoding?

If the audio track format is not specified during transcoding, the system converts it to AAC by default.

<!--RP2--><!--RP2End-->

## What should I do if the transcoding capabilities provided by the system fail to be called?

1. Check whether the current transcoding system supports the video and the target video format settings.

   For details about the transcoding capabilities, see [AVTranscoder](media-kit-intro.md#avtranscoder) and [AVCodec Supported Formats](../avcodec/avcodec-support-formats.md).<!--RP1--><!--RP1End-->

2. When receiving an error event, the application should send the source video. When receiving a complete event, the application first calls **release** before performing operations such as sending or uploading the transcoded video.
