// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/3.2W+sync+sync+rfi-data.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_2_r3_2; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;

  vars[2] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 2;
  int v2_r3 = vars[2];
  int v3_r4 = v2_r3 ^ v2_r3;
  int v4_r4 = v3_r4 + 1;
  vars[0] = v4_r4;
  int v15 = (v2_r3 == 2);
  atom_2_r3_2 = v15;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_2_r3_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v5 = vars[0];
  int v6 = (v5 == 2);
  int v7 = vars[1];
  int v8 = (v7 == 2);
  int v9 = vars[2];
  int v10 = (v9 == 2);
  int v11 = atom_2_r3_2;
  int v12_conj = v10 & v11;
  int v13_conj = v8 & v12_conj;
  int v14_conj = v6 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}