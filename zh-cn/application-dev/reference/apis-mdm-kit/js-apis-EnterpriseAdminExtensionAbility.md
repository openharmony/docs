# @ohos.enterprise.EnterpriseAdminExtensionAbility（企业设备管理扩展能力）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供[企业设备管理扩展能力](../../mdm/mdm-kit-term.md#enterpriseadminextensionability企业设备管理扩展能力)，是企业设备管理应用的核心组件。

**主要功能**：
- 提供设备管理应用的生命周期管理能力（激活、去激活、启动等事件）。
- 提供应用生命周期事件监听能力（安装、卸载、启动、停止、更新）。
- 提供系统账号管理事件监听能力（账号新增、切换、删除）。
- 提供Kiosk模式、按键事件、日志收集、系统更新等系统级事件回调。
- 提供策略变更事件监听能力。

**使用场景**：企业设备管理应用开发、企业应用生命周期管理、设备安全管控、账号管理、设备运维监控等。

设备管理应用需要存在一个EnterpriseAdminExtensionAbility并重写相关接口，以此具备模块提供的各项能力，比如接收由系统发送的该应用被激活或者解除激活的通知。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> 
> 本模块接口仅可在Stage模型下使用。
> 

## 导入模块

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
```

## EnterpriseAdminExtensionAbility

企业设备管理扩展能力组件，是设备管理应用必备组件。当开发者为企业开发设备管理应用时，需继承EnterpriseAdminExtensionAbility，在EnterpriseAdminExtensionAbility实例中实现MDM业务逻辑，EnterpriseAdminExtensionAbility实现了系统管理状态变化通知功能，并定义了管理应用激活、去激活、应用安装、卸载事件等回调接口。

### 属性

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context<sup>23+</sup> | [EnterpriseAdminExtensionContext](js-apis-application-EnterpriseAdminExtensionContext.md) | 否 | 否 | EnterpriseAdminExtensionAbility的上下文。继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。|

### onAdminEnabled

onAdminEnabled(): void

当前设备管理应用被激活后，触发该回调。企业管理员或者员工部署并激活设备管理应用，系统通知设备管理应用已激活admin权限。设备管理应用可在此回调函数中进行初始化策略设置。无需注册，激活后默认触发该回调。

**与onDeviceAdminEnabled的区别：**
- onAdminEnabled：设备管理应用自身被激活时触发，用于设备管理应用初始化自己的策略。
- onDeviceAdminEnabled：超级设备管理应用监听普通设备管理应用激活事件，用于超级设备管理应用对普通设备管理应用进行管理。

开发者应根据应用类型和监听场景选择合适的方法：普通设备管理应用使用onAdminEnabled，超级设备管理应用监听其他应用激活时使用onDeviceAdminEnabled。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
    console.info(`Succeeded in calling onAdminEnabled callback.`);
  }
}
```

### onAdminDisabled

onAdminDisabled(): void

