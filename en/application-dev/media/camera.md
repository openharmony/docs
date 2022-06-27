# Camera Development

## When to Use

You can use the camera module to develop basic camera functions, including previewing, photographing, and video recording.  

## How to Develop

### Available APIs

For details about the APIs, see [Camera Management](../reference/apis/js-apis-camera.md).

### Full-Process Scenario

The full process includes creating an instance, setting parameters, managing sessions, taking photos, recording videos, and releasing resources.

The method for creating an XComponent is also provided. For details, see [XComponent Creation](#xcomponent-creation).

For details about the APIs used to save images, see [Image Processing](../reference/apis/js-apis-image.md).

#### Creating an Instance

```js
import camera from '@ohos.multimedia.camera'
import image from '@ohos.multimedia.image'
import media from '@ohos.multimedia.media'
import featureAbility from '@ohos.ability.featureAbility'

// Create a CameraManager object.
let cameraManager
await camera.getCameraManager(globalThis.Context, (err, manager) => {
    if (err) {
        console.error('Failed to get the CameraManager instance ${err.message}');
        return;
    }
    console.log('Callback returned with the CameraManager instance');
    cameraManager = manager
})

// Register a callback to listen for camera status changes and obtain the updated camera status information.
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})

// Obtain the camera list.
let cameraArray
await cameraManager.getCameras((err, cameras) => {
    if (err) {
        console.error('Failed to get the cameras. ${err.message}');
        return;
    }
    console.log('Callback returned with an array of supported cameras: ' + cameras.length);
    cameraArray = cameras
})

for(let cameraIndex = 0; cameraIndex < cameraArray.length; cameraIndex) {
    console.log('cameraId : ' + cameraArray[cameraIndex].cameraId)                          // Obtain the camera ID.
    console.log('cameraPosition : ' + cameraArray[cameraIndex].cameraPosition)              // Obtain the camera position.
    console.log('cameraType : ' + cameraArray[cameraIndex].cameraType)                      // Obtain the camera type.
    console.log('connectionType : ' + cameraArray[cameraIndex].connectionType)              // Obtain the camera connection type.
}

// Create a camera input stream.
let cameraInput
await cameraManager.createCameraInput(cameraArray[0].cameraId).then((input) => {
    console.log('Promise returned with the CameraInput instance');
    cameraInput = input
})

// Create a preview output stream.
let previewOutput
camera.createPreviewOutput((globalThis.surfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with previewOutput instance');
    previewOutput = output
});

// Create an ImageReceiver object and set image parameters.
let imageReceiver = await image.createImageReceiver(1920, 1080, 4, 8)
// Obtain the surface ID for displaying the photos.
let photoSurfaceId = await imageReceiver.getReceivingSurfaceId()
// Create a photographing output stream.
let photoOutput
camera.createPhotoOutput((photoSurfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the PhotoOutput instance.');
    photoOutput = output
});

// Define video recording parameters.
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
    videoFrameWidth : 640,
    videoFrameHeight : 480,
    videoFrameRate : 30
}
let videoConfig = {
    audioSourceType : 1,
    videoSourceType : 0,
    profile : videoProfile,
    url : 'file:///data/media/01.mp4',
    orientationHint : 0,
    location : { latitude : 30, longitude : 130 },
}

// Create a video recording output stream.
let videoRecorder
await media.createVideoRecorder().then((recorder) => {
    console.log('createVideoRecorder called')
    videoRecorder = recorder
})
// Set video recording parameters.
await videoRecorder.prepare(videoConfig)
// Obtain the surface ID for video recording.
await videoRecorder.getInputSurface().then((id) => {
    console.log('getInputSurface called')
    videoSurfaceId = id
})
```
For details about how to create a video recorder, see [Video Recording Development](./video-recorder.md).
```js
// Create a VideoOutput object.
let videoOutput
camera.createVideoOutput((surfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the VideoOutput instance');
    videoOutput = output
});

```

#### Setting Parameters

```js
// Check whether the camera has flash.
let flashStatus
await cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
    flashStatus = status
})
if(flashStatus) {
    // Check whether the auto flash mode is supported.
    let flashModeStatus
    cameraInput.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO, (err, status) => {
        if (err) {
            console.error('Failed to check whether the flash mode is supported. ${err.message}');
            return;
        }
        console.log('Callback returned with the flash mode support status: ' + status);
        flashModeStatus = status
    })
    if(flashModeStatus) {
        // Set the flash mode to auto.
        cameraInput.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO, (err) => {
            if (err) {
                console.error('Failed to set the flash mode  ${err.message}');
                return;
            }
            console.log('Callback returned with the successful execution of setFlashMode.');
        })
    }
}

// Check whether the continuous auto focus is supported.
let focusModeStatus
cameraInput.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO, (err, status) => {
    if (err) {
        console.error('Failed to check whether the focus mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the focus mode support status: ' + status);
    focusModeStatus = status
})
if(focusModeStatus) {
    // Set the focus mode to continuous auto focus.
    cameraInput.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO, (err) => {
        if (err) {
            console.error('Failed to set the focus mode  ${err.message}');
            return;
        }
        console.log('Callback returned with the successful execution of setFocusMode.');
    })
}

// Obtain the zoom ratio range supported by the camera.
let zoomRatioRange
cameraInput.getZoomRatioRange((err, range) => {
    if (err) {
        console.error('Failed to get the zoom ratio range. ${err.message}');
        return;
    }
    console.log('Callback returned with zoom ratio range: ' + range.length);
    zoomRatioRange = range
})

// Set a zoom ratio.
cameraInput.setZoomRatio(zoomRatioRange[0], (err) => {
    if (err) {
        console.error('Failed to set the zoom ratio value ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setZoomRatio.');
})
```

#### Managing Sessions

##### Creating a Session

```js
// Create a Context object.
let context = featureAbility.getContext()

// Create a session.
let captureSession
await camera.createCaptureSession((context), (err, session) => {
    if (err) {
        console.error('Failed to create the CaptureSession instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CaptureSession instance.' + session);
    captureSession = session
});

// Start configuration for the session.
await captureSession.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});

// Add the camera input stream to the session.
await captureSession.addInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to add the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is added.');
});

// Add the preview input stream to the session.
await captureSession.addOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to add the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is added.');
});

// Add the photographing output stream to the session.
await captureSession.addOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to add the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is added.');
});

// Commit the session configuration.
await captureSession.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});

// Start the session.
await captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

##### Switching a Session

```js
// Stop the current session.
await captureSession.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});

