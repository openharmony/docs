# @ohos.application.AccessibilityExtensionAbility    
基于ExtensionAbility框架，提供辅助功能业务的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ElementAttributeKeys<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
## AccessibilityExtensionAbility    
辅助事件信息。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### 属性    
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | AccessibilityExtensionContext | false | true | 表示辅助扩展能力上下文。 |  
    
### onConnect    
用户启用AccessibilityExtensionAbility时，系统服务完成连接后，回调此接口，可以该方法中执行初始化业务逻辑操作。该方法可以选择性重写。  
 **调用形式：**     
- onConnect(): void  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **示例代码：**   
```ts    
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';  
  
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {  
    onConnect(): void {  
        console.log('AxExtensionAbility onConnect');  
    }  
}  
    
```    
  
    
### onDisconnect    
用户停用AccessibilityExtensionAbility时，系统服务完成断开连接后，回调此接口，可以该方法中执行资源回收退出业务逻辑操作。该方法可以选择性重写。  
 **调用形式：**     
- onDisconnect(): void  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **示例代码：**   
```ts    
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';  
  
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {  
    onDisconnect(): void {  
        console.log('AxExtensionAbility onDisconnect');  
    }  
}  
    
```    
  
    
### onAccessibilityEvent    
在关注的应用及事件类型对应的事件发生时回调此接口，可以在该方法中根据事件信息进行业务逻辑处理。一般情况下需要重写该方法完成业务。  
 **调用形式：**     
- onAccessibilityEvent(event: AccessibilityEvent): void  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | AccessibilityEvent | true | 无障碍事件回调函数。无返回值。 |  
    
 **示例代码：**   
```ts    
import AccessibilityExtensionAbility , { AccessibilityEvent } from '@ohos.application.AccessibilityExtensionAbility';  
  
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {  
    onAccessibilityEvent(event: AccessibilityEvent): void {  
        console.log('AxExtensionAbility onAccessibilityEvent');  
        if (event.eventType === 'click') {  
            console.log('AxExtensionAbility onAccessibilityEvent: click');  
        }  
    }  
}  
    
```    
  
    
### onKeyEvent    
在物理按键按下时回调此方法，可以在该方法中根据业务判断是否对事件进行拦截。  
 **调用形式：**     
- onKeyEvent(keyEvent: KeyEvent): boolean  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| keyEvent | KeyEvent | true | 按键事件回调函数。返回true表示拦截此按键。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
 **示例代码：**   
```ts    
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';  
import { KeyEvent } from '@ohos.multimodalInput.keyEvent';  
  
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {  
    onKeyEvent(keyEvent: KeyEvent): boolean {  
        console.log('AxExtensionAbility onKeyEvent');  
        if (keyEvent.key.code === 16) {  
            console.log('AxExtensionAbility onKeyEvent: intercept 16');  
            return true;  
        }  
        return false;  
    }  
}  
    
```    
  
    
## AccessibilityEvent    
辅助事件信息。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventType | accessibility.EventType \| accessibility.WindowUpdateType \| TouchGuideType \| GestureType \| PageUpdateType | false | true | 具体事件类型。<br />EventType：无障碍事件类型；<br />WindowUpdateType：窗口变化类型；TouchGuideType：触摸浏览事件类型；<br />GestureType：手势事件类型；<br />PageUpdateType：页面刷新类型，当前版本暂不支持。 |  
| target | AccessibilityElement | false | false | 发生事件的目标组件。 |  
| timeStamp | number | false | false | 事件时间戳。 |  
    
## GestureType    
手势事件类型。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| left | 类型为字符串，表示向左的手势。 |  
| leftThenRight | 类型为字符串，表示先向左再向右的手势。 |  
| leftThenUp | 类型为字符串，表示先向左再向上的手势。 |  
| leftThenDown | 类型为字符串，表示先向左再向下的手势。 |  
| right | 类型为字符串，表示向右的手势。 |  
| rightThenLeft | 类型为字符串，表示先向右再向左的手势。 |  
| rightThenUp | 类型为字符串，表示先向右再向上的手势。 |  
| rightThenDown | 类型为字符串，表示先向右再向下的手势。 |  
| up | 类型为字符串，表示向上的手势。 |  
| upThenLeft | 类型为字符串，表示先向上再向左的手势。 |  
| upThenRight | 类型为字符串，表示先向上再向右的手势。 |  
| upThenDown | 类型为字符串，表示先向上再向下的手势。 |  
| down | 类型为字符串，表示向下的手势。 |  
| downThenLeft | 类型为字符串，表示先向下再向左的手势。 |  
| downThenRight | 类型为字符串，表示先向下再向右的手势。 |  
| downThenUp | 类型为字符串，表示先向下再向上的手势。 |  
    
## PageUpdateType    
页面刷新类型；当前版本暂不支持。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| pageContentUpdate | 类型为字符串，表示页面内容刷新。 |  
| pageStateUpdate | 类型为字符串，表示页面状态刷新。 |  
    
## TouchGuideType    
触摸浏览事件类型。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| touchBegin | 类型为字符串，表示触摸浏览时开始触摸。 |  
| touchEnd | 类型为字符串，表示触摸浏览时结束触摸。 |  
