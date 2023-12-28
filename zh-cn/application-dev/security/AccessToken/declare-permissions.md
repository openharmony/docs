# 声明权限


应用在申请权限时，需要在项目的配置文件中，逐个声明需要的权限，否则应用将无法获取授权。


应用需要在module.json5配置文件的[requestPermissions](../../quick-start/module-configuration-file.md#requestpermissions标签)标签中声明权限。


| 属性 | 说明 | 取值范围 | 
| -------- | -------- | -------- |
| name | 必须，填写需要使用的权限名称。 | 需为系统已定义的权限，取值范围请参考[应用权限列表](permissions-for-all.md)。 | 
| reason | 可选，当申请的权限为user_grant权限时此字段必填，用于描述申请权限的原因。<br/>**说明：**<br/>该字段用于应用上架校验，当申请的权限为user_grant权限时必填，并且需要进行多语种适配。 | 使用string类资源引用。格式为$string: \*\*\*。<br/>可参考[权限使用理由的文案内容规范](#权限使用理由的文案内容规范)。 | 
| usedScene | 可选，当申请的权限为user_grant权限时此字段必填。描述权限使用的场景由abilities和when组成。其中abilities可以配置为多个UIAbility组件，when表示调用时机。<br/>**说明：**<br/>默认为可选，当申请的权限为user_grant权限时，abilities标签必填，when标签可选。 | abilities：UIAbility或者ExtensionAbility组件的名称。<br/>when：inuse（使用时）、always（始终）。 | 


```json
{
  "module" : {
    // ...
    "requestPermissions":[
      {
        "name" : "ohos.permission.PERMISSION1",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.PERMISSION2",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
```


## 权限使用理由的文案内容规范

当申请的权限为user_grant权限时，字段reason（申请权限的原因）必填。开发者需要在应用配置文件中，配置每一个需要使用的权限。

但在实际向用户弹窗申请授权时，user_grant权限将会以[权限组](app-permission-mgmt-overview.md#权限组和子权限)的形式向用户申请。当前支持的权限组请查看[应用权限组列表](app-permission-group-list.md)。

**reason字段的内容写作规范及建议如下：**

1. 保持句子简洁、不要加入多余的分割符号。

   **建议句式**：用于某事。

   **示例**：用于扫码拍照。

2. 用途描述的字串建议小于72个字符（即36个中文字符，UI界面显示大约为两行）。不能超过256个字符，以保证多语言适配的体验。

3. 如果不写，将展示默认的申请理由。

**权限使用理由展示方式：**

权限使用理由有两个展示途径：授权弹窗界面和“设置（Settings）”界面。“设置”的具体路径：设置-隐私-权限管理-某应用某权限详情。

1. 如果是申请“电话、信息、日历、通讯录、通话记录”这五个权限组中的权限，根据工信部要求，将展示具体子权限的内容与用途。
   
   **句式**：包括子权限A和子权限B，用于某事。

   **样例**：用于获取通话状态和移动网络信息，用于安全运营和统计计费服务。

2. 如果是申请其他权限组中的权限。系统将使用权限组内当前被申请的第一个子权限的使用理由，作为该权限组的使用理由进行展示。组内的排序，固定按照权限管理内排列的权限组数组顺序。
   
   举例说明：权限组A = {权限A, 权限B, 权限C}；申请传入的权限是{权限C, 权限B}，界面将展示权限B的权限使用理由。
