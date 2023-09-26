# Telephony Subsystem Changelog



## cl.telephony.1 VoNRState Enum Value Change of setVoNState

Changed the **VoNRState** enum values of the **setVoNState** API. The values value of **VONR_STATE_ON** is changed from **0** to **1** and that of **VONR_STATE_OFF** is defined as **0** to keep consistency with boolean values.

**Change Impact**

The new **VoNRState** enum values need to be used when **setVoNState** is called. The API function remains unchanged.

**Key API/Component Changes**

Before change:

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

After change:

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


**Adaptation Guide**

When calling **setVoNState**, use the new **VoNRState** enum values. The sample code is as follows:


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


## cl.telephony.2 Callback Value Change of setVoNState

Changed the callback value of **setVoNState** from a boolean value to **void**.

**Change Impact**

The callback value needs to be set to **void** when **setVoNState** is called.

**Key API/Component Changes**

Before change:

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<boolean>): void;
function setVoNRState(slotId: number, state: VoNRState): Promise<boolean>;

```

After change:

```js
function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback<void>): void;
function setVoNRState(slotId: number, state: VoNRState): Promise<void>;
```

**Adaptation Guide**

Set the callback value to **void** when calling **setVoNState**. The sample code is as follows:

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