当前设备管理应用被解除激活后，触发该回调。企业管理员或者员工解除激活设备管理，系统通知设备管理应用已解除激活admin权限。设备管理应用可在此回调函数中通知企业管理员设备已脱管。无需注册，解除激活后默认触发该回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminDisabled() {
    console.info(`Succeeded in calling onAdminDisabled callback.`);
  }
}
```

### onBundleAdded

onBundleAdded(bundleName: string): void

应用安装事件回调，回调中包含应用包名。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BUNDLE_ADDED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用安装事件，端侧应用安装事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 被安装应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}`);
  }
}
```

### onBundleAdded<sup>14+</sup>

onBundleAdded(bundleName: string, accountId: number): void

应用安装事件回调，回调中包含应用包名和账号ID。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BUNDLE_ADDED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用安装事件，端侧应用安装事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 被安装应用的包名。 |
| accountId | number | 是    | 被安装应用所在的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // 由于存在同名回调方法onBundleAdded(bundleName: string)，该回调方法无accountId参数，因此在实际调用时accountId必须为可选参数，写法请参考示例代码。如果删除accountId后的问号"?"，编译会报错。
  onBundleAdded(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onBundleRemoved

onBundleRemoved(bundleName: string): void

应用卸载事件回调，回调中包含应用包名。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BUNDLE_REMOVED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用卸载事件，端侧应用卸载事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 被卸载应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}`);
  }
}
```

### onBundleRemoved<sup>14+</sup>

onBundleRemoved(bundleName: string, accountId: number): void

应用卸载事件回调，回调中包含应用包名和账号ID。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BUNDLE_REMOVED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用卸载事件，端侧应用卸载事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 被卸载应用的包名。 |
| accountId | number | 是    | 被卸载应用所在的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // 由于存在同名回调方法onBundleRemoved(bundleName: string)，该回调方法无accountId参数，因此在实际调用时accountId必须为可选参数，写法请参考示例代码。如果删除accountId后的问号"?"，编译会报错。
  onBundleRemoved(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onAppStart

onAppStart(bundleName: string): void

应用启动事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_APP_START事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用启动事件，端侧应用启动事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 启动应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_APP_START];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStart(bundleName: string) {
    console.info(`Succeeded in calling onAppStart callback, started bundle name : ${bundleName}`);
  }
}
```

### onAppStop

onAppStop(bundleName: string): void

应用停止事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_APP_STOP事件才能收到此回调。企业设备管理场景下，设备管理应用订阅应用停止事件，端侧应用停止事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 停止应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_APP_STOP];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStop(bundleName: string) {
    console.info(`Succeeded in calling onAppStop callback, stopped bundle name : ${bundleName}`);
  }
}
```
### onSystemUpdate

onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo): void

系统更新事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_SYSTEM_UPDATE事件才能收到此回调。企业设备管理场景下，设备管理应用订阅系统更新事件，端侧系统更新事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名           | 类型                                                         | 必填 | 说明                 |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------- |
| systemUpdateInfo | [systemManager.SystemUpdateInfo](js-apis-enterprise-systemManager.md#systemupdateinfo) | 是   | 系统更新的版本信息，用于通知设备管理应用系统版本更新情况。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_SYSTEM_UPDATE];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo) {
    console.info(`Succeeded in calling onSystemUpdate callback, version name  : ${systemUpdateInfo.versionName}`);
  }
}
```

### onStart

onStart(): void

EnterpriseAdminExtensionAbility启动事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStart() {
    console.info(`Succeeded in calling onStart callback.`);
  }
}
```

### onAccountAdded<sup>18+</sup>

onAccountAdded(accountId: number): void

系统账号新增事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_ACCOUNT_ADDED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅系统账号新增事件，系统账号新增事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | 是    | 新增的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountAdded(accountId: number) {
    console.info(`Succeeded in calling onAccountAdded callback, added accountId: ${accountId}`);
  }
}
```

### onAccountSwitched<sup>18+</sup>

onAccountSwitched(accountId: number): void

系统账号切换事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_ACCOUNT_SWITCHED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅系统账号切换事件，系统账号切换事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | 是    | 切换后的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_SWITCHED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountSwitched(accountId: number) {
    console.info(`Succeeded in calling onAccountSwitched callback, switched accountId: ${accountId}`);
  }
}
```

### onAccountRemoved<sup>18+</sup>

onAccountRemoved(accountId: number): void

系统账号删除事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_ACCOUNT_REMOVED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅系统账号删除事件，系统账号删除事件通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | 是    | 被删除的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountRemoved(accountId: number) {
    console.info(`Succeeded in calling onAccountRemoved callback, removed accountId: ${accountId}`);
  }
}
```

### onKioskModeEntering<sup>20+</sup>

onKioskModeEntering(bundleName: string, accountId: number): void

应用进入Kiosk模式回调，回调中包含应用包名和用户ID。

