# VpnExtensionContext

VpnExtensionContext是VpnExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

VpnExtensionContext可直接作为VpnExtension的上下文环境，提供允许访问特定于VpnExtensionAbility的资源的能力。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import VpnExtensionAbility from '@ohos.app.ability.VpnExtensionAbility';
```
## 使用说明

通过VpnExtensionAbility子类实例来获取。

```ts
import VpnExtensionAbility from '@ohos.app.ability.VpnExtensionAbility';
import Want from '@ohos.app.ability.Want';
import vpnExt from '@ohos.net.vpnExtension';

let VpnConnection: vpnExt.VpnConnection;

export default class MyVpnExtAbility extends VpnExtensionAbility {
  private vpnServerIp: string = 'xxx.xxx.x.x';
  private tunIp: string = 'x.x.x.x';
  private blockedAppName: string = 'xxxx';

  onCreate(want: Want) {
    // this.context is VpnExtensionContext
    VpnConnection = vpnExt.createVpnConnection(this.context);
  }
}
```
