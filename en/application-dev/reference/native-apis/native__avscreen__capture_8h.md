# native_avscreen_capture.h


## Overview

The **native_avscreen_capture.h** file declares the native APIs used to create an **OH_AVScreenCapture** instance.

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVScreenCapture_Create](_a_v_screen_capture.md#oh_avscreencapture_create) (void) | Creates an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCapture_Init](_a_v_screen_capture.md#oh_avscreencapture_init) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | Initializes parameters related to an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCapture_StartScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Starts screen capture and collects original streams. After calling this function, the application can use the callback listeners **OH_AVScreenCaptureOnAudioBufferAvailable** and **OH_AVScreenCaptureOnVideoBufferAvailable** to check whether streams are generated.| 
| [OH_AVScreenCapture_StopScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Stops screen capture. This function is used in pair with **OH_AVScreenCapture_StartScreenCapture**. After calling this function, the application stops screen capture or screen share and releases the microphone.| 
| [OH_AVScreenCapture_StartScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Starts screen recording and collects encoded streams.<br>**NOTE**: This function is reserved and will be provided in later versions.| 
| [OH_AVScreenCapture_StopScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Stops screen recording. This function is used in pair with **OH_AVScreenCapture_StartScreenRecording**.<br>**NOTE**: This function is reserved and will be provided in later versions.| 
| [OH_AVScreenCapture_AcquireAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.| 
| [OH_AVScreenCapture_AcquireVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | Obtains a video buffer. An application can call this function to obtain information such as the video buffer and timestamp.| 
| [OH_AVScreenCapture_ReleaseAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | Releases an audio buffer.| 
| [OH_AVScreenCapture_ReleaseVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Releases a video buffer.| 
| [OH_AVScreenCapture_SetCallback](_a_v_screen_capture.md#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.| 
| [OH_AVScreenCapture_Release](_a_v_screen_capture.md#oh_avscreencapture_release) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | Releases an **OH_AVScreenCapture** instance. This function is used in pair with **OH_AVScreenCapture_Create**.| 
| [OH_AVScreenCapture_SetMicrophoneEnabled](_a_v_screen_capture.md#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isMicrophone) | Enables or disables the microphone.| 
