# AVSession Development

## Development for the Session Access End

### Basic Concepts
- **AVMetadata**: media data related attributes, including the IDs of the current media asset, previous media asset, and next media asset, title, author, album, writer, and duration.
- **AVSessionDescriptor**: descriptor about a media session, including the session ID, session type (audio/video), custom session name (**sessionTag**), and information about the corresponding application (**elementName**).
- **AVPlaybackState**: information related to the media playback state, including the playback state, position, speed, buffered time, loop mode, and whether the media asset is favorited (**isFavorite**).

### Available APIs
The table below lists the APIs available for the development of the session access end. The APIs use either a callback or promise to return the result. The APIs listed below use a callback, which provide the same functions as their counterparts that use a promise. For details, see [AVSession Management](../reference/apis/js-apis-avsession.md).

Table 1 Common APIs for session access end development

| API                                                                             | Description         |
|----------------------------------------------------------------------------------|-------------|
| createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void | Creates a session.|
| setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void            | Sets session metadata.    |
| setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void | Sets the playback state information. |
| setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void       | Sets the launcher ability.|
| getController(callback: AsyncCallback\<AVSessionController>): void                | Obtains the controller of this session.|
| getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void                 | Obtains the output device information. |
| activate(callback: AsyncCallback\<void>): void                                    | Activates this session.       |
| destroy(callback: AsyncCallback\<void>): void                                     | Destroys this session.       |

### How to Develop
1. Import the modules.

```js
import avSession from '@ohos.multimedia.avsession';
import wantAgent from '@ohos.wantAgent';
import featureAbility from '@ohos.ability.featureAbility';
```

2. Create and activate a session.
```js
// Define global variables.
let mediaFavorite = false;
let currentSession = null;
let context = featureAbility.getContext();
   
// Create an audio session.
avSession.createAVSession(context, "AudioAppSample", 'audio').then((session) => {
   currentSession = session;
   currentSession.activate(); // Activate the session.
}).catch((err) => {
   console.info(`createAVSession : ERROR : ${err.message}`);
});
```

3. Set the session information, including:
- Session metadata. In addition to the current media asset ID (mandatory), you can set the title, album, author, duration, and previous/next media asset ID. For details about the session metadata, see **AVMetadata** in the API document.
- Launcher ability, which is implemented by calling an API of **WantAgent**. Generally, **WantAgent** is used to encapsulate want information. For more information, see [wantAgent](../reference/apis/js-apis-wantAgent.md).
- Playback state information.
```js
// Set the session metadata.
let metadata  = {
   assetId: "121278",
   title: "lose yourself",
   artist: "Eminem",
   author: "ST",
   album: "Slim shady",
   writer: "ST",
   composer: "ST",
   duration: 2222,
   mediaImage: "https://www.example.com/example.jpg",       // Set it based on your project requirements.
   subtitle: "8 Mile",
   description: "Rap",
   lyric: "https://www.example.com/example.lrc",            // Set it based on your project requirements.
   previousAssetId: "121277",
   nextAssetId: "121279",
};
currentSession.setAVMetadata(metadata).then(() => {
   console.info('setAVMetadata successfully');
}).catch((err) => {
   console.info(`setAVMetadata : ERROR : ${err.message}`);
});
```

```js
// Set the launcher ability.
let wantAgentInfo = {
  wants: [
    {
      bundleName: "com.neu.setResultOnAbilityResultTest1",
      abilityName: "com.example.test.MainAbility",
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentSession.setLaunchAbility(agent).then(() => {
    console.info('setLaunchAbility successfully');
  }).catch((err) => {
    console.info(`setLaunchAbility : ERROR : ${err.message}`);
  });
});
```

