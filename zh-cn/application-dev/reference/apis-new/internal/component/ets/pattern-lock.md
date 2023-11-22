# pattern_lock    
图案密码锁组件，以九宫格图案的方式输入密码，用于密码验证场景。手指在PatternLock组件区域按下时开始进入输入状态，手指离开屏幕时结束输入状态完成密码输入。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## PatternLockChallengeResult<sup>(11+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CORRECT | 1 | 图案密码正确。 |  
| WRONG | 2 | 图案密码错误。 |  
    
## PatternLockController    
PatternLock组件的控制器，可以通过它进行组件状态重置。    
### reset    
重置组件状态。  
 **调用形式：**     
- reset()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### setChallengeResult<sup>(11+)</sup>    
用于设置图案密码正确或错误状态。  
 **调用形式：**     
- setChallengeResult(result: PatternLockChallengeResult): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| result | PatternLockChallengeResult | true | 图案密码状态。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- PatternLock(controller?: PatternLockController)    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| controller | PatternLockController | false | 设置PatternLock组件控制器，可用于控制组件状态重置。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| sideLength |  Length |  |  
| circleRadius |  Length |  |  
| backgroundColor |  ResourceColor |  |  
| regularColor |  ResourceColor |  |  
| selectedColor |  ResourceColor |  |  
| activeColor |  ResourceColor |  |  
| pathColor |  ResourceColor |  |  
| pathStrokeWidth |  number \| string |  |  
| autoReset |  boolean |  |  
    
### onPatternComplete<sup>(deprecated)</sup>    
onPatternComplete(callback: (input: Array<number>) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onDotConnect<sup>(deprecated)</sup>    
onDotConnect(callback: import('../api/@ohos.base').Callback<number>)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct PatternLockExample {  
  @State passwords: Number[] = []  
  @State message: string = 'please input password!'  
  private patternLockController: PatternLockController = new PatternLockController()  
  
  build() {  
    Column() {  
      Text(this.message).textAlign(TextAlign.Center).margin(20).fontSize(20)  
      PatternLock(this.patternLockController)  
        .sideLength(200)  
        .circleRadius(9)  
        .pathStrokeWidth(18)  
        .activeColor('#B0C4DE')  
        .selectedColor('#228B22')  
        .pathColor('#90EE90')  
        .backgroundColor('#F5F5F5')  
        .autoReset(true)  
        .onDotConnect((index: number) => {  
          console.log("onDotConnect index: " + index)  
        })  
        .onPatternComplete((input: Array<number>) => {  
          // 输入的密码长度小于5时，提示重新输入  
          if (input === null || input === undefined || input.length < 5) {  
            this.message = 'The password length needs to be greater than 5, please enter again.'  
            return  
          }  
          // 判断密码长度是否大于0  
          if (this.passwords.length > 0) {  
            // 判断两次输入的密码是否相同，相同则提示密码设置成功，否则提示重新输入  
            if (this.passwords.toString() === input.toString()) {  
              this.passwords = input  
              this.message = 'Set password successfully: ' + this.passwords.toString()  
              this.patternLockController.setChallengeResult(PatternLockChallengeResult.CORRECT)  
            } else {  
              this.message = 'Inconsistent passwords, please enter again.'  
              this.patternLockController.setChallengeResult(PatternLockChallengeResult.WRONG)  
            }  
          } else {  
            // 提示第二次输入密码  
            this.passwords = input  
            this.message = "Please enter again."  
          }  
        })  
      Button('Reset PatternLock').margin(30).onClick(() => {  
        // 重置密码锁  
        this.patternLockController.reset()  
        this.passwords = []  
        this.message = 'Please input password'  
      })  
    }.width('100%').height('100%')  
  }  
}  
    
```    
  
![patternlock](figures/patternlock.gif)  
