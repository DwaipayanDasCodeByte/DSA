//Array ADT using C
#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key) {
    int l = 0;
    int h = arr.length - 1;
    int mid;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid]) return mid;
        else if (key < arr.A[mid]) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key) {
    if (l <= h) {
        int mid = (l + h) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) return RBinarySearch(a, l, mid - 1, key);
        else return RBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

int max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

int min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) min = arr.A[i];
    }
    return min;
}

int sum(struct Array arr) {
    int total = 0;
    for (int i = 0; i < arr.length; i++) {
        total += arr.A[i];
    }
    return total;
}

int avg(struct Array arr) {
    return sum(arr) / arr.length;
}

void Reverse(struct Array *arr) {
    int *B = (int *)malloc(arr->length * sizeof(int));
    int i, j;
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    free(B);
}

void LeftShift(struct Array *arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

void RightShift(struct Array *arr) {
    for (int i = arr->length; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->length++;
}

void InsertSort(struct Array *arr, int x) {
    int i = arr->length - 1;
    if (arr->length == arr->size) return;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr) {
    int i = 0, j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    return arr3;
}

int main() {
    struct Array arr1;
    int ch, x, index;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                insert(&arr1, index, x);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                index = LinearSearch(arr1, x);
                printf("Element index: %d\n", index);
                break;
            case 4:
                printf("Sum is %d\n", sum(arr1));
                break;
            case 5:
                Display(arr1);
                break;
        }
    } while (ch < 6);

    free(arr1.A);
    return 0;
}
 
