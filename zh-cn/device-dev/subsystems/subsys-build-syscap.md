# 如何按需配置部件的系统能力
SysCap（SystemCapability，系统能力）是部件向开发者提供的接口的集合。
##  部件配置系统能力
部件配置系统能力是为了方便某个特定部件是否要打开或关闭特定的系统能力。

部件配置系统能力的位置在部件目录下的bundle.json，配置示例如下所示：
```json
  "component": {
        "name": "wifi",
        "subsystem": "communication",
        "syscap": [
            "SystemCapability.Communication.WiFi.STA = true",
            "SystemCapability.Communication.WiFi.AP = true",
            "SystemCapability.Communication.WiFi.P2P = false",
            "SystemCapability.Communication.WiFi.Core = false",
            "SystemCapability.Communication.WiFi.HotspotExt"
          ]
        ],
        ...
  }

```
在component下加入关键字syscap，对内部配置相应的系统能力。系统能力若无赋值，则默认为true，若有赋值，则按实际值为准。若值为true，则表示该部件默认开启此系统能力，若值为false，则表明该部件默认关闭此系统能力。

以上配置表明，WIFI的STA、AP、和HotspotExt三个系统能力是打开的，而P2P和Core是关闭的。
## 产品配置系统能力
产品配置系统能力是为了方便某个特定产品是否要打开或关闭特定的系统能力，若无配置，则以部件侧的配置为准，产品配置系统能力的位置在vender/{company}/{product}/config.json。

如果要对产品的系统能力进行精细化配置，可在产品配置中加入syscap关键字，并对要配置的系统能力赋值。产品侧的配置优先级大于部件系统能力默认配置，若某一个系统能力在部件侧默认配置为false，在产品侧配置为true，则这个系统能力的最终配置为true。示例如下：
```json
{
      "subsystem": "communication",
      "components": [
        ...
        {
          "component": "wifi",
          "features": [],
          "syscap": [
            "SystemCapability.Communication.WiFi.AP = false",
            "SystemCapability.Communication.WiFi.P2P = true",
            "SystemCapability.Communication.WiFi.HotspotExt = false"
          ]
        },
        ...
```
以上配置表明，WiFi的AP和HotspotExt系统能力是关闭的，而P2P是打开的。综合部件侧的配置，最终STA、P2P为打开系统能力，而AP、Core和HotspotExt为关闭的系统能力。
## 部件侧配置和产品侧配置的作用
一般来说，当产品没有特性化差异的时候，我们仅需在部件侧配置系统能力，部件侧配置的系统能力是我们的基础，只有当产品存在特性化差异，需要关闭某个默认打开的系统能力或打开某个系统默认关闭的系统能力时，我们才会需要在产品侧配置。
