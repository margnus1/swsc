// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S0014.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  int v2_r3 = vars[0];
  int v4_r4 = vars[0];
  int v5_r5 = v4_r4 ^ v4_r4;
  int v6_r5 = v5_r5 + 1;
  vars[1] = v6_r5;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v8_r1 = vars[1];
  int v9_r3 = v8_r1 ^ v8_r1;
  int v10_r3 = v9_r3 + 1;
  vars[0] = v10_r3;
  int v15 = (v8_r1 == 1);
  atom_1_r1_1 = v15;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v11 = vars[0];
  int v12 = (v11 == 2);
  int v13 = atom_1_r1_1;
  int v14_conj = v12 & v13;
  if (v14_conj == 1) assert(0);
  return 0;
}