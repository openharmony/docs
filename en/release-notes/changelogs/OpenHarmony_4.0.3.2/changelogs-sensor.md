# Pan-sensor Subsystem Changelog

## cl.ability.1 Attribute Name Changed from venderName to vendorName in the Sensor API

**venderName** is changed to **vendorName**.

**Change Impact**

The **venderName** attribute cannot be used anymore. Use **vendorName** instead.

**Key API/Component Changes**

- Before change:

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

- After change:

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

**Adaptation Guide**

Replace **venderName** with **vendorName**.
