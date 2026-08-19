# SceneBoidsSim (System API)

<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=5bc262ed75d6721bdce7356b567e19cbd8bd3794 translatedAt=2026-08-13T13:23:23.625Z pushedAt=2026-08-17T07:43:18.113Z -->

This module provides types and operation methods for Boids simulation animation in ArkGraphics 3D. Boids simulation animation is a computer animation method that drives individuals in a group through rules such as separation, alignment, and cohesion, making them exhibit movement characteristics similar to flocks of birds or schools of fish in nature.

> **NOTE**
> - The APIs of this module are system APIs.
> - Before using the APIs of this module, you need to load the Boids simulation plugin [BoidsSimPlugin](#boidssimplugin) through [RenderContext.loadPlugin](js-apis-inner-scene.md#loadplugin20).

**Since**: 26.0.0

## Modules to Import

```ts
import { BoidsSimPlugin, BoidsSimWorld, BoidsSimParameters,
  BoidsSimGravityParameters, BoidsSimRepulsionParameters } from '@kit.ArkGraphics3D';
```

## BoidsSimParameters

Boids simulation parameters used to configure the behavioral attributes of each individual.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

> **NOTE**
>
> A simulation frame refers to the update cycle executed at a fixed time step in the Boids simulation, similar to FixedUpdate in Unity. The default time step is 16 ms (approximately 62.5 FPS). The simulation is driven by accumulating real time and consuming it in fixed steps. The default values of some parameters below are calculated based on this time step:
> - **maxVelocityMag:** 0.01 / 0.016 ≈ 0.625 (m/s).
> - **maxAccelerationMag:** maxVelocityMag / 0.016 ≈ 39.06 (m/s²).
> - **maxTurnRate:** π × 0.75 × 0.016 ≈ 0.0377 (rad/simulation frame).

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| initialVelocity | [Vec3](js-apis-inner-scene-types.md#vec3) | No | Yes | Initial velocity vector of each individual, in m/s for each component. The default value is (0, 0, 0). |
| initialPosition | [Vec3](js-apis-inner-scene-types.md#vec3) | No | Yes | Initial position of each individual, in m for each component. If not set, the current entity position is retained. The default value is (NaN, NaN, NaN). |
| initialRotation | [Quaternion](js-apis-inner-scene-types.md#quaternion) | No | Yes | Quaternion of the initial rotation direction of each individual. If not set, the quaternion of the current entity rotation direction is retained. The default value is (NaN, NaN, NaN, NaN). |
| boundaryMinPos | [Vec3](js-apis-inner-scene-types.md#vec3) | No | Yes | Minimum corner of the axis-aligned bounding box that constrains the movement range of the individual, in m for each component. When any component of boundaryMinPos is greater than or equal to the corresponding component of boundaryMaxPos, the individual is considered to have no boundary constraint. The default value is (0, 0, 0). |
| boundaryMaxPos | [Vec3](js-apis-inner-scene-types.md#vec3) | No | Yes | Maximum corner of the axis-aligned bounding box that constrains the movement range of the individual, in m for each component. The default value is (0, 0, 0). |
| maxVelocityMag | number | No | Yes | Maximum velocity that the individual can reach per simulation frame, in m/s. The value must be >= 0. The default value is approximately 0.625. |
| maxAccelerationMag | number | No | Yes | Maximum acceleration that the individual can reach per simulation frame, in m/s². The value must be >= 0. The default value is approximately 39.06. |
| maxTurnRate | [Vec3](js-apis-inner-scene-types.md#vec3) | No | Yes | Maximum turn rate per axis per simulation frame, in rad/simulation frame for each component. Each component must be >= 0. The default value of each component is approximately 0.0377. |
| separationWeight | number | No | Yes | Weight of the separation rule. The intensity with which the individual is repelled by neighboring individuals within the separationDistance range. The value must be >= 0. The default value is 0.0. |
| separationDistance | number | No | Yes | Perception radius of the separation rule, in m. Only neighboring individuals strictly within this distance contribute to the separation force (the boundary force is 0). The value must be >= 0. The default value is 0.0. |
| alignmentWeight | number | No | Yes | Weight of the alignment rule. The intensity with which the individual steers toward the average heading of neighboring individuals within the alignmentDistance range. The value must be >= 0. The default value is 0.0. |
| alignmentDistance | number | No | Yes | Perception radius of the alignment rule, in m. Neighboring individuals within this distance (inclusive of the boundary) contribute to the alignment force. The value must be >= 0. The default value is 0.0. |
| cohesionWeight | number | No | Yes | Weight of the cohesion rule. The intensity with which the individual is attracted toward the average position of neighboring individuals within the cohesionDistance range. The value must be >= 0. The default value is 0.0. |
| cohesionDistance | number | No | Yes | Perception radius of the cohesion rule, in m. Neighboring individuals within this distance (inclusive of the boundary) contribute to the cohesion force. The value must be >= 0. The default value is 0.0. |
| boundaryWeight | number | No | Yes | Weight of the boundary constraint force. The intensity with which the individual is pushed back by the boundary wall within the boundaryDistance range. The value must be >= 0. The default value is 0.0. |
| boundaryDistance | number | No | Yes | Effective distance of the boundary constraint force, in m. The individual is repelled when its distance to the boundary wall is within this distance. The value must be >= 0. The default value is 0.0. |
| gravityWeight | number | No | Yes | Weight of the attraction field. The intensity with which the attraction field attracts the individual. The value must be >= 0. The default value is 0.0. |
| repulsionWeight | number | No | Yes | Weight of the repulsion field. The intensity with which the repulsion field repels the individual. The value must be >= 0. The default value is 0.0. |

## BoidsSimGravityParameters

Attraction field parameters, used to configure the attraction field in the scene.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| radius | number | No | Yes | Radius of the attraction field. Only individuals strictly within this distance are attracted (the boundary force is 0). The value must be greater than or equal to 0. The default value is 0.0. |
| accelerationMag | number | No | Yes | Magnitude of the attraction acceleration applied to an individual, with the direction pointing to the attraction field entity. The value must be greater than or equal to 0. The default value is 0.0. |

## BoidsSimRepulsionParameters

Repulsion field parameters, used to configure the repulsion field in the scene.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| radius | number | No | Yes | Radius of the repulsion field. Only individuals strictly within this distance are repelled (the boundary force is 0). The value must be greater than or equal to 0. The default value is 0.0. |
| accelerationMag | number | No | Yes | Magnitude of the repulsion acceleration applied to individuals, with the direction pointing away from the repulsion field entity. The value must be greater than or equal to 0. The default value is 0.0. |

## BoidsSimWorld

The Boids simulation world object, used to manage the lifecycle and components of the Boids simulation.

> **NOTE**
>
> Before using the following APIs, you need to obtain the Boids simulation world instance through [BoidsSimPlugin.getDefaultBoidsSimWorld](#getdefaultboidssimworld).

### Attributes

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| isPlaying | boolean | Yes | No | Whether the current simulation is playing. The value **true** indicates that it is playing, and **false** indicates that it is paused. |

### play

play(): void

Starts or resumes the boids simulation. When the boids simulation is in the stopped state, calling this method starts the boids simulation; when the boids simulation is in the paused state, calling this method resumes the boids simulation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**

```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function controlBoidsSimLifecycle(world: BoidsSimWorld): void {
  world.play();
}
```

### pause

pause(): void

Pauses the Boids simulation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**

```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function pauseBoidsSim(world: BoidsSimWorld): void {
  world.pause();
}
```

### stop

stop(): void

Stops the Boids simulation and resets the state.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Example**

```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function stopBoidsSim(world: BoidsSimWorld): void {
  world.stop();
}
```

### addBoidsSimComponent

addBoidsSimComponent(node: Node, param: BoidsSimParameters): void

Adds a flock behavior component at the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |
| param | [BoidsSimParameters](#boidssimparameters) | Yes | Boids behavior parameters. |

**Example**

```ts
import { BoidsSimParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  // Add the boids behavior component.
  let boidsParams: BoidsSimParameters = {
    boundaryMinPos: { x: -10.0, y: -10.0, z: -10.0 },
    boundaryMaxPos: { x: 10.0, y: 10.0, z: 10.0 },
    separationWeight: 4.0,
    separationDistance: 0.5,
  };
  world.addBoidsSimComponent(node, boidsParams);

  // Update the boids behavior component.
  world.setBoidsSimComponent(node, boidsParams);

  // Obtain the boids behavior parameters.
  let params: BoidsSimParameters | null = world.getBoidsSimComponent(node);

  // Remove the boids behavior component.
  world.removeBoidsSimComponent(node);
}
```

### setBoidsSimComponent

setBoidsSimComponent(node: Node, param: BoidsSimParameters): void

Updates the flock behavior component on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |
| param | [BoidsSimParameters](#boidssimparameters) | Yes | Boids behavior parameters. |

**Example**

```ts
import { BoidsSimParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function updateBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  let newParams: BoidsSimParameters = {
    boundaryMinPos: { x: -20.0, y: -20.0, z: -20.0 },
    boundaryMaxPos: { x: 20.0, y: 20.0, z: 20.0 },
    separationWeight: 5.0,
    separationDistance: 1.0,
  };
  world.setBoidsSimComponent(node, newParams);
}
```

### addBoidsSimGravityComponent

addBoidsSimGravityComponent(node: Node, param: BoidsSimGravityParameters): void

Adds an attraction field component at the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node of the target scene. |
| param | [BoidsSimGravityParameters](#boidssimgravityparameters) | Yes | Attraction field parameters. |

**Example**

```ts
import { BoidsSimGravityParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimGravityComponent(world: BoidsSimWorld, fieldNode: Node): void {
  // Add the attraction field component.
  let gravityParams: BoidsSimGravityParameters = { accelerationMag: 4.0, radius: 10.0 };
  world.addBoidsSimGravityComponent(fieldNode, gravityParams);

  // Update the attraction field component.
  world.setBoidsSimGravityComponent(fieldNode, gravityParams);

  // Obtain the attraction field parameters.
  let grav: BoidsSimGravityParameters | null = world.getBoidsSimGravityComponent(fieldNode);

  // Remove the attraction field component.
  world.removeBoidsSimGravityComponent(fieldNode);
}
```

### setBoidsSimGravityComponent

setBoidsSimGravityComponent(node: Node, param: BoidsSimGravityParameters): void

Updates the attraction field component on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node of the target scene. |
| param | [BoidsSimGravityParameters](#boidssimgravityparameters) | Yes | Attraction field parameters. |

**Example**

```ts
import { BoidsSimGravityParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function updateBoidsSimGravityComponent(world: BoidsSimWorld, node: Node): void {
  let newParams: BoidsSimGravityParameters = { accelerationMag: 8.0, radius: 15.0 };
  world.setBoidsSimGravityComponent(node, newParams);
}
```

### addBoidsSimRepulsionComponent

addBoidsSimRepulsionComponent(node: Node, param: BoidsSimRepulsionParameters): void

Adds a repulsion field component at the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |
| param | [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) | Yes | Repulsion field parameters. |

**Example**

```ts
import { BoidsSimRepulsionParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimRepulsionComponent(world: BoidsSimWorld, fieldNode: Node): void {
  // Add the repulsion field component.
  let repulsionParams: BoidsSimRepulsionParameters = { accelerationMag: 4.0, radius: 10.0 };
  world.addBoidsSimRepulsionComponent(fieldNode, repulsionParams);

  // Update the repulsion field component.
  world.setBoidsSimRepulsionComponent(fieldNode, repulsionParams);

  // Obtain the repulsion field parameters.
  let repl: BoidsSimRepulsionParameters | null = world.getBoidsSimRepulsionComponent(fieldNode);

  // Remove the repulsion field component.
  world.removeBoidsSimRepulsionComponent(fieldNode);
}
```

### setBoidsSimRepulsionComponent

setBoidsSimRepulsionComponent(node: Node, param: BoidsSimRepulsionParameters): void

Updates the repulsion field component on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node of the target scene. |
| param | [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) | Yes | Repulsion field parameters. |

**Example**

```ts
import { BoidsSimRepulsionParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function updateBoidsSimRepulsionComponent(world: BoidsSimWorld, node: Node): void {
  let newParams: BoidsSimRepulsionParameters = { accelerationMag: 8.0, radius: 15.0 };
  world.setBoidsSimRepulsionComponent(node, newParams);
}
```

### getBoidsSimComponent

getBoidsSimComponent(node: Node): BoidsSimParameters \| null

Gets the flock behavior parameters on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |

**Return value**

| Type | Description |
| ---- | ---- |
| [BoidsSimParameters](#boidssimparameters) \| null | Boids behavior parameters. Returns null if the node does not have this component attached. |

**Example**

```ts
import { BoidsSimParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function queryBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  let params: BoidsSimParameters | null = world.getBoidsSimComponent(node);
  if (params) {
    let maxVel: number = params.maxVelocityMag;
  }
}
```

### getBoidsSimGravityComponent

getBoidsSimGravityComponent(node: Node): BoidsSimGravityParameters \| null

Gets the attraction field parameters on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |

**Return value**

| Type | Description |
| ---- | ---- |
| [BoidsSimGravityParameters](#boidssimgravityparameters) \| null | Attraction field parameters, or null if the node does not have this component attached. |

**Example**

```ts
import { BoidsSimGravityParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function queryBoidsSimGravityComponent(world: BoidsSimWorld, node: Node): void {
  let params: BoidsSimGravityParameters | null = world.getBoidsSimGravityComponent(node);
  if (params) {
    let accel: number = params.accelerationMag;
  }
}
```

### getBoidsSimRepulsionComponent

getBoidsSimRepulsionComponent(node: Node): BoidsSimRepulsionParameters \| null

Gets the repulsion field parameters on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |

**Return value**

| Type | Description |
| ---- | ---- |
| [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) \| null | Repulsion field parameters. Returns null if the node does not have this component attached. |

**Example**

```ts
import { BoidsSimRepulsionParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function queryBoidsSimRepulsionComponent(world: BoidsSimWorld, node: Node): void {
  let params: BoidsSimRepulsionParameters | null = world.getBoidsSimRepulsionComponent(node);
  if (params) {
    let accel: number = params.accelerationMag;
  }
}
```

### removeBoidsSimComponent

removeBoidsSimComponent(node: Node): void

Removes the flock behavior component from the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node of the target scene. |

**Example**

```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimComponent(node);
}
```

### removeBoidsSimGravityComponent

removeBoidsSimGravityComponent(node: Node): void

Removes the attraction field component on the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node of the target scene. |

**Example**

```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimGravityComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimGravityComponent(node);
}
```

### removeBoidsSimRepulsionComponent

removeBoidsSimRepulsionComponent(node: Node): void

Removes the repulsion field component from the specified node.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | Yes | Node in the target scene. |

**Example**

```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimRepulsionComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimRepulsionComponent(node);
}
```

## BoidsSimPlugin

Boids simulation plugin, providing static methods for obtaining the boids simulation world.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

### getDefaultBoidsSimWorld

static getDefaultBoidsSimWorld(scene: Scene): BoidsSimWorld \| null

Gets the Boids simulation world instance associated with the specified scene.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUi.Graphics3D

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| scene | [Scene](js-apis-inner-scene.md#scene-1) | Yes | Object of the target scene. |

**Return value**

| Type | Description |
| ---- | ---- |
| [BoidsSimWorld](#boidssimworld) \| null | Boids simulation world instance, or null if it does not exist. |

**Example**

```ts
import { BoidsSimPlugin, BoidsSimWorld, Scene, RenderContext } from '@kit.ArkGraphics3D';

async function initBoidsSim(): Promise<BoidsSimWorld | null> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return null;
  }
  // UUID of the Boids simulation plugin.
  const BOIDS_SIM_PLUGIN_UUID: string = 'a1b2c3d4-e5f6-4a5b-8c9d-0e1f2a3b4c5d';
  // Load the Boids simulation plugin.
  const loaded: boolean = await renderContext.loadPlugin(BOIDS_SIM_PLUGIN_UUID);
  if (!loaded) {
    return null;
  }
  // Create an empty scene.
  const scene: Scene = await Scene.load();
  // Obtain the Boids simulation world instance.
  const world: BoidsSimWorld | null = BoidsSimPlugin.getDefaultBoidsSimWorld(scene);
  return world;
}
```