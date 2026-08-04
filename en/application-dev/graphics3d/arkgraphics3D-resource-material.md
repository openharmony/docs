# Creating and Using Material Resources

<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=347413418efa7bc77920c06f5cdec8cea53cbed3 translatedAt=2026-08-04T08:00:06.220Z pushedAt=2026-08-04T08:13:33.862Z -->

Materials are essential resources that define the visual appearance of an object's surface. They determine how an object interacts with light, thereby affecting its final rendering result, such as color, metallic appearance, and roughness.

ArkGraphics 3D uses the Physically Based Rendering (PBR) model. Its material implementation follows the general principles of PBR. You can either use standard materials to quickly achieve realistic effects or customize shader materials to flexibly control the rendering logic.

## Basic Concepts

Shader: a program executed on a GPU to tell the GPU which parallel computing operations can be performed. The default shader provided by the Ark Graphics Platform (AGP) engine implements PBR. You only need to specify parameters to get different PBR effects.

ArkGraphics 3D allows you to create custom shaders. By customizing shaders, you can control the rendering computation process and fully control the rendering workflow. For example, you can control whether an object is affected by a particular light source, customize edge outlining, or create highlight effects for personalized visual presentations.

Shaders are typically used with **MaterialType.SHADER** materials and are an important means of achieving customized rendering. They require a name and sandbox path for creation. Once created, they can be bound to materials to replace the default rendering behavior.

## Material Types

