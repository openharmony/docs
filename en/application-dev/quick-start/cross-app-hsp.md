# Inter-Application HSP Development

An inter-application Harmony Shared Package (HSP) is a file used for code and resource sharing between the host application and other applications.
The host application of an inter-application HSP is a special form of application, which consists of only one HSP. Instead of running independently on a device, the host application runs by being referenced by dependencies of common application modules. When a common application is running, it can invoke capabilities provided by the inter-application HSP dynamically as needed.

## Precautions
1. The code of an inter-application HSP runs in the application process. When invoking the code, implement an exception capture and fault tolerance mechanism to avoid stability issues caused by malfunctioning of the inter-application HSP.
2. An application can depend on multiple inter-application HSP files at the same time.
3. The inter-application HSP may slow down the startup of the application that depends on it. To avoid significant increase in the startup delay, limit the number of inter-application HSP dependencies within 16.
4. Privilege verification is conducted during inter-application HSP installation. To develop an inter-application HSP, you must configure the **allowAppShareLibrary** application privilege. For details, see [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

## Inter-Application HSP Usage
An inter-application HSP works by combining the following parts:

[HAR](har-package.md): contains only objects and methods to be exported and therefore comes in a small size. By integrating the HAR into your application project, you can call the objects and methods therein to implement features.

HSP: contains the actual implementation code, including the JS/TS code, C++ libraries, resources, and configuration files. It is either released to the application market or integrated into the system version.

### Integrating the HAR in an Inter-Application HSP
Define the interfaces to be exported in the **index.ets** file in the HAR, which is the entry to the declaration file exported by the inter-application HSP. The path to the **index.ets** file is as follows:
```
liba
├── src
│   └── main
│       ├── ets
│       │   ├── pages
│       │   └── index.ets
│       ├── resources
│       └── module.json5
└── oh-package.json5
```
Below is an example of the **index.ets** file content:

```ts
// liba/src/main/ets/index.ets
export { hello, foo1, foo2, nativeMulti, UIComponent } from './ui/MyUIComponent'
```
In the example, **UIComponent** is an ArkUI component, **hello()**, **foo1()**, and **foo2()** are TS methods, and **nativeMulti()** is a native method. Specific implementation is as follows:
#### ArkUI Components
The following is an implementation example of ArkUI components in the HSP:
```ts
// liba/src/main/ets/ui/MyUIComponent.ets
@Component
export struct UIComponent {
  @State message: string = 'Hello World'
  build() {
    Column() {
      Text(this.message)
        .fontSize(32)
        .padding(8)
        .fontColor(0xffffff)
        .backgroundColor(0x0000ff)
    }.padding(8).width('100%')
  }
}
```

#### **TS Methods**
The following is an implementation example of TS methods in the HSP:
```ts
// liba/src/main/ets/ui/MyUIComponent.ets
export function hello(name: string): string {
  return "hello + " + name;
}

export function foo1() {
  return "foo1";
}

export function foo2() {
  return "foo2";
}

```
#### **Native Methods**
The HSP can contain .so files compiled in C++. The HSP indirectly exports the native method in the .so file. In this example, the **multi** API in the **libnative.so** file is exported.

```ts
// liba/src/main/ets/ui/MyUIComponent.ets
import native from "libnative.so"

export function nativeMulti(a: number, b: number) {
    return native.multi(a, b);
}
```

### Using the Capabilities Exported from the HAR
To start with, [configure dependency](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section611662614153) on the HAR. The dependency information will then be generated in the **module.json5** file of the corresponding module, as shown in the following:
```json
"dependencies": [
      {
        "bundleName": "com.share.liba",
        "moduleName": "liba",
        "versionCode": 10001
      }
]
```
In the preceding information, **bundleName**, **moduleName**, and **versionCode** indicate the bundle name, module name, and version number of the inter-application HSP, respectively.
#### Referencing ArkUI Components in the HAR
After configuring the dependency on the HAR, you can reference ArkUI components exported from the HAR by using **import**. The sample code is as follows:
``` ts
import { UIComponent } from 'liba'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      // Reference the ArkUI component in the HAR.
      UIComponent()
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

#### Referencing TS Classes and Methods in the HAR
To reference the TS classes and methods exported from the HAR, use **import** as follows:
``` ts
import { foo1 } from 'liba'
import { foo2 } from 'liba'

@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Button')
          .onClick(()=>{
            // Reference the TS methods in the HAR.
            foo1();
            foo2();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
#### Referencing Native Methods in the HAR
To reference the native methods exported from the HAR, use **import** as follows:
``` ts
import { nativeMulti } from 'liba'

@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Button')
          .onClick(()=>{
            // Reference the native method in the HAR.
            nativeMulti();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Inter-Application HSP Distribution
Inter-application HSPs are not completely integrated into an application. They are distributed by being preset in the system version or installed with an application on the device. To be specific:
1. Some frequently-used inter-application HSPs are preset in the system version.
2. When a user downloads an application from the application market, if the application market detects that the application depends on one or more inter-application HSPs and any of these HSPs are not installed on the target device, it will download the application as well as the missing HSPs for the user. In this way, the application can use the features shared through the HSPs properly.

### Inter-Application HSP Debugging Mode
You can debug an inter-application HSP after it is distributed to a device. If the aforementioned distribution methods are not applicable, you can distribute the HSP by running **bm** commands. The procedure is as follows:
1. Obtain the inter-application HSP installation package.
2. Run the following **bm** command to install the inter-application HSP.
```
bm install -s sharebundle.hsp
```
3. Run the following **bm** command to install the HAP file of your application.
```
bm install -p feature.hap
```
4. Start your application and start debugging.

> **NOTE**
>
> Do not reverse steps 2 and 3. Otherwise, your application will fail to be installed due to a lack of the required inter-application HSP. For more information about the **bm** commands, see [bm Commands](../../readme/bundle-management.md#bm-commands).