# ArkGraphics2D变更说明

## cl.arkgraphics2d.1 在应用的任一模块配置metadata标签ohos.graphics2d.text.adapter_text_height以支持全局使能新的行高计算规则

**访问级别**

公开接口

**变更原因**

在之前的变更：[主模块metadata标签新增ohos.graphics2d.text.adapter_text_height支持全局使能新的行高计算规则](../OpenHarmony_5.0.0.46/changelogs-arkgraphics2d.md#clarkgraphics2d1-主模块metadata标签新增ohosgraphics2dtextadapter_text_height支持全局使能新的行高计算规则)中有必须配置在主模块的限制，而存在应用没有主模块的配置文件，在不修改配置文件类型的情况下无法使能新的行高规则，所以需要取消该限制，改为在应用的任一模块的配置文件中配置即可使能新的行高规则。

**变更影响**

该变更为兼容性变更。
在应用的任一模块的[module.json5配置文件metadata标签](../../../application-dev/quick-start/module-configuration-file.md#metadata标签)中新增ohos.graphics2d.text.adapter_text_height以支持应用使能新的行高计算规则。

```json
{
    "module": {
        "name": "test",
        "type": "entry",
        "metadata": [
            {
                "name": "ohos.graphics2d.text.adapter_text_height",
            }
        ]
    }
}
```

在应用启动之后会输出一条INFO级别的日志，只有"Adapter text height enabled: 1"表示使能新的行高规则，其余情况使能默认的行高规则。

**起始API Level**

13

**变更发生版本**

从OpenHarmony SDK 5.0.0.53版本开始。

**变更的接口/组件**

不涉及

**适配指导**

此次主要是取消只有在主模块配置ohos.graphics2d.text.adapter_text_height才能使能新的字体行高规则的限制，原先已在主模块配置的不受影响。