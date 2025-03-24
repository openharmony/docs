# ArkGraphics 3D场景动画控制以及管理
动画是3D场景中重要的资源类型，用于控制场景中各种元素的运动。比如想要场景中的人物进行走路这个动作，每帧计算人物每一个关节的旋转角并进行设置是难以实现的。所以在完成类似的要求时，3D场景资源的制作者会将动画制作好，在模型文件中保存动画的关键帧数据以及关键帧间的插值器类型。ArkGraphics 3D提供播放并控制场景动画的能力，支持开发者灵活地控制动画的状态，达到预期的渲染效果。

## 动画资源的创建
动画资源是模型资源制作者在制作模型的过程中制作并保存到模型文件中的。ArkGraphics 3D提供从glTF模型资源中提取并播放动画的能力，进而使得开发者可以进行动画状态的控制。
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createAnimation() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      // 获取动画资源
      let anim: Animation = result.animations[0];
    }
  });
}
```

## 动画状态的控制
ArkGraphics 3D提供的动画状态控制操作主要包含如下几种：
- 开始（start）：基于当前进度开始播放一个动画。
- 停止（stop）：停止播放一个动画，并将动画的进度设置到未开始状态。
- 结束（finish）：直接跳转到动画的最后，并将动画的进度设置到已结束状态。
- 暂定（pause）：将动画暂定，动画的播放进度保持在当前状态。
- 重启（restart）：从动画的起点开始播放动画。

示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function animationControl() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 动画状态控制
      anim.start();
      anim.pause();
      anim.stop();
      anim.restart();
      anim.finish();
    }
  });
}
```

## 动画回调的使用

动画回调指的是在动画执行到某些状态时执行的函数，用于帮助开发者以动画状态为基础做触发式的逻辑控制工作。ArkGraphics 3D提供给开发者如下回调：
- onStarted()：当动画开始播放时执行的回调函数，start操作以及restart操作也会触发这个回调。
- onFinished()：动画播放结束时执行的的回调函数，动画播放完成或者finish操作会触发这个回调。

示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function callBacks() : void {
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {
    if (result) {
      let anim: Animation = result.animations[0];
      // 注册回调函数
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
## 相关实例

对于3D动画更详细的使用可以参考以下实例：
- [3D引擎接口示例（ArkTS）（API12）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)
