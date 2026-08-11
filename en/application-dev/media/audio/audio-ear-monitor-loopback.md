# Implementing Low-Latency Audio Monitoring

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=3a7084fa36f3aa40ad1ae670f066e28c8494300a translatedAt=2026-08-06T01:42:56.896Z pushedAt=2026-08-06T03:43:43.157Z -->

Low-latency audio monitoring is supported since API version 20.

AudioLoopback is an audio monitoring tool that delivers audio to headphones with reduced latency in real time, enabling users to hear their own voice or other relevant sounds immediately.

It is commonly used in karaoke applications, where the recorded vocals and background music are sent to the headphones in real time. This allows users to adjust their performance based on the feedback, enhancing their experience.

When audio loopback is enabled, the system creates a low-latency renderer and capturer to implement low-latency in-ear monitoring. The audio captured is routed back to the renderer through an internal path. The renderer follows the audio focus strategy for [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), whereas the capturer follows the strategy for [SOURCE_TYPE_MIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8).

The input/output device is automatically selected by the system. If the current input/output device does not support low latency, audio monitoring cannot be enabled. During operation, if the audio focus is preempted by another audio stream, or the input/output device switches to one that does not support low latency, the system automatically disables audio monitoring.

## Prerequisites

- Currently, low-latency audio monitoring is supported through wired earphones and certain NearLink earphones. When a wired earphone is connected, audio is captured and played back by the earphone. When a NearLink earphone is connected, audio is captured by the phone and played back by the earphone.

- Low-power renderers and low-latency renderers cannot be used concurrently in API version 20. To enable a renderer, you are advised to use [STREAM_USAGE_UNKNOWN](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage). If [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage) is used, the system creates a normal renderer.

## When to Use

Audio monitoring is implemented through the system-provided AudioLoopback API. The system internally sets up a low-latency audio loopback data link, which is suitable for scenarios with stricter latency requirements. If your app needs to process loopback data in real time and is not sensitive to latency, refer to [Implementing Custom Audio Monitoring](audio-ear-monitor.md).

## Development Guidelines

Using AudioLoopback for audio monitoring involves querying the monitoring capability with [isAudioLoopbackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isaudioloopbacksupported20), creating an AudioLoopback instance, setting the volume, listening for status changes, and enabling/disabling audio loopback. This guide walks you through the process of enabling audio monitoring using AudioLoopback, with a focus on how to use AudioLoopback for audio monitoring. You are advised to read this in conjunction with the [AudioLoopback](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md) API documentation.

The following figure shows the status changes of **AudioLoopback**. After an instance is created, you can call the corresponding method to enter the specified state to implement the corresponding behavior.

If an API is called when the AudioLoopback is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AudioLoopback state before triggering state transition.

**AudioLoopback status changes**

![AudioLoopback status change](figures/audioloopback-status-change.png)

The [on('statusChange')](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#onstatuschange20) API can be used to listen for **AudioLoopback** status changes. For details about the value and description of each status, see [AudioLoopbackStatus](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackstatus20).

### How to Develop

  The following examples are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS) via the link at the bottom right of each code snippet.

