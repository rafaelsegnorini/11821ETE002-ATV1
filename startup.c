#include <stdint.h>
#include <stdlib.h>
#define SRAM_START 0x20000000U     /Início da memória SRAM/
#define SRAM_SIZE  (128U * 1024U) /Tamanho da SRAM/
#define SRAM_END   ((SRAM_START)+ \
                    (SRAM_SIZE)) /Final da SRAM STM32F411/

#define STACK_START SRAM_END     /Início da Stack/

int main(void);

void reset_handler (void);
void nmi_handler (void) __attribute__ ((alias("default_handler")));
void hardfault_handler (void) __attribute__ ((alias("default_handler")));
void memmanage_handler (void) __attribute__ ((alias("default_handler")));
void busfault_handler (void) __attribute__ ((alias("default_handler")));
void usagefault_handler(void) __attribute__ ((alias("default_handler")));
void svc_handler (void) __attribute__ ((alias("default_handler")));
void debugmon_handler (void) __attribute__ ((alias("default_handler")));
void pendsv_handler (void) __attribute__ ((alias("default_handler")));
void systick_handler (void) __attribute__ ((alias("default_handler")));

uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
STACK_START,             /* 0x0000 0000 */
(uint32_t)reset_handler,    /* 0x0000 0004 */
(uint32_t)nmi_handler,       /* 0x0000 0008 */
(uint32_t)default_handler, /* 0x0000 000c */
(uint32_t)default_handler, /* 0x0000 0010 */
(uint32_t)default_handler, /* 0x0000 0014 */
(uint32_t)default_handler, /* 0x0000 0018 */
0,                          /* 0x0000 001c */
0,          /* 0x0000 0020 */
0, /* 0x0000 0024 */
0, /* 0x0000 0028 */
(uint32_t)default_handler, /* 0x0000 002c */
(uint32_t)default_handler, /* 0x0000 0030 */
0, /* 0x0000 0034 */
(uint32_t)default_handler, /* 0x0000 0038 */
(uint32_t)default_handler, /* 0x0000 003c */
};
void reset_handler(void)
{
}
void nmi_handler(void)
{
while(1){};
}
void default_handler(void)
{
while(1){};
}