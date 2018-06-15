// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0985.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r6_2; 
volatile int atom_1_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  vars[1] = 1;
  vars[1] = 2;
  int v2_r6 = vars[1];
  int v3_r7 = v2_r6 ^ v2_r6;
  int v4_r7 = v3_r7 + 1;
  vars[2] = v4_r7;
  int v13 = (v2_r6 == 2);
  atom_0_r6_2 = v13;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[2] = 2;

  int v6_r3 = vars[0];
  int v14 = (v6_r3 == 0);
  atom_1_r3_0 = v14;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_0_r6_2 = 0;
  atom_1_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v7 = vars[2];
  int v8 = (v7 == 2);
  int v9 = atom_0_r6_2;
  int v10 = atom_1_r3_0;
  int v11_conj = v9 & v10;
  int v12_conj = v8 & v11_conj;
  if (v12_conj == 1) assert(0);
  return 0;
}