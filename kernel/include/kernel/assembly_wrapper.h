#ifndef _KERNEL_ASSEMBLY_WRAPPER_H
#define _KERNEL_ASSEMBLY_WRAPPER_H

/**
Sends the given data to the given I/O port. Defined in io.s
Input:
port - The I/O port to send the data to
data - The data to send to the I/O port
Output:
*/
void outb(unsigned short port, unsigned char data);

#endif /* end of include guard: _KERNEL_ASSEMBLY_WRAPPER_H */
