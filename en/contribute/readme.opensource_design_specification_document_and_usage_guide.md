# README.OpenSource Design Specification Document and Usage Guide

## Introduction

To facilitate the tracking of third-party open-source software's original upstream information, the OpenHarmony community mandates the following in the *Third-Party Open Source Software Introduction Guide*:

> New open-source software introduced must provide a `README.OpenSource` file at its root directory, accurately detailing the software name, license, license file location, version, corresponding upstream community address, software maintainer (Owner), functional description, and the reason for inclusion.

However, community developers often find the requirements and standards for writing `README.OpenSource` files unclear, particularly when managing scenarios involving multiple licenses or multiple open-source software entries. This document serves as a final optimized design specification and usage guide for OpenHarmony project’s `README.OpenSource` files. By **retaining the existing metadata field structure**, this guide addresses the issue of multiple licenses possibly corresponding to the same license file, ensuring compatibility with engineering-level parsing and minimizing impact on existing `README.OpenSource` files.

## Scope

This guide applies to all contributors in the OpenHarmony community, particularly when introducing third-party open-source software into the OpenHarmony project.

## Overall Configuration Structure

The `README.OpenSource` file uses JSON format and contains an array where each element represents the metadata object of an open-source software entry. **No fields are added or removed from the original structure**.

### Field Structure

```
[
    {
        "Name": "softwarename",               // Full name of the upstream open-source software
        "License": "SPDX-License-Identifier", // License information; multiple licenses are separated by semicolons
        "License File": "path/to/license",    // Path to the license file; multiple paths are separated by semicolons
        "Version Number": "1.0.0",            // Software version number
        "Owner": "zhangsan@xyz.com",          // Maintainer’s contact (email)
        "Upstream URL": "https://example.com",// Upstream software URL
        "Description": "Brief function description", // Software description
        // "Dependencies": ["dependency1", "dependency2"] // Optional; list if dependencies exist
    }
]
```

## Field Definitions and Completion Guidelines

### 1. Name

- **Description**: Full name of the upstream open-source software.
- **Requirement**: Accurately enter the official software name as published by the upstream.

### 2. License

- **Description**: Open-source software license information.

