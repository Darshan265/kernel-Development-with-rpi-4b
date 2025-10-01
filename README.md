# kernel-Development-with-rpi-4b
-Projects related to kernel development with raspberry pi 4B( ARM Cortex A-72). 

## Prerequisites
- Raspberry Pi 4B with Raspberry Pi OS (preferably 32-bit "Buster" or later)
- build-essential, raspberrypi-kernel-headers installed
- Terminal or SSH access to Pi

## Set UP the Development Environment
On Rapsberry Pi 4B, run:
- ``$sudo apt update``
- ``$sudo apt install build-essential raspberrypi-kernel-headers -y``

Verify header location (typically /lib/modules/$(uname -r)/build exists):
- ``$ls /lib/modules/$(uname -r)/build``

# Kernel Development Commands — Quick Reference

A compact README listing common Linux commands used during kernel development. Columns: **Command**, **Syntax**, **Purpose**, **Example**.

| Command                     |                                                 Syntax / Format | Purpose                                                              | Example                                                       |                |                 |
| --------------------------- | --------------------------------------------------------------: | -------------------------------------------------------------------- | ------------------------------------------------------------- | -------------- | --------------- |
| `make`                      |                                                 `make [target]` | Build kernel or specific targets.                                    | `make` (build default), `make bzImage`                        |                |                 |
| `make menuconfig`           |                                               `make menuconfig` | Text-based kernel configuration menu.                                | `make menuconfig`                                             |                |                 |
| `make xconfig`              |                                                  `make xconfig` | Qt GUI kernel configuration.                                         | `make xconfig`                                                |                |                 |
| `make defconfig`            |                                                `make defconfig` | Create default .config for current arch.                             | `make defconfig`                                              |                |                 |
| `make oldconfig`            |                                                `make oldconfig` | Update old .config with new options.                                 | `make oldconfig`                                              |                |                 |
| `make modules`              |                                                  `make modules` | Build kernel modules only.                                           | `make modules`                                                |                |                 |
| `make modules_install`      |                                     `sudo make modules_install` | Install built modules to `/lib/modules/$VER`.                        | `sudo make modules_install`                                   |                |                 |
| `make M=dir`                |                                   `make M=<module-dir> modules` | Build an out-of-tree kernel module directory.                        | `make M=/home/user/driver modules`                            |                |                 |
| `make ARCH`                 |                                              `make ARCH=<arch>` | Specify target architecture.                                         | `make ARCH=arm64 defconfig`                                   |                |                 |
| `make CROSS_COMPILE`        |                                  `make CROSS_COMPILE=<prefix>-` | Use cross-compiler toolchain.                                        | `make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage`     |                |                 |
| `make clean`                |                                                    `make clean` | Remove most build artifacts.                                         | `make clean`                                                  |                |                 |
| `make mrproper`             |                                                 `make mrproper` | Remove kernel build artifacts and .config.                           | `make mrproper`                                               |                |                 |
| `insmod`                    |                                       `sudo insmod <module.ko>` | Insert a kernel module.                                              | `sudo insmod hello.ko`                                        |                |                 |
| `rmmod`                     |                                           `sudo rmmod <module>` | Remove a loaded module.                                              | `sudo rmmod hello`                                            |                |                 |
| `modprobe`                  |                                           `sudo modprobe <mod>` | Insert module and resolve dependencies.                              | `sudo modprobe i2c_dev`                                       |                |                 |
| `lsmod`                     |                                                         `lsmod` | List loaded kernel modules.                                          | `lsmod                                                        | grep hello`    |                 |
| `modinfo`                   |                                   `modinfo <module.ko or name>` | Show metadata about module.                                          | `modinfo hello.ko`                                            |                |                 |
| `depmod`                    |                                                `sudo depmod -a` | Generate module dependency list.                                     | `sudo depmod -a`                                              |                |                 |
| `dmesg`                     |                                               `dmesg [options]` | Kernel ring buffer logs.                                             | `dmesg                                                        | tail -n 50`    |                 |
| `journalctl -k`             |                                                 `journalctl -k` | Show kernel messages from systemd journal.                           | `journalctl -k --since "1 hour ago"`                          |                |                 |
| `tail -f /var/log/kern.log` |                                             `tail -f <logfile>` | Live kernel log tailing (distro-dependent).                          | `sudo tail -f /var/log/kern.log`                              |                |                 |
| `objdump`                   |                                          `objdump -D <vmlinux>` | Disassemble kernel image or module.                                  | `objdump -D vmlinux                                           | less`          |                 |
| `readelf`                   |                                             `readelf -a <file>` | Show ELF headers and sections.                                       | `readelf -h vmlinux`                                          |                |                 |
| `nm`                        |                                                 `nm -n <vmlinux | module.o>`                                                           | List symbols in object files.                                 | `nm -n vmlinux | grep my_symbol` |
| `addr2line`                 |                                 `addr2line -e <vmlinux> <addr>` | Map address to source file:line (requires vmlinux with debug info).  | `addr2line -e vmlinux 0xffffffff81012345`                     |                |                 |
| `perf record`               |                              `perf record -e <events> -- <cmd>` | Profile kernel or user workloads.                                    | `sudo perf record -a -g -- sleep 10`                          |                |                 |
| `perf report`               |                                                   `perf report` | View perf data.                                                      | `sudo perf report`                                            |                |                 |
| `trace-cmd record`          |                                   `trace-cmd record -e <event>` | Ftrace trace recorder.                                               | `sudo trace-cmd record -e sched_switch`                       |                |                 |
| `trace-cmd report`          |                                              `trace-cmd report` | Show trace-cmd results.                                              | `sudo trace-cmd report`                                       |                |                 |
| `ftrace`                    | `echo <function> > /sys/kernel/debug/tracing/set_ftrace_filter` | Kernel function tracer via debugfs.                                  | `echo do_exit > /sys/kernel/debug/tracing/set_ftrace_filter`  |                |                 |
| `bpftrace`                  |                                  `sudo bpftrace -e '<program>'` | Dynamic tracing with BPF.                                            | `sudo bpftrace -e 'kprobe:do_exit {printf("pid %d\n", pid)}'` |                |                 |
| `kgdb`                      |                                                          `kgdb` | Kernel remote debugger (over serial or network).                     | `echo ttyS0,115200 > /proc/sys/kernel/printk` (setup)         |                |                 |
| `gdb vmlinux`               |                                                   `gdb vmlinux` | Debug kernel image with symbols.                                     | `gdb vmlinux` then `target remote /dev/ttyUSB0`               |                |                 |
| `git`                       |                                              `git <subcommand>` | Kernel source management.                                            | `git clone https://git.kernel.org/.../linux.git`              |                |                 |
| `git bisect`                |       `git bisect start; git bisect bad; git bisect good <rev>` | Find commit that introduced a bug.                                   | `git bisect start; git bisect bad; git bisect good v5.4`      |                |                 |
| `scripts/config`            |                       `scripts/config --set-val <CONFIG_FOO> y` | Manage kernel .config from scripts.                                  | `./scripts/config --set-val CONFIG_DEBUG_INFO y`              |                |                 |
| `scripts/get_maintainer.pl` |                            `./scripts/get_maintainer.pl <file>` | Find maintainers for a subsystem/file.                               | `./scripts/get_maintainer.pl drivers/net/`                    |                |                 |
| `checkpatch.pl`             |                                 `scripts/checkpatch.pl <patch>` | Check patch style for kernel contribution.                           | `scripts/checkpatch.pl 0001-fix-foo.patch`                    |                |                 |
| `patch`                     |                         `git apply` or `patch -p1 < file.patch` | Apply patches to source.                                             | `git apply fix.patch`                                         |                |                 |
| `make config`               |                                                 `make <target>` | Build specific targets like `modules`, `headers_install`, `install`. | `sudo make modules_install && sudo make install`              |                |                 |

## Notes

* Use `vmlinux` with debug symbols for accurate symbolication.
* Many tracing/profiling tools require `CONFIG_*` options enabled and root privileges.
* Cross-build environment needs `CROSS_COMPILE` and proper toolchain.


 




