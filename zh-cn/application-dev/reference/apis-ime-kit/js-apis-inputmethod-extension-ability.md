# @ohos.InputMethodExtensionAbility (InputMethodExtensionAbility)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

@ohos.InputMethodExtensionAbility模块提供输入法ExtensionAbility的基础类定义，是开发输入法应用的入口和生命周期管理框架。

本模块是输入法ExtensionAbility的核心类模块，定义了`InputMethodExtensionAbility`类，作为输入法应用的Extension基类。开发者需继承该类并实现`onCreate`和`onDestroy`生命周期回调，系统在拉起和销毁输入法Extension时自动调用这些回调。

本模块提供两大核心能力：1）通过`onCreate(want)`回调实现输入法应用的初始化——系统拉起输入法Extension时调用，开发者在此完成资源加载、面板创建等初始化工作；2）通过`onDestroy()`回调实现输入法应用的资源清理——系统销毁输入法Extension时调用，开发者在此释放资源。此外，通过`context`属性提供`InputMethodExtensionContext`上下文对象，供开发者在生命周期内执行销毁自身、拉起其他应用等上下文级操作。

当开发输入法应用时必须使用本模块。开发者通过继承`InputMethodExtensionAbility` → 在module.json5中配置ExtensionAbility信息 → 系统拉起时触发`onCreate`（初始化） → 系统销毁或开发者主动调用`context.destroy()`时触发`onDestroy`（清理）。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
> `InputMethodExtensionAbility`仅定义了基础的`onCreate`和`onDestroy`两个生命周期回调。输入法的核心交互能力（如面板创建/销毁、键盘事件监听、客户端绑定等）需在`onCreate`回调中通过`@ohos.inputMethodEngine`模块获取`InputMethodAbility`对象来实现。`onCreate`是所有关键对象获取和面板创建的唯一入口，必须在该回调中完成初始化。

| Class | 说明 |
|---|---|
| InputMethodExtensionAbility | 输入法ExtensionAbility基类，提供输入法应用的生命周期管理框架。关键成员包括：`context`属性（`InputMethodExtensionContext`上下文对象）、`onCreate(want)`方法（初始化回调）、`onDestroy()`方法（销毁回调）。开发者需继承此类并重写生命周期方法。 |

> **说明：**
>
> `InputMethodExtensionAbility`的`context`属性类型为`InputMethodExtensionContext`（来自`@ohos.InputMethodExtensionContext`模块），属于关联关系——`InputMethodExtensionAbility`拥有`InputMethodExtensionContext`的上下文能力。

本模块的`InputMethodExtensionAbility`是输入法应用开发的起点，其生命周期回调与多个IME Kit模块的API组合使用，形成完整的输入法应用初始化流程。

```javascript
// 以下为阐述调用逻辑的伪代码

// 1. 继承InputMethodExtensionAbility创建输入法Extension类
class InputMethodExt extends InputMethodExtensionAbility {

  // 2. 在onCreate中初始化输入法应用
  onCreate(want) {
    // 获取上下文对象
    let context = this.context;

    // 获取输入法核心能力对象（@ohos.inputMethodEngine模块）
    // let ability = inputMethodEngine.getInputMethodAbility();

    // 创建输入法面板（@ohos.inputMethodEngine模块）
    // let panelInfo = { type: PanelType.SOFT_KEYBOARD, flag: PanelFlag.FLAG_FIXED };
    // let panel = ability.createPanel(context, panelInfo);
  }

  // 3. 在onDestroy中清理资源
  onDestroy() {
    // 销毁面板、释放资源
  }
}
```

> **说明：**
>
> `InputMethodExtensionAbility`仅定义了基础的`onCreate`和`onDestroy`两个生命周期回调。输入法的核心交互能力（如面板创建/销毁、键盘事件监听、客户端绑定等）需在`onCreate`中通过`@ohos.inputMethodEngine`模块获取`InputMethodAbility`对象来实现。`onCreate`是输入法应用初始化的核心入口，所有关键对象的获取和面板创建均应在此回调中完成。

