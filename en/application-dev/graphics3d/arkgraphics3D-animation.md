# Controlling and Managing ArkGraphics 3D Scene Animations
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

Animations, an important resource type in a 3D scene, is used to control the motion of elements in the scene. For example, to simulate a scene where a person walks, it is difficult to calculate and set the rotation angle of every joint of the person in each frame. When making such an animation, the resource producer saves key frame data of the animation and the interpolator type between key frames in a model file.

ArkGraphics 3D provides APIs for you to play and control animations to achieve the expected rendering effect in the scene.


## Creating Animation Resources
Animation resources are made and saved to model files by model resource producers when they make the model. ArkGraphics 3D provides the capability of extracting and playing animations from glTF model resources.
```ts
import { Animation, Scene } from '@kit.ArkGraphics3D';

function createAnimation(): void {
  // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result && result.animations && result.animations[0]) {
      // Obtain animation resources.
      let anim: Animation = result.animations[0];
    }
  });
}
```


## Controlling the Animation Status
ArkGraphics 3D provides the following APIs to control the animation status:
- **start**: plays an animation based on the current progress.
- **stop**: stops playing an animation and sets its progress to **0** (not started).
- **finish**: finishes the playing of an animation and sets its progress of **1** (finished).
- **pause**: pauses an animation. The animation remains in the current playing progress.
- **restart**: plays an animation from the beginning.

The sample code is as follows:
```ts
import { Animation, Scene } from '@kit.ArkGraphics3D';

function animationControl(): void {
  // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result && result.animations && result.animations[0]) {
      let anim: Animation = result.animations[0];
      // These are for API demonstration purposes only and do not represent the actual playback process.
      anim.start();
      anim.pause();
      anim.stop();
      anim.restart();
      anim.finish();
    }
  });
}
```


## Using Animation Callbacks
An animation callback function is triggered when an animation enters a certain state. You can perform logic control based on the animation state. ArkGraphics 3D provides the following callback functions:
- **onStarted()**: called when an animation starts to play. The start operation is triggered by calling **start** or **restart**.
- **onFinished()**: called when an animation playback is complete or the **finish** API is called.

The sample code is as follows:
```ts
import { Animation, Scene } from '@kit.ArkGraphics3D';

function callBacks(): void {
  // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
  scene.then(async (result: Scene) => {
    if (result && result.animations && result.animations[0]) {
      let anim: Animation = result.animations[0];
      // Register the callbacks.
      anim.onFinished(()=>{
        console.info("onFinished");
      });
      anim.onStarted(()=>{
        console.info("onStarted");
      });
    }
  });
}
```


<!--RP1-->
