# ArkGraphics 3D场景搭建以及管理
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

一个3D场景通常由光源、相机、模型三个关键部分组成。
- 光源：为整个3D场景提供光照，使得3D场景中的模型变得可见。与真实物理场景一致，没有光源场景将变得一片漆黑，得到的渲染结果也就是全黑色。
- 相机：为3D场景提供一个观察者。3D渲染本质上是从一个角度观察3D场景并投影到2D图片上。没有相机就没有3D场景的观察者，也就不会得到渲染结果。
- 模型：3D场景中的模型用于描述对象的形状、结构和外观，一般具有网格、材质、纹理、动画等属性。一些常见的3D模型格式有OBJ、FBX、glTF等。

模型加载后，可以通过ArkUI的[Component3D](../reference/apis-arkui/arkui-ts/ts-basic-components-component3d.md)渲染组件呈现给用户，Component3D也可以对3D模型做自定义渲染。开发者也可以使用ArkTS API对相机和光源进行调节，获得合适的观察角度和光照效果。ArkTS API可通过napi调用AGP中由C++实现的相应能力。

![3D场景显示流程](./figures/scene.PNG)

## 模型的加载及呈现
模型的格式多种多样，目前ArkGraphics 3D仅支持glTF模型的加载，glTF是一种对于3D场景描述的格式，glTF作为一种开源3D场景格式在业界被广泛采用。关于glTF的介绍可以参照[glTF-2.0](https://registry.khronos.org/glTF/specs/2.0/glTF-2.0.html)。

一个glTF模型可以包含光源、相机、模型等3D场景关键要素，如果一个glTF模型中包含相机，使用ArkGraphics 3D提供的接口加载glTF就可以直接完成该相机视角下3D场景的渲染。如果不包含相机，也可以利用ArkGraphics 3D创建一个相机完成渲染。由于3D模型往往数据量很大，通常采用异步方式进行加载，加载成功后将返回一个scene对象，通过该对象可对整个3D场景进行编辑。

glTF模型可用Scene提供的[load](../reference/apis-arkgraphics3d/js-apis-inner-scene.md#load)接口加载，示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function loadModel(): void {
  // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
  let scene: Promise<Scene> = Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"));
  scene.then(async (result: Scene) => {});
}
```

模型加载成功后，可通过SceneResourceFactory实例创建相机、光源等，再对相机和光源的参数做调节，调整观察角度和光照效果。最后，将Scene实例和ModelType作为SceneOptions传给Component3D组件显示到屏幕。

模型显示完整的示例代码如下，需确保gltf文件内容和路径准确。

```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

@Entry
@Component
struct Model {
  scene: Scene | null = null;
  @State sceneOpt: SceneOptions | null = null;
  cam: Camera | null = null;

  onPageShow(): void {
    this.Init();
  }

  Init(): void {
    if (this.scene == null) {
      // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
      Scene.load($rawfile("gltf/DamagedHelmet/glTF/DamagedHelmet.glb"))
      .then(async (result: Scene) => {
        this.scene = result;
        let rf:SceneResourceFactory = this.scene.getResourceFactory();
        // 创建相机
        this.cam = await rf.createCamera({ "name": "Camera" });
        // 设置合适的相机参数
        this.cam.enabled = true;
        this.cam.position.z = 5;
        this.sceneOpt = { scene: this.scene, modelType: ModelType.SURFACE } as SceneOptions;
      })
      .catch((reason: string) => {
        console.log(reason);
      });
    }
  }

  build() {
    Row() {
      Column() {
        if (this.sceneOpt) {
          // 通过Component3D呈现3D场景
          Component3D(this.sceneOpt)
        } else {
          Text("Loading···")
        }
      }.width('100%')
    }.height('60%')
  }
}
```

## 相机的创建及管理

相机作为3D场景中的重要部分，决定了整个3D场景向2D图片的投影过程，相机的近远平面、Fov角等关键参数也会对整个3D渲染产生重要的影响。开发者可以通过设置相机参数，控制这个渲染过程，得到开发者想要的渲染效果。

相机相关控制的示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createCameraPromise(): Promise<Camera> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneCameraParameter: SceneNodeParameters = { name: "camera" };
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
        resolve(cameraEntity);
      }).catch((error:Error) => {
        console.error('Camera create failed:', error);
        reject(error);
      });
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```


## 光源的创建及管理

3D场景的光源是对于物理世界中光源的一种数据建模，模拟物理世界的光源对于3D场景中的物体产生影响。

光源具有多种类型，例如平行光、锥形光。平行光用于模拟生活中的太阳光照，其光线平行且强度均匀。锥形光类似于手电筒，从一个点向扇形区域发射光线，光线强度随距离衰减。光源的颜色会影响场景中物体的最终着色，渲染时依据物理规律计算光源与物体表面颜色的交互，使光照效果更加真实。

ArkGraphics 3D提供创建光源及修改光源参数的功能，支持开发者通过设置光源属性调整3D场景，以实现预期的渲染效果。

光源相关控制的示例代码如下：
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createLightPromise(): Promise<Light> {
  return new Promise((resolve, reject) => {
    // 加载场景资源，支持.gltf和.glb格式，路径和文件名可根据项目实际资源自定义
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
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
        resolve(lightEntity);
      }).catch((error: Error) => {
        console.error('Light create failed:', error);
        reject(error);
      });
    }).catch((error: Error) => {
      console.error('Scene load failed:', error);
      reject(error);
    });
  });
}
```

<!--RP1-->
## 相关实例

对于模型、相机和光源更加综合的使用可以参考以下实例：
- [3D引擎接口示例（ArkTS）（API12）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d) 
<!--RP1End-->
