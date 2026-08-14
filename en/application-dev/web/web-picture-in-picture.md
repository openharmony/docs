# Enabling Picture-in-Picture

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @gzweioh-->
<!--Designer: @zhangyao75477-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=4ac10367d8e4dd9081bfcad4a5715a3db45fc0ba translatedAt=2026-08-14T03:48:56.272Z pushedAt=2026-08-14T09:29:59.039Z -->

The web component supports the picture-in-picture (PiP) feature. An application can use the Picture-in-Picture API of the W3C standard to create a floating window on a web page to play videos. In this way, users can continue to watch videos in the PiP window when browsing other web pages or interacting with other applications. 

To use online video resources, you need to set the network permission in the configuration file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

<!-- @[web_picture_permissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ArkWebPictureInPicture/entry/src/main/module.json5) -->

``` JSON5
"requestPermissions": [
  {
    "name": "ohos.permission.INTERNET"
  }
]
```

## Constraints

1. H.264/H.265/HLS videos can be played in the PiP window. 

2. The size of the PiP window is adjusted based on the system capability. For details, see the system features and capabilities in the design guide.

## Entering Picture-in-Picture

In the following example, a video element that includes only a media source and a button element for user interaction are used to describe how to create a PiP window, through which a user can continuously watch a video when browsing another web page or interacting with another application.

```html
<!-- Replace the URL with the actual URL of the video source -->
<video id="video" src="https://example.com/file.mp4" controls></video>
<button id="togglePipButton">Enable PiP</button>
```

The **requestPictureInPicture()** method provided by the **HTMLVideoElement** interface requests to enter the picture-in-picture mode. If the system supports the picture-in-picture capability, the video is displayed in picture-in-picture mode.

```js
togglePipButton.addEventListener("click", async () => {
  try {
    // Request to enter the picture-in-picture mode.
    await video.requestPictureInPicture();
  } catch (err) {
    // If the PiP mode fails to be switched, an error message is displayed.
    console.error("Picture-in-Picture mode failed:", err);
  }
});
```

## Exiting Picture-in-Picture

To exit the PiP mode, use the **exitPictureInPicture()** method of the **Document** API to display the video on the original tab page.

```js
// Example: Obtain the video element first.
const video = document.getElementById('video');

try {
  if (video !== document.pictureInPictureElement) {
    await video.requestPictureInPicture();
  } else {
    await document.exitPictureInPicture();
  }
}
// ...
```

## Listening for Picture-in-Picture Events

When you enter the picture-in-picture mode to play a video, a floating window is displayed for video playback. The system allows only one picture-in-picture video to be played at a time.

When **HTMLVideoElement** successfully enters the PiP mode, the **enterpictureinpicture** event is triggered. When **HTMLVideoElement** successfully exits the PiP mode, the **leavepictureinpicture** event is triggered.

You can handle these events by listening for them.

```js
videoElement.addEventListener('enterpictureinpicture', function (event) {
// The video enters the PiP mode.
});

videoElement.addEventListener('leavepictureinpicture', function (event) {
// The video exits the PiP mode.
});
```

## Interacting with the Picture-in-Picture Window

* PiP window control:<br>

  Allows users to double-click a PiP window to zoom in or zoom out the window.<br>
  Allows users to drag the PiP window to any position on the screen.<br> 
  Allows users to click the PiP window to display or hide UI components at the PiP control layer.<br> 

* UI components at the PiP control layer:<br> 

  The picture-in-picture window control layer contains **Close** (closes the picture-in-picture window) and **Restore** (restores the original app UI from the picture-in-picture window).<br/>  
  Playback controls include **Pause**, **Play**, and **Forward/Backward** (the Forward/Backward UI controls are displayed by default; if the original video does not support forward/backward, a single tap has no effect).<br/>

  ![web-picture-in-picture](figures/web-picture-in-picture-ui.png)

## Example

The following is an example of entering and exiting the PiP mode:

* ETS code on the application side:

  <!-- @[web_picture_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ArkWebPictureInPicture/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  import { webview } from '@kit.ArkWeb';
  
  @Entry
  @Component
  struct Index {
    @State videoSrc: Resource = $rawfile('PictureInPicture.html');
    controller: webview.WebviewController = new webview.WebviewController();
  
    build() {
      Column() {
        Web({src: this.videoSrc, controller: this.controller})
      }
    }
  }
  ```

* Frontend page HTML code.

  ```html
  <!-- PictureInPicture.html -->
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1.0" />
      <title>Picture-in-Picture Demo</title>
      <style>
          body {
            font-family: Arial, sans-serif;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            margin: 0;
          }
          video {
            width: 60%;
            border: 1px solid #ccc;
            border-radius: 8px;
            margin-bottom: 20px;
          }
          button {
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
          }
      </style>
  </head>
  <body>
  <!-- Replace the URL with the actual URL of the video source -->
  <video id="video" src="https://example.com/file.mp4" controls></video>
  <button id="togglePipButton">Enable PiP</button>

  <script>
      const video = document.getElementById("video");
      const togglePipButton = document.getElementById("togglePipButton");

      // If the browser does not support the PiP feature or the feature is disabled, the button is hidden.
      togglePipButton.hidden =
        !document.pictureInPictureEnabled || video.disablePictureInPicture;

      // Listen for the button click event and toggle picture-in-picture mode.
      togglePipButton.addEventListener("click", async () => {
        try {
          if (document.pictureInPictureElement) {
            // If the PiP mode is used, exit the PiP mode.
            await document.exitPictureInPicture();
          } else {
            // Otherwise, enter the PiP mode.
            await video.requestPictureInPicture();
          }
        } catch (err) {
          // If the PiP mode fails to be switched, an error message is displayed.
          console.error("Picture-in-Picture mode failed:", err);
        }
      });

      // Listen for the PiP enter event.
      video.addEventListener("enterpictureinpicture", () => {
        // Update the button text to "Exit PiP"
        togglePipButton.textContent = "Exit PiP";
      });

      // Listen for the PiP exit event.
      video.addEventListener("leavepictureinpicture", () => {
        // Update the button text to "Enable PiP"
        togglePipButton.textContent = "Enable PiP";
      });
  </script>
  </body>
  </html>
  ```