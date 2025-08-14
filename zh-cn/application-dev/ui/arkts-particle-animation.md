# 粒子动画
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--SE: @yangfan229-->
<!--TSE: @lxl007-->

[粒子动画](../reference/apis-arkui/arkui-ts/ts-particle-animation.md)是通过在限定区域内随机生成大量粒子的运动，进而组合成的动画效果，通过Particle组件来实现。动画的基本构成元素为单个粒子，这些粒子可以表现为圆点或图片等形式。开发者能够通过对粒子在颜色、透明度、大小、速度、加速度、自旋角度等多个维度上的动态变化做动画，以营造特定的氛围，例如模拟下雪场景时，飘舞的雪花实际上是由一个个雪花粒子的动画效果所构成。

粒子动画的简单实现如下所示。
```ts
@Entry
@Component
struct ParticleExample {
  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor('rgb(240, 250, 255)')
      Particle({ particles: [
        {
          emitter: {
            particle: {
              type: ParticleType.POINT, // 粒子类型
              config: {
                radius: 5 // 圆点半径
              },
              count: 100, // 粒子总数
            },
          },
          color:{
            range:['rgb(39, 135, 217)','rgb(0, 74, 175)'],//初始颜色范围
          },
        },
      ]
      }).width(250).height(250)
    }.width("100%").height("100%").align(Alignment.Center)
  }
}
```

![particle-base](figures/particle-base.gif)


## 实现粒子发射器

粒子发射器（Particle Emitter）主要定义粒子的初始属性（如类型、位置和颜色），控制粒子的生成速率，以及管理粒子的生命周期。可通过[emitter](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#emitter12)方法调整粒子发射器的位置、发射速率和发射窗口的大小，实现发射器位置的动态更新。

```ts
// ...
@State emitterProperties: Array<EmitterProperty> = [
  {
    index: 0,
    emitRate: 100,
    position: { x: 60, y: 80 },
    size: { width: 200, height: 200 }
  }
]

Particle(...).width(300).height(300).emitter(this.emitterProperties) // 动态调整粒子发射器的位置
// ...
```

![particle-emitter](figures/particle-emitter.gif)


## 设置粒子颜色

可以通过[range](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#particlecolorpropertyoptions)来确定粒子的初始颜色范围，而[distributionType](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#particlecolorpropertyoptions)则用于指定粒子初始颜色随机值的分布方式，具体可选择均匀分布或者高斯（正态）分布。

```ts
// ...
color: {
  range: ['rgb(39, 135, 217)','rgb(0, 74, 175)'], // 初始颜色范围
  distributionType: DistributionType.GAUSSIAN // 初始颜色随机值分布
},
// ...
```

![particle-color](figures/particle-color.gif)


## 粒子的生命周期

粒子的生命周期（Lifecycle）是粒子从生成至消亡的整个过程，用于确定粒子的存活时间长度。粒子的生命周期可通过设置[lifetime](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#emitteroptions)和[lifetimeRange](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#emitteroptions)来指定。

```ts
// ...
emitter: {
  particle: {
    // ...
    lifetime: 300, // 粒子生命周期，单位ms
    lifetimeRange: 100 // 粒子生命周期取值范围，单位ms
  },
  emitRate: 10, // 每秒发射粒子数
  position: [0, 0],
  shape: ParticleEmitterShape.RECTANGLE // 发射器形状
},
color: {
  range: ['rgb(39, 135, 217)','rgb(0, 74, 175)'], // 初始颜色范围
},
// ...
```

![particle-lifetime](figures/particle-lifetime.gif)


## 设置粒子扰动场

扰动场（Disturbance Field）是一种影响粒子运动的机制。通过在粒子所在的空间区域内施加特定的力，扰动场能够改变粒子的轨迹和行为，进而实现更为复杂和自然的动画效果。扰动场的配置可以通过[disturbanceFields](../reference/apis-arkui/arkui-ts/ts-particle-animation.md#disturbancefields12)方法来完成。

```ts
// ...
Particle({ particles: [
  {
    emitter: // ...
    color: // ...
    scale: {
      range: [0.0, 0.0],
      updater: {
        type: ParticleUpdater.CURVE,
        config: [
          {
            from: 0.0,
            to: 0.5,
            startMillis: 0,
            endMillis: 3000,
            curve: Curve.EaseIn
          }
        ]
      }
    },
    acceleration: { //加速度的配置，从大小和方向两个维度变化，speed表示加速度大小，angle表示加速度方向
      speed: {
        range: [3, 9],
        updater: {
          type: ParticleUpdater.RANDOM,
          config: [1, 20]
        }
      },
      angle: {
        range: [90, 90]
      }
    }

  }
]
}).width(300).height(300).disturbanceFields([{
  strength: 10,
  shape: DisturbanceFieldShape.RECT,
  size: { width: 100, height: 100 },
  position: { x: 100, y: 100 },
  feather: 15,
  noiseScale: 10,
  noiseFrequency: 15,
  noiseAmplitude: 5
}])
// ... 
```

![particle-disturbance](figures/particle-disturbance.gif)