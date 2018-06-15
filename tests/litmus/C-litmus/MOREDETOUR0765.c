// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0765.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 
volatile int atom_3_r1_3; 

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
  vars[1] = 5;
  vars[0] = 1;
  int v22 = (v2_r1 == 1);
  atom_1_r1_1 = v22;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v4_r1 = vars[1];
  vars[1] = 2;

  int v6_r4 = vars[1];
  int v23 = (v6_r4 == 3);
  atom_2_r4_3 = v23;
  int v24 = (v4_r1 == 1);
  atom_2_r1_1 = v24;
  return NULL;
}

void *t3(void *arg){
label_4:;
  int v8_r1 = vars[1];
  vars[1] = 4;
  int v25 = (v8_r1 == 3);
  atom_3_r1_3 = v25;
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
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;
  atom_3_r1_3 = 0;

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
  int v12 = atom_2_r4_3;
  int v13 = atom_2_r1_1;
  int v14 = vars[1];
  int v15 = (v14 == 5);
  int v16 = atom_3_r1_3;
  int v17_conj = v15 & v16;
  int v18_conj = v13 & v17_conj;
  int v19_conj = v12 & v18_conj;
  int v20_conj = v11 & v19_conj;
  int v21_conj = v10 & v20_conj;
  if (v21_conj == 1) assert(0);
  return 0;
}