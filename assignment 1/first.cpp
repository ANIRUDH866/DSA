#include <iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
                j--;
            }
        }
    }
}

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) swap(arr[start++], arr[end--]);
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10] = {0};
    int r1, c1, r2, c2;
    cout << "\nEnter rows and cols of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible!\n";
        return;
    }

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void matrixTranspose() {
    int a[10][10], r, c;
    cout << "\nEnter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Transpose:\n";
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void rowColumnSum() {
    int a[10][10], r, c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "\nRow sums:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += a[i][j];
        cout << sum << " ";
    }
    cout << endl;

    cout << "Column sums:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += a[i][j];
        cout << sum << " ";
    }
    cout << endl;
}

void outputQuestion3() {
    int arr[5] = {1};  
    cout << "\nQ3 Output: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i];
    cout << endl;
}

int main() {
    int arr[100], n = 0, choice, pos, value, key;

    while (true) {
        cout << "\n\n========= MAIN MENU =========\n";
        cout << "1. CREATE ARRAY\n";
        cout << "2. DISPLAY ARRAY\n";
        cout << "3. INSERT ELEMENT\n";
        cout << "4. DELETE ELEMENT\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. REMOVE DUPLICATES\n";
        cout << "7. REVERSE ARRAY\n";
        cout << "8. MATRIX MULTIPLICATION\n";
        cout << "9. MATRIX TRANSPOSE\n";
        cout << "10. ROW & COLUMN SUM\n";
        cout << "11. OUTPUT OF QUESTION 3\n";
        cout << "12. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            break;

        case 2:
            displayArray(arr, n);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = value;
            n++;
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;
            for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Found at index " << i << endl;
                    goto DONE;
                }
            }
            cout << "Not Found\n";
        DONE:
            break;

        case 6:
            removeDuplicates(arr, n);
            cout << "Array after removing duplicates: ";
            displayArray(arr, n);
            break;

        case 7:
            reverseArray(arr, n);
            cout << "Reversed array: ";
            displayArray(arr, n);
            break;

        case 8:
            matrixMultiplication();
            break;

        case 9:
            matrixTranspose();
            break;

        case 10:
            rowColumnSum();
            break;

        case 11:
            outputQuestion3();
            break;

        case 12:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
