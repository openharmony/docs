# 电话子系统ChangeLog



## cl.telephony.1 call模块接口变更

VoNRState接口枚举值变更，VONR_STATE_ON 枚举值从0变为1，VONR_STATE_OFF枚举值定义为0，与布尔值保持一致，方便用户理解

**变更影响**

setVoNState接口中参数VoNRState枚举值变更，须用户使用最新枚举值调用接口。接口功能不变。

**关键的接口/组件变更**

修改前的接口原型：

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<void>): void;

/**
 * @systemapi Hide this for inner system use.
 * @since 10
 */
export enum VoNRState {
    /** Indicates the VoNR switch is on */
    VONR_STATE_ON = 0,
}
```

修改后的接口原型：

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<void>): void;

/**
 * Indicates the VoNR state.
 *
 * @enum { number }
 * @syscap SystemCapability.Telephony.CallManager
 * @systemapi Hide this for inner system use.
 * @since 10
 */
export enum VoNRState {
    /**
     * Indicates the VoNR switch is off.
     *
     * @syscap SystemCapability.Telephony.CallManager
     * @systemapi Hide this for inner system use.
     * @since 10
     */
    VONR_STATE_OFF = 0,

    /**
     * Indicates the VoNR switch is on.
     *
     * @syscap SystemCapability.Telephony.CallManager
     * @systemapi Hide this for inner system use.
     * @since 10
     */
    VONR_STATE_ON = 1,
}
```


**适配指导**

使用变更后的接口，调用时注意VONR_STATE_ON值使用最新的值。建议直接使用枚举值。示例代码如下：


```js
call.setVoNRState( 0, VONR_STATE_ON, (err) => {
    if (err) {
        console.log(`callback: err->${JSON.stringify(err)}`);
    }
    
});
call.setVoNRState( 0, VONR_STATE_OFF, (err) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## cl.telephony.2 call模块接口变更

原始设计误将set接口回调设置为布尔值，set接口回调修正为void。

**变更影响**

接口返回值/回调修复为void，请开发者注意调用方式。

**关键的接口/组件变更**

修改前的接口原型：

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<boolean>): void;
function setVoNRState(slotId: number, state: VoNRState): Promise<boolean>;

```

修改后的接口原型：

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<void>): void;
function setVoNRState(slotId: number, state: VoNRState): Promise<void>;
```

**适配指导**

使用变更后的接口，示例代码如下：

```js
call.setVoNRState( 0, VONR_STATE_ON, (err) => {
    if (err) {
        console.log(`callback: err->${JSON.stringify(err)}`);
    }
    
});
call.setVoNRState( 0, VONR_STATE_OFF, (err) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```