// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/LB+PPO0464.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[1] = v4_r3;
  int v19 = (v2_r1 == 1);
  atom_0_r1_1 = v19;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  int v7_r3 = v6_r1 ^ v6_r1;
  vars[2+v7_r3] = 1;
  int v9_r6 = vars[2];
  int v10_r7 = v9_r6 ^ v9_r6;
  vars[3+v10_r7] = 1;
  vars[3] = 2;
  int v12_r11 = vars[3];
  vars[0] = 1;
  int v20 = (v6_r1 == 1);
  atom_1_r1_1 = v20;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  vars[3] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v13 = vars[3];
  int v14 = (v13 == 2);
  int v15 = atom_0_r1_1;
  int v16 = atom_1_r1_1;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}