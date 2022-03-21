# 公共事件数据

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CommonEventData

**系统能力：**以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称       | 读写属性 | 类型                 | 必填 | 描述                                                    |
| ---------- | -------- | -------------------- | ---- | ------------------------------------------------------- |
| event      | 只读     | string               | 是   | 表示当前接收的公共事件名称                              |
| bundleName | 只读     | string               | 否   | 表示包名称                                              |
| code       | 只读     | number               | 否   | 表示公共事件的结果代码，用于传递int类型的数据           |
| data       | 只读     | string               | 否   | 表示公共事件的自定义结果数据，用于传递string类型的数据< |
| parameters | 只读     | {[key: string]: any} | 否   | 表示公共事件的附加信息                                  |