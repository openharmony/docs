# Third-Party Library Changelog

## libc++ condition_variable::wait_for Changed

**Access Level**

Public API

**Reason for Change**

Before the change, the **condition_variable::wait_for** API of the libc++ library uses the system wall clock time, which is affected by changes to the system time and does not meet expectations.

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

Here, 0x59682F000000E941 ns = 6442450944s = 2174-02-25 17:42:24. When the current system time plus the wait time specified in the **wait_for** API exceeds this value, it gets truncated, and **__libcpp_condvar_timedwait** returns immediately.

**Impact of the Change**

This change requires application adaptation.

- Before the change, the **condition_variable::wait_for** API of the libc++ library uses the system wall clock time and is affected by changes to the system time. When the current system time plus the wait time specified in the API exceeded a specific value (0x59682F000000E941), the **condition_variable::wait_for** API returns immediately.
  
- After the change, the **condition_variable::wait_for** API of the libc++ library uses a monotonically increasing time and is not affected by changes to the system time.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 6.0.0.39

**Adaptation Guide**

The libc++ library is released in binary form in the NDK (**libc++_shared.so**). The prototype of the **condition_variable::wait_for** API remains unchanged. Only the implementation has been aligned with the C++ standard and platforms like Android, iOS, and Windows. You can simply recompile your applications after updating the NDK.
