#include <stdlib.h>

typedef struct {
    int* data;
    int capacity;
    int size;
} FrontMiddleBackQueue;

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* obj = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
    obj->capacity = 4;
    obj->size = 0;
    obj->data = (int*)malloc(obj->capacity * sizeof(int));
    return obj;
}
void checkResize(FrontMiddleBackQueue* obj) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
    }
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    checkResize(obj);
    for (int i = obj->size; i > 0; i--) {
        obj->data[i] = obj->data[i - 1];
    }
    obj->data[0] = val;
    obj->size++;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    checkResize(obj);
    int mid = obj->size / 2;
    for (int i = obj->size; i > mid; i--) {
        obj->data[i] = obj->data[i - 1];
    }
    obj->data[mid] = val;
    obj->size++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    checkResize(obj);
    obj->data[obj->size] = val;
    obj->size++;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    int val = obj->data[0];
    for (int i = 0; i < obj->size - 1; i++) {
        obj->data[i] = obj->data[i + 1];
    }
    obj->size--;
    return val;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    int mid = (obj->size - 1) / 2;
    int val = obj->data[mid];
    for (int i = mid; i < obj->size - 1; i++) {
        obj->data[i] = obj->data[i + 1];
    }
    obj->size--;
    return val;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    int val = obj->data[obj->size - 1];
    obj->size--;
    return val;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    free(obj->data);
    free(obj);
}
