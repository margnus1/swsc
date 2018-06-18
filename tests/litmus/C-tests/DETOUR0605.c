// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0605.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r3_0; 
volatile int atom_1_r8_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 3;

  int v2_r3 = vars[1];
  int v14 = (v2_r3 == 0);
  atom_0_r3_0 = v14;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;
  int v4_r3 = vars[2];
  int v5_r5 = v4_r3 ^ v4_r3;
  vars[0+v5_r5] = 1;
  int v7_r8 = vars[0];
  int v15 = (v7_r8 == 2);
  atom_1_r8_2 = v15;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[0] = 2;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_0_r3_0 = 0;
  atom_1_r8_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v8 = atom_0_r3_0;
  int v9 = vars[0];
  int v10 = (v9 == 3);
  int v11 = atom_1_r8_2;
  int v12_conj = v10 & v11;
  int v13_conj = v8 & v12_conj;
  if (v13_conj == 1) assert(0);
  return 0;
}