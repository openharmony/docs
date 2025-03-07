# ArkGraphics2D Changelog

## cl.arkgraphics2d.1 New Line Height Calculation Rule Can Be Enabled By Configuring ohos.graphics2d.text.adapter_text_height Under metadata in Any Module

**Access Level**

Public API

**Reason for Change**

In the prior revision where [the **ohos.graphics2d.text.adapter_text_height** field was added to the **metadata** tag of the main module to enable the new line height calculation rule globally](../OpenHarmony_5.0.0.46/changelogs-arkgraphics2d.md), the field setting must be placed exclusively within the main module. However, some applications do not have a main module configuration file and therefore are unable to use the new line height calculation rule. To address this issue, the restriction is removed, allowing the new line height calculation rule to be activated by simply including the setting in the configuration file of any module within the application.

**Change Impact**

This change is a compatible change.

To enable the new line height calculation rule for the application, you can configure the **ohos.graphics2d.text.adapter_text_height** field under the [**metadata** tag in the module.json5 file](../../../application-dev/quick-start/module-configuration-file.md#metadata) of any module.

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

After the application is started, an INFO log is generated. If the log contains "Adapter text height enabled: 1", the new line height calculation rule is enabled. In other cases, the default rule is used.

**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.53

**Key API/Component Changes**

N/A

**Adaptation Guide**

This update removes the restriction that the new line height calculation rule can be activated only by configuring **ohos.graphics2d.text.adapter_text_height** within the main module. If you have already carried out this setting in the main module, no modification is required.
