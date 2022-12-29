# 使用显式Want启动Ability


在应用使用场景中，当用户点击某个按钮时，应用经常需要拉起指定UIAbility组件来完成某些特定任务。下面介绍如何通过显式Want拉起应用内一个指定UIAbility组件。


## 开发步骤

1. Stage模型工程内，创建一个Ability（此示例内命名为callerAbility）与相应Page（此示例中名为Index.ets），并在callerAbility.ts文件内的onWindowStageCreate函数内通过windowStage.loadContent()方法将两者绑定。
   
   ```ts
   // ...
       // callerAbility.ts
       onWindowStageCreate(windowStage) {
           // Main window is created, set main page for this ability
           console.info('[Demo] EntryAbility onWindowStageCreate')
           // Bind callerAbility with a paged named Index
           windowStage.loadContent('pages/Index')
       }
   // ...
   ```

2. 同上方法再创建一个Ability，此示例内命名为“calleeAbility”。

3. 在callerAbility的“Index.ets”页面内新增一个按钮。
   
   ```ts
   // ...
     build() {
       Row() {
         Column() {
           Text('hello')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           // A new button with will call explicitStartAbility() when clicked.
           Button("CLICKME")
           .onClick(this.explicitStartAbility) // explicitStartAbility见下面示例代码
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   // ...
   ```

4. 补充相对应的onClick方法，并使用**显式Want**在方法内启动calleeAbility。bundleName字段可在工程AppScope&gt;app.json5文件内获取；abilityName可在对应模块内的“yourModuleName &gt; src &gt; main &gt; module.json5”文件查看。
   
   ```ts
   import common from '@ohos.app.ability.common';
   
   // ...
     async explicitStartAbility() {
       try {
         // Explicit want with abilityName specified.
         let want = {
           deviceId: "",
           bundleName: "com.example.myapplication",
           abilityName: "calleeAbility"
         };
         let context = getContext(this) as common.UIAbilityContext;
         await context.startAbility(want);
         console.info(`explicit start ability succeed`);
       } catch (error) {
         console.info(`explicit start ability failed with ${error.code}`);
       }
     }
   // ...
   ```

5. 至此，当您点击CLICKME按钮时，应看到页面的跳转。
   <img src="figures/startAbilityWtExplicitWant.PNG" alt="startAbilityWtExplicitWant" style="zoom: 80%;" />
