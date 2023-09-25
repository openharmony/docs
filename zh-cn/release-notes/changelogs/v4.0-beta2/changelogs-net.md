# 网络子系统ChangeLog

## net.vpn createVpnConnection接口层级变更

**变更影响**

createVpnConnection接口不能被三方应用调用。

**示例：**
```ts
import vpn from '@ohos.net.vpn';
import common from '@ohos.app.ability.common';

@Entry
@Component
struct Index {
private context = getContext(this) as common.UIAbilityContext;
private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
    functiontest()
    {
        console.info("vpn createVpnConnection: " + JSON.stringify(this.VpnConnection));
    }
    build() {  }
}
```