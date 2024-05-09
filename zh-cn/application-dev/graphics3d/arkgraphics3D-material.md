# ArkGraphics 3D资源创建以及使用
3D场景中资源类型主要包含以下几种：
- 材质（Material）： 材质是对场景中物体的光学物理性质的数学建模。在渲染计算的过程中，利用这些物理性质计算与光的相互作用，得到最终渲染的颜色。ArkGraphics 3D提供的材质类型基于PBR渲染，支持用户参照PBR渲染材质类型创建材质资源，得到预期的渲染结果。
- 图片（Image）： 图片本质上是上一个储存信息的二维内存块(buffer)，用于储存3D渲染计算过程需要的相关信息，比如基础色、法线等等。ArkGraphics 3D提供基于png、jpg、ktx格式创建Image资源的能力，支持用户自定义需要的Image资源。
- 着色器（Shader）： 着色器是GPU上可以执行的一段程序，可以控制GPU执行哪些并行计算操作。AGP引擎提供的默认着色器实现了PBR渲染，开发者只需要指定对应的参数就可以完成不同的PBR渲染。ArkGraphics 3D支持开发者创建自定义的着色器，开发者可以通过自定义着色器自定义渲染计算过程，完全控制渲染计算流程，比如控制某物体不受某光源的影响等。
- 环境（Environment）： 环境是3D场景背景的一种描述，可以基于图片进行创建。通过将一张图片进行正方体或者球体的映射处理，将图片贴在正方体或者球体上，在3D场景中模拟真实的环境。ArkGraphics 3D支持用户创建环境资源，定义3D场景的背景。

## 材质的创建以及使用

材质的关键属性包括名字和类型，以此为输入可以创建材质。示例代码如下：
```ts
import scene3d from '@ohos.graphics.scene'

async function createMaterialPromise() : Promise<scene3d.Material> {
  return new Promise(() => {
    let scene: Promise<scene3d.Scene> = scene3d.Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: scene3d.Scene) => {
      let sceneFactory: scene3d.SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: scene3d.SceneResourceParameters = { name: "material" };
      // 创建材质
      let material: Promise<scene3d.Material> = sceneFactory.createMaterial(sceneMaterialParameter, scene3d.MaterialType.SHADER);
      return material;
    });
  });
}
```
## 着色器资源的创建以及使用
着色器主要用于控制GPU计算，给开发者提供自定义渲染的能力，提高了3D渲染控制的灵活性。着色器资源的创建需要着色器资源的名字以及着色器在文件沙箱中的路径。着色器资源主要的使用场景是替换材质的着色器属性，给材质自定义渲染算法，达到灵活控制渲染过程的目的，示例代码如下：
```ts
import scene3d from '@ohos.graphics.scene'

async function createShaderPromise() : Promise<scene3d.Shader> {
  return new Promise(() => {
    let scene: Promise<scene3d.Scene> = scene3d.Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: scene3d.Scene) => {
      let sceneFactory: scene3d.SceneResourceFactory = result.getResourceFactory();

      // 创建SceneResourceParameters类型变量并以此创建shader
      let sceneResourceParameter: scene3d.SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<scene3d.Shader> = sceneFactory.createShader(sceneResourceParameter);
      shader.then(async (shaderEntity: scene3d.Shader) => {
        let sceneMaterialParameter: scene3d.SceneResourceParameters = { name: "material" };
        // 创建材质
        let material: Promise<scene3d.Material> = sceneFactory.createMaterial(sceneMaterialParameter, scene3d.MaterialType.SHADER);
        material.then(async (materialEntity: scene3d.ShaderMaterial) => {
          // 绑定材质与shader
          materialEntity.colorShader = shaderEntity;
        });
      });
      return shader;
    });
  });
}
```

## 图片资源的创建以及使用
3D场景中的图片资源是指GPU可以直接使用的GpuImage资源。创建图片资源的关键参数包括图片资源的名字以及图片资源的路径。将图片资源应用到材质中作为材质属性，是常见的图片资源使用方式之一，示例代码如下：
```ts
import scene3d from '@ohos.graphics.scene'

async function createImagePromise() : Promise<scene3d.Image> {
  return new Promise(() => {
    let scene: Promise<scene3d.Scene> = scene3d.Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: scene3d.Scene) => {
      let sceneFactory: scene3d.SceneResourceFactory = result.getResourceFactory();
      let sceneImageParameter: scene3d.SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // 创建Image
      let image: Promise<scene3d.Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: scene3d.Image) => {
        let sceneMaterialParameter: scene3d.SceneResourceParameters = { name: "material" };
        // 创建材质
        let material: Promise<scene3d.Material> = sceneFactory.createMaterial(sceneMaterialParameter, scene3d.MaterialType.SHADER);
        material.then(async (materialEntity: scene3d.ShaderMaterial) => {
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
import scene3d from '@ohos.graphics.scene'

async function createEnvironmentPromise() : Promise<scene3d.Environment> {
  return new Promise(() => {
    let scene: Promise<scene3d.Scene> = scene3d.Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: scene3d.Scene) => {
      let sceneFactory: scene3d.SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: scene3d.SceneResourceParameters = { name: "env", uri: $rawfile("bricks.ktx") };
      // 创建Environment
      let env: Promise<scene3d.Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
      env.then(async (envEntity: scene3d.Environment) => {
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