Kiosk模式为系统层面提供的一种应用运行模式，该模式下会将设备锁定在单个应用或者一组应用运行，同时对锁屏状态、状态栏、手势操作和关键功能进行控制，防止用户在设备上启动其它应用或执行其它操作。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 进入Kiosk模式应用的包名。 |
| accountId | number | 是    | 进入Kiosk模式应用所在的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onKioskModeEntering(bundleName: string, accountId: number): void {
    console.info(`Succeeded in calling onKioskModeEntering callback, bundleName:${bundleName}, accountId:${accountId}`);
  }
}
```

### onKioskModeExiting<sup>20+</sup>

onKioskModeExiting(bundleName: string, accountId: number): void

应用退出Kiosk模式回调，回调中包含应用包名和用户ID。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 退出Kiosk模式应用的包名。 |
| accountId | number | 是    | 退出Kiosk模式应用所在的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onKioskModeExiting(bundleName: string, accountId: number): void {
    console.info(`Succeeded in calling onKioskModeExiting callback, bundleName:${bundleName}, accountId:${accountId}`);
  }
}
```

### onMarketAppInstallResult<sup>22+</sup>

onMarketAppInstallResult(bundleName: string, result: common.InstallationResult): void

安装应用市场应用接口[bundleManager.installMarketApps](./js-apis-enterprise-bundleManager.md#bundlemanagerinstallmarketapps22)安装结果回调，回调中包含应用包名和安装结果。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。
  
**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 应用市场应用包名。 |
| result | [common.InstallationResult](./js-apis-enterprise-common.md#installationresult) | 是    | 安装结果，表示应用市场应用的安装状态，包含安装成功或失败的状态信息。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, common } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onMarketAppInstallResult(bundleName: string, result: common.InstallationResult): void {
    console.info(`Succeeded in calling onMarketAppInstallResult callback, bundleName:${bundleName}, result:${result}`);
  }
}
```

### onDeviceAdminEnabled<sup>23+</sup>

onDeviceAdminEnabled(bundleName: string): void

仅超级设备管理应用在普通设备管理应用被激活时会触发此回调。企业管理员或者员工部署并激活普通设备管理应用，系统通知超级设备管理应用已激活admin权限。超级设备管理应用可在此回调函数中进行初始化策略设置。不需要注册，激活后默认触发该回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型   | 必填 | 说明               |
| ---------- | ------ | ---- | ------------------ |
| bundleName | string | 是   | 被激活应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceAdminEnabled(bundleName: string) {
  }
}
```

### onDeviceAdminDisabled<sup>23+</sup>

onDeviceAdminDisabled(bundleName: string): void

