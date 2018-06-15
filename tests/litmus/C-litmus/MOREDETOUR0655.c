// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0655.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r3_0; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  vars[1] = 2;
  vars[2] = 1;
  int v14 = (v2_r3 == 0);
  atom_0_r3_0 = v14;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 2;

  int v4_r3 = vars[0];
  int v15 = (v4_r3 == 0);
  atom_2_r3_0 = v15;
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
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v5 = vars[2];
  int v6 = (v5 == 2);
  int v7 = atom_0_r3_0;
  int v8 = vars[1];
  int v9 = (v8 == 2);
  int v10 = atom_2_r3_0;
  int v11_conj = v9 & v10;
  int v12_conj = v7 & v11_conj;
  int v13_conj = v6 & v12_conj;
  if (v13_conj == 1) assert(0);
  return 0;
}