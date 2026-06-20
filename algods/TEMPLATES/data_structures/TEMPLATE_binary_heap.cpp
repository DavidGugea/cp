#include <bits/stdc++.h>
using namespace std;

// insertKey(k):    O(log n)  -> sift up to restore heap property
// getMin():        O(1)      -> return root
// extractMin():    O(log n)  -> swap root with last + sift down
// decreaseKey(i):  O(log n)  -> sift up after decreasing value
// deleteKey(i):    O(log n)  -> decreaseKey + extractMin
// heapify(i):      O(log n)  -> sift down within subtree
// buildHeap():     O(n)      -> bottom-up heap construction
class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void swapInt(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }

public:
    MinHeap(int cap) {
        capacity = cap;
        heap_size = 0;
        harr = new int[cap];
    }

    void insertKey(int k) {
        if (heap_size == capacity) return;

        int i = heap_size++;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i]) {
            swapInt(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    int getMin() {
        return (heap_size > 0) ? harr[0] : INT_MAX;
    }

    int extractMin() {
        if (heap_size <= 0) return INT_MAX;
        if (heap_size == 1) return harr[--heap_size];

        int root = harr[0];
        harr[0] = harr[--heap_size];
        heapify(0);
        return root;
    }

    void decreaseKey(int i, int val) {
        harr[i] = val;

        while (i != 0 && harr[parent(i)] > harr[i]) {
            swapInt(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void heapify(int i) {
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[smallest]) smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;

        if (smallest != i) {
            swapInt(harr[i], harr[smallest]);
            heapify(smallest);
        }
    }

    ~MinHeap() {
        delete[] harr;
    }
};

// insertKey(k):    O(log n)  -> sift up to restore heap property
// getMax():        O(1)      -> return root
// extractMax():    O(log n)  -> swap root with last + sift down
// increaseKey(i):  O(log n)  -> sift up after increasing value
// deleteKey(i):    O(log n)  -> increaseKey + extractMax
// heapify(i):      O(log n)  -> sift down within subtree
// buildHeap():     O(n)      -> bottom-up heap construction
class MaxHeap {
    int *harr;
    int capacity;
    int heap_size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void swapInt(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        heap_size = 0;
        harr = new int[cap];
    }

    void insertKey(int k) {
        if (heap_size == capacity) return;

        int i = heap_size++;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] < harr[i]) {
            swapInt(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    int getMax() {
        return (heap_size > 0) ? harr[0] : INT_MIN;
    }

    int extractMax() {
        if (heap_size <= 0) return INT_MIN;
        if (heap_size == 1) return harr[--heap_size];

        int root = harr[0];
        harr[0] = harr[--heap_size];
        heapify(0);
        return root;
    }

    void increaseKey(int i, int val) {
        harr[i] = val;

        while (i != 0 && harr[parent(i)] < harr[i]) {
            swapInt(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        extractMax();
    }

    void heapify(int i) {
        int l = left(i), r = right(i);
        int largest = i;

        if (l < heap_size && harr[l] > harr[largest]) largest = l;
        if (r < heap_size && harr[r] > harr[largest]) largest = r;

        if (largest != i) {
            swapInt(harr[i], harr[largest]);
            heapify(largest);
        }
    }

    ~MaxHeap() {
        delete[] harr;
    }
};