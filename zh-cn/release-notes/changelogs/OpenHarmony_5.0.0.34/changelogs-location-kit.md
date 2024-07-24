# 位置服务子系统Changelog

## cl.location.1 interface Location的altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType属性从必选改为可选

**访问级别**

公开接口

**变更原因**

interface Location在API12上新增了必选属性altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType，需要定义成可选才是向前兼容的。

**变更影响**

该变更为不兼容变更。

变更前：APP代码在获取到Location时，可以直接使用altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType属性。

变更后：APP代码在获取到Location并且使用altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType属性时，需要先判断该属性是否等于undefined，不等于undefined才能读取并使用该属性。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.34 版本开始。

**变更的接口/组件**

interface Location的altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType属性。

**适配指导**

APP代码在获取到Location并且使用altitudeAccuracy、speedAccuracy、directionAccuracy、uncertaintyOfTimeSinceBoot、sourceType等属性时，需要先判断该属性是否等于undefined，不等于undefined才能读取并使用该属性。


## cl.location.2 interface SatelliteStatusInfo的satelliteConstellation、satelliteAdditionalInfo属性从必选改为可选

**访问级别**

公开接口

**变更原因**

interface SatelliteStatusInfo在API12上新增了必选属性satelliteConstellation、satelliteAdditionalInfo，需要定义成可选才是向前兼容的。

**变更影响**

该变更为不兼容变更。

变更前：APP代码在获取到SatelliteStatusInfo时，可以直接使用satelliteConstellation、satelliteAdditionalInfo属性。

变更后：APP代码在获取到SatelliteStatusInfo并且使用satelliteConstellation、satelliteAdditionalInfo属性时，需要先判断该属性是否等于undefined，不等于undefined才能读取并使用该属性。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.34 版本开始。

**变更的接口/组件**

interface SatelliteStatusInfo的satelliteConstellation、satelliteAdditionalInfo属性。

**适配指导**

APP代码在获取到SatelliteStatusInfo并且使用satelliteConstellation、satelliteAdditionalInfo等属性时，需要先判断该属性是否等于undefined，不等于undefined才能读取并使用该属性。