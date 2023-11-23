# @ohos.multimodalInput.pointer    
鼠标指针管理模块，用于查询和设置鼠标指针相关属性。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import pointer from '@ohos.multimodalInput.pointer'    
```  
    
## setPointerSpeed    
设置鼠标移动速度，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setPointerSpeed(speed: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setPointerSpeed(speed: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | number | true | 鼠标移动速度，范围1-11，默认为5。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setPointerSpeed(5, (error: Error) => {  
    if (error) {  
      console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set pointer speed success`);  
  });  
} catch (error) {  
  console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setPointerSpeed(5).then(() => {  
    console.log(`Set pointer speed success`);  
  });  
} catch (error) {  
  console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setPointerSpeedSync<sup>(10+)</sup>    
使用同步方式设置鼠标移动速度。  
 **调用形式：**     
- setPointerSpeedSync(speed: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | number | true | 鼠标移动速度，范围1-11，默认为5。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let speed = pointer.setPointerSpeedSync(5);  
  console.log(`Set pointer speed success`);  
} catch (error) {  
  console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerSpeed    
获取鼠标移动速度，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getPointerSpeed(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getPointerSpeed(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回鼠标移动速度。 |  
| Promise<number> | Promise实例，异步返回鼠标移动速度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getPointerSpeed((error: Error, speed: number) => {  
    if (error) {  
      console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);  
  });  
} catch (error) {  
  console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getPointerSpeed().then(speed => {  
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);  
  });  
} catch (error) {  
  console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerSpeedSync<sup>(10+)</sup>    
使用同步方式获取当前鼠标移动速度。  
 **调用形式：**     
- getPointerSpeedSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回鼠标移动速度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let speed = pointer.getPointerSpeedSync();  
  console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);  
} catch (error) {  
  console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setPointerColor<sup>(10+)</sup>    
设置鼠标光标颜色，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setPointerColor(color: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPointerColor(color: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | number | true | 鼠标光标颜色，默认为黑色：0x000000。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setPointerColor(0xF6C800, (error: Error) => {  
    if (error) {  
      console.log(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setPointerColor success`);  
  });  
} catch (error) {  
  console.log(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setPointerColor(0xF6C800).then(() => {  
    console.log(`setPointerColor success`);  
  });  
} catch (error) {  
  console.log(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setPointerColorSync<sup>(10+)</sup>    
设置鼠标光标颜色，使用同步方式进行设置。  
 **调用形式：**     
- setPointerColorSync(color: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | number | true | 鼠标光标颜色，默认为黑色：0x000000。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  pointer.setPointerColorSync(0xF6C800);  
  console.log(`setPointerColorSync success`);  
} catch (error) {  
  console.log(`setPointerColorSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerColor<sup>(10+)</sup>    
获取鼠标光标颜色，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getPointerColor(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getPointerColor(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回鼠标光标颜色。 |  
| Promise<number> | 获取当前鼠标光标颜色，使用Promise异步方式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getPointerColor((error: Error, color: number) => {  
    console.log(`getPointerColor success, color: ${JSON.stringify(color)}`);  
  });  
} catch (error) {  
  console.log(`getPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getPointerColor().then((color: number) => {  
    console.log(`getPointerColor success, color: ${JSON.stringify(color)}`);  
  });  
} catch (error) {  
  console.log(`getPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerColorSync<sup>(10+)</sup>    
获取鼠标光标颜色，使用同步方式返回结果。  
 **调用形式：**     
- getPointerColorSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 鼠标光标颜色。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```js    
try {  
  let pointerColor = pointer.getPointerColorSync();  
  console.log(`getPointerColorSync success, pointerColor: ${JSON.stringify(pointerColor)}`);  
} catch (error) {  
  console.log(`getPointerColorSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setPointerSize<sup>(10+)</sup>    
设置鼠标光标大小，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setPointerSize(size: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPointerSize(size: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 鼠标光标大小，范围为[1-7]，默认为1。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 设置鼠标光标大小，使用Promise异步方式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setPointerSize(1, (error: Error) => {  
    if (error) {  
      console.log(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setPointerSize success`);  
  });  
} catch (error) {  
  console.log(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setPointerSize(3).then(() => {  
    console.log(`setPointerSize success`);  
  });  
} catch (error) {  
  console.log(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setPointerSizeSync<sup>(10+)</sup>    
设置鼠标光标大小，使用同步方式进行设置。  
 **调用形式：**     
- setPointerSizeSync(size: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 鼠标光标大小，范围为[1-7]，默认为1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  pointer.setPointerSizeSync(5);  
  console.log(`setPointerSizeSync success`);  
} catch (error) {  
  console.log(`setPointerSizeSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerSize<sup>(10+)</sup>    
获取当前鼠标光标大小，使用Promise异步方式返回结果。  
 **调用形式：**     
    
- getPointerSize(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getPointerSize(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回鼠标光标大小。 |  
| Promise<number> | Promise对象，异步返回鼠标光标大小。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getPointerSize((error: Error, size: number) => {  
    console.log(`getPointerSize success, size: ${JSON.stringify(size)}`);  
  });  
} catch (error) {  
  console.log(`getPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getPointerSize().then((size: number) => {  
    console.log(`getPointerSize success, size: ${JSON.stringify(size)}`);  
  });  
} catch (error) {  
  console.log(`getPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getPointerSizeSync<sup>(10+)</sup>    
获取鼠标光标大小，使用同步方式返回结果。  
 **调用形式：**     
- getPointerSizeSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 鼠标光标大小。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```null    
try {  
  let pointerSize = pointer.getPointerSizeSync();  
  console.log(`getPointerSizeSync success, pointerSize: ${JSON.stringify(pointerSize)}`);  
} catch (error) {  
  console.log(`getPointerSizeSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setMousePrimaryButton<sup>(10+)</sup>    
设置鼠标主键，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setMousePrimaryButton(primary: PrimaryButton): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| primary | PrimaryButton | true | 鼠标主键id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setMousePrimaryButton(pointer.PrimaryButton.RIGHT, (error: Error) => {  
    if (error) {  
      console.log(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set mouse primary button success`);  
  });  
} catch (error) {  
  console.log(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setMousePrimaryButton(pointer.PrimaryButton.RIGHT).then(() => {  
    console.log(`Set mouse primary button success`);  
  });  
} catch (error) {  
  console.log(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getMousePrimaryButton<sup>(10+)</sup>  
 **调用形式：**     
    
- getMousePrimaryButton(callback: AsyncCallback\<PrimaryButton>): void    
起始版本： 10    
- getMousePrimaryButton(): Promise\<PrimaryButton>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<PrimaryButton> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getMousePrimaryButton((error: Error, primary: pointer.PrimaryButton) => {  
    console.log(`Get mouse primary button success, primary: ${JSON.stringify(primary)}`);  
  });  
} catch (error) {  
  console.log(`Get mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getMousePrimaryButton().then((primary: pointer.PrimaryButton) => {  
    console.log(`Get mouse primary button success, primary: ${JSON.stringify(primary)}`);  
  });  
} catch (error) {  
  console.log(`Get mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setHoverScrollState<sup>(10+)</sup>    
设置鼠标悬停滚动开关状态，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setHoverScrollState(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setHoverScrollState(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | 鼠标悬停滚动开关状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setHoverScrollState(true, (error: Error) => {  
    if (error) {  
      console.log(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set the mouse hover scroll success`);  
  });  
} catch (error) {  
  console.log(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setHoverScrollState(true).then(() => {  
    console.log(`Set the mouse hover scroll success`);  
  });  
} catch (error) {  
  console.log(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getHoverScrollState<sup>(10+)</sup>    
设置鼠标悬停滚动开关状态，使用Promise异步方式返回结果。  
 **调用形式：**     
    
- getHoverScrollState(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getHoverScrollState(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getHoverScrollState((error: Error, state: boolean) => {  
    console.log(`Get the mouse hover scroll success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`Get the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getHoverScrollState().then((state: boolean) => {  
    console.log(`Get the mouse hover scroll success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`Get the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setMouseScrollRows<sup>(10+)</sup>    
设置鼠标滚动行数，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setMouseScrollRows(rows: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setMouseScrollRows(rows: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rows | number | true | 鼠标滚动行数，范围1-100，默认为3。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setMouseScrollRows(1, (error: Error) => {  
    if (error) {  
      console.log(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setMouseScrollRows success`);  
  });  
} catch (error) {  
  console.log(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setMouseScrollRows(20).then(() => {  
    console.log(`setMouseScrollRows success`);  
  });  
} catch (error) {  
  console.log(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getMouseScrollRows<sup>(10+)</sup>    
设置鼠标滚动行数，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getMouseScrollRows(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getMouseScrollRows(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<number> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getMouseScrollRows((error: Error, rows: number) => {  
    console.log(`getMouseScrollRows success, rows: ${JSON.stringify(rows)}`);  
  });  
} catch (error) {  
  console.log(`getMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getMouseScrollRows().then((rows: number) => {  
    console.log(`getMouseScrollRows success, rows: ${JSON.stringify(rows)}`);  
  });  
} catch (error) {  
  console.log(`getMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadScrollSwitch<sup>(10+)</sup>    
获取触控板滚轴能力开启状态，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadScrollSwitch(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadScrollSwitch(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | 鼠标滚动行数，范围1-100，默认为3。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadScrollSwitch(true, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadScrollSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadScrollSwitch(false).then(() => {  
    console.log(`setTouchpadScrollSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadScrollSwitch<sup>(10+)</sup>    
获取触控板滚轴能力开启状态，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getTouchpadScrollSwitch(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getTouchpadScrollSwitch(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回触控板滚轴能力开启状态。 |  
| Promise<boolean> | Promise实例，异步返回触控板滚轴能力开启状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadScrollSwitch((error: Error, state: boolean) => {  
    console.log(`getTouchpadScrollSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadScrollSwitch().then((state) => {  
    console.log(`getTouchpadScrollSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadScrollDirection<sup>(10+)</sup>    
设置触控板滚轴的方向，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadScrollDirection(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadScrollDirection(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | state为触控板滚轴的方向。true与手指滑动的方向一致，false与手指滑动的方向相反，默认为true。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadScrollDirection(true, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadScrollDirection success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadScrollDirection (false).then(() => {  
    console.log(`setTouchpadScrollDirection success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadScrollDirection<sup>(10+)</sup>    
设置触控板滚轴的方向，使用Promise异步方式返回结果。  
 **调用形式：**     
    
- getTouchpadScrollDirection(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getTouchpadScrollDirection(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回触控板滚轴方向。 |  
| Promise<boolean> | 设置触控板滚轴的方向，使用Promise异步方式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadScrollDirection ((error: Error, state: boolean) => {  
    console.log(`getTouchpadScrollDirection success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadScrollDirection().then((state: boolean) => {  
    console.log(`getTouchpadScrollDirection success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadTapSwitch<sup>(10+)</sup>    
设置触控板轻触功能开关，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadTapSwitch(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadTapSwitch(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | 触控板轻触功能开关开启状态。 true代表轻触开启，false代表轻触关闭，默认开启。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadTapSwitch(true, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadTapSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadTapSwitch(false).then(() => {  
    console.log(`setTouchpadTapSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadTapSwitch<sup>(10+)</sup>  
 **调用形式：**     
    
- getTouchpadTapSwitch(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getTouchpadTapSwitch(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadTapSwitch((error: Error, state: boolean) => {  
    console.log(`getTouchpadTapSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadTapSwitch().then((state: boolean) => {  
    console.log(`getTouchpadTapSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadPointerSpeed<sup>(10+)</sup>    
设置触控板光标移动速度，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadPointerSpeed(speed: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadPointerSpeed(speed: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| speed | number | true | speed代表光标移动速度。speed取值范围[1,11]，默认5。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadPointerSpeed(1, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadPointerSpeedfailed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadPointerSpeed success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadPointerSpeed(10).then(() => {  
    console.log(`setTouchpadPointerSpeed success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadPointerSpeed<sup>(10+)</sup>  
 **调用形式：**     
    
- getTouchpadPointerSpeed(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getTouchpadPointerSpeed(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadPointerSpeed((error: Error, speed: number) => {  
    console.log(`getTouchpadPointerSpeed success, speed: ${JSON.stringify(speed)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadPointerSpeed().then((speed: number) => {  
    console.log(`getTouchpadPointerSpeed success, speed: ${JSON.stringify(speed)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadPinchSwitch<sup>(10+)</sup>    
设置触控板双指捏合功能开关，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadPinchSwitch(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadPinchSwitch(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | 触控板双指捏合功能开关开启状态。 true代表开启，false代表关闭，默认开启。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadTapSwitch(true, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadPinchSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadPinchSwitch(false).then(() => {  
    console.log(`setTouchpadPinchSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadPinchSwitch<sup>(10+)</sup>  
 **调用形式：**     
    
- getTouchpadPinchSwitch(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getTouchpadPinchSwitch(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadPinchSwitch((error: Error, state: boolean) => {  
    console.log(`getTouchpadPinchSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadPinchSwitch().then((state: boolean) => {  
    console.log(`getTouchpadPinchSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadSwipeSwitch<sup>(10+)</sup>    
设置触控板双指捏合功能开关，使用Promise异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadSwipeSwitch(state: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadSwipeSwitch(state: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | boolean | true | 触控板双指捏合功能开关开启状态。 true代表开启，false代表关闭，默认开启。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.setTouchpadSwipeSwitch(true, (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadSwipeSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadSwipeSwitch(false).then(() => {  
    console.log(`setTouchpadSwipeSwitch success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadSwipeSwitch<sup>(10+)</sup>  
 **调用形式：**     
    
- getTouchpadSwipeSwitch(callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getTouchpadSwipeSwitch(): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadSwipeSwitch((error: Error, state: boolean) => {  
    console.log(`getTouchpadSwipeSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadSwipeSwitch().then((state: boolean) => {  
    console.log(`getTouchpadSwipeSwitch success, state: ${JSON.stringify(state)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setTouchpadRightClickType<sup>(10+)</sup>    
设置触控板右键菜单类型，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setTouchpadRightClickType(type: RightClickType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setTouchpadRightClickType(type: RightClickType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | RightClickType | true | type代表触控板右键菜单类型。<br>- TOUCHPAD_RIGHT_BUTTON：触控板右键区域。<br>- TOUCHPAD_LEFT_BUTTON：触控板左键区域。<br>- TOUCHPAD_TWO_FINGER_TAP：双指轻击或按压触控板。<br>默认为TOUCHPAD_RIGHT_BUTTON 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）  
```js    
try {  
  pointer.setTouchpadRightClickType(pointer.RightClickType.TOUCHPAD_RIGHT_BUTTON , (error: Error) => {  
    if (error) {  
      console.log(`setTouchpadRightClickType, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`setTouchpadRightClickType success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.setTouchpadRightClickType(pointer.RightClickType.TOUCHPAD_RIGHT_BUTTON).then(() => {  
    console.log(`setTouchpadRightClickType success`);  
  });  
} catch (error) {  
  console.log(`setTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getTouchpadRightClickType<sup>(10+)</sup>    
设置触控板右键菜单类型，使用Promise异步方式返回结果。  
 **调用形式：**     
    
- getTouchpadRightClickType(callback: AsyncCallback\<RightClickType>): void    
起始版本： 10    
- getTouchpadRightClickType(): Promise\<RightClickType>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Pointer    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | type代表触控板右键菜单类型。<br>- TOUCHPAD_RIGHT_BUTTON：触控板右键区域。<br>- TOUCHPAD_LEFT_BUTTON：触控板左键区域。<br>- TOUCHPAD_TWO_FINGER_TAP：双指轻击或按压触控板。<br>默认为TOUCHPAD_RIGHT_BUTTON 。 |  
| Promise<RightClickType> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  pointer.getTouchpadRightClickType((error: Error, type: pointer.RightClickType) => {  
    console.log(`getTouchpadRightClickType success, type: ${JSON.stringify(type)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  pointer.getTouchpadRightClickType().then((type: pointer.RightClickType) => {  
    console.log(`getTouchpadRightClickType success, typeed: ${JSON.stringify(type)}`);  
  });  
} catch (error) {  
  console.log(`getTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
