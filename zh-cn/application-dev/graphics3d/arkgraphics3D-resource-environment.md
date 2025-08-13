# 创建并使用环境资源
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

环境（Environment）：环境是3D场景背景的一种描述，可以基于图片进行创建。通过将一张图片进行正方体或者球体的映射处理，将图片贴在正方体或者球体上，在3D场景中模拟真实的环境。

ArkGraphics 3D支持用户创建环境资源，定义3D场景的背景。


## 环境资源的创建及使用
环境资源的创建需要指定名字以及图片或者glTF在文件沙箱中的路径，将环境资源设置到3D scene的environment属性，即可以将创建的环境资源设置为3D场景的背景环境。环境资源提供了diffuseFactor、specularFactor等的属性，支撑开发者对于环境资源属性进行控制。示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node, EnvironmentBackgroundType } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      // 加载图片资源，可用于环境贴图。路径uri可根据项目结构自由指定
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        // 创建Environment
        let sceneEnvironmentParameter: SceneResourceParameters = { name: "env" };
        let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
        env.then(async (envEntity: Environment) => {
          // 设置环境背景类型为等矩形贴图
          envEntity.backgroundType = EnvironmentBackgroundType.BACKGROUND_EQUIRECTANGULAR;
          // 绑定加载的图片作为环境贴图
          envEntity.environmentImage  = imageEntity;
          // 设置环境相关属性
          envEntity.indirectDiffuseFactor.x = 1;
          envEntity.indirectDiffuseFactor.y = 1;
          envEntity.indirectDiffuseFactor.z = 1;
          envEntity.indirectDiffuseFactor.w = 1;
          resolve(envEntity);
        });
      });
    });
  });
}
```


<!--RP1-->
## 相关实例

对于3D资源更加综合的使用可以参考以下实例：
- [3D引擎接口示例（ArkTS）（API12）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)
<!--RP1End-->