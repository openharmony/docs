# 全局配置项功能场景

对于需要使用进程单例的场景，例如不同并发实例间需要数据保持一致的全局配置项功能，可以采用共享模块来实现。

以下示例展示了只有在Wi-Fi打开且用户登录的情况下才能进行下载的功能，具体步骤如下。

1. 编写全局配置文件。

   ```ts
   // Config.ets
   
   import { ArkTSUtils } from '@kit.ArkTS';
   
   "use shared"
   
   @Sendable
   class Config {
     lock: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
     isLogin: boolean = false;
     loginUser?: string;
     wifiOn: boolean = false;
   
     async login(user: string) {
       return this.lock.lockAsync(() => {
         this.isLogin = true;
         this.loginUser = user;
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async logout(user?: string) {
       return this.lock.lockAsync(() => {
         this.isLogin = false;
         this.loginUser = "";
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async getIsLogin(): Promise<boolean> {
       return this.lock.lockAsync(() => {
         return this.isLogin;
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   
     async getUser(): Promise<string> {
       return this.lock.lockAsync(() => {
         return this.loginUser!;
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   
     async setWifiState(state: boolean) {
       return this.lock.lockAsync(() => {
         this.wifiOn = state;
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async isWifiOn() {
       return this.lock.lockAsync(() => {
         return this.wifiOn;
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   }
   
   export let config = new Config();
   ```
   <!-- @[global_config](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/Config.ets) -->

2. UI主线程及子线程访问全局配置项。

   ```ts
   // Index.ets
   import { config } from './Config';
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   async function download() {
     if (!await config.isWifiOn()) {
       console.info("wifi is off");
       return false;
     }
     if (!await config.getIsLogin()) {
       console.info("not login");
       return false;
     }
     console.info(`User[${await config.getUser()}] start download ...`);
     return true;
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'not login';
     @State wifiState: string = "wifi off";
     @State downloadResult: string = "";
     input: string = ""
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
           TextInput({ placeholder: "请输入用户名" })
             .fontSize(20)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onChange((value) => {
               this.input = value;
             })
           Text("login")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               if (!await config.getIsLogin() && this.input) {
                 this.message = "login: " + this.input;
                 config.login(this.input);
               }
             })
             .backgroundColor(0xcccccc)
           Text("logout")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               if (await config.getIsLogin()) {
                 this.message = "not login";
                 config.logout();
               }
             })
             .backgroundColor(0xcccccc)
           Text(this.wifiState)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
           Toggle({ type: ToggleType.Switch })
             .onChange(async (isOn: boolean) => {
               await config.setWifiState(isOn);
               this.wifiState = isOn ? "wifi on" : "wifi off";
             })
           Text("download")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               let ret = await taskpool.execute(download);
               this.downloadResult = ret ? "download success" : "download fail";
             })
           Text(this.downloadResult)
             .fontSize(20)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!-- @[access_global_config](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/GlobalConfigurationGuide.ets) -->
