#include<stdio.h>
#include<stdint.h>

int main(){
  int eax;
  int a[3];
  const uint32_t base = 0x40000000;
  uint32_t leaf;

  //for (leaf = base + 0xff00; leaf >= base; leaf -= 0x100) {
  for (leaf = base + 0xff00; leaf >= base; leaf -= 0x1) {
    __asm__("mov %0, %%eax\n\t" :: "r" (leaf));
    __asm__("cpuid\n\t");
    __asm__("mov %%eax, %0\n\t" : "=r" (eax));
    __asm__("mov %%ebx, %0\n\t" : "=r" (a[0]));
    __asm__("mov %%ecx, %0\n\t" : "=r" (a[1]));
    __asm__("mov %%edx, %0\n\t" : "=r" (a[2]));

    if (a[2] > 0){
      printf("leaf: %x\n",leaf);
      printf("EAX dec: %d\n",eax);
      printf("EAX: %x\n",eax);
      printf("EBX: %x\n",a[0]);
      printf("ECX: %x\n",a[1]);
      printf("EDX: %x\n",a[2]);
      printf("CPUID: %s\n\n",&a);
    }
  }
  return  0;
}
