.intel_syntax noprefix
.global load_gdt

# load_gdt - loads the gdt from the given address
#        [esp + 4] the address of the gdt struct
load_gdt:
  mov eax, [esp+4]
  lgdt [eax]
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  jmp 0x08:flush
  flush:
    ret
