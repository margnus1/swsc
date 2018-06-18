// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0618.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_0; 
volatile int atom_1_r6_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 3;

  int v2_r3 = vars[1];
  int v11 = (v2_r3 == 0);
  atom_0_r3_0 = v11;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;
  vars[1] = 2;
  vars[0] = 1;
  int v4_r6 = vars[0];
  int v12 = (v4_r6 == 2);
  atom_1_r6_2 = v12;
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
  vars[0] = 0;
  atom_0_r3_0 = 0;
  atom_1_r6_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v5 = atom_0_r3_0;
  int v6 = vars[0];
  int v7 = (v6 == 3);
  int v8 = atom_1_r6_2;
  int v9_conj = v7 & v8;
  int v10_conj = v5 & v9_conj;
  if (v10_conj == 1) assert(0);
  return 0;
}