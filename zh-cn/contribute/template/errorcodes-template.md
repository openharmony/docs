# xxx（模块名，与API参考title保持一致）错误码

> **说明：** 
>
> *1、所有的写作说明，在完成写作后，都要删除。*
>
> *2、错误码文档的命名规则：统一前缀，命名格式为errorcode-xxx.md。*

|      | 说明项                         | 细则                                                         |
| ---- | ------------------------------ | ------------------------------------------------------------ |
| 1    | 错误码error.errorNumber        | 按统一的错误码编号规则设计错误码ID。                         |
| 2    | 错误信息error.message          | **字段含义**：出现异常时，会给开发者抛出一个错误对象，对象里包括errorNumber和error.message，此处定义error.message的值，即英文错误码简述。<br/>**要求**：<br/>1.应当简洁、具体，避免过于宽泛的定义。<br/>2.此处英文描述必须经过翻译中心审校。在提交本错误码设计评审前，请将预期的中英文message描述提供给翻译中心，将翻译中心审校后的英文填至此处。 |
| 3    | 错误简述<br/>Short Description | **字段含义**：中文错误码简述。<br/>**要求**：<br/>1.与”错误信息“对应的中文简述，应当简洁、具体，避免过于宽泛的定义。 |
| 4    | 错误描述<br/>Description       | **字段含义**：错误码详细描述，告知错误码所属的业务场景、产生位置等。<br/>**要求**：<br/>1.描述错误码所属的业务场景（比如开发xx业务、开发xx功能时）。<br/>2.描述出现异常的具体现象、产生位置（比如xx模块、xx类、xx接口等），辅助开发者理解和处理异常。 |
| 5    | 可能原因<br/>Possible Causes   | **字段含义**：列举出现该异常的所有可能原因（对应该错误码的产生机制）。<br/>**要求**：<br/>1.全面、无遗漏。<br/>2.言简意赅。<br/>3.根据可能性从高到低排序。 |
| 6    | 处理步骤<br/>Procedure         | **字段含义**：根据错误现象及可能原因，告知开发者遇到该异常时如何应对。<br/>**要求**：<br/>1.采用step样式描述处理指导。每个大步骤与可能原因一一对应，按顺序分别给出各原因对应的处理指导。大步骤下可以有子步骤。<br/>2.步骤要明确、具体、可执行。涉及判断的，提供明确的判断标准。<br/>3.对系统或业务有影响的操作，在操作前以“注意”或“警告”形式提供警示信息。具体提示要求，请参见“风格指南”中的“提示与说明”：https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/style-guide/style-guide-content-elements.md |

## 1300001 重复操作 *（错误码number+空格+错误简述）*

**错误信息**

This is repeat operation.

**错误描述**

> *写作说明：*
>
>  *描述**错误码所属的业务场景（比如开发xx业务、开发xx功能时）及出现异常的具体现象**，辅助开发者理解和处理异常*。


当对同一窗口对象存在重复操作时，系统会产生此错误码。

**可能原因**

> *写作说明：*
>
> *列举出现该异常的所有可能原因（对应该错误码的产生机制）。*
>
> *1.全面、无遗漏。*
>
> *2.言简意赅。*
>
> *3.根据可能性从高到低排序。*


1. 重复创建已创建的窗口。

2. xxx。

**处理步骤**

> *写作说明：*
>
> *根据错误现象及可能原因，告知开发者遇到该异常时如何应对。*
>
> *1.采用step样式描述处理指导。**每个大步骤与可能原因一一对应**，按顺序分别给出各原因对应的处理指导。**大步骤下可以有子步骤**。*
>
> *2.步骤要**明确、具体、可执行。涉及判断的，提供明确的判断标准**。*
>
> *3.对系统或业务有影响的操作，在操作前以“注意”或“警告”形式提供警示信息。具体提示要求，请参见“风格指南”中的“提示与说明”：https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/style-guide/style-guide-content-elements.md*


1. 检查该窗口是否已创建。

   xxx。     
   
   ```
   uth([in] String appId, [in] IHwShareCallback callback);
       int shareFaInfo([in] PacMapEx pacMapEx);
   }
   ```
   
2. xxx。

   a. xxx。

      ```
      uth([in] String appId, [in] IHwShareCallback callback);
          int shareFaInfo([in] PacMapEx pacMapEx);
      }
      ```

   b. xxx。

## 1300002 窗口状态异常

**错误信息**

xxx

**错误描述**

xxx

**可能原因**

1. xxx

**处理步骤**

1. 检查该窗口是否已创建。

   xxx。     

   ```
   uth([in] String appId, [in] IHwShareCallback callback);
       int shareFaInfo([in] PacMapEx pacMapEx);
   }
   ```

2. xxx。

   a. xxx。

      ```
      uth([in] String appId, [in] IHwShareCallback callback);
          int shareFaInfo([in] PacMapEx pacMapEx);
      }
      ```

   b. xxx。