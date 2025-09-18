# Creating and Using Image Resources
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

Image is essentially a two-dimensional buffer for storing information required for 3D rendering calculation, such as basic colors and normals.

ArkGraphics 3D provides the capability of creating image resources in PNG, JPG, and KTX formats and customizing image resources.


## Creating and Using an Image
An image resource in a 3D scene can be directly used by the GPU. Key parameters for creating an image resource include the name and path of the image resource. It is a common operation to apply an image resource to a material as one of the material attributes. The sample code is as follows:
```ts
import { Image, MaterialType, Material, ShaderMaterial, SceneResourceParameters, SceneResourceFactory,
  Scene } from '@kit.ArkGraphics3D';

function createImagePromise(): Promise<Image> {
  return new Promise((resolve, reject) => {
    // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
    let scene: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
    scene.then(async (result: Scene) => {
      let sceneFactory: SceneResourceFactory = result.getResourceFactory();
      // Load image resources, which can be used for material mapping. The URI can be specified based on the project structure.
      let sceneImageParameter: SceneResourceParameters = { name: "image", uri: $rawfile("bricks.jpg") };
      // Create an image.
      let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
      image.then(async (imageEntity: Image) => {
        let sceneMaterialParameter: SceneResourceParameters = { name: "material" };
        // Create a material.
        let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
        // ShaderMaterial inherits from Material.
        material.then(async (materialEntity: ShaderMaterial) => {
          // Use the created image resource to set the texture property.
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
