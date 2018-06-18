// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1170.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r7_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 4;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[0+v3_r3] = 1;
  vars[0] = 2;
  int v5_r7 = vars[0];
  vars[0] = 3;
  int v12 = (v2_r1 == 1);
  atom_1_r1_1 = v12;
  int v13 = (v5_r7 == 2);
  atom_1_r7_2 = v13;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r7_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v6 = vars[0];
  int v7 = (v6 == 4);
  int v8 = atom_1_r1_1;
  int v9 = atom_1_r7_2;
  int v10_conj = v8 & v9;
  int v11_conj = v7 & v10_conj;
  if (v11_conj == 1) assert(0);
  return 0;
}