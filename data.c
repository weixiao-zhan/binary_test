const int number[] __attribute__ ((section(".text#"))) = {0x1231, 0xaba1, 0x4309, 0x68ab, 0x891f};
int DataInText(int x) {
    if (x > 10) return number[x % 5];
    else return number[(x + 10) % 5];
}