仅超级设备管理应用在普通设备管理应用被解除激活时会触发此回调。企业管理员或者员工解除激活普通设备管理应用，系统通知超级设备管理应用已解除激活admin权限。超级设备管理应用可在此回调函数中通知企业管理员设备已脱管。不需要注册，解除激活后默认触发该回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型   | 必填 | 说明                   |
| ---------- | ------ | ---- | ---------------------- |
| bundleName | string | 是   | 被解除激活应用的包名。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceAdminDisabled(bundleName: string) {
  }
}
```

### onKeyEvent<sup>23+</sup>

onKeyEvent(keyEvent: systemManager.KeyEvent): void

[按键事件](./js-apis-enterprise-systemManager.md#keyevent23)回调。MDM应用需要通过[systemManager.addKeyEventPolicies](./js-apis-enterprise-systemManager.md#systemmanageraddkeyeventpolicies23)接口下发按键事件处理策略，当系统按键事件触发时，如果事件与已下发的策略匹配，则触发该回调。回调信息[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)中包含当前发生的按键事件信息。

单按键事件响应。设备单按键被触发时，[onKeyEvent](#onkeyevent23)会在按下和抬起时触发两次回调事件，可由[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)中keyAction属性进行判断。[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)中keyItems属性在单按键事件中可忽略。

组合按键事件响应。组合按键仅支持物理按键：电源键、音量加键、音量减键进行组合。用户按下组合键时，后按下按键的事件回调将通过[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)中的keyItems属性携带当前所有已按下的按键信息。其他与单按键事件响应逻辑一致。

长按事件响应。当单个按键或组合按键被长时间按下时，[onKeyEvent](#onkeyevent23)会以50ms的间隔（具体间隔时间可能因系统状态及性能而稍有延长）被连续触发，其中每次回调事件[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)的actionTime属性均与按键首次按下事件回调的[keyEvent](./js-apis-enterprise-systemManager.md#keyevent23)的actionTime属性相同。其他情况下的响应逻辑与单个按键和组合按键一致。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| keyEvent | [systemManager.KeyEvent](./js-apis-enterprise-systemManager.md#keyevent23) | 是    | 当前发生的按键事件信息，包含按键码（keyCode）、按键动作（keyAction，如按下/抬起）、触发时间（actionTime）、已按下按键列表（keyItems）等，用于识别和处理用户的按键操作。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
import { systemManager } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {

 /* MDM应用下发按键事件监听后，用户按键行为匹配监听策略时，将触发该事件，事件回调携带当前匹配的按键信息。
  * 
  * 例如：
  * 1.用户短按电源键时触发回调（以电源键为例）
  * 1.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1。
  * 1.2 用户短按电源键
  * 1.3 触发回调
  * 结果：按下：onKeyEvent event:{"actionTime": 1895101259, "keyCode": 0, "keyAction": 0,
  *          "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 1895101259}]}
  *       抬起：onKeyEvent event:{"actionTime": 1895478977, "keyCode": 0, "keyAction": 1,
  *         "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 1895101259}]}
  *
  * 2.用户长按电源键时触发回调（以电源键为例）
  * 2.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1。
  * 2.2 用户长按电源键
  * 2.3 触发回调
  * 结果：按下：onKeyEvent event:{"actionTime": 14468236859, "keyCode": 0, "keyAction": 0,
  *         "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 14468236859}]}
  *      长按：onKeyEvent event:{"actionTime": 14468236859, "keyCode": 0, "keyAction": 0,
  *         "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 14468236859}]}
  *          ......
  *       抬起：onKeyEvent event:{"actionTime": 14471425448, "keyCode": 0, "keyAction": 1,
  *         "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 14468236859}]}
  * 
  * 组合键根据下发策略不同，分为下面多种场景：
  * 3.用户按组合键触发回调1（以电源键和音量+键为例）
  * 3.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1；keyCode为1，keyPolicy为1；
  * 3.2 用户同时按下电源键和音量+键
  * 3.3 触发回调
  * 结果：同时按下（电源键先，音量+键后）
  *      onKeyEvent event:{"actionTime": 20991450446, "keyCode": 1, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 20991432293}，
  *   {"pressed": true, "keyCode": 1, "downTime": 20991450446}]}
  *      同时抬起 （音量+键先，电源键后）
  *      onKeyEvent event:{"actionTime": 20590590293, "keyCode": 1, "keyAction": 1,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 28588682984}，
  *   {"pressed": false, "keyCode": 1, "downTime": 21588900860}]}
  * 
  * 4.用户按组合键触发回调2（以电源键和音量+键为例）
  * 4.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1；keyCode为1，keyPolicy为0；
  * 4.2 用户同时按下电源键和音量+键
  * 4.3 触发回调
  * 结果：同时按下（音量+键先，电源键后）
  *      onKeyEvent event:{"actionTime": 28991115400, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 28990731985}，
  *   {"pressed": true, "keyCode": 0, "downTime": 20991115400}]}
  *      同时抬起 （音量+键先，电源键后）
  *      onKeyEvent event:{"actionTime": 28992721560, "keyCode": 0, "keyAction": 1,
  *   "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 28991115400}]}
  * 
  * 5.用户按组合键触发回调3（以电源键和音量+键为例）
  * 5.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1；
  * 5.2 用户同时按下电源键和音量+键
  * 5.3 触发回调
  * 结果：同时按下（音量+键先，电源键后）
  *      onKeyEvent event:{"actionTime": 29979014190, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 29978420634}，
  *   {"pressed": true, "keyCode": 0, "downTime": 29979014190}]}
  *      同时抬起 （电源键先，音量+键后）
  *      onKeyEvent event:{"actionTime": 29982420773, "keyCode": 0, "keyAction": 1,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 29978420634}，
  *   {"pressed": false, "keyCode": 0, "downTime": 29979014190}]}
  * 
  * 6.用户按组合键触发回调4（以电源键和导航键-最近打开为例）
  * 6.1 下发按键监听事件
  * 请参考systemManager.addKeyEventPolicies。
  * 下发keyCode为0，keyPolicy为1；keyCode为5，keyPolicy为1；
  * 6.2 用户同时按下电源键和导航键-最近打开
  * 6.3 触发回调
  * 结果：同时按下（各自执行回调，互不影响）
  *      onKeyEvent event:{"actionTime": 34073626894, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 34073626894}]}
  *      onKeyEvent event:{"actionTime": 34075144844, "keyCode": 5, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 5, "downTime": 0}]}
  */
  onKeyEvent(keyEvent: systemManager.KeyEvent): void {
    console.info(`Succeeded in calling onKeyEvent callback, key event:${JSON.stringify(keyEvent)}`);
  }
}
```

