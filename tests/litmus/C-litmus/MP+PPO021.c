// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO021.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r10_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 2;
  int v4_r4 = vars[1];
  int v5_r5 = v4_r4 ^ v4_r4;
  vars[2+v5_r5] = 1;
  int v7_r8 = vars[2];
  int v8_r9 = v7_r8 ^ v7_r8;
  int v11_r10 = vars[0+v8_r9];
  int v18 = (v2_r1 == 1);
  atom_1_r1_1 = v18;
  int v19 = (v11_r10 == 0);
  atom_1_r10_0 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r10_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v12 = vars[1];
  int v13 = (v12 == 2);
  int v14 = atom_1_r1_1;
  int v15 = atom_1_r10_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}