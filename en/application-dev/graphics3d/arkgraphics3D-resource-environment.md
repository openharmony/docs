# Creating and Using Environment Resources
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

Environment is a description of the 3D scene background, which can be created based on images. To simulate a real-world environment in a 3D scene, you can map a square or sphere onto an image and wrap the image around the square or sphere.

ArkGraphics 3D allows you to create environment resources and define the background of 3D scenes.


## Creating and Using an Environment
To create an environment resource, you need to specify the name and path of the image or glTF model in the application sandbox, and set the environment resource as an environment attribute of the 3D scene. In this way, the created environment resource is set as the background environment of the 3D scene. Environment resources also provide attributes such as **diffuseFactor** and **specularFactor**. The sample code is as follows:
```ts
import { Image, Environment, SceneResourceParameters, SceneResourceFactory, Scene,
  EnvironmentBackgroundType } from '@kit.ArkGraphics3D';

function createEnvironmentPromise(): Promise<Environment> {
  return new Promise((resolve, reject) => {
    // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      // Load image resources, which can be used for environment mapping. The URI can be specified based on the project structure.
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        // Create an environment.
        let sceneEnvironmentParameter: SceneResourceParameters = { name: "env" };
        let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
        env.then(async (envEntity: Environment) => {
          // Set the environment background type to equirectangular.
          envEntity.backgroundType = EnvironmentBackgroundType.BACKGROUND_EQUIRECTANGULAR;
          // Bind the loaded image as the environment map.
          envEntity.environmentImage  = imageEntity;
          // Set environment-related properties.
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
