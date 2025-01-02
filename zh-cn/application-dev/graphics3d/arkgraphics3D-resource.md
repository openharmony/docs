# ArkGraphics 3D资源创建以及使用
3D场景中资源类型主要包含以下几种：
- 材质（Material）： 材质是对场景中物体的光学物理性质的数学建模。在渲染计算的过程中，利用这些物理性质计算与光的相互作用，得到最终渲染的颜色。ArkGraphics 3D提供的材质类型基于PBR渲染，支持用户参照PBR渲染材质类型创建材质资源，得到预期的渲染结果。
- 图片（Image）： 图片本质上是上一个储存信息的二维内存块(buffer)，用于储存3D渲染计算过程需要的相关信息，比如基础色、法线等等。ArkGraphics 3D提供基于png、jpg、ktx格式创建Image资源的能力，支持用户自定义需要的Image资源。
- 着色器（Shader）： 着色器是GPU上可以执行的一段程序，可以控制GPU执行哪些并行计算操作。AGP引擎提供的默认着色器实现了PBR渲染，开发者只需要指定对应的参数就可以完成不同的PBR渲染。ArkGraphics 3D支持开发者创建自定义的着色器，开发者可以通过自定义着色器自定义渲染计算过程，完全控制渲染计算流程，比如控制某物体不受某光源的影响等。
- 环境（Environment）： 环境是3D场景背景的一种描述，可以基于图片进行创建。通过将一张图片进行正方体或者球体的映射处理，将图片贴在正方体或者球体上，在3D场景中模拟真实的环境。ArkGraphics 3D支持用户创建环境资源，定义3D场景的背景。
- 动画（Animation）： 3D中的动画资源用于创建三维场景可以运动的虚拟对象，例如人物、动物、车辆等。它们是构成3D场景的基本元素之一，为动画片、游戏、虚拟现实等领域提供了丰富的内容。

## 材质的创建及使用

材质的关键属性包括名字和类型，以此为输入可以创建材质。示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
      // 创建材质
      let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
      return material;
    });
  });
}
```
## 着色器资源的创建及使用
着色器主要用于控制GPU计算，给开发者提供自定义渲染的能力，提高了3D渲染控制的灵活性。着色器资源的创建需要着色器资源的名字以及着色器在文件沙箱中的路径。着色器资源主要的使用场景是替换材质的着色器属性，给材质自定义渲染算法，达到灵活控制渲染过程的目的，示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createShaderPromise() : Promise<Shader> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // 创建SceneResourceParameters类型变量并以此创建shader
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      shader.then(async (shaderEntity: Shader) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // 创建材质
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        material.then(async (materialEntity: ShaderMaterial) => {
          // 绑定材质与shader
          materialEntity.colorShader = shaderEntity;
        });
      });
      return shader;
    });
  });
}
```

## 图片资源的创建及使用
3D场景中的图片资源是指GPU可以直接使用的图片资源。创建图片资源的关键参数包括图片资源的名字以及图片资源的路径。将图片资源应用到材质中作为材质属性，是常见的图片资源使用方式之一，示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createImagePromise() : Promise<Image> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // 创建Image
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // 创建材质
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        material.then(async (materialEntity: ShaderMaterial) => {
          // 利用创建的图片资源设置纹理属性
          if (materialEntity && materialEntity.colorShader) {
            materialEntity.colorShader.inputs["BASE_COLOR_Image"] = imageEntity;
          }
        });
      });
      return image;
    });
  });
}
```
## 环境资源的创建及使用
环境资源的创建需要指定名字以及图片或者glTF在文件沙箱中的路径，将环境资源设置到3D scene的environment属性，即可以将创建的环境资源设置为3D场景的背景环境。环境资源提供了diffuseFactor、specularFactor等的属性，支撑开发者对于环境资源属性进行控制。示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("bricks.ktx") };
      // 创建Environment
      let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
      env.then(async (envEntity: Environment) => {
        // 设置env相关属性
        envEntity.indirectDiffuseFactor.x = 1;
        envEntity.indirectDiffuseFactor.y = 1;
        envEntity.indirectDiffuseFactor.z = 1;
        envEntity.indirectDiffuseFactor.w = 1;
      });
      return env;
    });
  });
}
```
## 相关实例

对于3D资源更加综合的使用可以参考以下实例：
- [3D引擎接口示例（ArkTS）（API12）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)

