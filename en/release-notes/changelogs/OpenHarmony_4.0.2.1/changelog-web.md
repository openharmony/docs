# Web Subsystem ChangeLog

Compared with earlier versions, OpenHarmony 4.0.2.1 has the following API changes in its Web subsystem:

## cl.web.1 Parameter Type Change of postMessageEvent

The **postMessageEvent** API supported only the string type. In OpenHarmony 4.0.2.1 and later versions, it also supports the ArrayBuffer type.

**Change Impacts**

The API change is forward compatible. Applications developed based on earlier versions can still use the API, and the original functions are not affected.

**Key API/Component Changes**

- Involved APIs

  postMessageEvent(message: string): void

- Before change

  ```ts
  postMessageEvent(message: string): void
  ```

- After change

  ```ts
  type WebMessage = ArrayBuffer | string
  postMessageEvent(message: WebMessage): void
  ```

**Adaptation Guide**

The API change is forward compatible. Applications developed based on earlier versions can still use the API, and the original functions are not affected.

## cl.web.2 Parameter Type Change of onMessageEvent

The **onMessageEvent** API supported only the string type. In OpenHarmony 4.0.2.1 and later versions, it also supports the ArrayBuffer type.

**Change Impacts**

The API change is forward compatible. Applications developed based on earlier versions can still use the API. With the corresponding logic handling added, the original functions are not affected.

**Key API/Component Changes**

- Involved APIs

  onMessageEvent(callback: (result: string) => void): void

- Before change

  ```ts
  onMessageEvent(callback: (result: string) => void): void
  ```

- After change

  ```ts
  type WebMessage = ArrayBuffer | string
  onMessageEvent(callback: (result: WebMessage) => void): void
  ```

**Adaptation Guide**

The API change is forward compatible. Applications developed based on earlier versions can still use the API. With the corresponding logic handling added, the original functions are not affected.
