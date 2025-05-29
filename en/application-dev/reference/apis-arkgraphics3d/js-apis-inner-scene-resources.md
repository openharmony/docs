# SceneResource
The SceneResource module provides basic resource types in 3D graphics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import { SceneResourceType, SceneResource, Shader, MaterialType, Material, ShaderMaterial,
  SubMesh, Mesh, Animation, EnvironmentBackgroundType, Environment, Image } from '@kit.ArkGraphics3D';
```
## SceneResourceType
Enumerates the scene resource types, which are used to classify resources in a scene.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Value| Description|
| ---- | ---- | ---- |
| UNKNOWN | 0 | Unknown.|
| NODE | 1 | Node resource.|
| ENVIRONMENT | 2 | Environment resource.|
| MATERIAL | 3 | Material resource.|
| MESH | 4 | Mesh resource.|
| ANIMATION | 5 | Animation resource.|
| SHADER | 6 | Shader resource.|
| IMAGE | 7 | Image resource.|

## SceneResource
Describes a resource in a scene.

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| name | string | No| No| Name. There is no special format requirement.|
| resourceType | [SceneResourceType](#sceneresourcetype) | Yes| No| Scene resource type. The default value is undefined.|
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | Yes| Yes| Resource to load. The default value is undefined.|

### destroy
destroy(): void

Destroys the scene resource and releases all associated resources or references. Once released, the resource can no longer be used or accessed.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function destroy() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      shader.then(async (shaderResult:Shader) => {
         // Release the resource.
         shaderResult.destroy();
      });
    }
  });
}
```

## Shader
Shader resource, which inherits from [SceneResource](#sceneresource).

### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| inputs | Record<string, number \| Vec2 \| Vec3 \| Vec4 \| Image> | Yes| No| Inputs of the shader.|

## MaterialType
Enumerates the material types in a scene.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Value| Description|
| ---- | ---- | ---- |
| SHADER | 1 | Shader-defined.|

## Material
Material resource, which inherits from [SceneResource](#sceneresource).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| materialType | [MaterialType](#materialtype) | Yes| No| Material type.|

## ShaderMaterial
Shader material, which inherits from [Material](#material).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| colorShader | [Shader](#shader) | No| Yes| Shader. The default value is undefined.|

## SubMesh
Sub-mesh resource.
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| name | string | No| No| Name. There is no special format requirement.|
| material | [Material](#material) | No| No| Material.|
| aabb | [Aabb](js-apis-inner-scene-types.md#aabb) | Yes| No| Axis aligned bounding box.|

## Mesh
Mesh resource, which inherits from [SceneResource](#sceneresource).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| subMeshes | [SubMesh](#submesh)[] | Yes| No| Array of sub-meshes.|
| aabb | [Aabb](js-apis-inner-scene-types.md#aabb) | Yes| No| Axis aligned bounding box.|
| materialOverride | [Material](#material) | No| Yes| Material. The default value is undefined.|

## Animation
Animation resource, which inherits from [SceneResource](#sceneresource).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| enabled | boolean | No| No| Whether the animation is enabled. The value **true** means that the animation can be played, and **false** means the opposite.|
| duration | number | Yes| No| Duration of the animation. The value is greater than or equal to 0.|
| running | boolean | Yes| No| Running status of the animation. The value **true** means that the animation is being played, and **false** means the opposite.|
| progress | number | Yes| No| Playing progress of the animation. The value range is [0, 1].|

### onFinished
onFinished(callback: Callback\<void>): void

Called when the animation playback is complete or the **finish** API is called.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| callback | Callback\<void> | Yes| Callback function. The return value is null.|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function onFinished() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Register a callback.
      anim.onFinished(()=>{
        console.info("onFinished");  
      });
    }
  });
}
```

### onStarted
onStarted(callback: Callback\<void>): void

Called when the animation starts to play. The start operation is triggered by calling **start** or **restart**.

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| callback | Callback\<void> | Yes| Callback function. The return value is null.|

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function onStarted() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Register a callback.
      anim.onStarted(()=>{
        console.info("onStarted");  
      });
    }
  });
}
```

### pause
pause(): void

Pauses the animation. The animation remains in the current playing progress.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function pause() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Pause the animation.
      anim.pause();
    }
  });
}
```

### restart
restart(): void

Plays the animation from the beginning.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function restart() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Restart the animation.
      anim.restart();
    }
  });
}
```

### seek
seek(position: number): void

Plays the animation from the specified position.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**
| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| position | number | Yes| Position from which the animation playback starts. The value range is [0, 1].|

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function seek() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Set the animation playback progress to 10%.
      anim.seek(0.1);
    }
  });
}
```

### start
start(): void

Plays the animation based on the current progress.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function start() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Start the animation.
      anim.start();
    }
  });
}
```

### stop
stop(): void

Stops playing the animation and sets its progress to **0** (not started).

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function stop() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Stop playing the animation and set its progress to 0 (not started).
      anim.stop();
    }
  });
}
```

### finish
finish(): void

Finishes the playing of the animation and sets its progress of **1** (finished).

**System capability**: SystemCapability.ArkUi.Graphics3D

```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function finish() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // Finish the playing of the animation and set its progress of **1** (finished).
      anim.finish();
    }
  });
}
```

## EnvironmentBackgroundType
Enumerates the environment background types.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Value| Description|
| ---- | ---- | ---- |
| BACKGROUND_NONE | 0 | No background.|
| BACKGROUND_IMAGE | 1 | Image background.|
| BACKGROUND_CUBEMAP | 2 | Cubemap background.|
| BACKGROUND_EQUIRECTANGULAR | 3 | Equirectangular background.|

## Environment
Environment resource, which inherits from [SceneResource](#sceneresource).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| backgroundType | [EnvironmentBackgroundType](#environmentbackgroundtype) | No| No| Environment background type.|
| indirectDiffuseFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | No| No| Indirect diffuse factor.|
| indirectSpecularFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | No| No| Indirect specular factor.|
| environmentMapFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | No| No| Environment map factor.|
| environmentImage | [Image](#image) \| null | No| Yes| Environment image. The default value is undefined.|
| radianceImage | [Image](#image) \| null | No| Yes| Radiance image. The default value is undefined.|
| irradianceCoefficients | [Vec3](js-apis-inner-scene-types.md#vec3)[] | No| Yes| Irradiance coefficients. The default value is undefined.|

## Image
Image resource, which inherits from [SceneResource](#sceneresource).
### Properties

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name| Type| Read Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| width | number | Yes| No| Image width. The value is greater than 0.|
| height | number | Yes| No| Image height. The value is greater than 0.|
