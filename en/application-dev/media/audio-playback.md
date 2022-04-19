# Audio Playback Development

## When to Use

You can use audio playback APIs to convert audio data into audible analog signals, play the signals using output devices, and manage playback tasks.

**Figure 1** Playback status

![en-us_image_audio_state_machine](figures/en-us_image_audio_state_machine.png)



**Figure 2** Layer 0 diagram of audio playback

![en-us_image_audio_player](figures/en-us_image_audio_player.png)

## How to Develop

For details about the APIs, see [AudioPlayer in the Media API](../reference/apis/js-apis-media.md).

### Full-Process Scenario

The full audio playback process includes creating an instance, setting the URI, playing audio, seeking to the playback position, setting the volume, pausing playback, obtaining track information, stopping playback, resetting the player, and releasing resources.

For details about the **src** media source input types supported by **AudioPlayer**, see the [src attribute](../reference/apis/js-apis-media.md#audioplayer_attributes).

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

function SetCallBack(audioPlayer) {
    audioPlayer.on('dataLoad', () => {              // Set the 'dataLoad' event callback, which is triggered when the src attribute is set successfully.
        console.info('audio set source success');
        // The playback page is ready. You can click the Play button to start the playback.
    });
    audioPlayer.on('play', () => {                  // Set the 'play' event callback.
        console.info('audio play success');
        // The Play button is changed to the pausable state.
    });
    audioPlayer.on('pause', () => {                 // Set the 'pause' event callback.
        console.info('audio pause success');
        // The Play button is changed to the playable state.
    });
    audioPlayer.on('stop', () => {                  // Set the 'stop' event callback.
        console.info('audio stop success');
        // The playback stops, the playback progress bar returns to 0, and the Play button is changed to the playable state.
    });
    audioPlayer.on('reset', () => {                 // Set the 'reset' event callback.
        console.info('audio reset success');
        // You can reconfigure the src attribute to play another audio file.
    });
    audioPlayer.on('timeUpdate', (seekDoneTime) => {// Set the 'timeUpdate' event callback.
        if (typeof(seekDoneTime) == 'undefined') {
            console.info('audio seek fail');
            return;
        }
        console.info('audio seek success, and seek time is ' + seekDoneTime);
        // The playback progress bar is updated to the seek position.
    });
    audioPlayer.on('volumeChange', () => {          // Set the 'volumeChange' event callback.
        console.info('audio volumeChange success');
        // Display the updated volume.
    });
    audioPlayer.on('finish', () => {                // Set the 'finish' event callback, which is triggered when the playback is complete.
        console.info('audio play finish');
    });
    audioPlayer.on('error', (error) => {            // Set the 'error' event callback.
        console.info(`audio error called, errName is ${error.name}`);
        console.info(`audio error called, errCode is ${error.code}`);
        console.info(`audio error called, errMessage is ${error.message}`);
    });
}

function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('audio key is ' + item);
        console.info('audio value is ' + property);
    }
}

// 1. Create an audioPlayer instance.
let audioPlayer = media.createAudioPlayer();
SetCallBack(audioPlayer);                          // Set the event callbacks.
// 2. Set the URI of the audio file selected by the user.
let fdPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

audioPlayer.src = fdPath;                         // Set the src attribute and trigger the 'dataLoad' event callback.
// 3. Play the audio file.
audioPlayer.play();                               // The play() API can be invoked only after the 'dataLoad' event callback is complete. The 'play' event callback is triggered.
// 4. Seek to the playback position.
audioPlayer.seek(30000);                          // Trigger the 'timeUpdate' event callback, and seek to 30000 ms for playback.
// 5. Set the volume.
audioPlayer.setVolume(0.5);                       // Trigger the 'volumeChange' event callback.
// 6. Pause the playback.
audioPlayer.pause();                              // Trigger the 'pause' event callback and pause the playback.
// 7. Obtain the track information.
audioPlayer.getTrackDescription((error, arrlist) => {  // Obtain the audio track information in callback mode.
    if (typeof (arrlist) != 'undefined') {
        for (let i = 0; i < arrlist.length; i++) {
            printfDescription(arrlist[i]);
        }
    } else {
        console.log(`audio getTrackDescription fail, error:${error.message}`);
    }
});
// 8. Stop the playback.
audioPlayer.stop();                              // Trigger the 'stop' event callback.
// 9. Reset the player.
audioPlayer.reset();                             // Trigger the 'reset' event callback, and reconfigure the src attribute to switch to the next song.
// 10. Release the resource.
audioPlayer.release();                           // Release the AudioPlayer instance.
audioPlayer = undefined;
```

### Normal Playback Scenario

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

function SetCallBack(audioPlayer) {
    audioPlayer.on('dataLoad', () => {              // Set the 'dataLoad' event callback, which is triggered when the src attribute is set successfully.
        console.info('audio set source success');
        audioPlayer.play();                         // Call the play() API to start the playback and trigger the 'play' event callback.
    });
    audioPlayer.on('play', () => {                  // Set the 'play' event callback.
        console.info('audio play success');
    });
    audioPlayer.on('finish', () => {                // Set the 'finish' event callback, which is triggered when the playback is complete.
        console.info('audio play finish');
        audioPlayer.release();                      // Release the AudioPlayer instance.
		audioPlayer = undefined;
    });
}

let audioPlayer = media.createAudioPlayer();       // Create an AudioPlayer instance.
SetCallBack(audioPlayer);                          // Set the event callbacks.
/* Set the FD (local playback) of the audio file selected by the user. */
let fdPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

audioPlayer.src = fdPath;                           // Set the src attribute and trigger the 'dataLoad' event callback.
```

