# Creating and Using Image Resources

<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=160b5b2beee4bcc311002f3e8a787da3e22aeee3 translatedAt=2026-08-04T08:00:02.820Z pushedAt=2026-08-04T08:08:24.793Z -->

Image is essentially a two-dimensional buffer for storing information required for 3D rendering calculation, such as basic colors and normals.

ArkGraphics 3D provides the capability of creating image resources in PNG, JPG, and KTX formats and customizing image resources.

## How to Develop

1. Import the required modules.

   Import the core types provided by ArkGraphics 3D in the page script to create objects like scenes, cameras, materials, and images.

   <!-- @[resource_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   import { Camera, Environment, Geometry, Image, Material, MaterialType, Scene, SceneResourceFactory,
     SceneResourceParameters, Shader, ShaderMaterial, EnvironmentBackgroundType } from '@kit.ArkGraphics3D';
   ```

2. Load the scene and configure rendering parameters.

   Call **Scene.load()** to load model files in .glb or .gltf format, and obtain a scene object upon completion. Then, construct a SceneOptions object to specify the scene and rendering mode for rendering the scene content via Component3D.

   <!-- @[scene_load_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   if (this.scene === null) {
     // Switched from .gltf to .glb; same content, different format
     Scene.load($rawfile('gltf/CubeWithFloor/glTF/AnimatedCube.glb'))
       .then(async (result: Scene) => {
         // Assign loaded scene to globalScene for unified resource creation
         globalScene = result;
         this.scene = result;
         this.sceneOpt = { scene: this.scene, modelType: ModelType.SURFACE } as SceneOptions;
         this.rf = this.scene.getResourceFactory();
         // ...
       })
       .catch((error: string) => {
         console.error('init error: ' + error + '.');
       });
   }
   ```

3. Initialize the camera.

   Create a camera object, and set its enabled state and viewing position for subsequent model display.

   <!-- @[scene_camera_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   this.cam = await this.rf.createCamera({ 'name': 'Camera1' });
   this.cam.enabled = true;
   this.cam.position.z = 5;
   ```

4. Obtain the geometry node.

   Call **Scene.getNodeByPath()** to obtain the geometry node of the target model, and record its original material. This enables rollback or recovery in case the material is later modified.

   <!-- @[geometry_node_get](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   this.geom = this.scene.getNodeByPath('rootNode_/Unnamed Node 1/AnimatedCube') as Geometry;
   
   // record original material
   this.originalMat = this.geom.mesh.subMeshes[0].material;
   ```

5. Create an image resource.

   Use **SceneResourceFactory.createImage()** to create an image resource.

   <!-- @[create_image_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   function createImagePromise(): Promise<Image> {
     return new Promise((resolve, reject) => {
       // Ensure the scene is loaded before accessing sceneFactory
       if (globalScene) {
         let sceneFactory: SceneResourceFactory = globalScene.getResourceFactory();
   
         let sceneImageParameter: SceneResourceParameters = {
           name: 'image',
           uri: $rawfile('image/Cube_BaseColor.png')
         };
   
         let image: Promise<Image> = sceneFactory.createImage(sceneImageParameter);
         image.then((imageEntity: Image) => {
           resolve(imageEntity);
         }).catch((err: string) => {
           console.error('Image load failed: ' + err + '.');
           reject(err);
         });
       } else {
         reject('Scene is not loaded yet.');
       }
     });
   }
   ```

6. Apply the image material to the model node.

   In the button click callback, create a shader material using **createShader()** and **createMaterial()**, call **createImagePromise()** to obtain the image resource and bind it to the shader input property **BASE_COLOR_Image**, and then apply the material to the model geometry to make the surface texture take effect and replace the texture.

   <!-- @[replace_with_image_material](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   Button('Replace with a Image material')
     // ...
     .onClick(async (): Promise<void> => {
       console.info('Start to replace with a material of image');
   
       if (!this.scene || !this.cam || !this.rf) {
         return;
       }
   
       // create shader
       this.shader = await this.rf.createShader({
         name: 'shaderResource',
         uri: $rawfile('shaders/custom_shader/custom_material_sample.shader')
       });
   
       // create imageMat
       this.imageMat = await this.rf.createMaterial({ name: 'imageMat' }, MaterialType.SHADER) as ShaderMaterial;
   
       // bind between shader and imageMat
       this.imageMat.colorShader = this.shader;
       let createdImage =  await createImagePromise();
       if (createdImage) {
         this.imageMat.colorShader.inputs['BASE_COLOR_Image'] = createdImage;
       }
   
       this.geom = this.scene.getNodeByPath('rootNode_/Unnamed Node 1/AnimatedCube') as Geometry;
   
       this.geom.mesh.materialOverride = undefined;
       this.geom.mesh.subMeshes[0].material = this.imageMat;
     })
   ```

<!--RP1-->

## Samples

The following sample is provided to help you better understand how to efficiently use 3D resources:

- [3D Engine Interface Example (ArkTS) (API version 12)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)

<!--RP1End-->