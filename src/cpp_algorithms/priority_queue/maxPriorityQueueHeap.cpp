#include <cstddef>
#include <iostream>

// 编译的时候加上：gcc xxx.cpp -lstdc++

class MaxPriorityQueueHeap
{
public:
    MaxPriorityQueueHeap(int maxN){
        m_MaxN = maxN;
        m_pq = new int[m_MaxN];
    };

    bool isEmpty(){ return m_N == 0; }
    int size(){ return m_N; }

    void insert(int v){
        m_pq[++m_N] = v;
        swim(m_N);
    }

    int delMax(){
        int max = m_pq[1];
        exch(1, m_N--);
        m_pq[m_N+1] = 0;
        sink(1);
        return max;
    }

    bool less(int i, int j){
        return m_pq[i] < m_pq[j];
    }

    void exch(int i, int j){
        int temp = m_pq[i]; m_pq[i] = m_pq[j]; m_pq[j] = temp; 
    }

    void swim(int k){
        while(k>1 && less(k/2, k)){
            exch(k/2, k);
            k = k/2;
        }
    }

    void sink(int k){
        while(2*k <= m_N){
            int j = 2*k;
            if(j<m_N && less(j, j+1)) j++;
            if(!less(k,j)) break;
            exch(k,j);
            k = j;
        }
    }

    // 进行深拷贝的操作，否会引起浅拷贝，开辟到堆区的内存重复释放错误
    MaxPriorityQueueHeap(const MaxPriorityQueueHeap &pq){
        m_N = pq.m_N;
        m_MaxN = pq.m_MaxN;
        // m_pq = pq.m_pq; // 这会在拷贝的时候引发浅拷贝的问题
        m_pq = new int[pq.m_MaxN];
    }

    ~MaxPriorityQueueHeap(){
        if(m_pq != NULL){
            delete [] m_pq;
            m_pq = NULL;
        }
    };
private:
    int * m_pq;
    int m_N;
    int m_MaxN;
};

int main(){
    int arr[] = {23,23,5345,2,42,3,54,5,4,35,4,6,34,534,6,3,45,34,534,534,5};
    int M;
    printf("请输入优先队列的大小: ");
    scanf("%d", &M);
    // MaxPriorityQueueHeap * pq = new MaxPriorityQueueHeap(M);
    MaxPriorityQueueHeap pq(M);
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        pq.insert(arr[i]);
        if(pq.size() > M){
            pq.delMax();
        }
    }

    printf("筛选出来的最小的 %d 个 Transaction ********************\n",M);
    for(int j = 0; j<M; j++){
        printf("%d ",pq.delMax());
    }
    printf("\n");


    return 0;
}
