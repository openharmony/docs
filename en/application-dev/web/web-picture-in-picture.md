# Enabling Picture-in-Picture
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @gzweioh-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->
The web component supports the picture-in-picture (PiP) feature. An application can use the Picture-in-Picture API of the W3C standard to create a floating window on a web page to play videos. In this way, users can continue to watch videos in the PiP window when browsing other web pages or interacting with other applications. 

To use online video resources, you need to set the network permission in the configuration file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

```json
// src/main/module.json5
"requestPermissions": [
  {
    "name": "ohos.permission.INTERNET"
  },
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

Use the **requestPictureInPicture()** method provided by the **HTMLVideoElement** API to enable the PiP feature. If the system supports the PiP feature, the video is displayed in PiP mode.

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
// ...
try {
  if (videoElement !== document.pictureInPictureElement) {
    await videoElement.requestPictureInPicture();
  } else {
    await document.exitPictureInPicture();
  }
}
// ...
```

## Listening for Picture-in-Picture Events

When a user enables the picture-in-picture mode, a floating window is displayed for playing the video. The system specifies that only one picture-in-picture video can be played at a time.
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

* PiP window control: 
  Allows users to double-click a PiP window to zoom in or zoom out the window. 
  Allows users to drag the PiP window to any position on the screen. 
  Allows users to click the PiP window to display or hide UI components at the PiP control layer. 

* UI components at the PiP control layer: 
  The PiP window control layer includes the close (close the PiP window) and restore (restore from the PiP window to the original application UI) components. 
  The playback control includes the pause, play, and forward/rewind components. (By default, the forward/rewind UI component is displayed. If the original video does not support forward/rewind, there is no response for click events.)
  
  ![web-picture-in-picture](figures/web-picture-in-picture-ui.png)


## Example

The following is an example of entering and exiting the PiP mode:

* ETS code on the application side:

  ```ts
  // xxx.ets
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

* Code of the HTML page:

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

      // Listen for the click events to enter or exit the PiP mode.
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
        togglePipButton.textContent = "Exit PiP"
      });

      // Listen for the PiP exit event.
      video.addEventListener("leavepictureinpicture", () => {
        // Update the button text to "Enable PiP"
        togglePipButton.textContent = "Enable PiP"
      });
  </script>
  </body>
  </html>
  ```
