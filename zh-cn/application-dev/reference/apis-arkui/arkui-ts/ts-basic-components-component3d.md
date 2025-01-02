# Component3D
3D渲染组件，可以加载3D模型资源并做自定义渲染，通常用于3D动效场景。

>  **说明：**
>
>  该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无


## 接口 

Component3D(sceneOptions?: SceneOptions)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**

| 参数名       | 类型                                  | 必填 | 说明                                                         |
| ------------ | ------------------------------------- | ---- | ------------------------------------------------------------ |
| sceneOptions | [SceneOptions](#sceneoptions对象说明) | 否   | 3D场景配置选项。<br/>**说明：** <br/> 3D场景配置选项在控件创建后不支持动态修改。 |


## SceneOptions对象说明

Component3D组件配置选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称        | 类型                               | 必填   | 说明                                       |
| --------- | -------------------------------- | ---- | ---------------------------------------- |
| scene     | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[Scene](#scene12) | 否    | 3D模型资源文件或场景对象，默认值为undefined。<br/>**说明：** <br/>目前仅支持GLTF格式资源。 |
| modelType | [ModelType](#modeltype枚举说明) | 否    | 3D场景显示合成方式。<br/>默认值：ModelType.SURFACE<br/>**说明：** <br/>设置为ModelType.TEXTURE时通过GPU合成显示。<br/>设置为ModelType.SURFACE时通过专有硬件合成显示。<br/>一般开发者可以使用默认值而无需关心此项设置。 |

## ModelType枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称    | 值   | 说明                     |
| ------- | ---- | ------------------------ |
| TEXTURE | 0    | 使用GPU合成显示3D场景。  |
| SURFACE | 1    | 使用专有硬件显示3D场景。 |

## Scene<sup>12+</sup>

type Scene = Scene

设置3D场景。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [Scene](../../apis-arkgraphics3d/js-apis-inner-scene.md#scene-1) | 用于设置场景。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### environment

environment(uri: ResourceStr)

设置3D环境资源。目前仅支持GLTF格式资源，模型资源在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型                                   | 必填 | 说明         |
| ------ | -------------------------------------- | ---- | ------------ |
| uri    | [ResourceStr](ts-types.md#resourcestr) | 是   | 3D环境资源。 |

### customRender

customRender(uri: ResourceStr, selfRenderUpdate: boolean)

设置三维场景渲染的渲染管道。管线配置及自渲染属性在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名           | 类型                                   | 必填 | 说明                                                         |
| ---------------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| uri              | [ResourceStr](ts-types.md#resourcestr) | 是   | 自定义渲染管线的配置文件。                                   |
| selfRenderUpdate | boolean                                | 是   | 当设置为true时外部UI没有更新时也能触发动效渲染。<br/>当设置为false时只有外部UI更新才能触发渲染。 |

### shader

shader(uri: ResourceStr)

设置自定义渲染的shader文件资源。自定义渲染的shader文件资源在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型                                   | 必填 | 说明                         |
| ------ | -------------------------------------- | ---- | ---------------------------- |
| uri    | [ResourceStr](ts-types.md#resourcestr) | 是   | 自定义渲染的shader文件资源。 |

### shaderImageTexture

shaderImageTexture(uri: ResourceStr)

设置自定义渲染用到的纹理资源。若自定义渲染用到多个纹理资源则调用多次，绑定点与调用顺序一致，不支持纹理更换。纹理资源在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| uri    | [ResourceStr](ts-types.md#resourcestr) | 是   | 自定义渲染用到的纹理资源。 |

### shaderInputBuffer

shaderInputBuffer(buffer: Array&lt;number&gt;)

设置自定义渲染用到的动效参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型           | 必填 | 说明                       |
| ------ | -------------- | ---- | -------------------------- |
| buffer | Array<number\> | 是   | 自定义渲染用到的动效参数。 |

### renderWidth

renderWidth(value: Dimension)

设置3D渲染分辨率的宽度。渲染分辨率的长宽可以不同于控件的长宽，若渲染分辨率与控件分辨率长宽不一致时会上采样或下采样到控件长宽。

不调用此属性时默认渲染分辨率。

渲染分辨率在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型                                 | 必填 | 说明                 |
| ------ | ------------------------------------ | ---- | -------------------- |
| value  | [Dimension](ts-types.md#dimension10) | 是   | 3D渲染分辨率的宽度。 |

### renderHeight

renderHeight(value: Dimension)

设置3D渲染分辨率的长度。渲染分辨率的长宽可以不同于控件的长宽，若渲染分辨率与控件分辨率长宽不一致时会上采样或下采样到控件长宽。

不调用此属性时默认渲染分辨率。

渲染分辨率在控件创建后不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：** 

| 参数名 | 类型                                 | 必填 | 说明                 |
| ------ | ------------------------------------ | ---- | -------------------- |
| value  | [Dimension](ts-types.md#dimension10) | 是   | 3D渲染分辨率的长度。 |

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例
示例效果请以真机运行为准，当前DevEco Studio预览器不支持。<br/>
GLTF模型加载示例。 <br/>
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
自定义渲染示例。 <br/>

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