### Switching to the Next Song

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

function SetCallBack(audioPlayer) {
    audioPlayer.on('dataLoad', () => {              // Set the 'dataLoad' event callback, which is triggered when the src attribute is set successfully.
        console.info('audio set source success');
        audioPlayer.play();                         // Call the play() API to start the playback and trigger the 'play' event callback.
    });
    audioPlayer.on('play', () => {                  // Set the 'play' event callback.
        console.info('audio play success');
    });
    audioPlayer.on('finish', () => {                // Set the 'finish' event callback, which is triggered when the playback is complete.
        console.info('audio play finish');
        audioPlayer.release();                      // Release the AudioPlayer instance.
		audioPlayer = undefined;
    });
}

let audioPlayer = media.createAudioPlayer();       // Create an AudioPlayer instance.
SetCallBack(audioPlayer);                          // Set the event callbacks.
/* Set the FD (local playback) of the audio file selected by the user. */
let fdPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

audioPlayer.src = fdPath;                           // Set the src attribute and trigger the 'dataLoad' event callback.
/* Send the instruction to switch to the next song after a period of time. */
audioPlayer.reset();

/* Set the FD (local playback) of the audio file selected by the user. */
let fdNextPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\02.mp3 /data/accounts/account_0/appdata" command.
let nextPath = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/02.mp3';
await fileIO.open(nextPath).then(fdNumber) => {
   fdNextPath = fdNextPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdNextPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});
audioPlayer.src = fdNextPath;
```

### Looping a Song

```js
import media from '@ohos.multimedia.media'
import fileIO from '@ohos.fileio'

function SetCallBack(audioPlayer) {
    audioPlayer.on('dataLoad', () => {              // Set the 'dataLoad' event callback, which is triggered when the src attribute is set successfully.
        console.info('audio set source success');
        audioPlayer.play();                         // Call the play() API to start the playback and trigger the 'play' event callback.
    });
    audioPlayer.on('play', () => {                  // Set the 'play' event callback.
        console.info('audio play success');
    });
    audioPlayer.on('finish', () => {                // Set the 'finish' event callback, which is triggered when the playback is complete.
        console.info('audio play finish');
        audioPlayer.release();                      // Release the AudioPlayer instance.
		audioPlayer = undefined;
    });
}

let audioPlayer = media.createAudioPlayer();       // Create an AudioPlayer instance.
SetCallBack(audioPlayer);                          // Set the event callbacks.

/* Set the FD (local playback) of the audio file selected by the user. */
let fdPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = 'data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
   console.info('open fd failed err is' + err);
});

audioPlayer.src = fdPath;                           // Set the src attribute and trigger the 'dataLoad' event callback.
audioPlayer.loop = true;                            // Set the loop playback attribute.
```

## Samples

The following samples are provided to help you better understand how to develop audio playback:

- [`JsDistributedMusicPlayer`: Distributed Music Player (JS) (API7)](https://gitee.com/openharmony/app_samples/tree/master/ability/JsDistributedMusicPlayer)

- [`JsAudioPlayer`: Audio Playback and Management (JS) (API7)](https://gitee.com/openharmony/app_samples/tree/master/media/JsAudioPlayer)

- [Audio Player](https://gitee.com/openharmony/codelabs/tree/master/Media/Audio_OH_ETS)
