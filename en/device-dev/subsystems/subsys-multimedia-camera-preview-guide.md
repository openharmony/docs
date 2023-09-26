# Previewing Development


## When to Use

Use the camera module APIs to generate and play video streams.


## Available APIs

For details, see [Available APIs](subsys-multimedia-camera-photo-guide.md#available-apis).


## Constraints

None


## How to Develop

1. Perform step 1 through step 4 described in [Photographing Development](subsys-multimedia-camera-photo-guide.md).

2. Set the preview area.
     
   ```
   Surface *surface = Surface::CreateSurface();
   /* Set the display area. */
   surface->SetUserData("region_position_x", "480"); // X-coordinate of the upper left corner of the rectangle.
   surface->SetUserData("region_position_y", "270"); // Y-coordinate of the upper left corner of the rectangle.
   surface->SetUserData("region_width", "960"); // Width.
   surface->SetUserData("region_height", "540"); // Height.
   
   fc->AddSurface(*surface);
   ```

3. Start and stop previewing.
     
   ```
   stateCallback->camera_->TriggerLoopingCapture(*fc); // Start previewing.
   stateCallback->camera_->StopLoopingCapture(); // Stop previewing.
   ```
