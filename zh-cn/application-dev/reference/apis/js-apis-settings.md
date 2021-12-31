# 设置数据项名称

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


本模块提供设置数据项的访问功能相关接口的说明及示例。


## 导入模块

```
import settings from '@ohos.settings';
```


## 权限

无


## settings.getUri

getUri(name: string): string

获取数据项的URI。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name | string | 是 | 数据项的名称。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 数据项的URI。 |

- 示例：
  ```
   // 获取数据项的URI
   let urivar = settings.getUri(this.dataName);  
  ```


## settings.getValue

getValue(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string

获取数据项的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | 是 | 数据管理辅助类。 |
  | name | string | 是 | 数据项的名称。 |
  | defValue | string | 是 | 默认值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回数据项的值。 |

- 示例：
  ```
  Button(`register and unregister an observer`)
      .onClick(()=>{
          // 获取数据项的URI
          let urivar = settings.getUri(this.dataName);
          // 获取DataAbilityHelper对象
          let helper = featureAbility.acquireDataAbilityHelper(urivar);
          // 注册观察者，on方法第一个参数写"dataChange"，第二个参数为URI，第三个参数为当该URI指向的数据发生改变时触发的回调函数
          helper.on("dataChange", urivar, (err) => {
          console.log('observer reveive notifychange on success data : ' + JSON.stringify(err))
          this.value = settings.getValue(helper, this.dataName, 'this is default value')
      })
  ```


## settings.setValue

setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean

设置数据项的值。

使用此方法需获取ohos.permission.WRITE_SYSTEM_SETTING权限。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | 是 | 数据管理辅助类。 |
  | name | string | 是 | 数据项的名称。 |
  | value | string | 是 | 数据项的具体数值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回设置数据项的值是否成功的结果。true表示设置成功，false则表示设置失败。 |

- 示例：
  ```
  Button(`setValue`)
      .onClick(()=>{
          // 获取数据项的URI
          let urivar = settings.getUri(this.dataName);
          // 获取DataAbilityHelper对象
          let helper = featureAbility.acquireDataAbilityHelper(urivar);
          let valueTest = 'valueTest';
          // 更新数据库中的值
          settings.setValue(helper, this.dataName, valueTest)
      })
  ```
