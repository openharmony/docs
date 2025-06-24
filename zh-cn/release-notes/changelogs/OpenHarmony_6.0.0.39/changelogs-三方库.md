# 三方库Changelog

## libc++ condition_variable::wait_for接口变更

**访问级别**

公开接口

**变更原因**

变更前，libc++库condition_variable::wait_for接口使用系统墙上时间，受到修改系统时间的影响，和开发者预期不符合。

```
template <class _Rep, class _Period>
cv_status
condition_variable::wait_for(unique_lock<mutex>& __lk,
                             const chrono::duration<_Rep, _Period>& __d)
{
    ...

#if defined(_LIBCPP_HAS_COND_CLOCKWAIT)
    using __clock_tp_ns = time_point<steady_clock, nanoseconds>;
    __ns_rep __now_count_ns = _VSTD::__safe_nanosecond_cast(__c_now.time_since_epoch()).count();
#else
    using __clock_tp_ns = time_point<system_clock, nanoseconds>;
    __ns_rep __now_count_ns = _VSTD::__safe_nanosecond_cast(system_clock::now().time_since_epoch()).count();
#endif
    
    ...
    __do_timed_wait(...);
    ...
}
```

```
void
condition_variable::__do_timed_wait(unique_lock<mutex>& lk,
     chrono::time_point<chrono::system_clock, chrono::nanoseconds> tp) noexcept
{
    ...
    nanoseconds d = tp.time_since_epoch();
    if (d > nanoseconds(0x59682F000000E941))
        d = nanoseconds(0x59682F000000E941);
    ...
    int ec = __libcpp_condvar_timedwait(&__cv_, lk.mutex()->native_handle(), &ts);
    ...
}
```

其中0x59682F000000E941 ns = 6442450944s = 2174-02-25 17:42:24，当系统当前时间加上wait_for接口入参需要等待的时间超过该值时被截断，__libcpp_condvar_timedwait会立即返回。

**变更影响**

此变更涉及应用适配。

- 变更前：libc++库condition_variable::wait_for接口使用系统墙上时间，受修改系统时间影响；当系统当前时间加上接口入参需要等待的时间超过特定值（0x59682F000000E941），condition_variable::wait_for接口会立即返回。
  
- 变更后：libc++库condition_variable::wait_for接口使用单调递增时间，不受修改系统时间影响。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 6.0.0.39开始。

**适配指导**

libc++库以二进制的形式发布在NDK中（libc++_shared.so）。condition_variable::wait_for接口原型未变，只是实现和C++标准、安卓、iOS、Windows等平台保持一致，开发者更新NDK后重新编译应用即可。
