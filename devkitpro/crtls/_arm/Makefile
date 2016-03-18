include ../../base_rules

all:
	arm-gnu-eabi-gcc  -x assembler-with-cpp -marm -c $(CRT)_crt0.s -o$(CRT)_crt0.o
	arm-gnu-eabi-gcc  -x assembler-with-cpp -mthumb -c $(CRT)_crt0.s -o thumb/$(CRT)_crt0.o
