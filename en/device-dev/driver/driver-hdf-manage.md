# Configuration Management


## HDF Configuration Overview

HDF Configuration Source (HCS) provides the source code that describes the HDF configuration in key-value pairs. It decouples the configuration code from driver code, thereby facilitating configuration management.

HDF Configuration Generator (HC-GEN) is a tool for converting an HDF configuration file into a file that can be read by the software.

- In a low-performance system on a chip (SoC), this tool converts an HCS configuration file into the source code or macro definitions of the configuration tree. The driver can obtain the configuration by calling the C library code or macro-based APIs.

- In a high-performance SoC, this tool converts an HCS configuration file into an HDF Configuration Binary (HCB) file. The driver can obtain the configuration by calling the configuration parsing APIs provided by the HDF.

The figure below illustrates how an HCB file is used.

  **Figure 1** Process of using an HCB file

  ![](figures/HCB-using-process.png)

The HC-GEN converts the HCS into an HCB file. The HCS Parser module in the HDF rebuilds a configuration tree from the HCB file. The HDF driver obtains the configuration through the configuration read API provided by the HCS Parser.


## Configuration Syntax

The following describes the HCS syntax.


### Keywords

The table below describes the keywords used in the HCS syntax.

  **Table 1** Keywords used in HCS syntax

| Keyword| Description| Remarks|
| -------- | -------- | -------- |
| root | Sets the root node.| - |
| include | References other HCS files.| - |
| delete | Deletes a node or an attribute.| Applicable only to the configuration tree referenced by **include**.|
| template | Defines a template node.| - |
| match_attr | Marks the node attribute for matching.| When parsing the configuration, the driver can use the attribute value as a parameter to call an API to locate the node that has this attribute. |


### Basic Structures

The HCS has two structures: attribute and node.

Attribute

An attribute is the minimum, independent configuration unit. The syntax is as follows:


```
  attribute_name = value;
```

- **attribute_name** is a case-sensitive string of letters, digits, and underscores (\_) and must start with a letter or underscore (_).

