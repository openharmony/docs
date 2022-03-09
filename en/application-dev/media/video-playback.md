# Video Playback Development

## When to Use

You can use video playback APIs to convert video data into visible signals, play the signals using output devices, and manage playback tasks. This document describes the following video playback development scenarios: full-process, normal playback, video switching, and loop playback.

**Figure 1** Video playback state transition

![en-us_image_video_state_machine](figures/en-us_image_video_state_machine.png)



**Figure 2** Layer 0 diagram of video playback

![en-us_image_video_player](figures/en-us_image_video_player.png)

Note: Video playback requires hardware capabilities such as display, audio, and codec.

1. A third-party application obtains a surface ID from the Xcomponent.
2. The third-party application transfers the surface ID to the VideoPlayer JS.
3. The media service flushes the frame data to the surface buffer.

## How to Develop

For details about the APIs used for video playback, see [js-apis-media.md](../reference/apis/js-apis-media.md).

### Full-Process Scenario

The full video playback process includes creating an instance, setting the URL, setting the surface ID, preparing for video playback, playing video, pausing playback, obtaining track information, seeking to a playback position, setting the volume, setting the playback speed, stopping playback, resetting the playback configuration, and releasing resources.

For details about the **url** media source input types supported by **VideoPlayer**, see the [url attribute](../reference/apis/js-apis-media.md#videoplayer_Attributes).

```js
let videoPlayer = undefined; // Used to store instances created by calling the createVideoPlayer method.
let surfaceID = undefined; // Used to save the surface ID returned by the Xcomponent interface.

// Report an error in the case of a function invocation failure.
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// Report an error in the case of a function invocation exception.
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// Used to print the video track information.
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('key is ' + item);
        console.info('value is ' + property);
    }
}

// Call createVideoPlayer to create a VideoPlayer instance.
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// Set the URL of the video file selected by the user.
videoPlayer.url = 'file:///data/data/ohos.xxx.xxx/files/test.mp4';

// Call the Xcomponent interface to obtain the surface ID and save it to the surfaceID variable.

// Set the surface ID to display the video image.
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// Call the prepare interface to prepare for playback.
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// Call the play interface to start playback.
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);

// Pause playback.
await videoPlayer.pause().then(() => {
    console.info('pause success');
}, failureCallback).catch(catchCallback);

// Use a promise to obtain the video track information.
let arrayDescription;
await videoPlayer.getTrackDescription().then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('video getTrackDescription fail');
    }
}, failureCallback).catch(catchCallback);

for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}

// Seek to the 50s position. For details about the input parameters, see the interface document.
let seekTime = 50000;
await videoPlayer.seek(seekTime, media.SeekMode._NEXT_SYNC).then((seekDoneTime) => {
    console.info('seek success');
}, failureCallback).catch(catchCallback);

// Set the volume. For details about the input parameters, see the interface document.
let volume = 0.5;
await videoPlayer.setVolume(volume).then(() => {
    console.info('setVolume success');
}, failureCallback).catch(catchCallback);

// Set the playback speed. For details about the input parameters, see the interface document.
let speed = media.PlaybackRateMode.SPEED_FORWARD_2_00_X;
await videoPlayer.setSpeed(speed).then(() => {
    console.info('setSpeed success');
}, failureCallback).catch(catchCallback);

// Stop playback.
await videoPlayer.stop().then(() => {
    console.info('stop success');
}, failureCallback).catch(catchCallback);

// Reset the playback configuration.
await videoPlayer.reset().then(() => {
    console.info('reset success');
}, failureCallback).catch(catchCallback);

// Release playback resources.
await videoPlayer.release().then(() => {
    console.info('release success');
}, failureCallback).catch(catchCallback);

// Set the related instances to undefined.
videoPlayer = undefined;
surfaceID = undefined;
```

### Normal Playback Scenario

```js
let videoPlayer = undefined; // Used to store instances created by calling the createVideoPlayer method.
let surfaceID = undefined; // Used to save the surface ID returned by the Xcomponent interface.

// Report an error in the case of a function invocation failure.
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// Report an error in the case of a function invocation exception.
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// Set the 'playbackCompleted' event callback, which is triggered when the playback is complete.
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// Call createVideoPlayer to create a VideoPlayer instance.
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// Set the event callbacks.
SetCallBack(videoPlayer);

// Set the URL of the video file selected by the user.
videoPlayer.url = 'file:///data/data/ohos.xxx.xxx/files/test.mp4';

// Call the Xcomponent interface to obtain the surface ID and save it to the surfaceID variable.

// Set the surface ID to display the video image.
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// Call the prepare interface to prepare for playback.
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// Call the play interface to start playback.
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```

### Switching to the Next Video Clip

```js
let videoPlayer = undefined; // Used to store instances created by calling the createVideoPlayer method.
let surfaceID = undefined; // Used to save the surface ID returned by the Xcomponent interface.

// Report an error in the case of a function invocation failure.
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// Report an error in the case of a function invocation exception.
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// Set the 'playbackCompleted' event callback, which is triggered when the playback is complete.
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// Call createVideoPlayer to create a VideoPlayer instance.
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// Set the event callbacks.
SetCallBack(videoPlayer);

// Set the URL of the video file selected by the user.
videoPlayer.url = 'file:///data/data/ohos.xxx.xxx/files/test.mp4';

// Call the Xcomponent interface to obtain the surface ID and save it to the surfaceID variable.

// Set the surface ID to display the video image.
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// Call the prepare interface to prepare for playback.
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// Call the play interface to start playback.
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);

// Send the instruction to switch to the next video clip after a period of time.
// Reset the playback configuration.
await videoPlayer.reset().then(() => {
    console.info('reset success');
}, failureCallback).catch(catchCallback);

videoPlayer.url = 'file:///data/data/ohos.xxx.xxx/files/next.mp4';

// Set the surface ID to display the video image.
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// Call the prepare interface to prepare for playback.
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// Call the play interface to start playback.
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```

### Looping a Video Clip

```js
let videoPlayer = undefined; // Used to store instances created by calling the createVideoPlayer method.
let surfaceID = undefined; // Used to save the surface ID returned by the Xcomponent interface.

// Report an error in the case of a function invocation failure.
function failureCallback(error) {
    console.info(`error happened,error Name is ${error.name}`);
    console.info(`error happened,error Code is ${error.code}`);
    console.info(`error happened,error Message is ${error.message}`);
}

// Report an error in the case of a function invocation exception.
function catchCallback(error) {
    console.info(`catch error happened,error Name is ${error.name}`);
    console.info(`catch error happened,error Code is ${error.code}`);
    console.info(`catch error happened,error Message is ${error.message}`);
}

// Set the 'playbackCompleted' event callback, which is triggered when the playback is complete.
function SetCallBack(videoPlayer) {
	videoPlayer.on('playbackCompleted', () => {
        console.info('video play finish');
        
        await videoPlayer.release().then(() => {
    		console.info('release success');
		}, failureCallback).catch(catchCallback);

		videoPlayer = undefined;
        surfaceID = undefined;
    });
}

// Call createVideoPlayer to create a VideoPlayer instance.
await media.createVideoPlayer().then((video) => {
    if (typeof (video) != 'undefined') {
        console.info('createVideoPlayer success!');
        videoPlayer = video;
    } else {
        console.info('createVideoPlayer fail!');
    }
}, failureCallback).catch(catchCallback);

// Set the event callbacks.
SetCallBack(videoPlayer);

// Set the URL of the video file selected by the user.
videoPlayer.url = 'file:///data/data/ohos.xxx.xxx/files/test.mp4';

// Call the Xcomponent interface to obtain the surface ID and save it to the surfaceID variable.

// Set the surface ID to display the video image.
await videoPlayer.setDisplaySurface(surfaceID).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);

// Call the prepare interface to prepare for playback.
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);

// Set the loop playback attribute.
videoPlayer.loop = true;

// Call the play interface to start playback.
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
```
