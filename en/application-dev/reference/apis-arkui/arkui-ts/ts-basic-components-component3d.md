# Component3D
The **Component3D** component is used to load 3D model resources and create custom rendering. It is typically used to present 3D animations.

>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported


## APIs

Component3D((sceneOptions?: SceneOptions))

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name         | Type                             | Mandatory  | Description                                    |
| ------------ | --------------------------------- | ---- | ---------------------------------------- |
| sceneOptions | [SceneOptions](#sceneoptions) | No   | 3D scene configuration.<br>**NOTE**<br> The 3D scene configuration cannot be dynamically modified after the component is created.|


## SceneOptions

Provides the 3D scene configuration options.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name       | Type                              | Mandatory  | Description                                      |
| --------- | -------------------------------- | ---- | ---------------------------------------- |
| scene     | [Resource](ts-types.md#resource)\|[Scene](../../apis-arkgraphics3d/js-apis-inner-scene.md#scene-1)<sup>12+</sup> | No   | 3D model resource file or scene object.<br>Default value: **undefined**<br>**NOTE**<br>Currently, only GLTF files are supported.|
| modelType | [ModelType](#modeltype) | No   | Composition mode of the 3D scene.<br>Default value: **ModelType.SURFACE**<br>**NOTE**<br>**ModelType.TEXTURE**: The GPU is used for composition.<br>**ModelType.SURFACE**: Dedicated hardware is used for composition.<br>In general cases, leave this parameter at its default settings.|

## ModelType

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name     | Description            |
| ------- | -------------- |
| TEXTURE | The GPU is used for composition of the 3D scene.|
| SURFACE | Dedicated hardware is used for composition of the 3D scene. |


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### environment

environment(uri: Resource)

Sets the 3D environment resource. Currently, only GLTF files are supported. Model resources cannot be dynamically modified after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type                            | Mandatory| Description        |
| ------ | -------------------------------- | ---- | ------------ |
| uri    | [Resource](ts-types.md#resource) | Yes  | 3D environment resource.|

### customRender

customRender(uri: Resource, selfRenderUpdate: boolean)

Sets the custom 3D scene rendering pipeline. **uri** and **selfRenderUpdate** cannot be dynamically modified after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name          | Type                            | Mandatory| Description                                                        |
| ---------------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| uri              | [Resource](ts-types.md#resource) | Yes  | Configuration file for creating a custom rendering pipeline.                                  |
| selfRenderUpdate | boolean                          | Yes  | Whether rendering can be triggered when the external UI is not updated.<br>The value **true** means that rendering can be triggered when the external UI is not updated, and false means the opposite.|

### shader

shader(uri: Resource)

Sets the shader file for custom rendering. The shader file cannot be dynamically modified after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type                            | Mandatory| Description                        |
| ------ | -------------------------------- | ---- | ---------------------------- |
| uri    | [Resource](ts-types.md#resource) | Yes  | Shader file for custom rendering.|

### shaderImageTexture

shaderImageTexture(uri: Resource)

Sets the texture resource used for custom rendering. To use multiple texture resources for custom rendering, call this API multiple times. The sequence in which the resources are used is the same as the call sequence. The texture resource cannot be dynamically modified after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type                            | Mandatory| Description                      |
| ------ | -------------------------------- | ---- | -------------------------- |
| uri    | [Resource](ts-types.md#resource) | Yes  | Texture resource used for custom rendering.|

### shaderInputBuffer

shaderInputBuffer(buffer: Array&lt;number&gt;)

Set the animation parameters used for custom rendering. 

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type          | Mandatory| Description                      |
| ------ | -------------- | ---- | -------------------------- |
| buffer | Array<number\> | Yes  | Animation parameters used for custom rendering.|

### renderWidth

renderWidth(value: Dimension)

Sets the width of the 3D rendering resolution. The width and height of the rendering resolution may be different from those of the component. If this is the case, they are upsampled or downsampled to the component width and height.

If this attribute is not specified, the default width of the rendering resolution is used.

The rendering resolution cannot be dynamically changed after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type                                | Mandatory| Description                |
| ------ | ------------------------------------ | ---- | -------------------- |
| value  | [Dimension](ts-types.md#dimension10) | Yes  | Width of the 3D rendering resolution.|

### renderHeight

renderHeight(value: Dimension)

Sets the height of the 3D rendering resolution. The width and height of the rendering resolution may be different from those of the component. If this is the case, they are upsampled or downsampled to the component width and height.

If this attribute is not specified, the default width of the rendering resolution is used.

The rendering resolution cannot be dynamically changed after the component is created.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name| Type                                | Mandatory| Description                |
| ------ | ------------------------------------ | ---- | -------------------- |
| value  | [Dimension](ts-types.md#dimension10) | Yes  | Height of the 3D rendering resolution.|

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example
You can preview how this component looks on a real device, but not in DevEco Studio Previewer.<br>
Example of loading a GLTF model:<br>
```ts
// xxx.ets
@Entry
@Component
struct Index {
  scene: SceneOptions = { scene: $rawfile('gltf/DamageHemlt/glTF/DamagedHelmet.gltf'), modelType: ModelType.SURFACE};
  build() {
    Row() {
      Column() {
        Text('GLTF Example')
        Component3D( this.scene )
          .environment($rawfile('gltf/Environment/glTF/Environment.gltf'))
          .renderWidth('90%').renderHeight('90%')
      }.width('100%')
    }
    .height('100%')
  }
}
```
Example of custom rendering:<br>

```ts
import { Animator as animator, AnimatorResult } from '@kit.ArkUI';

class EngineTime {
  totalTimeUs = 0;
  deltaTimeUs = 0;
};

let engineTime = new EngineTime();
let frameCount: number = 0;

function TickFrame() {
  if (frameCount == 10) {
    engineTime.totalTimeUs += 1.0;
    engineTime.deltaTimeUs += 1.0;
    frameCount = 0;
  } else {
    frameCount++;
  }
}

@Entry
@Component
struct Index {
  scene: SceneOptions = { scene: $rawfile('gltf/DamageHemlt/glTF/DamagedHelmet.gltf'), modelType: ModelType.SURFACE};
  backAnimator: AnimatorResult = animator.create({
    duration: 2000,
    easing: "ease",
    delay: 0,
    fill: "none",
    direction: "normal",
    iterations: -1,
    begin: 100,
    end: 200,
  });
  @State timeDelta: number[] = [1.0, 2.0];
  create() {
    this.backAnimator.onfinish = () => {
      console.log('backAnimator onfinish');
    }
    this.backAnimator.onframe = value => {
      TickFrame();
      this.timeDelta[0] = engineTime.deltaTimeUs;
    }

  }
  build() {
    Row() {
      Column() {
        Text('custom rendering')
        Component3D()
          .shader($rawfile('assets/app/shaders/shader/London.shader'))
          .shaderImageTexture($rawfile('assets/London.jpg'))
          .shaderInputBuffer(this.timeDelta)
          .customRender($rawfile('assets/app/rendernodegraphs/London.rng'), true)
          .renderWidth('90%').renderHeight('90%')
          .onAppear(() => {
            this.create();
            this.backAnimator.play();
          }).width('50%').height('50%')
      }.width('100%')
    }
    .height('100%')
  }
}
```
