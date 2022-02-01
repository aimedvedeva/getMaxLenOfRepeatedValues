/*
1. This function returns the length of the largest non-last segment with repeated values;
2. Time complexity estimate is O(n^2);
3. Logical defect: it ignores the segment of repeated values ​​in case it closes the data array, i.e. comes last.
*/
int myfunc(int a[], int size) {
    int shift = 0;
    for (int first_index = 0; first_index < size; first_index++) {
        for (int second_index = first_index; second_index < size; second_index++) {
            if (a[second_index] != a[first_index]) {
                if (second_index - first_index > shift) {
                    shift = second_index - first_index;
                }
                first_index = second_index - 1;
                break;
            }
        }
    }
    return shift;
}
/*
Improved version with O(n) time complexity estimate;
*/
int getMaxLenOfRepeatedValues(int a[], int size) {
    int max_len = 0;
    int len = 1;
    int value = a[0];

    for (int i = 1; i < size; i++) { 
         
        if (a[i] != value) {
            if (max_len < len) {
                max_len = len;
            }
            value = a[i];
            len = 1;
        }
        else {
            len++;
        }     
    }

    if (max_len < len) {
        max_len = len;
    }

    return max_len;
}

void main() {
    const int size = 7;
    int a[size] = {0,0,1,1,1,1,1};
    int res1 = getMaxLenOfRepeatedValues(a, size);
    int res2 = myfunc(a, size);
}
