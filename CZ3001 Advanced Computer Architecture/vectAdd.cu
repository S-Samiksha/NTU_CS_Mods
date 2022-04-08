#include <stdio.h>

__global__ void vector_add_cu(int *d_c, int *d_a, int *d_b, int n){ 
    int i = blockIdx.x * blockDim.x + threadIdx.x; 
    c[i] = d_a[i] + d_b[i]; 

}
int main(void){
    int N = 4, i=0;
    int a[N] = {22,13,16, 5};
    int b[N] = {5, 22, 17, 37};
    int c[N]; 
    int *d_a, *d_b, *d_c; 
    cudaMalloc((void**)&d_a, sizeof(int)*N); 
    cudaMalloc((void**)&d_b, sizeof(int)*N); 
    cudaMalloc((void**)&d_c, sizeof(int)*N); 
    cudaMemcpy(d_a, a, sizeof(int)*N, cudaMemcpyHostToDevice); 
    cudaMemcpy(d_b, b, sizeof(int)*N, cudaMemcpyHostToDevice); 
    vector_add_cu<<<1,N>>>(d_c, d_a, d_b, N); // note: 1 thread
    cudaDeviceSynchronize();
    cudaMemcpy(c, d_c, sizeof(int)*N, cudaMemcpyDeviceToHost); 
    printf("value of d_c: ");
    for (i=0; i<N;i++){
        printf(" %d ", d_c[i]);
    }
    printf("\n");
    cudaFree(d_a); 
    cudaFree(d_b);
    cudaFree(d_c);
  
} 
