cmd_/home/shushanth/charDeviceDriver/charDeviceDriver.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/shushanth/charDeviceDriver/charDeviceDriver.ko /home/shushanth/charDeviceDriver/charDeviceDriver.o /home/shushanth/charDeviceDriver/charDeviceDriver.mod.o ;  true