## 约束限制

为保障系统安全性和稳定性，防止InputMethodExtensionAbility滥用系统资源，系统对其能力进行管控，不支持部分模块的引用，详情请参考[附录](#附录)。

另外输入法应用区分基础模式和完整体验模式，关于基础模式和完整体验模式说明如下：

**基础模式介绍：**
基础模式下，输入法扩展（InputMethodExtensionAbility）进程无法拉起其他UIAbility或ExtensionAbility。

基础模式下，输入法扩展会受到系统管控，不能使用涉及访问或泄露用户个人数据的各种接口，同时无法将数据传递出进程。管控功能包括但不限于：网络、短信、电话、麦克风、定位、相机、蓝牙、壁纸、支付、日历、游戏、扬声器、Wi-Fi、剪切板、多媒体、联系人、公共事件、系统账号、健康数据、地图服务、推送服务、融合搜索、共享内存、分布式特性、广告设备标识、振动等。

基础模式下，输入法扩展可以使用基础输入功能必要的系统能力，例如，IME Kit、ArkUI、窗口、图形、屏幕管理等。

基础模式下，输入法扩展对共享沙箱只读，对输入法扩展独立沙箱可读写；应用主入口可以对共享沙箱及其独立沙箱读写。

**完整体验模式介绍：**

完整体验模式下，输入法扩展不受基础模式相关限制，例如可以拉起其他UIAbility或ExtensionAbility、可以调用访问用户数据的接口等。

完整体验模式下，输入法扩展可以对共享沙箱读写。

## 导入模块

```ts
import { InputMethodExtensionAbility } from '@kit.IMEKit';
```

## InputMethodExtensionAbility

输入法ExtensionAbility类，提供了输入法应用的核心能力，支持开发者创建输入法应用。

下列API均需通过继承`InputMethodExtensionAbility`创建子类后，在子类中重写或使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [InputMethodExtensionContext](js-apis-inputmethod-extension-context.md) | 否 | 否 | InputMethodExtensionAbility的上下文环境，继承于ExtensionContext。 |

context参数使用建议：

- 含义/功能：提供`InputMethodExtensionContext`上下文对象，用于执行输入法应用上下文级操作，包括销毁自身（`destroy()`）和拉起其他应用（`startAbility()`）。
- 使用场景：当输入法应用需要主动终止自身运行或拉起目标应用时使用`context`属性。`context`在`onCreate`回调触发后即可使用。
- 使用后效果：通过`context.destroy()`可销毁当前ExtensionAbility；通过`context.startAbility(want)`可拉起目标应用。
- 前提条件：`context`由系统在创建`InputMethodExtensionAbility`实例时自动赋值，开发者无需手动创建。`context`仅在ExtensionAbility生命周期内有效，`onDestroy`回调执行后`context`将不可用。
- 相关接口间的配合/制约关系：`context`需配合`@ohos.inputMethodEngine`模块使用——在`onCreate`回调中，`context`作为`InputMethodAbility.createPanel()`的参数传入，用于创建输入法面板。

### onCreate

onCreate(want: Want): void

生命周期回调，在拉起输入法Extension时调用，用于初始化输入法应用。

- 含义/功能：系统拉起输入法ExtensionAbility时触发的初始化回调。开发者在该回调中完成输入法应用的所有关键初始化工作，包括获取核心能力对象、创建输入法面板、订阅事件等。
- 使用场景：当系统根据module.json5配置拉起输入法ExtensionAbility时自动触发。这是输入法应用初始化的唯一入口，所有关键对象的获取和面板创建必须在此回调中完成。
- 使用后效果：回调执行完成后，输入法应用进入正常运行状态。系统将随后触发键盘显示/隐藏请求、客户端绑定等事件，输入法应用需在此之前完成初始化（如已订阅`on('inputStart')`事件、已创建面板等），否则后续事件可能无法正常响应。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 当前Extension相关的Want类型信息，包括Ability名称、bundle名称等。 |

want参数使用建议：

- 含义/功能：系统传递给`onCreate`回调的Want信息，描述当前ExtensionAbility的启动信息。
- 使用场景：开发者可通过want获取启动参数（如abilityName、bundleName等），用于判断启动场景或获取配置参数。
- 取值范围：Want对象包含多种类型的属性，常见属性如abilityName、bundleName等为string类型。want中包含的abilityName和bundleName与module.json5中配置的值一致。
- 注意事项：want参数由系统自动传入，开发者无需手动构造。

注意事项：

- 前提条件：`onCreate`是输入法应用初始化的核心入口。必须在`onCreate`中完成以下关键初始化工作：
  1. 通过`inputMethodEngine.getInputMethodAbility()`获取`InputMethodAbility`实例。
  2. 通过`inputMethodEngine.getKeyboardDelegate()`获取`KeyboardDelegate`实例。
  3. 订阅`on('inputStart')`事件以接收编辑框绑定通知。
  4. 创建输入法面板（`InputMethodAbility.createPanel(this.context, panelInfo)`），注意`this.context`参数必须传入。
  5. 订阅其他必要事件（如`on('keyboardShow')`、`on('setSubtype')`等）。
- 开发建议：建议将面板创建和事件订阅集中放在`onCreate`中完成，避免在其他时机初始化导致事件遗漏或面板创建失败。

相关接口间的配合/制约关系：`onCreate`需配合以下接口使用：
- `inputMethodEngine.getInputMethodAbility()`：获取输入法能力对象。
- `inputMethodEngine.getKeyboardDelegate()`：获取键盘代理对象。
- `InputMethodAbility.createPanel(this.context, panelInfo)`：创建面板时必须使用`onCreate`中可获取的`this.context`作为参数。
- `InputMethodAbility.on('inputStart')`：必须在`onCreate`中订阅，否则后续编辑框绑定事件无法接收。

**示例：**

```ts
import { InputMethodExtensionAbility, InputMethodAbility, KeyboardDelegate, PanelInfo, PanelType, PanelFlag, inputMethodEngine } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';

class InputMethodExt extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    console.info(`onCreate, want: ${want.abilityName}`);

    // 获取输入法能力对象
    let ability: InputMethodAbility = inputMethodEngine.getInputMethodAbility();

    // 获取键盘代理对象
    let keyboardDelegate: KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();

    // 创建面板
    let panelInfo: PanelInfo = {
      type: PanelType.SOFT_KEYBOARD,
      flag: PanelFlag.FLG_FIXED
    };
    ability.createPanel(this.context, panelInfo, (err, panel) => {
      if (err) {
        console.error(`Failed to create panel: ${err.code}`);
        return;
      }
      console.info('Succeeded in creating panel.');
    });

    // 订阅输入法绑定事件
    ability.on('inputStart', (kbController, inputClient) => {
      console.info('Input method bound to client.');
    });
  }
}
```

### onDestroy

onDestroy(): void

生命周期回调，在销毁输入法应用时调用，用于资源清理。

- 含义/功能：系统销毁输入法ExtensionAbility时触发的清理回调。开发者在该回调中释放面板、取消事件订阅等资源清理工作。
- 使用场景：当系统主动销毁输入法ExtensionAbility（如系统回收资源、用户切换到其他输入法）或开发者主动调用`context.destroy()`触发销毁时自动触发。
- 使用后效果：回调执行完成后，输入法ExtensionAbility进程终止，所有资源应已释放。调用后再进行其他操作将不起效。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**注意事项：**

- 开发建议：建议在`onDestroy`中完成以下清理工作：
  1. 销毁已创建的面板（`InputMethodAbility.destroyPanel(panel)`）。
  2. 取消所有事件订阅（`InputMethodAbility.off('inputStart')`等）。
  3. 释放其他应用资源（如缓存数据、定时器等）。
- 开发建议：未在`onDestroy`中正确销毁面板可能导致面板资源泄漏，影响系统资源使用。

相关接口间的配合/制约关系：`onDestroy`需配合以下接口使用：
- `InputMethodAbility.destroyPanel(panel)`：销毁在`onCreate`中创建的面板，必须与`createPanel`配对调用。
- `InputMethodAbility.off('inputStart')`等：取消在`onCreate`中订阅的事件。
- `context.destroy()`：开发者主动调用`context.destroy()`会触发系统执行`onDestroy`回调。

**示例：**

```ts
import { InputMethodExtensionAbility } from '@kit.IMEKit';

class InputMethodExt extends InputMethodExtensionAbility {
  onDestroy(): void {
    // 销毁面板、取消事件订阅等清理工作
    console.info('onDestroy');
  }
}
```
## 附录

InputMethodExtensionAbility不支持以下模块的引用。
| Kit | 模块 |
| -------- | -------- |
| Ability Kit |  [@ohos.ability.featureAbility (FeatureAbility模块)](../apis-ability-kit/js-apis-ability-featureAbility.md)</br>[@ohos.ability.particleAbility (ParticleAbility模块)](../apis-ability-kit/js-apis-ability-particleAbility.md) |
| Background Tasks Kit |  [@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)</br>[@ohos.reminderAgentManager (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)</br> [@ohos.reminderAgent (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md) |
| Basic Services Kit | [@ohos.account.osAccount (系统账号管理)](../apis-basic-services-kit/js-apis-osAccount.md)</br>[@ohos.account.distributedAccount (分布式账号管理)](../apis-basic-services-kit/js-apis-distributed-account.md)</br>[@ohos.wallpaper (壁纸)](../apis-basic-services-kit/js-apis-wallpaper.md) |
| Connectivity Kit |  [@ohos.bluetooth (蓝牙)](../apis-connectivity-kit/js-apis-bluetooth.md)</br>[@ohos.bluetoothManager (蓝牙)](../apis-connectivity-kit/js-apis-bluetoothManager.md)</br>[nfctech (标准NFC-Tag Nfc 技术)](../apis-connectivity-kit/js-apis-nfctech.md)</br>[@ohos.nfc.controller (标准NFC)](../apis-connectivity-kit/js-apis-nfcController.md)</br>[@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../apis-connectivity-kit/js-apis-cardEmulation.md)</br>[@ohos.connectedTag (有源标签)](../apis-connectivity-kit/js-apis-connectedTag.md)</br>[@ohos.wifiext (WLAN扩展接口)](../apis-connectivity-kit/js-apis-wifiext.md)</br>[@ohos.wifiManager (WLAN)](../apis-connectivity-kit/js-apis-wifiManager.md)</br>[@ohos.wifiManagerExt (WLAN扩展接口)](../apis-connectivity-kit/js-apis-wifiManagerExt.md)</br>[tagSession (标准NFC-Tag TagSession)](../apis-connectivity-kit/js-apis-tagSession.md)</br> |
| Location Kit | [@ohos.geolocation (位置服务)](../apis-location-kit/js-apis-geolocation.md)</br>[@ohos.geoLocationManager (位置服务)](../apis-location-kit/js-apis-geoLocationManager.md) |
| Telephony Kit | [@ohos.telephony.call (拨打电话)](../apis-telephony-kit/js-apis-call.md)</br>[@ohos.telephony.data (蜂窝数据)](../apis-telephony-kit/js-apis-telephony-data.md)</br>[@ohos.telephony.observer (observer)](../apis-telephony-kit/js-apis-observer.md)</br>[@ohos.telephony.radio (网络搜索)](../apis-telephony-kit/js-apis-radio.md)</br>[@ohos.telephony.sms (短信服务)](../apis-telephony-kit/js-apis-sms.md)</br>[@ohos.telephony.sim (SIM卡管理)](../apis-telephony-kit/js-apis-sim.md) |