```js
// Set the playback state information.
let PlaybackState = {
  state: avSession.PlaybackState.PLAYBACK_STATE_STOP,
  speed: 1.0,
  position:{elapsedTime: 0, updateTime: (new Date()).getTime()},
  bufferedTime: 1000,
  loopMode: avSession.LoopMode.LOOP_MODE_SEQUENCE,
  isFavorite: false,
};
currentSession.setAVPlaybackState(PlaybackState).then(() => {
  console.info('setAVPlaybackState successfully');
}).catch((err) => {
  console.info(`setAVPlaybackState : ERROR : ${err.message}`);
});
```

```js
// Obtain the controller of this session.
currentSession.getController().then((selfController) => {
   console.info('getController successfully');
}).catch((err) => {
   console.info(`getController : ERROR : ${err.message}`);
});
```

```js
// Obtain the output device information.
currentSession.getOutputDevice().then((outputInfo) => {
   console.info(`getOutputDevice successfully, deviceName : ${outputInfo.deviceName}`);
}).catch((err) => {
   console.info(`getOutputDevice : ERROR : ${err.message}`);
});
```

4. Subscribe to control command events.
```js
// Subscribe to the 'play' command event.
currentSession.on('play', () => {
   console.log ("Call AudioPlayer.play.");
   // Set the playback state information.
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PLAY}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});


// Subscribe to the 'pause' command event.
currentSession.on('pause', () => {
   console.log ("Call AudioPlayer.pause.");
   // Set the playback state information.
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PAUSE}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'stop' command event.
currentSession.on('stop', () => {
   console.log ("Call AudioPlayer.stop.");
   // Set the playback state information.
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_STOP}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'playNext' command event.
currentSession.on('playNext', () => {
   // When the media file is not ready, download and cache the media file, and set the 'PREPARE' state.
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PREPARE}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
   // The media file is obtained.
   currentSession.setAVMetadata({assetId: '58970105', title: 'See you tomorrow'}).then(() => {
       console.info('setAVMetadata successfully');
   }).catch((err) => {
       console.info(`setAVMetadata : ERROR : ${err.message}`);
   });
   console.log ("Call AudioPlayer.play.");
   // Set the playback state information.
   let time = (new Data()).getTime();
   currentSession.setAVPlaybackState({state: avSession.PlaybackState.PLAYBACK_STATE_PLAY, position: {elapsedTime: 0, updateTime: time}, bufferedTime:2000}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'fastForward' command event.
currentSession.on('fastForward', () => {
   console.log("Call AudioPlayer for fast forwarding.");
   // Set the playback state information.
   currentSession.setAVPlaybackState({speed: 2.0}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'seek' command event.
currentSession.on('seek', (time) => {
   console.log("Call AudioPlayer.seek.");
   // Set the playback state information.
   currentSession.setAVPlaybackState({position: {elapsedTime: time, updateTime: (new Data()).getTime()}}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'setSpeed' command event.
currentSession.on('setSpeed', (speed) => {
   console.log(`Call AudioPlayer to set the speed to ${speed}`);
   // Set the playback state information.
   currentSession.setAVPlaybackState({speed: speed}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'setLoopMode' command event.
currentSession.on('setLoopMode', (mode) => {
   console.log(`The application switches to the loop mode ${mode}`);
   // Set the playback state information.
   currentSession.setAVPlaybackState({loopMode: mode}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
});

// Subscribe to the 'toggleFavorite' command event.
currentSession.on('toggleFavorite', (assetId) => {
   console.log(`The application favorites ${assetId}.`);
   // Perform the switch based on the last status.
   let favorite = mediaFavorite == false ? true : false;
   currentSession.setAVPlaybackState({isFavorite: favorite}).then(() => {
       console.info('setAVPlaybackState successfully');
   }).catch((err) => {
       console.info(`setAVPlaybackState : ERROR : ${err.message}`);
   });
   mediaFavorite = favorite;
});

// Subscribe to the key event.
currentSession.on('handleKeyEvent', (event) => {
   console.log(`User presses the key ${event.keyCode}`);
});

// Subscribe to output device changes.
currentSession.on('outputDeviceChange', (device) => {
   console.log(`Output device changed to ${device.deviceName}`);
});
```