1. Query the monitoring capability and create an **AudioLoopback** instance. For details about the audio loopback mode, see [AudioLoopbackMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackmode20).

   > **NOTE**
   > 
   > You must request the ohos.permission.MICROPHONE permission for audio monitoring. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

   <!-- @[create_AudioLoopback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { audio } from '@kit.AudioKit'; // Import the audio module.
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
   let mode: audio.AudioLoopbackMode = audio.AudioLoopbackMode.HARDWARE;
   let audioLoopback: audio.AudioLoopback | undefined = undefined;
   // ...
     let isSupported = audio.getAudioManager().getStreamManager().isAudioLoopbackSupported(mode);
     if (isSupported) {
       audio.createAudioLoopback(mode).then((loopback) => {
         console.info('Succeeded in creating audio loopback.');
         // ...
         audioLoopback = loopback;
       }).catch((err: BusinessError) => {
         console.error(`Failed to create audio loopback. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
     } else {
       console.error('Audio loopback is unsupported.');
       // ...
     }
   ```

2. Starting from API version 26.0.0, you can call [getSupportedDevicePairs](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getsupporteddevicepairs) to query the input/output device combinations that support loopback.

  > **NOTE**
  > 
  > - If no loopback input/output device combination is currently available, an empty array is returned.
  > - You are advised to check whether the returned array is empty before processing the input/output device combination information.

   <!-- @[get_SupportedDevicePairs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       let devicePairs = audioLoopback.getSupportedDevicePairs();
       // ...
   ```

3. Starting from API version 26.0.0, you can call [getPreferredDevicePair](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getpreferreddevicepair) to query the input/output device combination recommended by the system for loopback.

  > **NOTE**
  > 
  > If no loopback input/output device combination is currently available, null is returned.

   <!-- @[get_PreferredDevicePair](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       let devicePair = audioLoopback.getPreferredDevicePair();
       // ...
   ```

4. Call [getStatus](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getstatus20) to query the current loopback status.

   > **NOTE**
   > 
   > The audio loopback status is affected by factors such as audio focus, low-latency control, and capturer and renderer devices.

   <!-- @[get_Status](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       audioLoopback.getStatus().then((status: audio.AudioLoopbackStatus) => {
         console.info(`Succeeded in getting status, status is ${status}.`);
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to get status. Code: ${err.code}, message: ${err.message}`);
         // ...
       })
   ```

5. Call [setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#setvolume20) to set the audio loopback volume.

   > **NOTE**
   > 
   > - Setting the volume before enabling audio loopback will take effect after successful activation of audio loopback.
   > - Setting the volume after enabling audio loopback will take effect immediately.
   > - If the volume is not set before enabling audio loopback, the default volume of 0.5 is used upon activation of audio loopback.

   <!-- @[set_Volume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       try {
         await audioLoopback.setVolume(volume);
         console.info('Succeeded in setting volume.');
         // ...
       } catch (err) {
         console.error(`Failed to set volume. Code: ${err.code}, message: ${err.message}`);
         // ...
       }
   ```

6. Starting from API version 26.0.0, you can call [getVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getvolume) to query the current monitor volume.

  > **NOTE**
  > 
  > The returned volume range is [0.0, 1.0].

   <!-- @[get_Volume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       let volume = audioLoopback.getVolume();
       // ...
   ```

7. Starting from API version 21, you can call [setReverbPreset](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#setreverbpreset21) to set the reverb mode for audio loopback.

   > **NOTE**
   > 
   > - If you set the reverb mode before enabling loopback, the setting takes effect after audio loopback is successfully enabled.
   > - If you set the reverb mode after enabling loopback, the setting takes effect immediately.
   > - If you do not set the reverb mode before enabling loopback, the default mode [THEATER](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackreverbpreset21) is used upon activation of audio loopback.

   <!-- @[set_ReverbPreset](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       try {
         if (audioLoopback.setReverbPreset(preset)) {
           console.info('Succeeded in setting reverb preset.');
           // ...
           // Obtain the current reverb mode to prevent setting failure.
           currentReverbPreset = preset;
         } else {
           console.error('Failed to set reverb preset.');
           // ...
         }
       } catch (err) {
         console.error(`Failed to set reverb preset. Code: ${err.code}, message: ${err.message}`);
         // ...
       }
   ```

8. Starting from API version 21, you can call [getReverbPreset](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getreverbpreset21) to query the current reverb mode of audio loopback.

   > **NOTE**
   > 
   > If no reverb mode has been set, the default mode [THEATER](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackreverbpreset21) is returned.

   <!-- @[get_ReverbPreset](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       let reverbPreset = audioLoopback.getReverbPreset();
   ```

9. Starting from API version 21, you can call [setEqualizerPreset](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#setequalizerpreset21) to set the equalizer type for audio loopback.

   > **NOTE**
   > 
   > - If you set the equalizer type before enabling loopback, the setting takes effect after audio loopback is successfully enabled.
   > - If you set the equalizer type after enabling loopback, the setting takes effect immediately.
   > - If you do not set the equalizer type before enabling loopback, the default mode [FULL](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackequalizerpreset21) is used upon activation of audio loopback.

   <!-- @[set_EqualizerPreset](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
   // ...
       try {
         if (audioLoopback.setEqualizerPreset(preset)) {
           console.info('Succeeded in setting equalizer preset.');
           // ...
           // Obtain the current equalizer type to prevent setting failures.
           currentEqualizerPreset = preset;
         } else {
           console.error('Failed to set equalizer preset.');
           // ...
         }
       } catch (err) {
         console.error(`Failed to set equalizer preset. Code: ${err.code}, message: ${err.message}`);
         // ...
       }
   ```

10. Starting from API version 21, you can call [getEqualizerPreset](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#getequalizerpreset21) to query the current equalizer type of audio loopback.

    > **NOTE**
    > 
    > If no equalizer type has been set, the default equalizer type [FULL](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioloopbackequalizerpreset21) is returned.

    <!-- @[get_EqualizerPreset](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

    ``` TypeScript
    import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
    // ...
        let equalizerPreset = audioLoopback.getEqualizerPreset();
    ```

11. Call [enable](../../reference/apis-audio-kit/arkts-apis-audio-AudioLoopback.md#enable20) to enable or disable audio loopback.

    <!-- @[enable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

    ``` TypeScript
    import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
    // ...
    // Set the listener event and enable audio loopback.
    async function enable(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
      if (audioLoopback !== undefined) {
        try {
          let status = await audioLoopback.getStatus();
          if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
            // Register the listener.
            audioLoopback.on('statusChange', statusChangeCallback);
            // Start loopback.
            let isSuccess = await audioLoopback.enable(true);
            if (isSuccess) {
              console.info('Succeeded in using enable function.');
              // ...
            } else {
              status = await audioLoopback.getStatus();
              statusChangeCallback(status);
            }
          } else {
            statusChangeCallback(status);
          }
        } catch (err) {
          console.error(`Failed to use enable function. code: ${err.code}, message: ${err.message}`);
          // ...
        }
      } else {
        console.error('Audio loopback not created.');
        // ...
      }
    }
   
    // Disable audio loopback and close the listener event.
    async function disable(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
      if (audioLoopback !== undefined) {
        try {
          let status = await audioLoopback.getStatus();
          if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
            // Disable loopback.
            let isSuccess = await audioLoopback.enable(false);
            if (isSuccess) {
              console.info('Succeeded in using enable function.');
              // ...
              // Close the listener.
              audioLoopback.off('statusChange', statusChangeCallback);
            } else {
              status = await audioLoopback.getStatus();
              statusChangeCallback(status);
            }
          } else {
            statusChangeCallback(status);
          }
        } catch (err) {
          console.error(`Failed to use enable function. code: ${err.code}, message: ${err.message}`);
          // ...
        }
      } else {
        console.error('Audio loopback not created.');
        // ...
      }
    }
    ```

### Complete Sample Code

The following example demonstrates how to use AudioLoopback to enable low-latency audio monitoring:

<!-- @[all_audioLoopback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopback.ets) -->    

``` TypeScript
import { audio } from '@kit.AudioKit'; // Import the audio module.
import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.
import { common, abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit'; // Import UIAbilityContext.

const TAG = 'AudioLoopbackDemo';
let mode: audio.AudioLoopbackMode = audio.AudioLoopbackMode.HARDWARE;
let audioLoopback: audio.AudioLoopback | undefined = undefined;
let currentReverbPreset: audio.AudioLoopbackReverbPreset = audio.AudioLoopbackReverbPreset.THEATER;
let currentEqualizerPreset: audio.AudioLoopbackEqualizerPreset = audio.AudioLoopbackEqualizerPreset.FULL;
// ...

// ...

// Query the capability and create an instance.
function init(updateCallback?: (msg: string, isError: boolean) => void): void {
  let isSupported = audio.getAudioManager().getStreamManager().isAudioLoopbackSupported(mode);
  if (isSupported) {
    audio.createAudioLoopback(mode).then((loopback) => {
      console.info('Succeeded in creating audio loopback.');
      // ...
      audioLoopback = loopback;
    }).catch((err: BusinessError) => {
      console.error(`Failed to create audio loopback. Code: ${err.code}, message: ${err.message}`);
      // ...
    });
  } else {
    console.error('Audio loopback is unsupported.');
    // ...
  }
}

// Set the volume for audio loopback.
async function setVolume(volume: number, updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioLoopback !== undefined) {
    try {
      await audioLoopback.setVolume(volume);
      console.info('Succeeded in setting volume.');
      // ...
    } catch (err) {
      console.error(`Failed to set volume. Code: ${err.code}, message: ${err.message}`);
      // ...
    }
  } else {
    console.error('Audio loopback not created.');
    // ...
  }
}

// Set the reverb mode for audio loopback.
async function setReverbPreset(preset: audio.AudioLoopbackReverbPreset, updateCallback?: (msg: string,
  isError: boolean) => void): Promise<void> {
  if (audioLoopback !== undefined) {
    try {
      if (audioLoopback.setReverbPreset(preset)) {
        console.info('Succeeded in setting reverb preset.');
        // ...
        // Obtain the current reverb mode to prevent setting failure.
        currentReverbPreset = preset;
      } else {
        console.error('Failed to set reverb preset.');
        // ...
      }
    } catch (err) {
      console.error(`Failed to set reverb preset. Code: ${err.code}, message: ${err.message}`);
      // ...
    }
  } else {
    console.error('Audio loopback not created.');
    // ...
  }
}

// Set the equalizer type for audio loopback.
async function setEqualizerPreset(preset: audio.AudioLoopbackEqualizerPreset, updateCallback?:
  (msg: string, isError: boolean) => void): Promise<void> {
  if (audioLoopback !== undefined) {
    try {
      if (audioLoopback.setEqualizerPreset(preset)) {
        console.info('Succeeded in setting equalizer preset.');
        // ...
        // Obtain the current equalizer class to prevent setting failure.
        currentEqualizerPreset = preset;
      } else {
        console.error('Failed to set equalizer preset.');
        // ...
      }
    } catch (err) {
      console.error(`Failed to set equalizer preset. Code: ${err.code}, message: ${err.message}`);
      // ...
    }
  } else {
    console.error('Audio loopback not created.');
    // ...
  }
}

// Set a listener and enable audio loopback.
async function enable(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioLoopback !== undefined) {
    try {
      let status = await audioLoopback.getStatus();
      if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
        // Register a listener.
        audioLoopback.on('statusChange', statusChangeCallback);
        // Enable audio loopback.
        let isSuccess = await audioLoopback.enable(true);
        if (isSuccess) {
          console.info('Succeeded in using enable function.');
          // ...
        } else {
          status = await audioLoopback.getStatus();
          statusChangeCallback(status);
        }
      } else {
        statusChangeCallback(status);
      }
    } catch (err) {
      console.error(`Failed to use enable function. code: ${err.code}, message: ${err.message}`);
      // ...
    }
  } else {
    console.error('Audio loopback not created.');
    // ...
  }
}

// Disable audio loopback and unregister the listener.
async function disable(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioLoopback !== undefined) {
    try {
      let status = await audioLoopback.getStatus();
      if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
        // Disable audio loopback.
        let isSuccess = await audioLoopback.enable(false);
        if (isSuccess) {
          console.info('Succeeded in using enable function.');
          // ...
          // Unregister the listener.
          audioLoopback.off('statusChange', statusChangeCallback);
        } else {
          status = await audioLoopback.getStatus();
          statusChangeCallback(status);
        }
      } else {
        statusChangeCallback(status);
      }
    } catch (err) {
      console.error(`Failed to use enable function. code: ${err.code}, message: ${err.message}`);
      // ...
    }
  } else {
    console.error('Audio loopback not created.');
    // ...
  }
}
```

<!--no_check-->