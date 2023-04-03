# 泛sensor子系统ChangeLog

## cl.ability.1 Sensor接口中venderName属性名称变更，更改为vendorName。

venderName为错别字，更正为vendorName。

**变更影响**

该venderName属性无法再使用，请使用新增属性vendorName替换。

**关键的接口/组件变更**

- 变更前：

```js
    interface Sensor {
        sensorName:string; /**< Sensor name */
        venderName:string; /**< Sensor vendor version */
        firmwareVersion:string; /**< Sensor firmware version */
        hardwareVersion:string; /**< Sensor hardware version */
        sensorId:number; /**< Sensor type ID, {@code SensorType} */
        maxRange:number; /**< Maximum measurement range of the sensor */
        minSamplePeriod:number; /**< Minimum sample period allowed, in ns */
        maxSamplePeriod:number; /**< maximum sample period allowed, in ns */
        precision:number; /**< Sensor accuracy */
        power:number; /**< Sensor power */
    }
```

- 变更后：

```js
    interface Sensor {
        sensorName:string; /**< Sensor name */
        vendorName:string; /**< Sensor vendor version */
        firmwareVersion:string; /**< Sensor firmware version */
        hardwareVersion:string; /**< Sensor hardware version */
        sensorId:number; /**< Sensor type ID, {@code SensorType} */
        maxRange:number; /**< Maximum measurement range of the sensor */
        minSamplePeriod:number; /**< Minimum sample period allowed, in ns */
        maxSamplePeriod:number; /**< maximum sample period allowed, in ns */
        precision:number; /**< Sensor accuracy */
        power:number; /**< Sensor power */
    }
```

**适配指导**

该venderName属性删除无法再使用，请使用新增属性vendorName替换。