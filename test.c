int main(void) {
  char *text = "Stack executable!\n";
  char buf[19] = {0xb8, 0x01, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x00,
                  0xba, 0x12, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x0f, 0x0b};

  char *bufptr = buf;
  char *textptr = text;

  asm("mov rsi, %0\n"
      "jmp %1"
      : "=m"(textptr)
      : "m"(bufptr));
}
