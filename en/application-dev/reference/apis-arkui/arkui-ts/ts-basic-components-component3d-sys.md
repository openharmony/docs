# Component3D (System API)

The **\<Component3D>** component is used to load 3D model resources and create custom rendering. It is typically used to present 3D animations.

>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this module are system APIs.

## Child Components

Not supported


## APIs

Component3D((sceneOptions?: SceneOptions))


**Parameters**

| Name         | Type                             | Mandatory  | Description                                    |
| ------------ | --------------------------------- | ---- | ---------------------------------------- |
| sceneOptions | [SceneOptions](#sceneoptions) | No   | 3D scene configuration.<br>**NOTE**<br> The 3D scene configuration cannot be dynamically modified after the component is created.|


## SceneOptions

Provides the 3D scene configuration options.

| Name       | Type                              | Mandatory  | Description                                      |
| --------- | -------------------------------- | ---- | ---------------------------------------- |
| scene     | [Resource](ts-types.md#resource) | No   | 3D model resource file.<br>**NOTE**<br>Currently, only GLTF files are supported.|
| modelType | [ModelType](#modeltype)      | No   | Composition mode of the 3D scene.<br>Default value: **ModelType.SURFACE**<br>**NOTE**<br>**ModelType.TEXTURE**: The GPU is used for composition.<br>**ModelType.SURFACE**: Dedicated hardware is used for composition.<br>In general cases, leave this parameter at its default settings.|

## ModelType

| Name     | Description            |
| ------- | -------------- |
| TEXTURE | The GPU is used for composition of the 3D scene.|
| SURFACE | Dedicated hardware is used for composition of the 3D scene. |


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                | Type                                    | Description                                      |
| ------------------ | ---------------------------------------- | ---------------------------------------- |
| environment        | [Resource](ts-types.md#resource)         | 3D environment resource.<br>**NOTE**<br>Currently, only GLTF files are supported. Model resources cannot be dynamically modified after the component is created.|
| customRender       | uri: [Resource](ts-types.md#resource)<br> selfRenderUpdate: boolean | **uri**: configuration file for creating a custom rendering pipeline.<br> **selfRenderUpdate**: whether rendering can be triggered when the external UI is not updated. The value **true** means that rendering can be triggered when the external UI is not updated, and **false** means the opposite.<br>**NOTE**<br>**uri** and **selfRenderUpdate** cannot be dynamically modified after the component is created.|
| shader             | [Resource](ts-types.md#resource)         | Shader file for custom rendering.<br>**NOTE**<br>  The shader file cannot be dynamically modified after the component is created.|
| shaderImageTexture | [Resource](ts-types.md#resource)         | Texture resource used for custom rendering.<br>**NOTE**<br>To use multiple texture resources for custom rendering, call this API multiple times. The sequence in which the resources are used is the same as the calling sequence. The texture resource cannot be dynamically modified after the component is created.|
| shaderInputBuffer  | Array<number\>                           | Animation parameters used for custom rendering.                           |
| renderWidth        | [Dimension](ts-types.md#dimension10)     | Width of the 3D rendering resolution.<br>**NOTE**<br> The width and height of the rendering resolution may be different from those of the component. If this is the case, they are upsampled or downsampled to the component width and height.<br> If this attribute is not specified, the default width of the rendering resolution is used.<br> The rendering resolution cannot be dynamically changed after the component is created.|
| renderHeight       | [Dimension](ts-types.md#dimension10)     | Height of the 3D rendering resolution.<br>**NOTE**<br> The width and height of the rendering resolution may be different from those of the component. If this is the case, they are upsampled or downsampled to the component width and height.<br> If this attribute is not specified, the default width of the rendering resolution is used.<br> The rendering resolution cannot be dynamically changed after the component is created.|

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
import animator, { AnimatorResult } from '@ohos.animator';
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
          .shader($rawfile('assets/app/shaders'))
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
