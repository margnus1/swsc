// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0022.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r6_0; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  int v3_r5 = v2_r3 ^ v2_r3;
  int v6_r6 = vars[2+v3_r5];
  vars[2] = 1;
  int v18 = (v6_r6 == 0);
  atom_0_r6_0 = v18;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v8_r1 = vars[2];
  int v9_r3 = v8_r1 ^ v8_r1;
  int v12_r4 = vars[0+v9_r3];
  int v19 = (v8_r1 == 1);
  atom_1_r1_1 = v19;
  int v20 = (v12_r4 == 0);
  atom_1_r4_0 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_0_r6_0 = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v13 = atom_0_r6_0;
  int v14 = atom_1_r1_1;
  int v15 = atom_1_r4_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}