# save_button    
安全控件的保存控件，用户通过点击该保存按钮，可以临时获取存储权限，而不需要权限弹框授权确认。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SaveIconStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FULL_FILLED | 0 | 保存按钮展示填充样式图标。 |  
| LINES | 1 | 保存按钮展示线条样式图标。 |  
    
## SaveDescription    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DOWNLOAD | 0 | 保存按钮的文字描述为“下载”。 |  
| DOWNLOAD_FILE | 1 | 保存按钮的文字描述为“下载文件”。 |  
| SAVE | 2 | 保存按钮的文字描述为“保存”。 |  
| SAVE_IMAGE | 3 | 保存按钮的文字描述为“保存图片”。 |  
| SAVE_FILE | 4 | 保存按钮的文字描述为“保存文件”。 |  
| DOWNLOAD_AND_SHARE | 5 | 保存按钮的文字描述为“下载分享”。 |  
| RECEIVE | 6 | 保存按钮的文字描述为“接收”。 |  
| CONTINUE_TO_RECEIVE | 7 | 保存按钮的文字描述为“继续接收”。 |  
    
## SaveButtonOptions    
创建包含指定元素的保存按钮。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| icon | SaveIconStyle | false | false | 设置保存按钮的图标风格<br/>不传入该参数表示没有图标，icon和text至少存在一个。<br/> |  
| text | SaveDescription | false | false | 设置保存按钮的文本描述<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。<br/> |  
| buttonType | ButtonType | false | false | 设置保存按钮的背景样式<br/>不传入该参数表示没有背景。<br/> |  
    
## SaveButtonOnClickResult    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 保存按钮点击成功。 |  
| TEMPORARY_AUTHORIZATION_FAILED | 1 | 保存按钮点击后权限授权失败。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- SaveButton()    
起始版本： 10    
    
- SaveButton(options: SaveButtonOptions)    
起始版本： 10    
### onClick<sup>(deprecated)</sup>    
onClick(event: (event: ClickEvent, result: SaveButtonOnClickResult) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ClickEvent, result: SaveButtonOnClickResult) => void | true | 见ClickEvent对象说明。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import photoAccessHelper from '@ohos.file.photoAccessHelper';  
import fs from '@ohos.file.fs';  
  
@Entry  
@Component  
struct Index {  
  build() {  
    Row() {  
      Column({space:10}) {  
        // 默认参数下，图标、文字、背景都存在  
        SaveButton().onClick(async (event:ClickEvent, result:SaveButtonOnClickResult) => {  
          if (result == SaveButtonOnClickResult.SUCCESS) {  
            try {  
              const context = getContext(this);  
              let helper = photoAccessHelper.getPhotoAccessHelper(context);  
              // onClick触发后5秒内通过createAsset接口创建图片文件，5秒后createAsset权限收回。  
              let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'png');  
              // 使用uri打开文件，可以持续写入内容，写入过程不受时间限制  
              let file = await fs.open(uri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
              // 写入文件  
              await fs.write(file.fd, "context");  
              // 关闭文件  
              await fs.close(file.fd);  
            } catch (error) {  
              console.error("error is "+ JSON.stringify(error));  
            }  
          }  
        })  
        // 传入参数即表示元素存在，不传入的参数表示元素不存在，例如：只显示图标  
        SaveButton({icon:SaveIconStyle.FULL_FILLED})  
        // 只显示图标+背景  
        SaveButton({icon:SaveIconStyle.FULL_FILLED, buttonType:ButtonType.Capsule})  
        // 图标、文字、背景都存在  
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})  
      }.width('100%')  
    }.height('100%')  
  }  
}  
    
```    
  
![zh-cn_image_0000001643320073](figures/zh-cn_image_0000001643320073.png)  