5. Release resources.
```js
// Unsubscribe from the events.
currentSession.off('play');
currentSession.off('pause');
currentSession.off('stop');
currentSession.off('playNext');
currentSession.off('playPrevious');
currentSession.off('fastForward');
currentSession.off('rewind');
currentSession.off('seek');
currentSession.off('setSpeed');
currentSession.off('setLoopMode');
currentSession.off('toggleFavorite');
currentSession.off('handleKeyEvent');
currentSession.off('outputDeviceChange');

// Deactivate the session and destroy the object.
currentSession.deactivate().then(() => {
   currentSession.destory();
});
```

### Verification
Touch the play, pause, or next button on the media application. Check whether the media playback state changes accordingly.

### FAQs

1. Session Service Exception
- Symptoms

  The session service is abnormal, and the application cannot obtain a response from the session service. For example, the session service is not running or the communication with the session service fails. The error message "Session service exception" is displayed.
  
- Possible causes
  
  The session service is killed during session restart.
  
- Solution

  (1) The system retries the operation automatically. If the error persists for 3 seconds or more, stop the operation on the session or controller.
  
  (2) Destroy the current session or session controller and re-create it. If the re-creation fails, stop the operation on the session.

2. Session Does Not Exist
- Symptoms

  Parameters are set for or commands are sent to the session that does not exist. The error message "The session does not exist" is displayed.

- Possible causes

  The session has been destroyed, and no session record exists on the server.

- Solution

  (1) If the error occurs on the application, re-create the session. If the error occurs on Media Controller, stop sending query or control commands to the session.
  
  (2) If the error occurs on the session service, query the current session record and pass the correct session ID when creating the controller.

3. Session Not Activated
- Symptoms

  A control command or event is sent to the session when it is not activated. The error message "The session not active" is displayed.

- Possible causes

  The session is in the inactive state.

- Solution

  Stop sending the command or event. Subscribe to the session activation status, and resume the sending when the session is activated.

## Development for the Session Control End (Media Controller)

### Basic Concepts
- Remote projection: A local media session is projected to a remote device. The local controller sends commands to control media playback on the remote device.
- Sending key events: The controller controls media playback by sending key events.
- Sending control commands: The controller controls media playback by sending control commands.
- Sending system key events: A system application calls APIs to send system key events to control media playback.
- Sending system control commands: A system application calls APIs to send system control commands to control media playback.

### Available APIs

The table below lists the APIs available for the development of the session control end. The APIs use either a callback or promise to return the result. The APIs listed below use a callback, which provide the same functions as their counterparts that use a promise. For details, see [AVSession Management](../reference/apis/js-apis-avsession.md).

Table 2 Common APIs for session control end development

| API                                                                                           | Description              |
| ------------------------------------------------------------------------------------------------ | ----------------- |
| getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void    | Obtains the descriptors of all sessions. |
| createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void          | Creates a controller.         |
| sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void                            | Sends a key event.       |
| getLaunchAbility(callback: AsyncCallback\<WantAgent>): void                                      | Obtains the launcher ability.          |
| sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void              | Sends a control command.       |
| sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void                       | Send a system key event.    |
| sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void         | Sends a system control command.    |
| castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void | Casts the media session to a remote device.|

### How to Develop
1. Import the modules.
```js
import avSession from '@ohos.multimedia.avsession';
import {Action, KeyEvent} from '@ohos.multimodalInput.KeyEvent';
import wantAgent from '@ohos.wantAgent';
import audio from '@ohos.multimedia.audio';
```