// Start configuration for the session.
await captureSession.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});

// Remove the photographing output stream from the session.
await captureSession.removeOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is removed.');
});

// Add a video recording output stream to the session.
await captureSession.addOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to add the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is added.');
});

// Commit the session configuration.
await captureSession.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});

// Start the session.
await captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

#### Taking Photos

```js
let settings = {
    quality: camera.QualityLevel.QUALITY_LEVEL_HIGH                                      // Set the image quality to high.
    rotation: camera.ImageRotation.ROTATION_0,                                           // Set the image rotation angle to 0.
}
// Use the current photographing settings to take photos.
photoOutput.capture(settings, (err) => {
    if (err) {
        console.error('Failed to capture the photo ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

#### Recording Videos

```js
// Start the video recording output stream.
videoOutput.start((err) => {
    if (err) {
        console.error('Failed to start the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output start success.');
});

// Start video recording.
await videoRecorder.start().then(() => {
    console.info('videoRecorder start success');
}

// Stop video recording.
await videoRecorder.stop().then(() => {
    console.info('stop success');
}

// Stop the video recording output stream.
await videoOutput.stop((err) => {
    if (err) {
        console.error('Failed to stop the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
});
```

#### Releasing Resources

```js
// Stop the current session.
await captureSession.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});
// Release the camera input stream.
await cameraInput.release((err) => {
    if (err) {
        console.error('Failed to release the CameraInput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is released successfully.');
});
// Release the preview output stream.
await previewOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
// Release the photographing output stream.
await photoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is released successfully.');
});
// Release the video recording output stream.
await videoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is released successfully.');
});
// Release the session.
await captureSession.release((err) => {
    if (err) {
        console.error('Failed to release the CaptureSession instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
});
```

#### XComponent Creation
The surface ID must be obtained for image preview.

```js
mXComponentController: XComponentController = new XComponentController                   // Create an XComponentController.

build() {
    Flex() {
        XComponent({                                                                     // Create an XComponent.
            id: '',
            type: 'surface',
            libraryname: '',
            controller: this.mXComponentController
        })
        .onload(() => {                                                                  // Set the onload callback.
            // Set the width and height of the surface to 1920 and 1080, respectively.
            this.mXComponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080})
            // Obtain the surface ID.
            globalThis.surfaceId = mXComponentController.getXComponentSurfaceId()
        })
        .width('1920px')                                                                 // Set the width of the XComponent.
        .height('1080px')                                                                // Set the height of the XComponent.
    }
}
```
