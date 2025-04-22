# 配置卡片的配置文件


卡片相关的配置文件主要包含FormExtensionAbility的配置和卡片的配置两部分。


1. 卡片需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中的extensionAbilities标签下，配置FormExtensionAbility相关信息。FormExtensionAbility需要填写metadata元信息标签，其中键名称为固定字符串“ohos.extension.form”，资源为卡片的具体配置信息的索引。

   配置示例如下：


   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "EntryFormAbility",
           "srcEntry": "./ets/entryformability/EntryFormAbility.ets",
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
   | forms | 表示应用的全部卡片配置信息。<br/>最多支持配置16个卡片，若超过16个，则保留配置的前16个。 | 数组 | 否 |
   | name | 表示卡片的名称，字符串最大长度为127字节。 | 字符串 | 否 |
   | displayName | 表示卡片的显示名称。取值可以是名称内容，也可以是对名称内容的资源索引，以支持多语言。字符串最小长度为1字节，最大长度为30字节。 | 字符串 | 否 |
   | description | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省为空。 |
   | src | 表示卡片对应的UI代码的完整路径。当为ArkTS卡片时，完整路径需要包含卡片文件的后缀，如："./ets/widget/pages/WidgetCard.ets"。当为JS卡片时，完整路径无需包含卡片文件的后缀，如："./js/widget/pages/WidgetCard" | 字符串 | 否 |
   | uiSyntax | 表示该卡片的类型，当前支持如下两种类型：<br/>-&nbsp;arkts：当前卡片为ArkTS卡片。<br/>-&nbsp;hml：当前卡片为JS卡片。 | 字符串 | 可缺省，缺省值为“hml”。 |
   | [window](#window标签) | 用于定义与显示窗口相关的配置。 | 对象 | 可缺省，缺省值见表2。 |
   | isDefault | 表示该卡片是否为默认卡片，每个UIAbility有且只有一个默认卡片。<br/>-&nbsp;true：默认卡片。<br/>-&nbsp;false：非默认卡片。 | 布尔值 | 否 |
   | colorMode | 表示卡片的主题样式，取值范围如下：<br/>-&nbsp;auto：跟随系统的颜色模式值选取主题。<br/>-&nbsp;dark：深色主题。<br/>-&nbsp;light：浅色主题。 | 字符串 | 可缺省，缺省值为“auto”。 |
   | supportDimensions | 表示卡片支持的外观规格，取值范围：<br/>-&nbsp;1&nbsp;\*&nbsp;2：表示1行2列的二宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;2：表示2行2列的四宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;4：表示2行4列的八宫格。<br/>-&nbsp;4&nbsp;\*&nbsp;4：表示4行4列的十六宫格。<br/>-&nbsp;1&nbsp;\*&nbsp;1：表示1行1列的圆形卡片。<br/>-&nbsp;6&nbsp;\*&nbsp;4：表示6行4列的二十四宫格。 | 字符串数组 | 否 |
   | defaultDimension | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串 | 否 |
   | updateEnabled | 表示卡片是否支持周期性刷新（包含定时刷新和定点刷新），取值范围：<br/>-&nbsp;true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，当两者同时配置时，定时刷新优先生效。<br/>-&nbsp;false：表示不支持周期性刷新。 | 布尔类型 | 否 |
   | scheduledUpdateTime | 表示卡片的定点刷新的时刻，采用24小时制，精确到分钟。<br/>**说明：**<br/>updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 字符串 | 可缺省，缺省时不进行定点刷新。 |
   | updateDuration | 表示卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br/>当取值为0时，表示该参数不生效。<br/>当取值为正整数N时，表示刷新周期为30\*N分钟。<br/>**说明：**<br/>updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 数值 | 可缺省，缺省值为“0”。 |
   | formConfigAbility | 表示卡片的配置跳转链接，采用URI格式。| 字符串 | 可缺省，缺省值为空。 |
   | metadata | 表示卡片的自定义信息，参考[Metadata](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md)数组标签。 | 对象 | 可缺省，缺省值为空。 |
   | dataProxyEnabled | 表示卡片是否支持卡片代理刷新，取值范围：<br/>-&nbsp;true：表示支持代理刷新。<br/>-&nbsp;false：表示不支持代理刷新。<br/>设置为true时，[定时刷新和下次刷新不生效，但不影响定点刷新](./arkts-ui-widget-update-by-time.md)。 | 布尔类型 | 可缺省，缺省值为false。 |
   | [isDynamic](#isdynamic标签) | 表示此卡片是否为动态卡片（仅针对ArkTS卡片生效）。 <br/>-&nbsp;true：为动态卡片 。<br/>-&nbsp;false：为静态卡片。<br/>| 布尔类型 | 可缺省，缺省值为true。 |
   | fontScaleFollowSystem | 表示卡片使用方设置此卡片的字体是否支持跟随系统变化。 <br/>-&nbsp;true：支持跟随系统字体大小变化 。<br/>-&nbsp;false：不支持跟随系统字体大小变化。<br/>| 布尔类型 | 可缺省，缺省值为true。 |
   | supportShapes | 表示卡片的显示形状，取值范围如下：<br/>-&nbsp;rect：表示方形卡片。<br/>-&nbsp;circle：表示圆形卡片。| 字符串 | 可缺省，缺省值为“rect”。 |
   | previewImages | 表示卡片预览图, 与配置项`supportDimensions`一一对应。| 字符串 | 可缺省，智能穿戴卡片必须配置，当前仅支持在智能穿戴上使用。 |
   | <!--DelRow-->formVisibleNotify | 表示是否允许卡片使用卡片可见性通知（仅对系统应用的卡片生效）。 | 布尔类型 | 可缺省，缺省值为false。 |
   | <!--DelRow-->transparencyEnabled | 表示是否支持卡片使用方设置此卡片的背景透明度（仅对系统应用的ArkTS卡片生效。）。 <br/>-&nbsp;true：支持设置背景透明度 。<br/>-&nbsp;false：不支持设置背景透明度。<br/>| 布尔类型 | 可缺省，缺省值为false。 |
   |enableBlurBackground|表示卡片是否使用模糊背板。<br/>-&nbsp;true：开启模糊背板。<br/>-&nbsp;false：关闭模糊背板。|布尔类型|可缺省，缺省值为false。|
   |renderingMode|表示卡片的渲染模式，取值范围如下：<br/>-&nbsp;autoColor：自动模式，锁屏卡片中心与桌面卡片中心/卡片管理内都可以显示的卡片。<br/>-&nbsp;fullColor：全色模式，桌面卡片中心/卡片管理内可以显示的卡片。<br/>-&nbsp;singleColor：单色模式，锁屏卡片中心内可以显示的卡片。	|字符串|可缺省，缺省值为“fullColor”。|
   |multiScheduledUpdateTime|表示卡片的多定点刷新的时刻，作为单点刷新的一个附加参数，采用24小时制，精确到分钟，多个时间用英文逗号分隔，最多写24个时间。<br/>**说明：**<br/>multiScheduledUpdateTime需要配合scheduledUpdateTime使用。|字符串|可缺省，缺省时不进行多定点刷新。|
   |conditionUpdate|表示卡片的支持的条件刷新（仅对系统应用的ArkTS卡片生效）。取值范围如下：<br/>-&nbsp;network：表示支持网络刷新。|字符串|可缺省，缺省值为空字符串。|

## isDynamic标签

此标签标识卡片是否为动态卡片（仅针对ArkTS卡片生效）。

| 卡片类型 | 支持的能力 | 适用场景 | 优缺点 |
| ------- | ------ | ------- | ------- | 
| 静态卡片 | 仅支持UI组件和布局能力。| 主要用于展示静态信息（UI相对固定），仅可以通过FormLink组件跳转到指定的UIAbility。| 功能简单但可以有效控制内存开销。|
| 动态卡片 | 除了支持UI组件和布局能力，还支持通用事件能力和自定义动效能力。 | 用于有复杂业务逻辑和交互的场景。例如：卡片页面图片的刷新、卡片内容的刷新等。| 功能丰富但内存开销较大。|

## window标签

此标签标识window对象的内部结构说明。

   | 属性名称 | 含义 | 数据类型 | 是否可缺省 |
   | -------- | -------- | -------- | -------- |
   | designWidth | 标识页面设计基准宽度。以此为基准，根据实际设备宽度来缩放元素大小。 | 数值 | 可缺省，缺省值为720px。 |
   | autoDesignWidth | 标识页面设计基准宽度是否自动计算。当配置为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 | 布尔值 | 可缺省，缺省值为false。 |

   配置示例如下：

<!--RP1-->
   ```json
   {
     "forms": [
       {
         "name": "widget",
         "displayName": "$string:widget_display_name",
         "description": "$string:widget_desc",
         "src": "./ets/widget/pages/WidgetCard.ets",
         "uiSyntax": "arkts",
         "window": {
           "designWidth": 720,
           "autoDesignWidth": true
         },
         "colorMode": "auto",
         "renderingMode": "fullColor",
         "isDefault": true,
         "updateEnabled": true,
         "scheduledUpdateTime": "10:30",
         "updateDuration": 1,
         "defaultDimension": "2*2",
         "supportDimensions": [
           "2*2"
         ],
         "formConfigAbility": "ability://EntryAbility",
         "dataProxyEnabled": false,
         "isDynamic": true,
         "transparencyEnabled": false,
         "metadata": []
       }
     ]
   }
   ```
<!--RP1End-->