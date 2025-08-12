# 创建并使用图片资源
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--SE: @zdustc-->
<!--TSE: @zhangyue283-->

图片（Image）：图片本质上是一个储存信息的二维内存块(buffer)，用于储存3D渲染计算过程需要的相关信息，比如基础色、法线等等。

ArkGraphics 3D提供基于png、jpg、ktx格式创建Image资源的能力，支持用户自定义需要的Image资源。


## 图片资源的创建及使用
3D场景中的图片资源是指GPU可以直接使用的图片资源。创建图片资源的关键参数包括图片资源的名字以及图片资源的路径。将图片资源应用到材质中作为材质属性，是常见的图片资源使用方式之一，示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createImagePromise() : Promise<Image> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      // 加载图片资源，可用于材质贴图等。路径uri可根据项目结构自由指定
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // 创建Image
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // 创建材质
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        // ShaderMaterial继承自Material
        material.then(async (materialEntity: ShaderMaterial) => {
          // 利用创建的图片资源设置纹理属性
          if (materialEntity && materialEntity.colorShader) {
            materialEntity.colorShader.inputs["BASE_COLOR_Image"] = imageEntity;
          }
          resolve(imageEntity);
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