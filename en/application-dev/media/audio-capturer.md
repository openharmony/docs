# Audio Capture Development

---
## ***Note***:
    1. This document applies to JavaScript.
---
## **Summary**
This guide will show how a JS application can use AudioCapturer to record the audio.
Applications can use the APIs provided in this document to record raw audio files.

## **AudioCapturer Framework**
The AudioCapturer interface is one of the most important components of the audio framework.
### **Audio Capturing:**
The AudioCapturer framework provides APIs for capturing raw audio files.

## **Usage**
Here's an example of how to use AudioCapturer to capture a raw audio file.
1. Use **createAudioCapturer()** to create an AudioCapturer instance. Capturer parameters can be set in **audioCapturerOptions**.\
   This instance can be used to record, control, and obtain the recording status, as well as to register a callback for notifications.
   ```
    var audioStreamInfo = {
        samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
        channels: audio.AudioChannel.CHANNEL_1,
        sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
        encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    }

    var audioCapturerInfo = {
        source: audio.SourceType.SOURCE_TYPE_MIC,
        capturerFlags: 1
    }

    var audioCapturerOptions = {
        streamInfo: audioStreamInfo,
        capturerInfo: audioCapturerInfo
    }

    let audioCapturer = await audio.createAudioCapturer(audioCapturerOptions);
    var state = audioRenderer.state;
   ```

2. (Optional) Subscribe to audio capturer state change events using the **on('stateChange')** API.
   If an application wants to take some action based on the state updates in capturer, the application can subscribe to the state change event.
   There are more events that applications can subscribe to, such as 'markReach' and 'periodReach'. Refer to [Audio](../reference/apis/js-apis-audio.md) for more details.
   ```
    audioCapturer.on('stateChange',(state) => {
    console.info('AudioCapturerLog: Changed State to : ' + state)
    switch (state) {
        case audio.AudioState.STATE_PREPARED:
            console.info('--------CHANGE IN AUDIO STATE----------PREPARED--------------');
            console.info('Audio State is : Prepared');
            break;
        case audio.AudioState.STATE_RUNNING:
            console.info('--------CHANGE IN AUDIO STATE----------RUNNING--------------');
            console.info('Audio State is : Running');
            break;
        case audio.AudioState.STATE_STOPPED:
            console.info('--------CHANGE IN AUDIO STATE----------STOPPED--------------');
            console.info('Audio State is : stopped');
            break;
        case audio.AudioState.STATE_RELEASED:
            console.info('--------CHANGE IN AUDIO STATE----------RELEASED--------------');
            console.info('Audio State is : released');
            break;
        default:
            console.info('--------CHANGE IN AUDIO STATE----------INVALID--------------');
            console.info('Audio State is : invalid');
            break;
        }
    });

   ```

3. Call the **start()** function on the AudioCapturer instance to start/resume the recording task.\
   The capturer state will be STATE_RUNNING once the start is complete. The application can then begin reading buffers.
   ```
    await audioCapturer.start();
    if (audioCapturer.state == audio.AudioState.STATE_RUNNING) {
        console.info('AudioRecLog: Capturer started');
    } else {
        console.info('AudioRecLog: Capturer start failed');
    }

   ```

4. Obtain the minimum buffer size to read using the **getBufferSize()** API.
   ```
    var bufferSize = await audioCapturer.getBufferSize();
    console.info('AudioRecLog: buffer size: ' + bufferSize);

    ```

5. Read the captured audio data and convert it to a byte stream. Call the **read()** API repeatedly to read the data
   until the application wants to stop the recording. The following example shows how to write recorded data into a file.
   ```
    import fileio from '@ohos.fileio';

    const path = '/data/data/.pulse_dir/capture_js.wav';
    let fd = fileio.openSync(path, 0o102, 0o777);
    if (fd !== null) {
        console.info('AudioRecLog: file fd created');
    }
    else{
        console.info('AudioRecLog: file fd create : FAILED');
        return;
    }

    fd = fileio.openSync(path, 0o2002, 0o666);
    if (fd !== null) {
        console.info('AudioRecLog: file fd opened in append mode');
    }

    var numBuffersToCapture = 150;
    while (numBuffersToCapture) {
        var buffer = await audioCapturer.read(bufferSize, true);
        if (typeof(buffer) == undefined) {
            console.info('read buffer failed');
        } else {
            var number = fileio.writeSync(fd, buffer);
            console.info('AudioRecLog: data written: ' + number);
        }

        numBuffersToCapture--;
    }
   ```
6. Once the recording is complete, call the **stop()** API on the AudioCapturer instance to stop the recording.
   ```
    await audioCapturer.stop();
    if (audioCapturer.state == audio.AudioState.STATE_STOPPED) {
        console.info('AudioRecLog: Capturer stopped');
    } else {
        console.info('AudioRecLog: Capturer stop failed');
    }
   ```

7. After the recording task is complete, call the **release()** API on the AudioCapturer instance to release the stream resources.
   ```
    await audioCapturer.release();
    if (audioCapturer.state == audio.AudioState.STATE_RELEASED) {
        console.info('AudioRecLog: Capturer released');
    } else {
        console.info('AudioRecLog: Capturer release failed');
    }
   ```

## **Importance of State Check**
Application developers should keep in mind that an AudioCapturer is state-based.
That is, the AudioCapturer has an internal state that the application must always check when calling recorder control APIs, because some operations are only acceptable while the capturer is in a given state.\
The system may throw an error/exception or generate other undefined behaviour if the application performs an operation while capturer is in an improper state.

## **Other APIs**
See [AudioCapturer in the Audio API](../reference/apis/js-apis-audio.md) for more useful APIs like **getAudioTime**, **getCapturerInfo** and **getStreamInfo**.
