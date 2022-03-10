struct IDT_entry {
  unsigned short int offset_lowerbits;
  unsigned short int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned short int offset_higherbits;
}

struct IDT_entry IDT[IDT_SIZE];

void idt_init(void);
void kb_init(void);
void keyboard_handler_main(void);