- Requirements

  :

  - Use standardized identifiers from [SPDX License Identifier](https://spdx.org/licenses/).

  - For multiple licenses, separate them with a semicolon (`;`).

    ```
    ";"
    ```

    - Example: `"MIT;BSD-3-Clause"`

  - **Order of licenses**: Corresponds one-to-one with the license file paths in the `License File` field.

### 3. License File

- **Description**: Path to the license file.

- Requirements

  :

  - **Multiple license files**: Separate paths with a semicolon (`;`), maintaining the same order as in the `License` field.

  - If multiple licenses refer to the same license file, repeat the path in the field.

    - Example: `"LICENSE;LICENSE"`

  - For a single license requiring multiple files, separate the paths with a colon.

    ```
    :
    ```

    - Example: `"COPYING:LICENSE"`

### 4. Version Number

- **Description**: Version number of the included open-source software.
- **Requirement**: Enter the official release version from the upstream, ensuring it matches the actual version used.

### 5. Owner

- **Description**: Maintainer and their email address within the OpenHarmony organization.
- **Requirement**: Enter the email address of the person responsible for maintaining the software.

### 6. Upstream URL

- **Description**: URL of the upstream source code repository or release page.
- **Requirement**: Provide a valid link to the source code or release page of the upstream software.

### 7. Description

- **Description**: Brief function description of the open-source software.
- **Requirement**: Use concise language to describe the software’s main functionality and purpose.

### 8. Dependencies (Optional)

- **Description**: List of other open-source software directly required by this software.
- Requirements:
  - **Only include** if the software has dependencies.
  - List dependencies as an array, aligning each with the `Name` field of the dependent software.
  - Example: `"Dependencies": ["dependency1", "dependency2"]`

## Usage Guide

### 1. Introducing New Open-Source Software

- Steps:
  1. Create a separate code repository for the new software.
  2. Create a `README.OpenSource` file in the root directory of the repository.
  3. Complete the `README.OpenSource` file using the field definitions above.
  4. If the software has dependencies, ensure all dependent software is introduced and has its own `README.OpenSource` file.

### 2. Handling Multiple License Situations

- **Multiple licenses pointing to a single license file**:

  - List all licenses in the `License` field, separated by semicolons.

  - Repeat the license file path in the `License File` field to correspond with each license.

  - Example:

    ```
    "License": "MIT;BSD-3-Clause",
    "License File": "LICENSE;LICENSE"
    ```

- **Single license pointing to multiple license files**:

  - Enter the license in the `License` field.

  - Separate the multiple paths in `License File` with a colon (`:`).

  - Example:

    ```
    "License": "GPL-2.0+",
    "License File": "COPYING:LICENSE"
    ```

- **Multiple licenses with multiple license files**:

  - Use a semicolon (`;`) to separate entries in both `License` and `License File` fields, maintaining one-to-one correspondence.

  - Example:

    ```
    "License": "MIT;Apache-2.0",
    "License File": "LICENSE-MIT;LICENSE-APACHE"
    ```

### 3. Maintaining Dependency Relationships

- **Description**: In the main software’s `README.OpenSource` file, list all directly dependent software under `Dependencies`.
- Requirements:
  - Only list direct dependencies, omitting indirect dependencies.
  - Ensure that each listed dependency is included in OpenHarmony with a corresponding `README.OpenSource` file.

### 4. Updating Open-Source Software

- Steps:
  1. When updating the software version, update the `Version Number` field to reflect the new version.
  2. Check for any changes in license information and update the `License` and `License File` fields if necessary.
  3. Review and update the `Dependencies` field if dependencies have changed.

### 5. Handling Special Cases

- **Exceptional Cases Reporting**: If managing multiple open-source software entries within a single `README.OpenSource` file, the project within OpenHarmony’s main branch must report to the Community Architecture SIG in advance.

## Engineering Parsing Guide

- **Parser Logic**:

  1. Read the `License` and `License File` fields, splitting entries with the semicolon (`;`) delimiter.
  2. Establish a one-to-one mapping between licenses and license files based on index order.
  3. When a path in `License File` contains multiple files, separate them with a colon (`:`).

- **Parsing Example**:

  ```
  "License": "MIT;BSD-3-Clause",
  "License File": "LICENSE;LICENSE"
  ```

  - Parsed output:
    - License list: `["MIT", "BSD-3-Clause"]`
    - License file list: `["LICENSE", "LICENSE"]`
    - Mappings:
      - `"MIT"` maps to `"LICENSE"`
      - `"BSD-3-Clause"` maps to `"LICENSE"`

## Examples

### Example 1: Multiple Licenses Sharing a Single License File

```
[
    {
        "Name": "examplelib",
        "License": "MIT;BSD-3-Clause",
        "License File": "LICENSE;LICENSE",
        "Version Number": "1.2.3",
        "Owner": "developer@openharmony.io",
        "Upstream URL": "https://github.com/example/examplelib",
        "Description": "An example library with multiple licenses corresponding to a single license file."
    }
]
```

### Example 2: Single License with Multiple License Files

```
[
    {
        "Name": "complexlib",
        "License": "GPL-2.0+",
        "License File": "COPYING:LICENSE",
        "Version Number": "3.0.0",
        "Owner": "maintainer@openharmony.io",
        "Upstream URL": "https://github.com/example/complexlib",
        "Description": "A complex library with a single license covering multiple license files."
    }
]
```

### Example 3: Software with Dependencies

```
[
    {
        "Name": "bindgen",
        "License": "BSD-3-Clause",
        "License File": "LICENSE",
        "Version Number": "0.59.1",
        "Owner": "lihua@openharmony.io",
        "Upstream URL": "https://github.com/rust-lang/rust-bindgen",
        "Description": "A tool for generating Rust FFI bindings to C/C++ libraries.",
        "Dependencies": ["shlex", "once_cell"]
    }
]
``
```

### Example 4: Software with No Dependencies

```
[
    {
        "Name": "simplelib",
        "License": "Apache-2.0",
        "License File": "LICENSE",
        "Version Number": "0.1.0",
        "Owner": "zhaoliu@openharmony.io",
        "Upstream URL": "https://github.com/example/simplelib",
        "Description": "A library providing basic functionality."
        // No need to fill in the Dependencies field
    }
]
```

## Notes

1. **Field Integrity**:
   - Retain the original field structure; do not add or remove fields.
   - All fields are mandatory unless specifically indicated as optional.
   - The `Dependencies` field is optional and should only be filled in if dependencies exist.
2. **Correspondence between License and License File**:
   - The elements in the `License` and `License File` fields must have the same quantity and order.
   - When multiple licenses correspond to a single license file, repeat the path of the license file.
   - When a license file corresponds to multiple files, separate the paths with a colon `":"`.
3. **Consistency of Parsing Rules**:
   - The parser should follow the agreed-upon delimiters and order to achieve accurate mapping of licenses to license files.
   - Ensure that parsing logic aligns with entry guidelines to avoid misunderstandings.
4. **Minimizing Impact on Existing Files**:
   - As the original field structure is maintained, existing `README.OpenSource` files are compatible with the new parsing rules and do not require modification.
5. **Field Formatting Requirements**:
   - The order of licenses in the `License` field should match the order of license files in the `License File` field.
   - Use standard SPDX license identifiers and avoid non-standard or abbreviated forms.
6. **Compliance Checks**:
   - Ensure that all entries accurately reflect the actual status of the upstream open-source software.
   - Regularly check license and version information to ensure timely updates.

## Fulfillment of Open-Source Obligations

- **Based on Mapping**: Ensure each license obligation is properly fulfilled.
- Process Steps:
  1. Parse the `License` and `License File` fields to establish the mapping between licenses and license files.
  2. Collect and review each license file to understand its requirements.
  3. Implement the required compliance measures based on each license, such as copyright notices, source code disclosures, etc.

## Document Improvements and Revision Notes

1. This document is drafted and maintained by the OpenHarmony Compliance SIG. The latest version of this document is available here.
2. Any additions, modifications, or deletions to the rules in this document must be tracked. Please access the tracking system for updates.
3. Final rules are reviewed and approved by the PMC after thorough discussion within the community.
