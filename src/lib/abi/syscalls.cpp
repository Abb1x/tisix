#include "abi/syscalls.hpp"
#include <syscalls.hpp>

extern "C" TxResult tx_sys_debug(const char *args)
{
    return tx_syscall(TX_SYS_DEBUG, (void *)args);
}

extern "C" TxResult tx_sys_ipc(TxIpc *ipc)
{
    return tx_syscall(TX_SYS_IPC, (void *)ipc);
}

extern "C" TxResult tx_syscall(TxSyscall syscall, void *arg)
{
    uint64_t res = 0;
    (void)res;
#ifdef __x86_64__
    asm volatile("int $0x42"
                 :
                 : "a"((int)syscall), "b"(arg));
#endif

    return res;
}