- The **value** can be in any of the following formats:

  - A binary, octal, decimal, or hexadecimal integer. For details, see [Data Types](#data-types).
  - String quoted by double quotation marks ("").
  - Node reference.

- An attribute key-value pair must end with a semicolon (;) and belong to a node.

**Node**

A node is a set of attributes. The syntax is as follows:


```
  node_name {
      module = "sample";
      ...
  }
```

- **node_name** is a case-sensitive string of letters, digits, and underscores (\_) and must start with a letter or underscore (_).

- No semicolon (;) is required after the curly brace ({) or (}).

- The keyword **root** is used to declare the root node of a configuration table. Each configuration table must start with the root node.

- The root node must contain a **module** attribute. The value is a string indicating the module to which the configuration belongs.

- The **match_attr** attribute can be added to a node. Its value is a globally unique string. During configuration parsing, the **match_attr** attribute can be used to quickly locate the node that contains the attribute.


### Data Types

Attributes automatically use built-in data types, including integer, string, array, and boolean. You do not need to explicitly specify the data type for the attribute values.

**Integer**

  An integer can be binary, octal, decimal, or hexadecimal. The minimum space is automatically allocated to the integer based on the actual data length.
- Binary: prefixed with **0b**, for example, **0b1010**.

- Octal: prefixed with **0**, for example, **0664**.

- Decimal: signed or unsigned, without prefix, for example, **1024** or **+1024**. Negative integers can be read only via APIs with signed numbers.

- Hexadecimal: prefixed with **0x**, for example, **0xff00** and **0xFF**.

**String**

A string is enclosed in double quotation marks ("").

**Array**

An array can hold either integers or strings, but not a mixture of them. The mixed use of **uint32_t** and **uint64_t** in an integer array will cause typecasting to **uint64**. The following is an example of an integer array and a string array:


```
attr_foo = [0x01, 0x02, 0x03, 0x04];
attr_bar = ["hello", "world"];
```

Boolean

Boolean data type is a form of data with only two possible values: **true** and **false**.


### Preprocessing

**include**

The keyword **include** is used to import other HCS files. The syntax is as follows:


```
#include "foo.hcs"
#include "../bar.hcs"
```

- The file name must be enclosed in double quotation marks (""). If the file to be included is in a different directory with the target file, use a relative path. The included file must be a valid HCS file.

- If multiple HCS files included contain the same nodes, the same nodes will be overridden and other nodes are listed in sequence.


### Comments

The following two comment formats are supported:

- Single-line comment

  
  ```
  // comment
  ```

- Multi-line comment

  
  ```
  /*
  comment
  */
  ```

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
  > Multi-line comments cannot be nested.


### Reference Modification

You can reference the content of a node to modify the content of another node. The syntax is as follows:


```
 node :& source_node
```

In this statement, the content of **node** is referenced to modify the content of **source_node**. 

Example:
```
root {
    module = "sample";
    foo {
        foo_ :& root.bar{
            attr = "foo";
        }
        foo1 :& foo2 {
            attr = 0x2;
        }
        foo2 {
            attr = 0x1;
        }
    }

    bar {
        attr = "bar";
    }
}
```

The configuration tree generated is as follows:


```
root {
    module = "sample";
    foo {
        foo2 {
            attr = 0x2;
        }
    }
    bar {
        attr = "foo";
    }
}
```

In this example, the value of **bar.attr** is changed to **foo** by referencing **foo.foo_**, and the value of **foo.foo2.attr** is changed to **0x2** by referencing **foo.foo1**. The **foo.foo_** and **foo.foo1** nodes are used to modify the content of the target nodes, and do not exist in the configuration tree generated.

- A node of the same level can be referenced simply using the node name. To reference a node of a different level, use the absolute path starting with **root**, and separate the node names using a period (.). **root** indicates the root node. For example, **root.foo.bar**.

- If multiple modifications are made to the same attribute, only one modification takes effect and a warning will be displayed for you to confirm the result.


### Node Replication

You can replicate a node to define a node with similar content. The syntax is as follows:


```
 node : source_node
```

This statement replicates the attributes of the **source_node** node to define **node**. 

Example:

```
root {
	module = "sample";
    foo {
        attr_0 = 0x0;
    }
    bar:foo {
        attr_1 = 0x1;
    }
}
```

The configuration tree generated is as follows:


```
root {
    module = "sample";
    foo {
        attr_0 = 0x0;
    }
    bar {
        attr_1 = 0x1;
        attr_0 = 0x0;
    }
}
```

In this example, the **bar** node contains **attr_0** and **attr_1** attributes, and the modification of the **attr_0** attribute in the **bar** node does not affect the **foo** node.

You do not need to specify the path of the **foo** node if the **foo** node and the **bar** node are of the same level. Otherwise, specify the absolute path of **foo**. For details, see [Reference Modification](#reference-modification).


### Delete

You can use the keyword **delete** to delete unnecessary nodes or attributes from the base configuration tree imported by using the **include** keyword. The following example includes the configuration in **sample2.hcs** to **sample1.hcs** and deletes the **attribute2** attribute and the **foo_2** node. 

Example:

```
// sample2.hcs
root {
    attr_1 = 0x1;
    attr_2 = 0x2;
    foo_2 {
        t = 0x1;
    }
}

// sample1.hcs
#include "sample2.hcs"
root {
    attr_2 = delete;
    foo_2 : delete {
    }
}
```

The configuration tree generated is as follows:


```
root {
    attr_1 = 0x1;
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The keyword **delete** cannot be used to delete nodes or attributes in the same HCS file. In an HCS file, you can directly delete unnecessary attributes.


### Attribute Reference

You can associate an attribute and a node so that the node can be quickly located when the attribute is read during configuration parsing. The syntax is as follows:


```
 attribute = &node;
```

In this statement, the value of **attribute** is a referenced to the node. During code parsing, you can quickly locate the node based on this **attribute**. 

Example:

```
node1 {
    attributes;
}
node2 {
    attr_1 = &root.node1;
}
```

Or


```
node2 {
    node1 {
        attributes;
    }
    attr_1 = &node1;
}
```


### Template

The template is used to generate nodes with consistent syntax, thereby facilitating the traverse and management of nodes of the same type.

If a node is defined using the keyword **template**, its child nodes inherit from the node configuration through the double colon operator (::). The child nodes can modify or add but cannot delete attributes in **template**. The attributes not defined in the child nodes will use the attributes defined in **template** as the default values.

Example:

```
root {
    module = "sample";
    template foo {
        attr_1 = 0x1;
        attr_2 = 0x2;
    }

    bar :: foo {
    }

    bar_1 :: foo {
        attr_1 = 0x2;
    }
}
```

The configuration tree generated is as follows:


```
root {
    module = "sample";
    bar {
        attr_1 = 0x1;
        attr_2 = 0x2;
    }
    bar_1 {
        attr_1 = 0x2;
        attr_2 = 0x2;
    }
}
```

In this example, the **bar** and **bar_1** nodes inherit from the **foo** node. The structure of the generated configuration tree is the same as that of the **foo** node, except that the attribute values are different.


## Configuration Generation

The HC-GEN tool checks the HCS configuration syntax and converts HCS source files into HCB files.


### HC-GEN

HC-GEN options:


```
Usage: hc-gen [Options] [File]
options:
  -o <file>   output file name, default same as input
  -a          hcb align with four bytes
  -b          output binary output, default enable
  -t          output config in C language source file style
  -m          output config in macro source file style
  -i          output binary hex dump in C language source file style
  -p <prefix> prefix of generated symbol name
  -d          decompile hcb to hcs
  -V          show verbose info
  -v          show version
  -h          show this help message
```

Generate a .c or .h configuration file.


```
hc-gen -o [OutputCFileName] -t [SourceHcsFileName]
```

Generate an HCB file.


```
hc-gen -o [OutputHcbFileName] -b [SourceHcsFileName]
```

Generate a macro definition file.


```
hc-gen -o [OutputMacroFileName] -m [SourceHcsFileName]
```

Decompile an HCB file to an HCS file.


```
hc-gen -o [OutputHcsFileName] -d [SourceHcbFileName]
```
