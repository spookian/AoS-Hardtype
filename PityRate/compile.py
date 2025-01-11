import os
import sys

DEFAULT_DKP_PATH = "C:\\devkitPro"
DKP_CC           = "\\devkitARM\\bin\\arm-none-eabi-gcc"
DKP_AS           = "\\devkitARM\\bin\\arm-none-eabi-as"
DKP_OBJCOPY      = "\\devkitARM\\bin\\arm-none-eabi-objcopy"
LD_FLAGS = " -g -mthumb -mthumb-interwork -nodefaultlibs -nostartfiles -Wl,--no-check-sections -T main.ld"
C_FLAGS = " -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork -c"

C_FILES = " .\\src\\pityTable.c .\\src\\pityCore.c"

OBJ_FILES = " include_game.o trampoline.o pityTable.o pityCore.o"

def test_program(path):
    ERRORCODE = os.system(path)
    if (ERRORCODE != 0):
        print("compile.py: Compiliation failed.")
        sys.exit(0)
        
if (os.path.exists("./build") == False):
    print("Creating build folder...")
    os.mkdir("./build")

print("Compiling C files...")
test_program( DEFAULT_DKP_PATH + DKP_CC + C_FILES + C_FLAGS )

print("Compiling Assembly files...")
test_program( DEFAULT_DKP_PATH + DKP_AS + " .\\asm\\trampoline.s -o trampoline.o" + " -mcpu=arm7tdmi -mthumb -mthumb-interwork")
test_program( DEFAULT_DKP_PATH + DKP_AS + " .\\asm\\include_game.s -o include_game.o" + " -I .\\ -mcpu=arm7tdmi -mthumb -mthumb-interwork")

print("Linking files together...")
test_program( DEFAULT_DKP_PATH + DKP_CC + OBJ_FILES + LD_FLAGS + " -o .\\build\\pityAria.elf")

print("Building rom...\n")
test_program( DEFAULT_DKP_PATH + DKP_OBJCOPY + " -O binary .\\build\\pityAria.elf .\\build\\pityAria.gba")
test_program("del *.o")
print("Done!")