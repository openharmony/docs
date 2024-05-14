# ArkGraphics 3D场景搭建以及管理

一个3D场景通常由光源、相机、模型三个关键部分组成。
- 光源：为整个3D场景提供光照，使得3D场景中的模型变得可见。与真实物理场景一致，没有光源场景将变得一片漆黑，得到的渲染结果也就是全黑色。
- 相机：为3D场景提供一个观察者。3D渲染本质上是从一个角度观察3D场景并投影到一张2D图片上。没有相机就没有3D场景的观察者，也就不会得到渲染结果。
- 模型：即真实存在于3D场景中的物体，也是3D渲染过程的渲染对象。ArkGraphics 3D支持的模型描述格式为glTF。

## glTF模型加载
glTF是一种对于3D场景描述的格式，就像图片有png格式一样，glTF作为一种开源3D场景格式在业界被广泛采用。关于glTF的介绍可以参照[glTF-2.0](https://registry.khronos.org/glTF/specs/2.0/glTF-2.0.html).

一个glTF模型可以包含光源、相机、模型等3D场景关键要素，如果一个glTF模型中包含相机，使用ArkGraphics 3D提供的接口加载glTF就可以直接完成该相机视角下3D场景的渲染。如果不包含相机，也可以利用ArkGraphics 3D创建一个相机完成渲染。

glTF模型的加载示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function loadModel() : void {
  // 加载模型
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
  scene.then(async (result: Scene) => {};
}
```
由于3D模型往往数据量很大，所以这里采用异步加载的方式，加载成功将返回一个scene对象，对于整个3D场景进行编辑。

## 相机的创建以及管理

相机作为3D场景中的重要部分，决定了整个3D场景向2D图片的投影过程，相机的近远平面、Fov角等关键参数也会对整个3D渲染产生重要的影响。开发者可以通过对于相机参数的设置。控制这个渲染过程，得到开发者想要的渲染效果。

相机相关控制的示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createCameraPromise() : Promise<Camera> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera1" };
      // 创建相机
      let camera: Promise<Camera> = sceneFactory.createCamera(sceneCameraParameter);
      camera.then(async (cameraEntity: Camera) => {
        // 使能相机节点
        cameraEntity.enabled = true;

        // 设置相机的位置
        cameraEntity.position.z = 5;

        // 设置相机Fov参数
        cameraEntity.fov = 60 * Math.PI / 180;

        // 可以参照此方式设置相机很多其他的参数
        // ...
      });
      return camera;
    });
  });
}
```


## 光源的创建以及管理

3D场景场景的光源是对于物理世界中光源的一种数据建模，模拟物理世界的光源对于3D场景中的物体产生影响。

光源具有很多的类型，比如平行光、锥形光。平行光即是用来模拟生活中的太阳光照，发出的光线处处平行且强度均匀。锥形光则像是我们使用的手电筒，以一个点向一个扇形区域发射光线，且发出的光线会随着距离而衰减。光源的颜色也会对场景中的物体最终的着色产生影响，光源颜色与物体颜色相互作用的计算与真实物理世界保持一致。ArkGraphics 3D提供了创建光源，修改光源各种参数的能力，支撑开发者通过对于光源属性的设置对于3D场景进行调整，得到期望的渲染效果。

光源相关控制的示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createLightPromise() : Promise<Light> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneLightParameter: SceneNodeParameters = { name: "light" };
      // 创建平行光
      let light: Promise<Light> = sceneFactory.createLight(sceneLightParameter, LightType.DIRECTIONAL);
      light.then(async (lightEntity: Light) => {
        // 设置平行光的颜色属性
        lightEntity.color = { r: 0.8, g: 0.1, b: 0.2, a: 1.0 };

        // 可以参照此方式设置光源很多其他的参数
        // ...
      });
      return light;
    });
  });
}
```



