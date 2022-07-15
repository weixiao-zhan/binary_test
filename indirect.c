/******************** Indirect control flow test cases ***********************/

int SwitchStatement(int x) {
    /* The Intel compiler for IA-64 requires at least 18 entries to
       trigger the generation of a jump table. */
    switch (x) {
      case 0:
        x += 11;
        break;
      case 1:
        x += 10;
        break;
      case 2:
        x -= 12;
        break;
      case 3:
        x *= 31;
        break;
      case 4:
        x /= 42;
        break;
      case 5:
        x %= 57;
        break;
      case 6:
        x <<= 2;
        break;
      case 7:
        x >>= 3;
        break;
      case 8:
        x ^= 0xfe;
        break;
      case 9:
        x &= 0x44;
        break;
      case 10:
        x |= 0x21;
        break;
      case 11:
        x += 110;
        break;
      case 12:
        x-= 112;
        break;
      case 13:
        x *= 133;
        break;
      case 14:
        x /= 142;
        break;
      case 15:
        x %= 157;
        break;
      case 16:
        x <<= 12;
        break;
      case 17:
        x >>= 13;
        break;
      case 18:
        x ^= 0x1fe;
        break;
      case 19:
        x &= 0x144;
        break;
    };

    return x;
}

