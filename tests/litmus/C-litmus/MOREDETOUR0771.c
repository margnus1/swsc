// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0771.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_4; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 3;
  int v4_r4 = vars[1];
  vars[0] = 1;
  int v19 = (v2_r1 == 1);
  atom_1_r1_1 = v19;
  int v20 = (v4_r4 == 4);
  atom_1_r4_4 = v20;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v6_r1 = vars[1];
  vars[1] = 2;

  int v8_r4 = vars[1];
  int v21 = (v8_r4 == 3);
  atom_2_r4_3 = v21;
  int v22 = (v6_r1 == 1);
  atom_2_r1_1 = v22;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 4;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[0] = 0;
  vars[1] = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_4 = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v9 = vars[0];
  int v10 = (v9 == 2);
  int v11 = atom_1_r1_1;
  int v12 = atom_1_r4_4;
  int v13 = atom_2_r4_3;
  int v14 = atom_2_r1_1;
  int v15_conj = v13 & v14;
  int v16_conj = v12 & v15_conj;
  int v17_conj = v11 & v16_conj;
  int v18_conj = v10 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}