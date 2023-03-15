# Configuring System Capabilities
The SystemCapability (SysCap) module provides a set of APIs for developers to implement system capabilities.
##  Configuring System Capabilities for a Component 
When adding a component, you need to enable or disable specific system capabilities for it in the **bundle.json** file in the component directory. 

The following is an example:

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
Add the keyword **syscap** under **component** to configure system capabilities. If no value is assigned for a system capability, the default value **true** will be used. The value **true** means to enable the system capability, and the value **false** means the opposite.

In this example, Wi-Fi STA, AP, and HotspotExt are enabled, and P2P and Core are disabled.
## Configuring System Capabilities for a Product
When building a product, you may need to enable or disable specific system capabilities for it in **vendor/{company}/{product}/config.json**. If you do not configure system capabilities here, the system capabilities configured for the component will be used.

To configure system capabilities for a product, add the keyword **syscap** to the product **config.json** file and configure the system capabilities. The system capabilities configured for a product take precedence over the system capabilities configured for a component. If a system capability is set to **false** for the component and to **true** for the product, the system capability is enabled. 

The following is an example:

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
In this example, Wi-Fi AP and HotspotExt are disabled and P2P is enabled for the product. Considering the system capability configuration example for the component, STA and P2P are enabled and AP, Core, and HotspotExt are disabled.
## Configuration Tips
If a product does not have feature difference, you only need to configure system capabilities for components. If a product has feature difference, you can enable or disable specific system capabilities in the product configuration file.