### onLogCollected<sup>23+</sup>

onLogCollected(result: common.Result): void

通过[systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23)接口成功创建日志收集任务后，当日志收集完成时，将触发该回调。回调中包含日志收集结果。

> **说明：**
> 
> 日志收集成功时，必须在应用的EnterpriseAdminExtensionAbility中访问沙箱目录（/data/edm/log）获取日志，获取日志方式参考下列示例代码。应用取走日志后，建议调用[systemManager.finishLogCollected](./js-apis-enterprise-systemManager.md#systemmanagerfinishlogcollected23)删除已收集到的日志。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| result | [common.Result](./js-apis-enterprise-common.md#result) | 是    | 日志收集结果，用于标识日志收集是否成功，常见值为SUCCESS（收集成功）或FAIL（收集失败），开发者可根据结果判断是否执行后续的日志获取操作。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { EnterpriseAdminExtensionAbility, common, systemManager } from '@kit.MDMKit';
import { fileIo as fs } from '@kit.CoreFileKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  /**
   * MDM应用调用systemManager.startCollectLog接口启动日志收集任务后，将触发该回调函数，回调携带日志收集结果。
   * 若result为common.Result.SUCCESS，表示日志收集成功。请取走日志，并调用systemManager.finishLogCollected删除已收集到的日志。
   * 若result为common.Result.FAIL，表示日志收集失败。
   */
  onLogCollected(result: common.Result): void {
    console.info(`Succeeded in calling onLogCollected callback, result:${result}`);
    if (result === common.Result.SUCCESS) {
      let filesDir = '/data/edm/log';
      // 应用沙箱路径，需根据实际情况进行替换
      let targetPath = this.context.tempDir;
      try {
        let files: string[] = fs.listFileSync(filesDir);
        // 从/data/edm/log沙箱目录取走日志
        files.forEach(value => {
          fs.copyFileSync(filesDir + '/' + value, targetPath + '/' + value);
        });
        let wantTemp: Want = {
          // 需根据实际情况进行替换
          bundleName: 'com.example.myapplication',
          abilityName: 'EnterpriseAdminAbility'
        };
        systemManager.finishLogCollected(wantTemp);
      } catch (error) {
        console.info("onLogCollected", "error: " + JSON.stringify(error))
      }
    }
    if (result === common.Result.FAIL) {
      console.error("onLogCollected", "Failed to collect log.")
    }
  }
}
```

### onStartupGuideCompleted<sup>24+</sup>

onStartupGuideCompleted(scene: common.StartupScene): void

开机向导完成事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_STARTUP_GUIDE_COMPLETED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅开机向导完成事件，端侧系统在首次切换子用户完成（仅限PC）、OTA升级完成、首次开机完成开机向导时会通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型   | 必填 | 说明                   |
| ---------- | ------ | ---- | ---------------------- |
| scene | [common.StartupScene](./js-apis-enterprise-common.md#startupscene24) | 是   | 开机向导完成场景，标识触发回调的具体场景类型，如用户设置完成（USER_SETUP）、OTA升级完成（OTA）、设备配置完成（DEVICE_PROVISION）等，开发者可根据不同场景执行相应的业务逻辑。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_STARTUP_GUIDE_COMPLETED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStartupGuideCompleted(scene: common.StartupScene) {
    if (scene === common.StartupScene.USER_SETUP) {
      console.info('onStartupGuideCompleted scene is USER_SETUP');
    } else if (scene === common.StartupScene.OTA) {
      console.info('onStartupGuideCompleted scene is OTA');
    } else if (scene === common.StartupScene.DEVICE_PROVISION) {
      console.info('onStartupGuideCompleted scene is DEVICE_PROVISION');
    }
  }
}
```

