# commonlibrary子系统JS API变更Changelog

OpenHarmony 3.2.10.1(Mr)版本相较于OpenHarmony 3.2.beta4版本，commonlibrary子系统的API变更如下

## cl.公共基础类库子系统.1 错误码及信息变更
公共基础类库子系统子系统中ArrayList、List、LinkedList、Stack、Queue、Deque、PlainArray、LightWeightMap、LightWeightSet、HashMap、HashSet、TreeMap、TreeSet类的接口抛出的错误码及信息变更：

变更后的错误码详细介绍请参见[语言基础类库错误码](../../../application-dev/reference/errorcodes/errorcode-utils.md)。

已使用相关接口开发的应用无需重新适配。

**关键的接口/组件变更**
各个类中的接口重新定义了错误码抛出的信息，并在对应模块的`*.d.ts`声明文件中通过'@throws'标签进行标示。
示例如下：
ArrayList类变更前：
constructor();
ArrayList类变更后：
@throws { BusinessError } 10200012 - The ArrayList's constructor cannot be directly invoked.
constructor();

**变更影响**

暂无影响。
