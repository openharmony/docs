# ArkTS子系统变更说明

## cl.arkts.1 collections模块bitVector.has接口内部实现行为变更

**访问级别**

公开接口

**变更原因**

collections模块bitVector.has接口存在越界访问的行为。

**变更影响**

此变更涉及应用适配。

变更前：
针对开发者调用push接口初始化BitVector容器值皆为1的情况，在调用collections模块BitVector.has接口查询容器是否含有0时，若传入的toIndex等于容器的长度时会返回错误的结果。示例如下：

```ts
import { collection } from '@kit.ArkTS';

let bitVector: collections.BitVector = new collections.BitVector(0);

bitVector.push(1);
bitVector.push(1);
bitVector.push(1);
bitVector.push(1);
bitVector.push(1); // bitVector: [1, 1, 1, 1, 1]

// 变更前：has接口因为越界读取会返回true
try {
  let res: boolean = bitVector.has(0, 0, 5);
  console.info("res: " + res);
  // 输出结果为res: true
} catch (err) {
  console.error("error message: " + err.message);
}
```

变更后：
调用collections模块BitVector.has接口时，当传入的toIndex等于容器的长度时，会触发jscrash从而报错返回异常信息。示例如下：

```ts
import { collection } from '@kit.ArkTS';

let bitVector: collections.BitVector = new collections.BitVector(0);

bitVector.push(1);
bitVector.push(1);
bitVector.push(1);
bitVector.push(1);
bitVector.push(1); // bitVector: [1, 1, 1, 1, 1]

// 变更后：has接口因为越界读取会触发jscrash报错
try {
  let res: boolean = bitVector.has(0, 0, 5);
  console.info("res: " + res);
} catch (err) {
  console.error("error message: " + err.message);
  // 输出结果为error message: The value of "toIndex" is out of range. It must be >= 0 && < 5. Received value is: 5
}
```

**起始 API Level**

12

**变更发生版本**

OpenHarmony SDK 5.1.0.56

**变更的接口/组件**

has(element: number, fromIndex: number, toIndex: number): boolean

**适配指导**

调用has接口时，针对toIndex等于容器的长度（length）的情况，需要开发者注意进行适配。主要适配建议如下：

将toIndex入参长度调整为length-1，避免发生越界情况导致jscrash。