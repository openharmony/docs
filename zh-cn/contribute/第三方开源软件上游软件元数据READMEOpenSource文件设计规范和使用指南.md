# README.OpenSource 设计规范文档和使用指南

## 引言

为了更好地追溯第三方开源软件的原始上游信息，OpenHarmony社区在 [《第三方开源软件引入指导》](第三方开源软件引入指导.md) 中要求：

> 新引入的开源软件必须在其根目录中提供 `README.OpenSource` 文件，该文件应准确描述以下内容：软件名称、许可证类型、许可文件位置、软件版本、对应版本的上游社区地址、软件维护者（Owner）、功能描述及依赖关系。

然而，在实际编写 `README.OpenSource` 文件时，社区开发者常常因规范定义和填写要求不够明确，尤其是在处理多许可证和多开源软件等复杂场景时，导致文件内容不规范。因此，本文档旨在为OpenHarmony项目中的 `README.OpenSource` 文件提供一套更清晰、更易理解的设计规范与使用指南。在**保持原有元数据字段结构**的基础上，我们将解决多个许可证可能共享同一许可证文件的问题，以满足工程化解析的需求，同时确保不影响现有 `README.OpenSource` 文件的使用。

## 范围

本指南适用于所有参与 OpenHarmony 社区的贡献者，特别是当引入第三方开源软件到 OpenHarmony 项目中时。


## 配置文件总体结构

`README.OpenSource` 文件采用 JSON 格式，包含一个数组，数组中的每个元素是一个开源软件的元数据对象。**保持原有字段逻辑，不增删字段**。

### 字段结构

```
[
    {
        "Name": "softwarename",              // 上游开源软件名全称
        "License": "SPDX-License-Identifier",// 许可证信息，可能包含多个，用分号分隔
        "License File": "path/to/license",   // 许可证文件路径，可能包含多个，用分号分隔
        "Version Number": "1.0.0",           // 软件版本号
        "Owner": "zhangsan@xyz.com",         // 维护人及邮箱
        "Upstream URL": "https://example.com", // 上游软件地址
        "Description": "软件功能简介",         // 软件描述
        // "Dependencies": ["dependency1", "dependency2"] // 可选，存在依赖时填写
    }
]
```

## 字段定义和填写指南

### 1. Name

- **说明**：上游开源软件的全称。
- **要求**：准确填写软件的正式名称，与上游发布的名称一致。

### 2. License

- **说明**：开源软件的许可证信息。

