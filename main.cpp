/* Demonstration and test (of your computer) of endienness
 *
 * This C programs shows how your computer handles integers (little endian
 * vs. big endian) and demonstrates the conversion of endianness.
 *
 * The program shows the byte order as a result of bit shifting (by 8 bits
 * at a time) and incrementing byte addresses.
 *
 * W. Newhall 11/2021 (original)
 */

#include <stdint.h>
#include <endian.h>
#include <stdio.h>

int main()
{
    uint32_t val = 0xABCDEF12;
    uint32_t be, le;
    uint8_t * pbyte;
    uint8_t * addr;
    int n;

    // Set a byte pointer to to the same address as the 32-bit value
    // so that we can increment byte-by-byte through the value.
    pbyte = (uint8_t*)&val;

    printf("\n======== Native Value on Host ========\n");
    be = htobe32(val);
    printf("Native Value: %08X\n", val);
    printf("                                 MSB      LSB\n");
    printf("Using bit shifting to get bytes: %02X %02X %02X %02X\n",
        (val>>24) & 0xFF,   // Shift and mask off a byte
        (val>>16) & 0xFF,
        (val>>8) & 0xFF,
        val & 0xFF
        );

    printf("\nUsing address increment to get bytes:\n");
    addr = pbyte;
    for(n=0; n<4; n++) {
        printf("At address %p: %02X\n", addr, *addr);
        addr++;
    }

    printf("Address of val (uint32_t): %p\n", &val);
    printf("Address of pbyte (uint8_t) (first byte of val): %p\n", pbyte);

    printf("\n======== After Conversion Host-to-Big-Endian ========\n");
    be = htobe32(val);
    printf("                                 MSB      LSB\n");
    printf("Using bit shifting to get bytes: %02X %02X %02X %02X\n",
        (be>>24) & 0xFF,
        (be>>16) & 0xFF,
        (be>>8) & 0xFF,
        be & 0xFF
        );

    printf("\nUsing address increment to get bytes:\n");
    addr = (uint8_t*)&be;
    for(n=0; n<4; n++) {
        printf("At address %p: %02X\n", addr, *addr);
        addr++;
    }

    printf("\n======== After Conversion Host-to-Little-Endian ========\n");
    le = htole32(val);
    printf("                                 MSB      LSB\n");
    printf("Using bit shifting to get bytes: %02X %02X %02X %02X\n",
        (le>>24) & 0xFF,
        (le>>16) & 0xFF,
        (le>>8) & 0xFF,
        le & 0xFF
        );

    printf("\nUsing address increment to get bytes:\n");
    addr = (uint8_t*)&le;
    for(n=0; n<4; n++) {
        printf("At address %p: %02X\n", addr, *addr);
        addr++;
    }

    return 0;
}
