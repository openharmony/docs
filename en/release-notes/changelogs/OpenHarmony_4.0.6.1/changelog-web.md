# Web Subsystem Changelog

Compared with earlier versions, OpenHarmony 4.0.6.1 has the following API changes in its web subsystem:

## cl.web.1 Parameters in createWebMessagePorts

Added an optional parameter to the **WebMessagePort** API to accommodate more data types.

**Change Impact**

None (The added parameter is optional, and the API is forward compatible.)

**Key API/Component Changes**

- Involved APIs:

  createWebMessagePorts(): Array\<WebMessagePort>;

- Before change:

  ```ts
  createWebMessagePorts(): Array<WebMessagePort>;
  ```

- After change:

  ```ts
  createWebMessagePorts(isExtentionType?: boolean): Array<WebMessagePort>;
  ```

**Adaptation Guide**

N/A
