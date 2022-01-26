# Development Guide for usage of SoundManager

## **Summary**
This guide will show you how to use SoundManager to save and retrieve the ringtone, alarm and notification uris.
Also the document explains how to use ringtone player APIs to play a ringtone uri.

## **SoundManager Framework**
The SoundManager interface consists of APIs which are used to save and retrieve ringtone, alarm and notification uris.
Other APIs required for ringtone playback is also provided by SoundManager. All the uris will be saved in persistent memory of the device.

Please see [**SystemSoundManager**](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-audio.md##systemsoundmanager) for the list of APIs supported by SoundManager.


## **Usage**
- Here's an example of how to use SoundManager to save and retrieve alarm uri
1. Use **getSystemSoundManager** to get an SoundManager instance.\
   This object can be used to set and get alarm uri
   ```
    const systemSoundManager = audio.getSystemSoundManager();
   ```

2. Use **setSystemAlarmUri** to save system alarm uri\
   Application should provide the application *context*, the *uri* to be saved while using this API.

   ```
    systemSoundManager.setSystemAlarmUri(context, '/data/media/alarm.wav', (err)=> {
        if (err) {
            console.error('Failed to setSystemAlarmUri');
        } else {
            console.log('Callback invoked to indicate a successful system alarm uri setting.');
        }
    })
   ```

3. Use **getSystemAlarmUri** to fetch system alarm uri\
   Application should provide the application *context* while using this API.

   ```
    systemSoundManager.getSystemAlarmUri(context, (err, alarmUri)=>{
        if (err) {
            console.err('getSystemAlarmUri failed');
        } else {
            console.log('getSystemAlarmUri success: ' + alarmUri);
        }
    })
   ```


- Here's another example of how to use SoundManager for ringtone uri playback
1. Use **getSystemSoundManager** to get an SoundManager instance.
   ```
    const systemSoundManager = audio.getSystemSoundManager();
   ```

2. Use **setSystemRingtoneUri** to set system ringtone uri\
   Application should provide the application *context*, *uri* to be saved and the [*RingtoneType*](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-audio.md#ringtonetype8) while using this API.

   ```
    systemSoundManager.setSystemRingtoneUri(context, '/data/media/ringtone_sim1.wav',
        audio.RingtoneType.RINGTONE_TYPE_DEFAULT, (err)=> {
        if (err) {
            console.error('Failed to setSystemRingtoneUri');
        } else {
            console.log('Callback invoked to indicate a successful system ringtone uri setting.');
        }
    })
   ```

3. Use **getSystemRingtonePlayer** to get ringtone player instance\
   Application should provide the application *context* and the [*RingtoneType*](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-audio.md#RingtoneType8) while using this api.

    ```
    systemSoundManager.getSystemRingtonePlayer(null, audio.RingtoneType.RINGTONE_TYPE_DEFAULT, (err, ringtonePlayer)=>{
        if (err) {
            console.err('getSystemRingtonePlayer failed');
        } else {
            console.log('getSystemRingtonePlayer success: ');
        }
    });
    ```

4. Use **configure** api to configure the ringtone player
   [*RingtoneOptions*](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-audio.md#ringtoneoptions8) should be provided while using this api.

    ```
    let ringtoneOptions = {
        volume: 1,
        loop: false
    };

    ringtonePlayer.configure(ringtoneOptions, (err)=> {
        if (err) {
            console.error('Failed to configure ringtone options');
        } else {
            console.log('Callback invoked to indicate a successful ringtone options configuration.');
        }
    });
    ```

5. Use **start** api to start playing the ringtone\
   *Note*: If *loop* was true in configure, the ringtone will continue to play until its stopped explicity.
    ```
    ringtonePlayer.start((err)=> {
        if (err) {
            console.error('Failed to start playing ringtone');
        } else {
            console.log('Ringtone start playing successfully.');
        }
    });
    ```

6. Use **stop** api to stop the ringtone while play is in progress
    ```
    ringtonePlayer.stop((err)=> {
        if (err) {
            console.error('Failed to stop playing ringtone');
        } else {
            console.log('Ringtone stop playing successfully.');
        }
    });
    ```

7. Use **release** api to release the ringtone player resources
    ```
    ringtonePlayer.release((err)=> {
        if (err) {
            console.error('Failed to release ringtone player resource');
        } else {
            console.log('Release ringtone player resource successfully.');
        }
    });
    ```

## **Other APIs**
ringtonePlayer object provides few more apis like;

1. **state**
   This is a readonly variable, which will contain the current state of the ringtone player.
   ```
    let playerState = ringtonePlayer.state
    ```

2. **getTitle**
   This api will return the title of the ringtone uri from the file metadata

    ```
    ringtonePlayer.getTitle((err, title)=>{
        if (err) {
            console.err('getTitle failed');
        } else {
            console.log('getTitle success: ' + title);
        }
    });
    ```

3. **getAudioRendererInfo**
   This api will return the audio renderer information
    ```
    ringtonePlayer.getAudioRendererInfo((err, rendererInfo)=>{
        if (err) {
            console.err('getAudioRendererInfo failed');
        } else {
            console.log('getAudioRendererInfo success');
        }
    });
    ```
