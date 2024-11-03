
#include <stdint.h>
#include "print_functions.c"

#define low_16(address) (uint16_t)((address) & 0xFFFF)
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)


typedef struct 
{
    /* data */uint16_t low_offset;
    uint16_t selector;
    uint8_t always_0;
    uint8_t flags;
    uint16_t high_offset;
} __attribute__((packed))idt_gate;

typedef struct 
{
    // datat segment 
     uint32_t ds;

    //registers for genral perpose
    uint32_t edi, esi ,ebp ,esp , eax, ebx ,ecx ,edx;
     
    uint32_t interupt_number,err_Code;

     uint32_t eip, cs, eflags, useresp , ss;
} registers_stc;


idt_gate idt_table[256];
unsigned char* exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment not present",
    "Stack fault",
    "General protection fault",
    "Page fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Fault",
    "Machine Check", 
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};


void set_idt_gate(int n , uint32_t handler)
{
idt_table[n].low_offset=low_16(handler);
idt_table[n].selector=0x08;
idt_table[n].always_0=0;
idt_table[n].flags=0x8e;
idt_table[n].high_offset=high_16(handler);

}

void isr_handler(registers_stc *r)
{
    if (r->interupt_number<32)
    {
    print_Str(exception_messages[r->interupt_number]);
    print_Str("\n");
    print_Str("you a stupid mistake dumass!!! halting. ");
    }
}

void initialize_idt(){
    //remapping the pic for protected mode 
    port_byte_out(0x20,0x11);
    port_byte_out(0xa0,0x11);

    port_byte_out(0x21,0x20);
    port_byte_out(0xA1,0x28);

    port_byte_out(0x21,0x04);
    port_byte_out(0xa1,0x02);

    port_byte_out(0x21,0x01);
    port_byte_out(0xA1,0x01);
    port_byte_out(0x21,0x0);
    port_byte_out(0xA1,0x0);
}
void isr_install()
{
  set_idt_gate(0,(uint32_t) isr0);
  set_idt_gate(1,(uint32_t) isr1);
  set_idt_gate(2,(uint32_t) isr2);
  set_idt_gate(3,(uint32_t) isr3);
  set_idt_gate(4,(uint32_t) isr4);
  set_idt_gate(5,(uint32_t) isr5);
  set_idt_gate(6,(uint32_t) isr6);
  set_idt_gate(7,(uint32_t) isr7);
  set_idt_gate(8,(uint32_t) isr8);
  set_idt_gate(9,(uint32_t) isr9);
  set_idt_gate(10,(uint32_t)isr10);
  set_idt_gate(11,(uint32_t) isr11);
  set_idt_gate(12,(uint32_t) isr12);
  set_idt_gate(13,(uint32_t) isr13);
  set_idt_gate(14,(uint32_t) isr14);
  set_idt_gate(15,(uint32_t) isr15);
  set_idt_gate(16,(uint32_t) isr16);
  set_idt_gate(17,(uint32_t) isr17);
  set_idt_gate(18,(uint32_t) isr18);
  set_idt_gate(19,(uint32_t) isr19);
  set_idt_gate(20,(uint32_t) isr20);
  set_idt_gate(21,(uint32_t) isr21);
  set_idt_gate(22,(uint32_t) isr22);
  set_idt_gate(23,(uint32_t) isr23);
  set_idt_gate(24,(uint32_t) isr24);
  set_idt_gate(25,(uint32_t) isr25);
  set_idt_gate(26,(uint32_t) isr26);
  set_idt_gate(27,(uint32_t) isr27);
  set_idt_gate(28,(uint32_t) isr28);
  set_idt_gate(29,(uint32_t) isr29);
  set_idt_gate(30,(uint32_t) isr30);
  set_idt_gate(31,(uint32_t) isr31);

  set_idt_gate(31,(uint32_t) isr0);
  set_idt_gate(29,(uint32_t) isr0);
  set_idt_gate(29,(uint32_t) isr0);
  set_idt_gate(29,(uint32_t) isr0);
 

  
 
}