make CRT=gba
make CRT=gp32
make CRT=er
make CRT=gp32_gpsdk
make CRT=ds_arm7
make CRT=ds_arm9
make CRT=ds_cart
make CRT=3dsx
#arm-gnu-eabi-gcc -march=armv6k -mfloat-abi=hard -c 3dsx_crt0.s -o armv6k/fpu/3dsx_crt0.o