Material types in ArkGraphics 3D are specified using the enum [MaterialType](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#materialtype). Currently, the following two types are supported:

- **MaterialType.SHADER**: This material type is based on shaders and supports binding custom shaders. You can use custom rendering programs to achieve personalized visual effects. It is suitable for advanced graphics rendering needs.

- **MaterialType.METALLIC_ROUGHNESS**: This is a standard PBR material type based on the metallic-roughness model. It conforms to the glTF material specification and is suitable for quickly building realistic rendering effects. It supports setting common properties such as base color, metallic appearance, roughness, and normal mapping.

Materials are created by calling [SceneResourceFactory.createMaterial()](../reference/apis-arkgraphics3d/js-apis-inner-scene.md#creatematerial), which requires specifying the material name and type. Different material types support different parameter configurations. You can choose as needed to achieve the desired rendering effect.

## Material Properties

Material properties define their visual behavior during rendering, such as color, metallic appearance, roughness, light response, and transparency control. By setting these properties, you can precisely control the appearance of objects in the scene.

In ArkGraphics 3D, material properties are designed to provide both unified basic capabilities and differentiated extensions based on material type, meeting diverse needs from basic scene building to advanced visual customization.

### Universal Properties

All materials have the following basic properties (such as **materialType**, **shadowReceiver**, and **blend**), which can be set through the [Material](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#material) type object to control the type of material and its basic rendering behavior:

- **materialType**: material type, indicating whether it is a standard PBR material or a custom shader material.

  Use case: Choose PBR material for quick use of preset realistic materials. Choose shader material for personalized or special rendering effects.

- **shadowReceiver**: whether the material can receive shadows cast in the scene. **true** if it can receive shadows, false otherwise. The default value is **false**.

  Use case: Enable for objects that need to display shadow effects, such as the ground, walls, and characters. Disable for purely emissive objects or those not participating in shadow calculations to optimize performance.

- **cullMode**: culling mode, which determines whether to cull back-facing geometry. The default value is **BACK**, meaning back-facing surfaces are culled.

  Use case: Enable for ordinary solid models to improve rendering efficiency. Disable for transparent or double-sided materials (such as leaves and fabrics) to display the complete model.

- **blend**: transparency effect setting of the material. The default value is undefined, which disables the transparency property of the material.

  Use case: Enable for materials that need to display transparency or translucency, such as glass, water surfaces, smoke, and transparent plastics.

- **alphaCutoff**: alpha cutoff value, ranging from [0,1]. The default is **1**. Pixels with an alpha value below this threshold will not be rendered, used to achieve hard transparency clipping.

  Use case: For materials with hard transparency clipping, such as leaves, wire meshes, and fabric edges that have transparent areas without translucent gradients. By setting the threshold, transparent parts can be quickly clipped.

- **renderSort**: rendering sort setting, used to control the rendering order of materials in the rendering queue to ensure correct overlay display of transparent or special effect materials.

  Use case: For scenes with multiple transparent materials, overlay effects, and UI elements, where strict rendering order is required.

- **polygonMode**: polygon rendering mode of the model. The default value is **FILL**.

  Use case: Renders the mesh of a 3D object in wireframe mode, allowing intuitive display of the model's modeling structure.

### PBR Material Properties

The metallic-roughness material based on PBR rendering, which conforms to the glTF standard, is implemented by setting [MetallicRoughnessMaterial](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#metallicroughnessmaterial20). Each property is encapsulated using the [MaterialProperty](../reference/apis-arkgraphics3d/js-apis-inner-scene-resources.md#materialproperty20) type, supporting binding textures and setting factor values. Specific properties include:

- **baseColor**: base color and transparency, including texture and corresponding factor, used to define the main color of the material surface.

  Use case: basic color settings for all materials, suitable for any object surface, especially for models that need to display color and transparency.

- **normal**: normal map, used to simulate surface detail bumps and enhance the realism of lighting effects.

  Use case: suitable for models that need to display surface details such as stone textures, skin pores, and wood grain bumps to enhance realism.

- **material**: Metallic, roughness, and reflectivity parameters, describing the optical properties of the material surface.

  Use case: distinguishing between metallic and non-metallic surfaces, controlling the smoothness or roughness of the material, commonly used for metal parts, plastics, rubbers, and various other materials.

- **ambientOcclusion**: ambient occlusion map, enhancing the shadow levels and realism of material details.

  Use case: enhancing the shadow effects of model details, suitable for complex structures or objects with rich details, such as building cracks and mechanical part gaps.

- **emissive**: emissive color and texture, expressing the self-luminous effect of the material.

  Use case: suitable for materials that need to display light sources or self-luminous effects, such as lights, screens, glowing signs, and fluorescent materials.

- **clearCoat**: clear coat strength, simulating materials with a transparent reflective layer, such as car paint.

  Use case: suitable for materials with a glossy coating, such as car bodies and furniture surfaces, to display transparent gloss and reflection.

- **clearCoatRoughness**: roughness of the clear coat, controlling the reflective details of the clear coat.

  Use case: used with **clearCoat** to adjust the smoothness or roughness of the coating surface.

- **clearCoatNormal**: clear coat normal map, enhancing the lighting changes of the clear coat.

  Use case: used when the clear coat has detailed textures to increase the realistic lighting feedback of the coating.

- **sheen**: sheen diffuse layer, used to display the luster of fabrics and textiles.

  Use case: suitable for textiles such as clothing, curtains, and sofas, to display a soft luster and delicate texture.

- **specular**: specular reflection properties, controlling the highlight reflection intensity of non-metallic materials.

  Use case: suitable for non-metallic materials such as glass, water surfaces, and plastics to enhance the specular reflection effect.

## Creating Shader Materials and Setting Properties

You can create shader materials using the **MaterialType.SHADER** type when you need to customize rendering logic or implement unique visual effects. Shader materials support binding of custom .shader files, where you can write custom rendering logic to flexibly control the appearance of models, achieving personalized visual effects such as outlines, highlights, and emissive effects. This example demonstrates the process of creating and using shader materials, including loading scenes, creating and binding shader resources, and applying shader materials to target geometry nodes.

1. Import the required modules.

   Import the core types provided by ArkGraphics 3D in the page script to create shader materials and bind shader resources.

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

5. Create a blank shader material.

   Call **SceneResourceFactory.createMaterial()** to create a blank shader material in preparation for binding a custom shader.

   <!-- @[create_material_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   function createMaterialPromise(): Promise<Material> {
     return new Promise((resolve, reject) => {
       // Ensure the scene is loaded before accessing sceneFactory
       if (globalScene) {
         let sceneFactory: SceneResourceFactory = globalScene.getResourceFactory();
         let sceneMaterialParameter: SceneResourceParameters = { name: 'material' };
         // Create Material
         let material: Promise<Material> = sceneFactory.createMaterial(sceneMaterialParameter, MaterialType.SHADER);
         material.then(resolve)
         .catch((err: string) => {
           console.error('Blank material create failed: ' + err);
           reject(err);
         });
       } else {
         reject('Scene is not loaded yet.');
       }
     });
   }
   ```

6. Create a shader resource.

   Create a custom shader resource through **SceneResourceFactory.createShader()**. The created shader resource can be bound to the shader material in subsequent steps to implement custom rendering logic.

   <!-- @[create_shader_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   function createShaderPromise(): Promise<Shader> {
     return new Promise((resolve, reject) => {
       // Ensure the scene is loaded before accessing sceneFactory
       if (globalScene) {
         let sceneFactory: SceneResourceFactory = globalScene.getResourceFactory();
   
         // Create a SceneResourceParameters object and use it to create a shader
         let sceneResourceParameter: SceneResourceParameters = {
           name: 'shaderResource',
           uri: $rawfile('shaders/custom_shader/custom_material_sample.shader')
         };
   
         let shader: Promise<Shader> = sceneFactory.createShader(sceneResourceParameter);
         shader.then((shaderEntity: Shader) => {
           resolve(shaderEntity);
         }).catch((err: string) => {
           console.error('Shader load failed: ' + err + '.');
           reject(err);
         });
       } else {
         reject('Scene is not loaded yet.');
       }
     });
   }
   ```

7. Bind the shader material to a geometry node.

   Bind the shader resource to the shader material, and then bind the shader material to a geometry node to render with custom rendering logic. Material switching can be triggered through a button click event, achieving a dynamic transition from the default material to the shader material at runtime.

   <!-- @[material_button_action](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/arkgraphic/resource.ets) -->

   ``` TypeScript
   Button('Replace with a blank material')
     // ...
     .onClick(async (): Promise<void> => {
       console.info('Start to replace with a blank material');
   
       if (!this.blankMat) {
         this.blankMat = await createMaterialPromise();
       }
   
       if (!this.scene || !this.rf) {
         return;
       }
   
       this.geom = this.scene.getNodeByPath('rootNode_/Unnamed Node 1/AnimatedCube') as Geometry;
   
       this.geom.mesh.materialOverride = undefined;
       if (this.blankMat) {
         this.geom.mesh.subMeshes[0].material = this.blankMat;
       }
   
     });
   
   Button('Replace with a Shader material')
     // ...
     .onClick(async (): Promise<void> => {
       console.info('Start to replace with a shader material');
   
       if (!this.shader) {
         this.shader = await createShaderPromise();
       }
   
       if (!this.scene || !this.rf) {
         return;
       }
   
       if (!this.shaderMat) {
         let rf = this.scene.getResourceFactory();
         this.shaderMat = await rf.createMaterial({ name: 'shaderMat' }, MaterialType.SHADER);
       }
   
       if (this.shader) {
         this.shaderMat.colorShader = this.shader;
       }
   
       this.geom = this.scene.getNodeByPath('rootNode_/Unnamed Node 1/AnimatedCube') as Geometry;
   
       this.geom.mesh.materialOverride = undefined;
   
       if (this.shaderMat) {
         this.geom.mesh.subMeshes[0].material = this.shaderMat;
       }
     })
   ```

## Creating PBR Materials and Setting Properties

In ArkGraphics 3D, Physically Based Rendering (PBR) materials allow you to precisely control the appearance of objects by adjusting parameters such as metallicity, roughness, and transparency, achieving highly realistic rendering effects. Since different models may have varying PBR properties when exported, you are advised to adapt the material settings based on the model content. This example uses the CompareClearcoat model, which comes with clear coat-related material parameters, making it suitable for demonstrating the adjustment of clear coat effects. By setting properties like **clearCoat** and **clearCoatRoughness**, you can observe the changes in the strength, gloss, and reflection characteristics of the clear coat layer.

1. Import the required modules.

   Import the core types provided by ArkGraphics 3D in the page script to create PBR materials and bind texture resources.

   <!-- @[pbr_clearcoat_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   import { Scene, Camera, Material, Node, Image, SceneResourceFactory, Geometry, EnvironmentBackgroundType,
     PostProcessSettings, ToneMappingType, MetallicRoughnessMaterial, Vec4 } from '@kit.ArkGraphics3D';
   import {lookAt, OrbitCameraHelper } from '../common/utils';
   ```

2. Load scene resources.

   Call **Scene.load()** to load model files in .glb or .gltf format, and obtain a scene object upon completion. Once the scene is loaded, you can access the resource factory of the scene to create materials and other resources.

   <!-- @[pbr_clearcoat_loadScene](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   if (this.scene == null) {
     // Switched from .gltf to .glb; same content, different format
     Scene.load($rawfile('gltf/CompareClearcoat/CompareClearcoat.glb'))
       .then(async (scene: Scene) => {
         this.scene = scene;
         if (!this.scene.root) {
           return;
         }
         let rf: SceneResourceFactory = scene.getResourceFactory();
   
         // ...
       });
   }
   ```

3. Obtain a geometry node and preload textures.

   Obtain the target geometry node through the node path in the scene, extract its material, and preload the texture resources related to the clear coat layer.

   <!-- @[pbr_clearcoat_getMaterialAndTextures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   let pbrNode: Node | null | undefined = this.scene.root?.getNodeByPath('Unnamed Node 1/GeoSphere003');
   if (pbrNode) {
     this.material = (pbrNode as Geometry).mesh.subMeshes[0].material;
     let mrMaterial = (this.material as MetallicRoughnessMaterial);
     let original: Image | null = mrMaterial.clearCoat.image;
     const helmAlbedo: Resource = $rawfile('image/round_pattern.png');
     const irregularUri: Resource = $rawfile('image/irregular_pattern.png');
     let round: Image | null = await rf.createImage({name: 'round', uri: helmAlbedo });
     let irregular: Image | null = await rf.createImage({name: 'irregular', uri: irregularUri });
     if (original && round && irregular ) {
       this.textures.push(original);
       this.textures.push(round);
       this.textures.push(irregular);
     }
   }
   ```

4. Configure environment lighting.

   Create an Image-based Lighting (IBL) environment, and configure the environment and radiance maps to implement realistic environment lighting.

   <!-- @[pbr_clearcoat_createIBL](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   scene.environment = await rf.createEnvironment({ name: 'env' });
   scene.environment.backgroundType = EnvironmentBackgroundType.BACKGROUND_CUBEMAP;
   scene.environment.environmentImage = await rf.createImage({ name: 'cube', uri: $rawfile('Environment/quarry_02_2k_skybox.ktx') });
   scene.environment.radianceImage = await rf.createImage({ name: 'rad', uri: $rawfile('Environment/quarry_02_2k_radiance.ktx') });
   scene.environment.irradianceCoefficients =
     [{ x: 1.080343842506409, y: 0.936282396316528, z: 0.665518164634705 },
       { x: 0.959947884082794, y: 0.828918874263763, z: 0.569704353809357 },
       { x: 0.848236382007599, y: 0.715092182159424, z: 0.473145037889481 },
       { x: -0.591795265674591, y: -0.501678705215454, z: -0.334018945693970 },
       { x: -0.775423347949982, y: -0.655484378337860, z: -0.437325984239578 },
       { x: 1.053589701652527, y: 0.887459456920624, z: 0.587381422519684 },
       { x: -0.018954016268253, y: -0.014871496707201, z: -0.008891185745597 },
       { x: -0.566255271434784, y: -0.476870059967041, z: -0.314557582139969 },
       { x: -0.239390164613724, y: -0.200478553771973, z: -0.132790848612785 }];
   ```

5. Create a camera and set the view.

   Create a camera object, set its position and target, and then enable orbit control to allow users to rotate and zoom the view with gestures.

   <!-- @[pbr_clearcoat_createCamera](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   this.cam = await rf.createCamera({ 'name': 'ClearcoatCam' });
   this.cam.enabled = true;
   lookAt(this.cam,{x:0,y:0,z:-3},{x:0,y:0,z:0},{x:0,y:1,z:0});
   this.sceneOpt = { scene: this.scene, modelType: ModelType.SURFACE } as SceneOptions;
   this.orbitCamera.SetOrbitFromEye(this.cam.position, this.scene.root.position, this.cam.rotation);
   ```

6. Switch the clear coat texture.

   To allow users to switch between different clear coat textures, provide a button or event trigger for dynamic texture switching.

   <!-- @[pbr_clearcoat_changeClearcoatTexture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   changeClearcoatTex() {
     if (this.textures.length > 0) {
       let i = ++this.textureInUse % this.textures.length;
       (this.material as MetallicRoughnessMaterial).clearCoat.image = this.textures[i];
     }
   }
   ```

7. Adjust the strength of the clear coat layer.

   To adjust the strength of the clear coat layer, use a slider to update the **clearCoat.factor** property of the material.

   <!-- @[pbr_clearcoat_setClearcoat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   setClearcoat(v: number) {
     if (this.material) {
       const f: Vec4 = (this.material as MetallicRoughnessMaterial).clearCoat.factor;
       f.x = v / RESO;
       (this.material as MetallicRoughnessMaterial).clearCoat.factor = f;
     }
   }
   ```

8. Switch the clear coat layer roughness texture.

   Similar to clear coat texture switching, you can also switch between different clear coat layer roughness textures.

   <!-- @[pbr_clearcoat_changeRoughnessTexture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   changeClearcoatRoughTex() {
     if (this.textures.length > 0) {
       let i = ++this.textureInUse % this.textures.length;
       (this.material as MetallicRoughnessMaterial).clearCoatRoughness.image = this.textures[i];
     }
   }
   ```

9. Adjust the roughness of the clear coat layer.

   To adjust the roughness of the clear coat layer, use a slider to update the **clearCoatRoughness.factor** property of the material.

   <!-- @[pbr_clearcoat_setClearcoatRoughness](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material/pbr_clearcoat.ets) -->

   ``` TypeScript
   setClearcoatRoughness(v: number) {
     if (this.material) {
       const f: Vec4 = (this.material as MetallicRoughnessMaterial).clearCoatRoughness.factor;
       f.y = v / RESO;
       (this.material as MetallicRoughnessMaterial).clearCoatRoughness.factor = f;
     }
   }
   ```

<!--RP1-->

## Samples

For detailed code implementations and examples, you can visit the corresponding samples directory to learn more:

- [General Material Properties and PBR Material Example (ArkTS)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics3D/entry/src/main/ets/material)

The following sample is provided to help you better understand how to efficiently use 3D resources:

- [3D Engine Interface Example (ArkTS) (API version 12)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/Graphics3d)

<!--RP1End-->