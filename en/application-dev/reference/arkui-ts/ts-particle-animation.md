# Particle Animation

Particle animation is an animation composed of a multitude of particles randomly generated within a certain range. The particles can be points or images. By animating different aspects of the particles, such as color, opacity, scale, velocity, acceleration, and spin angle, you can create engaging and dynamic aesthetics. For example, you can create an impressive snowfall animation by animating the particles – snowflakes.

The component used for producing particle animations is **Particle**.


>  **NOTE**
>
>  This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

```typescript
function Particle
<
  PARTICLE extends ParticleType,
  COLOR_UPDATER extends ParticleUpdater,
  OPACITY_UPDATER extends ParticleUpdater,
  SCALE_UPDATER extends ParticleUpdater,
  ACC_SPEED_UPDATER extends ParticleUpdater,
  ACC_ANGLE_UPDATER extends ParticleUpdater,
  SPIN_UPDATER extends ParticleUpdater
>(value: {
  particles: Array<
    ParticleOptions<
      PARTICLE, 
      COLOR_UPDATER, 
      OPACITY_UPDATER, 
      SCALE_UPDATER, 
      ACC_SPEED_UPDATER, 
      ACC_ANGLE_UPDATER, 
      SPIN_UPDATER
    >
  >
})

```

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | {<br>particles:Array&lt;[ParticleOptions](#particleoptions)&lt;<br>[PARTICLE](#particletype), <br>[COLOR_UPDATER](#particleupdater),<br>[OPACITY_UPDATER](#particleupdater),<br>[SCALE_UPDATER](#particleupdater),<br>[ACC_SPEED_UPDATER](#particleupdater),<br> [ACC_ANGLE_UPDATER](#particleupdater),<br>[SPIN_UPDATER](#particleupdater)<br>&gt;&gt;<br>} | Yes| An array of particle options, each of which covers the emitter, color, opacity, scale, velocity, acceleration, and spin speed of particles. For details, see [ParticleOptions](#particleoptions). |

## Attributes
The universal attributes are supported.

## Events
The universal events are supported.

## ParticleOptions

```typescript
interface ParticleOptions<
  PARTICLE extends ParticleType,
  COLOR_UPDATER extends ParticleUpdater,
  OPACITY_UPDATER extends ParticleUpdater,
  SCALE_UPDATER extends ParticleUpdater,
  ACC_SPEED_UPDATER extends ParticleUpdater,
  ACC_ANGLE_UPDATER extends ParticleUpdater,
  SPIN_UPDATER extends ParticleUpdater
> {
  emitter: EmitterOptions<PARTICLE>;
  color?: ParticleColorPropertyOptions<COLOR_UPDATER>;
  opacity?: ParticlePropertyOptions<number, OPACITY_UPDATER>;
  scale?: ParticlePropertyOptions<number, SCALE_UPDATER>;
  velocity?: {
    speed: [number, number];
    angle: [number, number];
  };
  acceleration?: {
    speed?: ParticlePropertyOptions<number, ACC_SPEED_UPDATER>;
    angle?: ParticlePropertyOptions<number, ACC_ANGLE_UPDATER>;
  };
  spin?: ParticlePropertyOptions<number, SPIN_UPDATER>;
}
```

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| emitter | [EmitterOptions](#emitteroptions)<[PARTICLE](#particletype)> | Yes| Particle emitter.|
| color | [ParticleColorPropertyOptions](#particlecolorpropertyoptions)<[COLOR_UPDATER](#particleupdater)> | No| Particle color.<br>**NOTE**<br>Default value: **{ range:[Color.White,Color.White] }.** Colors cannot be set for image particles.|
| opacity | [ParticlePropertyOptions](#particlepropertyoptions)\<number, [OPACITY_UPDATER](#particleupdater)> | No| Particle opacity.<br>Default value: **{range: [1.0,1.0] }**|
| scale | [ParticlePropertyOptions](#particlepropertyoptions)\<number, [SCALE_UPDATER](#particleupdater)> | No| Particle scale.<br>Default value: **{range: [1.0,1.0] }**|
| velocity | {<br>speed: [number, number];<br>angle: [number, number];<br>} |No| Particle velocity.<br>**NOTE**<br>**speed** indicates the time rate at which the particle moves, and **angle** indicates the direction (in angles) in which the particle moves.<br>Default value: **{speed: [0.0,0.0],angle: [0.0,0.0] }**|
| acceleration | {<br>speed?: [ParticlePropertyOptions](#particlepropertyoptions)<number, [ACC_SPEED_UPDATER](#particleupdater)>;<br>angle?:  [ParticlePropertyOptions](#particlepropertyoptions)<number, [ACC_ANGLE_UPDATER](#particleupdater)>;<br>} | No| Particle acceleration.<br>**NOTE**<br>**speed** indicates the acceleration speed, and **angle** indicates the acceleration direction (in angles).<br>Default value: **{speed:{range: [0.0,0.0] },angle:{range: [0.0,0.0] }}**|
| spin | [ParticlePropertyOptions](#particlepropertyoptions)<number, [SPIN_UPDATER](#particleupdater)> | No| Particle spin angle.<br>Default value: **{range: [0.0,0.0] }**|


## EmitterOptions
Provides particle emitter configuration.

```typescript
interface EmitterOptions<PARTICLE extends ParticleType> {   
  particle: {
    type: PARTICLE;
    config: ParticleConfigs[PARTICLE];
    count: number;
    lifetime?: number;
  };
  emitRate?: number;
  shape?: ParticleEmitterShape;
  position?: [Dimension, Dimension];
  size?: [Dimension, Dimension];
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| particle | {<br>type: [PARTICLE](#particletype),<br>config: [ParticleConfigs](#particleconfigs),<br>count: number,<br>lifetime?: number<br>} | Yes| Particle configuration.<br>- **type**: particle type, which can be **IMAGE** or **POINT**.<br>- **config**: configuration of the particle type.<br>- The value type of **config** is subject to the value of **type**.<br>1. If **type** is **ParticleType.POINT**, the **config** type is [PointParticleParameters](#pointparticleparameters).<br>2. If **type** is **ParticleType.IMAGE**, the **config** type is [ImageParticleParameters](#imageparticleparameters).<br>- **count**: number of particles. The value is greater than or equal to -1. The value **-1** indicates that the number of particles is infinite.<br>- **lifetime**: lifetime of a single particle. The default value is **1000** (that is, 1000 ms, 1s). The value is greater than or equal to -1. The value **-1** indicates that the lifetime of the particle is infinite.|
| emitRate | number | No| Emit rate (that is, the number of particles emitted per second). Default value: **5**|
| shape | [ParticleEmitterShape](#particleemittershape) | No| Emitter shape. Default value: **ParticleEmitterShape.RECTANGLE**|
| position | [Dimension, Dimension] | No| Emitter position (distance from the upper left corner of the component).<br>Default value: **[0.0, 0.0]**|
| size | [Dimension, Dimension] |No| Size of the emit window.<br>Default value: \['100%','100%'\] (that is, the emit window fully occupies the component).|

## ParticleConfigs

```typescript
interface ParticleConfigs { 
  [ParticleType.POINT]: PointParticleParameters;
  [ParticleType.IMAGE]: ImageParticleParameters;
}
```


| Parameter  | Type  | Mandatory| Description|
| -------- | -------------- | -------- | -------- |
| [ParticleType.POINT]      | [PointParticleParameters](#pointparticleparameters) | Yes   | Point particle configuration.|
| [ParticleType.IMAGE]      | [ImageParticleParameters](#imageparticleparameters) | Yes   | Image particle configuration.|

## PointParticleParameters
```typescript
interface PointParticleParameters {
  radius: VP;
}
```
| Parameter  | Type  | Mandatory| Description|
| -------- | -------------- | -------- | -------- |
| radius      | [VP](ts-types.md#vp)| Yes   | Particle radius.|

## ImageParticleParameters
```typescript
interface ImageParticleParameters {
  src: ResourceStr;
  size: [Dimension, Dimension];
  objectFit?: ImageFit;
}
```
| Parameter  | Type  | Mandatory| Description|
| -------- | -------------- | -------- | -------- |
| src      | [ResourceStr](ts-types.md#resourcestr) | Yes   | Image path. SVG and GIF images are not supported.|
| size     | \[[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)\]| Yes   | Image size.|
| objectFit| [ImageFit](ts-appendix-enums.md#imagefit)| No   | Image display mode.|

## ParticleColorPropertyOptions

```typescript
interface ParticleColorPropertyOptions<UPDATER extends ParticleUpdater> {
  range: [ResourceColor, ResourceColor]; 
  updater?: {
    type: UPDATER;
    config: ParticleColorPropertyUpdaterConfigs[UPDATER];
  };
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| range | \[[ResourceColor](ts-types.md#resourcecolor), [ResourceColor](ts-types.md#resourcecolor)\] | Yes| Initial color range of the particle. The initial color of particles generated by the particle emitter is randomly selected in this range.<br>Default value: **range:[Color.White,Color.White]**|
| updater | {<br>type: [UPDATER](#particleupdater);<br>config: [ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[UPDATER];<br>} | No| How the color attribute is updated. The available options of **type** are as follows:<br>1. **ParticleUpdater.NONE**: The attribute does not change. In this case, the **config** type is [ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.NONE].<br>2. **ParticleUpdater.RANDOM**: The attribute changes randomly. In this case, the **config** type is [ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.RANDOM].<br>3. **ParticleUpdater.CURVE**: The attribute changes with the animation curve. In this case, the **config** type is [ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.CURVE].|


## ParticleColorPropertyUpdaterConfigs
```typescript
interface ParticleColorPropertyUpdaterConfigs {
  [ParticleUpdater.NONE]: void;
  [ParticleUpdater.RANDOM]: {
    r: [number, number];
    g: [number, number];
    b: [number, number];
    a: [number, number];
  };
  [ParticleUpdater.CURVE]: Array<ParticlePropertyAnimation<ResourceColor>>;
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| [ParticleUpdater.NONE]|void | Yes| The color does not change. The default value is **undefined**.|
| [ParticleUpdater.RANDOM] | {<br>  r: [number, number];<br>  g: [number, number];<br>  b: [number, number];<br>  a: [number, number];<br>} | Yes| The color changes randomly. The color changes randomly.The target color is obtained by changing the value of each of the R, R, B, A channels and taking in the current color value.|
| [ParticleUpdater.CURVE]|Array<[ParticlePropertyAnimation](#particlepropertyanimation)\<[ResourceColor](ts-types.md#resourcecolor)\>> | Yes| The color changes with the animation curve. The array type indicates that multiple animation segments can be set for the current attribute, for example, 0-3000 ms, 3000-5000 ms, and 5000-8000 ms.|

## ParticlePropertyOptions
```typescript
interface ParticlePropertyOptions<TYPE, UPDATER extends ParticleUpdater> {
  range: [TYPE, TYPE];
  updater?: {
    type: UPDATER;
    config: ParticlePropertyUpdaterConfigs<TYPE>[UPDATER];
  };
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| range | [number, number] | Yes| Initial attribute value range of the particle. The initial attribute value of particles generated by the particle emitter is randomly selected in this range.<br>**NOTE**<br>The default values of different attributes are different:<br>1. Default value of the **opacity** attribute: **range: [1.0,1.0]**<br>2. Default value of the **scale** attribute: **range:[1.01.0]**<br>3. Default value of the acceleration **speed** attribute: **range: [0.0,0.0]**<br>4. Default value of the acceleration **angle** attribute: **range:[0.0,0.0]**<br>5. Default value of the **spin** attribute: **range: [0.0,0.0]**|
| updater | {type: [UPDATER](#particleupdater);config: [ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[UPDATER];} | No| How the attribute is updated. The available options of **type** are as follows:<br>1. **ParticleUpdater.NONE**: The attribute does not change. In this case, the **config** type is [ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.NONE].<br>2. **ParticleUpdater.RANDOM**: The attribute changes randomly. In this case, the **config** type is [ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.RANDOM].<br>3. **ParticleUpdater.CURVE**: The attribute changes with the animation curve. In this case, the **config** type is [ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.CURVE].|


## ParticlePropertyUpdaterConfigs
```typescript
interface ParticlePropertyUpdaterConfigs<T> {
    [ParticleUpdater.NONE]: void;
    [ParticleUpdater.RANDOM]: [T, T];
    [ParticleUpdater.CURVE]: Array<ParticlePropertyAnimation<T>>;
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| [[ParticleUpdater.NONE]|void | Yes| The attribute does not change. The default value is **undefined**.|
| [ParticleUpdater.RANDOM] | [number, number] | Yes| The attribute changes randomly, with the change difference being a value randomly generated from the range.<br>The target attribute value is obtained by applying the change difference to the current attribute value. For example, if the current attribute value is **0.2** and **config** is set to **[0.1,1.0]**, then:<br>1. When the random change difference is 0.5, the target attribute value is 0.2 + 0.5 = 0.7.<br>2. The change difference may also be a negative value. For example, if the current attribute value is **0.2** and **config** is set to **[-3.0,2.0]**, then when the random change difference is **-2.0**, the target attribute value is 0.2 - 2.0 = -1.8.<br>**NOTE**<br>**config** sets the value range of the change difference. While the change difference does not have a maximum or minimum value limit, the target attribute value does. Therefore, if the target attribute value is greater than the maximum attribute value, the maximum attribute value will be used instead; if the target attribute value is less than the minimum attribute value, the minimum attribute value will be used instead.<br>For example, if the value range of **opacity** is **[0.0,1.0]**, then if the target attribute value is greater than 1.0, **1.0** will be used instead.|
| [ParticleUpdater.CURVE]|Array<[ParticlePropertyAnimation](#particlepropertyanimation)\<number\>> | Yes| The attribute changes with the animation curve. The array type indicates that multiple animation segments can be set for the current attribute, for example, 0-3000 ms, 3000-5000 ms, and 5000-8000 ms.|



## ParticlePropertyAnimation
```typescript
interface ParticlePropertyAnimation<T> {
  from: T;
  to: T;
  startMillis: number;
  endMillis: number;
  curve?: Curve | ICurve;
}
```
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|from| T | Yes| Initial value of the attribute.|
| to | T | Yes| Target value of the attribute.|
|startMillis|number | Yes| Start time of the animation.|
|endMillis|number | Yes| End time of the animation.|
|curve|[Curve](ts-appendix-enums.md#curve) \| [ICurve](../apis/js-apis-curve.md#icurve)| No| Animation curve.<br>Default value: **Curve.Linear**|


## ParticleType
```typescript
enum ParticleType {
  POINT = 'point',
  IMAGE = 'image',
}
```
| Name | Description|
| -------- |  -------- | 
|POINT |Poin particle.|
|IMAGE | Image particle.|



## ParticleEmitterShape
```typescript
enum ParticleEmitterShape {
  RECTANGLE = 'rectangle',
  CIRCLE = 'circle',
  ELLIPSE = 'ellipse',
}
```
| Name | Description|
| -------- |  -------- | 
|RECTANGLE |The particle emitter is rectangular.|
|CIRCLE | The particle emitter is circular.|
|ELLIPSE |The particle emitter is elliptical.|


## ParticleUpdater
```typescript
enum ParticleUpdater {
  NONE = 'none',
  RANDOM = 'random',
  CURVE = 'curve',
}
```
| Name | Description|
| -------- |  -------- | 
|NONE |No change.|
|RANDOM | Random change.|
|CURVE |Change with the animation curve.|

## Example

### Example 1
```ts
// xxx.ets
// xxx.ets
@Entry
@Component
struct ParticleExample {
  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor(Color.Black)
      Particle({particles:[
        {
          emitter:{
            particle:{
              type:ParticleType.POINT,// Particle type.
              config:{
                radius:10// Point radius.
              },
              count: 500,// Total number of particles.
              lifetime:10000// Particle lifetime, in ms.
            },
            emitRate:10,// Number of particles emitted per second.
            position:[0,0],
            shape:ParticleEmitterShape.RECTANGLE// Emitter shape.
          },
          color:{
            range:[Color.Red,Color.Yellow],// Initial color range.
            updater:{
              type:ParticleUpdater.CURVE,// Change with the animation curve.
              config:[
                {
                  from:Color.White,// Initial value of the change.
                  to:Color.Pink,// Target value of the change.
                  startMillis:0,// Start time.
                  endMillis:3000,// End time.
                  curve:Curve.EaseIn// Animation curve.
                },
                {
                  from:Color.Pink,
                  to:Color.Orange,
                  startMillis:3000,
                  endMillis:5000,
                  curve:Curve.EaseIn
                },
                {
                  from:Color.Orange,
                  to:Color.Pink,
                  startMillis:5000,
                  endMillis:8000,
                  curve:Curve.EaseIn
                },
              ]
            }
          },
          opacity:{
            range: [0.0,0.0],// The initial value of particle opacity is randomly generated from 0.0 to 1.0.
            updater:{
              type:ParticleUpdater.CURVE,// Opacity changes randomly.
              config:[
                {
                  from:0.0,
                  to:1.0,
                  startMillis:0,
                  endMillis:3000,
                  curve:Curve.EaseIn
                },
                {
                  from:1.0,
                  to:0.0,
                  startMillis:5000,
                  endMillis:10000,
                  curve:Curve.EaseIn
                }
              ]
            }
          },
          scale:{
            range:[0.0,0.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from:0.0,
                  to:0.5,
                  startMillis:0,
                  endMillis:3000,
                  curve: Curve.EaseIn
                }
              ]
            }
          },
          acceleration:{// Acceleration. speed indicates the acceleration speed, and angle indicates the acceleration direction.
            speed:{
              range:[3,9],
              updater:{
                type:ParticleUpdater.RANDOM,
                config:[1,20]
              }
            },
            angle:{
              range:[90,90]
            }
          }

        }
      ]
      }).width(300).height(300)
    }.width("100%").height("100%").align(Alignment.Center)
  }
}
```

![particle](figures/particle.gif)

### Example 2
```ts
@Entry
@Component
struct ParticleExample {
  @State
  myCount : number = 100
  flag : boolean = false;
  build() {
    Column(){
      Stack() {
        Particle({particles:[
          {
            emitter:{
              particle:{
                type:ParticleType.IMAGE,
                config:{
                  src:$r("app.media.glass"),
                  size:[10,10]
                },
                count: this.myCount,
                lifetime:10000
              },
              emitRate:3,
              shape:ParticleEmitterShape.CIRCLE
            },
            color:{
              range:[Color.White,Color.White]
            },
            opacity:{
              range:[1.0,1.0],
              updater:{
                type:ParticleUpdater.CURVE,
                config:[
                  {
                    from:0,
                    to:1.0,
                    startMillis:0,
                    endMillis:6000
                  },
                  {
                    from:1.0,
                    to:.0,
                    startMillis:6000,
                    endMillis:10000
                  }
                ]
              }
            },
            scale:{
              range:[0.1,1.0],
              updater:{
                type:ParticleUpdater.CURVE,
                config:[
                  {
                    from: 0,
                    to: 1.5,
                    startMillis: 0,
                    endMillis: 8000,
                    curve: Curve.EaseIn
                  }

                ]
              }
            },
            acceleration:{
              speed:{
                range:[3,9],
                updater:{
                  type: ParticleUpdater.CURVE,
                  config:[
                    {
                      from:10,
                      to:20,
                      startMillis:0,
                      endMillis:3000,
                      curve:Curve.EaseIn
                    },
                    {
                      from:10,
                      to:2,
                      startMillis:3000,
                      endMillis:8000,
                      curve:Curve.EaseIn
                    }
                  ]
                }
              },
              angle:{
                range:[0,180],
                updater:{
                  type:ParticleUpdater.CURVE,
                  config:[{
                    from:1,
                    to:2,
                    startMillis:0,
                    endMillis:1000,
                    curve:Curve.EaseIn
                  },
                    {
                      from:50,
                      to:-50,
                      startMillis:1000,
                      endMillis:3000,
                      curve:Curve.EaseIn
                    },
                    {
                      from:3,
                      to:5,
                      startMillis:3000,
                      endMillis:8000,
                      curve:Curve.EaseIn
                    }
                  ]
                }
              }
            },
            spin:{
              range:[0.1,1.0],
              updater:{
                type:ParticleUpdater.CURVE,
                config:[
                {
                  from: 0,
                  to: 360,
                  startMillis: 0,
                  endMillis: 8000,
                  curve: Curve.EaseIn
                }
                ]
              }
            },
          }
          ,{
          emitter:{
            particle:{
              type:ParticleType.IMAGE,
              config:{
                src:$r('app.media.book'),
                size:[10,10]
              },
              count: this.myCount,
              lifetime:10000
            },
            emitRate:3,
            shape:ParticleEmitterShape.CIRCLE
          },
          color:{
            range:[Color.White,Color.White]
          },
          opacity:{
            range:[1.0,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from:0,
                  to:1.0,
                  startMillis:0,
                  endMillis:6000
                },
                {
                  from:1.0,
                  to:.0,
                  startMillis:6000,
                  endMillis:10000
                }
              ]
            }
          },
          scale:{
            range:[0.1,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from: 0,
                  to: 2.0,
                  startMillis: 0,
                  endMillis: 10000,
                  curve: Curve.EaseIn
                }

              ]
            }
          },
          acceleration:{
            speed:{
              range:[3,9],
              updater:{
                type: ParticleUpdater.CURVE,
                config:[
                  {
                    from:10,
                    to:20,
                    startMillis:0,
                    endMillis:3000,
                    curve:Curve.EaseIn
                  },
                  {
                    from:10,
                    to:2,
                    startMillis:3000,
                    endMillis:8000,
                    curve:Curve.EaseIn
                  }
                ]
              }
            },
            angle:{
              range:[0,180],
              updater:{
                type:ParticleUpdater.CURVE,
                config:[{
                  from:1,
                  to:2,
                  startMillis:0,
                  endMillis:1000,
                  curve:Curve.EaseIn
                },
                  {
                    from:50,
                    to:-50,
                    startMillis:0,
                    endMillis:3000,
                    curve:Curve.EaseIn
                  },
                  {
                    from:3,
                    to:5,
                    startMillis:3000,
                    endMillis:10000,
                    curve:Curve.EaseIn
                  }
                ]
              }
            }
          },
          spin:{
            range:[0.1,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from: 0,
                  to: 360,
                  startMillis: 0,
                  endMillis: 10000,
                  curve: Curve.EaseIn
                }
              ]
            }
          },
        },{
          emitter:{
            particle:{
              type:ParticleType.IMAGE,
              config:{
                src:$r('app.media.squares'),
                size:[10,10]
              },
              count: this.myCount,
              lifetime:10000
            },
            emitRate:3,
            shape:ParticleEmitterShape.CIRCLE
          },
          color:{
            range:[Color.White,Color.White]
          },
          opacity:{
            range:[1.0,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from:0,
                  to:1.0,
                  startMillis:0,
                  endMillis:6000
                },
                {
                  from:1.0,
                  to:.0,
                  startMillis:6000,
                  endMillis:10000
                }
              ]
            }
          },
          scale:{
            range:[0.1,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from: 0,
                  to: 2.0,
                  startMillis: 0,
                  endMillis: 10000,
                  curve: Curve.EaseIn
                }

              ]
            }
          },
          acceleration:{
            speed:{
              range:[3,9],
              updater:{
                type: ParticleUpdater.CURVE,
                config:[
                  {
                    from:10,
                    to:20,
                    startMillis:0,
                    endMillis:3000,
                    curve:Curve.EaseIn
                  },
                  {
                    from:10,
                    to:2,
                    startMillis:3000,
                    endMillis:8000,
                    curve:Curve.EaseIn
                  }
                ]
              }
            },
            angle:{
              range:[0,180],
              updater:{
                type:ParticleUpdater.CURVE,
                config:[{
                  from:1,
                  to:2,
                  startMillis:0,
                  endMillis:1000,
                  curve:Curve.EaseIn
                },
                  {
                    from:50,
                    to:-50,
                    startMillis:1000,
                    endMillis:3000,
                    curve:Curve.EaseIn
                  },
                  {
                    from:3,
                    to:5,
                    startMillis:3000,
                    endMillis:8000,
                    curve:Curve.EaseIn
                  }
                ]
              }
            }
          },
          spin:{
            range:[0.1,1.0],
            updater:{
              type:ParticleUpdater.CURVE,
              config:[
                {
                  from: 0,
                  to: 360,
                  startMillis: 0,
                  endMillis: 10000,
                  curve: Curve.EaseIn
                }
              ]
            }
          },
        }
        ]
        }).width(300).height(300)

      }.width(500).height(500).align(Alignment.Center)
    }.width("100%").height("100%")

  }
}
```
![particle](figures/particle_image.gif)
