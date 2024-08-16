# Creating and Using ArkGraphics 3D Resources
The following types of resources are used in a 3D scene:
- Material: mathematical modeling of optical properties of an object in a scene. During rendering calculation, these physical properties are used to calculate the interaction with light to obtain the final color rendered. ArkGraphics 3D provides physically based rendering (PBR) materials. You can create material resources based on these PBR materials so as to obtain the desired rendering result.
- Image: essentially a two-dimensional buffer for storing information required for 3D rendering calculation, such as basic colors and normals. ArkGraphics 3D provides the capability of creating image resources in PNG, JPG, and KTX formats and customizing image resources.
- Shader: a program executed on a GPU to tell the GPU which parallel computing operations can be performed. The default shader provided by the Ark Graphics Platform (AGP) engine implements PBR. You only need to specify parameters to get different PBR effects. ArkGraphics 3D allows you to create custom shaders and customize the rendering calculation process, for example, to prevent an object from being affected by light.
- Environment: a description of the 3D scene background, which can be created based on images. To simulate a real-world environment in a 3D scene, you can map a square or sphere onto an image and wrap the image around the square or sphere. ArkGraphics 3D allows you to create environment resources and define the background of 3D scenes.
- Animation: used to create virtual objects that can move in a 3D scene, for example, people, animals, and vehicles. They are one of the essential elements that make up a 3D scene, and provide rich content for cartoons, games, virtual reality, and similar scenes.

## Creating and Using Materials

Key attributes of a material include the name and type, which can be used as inputs to create a material. The sample code is as follows:
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createMaterialPromise() : Promise<Material> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
      // Create a material.
      let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
      return material;
    });
  });
}
```
## Creating and Using a Shader
Shaders are mainly used to control GPU computing. You can customize rendering capabilities for more flexibility in 3D rendering control. To create a shader resource, you must specify its name and path in the application sandbox. A shader resource is mainly used to replace the shader attribute of a material so as to customize the rendering algorithm for the material. The sample code is as follows:
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createShaderPromise() : Promise<Shader> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();

      // Create a variable of the SceneResourceParameters type and use it to create a shader.
      let sceneResourceParameter: SceneResourceParameters = { name: "shaderResource",
        uri: $rawfile("shaders/custom_shader/custom_material_sample.shader") };
      let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
      shader.then(async (shaderEntity: Shader) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // Create a material.
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        material.then(async (materialEntity: ShaderMaterial) => {
          // Bind the material to the shader.
          materialEntity.colorShader = shaderEntity;
        });
      });
      return shader;
    });
  });
}
```

## Creating and Using an Image
An image resource in a 3D scene can be directly used by the GPU. Key parameters for creating an image resource include the name and path of the image resource. It is a common operation to apply an image resource to a material as one of the material attributes. The sample code is as follows:
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createImagePromise() : Promise<Image> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // Create an image.
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // Create a material.
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        material.then(async (materialEntity: ShaderMaterial) => {
          // Use the created image resource to set the texture attribute.
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
## Creating and Using an Environment
To create an environment resource, you need to specify the name and path of the image or glTF model in the application sandbox, and set the environment resource as an environment attribute of the 3D scene. In this way, the created environment resource is set as the background environment of the 3D scene. Environment resources also provide attributes such as **diffuseFactor** and **specularFactor**. The sample code is as follows:
```ts
import { Image, Shader, MaterialType, Material, ShaderMaterial, Animation, Environment, Container, SceneNodeParameters,
  LightType, Light, Camera, SceneResourceParameters, SceneResourceFactory, Scene, Node } from '@kit.ArkGraphics3D';

function createEnvironmentPromise() : Promise<Environment> {
  return new Promise(() => {
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.gltf"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      let sceneEnvironmentParameter: SceneResourceParameters = { name: "env", uri: $rawfile("bricks.ktx") };
      // Create an environment.
      let env: Promise<Environment> = sceneFactory.createEnvironment(sceneEnvironmentParameter);
      env.then(async (envEntity: Environment) => {
        // Set environment-related attributes.
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
