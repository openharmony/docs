# 应用配置


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口['@ohos.i18n'](js-apis-i18n.md)和['@ohos.intl'](js-apis-intl.md)。
>


## 导入模块

```
import configuration from '@system.configuration';
```

## 权限列表

无


## configuration.getLocale

getLocale(): &lt;LocaleResponse&gt;

获取应用当前的语言和地区。默认与系统的语言和地区同步。

- 返回值
  **表1** LocaleResponse
  
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | language | string | 语言。例如：zh。 |
  | countryOrRegion | string | 国家或地区。例如：CN。 |
  | dir | string | 文字布局方向。取值范围：<br/>-&nbsp;ltr：从左到右；<br/>-&nbsp;rtl：从右到左。 |
  | $unicodeSetting^{5+}$ | string | 语言环境定义的Unicode语言环境键集，如果此语言环境没有特定键集，则返回空集。<br/>例如：{"nu":"arab"}，表示当前环境下的数字采用阿拉伯语的数字。 |

- 示例
  ```
  export default {    
    getLocale() {        
      const localeInfo = configuration.getLocale();        
      console.info(localeInfo.language);    
    }
  }
  ```
