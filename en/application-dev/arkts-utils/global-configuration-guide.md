# Global Configuration Items

In scenarios where a single process instance is required, for example, global configuration item services that require data consistency between different concurrent instances, the shared module can be used.

The following example implements the service function that can be downloaded only after Wi-Fi is enabled and users log in to the system. The procedure is as follows:

1. Compile the global configuration file.

   ```ts
   // Config.ets
   
   import { ArkTSUtils } from '@kit.ArkTS';
   
   "use shared"
   
   @Sendable
   class Config {
     lock: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock
     isLogin: boolean = false;
     loginUser?: string;
     wifiOn: boolean = false
   
     async login(user: string) {
       return this.lock.lockAsync(() => {
         this.isLogin = true;
         this.loginUser = user
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async logout(user?: string) {
       return this.lock.lockAsync(() => {
         this.isLogin = false
         this.loginUser = ""
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async getIsLogin(): Promise<boolean> {
       return this.lock.lockAsync(() => {
         return this.isLogin
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   
     async getUser(): Promise<string> {
       return this.lock.lockAsync(() => {
         return this.loginUser!
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   
     async setWifiState(state: boolean) {
       return this.lock.lockAsync(() => {
         this.wifiOn = state
       }, ArkTSUtils.locks.AsyncLockMode.EXCLUSIVE)
     }
   
     async isWifiOn() {
       return this.lock.lockAsync(() => {
         return this.wifiOn;
       }, ArkTSUtils.locks.AsyncLockMode.SHARED)
     }
   }
   
   export let config = new Config()
   ```

2. The UI main thread and subthreads access global configuration items.

   ```ts
   import { config } from './Config'
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   async function download() {
     if (!await config.isWifiOn()) {
       console.info("wifi is off")
       return false;
     }
     if (!await config.getIsLogin()) {
       console.info("not login")
       return false;
     }
     console.info(`User[${await config.getUser()}] start download ...`)
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
           TextInput ({placeholder: "Please enter a user name."})
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
                 this.message = "login: " + this.input
                 config.login(this.input)
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
                 this.message = "not login"
                 config.logout()
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
               await config.setWifiState(isOn)
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
               let ret = await taskpool.execute(download)
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
