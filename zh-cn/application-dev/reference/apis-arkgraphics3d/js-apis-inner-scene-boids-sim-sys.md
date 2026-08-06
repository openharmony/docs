# SceneBoidsSim (系统接口)
<!--Kit: ArkGraphics 3D-->
<!--Subsystem: Graphics-->
<!--Owner: @zzhao0-->
<!--Designer: @zdustc-->
<!--Tester: @zhangyue283-->
<!--Adviser: @ge-yafang-->

本模块提供ArkGraphics 3D中群组模拟动画的类型及操作方法。群组模拟动画是通过分离、对齐、凝聚等规则驱动群体中的个体，使其展现出类似自然界中鸟群、鱼群运动特征的计算机动画方法。

> **说明：** 
> - 本模块接口为系统接口。
> - 使用本模块的接口前，需先通过[RenderContext.loadPlugin](js-apis-inner-scene.md#loadplugin20)加载群组模拟插件[BoidsSimPlugin](#boidssimplugin)。

**起始版本：** 26.0.0

## 导入模块

```ts
import { BoidsSimPlugin, BoidsSimWorld, BoidsSimParameters,
  BoidsSimGravityParameters, BoidsSimRepulsionParameters } from '@kit.ArkGraphics3D';
```

## BoidsSimParameters

群组模拟参数，用于配置每个个体的行为属性。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

> **说明：**
>
> 模拟帧是指群组模拟中按固定时间步长执行的更新周期，类似Unity中的FixedUpdate。默认时间步长为16ms（约62.5FPS），模拟通过累积真实时间并按固定步长消耗来驱动。下文部分参数的默认值基于该时间步长计算：
> - **maxVelocityMag：** 0.01 / 0.016 ≈ 0.625（m/s）。
> - **maxAccelerationMag：** maxVelocityMag / 0.016 ≈ 39.06（m/s²）。
> - **maxTurnRate：** π × 0.75 × 0.016 ≈ 0.0377（rad/模拟帧）。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| initialVelocity | [Vec3](js-apis-inner-scene-types.md#vec3) | 否 | 是 | 每个个体的初始速度向量，各分量单位为m/s。默认值为(0, 0, 0)。 |
| initialPosition | [Vec3](js-apis-inner-scene-types.md#vec3) | 否 | 是 | 每个个体的初始位置，各分量单位为m。未设置时保留当前实体位置。默认值为(NaN, NaN, NaN)。 |
| initialRotation | [Quaternion](js-apis-inner-scene-types.md#quaternion) | 否 | 是 | 每个个体的初始旋转方向的四元数。未设置时保留当前实体旋转方向的四元数。默认值为(NaN, NaN, NaN, NaN)。 |
| boundaryMinPos | [Vec3](js-apis-inner-scene-types.md#vec3) | 否 | 是 | 约束个体运动范围的轴对齐包围盒最小角点，各分量单位为m。当boundaryMinPos的任一分量大于或等于boundaryMaxPos对应分量时，该个体视为无边界约束。默认值为(0, 0, 0)。 |
| boundaryMaxPos | [Vec3](js-apis-inner-scene-types.md#vec3) | 否 | 是 | 约束个体运动范围的轴对齐包围盒最大角点，各分量单位为m。默认值为(0, 0, 0)。 |
| maxVelocityMag | number | 否 | 是 | 个体每模拟帧可达到的最大速度，单位为m/s。取值 >= 0。默认值约为0.625。 |
| maxAccelerationMag | number | 否 | 是 | 个体每模拟帧可达到的最大加速度，单位为m/s²。取值 >= 0。默认值约为39.06。 |
| maxTurnRate | [Vec3](js-apis-inner-scene-types.md#vec3) | 否 | 是 | 每模拟帧每轴最大转向速率，各分量单位为rad/模拟帧。每个分量取值 >= 0。默认值各分量约为0.0377。 |
| separationWeight | number | 否 | 是 | 分离规则权重。个体在separationDistance范围内受邻近个体排斥的强度。取值 >= 0。默认值为0.0。 |
| separationDistance | number | 否 | 是 | 分离规则的感知半径，单位为m。仅严格在该距离内的邻近个体对分离力有贡献（边界处力为0）。取值 >= 0。默认值为0.0。 |
| alignmentWeight | number | 否 | 是 | 对齐规则权重。个体在alignmentDistance范围内朝向邻近个体平均航向的强度。取值 >= 0。默认值为0.0。 |
| alignmentDistance | number | 否 | 是 | 对齐规则的感知半径，单位为m。在该距离内（含边界）的邻近个体对对齐力有贡献。取值 >= 0。默认值为0.0。 |
| cohesionWeight | number | 否 | 是 | 凝聚规则权重。个体在cohesionDistance范围内朝向邻近个体平均位置吸引的强度。取值 >= 0。默认值为0.0。 |
| cohesionDistance | number | 否 | 是 | 凝聚规则的感知半径，单位为m。在该距离内（含边界）的邻近个体对凝聚力有贡献。取值 >= 0。默认值为0.0。 |
| boundaryWeight | number | 否 | 是 | 边界约束力权重。个体在boundaryDistance范围内被边界墙推回的强度。取值 >= 0。默认值为0.0。 |
| boundaryDistance | number | 否 | 是 | 边界约束力生效距离，单位为m。个体距边界墙面在该距离内时受到排斥力。取值 >= 0。默认值为0.0。 |
| gravityWeight | number | 否 | 是 | 引力场权重。引力场对该个体的吸引强度。取值 >= 0。默认值为0.0。 |
| repulsionWeight | number | 否 | 是 | 斥力场权重。斥力场对该个体的排斥强度。取值 >= 0。默认值为0.0。 |

## BoidsSimGravityParameters

引力场参数，用于配置场景中的引力场。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| radius | number | 否 | 是 | 引力场的作用半径。仅严格在该距离内的个体受到吸引（边界处力为0）。取值 >= 0。默认值为0.0。 |
| accelerationMag | number | 否 | 是 | 施加于个体的吸引加速度大小，其方向指向引力场实体。取值 >= 0。默认值为0.0。 |

## BoidsSimRepulsionParameters

斥力场参数，用于配置场景中的斥力场。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| radius | number | 否 | 是 | 斥力场的作用半径。仅严格在该距离内的个体受到排斥（边界处力为0）。取值 >= 0。默认值为0.0。 |
| accelerationMag | number | 否 | 是 | 施加于个体的排斥加速度大小，其方向远离斥力场实体。取值 >= 0。默认值为0.0。 |

## BoidsSimWorld

群组模拟世界对象，用于管理群组模拟的生命周期及组件。

> **说明：**
>
> 使用以下接口前，需先通过[BoidsSimPlugin.getDefaultBoidsSimWorld](#getdefaultboidssimworld)获取群组模拟世界实例。

### 属性

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| isPlaying | boolean | 是 | 否 | 当前模拟是否正在播放。true表示正在播放，false表示已经暂停。 |

### play

play(): void

开始或恢复群组模拟。当群组模拟处于停止状态时，调用此方法可以开始群组模拟；当群组模拟处于暂停状态时，调用此方法可以恢复群组模拟。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function controlBoidsSimLifecycle(world: BoidsSimWorld): void {
  world.play();
}
```

### pause

pause(): void

暂停群组模拟。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function pauseBoidsSim(world: BoidsSimWorld): void {
  world.pause();
}
```

### stop

stop(): void

停止群组模拟并重置状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**示例：**
```ts
import { BoidsSimWorld } from '@kit.ArkGraphics3D';

function stopBoidsSim(world: BoidsSimWorld): void {
  world.stop();
}
```

### addBoidsSimComponent

addBoidsSimComponent(node: Node, param: BoidsSimParameters): void

在指定节点上添加群组行为组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimParameters](#boidssimparameters) | 是 | 群组行为参数。 |

**示例：**
```ts
import { BoidsSimParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  // 添加群组行为组件
  let boidsParams: BoidsSimParameters = {
    boundaryMinPos: { x: -10.0, y: -10.0, z: -10.0 },
    boundaryMaxPos: { x: 10.0, y: 10.0, z: 10.0 },
    separationWeight: 4.0,
    separationDistance: 0.5,
  };
  world.addBoidsSimComponent(node, boidsParams);

  // 更新群组行为组件
  world.setBoidsSimComponent(node, boidsParams);

  // 获取群组行为参数
  let params: BoidsSimParameters | null = world.getBoidsSimComponent(node);

  // 移除群组行为组件
  world.removeBoidsSimComponent(node);
}
```

### setBoidsSimComponent

setBoidsSimComponent(node: Node, param: BoidsSimParameters): void

更新指定节点上的群组行为组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimParameters](#boidssimparameters) | 是 | 群组行为参数。 |

**示例：**
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

在指定节点上添加引力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimGravityParameters](#boidssimgravityparameters) | 是 | 引力场参数。 |

**示例：**
```ts
import { BoidsSimGravityParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimGravityComponent(world: BoidsSimWorld, fieldNode: Node): void {
  // 添加引力场组件
  let gravityParams: BoidsSimGravityParameters = { accelerationMag: 4.0, radius: 10.0 };
  world.addBoidsSimGravityComponent(fieldNode, gravityParams);

  // 更新引力场组件
  world.setBoidsSimGravityComponent(fieldNode, gravityParams);

  // 获取引力场参数
  let grav: BoidsSimGravityParameters | null = world.getBoidsSimGravityComponent(fieldNode);

  // 移除引力场组件
  world.removeBoidsSimGravityComponent(fieldNode);
}
```

### setBoidsSimGravityComponent

setBoidsSimGravityComponent(node: Node, param: BoidsSimGravityParameters): void

更新指定节点上的引力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimGravityParameters](#boidssimgravityparameters) | 是 | 引力场参数。 |

**示例：**
```ts
import { BoidsSimGravityParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function updateBoidsSimGravityComponent(world: BoidsSimWorld, node: Node): void {
  let newParams: BoidsSimGravityParameters = { accelerationMag: 8.0, radius: 15.0 };
  world.setBoidsSimGravityComponent(node, newParams);
}
```

### addBoidsSimRepulsionComponent

addBoidsSimRepulsionComponent(node: Node, param: BoidsSimRepulsionParameters): void

在指定节点上添加斥力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) | 是 | 斥力场参数。 |

**示例：**
```ts
import { BoidsSimRepulsionParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function manageBoidsSimRepulsionComponent(world: BoidsSimWorld, fieldNode: Node): void {
  // 添加斥力场组件
  let repulsionParams: BoidsSimRepulsionParameters = { accelerationMag: 4.0, radius: 10.0 };
  world.addBoidsSimRepulsionComponent(fieldNode, repulsionParams);

  // 更新斥力场组件
  world.setBoidsSimRepulsionComponent(fieldNode, repulsionParams);

  // 获取斥力场参数
  let repl: BoidsSimRepulsionParameters | null = world.getBoidsSimRepulsionComponent(fieldNode);

  // 移除斥力场组件
  world.removeBoidsSimRepulsionComponent(fieldNode);
}
```

### setBoidsSimRepulsionComponent

setBoidsSimRepulsionComponent(node: Node, param: BoidsSimRepulsionParameters): void

更新指定节点上的斥力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |
| param | [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) | 是 | 斥力场参数。 |

**示例：**
```ts
import { BoidsSimRepulsionParameters, BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function updateBoidsSimRepulsionComponent(world: BoidsSimWorld, node: Node): void {
  let newParams: BoidsSimRepulsionParameters = { accelerationMag: 8.0, radius: 15.0 };
  world.setBoidsSimRepulsionComponent(node, newParams);
}
```

### getBoidsSimComponent

getBoidsSimComponent(node: Node): BoidsSimParameters \| null

获取指定节点上的群组行为参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [BoidsSimParameters](#boidssimparameters) \| null | 返回群组行为参数，若节点未挂载该组件则返回null。 |

**示例：**
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

获取指定节点上的引力场参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [BoidsSimGravityParameters](#boidssimgravityparameters) \| null | 返回引力场参数，若节点未挂载该组件则返回null。 |

**示例：**
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

获取指定节点上的斥力场参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [BoidsSimRepulsionParameters](#boidssimrepulsionparameters) \| null | 返回斥力场参数，若节点未挂载该组件则返回null。 |

**示例：**
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

移除指定节点上的群组行为组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**示例：**
```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimComponent(node);
}
```

### removeBoidsSimGravityComponent

removeBoidsSimGravityComponent(node: Node): void

移除指定节点上的引力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**示例：**
```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimGravityComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimGravityComponent(node);
}
```

### removeBoidsSimRepulsionComponent

removeBoidsSimRepulsionComponent(node: Node): void

移除指定节点上的斥力场组件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [Node](js-apis-inner-scene-nodes.md#node) | 是 | 目标场景的节点。 |

**示例：**
```ts
import { BoidsSimWorld, Node } from '@kit.ArkGraphics3D';

function removeBoidsSimRepulsionComponent(world: BoidsSimWorld, node: Node): void {
  world.removeBoidsSimRepulsionComponent(node);
}
```

## BoidsSimPlugin

群组模拟插件，提供静态方法用于获取群组模拟世界。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

### getDefaultBoidsSimWorld

static getDefaultBoidsSimWorld(scene: Scene): BoidsSimWorld \| null

获取与指定场景关联的群组模拟世界实例。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUi.Graphics3D

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| scene | [Scene](js-apis-inner-scene.md#scene-1) | 是 | 目标场景的对象。 |

**返回值：**
| 类型 | 说明 |
| ---- | ---- |
| [BoidsSimWorld](#boidssimworld) \| null | 返回群组模拟世界实例，若不存在则返回null。 |

**示例：**
```ts
import { BoidsSimPlugin, BoidsSimWorld, Scene, RenderContext } from '@kit.ArkGraphics3D';

async function initBoidsSim(): Promise<BoidsSimWorld | null> {
  const renderContext: RenderContext | null = Scene.getDefaultRenderContext();
  if (!renderContext) {
    return null;
  }
  // 群组模拟插件UUID
  const BOIDS_SIM_PLUGIN_UUID: string = 'a1b2c3d4-e5f6-4a5b-8c9d-0e1f2a3b4c5d';
  // 加载群组模拟插件
  const loaded: boolean = await renderContext.loadPlugin(BOIDS_SIM_PLUGIN_UUID);
  if (!loaded) {
    return null;
  }
  // 创建空场景
  const scene: Scene = await Scene.load();
  // 获取群组模拟世界实例
  const world: BoidsSimWorld | null = BoidsSimPlugin.getDefaultBoidsSimWorld(scene);
  return world;
}
```
