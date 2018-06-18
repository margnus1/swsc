// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO286.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[5]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r14_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[2+v3_r3] = 1;
  int v5_r6 = vars[2];
  int v6_r7 = v5_r6 ^ v5_r6;
  int v9_r8 = vars[3+v6_r7];
  int v10_r10 = v9_r8 ^ v9_r8;
  vars[4+v10_r10] = 1;
  int v12_r13 = vars[4];
  int v13_cmpeq = (v12_r13 == v12_r13);
  if (v13_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v15_r14 = vars[0];
  int v19 = (v2_r1 == 1);
  atom_1_r1_1 = v19;
  int v20 = (v15_r14 == 0);
  atom_1_r14_0 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[1] = 0;
  vars[4] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r14_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v16 = atom_1_r1_1;
  int v17 = atom_1_r14_0;
  int v18_conj = v16 & v17;
  if (v18_conj == 1) assert(0);
  return 0;
}