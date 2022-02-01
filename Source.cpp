/*
1. ��� ������� ���������� ����� ����������� �� ���������� �������� � �������������� ����������;
2. ������ ��������� �� ������� ���������� O(n^2);
3. ���������� ������: ��� ���������� ������� ������������ �������� � ������, ���� �� �������� ������ ������, �.�. ���� ���������.
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
���������� ������� � ������� ��������� �� ������� O(n);
*/
int getMaxLenOfRepeatedValues(int a[], int size) {
    int max_len = 0;
    int len = 0;
    int value = 0;

    for (int i = 0; i < size; i++) { 
        if (i == 0) {
            value = a[i];
            len++;
            continue;
        }
        
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
    int a[size] = {0,0,1,1,1,2,3};
    int res1 = getMaxLenOfRepeatedValues(a, size);
    int res2 = myfunc(a, size);
    
}