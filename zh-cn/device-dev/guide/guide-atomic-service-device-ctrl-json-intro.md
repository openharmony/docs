# 概述<a name="ZH-CN_TOPIC_0000001205747225"></a>

模板中json配置文件为设备控制界面的主要依据，智能电风扇页面json文件路径为control/src/main/resources/rawfile/FAN，配置如下：

```
{
  "devName": "智能电风扇",
  "devType": "0",
  "prodId": "FAN",       -- prodId指定了控制界面上的产品图名称
  "templateUIInfo": [    -- templateUIInfo下面可以堆砌模板提供的Control类型控件，以行为单位。
    {"name": "电源"...},
    {"name": "模式"...},
    {"name": "档位"...},
    {"name": "预约关机"...}
  ],
  "dialogUIInfo": [      -- dialogUIInfo下面可以声明Dialog类型控件，默认不显示， 由点击事件触发弹框
    {"name": "关机时间"...}
  ]
}
```

目前模板里面提供了两种类型的控件（Control类型控件直接显示在界面上， Dialog类型控件需要触发后以弹窗形式展示），在json配置文件里声明不同控件即可。

**修改json配置文件后重新安装运行原子化服务就能显示修改后的效果。**