- 要求  ：
  - 使用 [SPDX License Identifier](https://spdx.org/licenses/) 标准化填写。
  - 多个许可证：用分号分隔。

    ```
    ";"
    ```
    - 示例：`"MIT;BSD-3-Clause"`

  - **许可证顺序**：与 `License File` 字段中的许可证文件路径一一对应。

### 3. License File

- **说明**：许可证文件的路径。

- 要求：

  - **多个许可证文件**：用分号 `";"` 分隔，顺序与 `License` 字段中的许可证一致。

  - 当多个许可证对应同一个许可证文件时： 在字段中重复该许可证文件路径。 

    ```
    License File
    ```

    - 示例：`"LICENSE;LICENSE"`

  - 单个许可证对应多个许可证文件：在对应的许可证文件路径中，用冒号 

    ```
    ":"
    ```

     分隔多个文件。
    - 示例：`"COPYING:LICENSE"`

### 4. Version Number

- **说明**：引入的开源软件版本号。
- **要求**：填写上游发布的正式版本号，确保与实际使用的版本一致。

### 5. Owner

- **说明**：开源软件在 OpenHarmony 组织下的维护人及其邮箱。
- **要求**：填写负责该软件维护的人员邮箱。

### 6. Upstream URL

- **说明**：上游开源软件的源代码仓库或发布页面链接。
- **要求**：提供有效的上游软件源码或发行版链接。

### 7. Description

- **说明**：开源软件的功能简介。
- **要求**：用简洁的语言描述软件的主要功能和用途。

### 8. Dependencies（可选）

- **说明**：该软件直接依赖的其他开源软件列表。

- 要求：
  - **仅当**软件存在被动依赖时，才需要填写此字段。
  - 以数组形式列出依赖的软件名称，与依赖软件的 `Name` 字段一致。
  - 示例：`"Dependencies": ["dependency1", "dependency2"]`

## 使用指南

### 1. 引入新开源软件

- 步骤：
  1. 为引入的软件创建独立的代码仓库。
  2. 在仓库根目录下创建 `README.OpenSource` 文件。
  3. 按照上述字段定义填写 `README.OpenSource` 文件。
  4. 如果软件存在被动依赖，确保所有依赖的软件也已主动引入，并有对应的 `README.OpenSource` 文件。

### 2. 处理多许可证情况

- **多个许可证对应同一个许可证文件**：
  - 在 `License` 字段中列出所有许可证，用分号 `";"` 分隔。
  - 在 `License File` 字段中重复该许可证文件路径，与 `License` 字段中的许可证顺序对应。
  - 示例：
    ```
    "License": "MIT;BSD-3-Clause",
    "License File": "LICENSE;LICENSE"
    ```

- **单个许可证对应多个许可证文件**：
  - 在 `License` 字段中填写对应的许可证。
  - 在 `License File` 字段中，用冒号 `":"` 分隔多个许可证文件路径。
  - 示例：
    ```
    "License": "GPL-2.0+",
    "License File": "COPYING:LICENSE"
    ```

- **多个许可证对应多个许可证文件**：

  - 在 `License` 字段和 `License File` 字段中，分别用分号 `";"` 分隔，顺序对应。
  - 示例：
    ```
    "License": "MIT;Apache-2.0",
    "License File": "LICENSE-MIT;LICENSE-APACHE"
    ```

### 3. 维护依赖关系

- **说明**：在主软件的 `README.OpenSource` 文件中，通过 `Dependencies` 字段列出其所有直接依赖的软件。

- 要求  ：
  - **仅当**软件存在被动依赖时，才需要填写 `Dependencies` 字段。
  - 仅列出直接依赖，不列出间接依赖，间接依赖通过直接依赖呈现。
  - 确保依赖的软件已在 OpenHarmony 中主动引入，并有对应的 `README.OpenSource` 文件。

### 4. 更新开源软件

- 步骤  ：
  1. 当需要更新开源软件版本时，修改 `Version Number` 字段，确保与实际使用的版本一致。
  2. 检查许可证信息是否有变化，若有，更新 `License` 和 `License File` 字段。
  3. 检查依赖关系是否有变化，更新 `Dependencies` 字段。

### 5. 特殊情况处理

- **异常场景报备**：如需在同一个 `README.OpenSource` 文件中管理多个开源软件，OpenHarmony主线组织下的项目必须提前向社区架构SIG报备申请。

## 工程化解析指导

- **解析器逻辑**：
  1. 读取 `License` 和 `License File` 字段，使用分号 `";"` 分隔，得到许可证列表和许可证文件列表。
  2. 通过索引对应，建立许可证与许可证文件的映射关系。
  3. 当许可证文件路径中包含多个文件时，使用冒号 `":"` 分隔，再次拆分。

- **解析示例**：
  ```
  "License": "MIT;BSD-3-Clause",
  "License File": "LICENSE;LICENSE"
  ```

  - 解析结果：
    - 许可证列表：`["MIT", "BSD-3-Clause"]`
    - 许可证文件列表：`["LICENSE", "LICENSE"]`
    - 映射关系：
      - `"MIT"` 对应 `"LICENSE"`
      - `"BSD-3-Clause"` 对应 `"LICENSE"`

## 示例

### 示例 1：多个许可证对应同一许可证文件

```
[
    {
        "Name": "examplelib",
        "License": "MIT;BSD-3-Clause",
        "License File": "LICENSE;LICENSE",
        "Version Number": "1.2.3",
        "Owner": "developer@openharmony.io",
        "Upstream URL": "https://github.com/example/examplelib",
        "Description": "一个示例库，具有多个许可证对应同一许可证文件。"
    }
]
```

### 示例 2：单个许可证对应多个许可证文件

```
[
    {
        "Name": "complexlib",
        "License": "GPL-2.0+",
        "License File": "COPYING:LICENSE",
        "Version Number": "3.0.0",
        "Owner": "maintainer@openharmony.io",
        "Upstream URL": "https://github.com/example/complexlib",
        "Description": "一个复杂库，单个许可证对应多个许可证文件。"
    }
]
```

### 示例 3：具有依赖关系的软件

```
[
    {
        "Name": "bindgen",
        "License": "BSD-3-Clause",
        "License File": "LICENSE",
        "Version Number": "0.59.1",
        "Owner": "lihua@openharmony.io",
        "Upstream URL": "https://github.com/rust-lang/rust-bindgen",
        "Description": "用于生成 Rust FFI 绑定到 C/C++ 库的工具。",
        "Dependencies": ["shlex", "once_cell"]
    }
]
```

### 示例 4：无依赖的软件

```
[
    {
        "Name": "simplelib",
        "License": "Apache-2.0",
        "License File": "LICENSE",
        "Version Number": "0.1.0",
        "Owner": "zhaoliu@openharmony.io",
        "Upstream URL": "https://github.com/example/simplelib",
        "Description": "提供简单功能的库。"
        // 无需填写 Dependencies 字段
    }
]
```

## 注意事项

1. **字段完整性**：
   - 保持原有字段结构，不增删字段。
   - 除非明确说明可选，所有字段均为必填项。
   - `Dependencies` 字段为可选，仅在存在依赖时填写。
2. **许可证与许可证文件的对应关系**：
   - `License` 和 `License File` 字段中的元素数量和顺序必须一致。
   - 当多个许可证对应同一个许可证文件时，重复许可证文件路径。
   - 当许可证文件对应多个文件时，使用冒号 `":"` 分隔。
3. **解析规则一致性**：
   - 解析器应按照约定的分隔符和顺序解析，实现许可证与许可证文件的正确映射。
   - 确保解析逻辑与填写规范一致，避免误解。
4. **避免对存量文件的影响**：
   - 由于保持了原有字段结构，现有的 `README.OpenSource` 文件无需修改即可兼容新的解析规则。
5. **字段格式要求**：
   - `License` 字段中的许可证顺序应与 `License File` 中的许可证文件顺序一致。
   - 使用标准的 SPDX 许可证标识符，避免使用非标准或简写形式。
6. **合规性检查**：
   - 确保填写的信息与上游开源软件的实际情况一致。
   - 定期检查许可证和版本信息，确保及时更新。

## 开源义务履行
- **依据映射关系**，确保每个许可证的义务得到正确履行。
- **处理流程**：
  1. 解析 `License` 和 `License File` 字段，建立许可证与许可证文件的映射。
  2. 收集并审阅每个许可证文件，理解其要求。
  3. 根据每个许可证的要求，执行相应的合规措施，如版权声明、源代码披露等。

## 本文的改进和修订说明
1. 本文档由 OpenHarmony 合规 SIG 主导起草和维护。本文档的最新版本可在 [这里](第三方开源软件上游软件元数据READMEOpenSource文件设计规范和使用指南.md) 获取。
2. 任何对于本文中涉及的规则的增加、修改、删除都必须被追踪，请进入该追踪系统。
3. 最终规则经过社区充分的讨论后，由 PMC 评审定稿。
