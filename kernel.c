#define SCREEN_LINE_COUNT 25
#define SCREEN_COLUMN_COUNT 80
#define SCREEN_ELEMENT_BYTES 2

void kmain(void)
{
  const char *str = "A Toy Kernel";
  char *vidptr = (char*) 0xb8000; 	//video mem begins here.
  unsigned i = 0;
  unsigned j = 0;
  
  /* clear the screen */
  while(j < SCREEN_COLUMN_COUNT * SCREEN_LINE_COUNT * SCREEN_ELEMENT_BYTES) {
    vidptr[j] = ' ';
    vidptr[j+1] = 0x07;
    j = j + 2;
  }
  
  j = 0;
  
  /* write string to video memory */
  while(str[j] != "\0") {
    /* ascii value */
    vidptr[i] = str[j];
    
    /* attribute-byte: give character black bg and light grey fg */
    vidptr[i+1] = 0x07;
    ++j;
    i = i + 2;
  }
  
  return;
}
