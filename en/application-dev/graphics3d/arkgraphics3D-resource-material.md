# Creating and Using Material Resources
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

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

- **blend**: whether to enable the material's transparency mode. **true** means to enable, **false** otherwise. The default value is **false**.

  Use case: Enable for materials that need to display transparency or translucency, such as glass, water surfaces, smoke, and transparent plastics.

- **alphaCutoff**: alpha cutoff value, ranging from [0,1]. The default is **1**. Pixels with an alpha value below this threshold will not be rendered, used to achieve hard transparency clipping.

  Use case: For materials with hard transparency clipping, such as leaves, wire meshes, and fabric edges that have transparent areas without translucent gradients. By setting the threshold, transparent parts can be quickly clipped.

- **renderSort**: rendering sort setting, used to control the rendering order of materials in the rendering queue to ensure correct overlay display of transparent or special effect materials.

  Use case: For scenes with multiple transparent materials, overlay effects, and UI elements, where strict rendering order is required.

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


## How to Develop
  1. Obtain the resource factory.

     Use a **Scene** object or other interfaces to obtain a **SceneResourceFactory** instance, which is used to create material resources.

       ```ts
     // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
     let scenePromise: Promise<Scene> = Scene.load($rawfile("gltf/ExampleModel.glb"));
     scenePromise.then(async (scene: Scene) => {
     if (!scene.root) {
         return;
     }
     let rf: SceneResourceFactory = scene.getResourceFactory();
     // Subsequent operations can be performed based on rf.
     });
       ```

  2. Create a material and specify the material type.

     Call **createMaterial()** to specify the material type (such as **MaterialType.METALLIC_ROUGHNESS** or **MaterialType.SHADER**), and asynchronously create a material object.

     - You can create a shader material. If you need to customize rendering effects, you can use custom shaders. The sample code is as follows:

       ```ts
       let shaderMaterialPromise = await rf.createMaterial({ name: "shaderMat" }, MaterialType.SHADER);
       let shaderMat = shaderMaterialPromise as ShaderMaterial;
       // Bind the custom shader. (Create shader resources. The path and file name can be customized based on the specific project resources.)
       let shader = await rf.createShader({ name: "MyShader", uri: $rawfile("shaders/my_shader.shader") });
       shaderMat.colorShader = shader;
       ```

     - You can also create a PBR material. If you need to quickly build realistic rendering effects, use preset parameters. The sample code is as follows:

       ```ts
       let pbrMaterialPromise = await rf.createMaterial({ name: "pbrMat" }, MaterialType.METALLIC_ROUGHNESS);
       let pbrMat = pbrMaterialPromise as MetallicRoughnessMaterial;
       // Set the base color texture and factor.
       // Load image resources. The path and file name can be customized based on the specific project resources. However, the PBR material texture type must match the material properties.
       let baseColorImage = await rf.createImage({ name: "baseColorTex", uri: $rawfile("textures/baseColor.png") });
       pbrMat.baseColor.image = baseColorImage;
       pbrMat.baseColor.factor = { x: 1, y: 1, z: 1, w: 1 };
       ```

  3. Set material properties.

     - Set universal properties. The sample code is as follows:

       ```ts
       material.shadowReceiver = true;  // Enable shadow receiving.
       material.cullMode = CullMode.BACK;  // Enable back-facing culling.
       material.blend = { enabled: true };  // Enable transparency blending.
       material.alphaCutoff = 0.5;  // Alpha cutoff value.
       material.renderSort = { renderSortLayer: 32, renderSortLayerOrder: 1 };  // Rendering sort order.
       ```

     - When the created material is PBR-based, you can also set PBR material properties. The sample code is as follows:

       The texture maps for different properties generally vary and should be created individually. When several materials use the same texture, you can share a single Image instance to conserve memory. All material property factors use the value range [0, 1].

       ```ts
       // The image path and file name can be customized based on the actual project resources. However, the PBR material texture type must match the material property.
       // Set the base color texture and color factor (supporting the alpha channel).
       let baseColorImage = await rf.createImage({ name: "baseColorTex", uri: $rawfile("textures/baseColor.png") });
       pbrMat.baseColor.image = baseColorImage;
       pbrMat.baseColor.factor = { x: 1, y: 1, z: 1, w: 1 }; // The components x, y, and z control color, and w controls alpha (0–1).
       // Set the normal map (controlling surface detail bumps).
       let normalImage = await rf.createImage({ name: "normalTex", uri: $rawfile("textures/normal.png") });
       pbrMat.normal.image = normalImage;
       pbrMat.normal.factor.x = 0.6; // x component: normal intensity (0–1).
       // Set roughness, metallic, and reflectivity properties. (A single texture can be shared.) The y, z, and w components are used to control the properties.
       let metallicRoughnessImage = await rf.createImage({ name: "materialTex", uri: $rawfile("textures/material_texture.png") });
       pbrMat.material.image = metallicRoughnessImage;
       pbrMat.material.factor.y = 1.0; // y component: roughness (0–1). 0 means smooth, and 1 means rough.
       pbrMat.material.factor.z = 0.5; // z component: metallic (0–1). 0 means non-metallic, and 1 means metallic.
       pbrMat.material.factor.w = 0.5; // w component: specular (0–1).
       // Set the ambient occlusion map. The x component is used to control the occlusion strength.
       let ambientOcclusionImage = await rf.createImage({ name: "ambientOcclusionTex", uri: $rawfile("textures/ambientOcclusion.png") });
       pbrMat.ambientOcclusion.image = ambientOcclusionImage;
       pbrMat.ambientOcclusion.factor.x = 1.0; // Occlusion strength (0–1).
       // Set the emissive map and color factor (for glow effects).
       let emissiveImage = await rf.createImage({ name: "emissiveTex", uri: $rawfile("textures/emissive.png") });
       pbrMat.emissive.image = emissiveImage;
       pbrMat.emissive.factor = { x: 1.0, y: 1.0, z: 0.8, w: 1 }; // The components x, y, and z control glow color, and w controls intensity (0–1).
       // Set the clear coat strength and roughness.
       pbrMat.clearCoat.factor.x = 1.0; // x component: clear coat strength (0–1).
       pbrMat.clearCoatRoughness.factor.y = 0.5; // y component: clear coat roughness (0–1).
       // Set the clear coat normal map. The x, y, and z components control the direction.
       let clearCoatNormalImage = await rf.createImage({ name: "clearCoatNormalTex", uri: $rawfile("textures/clearCoatNormal.png") });
       pbrMat.clearCoatNormal.image = clearCoatNormalImage;
       pbrMat.clearCoatNormal.factor.x = 1.0;
       pbrMat.clearCoatNormal.factor.y = 1.0;
       pbrMat.clearCoatNormal.factor.z = 1.0;
       // Set more PBR properties as needed, such as sheen and specular.
       // sheen: controls sheen intensity.
       // pbrMat.sheen.factor = { x: 1.0, y: 0.5, z: 0.3, w: 1.0 }; // The components x, y, and z control sheen color, and w controls intensity (0–1).

       // specular: controls specularity.
       // pbrMat.specular.factor = { x: 1.0, y: 1.0, z: 1.0, w: 0.7 }; // The components x, y, and z control specularity color, and w controls intensity (0–1).
       ```

     - For Shader materials, bind custom shader resources to implement personalized rendering effects. For details, see [Creating Shader Materials and Setting Properties](#creating-shader-materials-and-setting-properties).

  4. Bind the material to the mesh.

     Assign the created material to the **material** or **subMeshes[i].material** field of a geometry to make it effective. There are two common binding methods:

       - Create a mesh and geometry through the resource factory, and then bind the material. (This method is suitable for creating new geometries.) The sample code is as follows:

         ```ts
         let mesh = await resourceFactory.createMesh({ name: "mesh" }, geometry);
         let geometryInstance = await resourceFactory.createGeometry({ name: "geometry" }, mesh);
         geometryInstance.mesh.subMeshes[0].material = pbrMat;  // Bind the material.
         ```

       - Directly obtain an existing geometry node via **scene.root.getNodeByPath** and modify the bound material. (This method is suitable for modifying materials after loading a scene.) The sample code is as follows:

         ```ts
         let pbrNode = scene.root.getNodeByPath("path/to/node");
         if (pbrNode) {
           let geometry = pbrNode as Geometry;
           if (geometry.mesh?.subMeshes?.[0]) {
             geometry.mesh.subMeshes[0].material = pbrMat;  // Bind the material.
           }
         }
         ```

  5. Render the mesh and observe the effect. Execute rendering to visualize the material.


## Complete Code

  ### Creating Shader Materials and Setting Properties

   ```ts
   import { MaterialType, ShaderMaterial, SceneResourceParameters, SceneResourceFactory, Scene, Geometry,
     CullMode } from '@kit.ArkGraphics3D';

   function createAndApplyShaderMaterial(): Promise<void> {
     // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
     let scenePromise: Promise<Scene> = Scene.load($rawfile("gltf/CubeWithFloor/glTF/AnimatedCube.glb"));
     return scenePromise.then(async (scene: Scene) => {
       if (!scene.root) {
         return;
       }
       // Obtain the resource factory.
       let rf: SceneResourceFactory = scene.getResourceFactory();
       // Create a shader material.
       let materialParams: SceneResourceParameters = { name: "material" };
       let material = await rf.createMaterial(materialParams, MaterialType.SHADER);
       let shaderMat = material as ShaderMaterial;
       // Load and bind the custom shader. (Create shader resources. The path and file name can be customized based on the specific project resources.)
       let shader = await rf.createShader({
         name: "shaderResource",
         uri: $rawfile("shaders/custom_shader/custom_material_sample.shader")
       });
       shaderMat.colorShader = shader;
       // Set universal properties.
       shaderMat.shadowReceiver = true;
       shaderMat.cullMode = CullMode.BACK;
       shaderMat.blend = { enabled: true }; // For example, enable transparency blending.
       shaderMat.alphaCutoff = 0.5;
       // Bind the material to an existing mesh node.
       let shaderNode = scene.root.getNodeByPath("rootNode_/Unnamed Node 1/AnimatedCube");
       if (shaderNode) {
         let geometry = shaderNode as Geometry;
         if (geometry.mesh?.subMeshes?.[0]) {
           geometry.mesh.subMeshes[0].material = shaderMat;
         }
       }
       // Render the mesh and observe the effect.
     });
   }
   ```

  ### Creating PBR Materials and Setting Properties

Different models may support different PBR properties. Before setting the material, you are advised to adapt it according to the model content. This example uses the CompareClearcoat model to set its supported PBR properties. You can use the corresponding model and set related properties as needed.

   ```ts
   import { MaterialType, SceneResourceParameters, SceneResourceFactory, Scene, MetallicRoughnessMaterial, Geometry,
     CullMode } from '@kit.ArkGraphics3D';

   function createAndApplyPBRMaterial(): Promise<void> {
     // Load scene resources, which supports .gltf and .glb formats. The path and file name can be customized based on the specific project resources.
     // Different models may support different PBR properties. Before setting the material, you are advised to adapt it according to the model content. This example uses the CompareClearcoat model to set its supported PBR properties.
     let scenePromise: Promise<Scene> = Scene.load($rawfile("CompareClearcoat.glb"));
     return scenePromise.then(async (scene: Scene) => {
       if (!scene.root) {
         return;
       }
       // Obtain the resource factory.
       let rf: SceneResourceFactory = scene.getResourceFactory();
       // Create a PBR material.
       let materialParams: SceneResourceParameters = { name: "MyPBRMaterial" };
       let material = await rf.createMaterial(materialParams, MaterialType.METALLIC_ROUGHNESS);
       let pbrMat = material as MetallicRoughnessMaterial;

       // Load the shared metallic-roughness texture map (reusable, saving resources). The image path and file name can be customized based on the actual project resources. However, the texture type must match the material properties.
       let metallicImage = await rf.createImage({
         name: "materialTex",
         uri: $rawfile("gltf/DamagedHelmet/glTF/Default_metalRoughness.jpg")
       });
       pbrMat.material.image = metallicImage;
       // Configure the y, z, and w components to control roughness, metallic appearance, and reflectivity.
       pbrMat.material.factor = { x: 0, y: 0.8, z: 0.4, w: 0.6 };
       // Set the ambient occlusion map.
       pbrMat.ambientOcclusion.factor.x = 1.0;
       // Set the clear coat strength and roughness.
       pbrMat.clearCoat.factor.x = 1.0;
       pbrMat.clearCoatRoughness.factor.y = 0.5;
       // Set the sheen gloss properties.
       pbrMat.sheen.factor = { x: 1.0, y: 0.2, z: 0.2, w: 0.8 };

       // Set universal properties.
       pbrMat.shadowReceiver = true;
       pbrMat.cullMode = CullMode.BACK;
       pbrMat.blend = { enabled: false };
       pbrMat.alphaCutoff = 0.5;
       // Bind the material to an existing mesh node.
       let pbrNode = scene.root.getNodeByPath("Unnamed Node 1/GeoSphere002");
       if (pbrNode) {
         let geometry = pbrNode as Geometry;
         geometry.mesh.subMeshes[0].material = pbrMat;
       }
       // Execute rendering to visualize the material.
     });
   }
   ```


<!--RP1-->
