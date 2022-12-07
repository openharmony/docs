# Media Development

## How do I set a front camera?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

1. Set the camera position to **camera.CameraPosition.CAMERA_POSITION_FRONT**.

2. Create a **CameraInput** instance based on the camera position and type.

Reference: [Camera Management](../reference/apis/js-apis-camera.md)

Example:

```
// The rear camera is set by default. You can use **isFrontCamera** to switch to the rear camera.
let cameraId
let cameraInput
for(let cameraIndex = 0; cameraIndex < this.cameraArray.length; cameraIndex++) {
   let faceType = this.cameraArray[cameraIndex].cameraPosition
   switch(faceType) {
  case camera.CameraPosition.CAMERA_POSITION_FRONT: // Front camera
    if(this.isFrontCamera){
   cameraId = this.cameraArray[cameraIndex].cameraId
    }
	   break
	 case camera.CameraPosition.CAMERA_POSITION_BACK: // Rear camera
	   if(!this.isFrontCamera){
		 cameraId = this.cameraArray[cameraIndex].cameraId
	   }
	   break
	 case camera.CameraPosition.CAMERA_POSITION_UNSPECIFIED:
	 default:
	   break
   }
}
cameraInput = await this.cameraManager.createCameraInput(cameraId)
```

## How do I crop an image?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

1. Create an **ImageSource** instance based on the input URI.
     
   ```
   let path = this.context.getApplicationContext().fileDirs + "test.jpg";
   const imageSourceApi = image.createImageSource(path);
   ```

2. Set decoding parameters and decode the image to obtain a **PixelMap** object. Image processing is supported during decoding.
   - Set **desiredSize** to specify the target size after scaling. If the values are all set to **0**, scaling will not be performed.
   - Set **desiredRegion** to specify the target rectangular area after cropping. If the values are all set to **0**, cropping will not be performed.
   - Set **rotateDegrees** to specify the rotation angle. The image will be rotated clockwise at the center.
        
      ```
      const decodingOptions = {
        desiredSize: {
        height:0,
        width:0
        },
        // Crop a rectangular area.
        desiredRegion: {
        size: {
         height:100,
         width:100
        },
        x:0,
        y:0
        },
        // Rotate the image by 90 degrees.
        rotate:90
      }
      imageSourceApi.createPixelMap(decodingOptions).then(pixelMap => {
        this.handlePixelMap(pixelMap)
      })
      ```

3. Process the obtained **PixelMap** object. For example, render and display the image.

## How do I apply for the media read/write permission on a device?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

1. Configure the permissions **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** in the **module.json5** file.
   Example:

     
   ```
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.READ_MEDIA",
           "reason": "$string:reason"
         },
         {
           "name" : "ohos.permission.WRITE_MEDIA",
           "reason": "$string:reason"
         }
       ]
     }
   }
   ```

2. Call **requestPermissionsFromUser** to request the permissions from end users in the form of a dialog box. This operation is required because the grant mode of both permissions is **user_grant**.
     
   ```
   let permissions: Array<string> = ['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
   context.requestPermissionsFromUser(permissions).then((data) => {
       console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
   }).catch((error) => {
       console.log("Failed to request permission from user with error: " + JSON.stringify(error))
   })
   ```

## Why can't I play MP4 videos?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

Currently, the system does not support the playback of MP4 videos in H.265 format.


## Why can't I play a new video or even encounters a crash after creating more than 10 videos?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

A maximum of 13 media player instances can be created.
