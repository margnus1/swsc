// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/LB+PPO0259.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[5]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[1] = v4_r3;
  int v20 = (v2_r1 == 1);
  atom_0_r1_1 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  int v8_r3 = vars[1];
  int v9_r4 = v8_r3 ^ v8_r3;
  int v12_r5 = vars[2+v9_r4];
  int v13_cmpeq = (v12_r5 == v12_r5);
  if (v13_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[3] = 1;
  int v15_r9 = vars[3];
  int v16_cmpeq = (v15_r9 == v15_r9);
  if (v16_cmpeq)  goto lbl_LC01; else goto lbl_LC01;
lbl_LC01:;
  vars[4] = 1;
  vars[0] = 1;
  int v21 = (v6_r1 == 1);
  atom_1_r1_1 = v21;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  vars[4] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v17 = atom_0_r1_1;
  int v18 = atom_1_r1_1;
  int v19_conj = v17 & v18;
  if (v19_conj == 1) assert(0);
  return 0;
}