# SceneResource
本模块提供3D图形中常用的基本资源类型。

> **说明：** 
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标标记接口的起始版本。

## 导入模块
```ts
import { SceneResourceType, SceneResource, Shader, MaterialType, Material, ShaderMaterial,
  SubMesh, Mesh, MeshResource, Animation, EnvironmentBackgroundType, Environment, Image } from '@kit.ArkGraphics3D';
```
## SceneResourceType
场景资源类型枚举，对场景中的资源进行分类。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| UNKNOWN | 0 | 未定义类型。 |
| NODE | 1 | 结点类型。 |
| ENVIRONMENT | 2 | 环境类型。 |
| MATERIAL | 3 | 材质类型。 |
| MESH | 4 | 网格类型。 |
| ANIMATION | 5 | 动画类型。 |
| SHADER | 6 | 着色器类型。 |
| IMAGE | 7 | 图片类型。 |
| MESH_RESOURCE<sup>18+</sup> | 8 | 网格资源类型。 |

## SceneResource
用于表示场景中的资源。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 名称，没有特殊格式要求。 |
| resourceType | [SceneResourceType](#sceneresourcetype) | 是 | 否 | 场景资源类型，默认值为undefined。|
| uri | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr) | 是 | 是 | 需要加载的资源，默认值为undefined。|

### destroy
destroy(): void

销毁场景资源，释放所有关联的资源或引用，一旦被释放，资源就不能被再次使用或访问。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
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
         // 释放资源
         shaderResult.destroy();
      });
    }
  });
}
```

## Shader
着色器，继承自[SceneResource](#sceneresource)。

### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| inputs | Record<string, number \| Vec2 \| Vec3 \| Vec4 \| Image> | 是 | 否 | 着色器输入。 |

## MaterialType
场景中物体材质类型枚举。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| SHADER | 1 | 材质由着色器定义。 |

## Material
材质类型，继承自[SceneResource](#sceneresource)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| materialType | [MaterialType](#materialtype) | 是 | 否 | 材质类型。 |

## ShaderMaterial
着色器材质，继承自[Material](#material)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| colorShader | [Shader](#shader) | 否 | 是 | 着色器，默认值为undefined。 |

## SubMesh
子网格类型。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| name | string | 否 | 否 | 名称，没有特殊格式要求。 |
| material | [Material](#material) | 否 | 否 | 材质。 |
| aabb | [Aabb](js-apis-inner-scene-types.md#aabb) | 是 | 否 | 轴对齐边界盒。 |

## Mesh
网格类型，继承自[SceneResource](#sceneresource)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| subMeshes | [SubMesh](#submesh)[] | 是 | 否 | 子网格数组。 |
| aabb | [Aabb](js-apis-inner-scene-types.md#aabb) | 是 | 否 | 轴对齐包围盒。|
| materialOverride | [Material](#material) | 否 | 是 | 材质，默认为空。 |

## MeshResource<sup>18+</sup>
网格资源，继承自[SceneResource](#sceneresource)。

**系统能力：** SystemCapability.ArkUi.Graphics3D

## Animation
动画类型，继承自[SceneResource](#sceneresource)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| enabled | boolean | 否 | 否 | 动画是否使能。true表示可以播放动画，false表示不可以播放动画。 |
| duration | number | 是 | 否 | 动画持续时间，取值范围大于等于0。 |
| running | boolean | 是 | 否 | 动画运行状态。true表示动画正在播放，false表示动画停止播放。 |
| progress | number | 是 | 否 | 动画进度状态，取值区间为[0, 1]。 |

### onFinished
onFinished(callback: Callback\<void>): void

动画播放结束时执行的的回调函数，动画播放完成或者finish操作会触发这个回调。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| callback | Callback\<void> | 是 | 回调函数，返回值为空。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function onFinished() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 注册回调函数
      anim.onFinished(()=>{
        console.info("onFinished");  
      });
    }
  });
}
```

### onStarted
onStarted(callback: Callback\<void>): void

当动画开始播放时执行的回调函数，start操作以及restart操作也会触发这个回调。

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| callback | Callback\<void> | 是 | 回调函数，返回值为空。 |

动画开始时会执行传入的回调函数。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function onStarted() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 注册回调函数
      anim.onStarted(()=>{
        console.info("onStarted");  
      });
    }
  });
}
```

### pause
pause(): void

将动画暂停，动画的播放进度保持在当前状态。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function pause() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 暂停动画
      anim.pause();
    }
  });
}
```

### restart
restart(): void

从动画的起点开始播放动画。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function restart() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 重启动画
      anim.restart();
    }
  });
}
```

### seek
seek(position: number): void

从指定位置开始播放动画。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 要重新播放动画的起始位置，取值区间为[0, 1]。 |

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function seek() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 指定动画的播放进度到10%
      anim.seek(0.1);
    }
  });
}
```

### start
start(): void

基于当前进度开始播放一个动画。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function start() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 开始动画
      anim.start();
    }
  });
}
```

### stop
stop(): void

停止播放一个动画，并将动画的进度设置到未开始状态。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function stop() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 停止播放动画，并将动画的进度设置到未开始状态
      anim.stop();
    }
  });
}
```

### finish
finish(): void

直接跳转到动画的最后，并将动画的进度设置到已结束状态。

**系统能力：** SystemCapability.ArkUi.Graphics3D

```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function finish() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 直接跳转到动画的最后，并将动画的进度设置到已结束状态。
      anim.finish();
    }
  });
}
```

## EnvironmentBackgroundType
环境背景类型枚举。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| BACKGROUND_NONE | 0 | 无背景。|
| BACKGROUND_IMAGE | 1 | 图片背景。 |
| BACKGROUND_CUBEMAP | 2 | 立方体贴图背景。|
| BACKGROUND_EQUIRECTANGULAR | 3 | 等距矩形背景。 |

## Environment
环境类型，继承自[SceneResource](#sceneresource)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| backgroundType | [EnvironmentBackgroundType](#environmentbackgroundtype) | 否 | 否 | 环境背景类型。 |
| indirectDiffuseFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | 否 | 否 | 间接散射系数。 |
| indirectSpecularFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | 否 | 否 | 间接反射系数。 |
| environmentMapFactor | [Vec4](js-apis-inner-scene-types.md#vec4) | 否 | 否 | 环境地图系数。 |
| environmentImage | [Image](#image) \| null | 否 | 是 | 环境图片，默认为undefined。 |
| radianceImage | [Image](#image) \| null | 否 | 是 | 辐射图片，默认为undefined。 |
| irradianceCoefficients | [Vec3](js-apis-inner-scene-types.md#vec3)[] | 否 | 是 | 辐射系数，默认为undefined。 |

## Image
图片类型，继承自[SceneResource](#sceneresource)。
### 属性

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| width | number | 是 | 否 | 图片宽度，取值范围大于0。 |
| height | number | 是 | 否 | 图片高度，取值范围大于0。 |