2. Obtain the session descriptors and create a controller.
```js
// Define global variables.
let g_controller = new Array<avSession.AVSessionController>();
let g_centerSupportCmd:Set<avSession.AVControlCommandType> = new Set(['play', 'pause', 'playNext', 'playPrevious', 'fastForward', 'rewind', 'seek','setSpeed', 'setLoopMode', 'toggleFavorite']);
let g_validCmd:Set<avSession.AVControlCommandType>;

// Obtain the session descriptors and create a controller.
avSession.getAllSessionDescriptors().then((descriptors) => {
   descriptors.forEach((descriptor) => {
       avSession.createController(descriptor.sessionId).then((controller) => {
           g_controller.push(controller);
       }).catch((err) => {
           console.error('createController error');
       });
   });
}).catch((err) => {
   console.error('getAllSessionDescriptors error');
});

// Subscribe to the 'sessionCreate' event and create a controller.
avSession.on('sessionCreate', (session) => {
  // After a session is added, you must create a controller.
  avSession.createController(session.sessionId).then((controller) => {
    g_controller.push(controller);
  }).catch((err) => {
    console.info(`createController : ERROR : ${err.message}`);
  });
});
```

3. Subscribe to the session state and service changes.
```js
// Subscribe to the 'activeStateChange' event.
controller.on('activeStateChange', (isActive) => {
  if (isActive) {
    console.log ("The widget corresponding to the controller is highlighted.");
  } else {
    console.log("The widget corresponding to the controller is invalid.");
  }
});

// Subscribe to the 'sessionDestroy' event to enable Media Controller to get notified when the session dies.
controller.on('sessionDestroy', () => {
   console.info('on sessionDestroy : SUCCESS ');
   controller.destroy().then(() => {
       console.info('destroy : SUCCESS ');
   }).catch((err) => {
       console.info(`destroy : ERROR :${err.message}`);
   });
});

// Subscribe to the 'sessionDestroy' event to enable the application to get notified when the session dies.
avSession.on('sessionDestroy', (session) => {
   let index = g_controller.findIndex((controller) => {
       return controller.sessionId == session.sessionId;
   });
   if (index != 0) {
       g_controller[index].destroy();
       g_controller.splice(index, 1);
   }
});

// Subscribe to the 'topSessionChange' event.
avSession.on('topSessionChange', (session) => {
   let index = g_controller.findIndex((controller) => {
       return controller.sessionId == session.sessionId;
   });
   // Place the session on the top.
   if (index != 0) {
       g_controller.sort((a, b) => {
           return a.sessionId == session.sessionId ? -1 : 0;
       });
   }
});

// Subscribe to the 'sessionServiceDie' event.
avSession.on('sessionServiceDie', () => {
   // The server is abnormal, and the application clears resources.
   console.log("Server exception");
})
```

4. Subscribe to media session information changes.
```js
// Subscribe to metadata changes.
let metaFilter = ['assetId', 'title', 'description'];
controller.on('metadataChange', metaFilter, (metadata) => {
   console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

// Subscribe to playback state changes.
let playbackFilter = ['state', 'speed', 'loopMode'];
controller.on('playbackStateChange', playbackFilter, (playbackState) => {
   console.info(`on playbackStateChange state : ${playbackState.state}`);
});

// Subscribe to supported command changes.
controller.on('validCommandChange', (cmds) => {
   console.info(`validCommandChange : SUCCESS : size : ${cmds.size}`);
   console.info(`validCommandChange : SUCCESS : cmds : ${cmds.values()}`);
   g_validCmd.clear();
   for (let c of g_centerSupportCmd) {
       if (cmds.has(c)) {
           g_validCmd.add(c);
       }
   }
});

// Subscribe to output device changes.
controller.on('outputDeviceChange', (device) => {
   console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

5. Control the session behavior.
```js
// When the user touches the play button, the control command 'play' is sent to the session.
if (g_validCmd.has('play')) {
   controller.sendControlCommand({command:'play'}).then(() => {
       console.info('sendControlCommand successfully');
   }).catch((err) => {
       console.info(`sendControlCommand : ERROR : ${err.message}`);
   });
}