### onDeviceBootCompleted<sup>24+</sup>

onDeviceBootCompleted(): void

设备开机完成事件回调。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BOOT_COMPLETED事件才能收到此回调。企业设备管理场景下，设备管理应用订阅设备启动完成事件，端侧系统在设备开机完成后会通知设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知企业管理员。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BOOT_COMPLETED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceBootCompleted() {
    console.info("EnterpriseAdminExtensionAbility onDeviceBootCompleted");
  }
}
```

### onBundleUpdated

onBundleUpdated(bundleName: string, accountId: number): void

应用更新事件回调，回调中包含应用包名和用户ID。通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_BUNDLE_UPDATED事件才能收到此回调。企业设备管理场景下，设备管理应用可订阅所有用户下的应用更新事件，应用更新事件触发时会通知当前用户下的设备管理应用，设备管理应用可以在此回调函数中进行事件上报，通知主用户下的企业管理员。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 被更新应用的包名。 |
| accountId | number | 是    | 被更新应用所在的用户ID。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_UPDATED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleUpdated(bundleName: string, accountId: number) {
    console.info(`Succeeded in calling onBundleUpdated callback, update bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onAdminPolicyChanged

onAdminPolicyChanged(event: common.PolicyChangedEvent): void

策略变更事件回调。超级设备管理应用可以通过接口[adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync)注册MANAGED_EVENT_POLICIES_CHANGED事件后可接收此回调。企业设备管理场景下，当任意MDM应用调用[策略变更上报列表](../../mdm/mdm-kit-appendix.md#策略变更上报列表)中的接口时，系统会通知当前用户下的超级设备管理应用。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| event | [common.PolicyChangedEvent](./js-apis-enterprise-common.md#policychangedevent) | 是    | 策略变更事件，包含策略变更的详细信息，如变更的应用包名（bundleName）、变更的函数名（functionName）、变更的参数（parameters）和变更时间（time），超级设备管理应用可根据这些信息进行策略审计或同步。 |

**示例：**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_POLICIES_CHANGED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminPolicyChanged(event: common.PolicyChangedEvent) {
    // 例如当MDM应用调用setPasswordPolicy接口设置密码策略时，输出示例为: Policy changed, bundleName : com.example.test, functionName: setPasswordPolicy, parameters: {"policy":{"complexityRegex":"^(?=.*[a-zA-Z])(?=.*\\d).{8},$","validityPeriod":1808309786000,"additionalDescription":"至少8个字符，且包含数字和字母。"}}, time: 1776773305379.
    console.info(`Policy changed, bundleName : ${event.bundleName}, functionName: ${event.functionName}, parameters: ${event.parameters}, time: ${event.time}.`);
  }
}
```