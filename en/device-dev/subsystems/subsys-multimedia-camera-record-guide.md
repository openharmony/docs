# Video Recording Development


## When to Use

Use the camera module APIs to capture video streams.


## Available APIs

For details, see [Available APIs](subsys-multimedia-camera-photo-guide.md#available-apis).


## Constraints

None


## How to Develop

1. Perform step 1 through step 4 described in [Photographing Development](subsys-multimedia-camera-photo-guide.md).

2. Obtain the **FrameConfig** instance for video recording.
     
   ```
   /* Obtain the surface from the recorder. */
   Surface *surface = recorder_->GetSurface(0);
   surface->SetWidthAndHeight(1920, 1080);
   surface->SetQueueSize(3);
   surface->SetSize(1024 * 1024);
   /* Add the surface to the FrameConfig instance. */
   FrameConfig *fc = new FrameConfig(FRAME_CONFIG_RECORD);
   fc->AddSurface(*surface);
   ```

3. Start and stop video recording.
     
   ```
   stateCallback->camera_->TriggerLoopingCapture(*fc); // Start recording.
   stateCallback->camera_->StopLoopingCapture();       // Stop recording.
   ```