// When the user selects the single loop mode, the corresponding control command is sent to the session.
if (g_validCmd.has('setLoopMode')) {
   controller.sendControlCommand({command: 'setLoopMode', parameter: avSession.LoopMode.LOOP_MODE_SINGLE}).then(() => {
       console.info('sendControlCommand successfully');
   }).catch((err) => {
       console.info(`sendControlCommand : ERROR : ${err.message}`);
   });
}

// Send a key event.
let keyItem = {code: 0x49, pressedTime: 123456789, deviceId: 0};
let event = {action: 2, key: keyItem, keys: [keyItem]};
controller.sendAVKeyEvent(event).then(() => {
   console.info('sendAVKeyEvent Successfully');
}).catch((err) => {
   console.info(`sendAVKeyEvent : ERROR : ${err.message}`);
});

// The user touches the blank area on the widget to start the application.
controller.getLaunchAbility().then((want) => {
   console.log("Starting the application in the foreground");
}).catch((err) => {
   console.info(`getLaunchAbility : ERROR : ${err.message}`);
});

// Send the system key event.
let keyItem = {code: 0x49, pressedTime: 123456789, deviceId: 0};
let event = {action: 2, key: keyItem, keys: [keyItem]};
avSession.sendSystemAVKeyEvent(event).then(() => {
   console.info('sendSystemAVKeyEvent Successfully');
}).catch((err) => {
   console.info(`sendSystemAVKeyEvent : ERROR : ${err.message}`);
});

// Send a system control command to the top session.
let avcommand = {command: 'toggleFavorite', parameter: "false"};
avSession.sendSystemControlCommand(avcommand).then(() => {
   console.info('sendSystemControlCommand successfully');
}).catch((err) => {
   console.info(`sendSystemControlCommand : ERROR : ${err.message}`);
});

// Cast the session to another device.
let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
   audioDevices = data;
   console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
   console.info(`getDevices : ERROR : ${err.message}`);
});

avSession.castAudio('all', audioDevices).then(() => {
   console.info('createController : SUCCESS');
}).catch((err) => {
   console.info(`createController : ERROR : ${err.message}`);
});
```

6. Release resources.
```js
// Unsubscribe from the events.
 controller.off('metadataChange');
 controller.off('playbackStateChange');
 controller.off('sessionDestroy');
 controller.off('activeStateChange');
 controller.off('validCommandChange');
 controller.off('outputDeviceChange');
 
 // Destroy the controller.
 controller.destroy().then(() => {
     console.info('destroy : SUCCESS ');
 }).catch((err) => {
     console.info(`destroy : ERROR : ${err.message}`);
 });
```

### Verification
When you touch the play, pause, or next button in Media Controller, the playback state of the application changes accordingly.

### FAQs
1. Controller Does Not Exist
- Symptoms

  A control command or an event is sent to the controller that does not exist. The error message "The session controller does not exist" is displayed.

- Possible causes

  The controller has been destroyed.

- Solution

  Query the session record and create the corresponding controller.

2. Remote Session Connection Failure
- Symptoms

  The communication between the local session and the remote session fails. The error information "The remote session connection failed" is displayed.

- Possible causes

  The communication between devices is interrupted.

- Solution

  Stop sending control commands to the session. Subscribe to output device changes, and resume the sending when the output device is changed.

3. Invalid Session Command
- Symptoms

  The control command or event sent to the session is not supported. The error message "Invalid session command" is displayed.

- Possible causes

  The session does not support this command.

- Solution

  Stop sending the command or event. Query the commands supported by the session, and send a command supported.

4. Too Many Commands or Events
- Symptoms

  The session client sends too many messages or commands to the server in a period of time, causing the server to be overloaded. The error message "Command or event overload" is displayed.

- Possible causes

  The server is overloaded with messages or events.

- Solution

  Control the frequency of sending commands or events.
