# *ModuleName* Error Codes

> **NOTE**
>
> 1. Delete all writing instructions from your document after you finish the writing.
>
> 2. The error code document must be named in the format of **errorcode-*moduleName*.md**, where *moduleName* must be the same as that used in the corresponding API reference document.
>
> *3. If a kit includes only generic error codes, an error code page is not required.*

|      | Item                        | Writing Instruction                                                        |
| ---- | ------------------------------ | ------------------------------------------------------------ |
| 1    | error.errorNumber       | Use the error code IDs that are designed based on the unified error code numbering rule.                        |
| 2    | error.message         | **Meaning of this field**: If an exception occurs, an error object is thrown. The object contains **errorNumber** and **error.message**, which is a short text description of the error code in English.<br>**Instructions**<br>1. The description should be concise and specific.<br>2. The description should be grammatically correct.  |
| 3    |  <br> |  <br> <br> |
| 4    |  <br>Description       | **Meaning of this field**: provides detailed description for the error code, including the use case when and the location where the error code is thrown.<br>**Instructions**<br>1. Describe the use case when the error code is thrown, for example, when developing a specific service or feature.<br>2. Describe the symptom and location of the error (for example, the exact module name, class name, and interface name).|
| 5    | Possible cause<br>Possible Causes   | **Meaning of this field**: lists all possible causes of the error.<br>**Instructions**<br>1. List all the possible causes.<br>2. Use concise sentences.<br>3. Sort the causes by possibility in descending order.|
| 6    | Procedure<br>Procedure         | **Meaning of this field**: describes how to handle the error based on the symptom and possible causes.<br>**Instructions**<br>1. Provide the procedure step by step. Each step should correspond to a possible cause. You can use substeps for complex operations of a step.<br>2. The steps should be clear, specific, and executable. If judgment is involved, provide clear judgment criteria.<br>3. If an operation has impact on the system or services, provide warning information in the form of Caution or Warning before the operation.  |

## 1300001 Repeated Operation (Error Code + Space + Error Description)

**Error Message**

This is repeat operation.

**Description**

> *Writing instructions*:
>
> Describe the use case (for example, developing a specific service or feature) when the error code is thrown and the symptom.


This error code is generated when a repeated operation is performed on the same **Window** object.

**Possible Causes**

> *Writing instructions*:
>
> List all possible causes of the error.
>
> *1. List all the possible causes.*
>
> *2. Use concise sentences.*
>
> *3. Sort the causes by possibility in descending order.*


1. The **Window** object to create already exists.

2. xxx.

**Procedure**

> *Writing instructions*:
>
> *Describe how to handle the error based on the symptom and possible causes.*
>
> 1. Provide the procedure step by step. Each step should correspond to a possible cause. You can use substeps for complex operations of a step.
>
> 2. The steps should be clear, specific, and executable. If judgment is involved, provide clear judgment criteria.
>
> 3. If an operation has impact on the system or services, provide warning information in the form of Caution or Warning before the operation.


1. Check whether the **Window** object has been created.

   xxx.    
   
   ```
   uth([in] String appId, [in] IHwShareCallback callback);
       int shareFaInfo([in] PacMapEx pacMapEx);
   }
   ```
   
2. xxx.

   a. xxx.

      ```
      uth([in] String appId, [in] IHwShareCallback callback);
          int shareFaInfo([in] PacMapEx pacMapEx);
      }
      ```

   b. xxx.

## 1300002 Abnormal Window State

**Error Message**

xxx

**Description**

xxx

**Possible Causes**

xxx

**Procedure**

1. Check whether the **Window** object has been created.

   xxx.    

   ```
   uth([in] String appId, [in] IHwShareCallback callback);
       int shareFaInfo([in] PacMapEx pacMapEx);
   }
   ```

2. xxx.

   a. xxx.

      ```
      uth([in] String appId, [in] IHwShareCallback callback);
          int shareFaInfo([in] PacMapEx pacMapEx);
      }
      ```

   b. xxx.
