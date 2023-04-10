# 配置卡片的配置文件


卡片相关的配置文件主要包含FormExtensionAbility的配置和卡片的配置两部分：


1. 卡片需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中的extensionAbilities标签下，配置FormExtensionAbility相关信息。FormExtensionAbility需要填写metadata元信息标签，其中键名称为固定字符串“ohos.extension.form”，资源为卡片的具体配置信息的索引。

   配置示例如下：

   
   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "name": "EntryFormAbility",
           "srcEntry": "./ets/entryformability/EntryFormAbility.ts",
           "label": "$string:EntryFormAbility_label",
           "description": "$string:EntryFormAbility_desc",
           "type": "form",
           "metadata": [
             {
               "name": "ohos.extension.form",
               "resource": "$profile:form_config"
             }
           ]
         }
       ]
     }
   }
   ```

2. 卡片的具体配置信息。在上述FormExtensionAbility的元信息（“metadata”配置项）中，可以指定卡片具体配置信息的资源索引。例如当resource指定为$profile:form_config时，会使用开发视图的resources/base/profile/目录下的form_config.json作为卡片profile配置文件。内部字段结构说明如下表所示。

   **表1** 卡片form_config.json配置文件

   | 属性名称 | 含义 | 数据类型 | 是否可缺省 |
   | -------- | -------- | -------- | -------- |
   | name | 表示卡片的类名，字符串最大长度为127字节。 | 字符串 | 否 |
   | description | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省为空。 |
   | src | 表示卡片对应的UI代码的完整路径。当为ArkTS卡片时，完整路径需要包含卡片文件的后缀，如："./ets/widget/pages/WidgetCard.ets"。当为JS卡片时，完整路径无需包含卡片文件的后缀，如："./js/widget/pages/WidgetCard" | 字符串 | 否 |
   | uiSyntax | 表示该卡片的类型，当前支持如下两种类型：<br/>-&nbsp;arkts：当前卡片为ArkTS卡片。<br/>-&nbsp;hml：当前卡片为JS卡片。 | 字符串 | 可缺省，缺省值为hml |
   | window | 用于定义与显示窗口相关的配置。 | 对象 | 可缺省 |
   | isDefault | 表示该卡片是否为默认卡片，每个UIAbility有且只有一个默认卡片。<br/>-&nbsp;true：默认卡片。<br/>-&nbsp;false：非默认卡片。 | 布尔值 | 否 |
   | colorMode | 表示卡片的主题样式，取值范围如下：<br/>-&nbsp;auto：自适应。<br/>-&nbsp;dark：深色主题。<br/>-&nbsp;light：浅色主题。 | 字符串 | 可缺省，缺省值为“auto”。 |
   | supportDimensions | 表示卡片支持的外观规格，取值范围：<br/>-&nbsp;1&nbsp;\*&nbsp;2：表示1行2列的二宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;2：表示2行2列的四宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;4：表示2行4列的八宫格。<br/>-&nbsp;4&nbsp;\*&nbsp;4：表示4行4列的十六宫格。 | 字符串数组 | 否 |
   | defaultDimension | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串 | 否 |
   | updateEnabled | 表示卡片是否支持周期性刷新（包含定时刷新和定点刷新），取值范围：<br/>-&nbsp;true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，当两者同时配置时，定时刷新优先生效。<br/>-&nbsp;false：表示不支持周期性刷新。 | 布尔类型 | 否 |
   | scheduledUpdateTime | 表示卡片的定点刷新的时刻，采用24小时制，精确到分钟。<br/>&gt;&nbsp;**说明：**<br/>&gt;&nbsp;updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 字符串 | 可缺省，缺省时不进行定点刷新。 |
   | updateDuration | 表示卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br/>当取值为0时，表示该参数不生效。<br/>当取值为正整数N时，表示刷新周期为30\*N分钟。<br/>&gt;&nbsp;**说明：**<br/>&gt;&nbsp;updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 数值 | 可缺省，缺省值为“0”。 |
   | formConfigAbility | 表示卡片的配置跳转链接，采用URI格式。 | 字符串 | 可缺省，缺省值为空。 |
   | formVisibleNotify | 标识是否允许卡片使用卡片可见性通知。 | 字符串 | 可缺省，缺省值为空。 |
   | metadata | 表示卡片的自定义信息，包含customizeData数组标签。 | 对象 | 可缺省，缺省值为空。 |

   配置示例如下：

   
   ```json
   {
     "forms": [
       {
         "name": "widget",
         "description": "This is a service widget.",
         "src": "./ets/widget/pages/WidgetCard.ets",
         "uiSyntax": "arkts",
         "window": {
           "designWidth": 720,
           "autoDesignWidth": true
         },
         "colorMode": "auto",
         "isDefault": true,
         "updateEnabled": true,
         "scheduledUpdateTime": "10:30",
         "updateDuration": 1,
         "defaultDimension": "2*2",
         "supportDimensions": [
           "2*2"
         ]
       }
     ]
   }
   ```
