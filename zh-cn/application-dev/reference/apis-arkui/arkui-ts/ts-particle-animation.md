# 粒子动画 (Particle)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

粒子动画是在一定范围内随机生成的大量粒子产生运动而组成的动画。动画元素是一个个粒子，这些粒子可以是圆点、图片。通过对粒子在颜色、透明度、大小、速度、加速度、自旋角度等维度变化做动画，来营造一种氛围感，比如下雪的动效，雪花飘舞就相当于一个个雪花粒子在做动画。

粒子动画的效果通过Particle组件展现。


>  **说明：**
>
> - 该组件从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - Particle在熄屏之后再次打开或者切换后台再次唤起，粒子动画会自动暂停。


## 子组件

无


## 接口

```typescript
interface ParticleInterface {
  <
    PARTICLE extends ParticleType,
    COLOR_UPDATER extends ParticleUpdater,
    OPACITY_UPDATER extends ParticleUpdater,
    SCALE_UPDATER extends ParticleUpdater,
    ACC_SPEED_UPDATER extends ParticleUpdater,
    ACC_ANGLE_UPDATER extends ParticleUpdater,
    SPIN_UPDATER extends ParticleUpdater
  >(particles: Particles<
      PARTICLE,
      COLOR_UPDATER,
      OPACITY_UPDATER,
      SCALE_UPDATER,
      ACC_SPEED_UPDATER,
      ACC_ANGLE_UPDATER,
      SPIN_UPDATER
    >): ParticleAttribute;
}
```

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| particles | [Particles](#particles18)<<br>&nbsp;&nbsp;[PARTICLE](#particletype), <br>&nbsp;&nbsp;COLOR_UPDATER,<br>&nbsp;&nbsp;OPACITY_UPDATER,<br>&nbsp;&nbsp;SCALE_UPDATER,<br>&nbsp;&nbsp;ACC_SPEED_UPDATER,<br>&nbsp;&nbsp;ACC_ANGLE_UPDATER,<br>&nbsp;&nbsp;SPIN_UPDATER<br>><br> | 否 | 否 | 粒子动画的集合，详见[Particles](#particles18)属性说明。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外还支持以下属性：

### disturbanceFields<sup>12+</sup>

disturbanceFields(fields: Array&lt;DisturbanceFieldOptions&gt;)

设置扰动场。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------ | ------- | ---- | ---------------------------- |
| fields  | Array<[DisturbanceFieldOptions](#disturbancefieldoptions12)> | 是   | 扰动场数组。用于设置粒子运动轨迹的干扰效果，通过配置多个扰动场可对粒子施加排斥力或吸引力，改变粒子的运动轨迹。 |

### emitter<sup>12+</sup>
emitter(value: Array&lt;EmitterProperty&gt;)

支持发射器属性动态更新。通过EmitterProperty中的index指定需要更新的发射器（按初始化参数中发射器的数组索引），可动态更新发射器的发射速率、位置、大小和环形区域参数。必须先通过Particle接口创建粒子动画并配置发射器，再通过emitter()属性动态更新对应发射器的参数，emitter()属性仅更新已有发射器的参数，不能新增发射器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------ | ------- | ---- | ---------------------------- |
| value  | Array<[EmitterProperty](#emitterproperty12)> | 是   | 需要更新的发射器参数数组。 |

### rippleFields<sup>22+</sup>
rippleFields(fields: Array&lt;RippleFieldOptions&gt;\|undefined)

设置粒子波动场。波动场会对影响范围内的粒子施加按波形变化的力，产生类似波纹扩散的效果。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------ | ------- | ---- | ---------------------------- |
| fields  | Array<[RippleFieldOptions](#ripplefieldoptions22)>\|undefined | 是   | 粒子波动场数组。通过数组形式可以设置多个粒子波动场。当设置为undefined时，表示无波动场。 |

### velocityFields<sup>22+</sup>
velocityFields(fields: Array&lt;VelocityFieldOptions&gt;\|undefined)

设置粒子速度场。速度场会对影响范围内的粒子施加一个力，使粒子在原有速度的基础上叠加速度场指定的速度。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------ | ------- | ---- | ---------------------------- |
| fields  | Array<[VelocityFieldOptions](#velocityfieldoptions22)>\|undefined | 是   | 粒子速度场数组。通过数组形式可设置多个粒子速度场。设置为undefined时表示无速度场。 |

## 事件
支持[通用事件](ts-component-general-events.md)。

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
  velocity?: VelocityOptions;
  acceleration?: AccelerationOptions<ACC_SPEED_UPDATER, ACC_ANGLE_UPDATER>;
  spin?: ParticlePropertyOptions<number, SPIN_UPDATER>;
}
```

设置粒子参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| emitter | [EmitterOptions](#emitteroptions)<[PARTICLE](#particletype)> | 否 | 否 | 粒子发射器配置。 |
| color | [ParticleColorPropertyOptions](#particlecolorpropertyoptions)<COLOR_UPDATER> | 否 | 是 | 粒子颜色配置。<br>**说明**：<br>默认值：{ range:[Color.White,Color.White] }。图片粒子不支持设置颜色。|
| opacity | [ParticlePropertyOptions](#particlepropertyoptions)\<number, OPACITY_UPDATER> | 否 | 是 | 粒子透明度配置。<br>默认值：{ range:[1.0,1.0] } |
| scale | [ParticlePropertyOptions](#particlepropertyoptions)\<number, SCALE_UPDATER> | 否 | 是 | 粒子大小配置。<br>默认值：{ range:[1.0,1.0] } |
| velocity | [VelocityOptions](#velocityoptions18) |否 | 是 | 粒子速度配置。<br>**说明**：<br>speed表示速度大小。angle表示速度的方向（单位：度），以元素几何中心为坐标原点，水平方向为X轴，正数表示顺时针方向旋转角度。<br>默认值：{ speed:[0.0,0.0],angle:[0.0,0.0] } |
| acceleration | [AccelerationOptions](#accelerationoptions18)\<ACC_SPEED_UPDATER, ACC_ANGLE_UPDATER> | 否 | 是 | 粒子加速度配置。 <br>**说明**：<br>speed表示加速度大小，angle表示加速度方向（单位：度）。<br>默认值：{ speed:{range:[0.0,0.0]},angle:{range:[0.0,0.0]} } |
| spin | [ParticlePropertyOptions](#particlepropertyoptions)\<number, SPIN_UPDATER> | 否 | 是 | 粒子自旋角度配置，单位为度（°）。 <br>默认值：{range:[0.0,0.0]}<br>方向：正数表示顺时针旋转，负数表示逆时针旋转。 |


## EmitterOptions

```typescript
interface EmitterOptions<PARTICLE extends ParticleType> {   
  particle: EmitterParticleOptions<PARTICLE>;
  emitRate?: number;
  shape?: ParticleEmitterShape;
  position?: ParticleTuple<Dimension, Dimension>;
  size?: ParticleTuple<Dimension, Dimension>;
  annulusRegion?: ParticleAnnulusRegion;
}
```

粒子发射器的配置。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| particle | [EmitterParticleOptions](#emitterparticleoptions18)<[PARTICLE](#particletype)> | 否 | 否 | 粒子配置。<br>-type表示粒子类型，可以选择图片或点。<br>-config表示对应类型的配置。<br>-config类型和type值有关联：<br>1. 如果type为ParticleType.POINT，则config类型为[PointParticleParameters](#pointparticleparameters) 。<br>2. 如果type为ParticleType.IMAGE，则config类型为[ImageParticleParameters](#imageparticleparameters) 。<br>-count表示发射的粒子总数，count取值>=-1，当count为-1表示粒子总数无限大。<br>-lifetime表示单个粒子的生命周期，默认值1000（即1000ms，1s），lifetime>=-1，当lifetime为-1表示粒子生命周期无限大。当lifetime<-1，取默认值。<br>**说明**：如果不需要动画一直播放，建议不要将生命周期设置为-1，可能对性能造成较大影响。<br>lifetimeRange表示粒子生命周期取值范围，设置lifetimeRange后粒子的生命周期为[lifetime-lifetimeRange, lifetime+lifetimeRange]中间的一个随机整数。lifetimeRange默认值为0，取值范围为[0, +∞）。设置为负值时取默认值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| emitRate | number | 否 | 是 | 发射器发射速率（即每秒发射粒子数）。 默认值：5，小于0时取默认值5。emitRate值超过5000时会严重影响性能，可能导致帧率大幅下降，建议设置参数小于5000。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| shape | [ParticleEmitterShape](#particleemittershape) | 否 | 是 | 发射器形状。<br>默认值：ParticleEmitterShape.RECTANGLE<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| position | [ParticleTuple](#particletuple18)<[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)> | 否 | 是 | 发射器位置（距离组件左上角的位置。第一个参数为x方向上的相对偏移，第二个参数为y轴方向相对偏移。）。当发射器形状为环形（即shape为ParticleEmitterShape.ANNULUS）时，此属性不生效，需通过annulusRegion参数指定形状信息。 <br>默认值：`[0.0, 0.0]`<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| size |  [ParticleTuple](#particletuple18)<[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)>     |否 | 是 | 发射器的大小。第一个参数为发射器宽，第二个参数为发射器高。当发射器形状为环形（即shape为ParticleEmitterShape.ANNULUS）时，此属性不生效，需通过annulusRegion参数指定形状信息。<br>默认值：`['100%','100%']`(即发射窗口占满Particle组件)<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| annulusRegion<sup>20+</sup>  | [ParticleAnnulusRegion](ts-particle-animation.md#particleannulusregion20)| 否 | 是  |环形发射器参数。需要发射器形状为环形（即shape参数为ParticleEmitterShape.ANNULUS）时才生效，且对于环形发射器，形状信息必须通过annulusRegion参数指定，position和size不生效。未设置时，发射器不使用环形区域参数。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## ParticleConfigs

设置粒子配置项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明 |
| -------- | -------- | ------ | -------- | -------- |
| [ParticleType.POINT]      | [PointParticleParameters](#pointparticleparameters) | 否 | 否    | 点状粒子配置。 |
| [ParticleType.IMAGE]      | [ImageParticleParameters](#imageparticleparameters) | 否 | 否    | 图片粒子配置。 |

## PointParticleParameters

设置粒子半径。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明 |
| -------- | ------- | ------- | -------- | -------- |
| radius      | [VP](ts-types.md#vp10)| 否 | 否    | 粒子半径。<br>默认值：0，小于0时取默认值0。<br>取值范围：[0, +∞) |

## ImageParticleParameters

设置图片选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明 |
| -------- | ------- | ------- | -------- | -------- |
| src      | [ResourceStr](ts-types.md#resourcestr) | 否 | 否    | 图片路径，支持本地图片和网络图片，引用方式请参考[加载图片资源](../../../ui/arkts-graphics-display.md#加载图片资源)。<br>暂不支持svg图片类型。<br>src未发生变化时，会优先使用缓存的资源，无法动态切换资源。如需动态切换资源建议切换为不同的src。 |
| size     | [ParticleTuple](#particletuple18)<[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)> | 否 | 否    | 图像尺寸，第一个参数为图像宽度，第二个参数为图像高度。<br>默认值：[0, 0] |
| objectFit| [ImageFit](ts-appendix-enums.md#imagefit)| 否 | 是   | 图片显示模式。<br>默认值：ImageFit.Cover |

## ParticleColorPropertyOptions

```typescript
interface ParticleColorPropertyOptions<UPDATER extends ParticleUpdater> {
  range: ParticleTuple<ResourceColor, ResourceColor>; 
  distributionType?: DistributionType;
  updater?: ParticleColorUpdaterOptions<UPDATER>;
}
```

设置粒子颜色属性更新器配置。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| range | [ParticleTuple](#particletuple18)<[ResourceColor](ts-types.md#resourcecolor), [ResourceColor](ts-types.md#resourcecolor)> | 否 | 否 | 粒子初始颜色区间，粒子发射器生成粒子的初始颜色在range区间随机取值。<br>默认值：range:[Color.White,Color.White] <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| distributionType<sup>12+</sup> | [DistributionType](#distributiontype12) | 否 | 是 | 粒子初始颜色随机值分布，允许用户选择颜色随机值生成的分布类型，支持均匀分布或正态（高斯）分布。<br>默认值：DistributionType.UNIFORM<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| updater | [ParticleColorUpdaterOptions](#particlecolorupdateroptions18)\<UPDATER> | 否 | 是 | 颜色属性变化配置。颜色属性变化类型type有三类：<br>1、当type为ParticleUpdater.NONE，表示无变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.NONE]。 <br>2、type为ParticleUpdater.RANDOM，表示随机均匀变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.RANDOM]。 <br>3、type为ParticleUpdater.CURVE,表示按动画曲线变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.CURVE]。<br>默认值：type默认为 ParticleUpdater.NONE。 <br>**说明**：<br>当type为ParticleUpdater.RANDOM或者ParticleUpdater.CURVE时，updater中颜色配置的优先级高于range中的颜色配置。在updater配置的动画时间周期内，以updater中的颜色配置来变化；在updater配置的动画时间周期外，以range中的颜色配置来变化。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |


## ParticleColorPropertyUpdaterConfigs

设置粒子颜色属性更新器的配置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
|[ParticleUpdater.NONE]|void | 否 | 否 | 无变化。|
| [ParticleUpdater.RANDOM] | [ParticleColorOptions](#particlecoloroptions18) | 否 | 否 | 表示变化方式为随机变化的时候，对每个粒子在变化区间内随机生成一个差值。r、g、b、a四个颜色通道每秒分别使用差值叠加当前颜色值，生成目标颜色值。实现颜色随机变化的效果。 |
| [ParticleUpdater.CURVE]|Array<[ParticlePropertyAnimation](#particlepropertyanimation)\<[ResourceColor](ts-types.md#resourcecolor)\>> | 否 | 否 | 表示变化方式为曲线变化时，颜色变化的配置。数组类型表示当前属性可以设置多段动画，如0ms-3000ms，3000ms-5000ms，5000ms-8000ms分别设置动画。|

## ParticlePropertyOptions
```typescript
interface ParticlePropertyOptions<TYPE, UPDATER extends ParticleUpdater> {
  range: ParticleTuple<TYPE, TYPE>;
  updater?: ParticleUpdaterOptions<TYPE, UPDATER>;
}
```

设置粒子属性选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

<!--Table: 10%; auto; 10%; auto-->
| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| range | [ParticleTuple](#particletuple18)<TYPE, TYPE> | 否 | 否 | 粒子初始属性值区间，粒子发射器生成粒子的属性值在range区间随机取值。<br>**说明**<br>各项属性的非法输入取默认值，当最大值小于最小值的时候取默认区间。TYPE为number。<br>不同属性的默认值不同：<br>1、opacity属性：range:[1.0,1.0]，取值范围为[0, 1]，默认值为1.0。<br>2、scale属性：range:[1.0,1.0]，取值范围为[0, 10000]，默认值为1.0。<br>3、acceleration加速度speed属性：range:[0.0,0.0]，取值范围为[0, 10000]，默认值为0.0。<br>4、acceleration加速度angle属性：range:[0.0,0.0]，取值范围为[-10000, 10000]，默认值为0.0。<br>5、spin属性：range:[0.0,0.0]，取值范围为[-10000, 10000]，默认值为0.0。|
| updater | [ParticleUpdaterOptions](#particleupdateroptions18)<TYPE, UPDATER> | 否 | 是 | 属性变化配置。属性变化类型type有三类：<br>1、当type为ParticleUpdater.NONE，表示无变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.NONE]。<br>2、当type为ParticleUpdater.RANDOM，表示变化类型为随机变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.RANDOM]。<br>3、当type为ParticleUpdater.CURVE，表示变化类型为曲线变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.CURVE] <br>默认值：type默认为ParticleUpdater.NONE。 |


## ParticlePropertyUpdaterConfigs
```typescript
interface ParticlePropertyUpdaterConfigs<T> {
    [ParticleUpdater.NONE]: void;
    [ParticleUpdater.RANDOM]: ParticleTuple<T, T>;
    [ParticleUpdater.CURVE]: Array<ParticlePropertyAnimation<T>>;
}
```

设置粒子属性更新器配置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | -------- |
| [ParticleUpdater.NONE]|void | 否 | 否 | 无变化。|
| [ParticleUpdater.RANDOM] | [ParticleTuple](#particletuple18)<T, T> | 否 | 否 | 表示变化方式为随机变化时，每秒的变化差值为设置区间随机生成的值。<br>目标属性值为当前属性值叠加变化差值。如当前属性值为0.2，config取[0.1,1.0]:<br>1、如果变化差值在区间[0.1,1.0]取随机值0.5，则目标属性值为0.2+0.5 = 0.7；<br>2、变化差值也可以取负值。如当前属性值为0.2，config为 [-3.0,2.0],如果变化差值在区间[-3.0,2.0]取随机值-2.0，则目标属性值为0.2-2.0 = -1.8。<br>**说明：**<br>config配置的是变化差值的取值范围，差值的最大最小值没有约束。但是如果当前属性值叠加差值大于属性最大值，目标属性值取属性最大值；如果当前属性值叠加差值小于属性最小值，目标属性值取属性最小值。T为number。<br>例如：opacity的取值范围[0.0,1.0]则当当前属性值叠加差值超过1.0，则取1.0。|
|[ParticleUpdater.CURVE]|Array<[ParticlePropertyAnimation](#particlepropertyanimation)\<T\>> | 否 | 否 | 表示变化方式为曲线变化时，属性变化的配置。数组类型表示当前属性可以设置多段动画，如0ms-3000ms，3000ms-5000ms，5000ms-8000ms分别设置动画。T为number。|

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

设置粒子属性生命周期。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | ---- | ---- | -------- | -------- |
|from| T | 否 | 否 | 属性起始值。非法输入取对应属性的默认值。|
| to | T | 否 | 否 | 属性目标值。非法输入取对应属性的默认值。|
|startMillis|number | 否 | 否 | 动画开始时间。<br>单位：毫秒。<br>取值范围：[0, +∞)。传入负值时取默认值0。|
|endMillis|number | 否 | 否 | 动画结束时间。<br>单位：毫秒。<br>取值范围：[0, +∞)。传入负值时取默认值0。|
|curve|[Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;[ICurve](../js-apis-curve.md#icurve9)| 否 | 是 | 设置动画曲线。<br>默认值：Curve.Linear|


## ParticleType

粒子类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  |  值  | 说明 |
| -------- | -------- | -------- | 
| POINT | 'point' | 点状粒子 |
| IMAGE | 'image' | 图片粒子。<br>图片粒子不支持设置颜色。|



## ParticleEmitterShape

粒子发射器形状。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  |  值  | 说明 |
| -------- | -------- | -------- | 
| RECTANGLE | 'rectangle' | 粒子发射器为矩形。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| CIRCLE | 'circle' | 粒子发射器为圆形。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| ELLIPSE | 'ellipse' | 粒子发射器为椭圆形。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| ANNULUS<sup>20+</sup> | 'annulus' | 粒子发射器为环形。使用此形状时必须配置annulusRegion参数，且position和size参数不生效。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## DistributionType<sup>12+</sup>

初始颜色随机值分布类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  |  值  | 说明 |
| -------- | -------- | -------- | 
| UNIFORM | 0 | 初始颜色随机值分布为均匀分布。|
| GAUSSIAN | 1 | 初始颜色随机值分布为高斯分布。|

## ParticleUpdater

粒子变化类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  |  值  | 说明 |
| -------- | -------- | -------- | 
|NONE | 'none' | 无变化。|
|RANDOM | 'random' | 随机均匀变化。|
|CURVE | 'curve' | 动画曲线变化。|

## DisturbanceFieldOptions<sup>12+</sup>

设置粒子扰动场参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型    | 只读 | 可选 | 说明                         |
| ------ | ------- | ---- | ------- | --------------------- |
| strength  | number | 否 | 是   |场强，表示场从中心向外的排斥力的强度，默认值0。正数表示排斥力方向朝外，负数表示吸引力，方向朝内。<br>取值范围：(-∞, +∞)。 |
| shape  |   [DisturbanceFieldShape](#disturbancefieldshape12) | 否 | 是   | 场的形状。<br>默认为DisturbanceFieldShape.RECT。 |
| size  | [SizeT](#sizett12)&lt;number&gt;| 否 | 是  |场的大小，单位：vp。<br>默认值 {width:0, height:0}。<br>width和height的取值范围：[0, +∞)。|
| position  | [PositionT](#positiontt12)&lt;number&gt; | 否 | 是   |场的位置，单位：vp。<br>默认值{x:0, y:0}。<br>x、y的取值范围：(-∞, +∞)。 |
| feather  | number | 否 | 是   |羽化值，表示场从中心点到场边缘的衰减程度，取值范围为0到100的整数。取值为0时表示场是一个刚体，所有范围内的粒子都被排斥在外。羽化值越大场的缓和程度越大，场范围内出现越多靠近中心点的粒子。设置为负值或大于100时取默认值，设置为非整数时截断取整。<br>默认值为0。 |
| noiseScale  | number | 否 | 是   |噪声尺度，用于控制噪声图案的整体大小，取值大于等于0。<br>默认值1。传入负值时取默认值1。 |
| noiseFrequency  | number | 否 | 是   |噪声频率，频率越大噪声越细腻，取值大于等于0。<br> 默认值1。传入负值时取默认值1。 |
| noiseAmplitude  | number | 否 | 是   |噪声振幅，表示噪声值的波动范围，振幅越大波动范围越大。取值大于等于0。<br> 默认值1。传入负值时取默认值1。 |

## DisturbanceFieldShape<sup>12+</sup>

扰动场形状。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值    | 说明   |
| --------| ---- | ------|
| RECT    | 0 | 矩形。   |
| CIRCLE  | 1 | 圆。       |
| ELLIPSE | 2 | 椭圆。     |

## EmitterProperty<sup>12+</sup>

设置发射器属性。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型    | 只读 | 可选 | 说明                         |
| ------ | ------- | ---- | ------- | --------------------- |
| index   | number | 否 | 否   |索引，取整，按初始化参数中发射器的数组索引指定对应的发射器。异常默认值为0。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| emitRate  | number  | 否 | 是   | 发射器发射速率，即每秒发射粒子的数量。<br>未传入时保持其当前的发射速率， 传入值小于0时取默认值5。emitRate值超过5000时会严重影响性能，可能导致帧率大幅下降，建议设置参数小于5000。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| position  | [PositionT](#positiontt12)&lt;number&gt; | 否 | 是  |发射器位置，只支持number类型。<br>未传入时保持其当前的发射器位置。需传入两个有效参数，若其中一个为异常值，则position不生效。当对应index的发射器形状为环形（ANNULUS）时，position不生效。<br>x、y的取值范围：(-∞, +∞)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| size  | [SizeT](#sizett12)&lt;number&gt;| 否 | 是  |发射器的大小，只支持number类型。<br>未传入时保持其当前发射器大小。需传入两个有效参数且都大于0，若其中一个为异常值，则size不生效。当对应index的发射器形状为环形（ANNULUS）时，size不生效。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| annulusRegion<sup>20+</sup>  | [ParticleAnnulusRegion](ts-particle-animation.md#particleannulusregion20)| 否 | 是 |环形发射器参数。需要对应index的发射器形状为环形才生效，且对于环形发射器，position和size不生效。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## ParticleTuple<sup>18+</sup>

```typescript
type ParticleTuple<T1, T2> = [T1, T2]
```

粒子元组，表示定义动画参数配置值对的类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型         | 说明                                           |
| ----------- | ---------------------------------------------- |
| [T1, T2]    | 动画参数配置值对的类型，T1和T2支持多种具体类型（如number、ResourceColor、Dimension等）。              |

## Particles<sup>18+</sup>

```typescript
interface Particles<
  PARTICLE extends ParticleType,
  COLOR_UPDATER extends ParticleUpdater,
  OPACITY_UPDATER extends ParticleUpdater,
  SCALE_UPDATER extends ParticleUpdater,
  ACC_SPEED_UPDATER extends ParticleUpdater,
  ACC_ANGLE_UPDATER extends ParticleUpdater,
  SPIN_UPDATER extends ParticleUpdater
> {
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
  >;
}
```

粒子动画的集合。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                           | 只读 | 可选 | 说明                                                                                                                     |
| ------ | ------------------------------ | ---- | ------------------------------------------ | ----------------------------------------------------------------------------- |
| particles<sup>10+</sup>  | Array<<br>&nbsp;&nbsp;ParticleOptions<<br>&nbsp;&nbsp;&nbsp;&nbsp;PARTICLE,<br>&nbsp;&nbsp;&nbsp;&nbsp;COLOR_UPDATER,<br>&nbsp;&nbsp;&nbsp;&nbsp;OPACITY_UPDATER,<br>&nbsp;&nbsp;&nbsp;&nbsp;SCALE_UPDATER,<br>&nbsp;&nbsp;&nbsp;&nbsp;ACC_SPEED_UPDATER,<br>&nbsp;&nbsp;&nbsp;&nbsp;ACC_ANGLE_UPDATER,<br>&nbsp;&nbsp;&nbsp;&nbsp;SPIN_UPDATER<br>&nbsp;&nbsp;><br>>  | 否 | 否   | 粒子动画的集合。每个粒子动画（[ParticleOptions](#particleoptions)）包含粒子发射，同时可配置粒子的颜色、透明度、大小、速度、加速度与自旋角度，详见[ParticleOptions](#particleoptions)属性说明。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|

## VelocityOptions<sup>18+</sup>

粒子速度配置。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                           | 只读 | 可选 | 说明                                                                                                                     |
| ------ | ------------------------------ | ---- | ------------------------- | ---------------------------------------------------------------------------------------------- |
| speed<sup>10+</sup>  | [ParticleTuple](#particletuple18)\<number, number>  | 否 | 否   | 表示速度大小。<br>默认值：{range:[0.0,0.0]}    <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                          |
| angle<sup>10+</sup>  | [ParticleTuple](#particletuple18)\<number, number>  | 否 | 否   | 表示速度的方向，单位为度（°）。以元素几何中心为坐标原点，水平方向为X轴，正数表示顺时针方向旋转角度。<br>默认值：{range:[0.0,0.0]} <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|

## AccelerationOptions<sup>18+</sup>

```typescript
declare interface AccelerationOptions<
  ACC_SPEED_UPDATER extends ParticleUpdater,
  ACC_ANGLE_UPDATER extends ParticleUpdater
> {
  speed?: ParticlePropertyOptions<number, ACC_SPEED_UPDATER>;
  angle?: ParticlePropertyOptions<number, ACC_ANGLE_UPDATER>;
}
```

粒子加速度配置。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                | 只读 | 可选 | 说明                                                       |
| ------ | --------------------------------------------------- | ---- | ----------- | ---------------------------------------------- |
| speed<sup>10+</sup>  | [ParticlePropertyOptions](#particlepropertyoptions)<number, ACC_SPEED_UPDATER>  | 否 | 是   | 表示加速度大小。单位：vp/s²<br>默认值：{range:[0.0,0.0]}      <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| angle<sup>10+</sup>  | [ParticlePropertyOptions](#particlepropertyoptions)<number, ACC_ANGLE_UPDATER>  | 否 | 是   | 表示加速度方向，单位为度（°）。<br>默认值：{range:[0.0,0.0]} <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|

## EmitterParticleOptions<sup>18+</sup>

```typescript
interface EmitterParticleOptions<PARTICLE extends ParticleType> {
  type: PARTICLE;
  config: ParticleConfigs[PARTICLE];
  count: number;
  lifetime?: number;
  lifetimeRange?: number;
}
```

粒子配置。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                | 只读 | 可选 | 说明                                                       |
| ------ | --------------------------------------------------- | ---- | ----------- | ---------------------------------------------- |
| type<sup>10+</sup>  | [PARTICLE](#particletype)  | 否 | 否   | 表示粒子类型，可以选择图片或点。   <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。           |
| config<sup>10+</sup>  | [ParticleConfigs](#particleconfigs)[PARTICLE]  | 否 | 否   | 表示对应类型的配置。<br>config类型和type值有关联：<br>1. 如果type为ParticleType.POINT，则config类型为[PointParticleParameters](#pointparticleparameters) 。<br>2. 如果type为ParticleType.IMAGE，则config类型为[ImageParticleParameters](#imageparticleparameters) 。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| count<sup>10+</sup>  | number  | 否 | 否   | 表示发射的粒子总数，count取值>=-1,当count为-1表示粒子总数无限大。<br>**说明：**<br>当count为-1时发射器将持续发射粒子，如果不需要持续产生大量粒子，建议不要将count设置为-1，可能对性能造成较大影响，建议配合合理的emitRate和lifetime设置以避免性能问题。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| lifetime<sup>10+</sup>  | number  | 否 | 是   | 表示单个粒子的生命周期，默认值1000（即1000ms，1s），lifetime>=-1。当lifetime为-1表示粒子生命周期无限大。当lifetime<-1，取默认值。<br>**说明：**如果不需要动画一直播放，建议不要将生命周期设置为-1，可能对性能造成较大影响。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| lifetimeRange<sup>12+</sup>  | number  | 否 | 是   | 表示粒子生命周期取值范围，单位：毫秒(ms)。设置lifetimeRange后粒子的生命周期为[lifetime-lifetimeRange, lifetime+lifetimeRange]中间的一个随机整数。lifetimeRange默认值为0，取值范围为0到正无穷。设置为负值时取默认值。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## ParticleUpdaterOptions<sup>18+</sup>

```typescript
interface ParticleUpdaterOptions<TYPE, UPDATER extends ParticleUpdater> {
  type: UPDATER;
  config: ParticlePropertyUpdaterConfigs<TYPE>[UPDATER];
}
```

属性变化配置。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                | 只读 | 可选 | 说明                                                       |
| ------ | ----------------------------------- | ---------------- | ---- | --------------------------------------------------------- |
| type<sup>10+</sup>  | UPDATER | 否 | 否   | 表示属性变化类型。 <br>默认值：type默认为ParticleUpdater.NONE。    **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。          |
| config<sup>10+</sup>  | [ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)\<TYPE>[UPDATER] | 否 | 否   | 属性变化配置。属性变化类型type有三类：<br>1、当type为ParticleUpdater.NONE，表示无变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.NONE]。<br>2、当type为ParticleUpdater.RANDOM，表示变化类型为随机变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.RANDOM]。<br>3、当type为ParticleUpdater.CURVE，表示变化类型为曲线变化，则config类型为[ParticlePropertyUpdaterConfigs](#particlepropertyupdaterconfigs)[ParticleUpdater.CURVE]。 **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

## ParticleColorUpdaterOptions<sup>18+</sup>

```typescript
interface ParticleColorUpdaterOptions<UPDATER extends ParticleUpdater> {
  type: UPDATER;
  config: ParticleColorPropertyUpdaterConfigs[UPDATER];
}
```

颜色属性变化配置。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                | 只读 | 可选 | 说明                                                       |
| ------ | --------------------------------------------------- | ---- | ---------- | ----------------------------------------------- |
| type<sup>10+</sup>  | UPDATER  | 否 | 否   | 表示颜色属性变化类型。<br>默认值：type默认为 ParticleUpdater.NONE。     <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| config<sup>10+</sup>  | [ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[UPDATER]  | 否 | 否   | 颜色属性变化类型type有三类：<br>1、当type为ParticleUpdater.NONE，表示无变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.NONE]。 <br>2、type为ParticleUpdater.RANDOM，表示随机均匀变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.RANDOM]。 <br>3、type为ParticleUpdater.CURVE,表示按动画曲线变化，则config类型为[ParticleColorPropertyUpdaterConfigs](#particlecolorpropertyupdaterconfigs)[ParticleUpdater.CURVE]。 <br>**说明**：<br>当type为ParticleUpdater.RANDOM或者ParticleUpdater.CURVE时，updater中颜色配置的优先级高于range中的颜色配置。在updater配置的动画时间周期内，以updater中的颜色配置来变化；在updater配置的动画时间周期外，以range中的颜色配置来变化。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

## ParticleColorOptions<sup>18+</sup>

颜色变化方式为随机变化的时候，在区间内随机生成一个差值。r、g、b、a四个颜色通道每秒分别使用差值叠加当前颜色值，生成目标颜色值。实现颜色随机变化的效果。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                           | 只读 | 可选 | 说明                         |
| ---- | ----------------- | ------------- | ---- | --------------------------- |
| r<sup>10+</sup>    | [ParticleTuple](#particletuple18)<number, number>  | 否 | 否   | r颜色通道的差值。   **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| g<sup>10+</sup>    | [ParticleTuple](#particletuple18)<number, number>  | 否 | 否   | g颜色通道的差值。   **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| b<sup>10+</sup>    | [ParticleTuple](#particletuple18)<number, number>  | 否 | 否   | b颜色通道的差值。   **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| a<sup>10+</sup>    | [ParticleTuple](#particletuple18)<number, number>  | 否 | 否   | a颜色通道的差值。   **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |

## ParticleAnnulusRegion<sup>20+</sup>

用于设置环形发射器区域的配置信息。

> **说明：**
>
> - outerRadius、innerRadius小于零或使用百分比单位时，会按零进行处理。
>
> - 当outerRadius小于innerRadius时（即外圆半径小于内圆半径时），会将当前较小的值作为新的内圆半径，将较大的值作为新的外圆半径。
>
> - 当endAngle小于startAngle时（即结束角度小于起始角度时），会将当前较小的值作为新的起始角度，将较大的值作为新的结束角度。
>
> ![](figures/annulus.png)


**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | -- | -- | ---- |
| center      | [PositionT](#positiontt12)&lt;[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&gt; | 否 | 是  | 圆环的圆心坐标，组件的左上角为坐标原点。默认值：{x:LengthMetrics.percent(0.5),y:LengthMetrics.percent(0.5)}   |
| outerRadius      | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 否   | 圆环的外圆半径。小于零或使用百分比单位时按零进行处理。当outerRadius小于innerRadius时，会将当前较小的值作为新的内圆半径，将较大的值作为新的外圆半径。   |
| innerRadius  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 否  | 圆环的内圆半径。小于零或使用百分比单位时按零进行处理。当outerRadius小于innerRadius时，会将当前较小的值作为新的内圆半径，将较大的值作为新的外圆半径。   |
| startAngle | number | 否 | 是   | 圆环的起始角度。<br>单位：度（°）<br>取值范围：(-∞, +∞)<br>默认值：0  |
| endAngle | number | 否 | 是   | 圆环的结束角度。<br>单位：度（°）<br>取值范围：(-∞, +∞)<br>默认值：360  |

## Vector2T\<T><sup>22+</sup>

type Vector2T\<T> = import('../api/arkui/Graphics').Vector2T\<T>

定义Vector2T类型。其中Vector2T类型包含x和y两个属性值。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                         | 说明                                |
| ---------------------------- | ----------------------------------- |
| import('../api/arkui/Graphics').[Vector2T\<T>](../js-apis-arkui-graphics.md#vector2tt12) | 用于表示T类型的包含x和y两个值的向量。x表示向量x轴方向的值。y表示向量y轴方向的值。<br>单位：vp |

## PositionT\<T><sup>12+</sup>

type PositionT\<T> = import('../api/arkui/Graphics').Position\<T>

用于设置或返回组件的位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                         | 说明                                |
| ---------------------------- | ----------------------------------- |
| import('../api/arkui/Graphics').[PositionT\<T>](../js-apis-arkui-graphics.md#positiontt12) | 包含x和y两个值的向量。<br>单位：vp |

## SizeT\<T><sup>12+</sup>

type SizeT\<T> = import('../api/arkui/Graphics').SizeT\<T>

定义Size类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                         | 说明                                |
| ---------------------------- | ----------------------------------- |
| import('../api/arkui/Graphics').[SizeT\<T>](../js-apis-arkui-graphics.md#sizett12) | Size类型，包含了宽和高。<br>单位：vp |

## FieldRegion<sup>22+</sup>

用于设置粒子场的区域信息。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | -- | -- | ---- |
| shape      | [DisturbanceFieldShape](#disturbancefieldshape12) | 否 | 是  | 粒子场的区域形状。<br>默认值：DisturbanceFieldShape.RECT  |
| position      | [PositionT](#positiontt12)&lt;number&gt; | 否 | 是 | 粒子场的区域中心位置。坐标单位为vp。<br>默认值：{x:0, y:0}  |
| size  | [SizeT](#sizett12)&lt;number&gt; | 否 | 是  | 粒子场的区域大小。值的单位为vp。<br>默认值：{width:0, height:0}<br>取值范围：<br>width：[0, +∞)<br>height：[0, +∞)<br>当size的width（或height）设置为负值时取width（或height）的默认值。  |

## RippleFieldOptions<sup>22+</sup>

用于描述粒子波动场信息的参数。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | -- | -- | ---- |
| amplitude      | number | 否 | 是  | 描述粒子波动场波的幅值。幅值越大，波动场的力越大，粒子在波动场作用下产生的位移变化越明显，波纹扩散效果越强烈。<br>取值范围：[0, +∞)<br>默认值：0<br>设置为负值时取默认值。  |
| wavelength      | number | 否 | 是 | 描述粒子波动场的波长，即一个波周期的变化距离。波长越大，则随距离的变化，波的变化越慢，波动越不明显，粒子受波动影响的周期变长。<br>取值范围：[0, +∞)<br>默认值：0<br>设置为负值时取默认值。  |
| waveSpeed  | number | 否 | 是  | 描述粒子波动场的波速。波速越大，则随时间的变化，波的变化越快，波动越明显，粒子受波动影响的响应越迅速。单位：vp/s。<br>取值范围：[0, +∞)<br>默认值：0<br>设置为负值时取默认值。  |
| attenuation  | number | 否 | 是  | 描述粒子波动场波的衰减系数。衰减系数越大，则随时间的变化，波的衰减越快，粒子受到的波动场力随时间迅速减弱，波纹扩散效果逐渐消失。<br>取值范围：[0, 1]<br>默认值：0.0<br>设置的数值不在范围内时取默认值。  |
| center  | [PositionT](#positiontt12)&lt;number&gt; | 否 | 是  | 粒子波动场产生力的中心位置。组件的左上角为坐标原点。坐标单位为vp。<br>默认值：{x:0, y:0} |
| region  | [FieldRegion](#fieldregion22) | 否 | 是  | 粒子波动场影响的区域信息，其中区域信息包括区域形状、区域大小以及区域中心位置。<br>默认值：{shape:DisturbanceFieldShape.RECT, position:{x:0, y:0}, size:{width:0, height:0}}  |

## VelocityFieldOptions<sup>22+</sup>

用于描述粒子速度场信息的参数。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明 |
| ------ | ------ | -- | -- | ---- |
| velocity      | [Vector2T](#vector2tt22)\<number> | 否 | 是  | 粒子速度场的各方向速度值。粒子只有在速度场作用范围内时获得该速度，离开速度场范围后不受该速度场影响，不获得该额外的速度。单位：vp/s。<br>默认值：{x:0, y:0}  |
| region  | [FieldRegion](ts-particle-animation.md#fieldregion22) | 否 | 是  | 粒子速度场影响的区域信息，其中区域信息包括区域形状、区域大小以及区域中心位置。<br>默认值：{shape:DisturbanceFieldShape.RECT, position:{x:0, y:0}, size:{width:0, height:0}}  |

## 示例

### 示例1（圆形初始化粒子）

描述粒子动画基础用法，通过圆形初始化粒子。

<!-- @[particle_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/particle/template1/Index.ets) -->

``` TypeScript
@Entry
@Component
struct ParticleExample {
  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor(Color.Black)
      Particle({
        particles: [
          {
            emitter: {
              particle: {
                type: ParticleType.POINT, // 粒子类型
                config: {
                  radius: 10 // 圆点半径
                },
                count: 500, // 粒子总数
                lifetime: 10000, // 粒子生命周期，单位ms
                lifetimeRange: 100 // 粒子生命周期取值范围，单位ms
              },
              emitRate: 10, // 每秒发射粒子数
              position: [0, 0],
              shape: ParticleEmitterShape.RECTANGLE // 发射器形状
            },
            color: {
              range: [Color.Red, Color.Yellow], // 初始颜色范围
              distributionType: DistributionType.GAUSSIAN, // 初始颜色随机值分布
              updater: {
                type: ParticleUpdater.CURVE, // 变化方式为曲线变化
                config: [
                  {
                    from: Color.White, // 变化起始值
                    to: Color.Pink, // 变化终点值
                    startMillis: 0, // 开始时间
                    endMillis: 3000, // 结束时间
                    curve: Curve.EaseIn // 变化曲线
                  },
                  {
                    from: Color.Pink,
                    to: Color.Orange,
                    startMillis: 3000,
                    endMillis: 5000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: Color.Orange,
                    to: Color.Pink,
                    startMillis: 5000,
                    endMillis: 8000,
                    curve: Curve.EaseIn
                  },
                ]
              }
            },
            opacity: {
              range: [0.0, 1.0], // 粒子透明度的初始值从【0.0到1.0】随机产生
              updater: {
                type: ParticleUpdater.CURVE,
                config: [
                  {
                    from: 0.0,
                    to: 1.0,
                    startMillis: 0,
                    endMillis: 3000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: 1.0,
                    to: 0.0,
                    startMillis: 5000,
                    endMillis: 10000,
                    curve: Curve.EaseIn
                  }
                ]
              }
            },
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
            acceleration: {
              // 加速度的配置，从大小和方向两个维度变化，speed表示加速度大小，angle表示加速度方向
              speed: {
                range: [3, 9],
                updater: {
                  type: ParticleUpdater.RANDOM, // Speed的变化方式是随机均匀变化
                  config: [1, 20]
                }
              },
              angle: {
                range: [90, 90]
              }
            }

          }
        ]
      }).width(300).height(300)
    }.width('100%').height('100%').align(Alignment.Center)
  }
}
```

![particle](figures/particle.gif)

### 示例2（图片初始化粒子）

描述粒子动画基础用法，通过图片初始化粒子。该示例同时配置两种不同的图片粒子，展示多粒子类型组合效果。

```ts
@Entry
@Component
struct ParticleExample {
  @State
  myCount: number = 100

  // 通过参数化配置减少重复代码，imageSrc为图片资源，scaleTo为缩放目标值，durationMs为动画持续时长
  private createImageParticle(imageSrc: ResourceStr, scaleTo: number, durationMs: number)
    : ParticleOptions<ParticleType.IMAGE, ParticleUpdater.CURVE, ParticleUpdater.CURVE,
  ParticleUpdater.CURVE, ParticleUpdater.CURVE, ParticleUpdater.CURVE, ParticleUpdater.CURVE>
  {
    return {
      emitter: {
        particle: {
          type: ParticleType.IMAGE,
          config: {
            src: imageSrc,
            size: [10, 10]
          },
          count: this.myCount,
          lifetime: 10000,
          lifetimeRange: 100
        },
        emitRate: 3,
        shape: ParticleEmitterShape.CIRCLE
      },
      color: {
        range: [Color.White, Color.White]
      },
      opacity: {
        range: [1.0, 1.0],
        updater: {
          type: ParticleUpdater.CURVE,
          config: [
            { from: 0, to: 1.0, startMillis: 0, endMillis: 6000 },
            { from: 1.0, to: 0, startMillis: 6000, endMillis: 10000 }
          ]
        }
      },
      scale: {
        range: [0.1, 1.0],
        updater: {
          type: ParticleUpdater.CURVE,
          config: [
            { from: 0, to: scaleTo, startMillis: 0, endMillis: durationMs, curve: Curve.EaseIn }
          ]
        }
      },
      acceleration: {
        speed: {
          range: [3, 9],
          updater: {
            type: ParticleUpdater.CURVE,
            config: [
              { from: 10, to: 20, startMillis: 0, endMillis: 3000, curve: Curve.EaseIn },
              { from: 10, to: 2, startMillis: 3000, endMillis: 8000, curve: Curve.EaseIn }
            ]
          }
        },
        angle: {
          range: [0, 180],
          updater: {
            type: ParticleUpdater.CURVE,
            config: [
              { from: 1, to: 2, startMillis: 0, endMillis: 1000, curve: Curve.EaseIn },
              { from: 50, to: -50, startMillis: 1000, endMillis: 3000, curve: Curve.EaseIn },
              { from: 3, to: 5, startMillis: 3000, endMillis: durationMs, curve: Curve.EaseIn }
            ]
          }
        }
      },
      spin: {
        range: [0.1, 1.0],
        updater: {
          type: ParticleUpdater.CURVE,
          config: [
            { from: 0, to: 360, startMillis: 0, endMillis: durationMs, curve: Curve.EaseIn }
          ]
        }
      },
    }
  }

  build() {
    Column() {
      Stack() {
        Particle({
          particles: [
            this.createImageParticle($r("app.media.book"), 1.5, 8000),   // book粒子：缩放至1.5倍，持续8000ms
            this.createImageParticle($r('app.media.heart'), 2.0, 10000),  // heart粒子：缩放至2.0倍，持续10000ms
          ]
        }).width(300).height(300)

      }.width(500).height(500).align(Alignment.Center)
    }.width('100%').height('100%')

  }
}
```

![particle](figures/particle_inage_one.gif)

### 示例3（粒子扰动场的干扰下运动轨迹发生变化）

演示粒子在扰动场干扰下运动轨迹变化的效果。

<!-- @[particle_example3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/particle/template3/Index.ets) -->  

``` TypeScript
@Entry
@Component
struct ParticleExample3 {
  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor(Color.Black)
      Particle({
        particles: [
          {
            emitter: {
              particle: {
                type: ParticleType.POINT, // 粒子类型
                config: {
                  radius: 10 // 圆点半径
                },
                count: 500, // 粒子总数
                lifetime: 10000 // 粒子生命周期，单位ms
              },
              emitRate: 10, // 每秒发射粒子数
              position: [0, 0],
              shape: ParticleEmitterShape.RECTANGLE // 发射器形状
            },
            color: {
              range: [Color.Red, Color.Yellow], // 初始颜色范围
              updater: {
                type: ParticleUpdater.CURVE, // 变化方式为曲线变化
                config: [
                  {
                    from: Color.White, // 变化起始值
                    to: Color.Pink, // 变化终点值
                    startMillis: 0, // 开始时间
                    endMillis: 3000, // 结束时间
                    curve: Curve.EaseIn // 变化曲线
                  },
                  {
                    from: Color.Pink,
                    to: Color.Orange,
                    startMillis: 3000,
                    endMillis: 5000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: Color.Orange,
                    to: Color.Pink,
                    startMillis: 5000,
                    endMillis: 8000,
                    curve: Curve.EaseIn
                  },
                ]
              }
            },
            opacity: {
              range: [0.0, 1.0], // 粒子透明度的初始值从[0.0,1.0]随机产生
              updater: {
                type: ParticleUpdater.CURVE,
                config: [
                  {
                    from: 0.0,
                    to: 1.0,
                    startMillis: 0,
                    endMillis: 3000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: 1.0,
                    to: 0.0,
                    startMillis: 5000,
                    endMillis: 10000,
                    curve: Curve.EaseIn
                  }
                ]
              }
            },
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
            acceleration: {
              // 加速度的配置，从大小和方向两个维度变化，speed表示加速度大小，angle表示加速度方向
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
      // 设置粒子扰动场，干扰粒子运动轨迹
      }).width(300).height(300).disturbanceFields([{
        strength: 10, // 场强，表示排斥力或吸引力的强度
        shape: DisturbanceFieldShape.RECT, // 扰动场形状为矩形
        size: { width: 100, height: 100 }, // 扰动场大小
        position: { x: 100, y: 100 }, // 扰动场位置
        feather: 15, // 羽化值，表示场从中心点到场边缘的衰减程度
        noiseScale: 10, // 噪声尺度
        noiseFrequency: 15, // 噪声频率
        noiseAmplitude: 5 // 噪声振幅
      }])
    }.width('100%').height('100%').align(Alignment.Center)
  }
}
```
![particle](figures/disturbanceFields.gif)

### 示例4（调整粒子发射器位置）
通过emitter()调整粒子发射器的位置。
<!-- @[particle_example4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/particle/template4/Index.ets) -->

``` TypeScript
@Entry
@Component
struct ParticleExample4 {
  @State emitterProperties: Array<EmitterProperty> = [
    {
      index: 0,
      emitRate: 100,
      position: { x: 60, y: 80 },
      size: { width: 200, height: 200 }
    }
  ];

  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor(Color.Black)
      Particle({
        particles: [
          {
            emitter: {
              particle: {
                type: ParticleType.POINT, // 粒子类型
                config: {
                  radius: 5 // 圆点半径
                },
                count: 400, // 粒子总数
                lifetime: -1 // 粒子的生命周期，-1表示粒子生命周期无限大
              },
              emitRate: 10, // 每秒发射粒子数
              position: [0, 0], // 粒子发射位置
              shape: ParticleEmitterShape.CIRCLE // 发射器形状
            },
            color: {
              range: [Color.Red, Color.Yellow], // 初始颜色范围
              updater: {
                type: ParticleUpdater.CURVE, // 变化方式为曲线变化
                config: [
                  {
                    from: Color.White,
                    to: Color.Pink,
                    startMillis: 0,
                    endMillis: 3000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: Color.Pink,
                    to: Color.Orange,
                    startMillis: 3000,
                    endMillis: 5000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: Color.Orange,
                    to: Color.Pink,
                    startMillis: 5000,
                    endMillis: 8000,
                    curve: Curve.EaseIn
                  },
                ]
              }
            },
          },
        ]
      })
        .width(300)
        .height(300)
        .emitter(this.emitterProperties)
    }.width('100%').height('100%').align(Alignment.Center)
  }
}
```
![particle](figures/emitters.gif)

### 示例5（环形发射器创建）
该示例演示如何创建环形发射器，粒子在整个圆环范围内（起始角度0到结束角度360）静态发射。
<!-- @[particle_example5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/particle/template5/Index.ets) -->

``` TypeScript
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct ParticleExample5 {
  build() {
    Stack() {
      Text()
        .width(300).height(300).backgroundColor(Color.Black)
      Particle({
        particles: [
          {
            emitter: {
              particle: {
                type: ParticleType.POINT, // 粒子类型
                config: {
                  radius: 5 // 圆点半径
                },
                count: 2000, // 粒子总数
                lifetime: 10000, // 粒子生命周期，单位ms
                lifetimeRange: 100 // 粒子生命周期取值范围，单位ms
              },
              emitRate: 100, // 每秒发射粒子数
              shape: ParticleEmitterShape.ANNULUS, // 环形发射器
              annulusRegion:{
                center:{x:LengthMetrics.percent(0.5),y:LengthMetrics.percent(0.5)}, // 圆环的圆心坐标
                innerRadius:LengthMetrics.vp(100), // 圆环的内圆半径
                outerRadius:LengthMetrics.vp(120), // 圆环的外圆半径
                startAngle:0, // 圆环的起始角度
                endAngle:360 // 圆环的结束角度
              }
            },
            color: {
              range: [Color.Pink, Color.White],
            },
            opacity: {
              range: [0.0, 1.0],
              updater: {
                type: ParticleUpdater.CURVE,
                config: [
                  {
                    from: 0.0,
                    to: 1.0,
                    startMillis: 0,
                    endMillis: 3000,
                    curve: Curve.EaseIn
                  },
                  {
                    from: 1.0,
                    to: 0.0,
                    startMillis: 5000,
                    endMillis: 10000,
                    curve: Curve.EaseIn
                  }
                ]
              }
            },
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
          }
        ]
      }).width(300).height(300)
    }.width('100%').height('100%').align(Alignment.Center)
  }
}
```
![](figures/annulusCreate.gif)

### 示例6（环形发射器更新）
描述粒子动画环形发射器更新的基础用法。
<!-- @[particle_example6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/particle/template6/Index.ets) -->  

``` TypeScript
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct ParticleExample6 {
  @State radius: number = 1;
  @State shape: ParticleEmitterShape = ParticleEmitterShape.ANNULUS; // 圆环
  @State emitRate: number = 200;
  @State count: number = 4000;
  private timerID: number = -1;
  private centerX: LengthMetrics = LengthMetrics.percent(0.5);
  private centerY: LengthMetrics = LengthMetrics.percent(0.5);
  private inRadius: LengthMetrics = LengthMetrics.vp(120);
  private outRadius: LengthMetrics = LengthMetrics.vp(120);
  private startAngle: number = -90;   // 时钟12点钟方向
  private endAngle: number = -60;   // 时钟1点钟方向

  // 粒子动画，环形发射器的更新参数设置
  @State emitterProperties: Array<EmitterProperty> = [
    {
      index: 0,
      emitRate: 100,
      annulusRegion: {
        center: {x:this.centerX, y: this.centerY}, // 圆环的圆心坐标
        outerRadius: this.outRadius, // 圆环的外圆半径
        innerRadius: this.inRadius, // 圆环的内圆半径
        startAngle: this.startAngle, // 圆环的起始角度
        endAngle: this.endAngle // 圆环的结束角度
      }
    }
  ]

  // 创建的时候，环形发射器的初始设置
  @State region: ParticleAnnulusRegion = {
    center: {x:this.centerX, y: this.centerY},
    outerRadius: this.outRadius,
    innerRadius: this.inRadius,
    startAngle: -90,
    endAngle: -60
  }

  onPageShow(): void {
    // 创建定时器（每秒更新）
    this.timerID = setInterval(() => {
      this.emitterProperties = [
        {
          index: 0,
          emitRate: this.emitRate,
          annulusRegion: {
            center:{x:this.centerX, y: this.centerY},
            outerRadius: this.outRadius,
            innerRadius: this.inRadius,
            startAngle: this.startAngle,
            endAngle: this.endAngle
          }
        }
      ];
      if (this.endAngle >= 360) {
        if (this.timerID != -1) {
          clearInterval(this.timerID);
        }
        return;
      }
      // 更新角度值（30度/秒）
      this.startAngle += 30;
      this.endAngle += 30;
      console.info("angle: " + this.startAngle + ", " + this.endAngle);
    }, 1000);
  }

  build() {
    Column({ space: 10}) {
      Stack() {
        Text()
          .width(300).height(300).backgroundColor(Color.Black)

        Particle({
          particles: [
            {
              emitter: {
                particle: {
                  type: ParticleType.POINT, // 粒子类型
                  config: {
                    radius: this.radius // 圆点半径
                  },
                  count: this.count, // 粒子总数
                  lifetime: -1 // 粒子的生命周期，-1表示粒子生命周期无限大
                },
                emitRate: this.emitRate, // 每秒发射粒子数
                shape: this.shape, // 发射器形状
                annulusRegion: this.region
              },
              color: {
                range: [Color.White, Color.Pink], // 初始颜色范围
              },
            },
          ]
        }).width('100%')
          .height('100%')
          .emitter(this.emitterProperties)
      }
      .width('100%')
      .height('100%')
      .align(Alignment.Center)
    }
  }
}
```
![](figures/annulusUpdate.gif)

### 示例7（设置波动场和速度场）
从API version 22开始，支持设置粒子波动场和速度场。该示例演示如何通过rippleFields接口设置粒子波动场，产生类似波纹扩散的效果。通过velocityFields接口设置粒子速度场，使粒子在原有速度的基础上叠加速度场指定的速度。
```ts
// xxx.ets
@Entry
@Component
struct ParticleExample {
  @State count: number = 1000
  @State particle: EmitterParticleOptions<ParticleType> = {
    type: ParticleType.POINT, // 粒子类型
    config: {
      radius: 1 // 圆点半径
    },
    count: this.count, // 粒子总数
    lifetime: 9000, // 粒子生命周期，单位ms
    lifetimeRange: 100 // 粒子生命周期取值范围，单位ms
  }
  build() {
    Column() {
      Text('波动场')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      Stack() {
        Text()
          .width(300).height(300).backgroundColor(Color.Black)
        Particle({
          particles: [
            {
              emitter: {
                particle: this.particle,
                emitRate: 10000, // 每秒发射粒子数
                position: [0, 0],
                shape: ParticleEmitterShape.RECTANGLE // 发射器形状
              },
              color: {
                range: [Color.White, Color.White], // 初始颜色范围
              },
              scale: {
                range: [0.2, 1.5], // 初始大小范围
              },
              opacity : {
                range: [0.2, 0.8], // 初始透明度范围
              }
            }
          ]
        }).width(300).height(300)
          .rippleFields([
            {
              amplitude: 120, // 波动场幅值
              wavelength: 500, // 波动场的波长
              waveSpeed: 220, // 波动场的波速
              center: { x: 150, y: 150 }, // 波动场的力的中心
              attenuation: 0, // 波动场随时间的衰减系数
              region: {
                // 波动场的影响区域
                shape: DisturbanceFieldShape.RECT, // 波动场影响区域的形状
                position: { x: 150, y: 150 }, // 波动场影响区域的区域中心
                size: { width: 300, height: 300 } // 波动场影响区域的大小
              }
            }
          ])
      }.width('100%').height(300).align(Alignment.Center)
      Text('速度场')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      Stack() {
        Text()
          .width(300).height(300).backgroundColor(Color.Black)
        Particle({
          particles: [
            {
              emitter: {
                particle: {
                  type: ParticleType.POINT, // 粒子类型
                  config: {
                    radius: 2 // 圆点半径
                  },
                  count: 1000, // 粒子总数
                  lifetime: 1000, // 粒子生命周期，单位ms
                  lifetimeRange: 0 // 粒子生命周期取值范围，单位ms
                },
                emitRate: 120, // 每秒发射粒子数
                position: [0, 0],
                size: [300, 300],
                shape: ParticleEmitterShape.RECTANGLE // 发射器形状
              },
              color: {
                range: [Color.White, Color.White], // 初始颜色范围
              },
              opacity: {
                range: [1.0, 1.0],
                updater: {
                  type: ParticleUpdater.CURVE, // 透明度按曲线变化
                  config: [
                    {
                      from: 1.0,
                      to: 0.0,
                      startMillis: 0,
                      endMillis: 1000,
                      curve: Curve.EaseIn
                    }
                  ]
                }
              },
            }
          ]
        }).width(300).height(300)
          .margin({ top: 30 })
          .velocityFields([
            {
              velocity: { x: 100, y: 0 }, // 速度场的速度值
              region: {
                // 速度场的影响区域
                shape: DisturbanceFieldShape.RECT, // 速度场影响区域的形状
                position: { x: 150, y: 150 }, // 速度场影响区域的区域中心
                size: { width: 200, height: 200 } // 速度场影响区域的大小
              }
            }
          ])
      }.width('100%').height(300).align(Alignment.Center)
    }
  }
}
```
![](figures/particleRipple.gif)
